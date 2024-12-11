// Should accept 2 read lines, 1 write line
// only passing cache protocol to axi
module dumb_cache #( 
    parameter LINE_COUNT = 64, 
    parameter BYTES_PER_LINE = 64, 
    parameter INDEX_SIZE = $clog2(LINE_COUNT), 
    parameter OFFSET_SIZE = $clog2(BYTES_PER_LINE), 
    parameter TAG_SIZE = 64 - INDEX_SIZE - OFFSET_SIZE, 
    parameter DATA_SIZE = BYTES_PER_LINE * 8
) (
    input  clk,
          reset,

    // Cache Protocol Signals (Servicing data requests)
    // READ LINE 1
    output wire m_axi_arready_1,
    input  wire [63:0] m_axi_araddr_1,
    input  wire m_axi_arvalid_1,

    output wire [63:0] m_axi_rdata_1,
    output wire  m_axi_rvalid_1,
    input  wire  m_axi_rready_1,

    //READ LINE 2
    output wire m_axi_arready_2,
    input  wire [63:0] m_axi_araddr_2,
    input  wire m_axi_arvalid_2,

    output wire [63:0] m_axi_rdata_2,
    output wire  m_axi_rvalid_2,
    input  wire  m_axi_rready_2,


    // WRITE LINE
    input wire S_W_VALID,
    input wire [63:0] S_W_ADDR,
    input wire [63:0] S_W_DATA,
    input wire [3:0] S_W_SIZE,

    // Axi Signals
    // Read
    input   wire m_axi_arready,
    output  wire [63:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [63:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready,

    output  wire   m_axi_awvalid,
    input wire   m_axi_awready,
    output wire [63:0] m_axi_awaddr,
    output  wire [63:0] m_axi_wdata,
    output  wire   m_axi_wlast,
    output  wire   m_axi_wvalid,
    input wire   m_axi_wready,
    input  wire  m_axi_bvalid,
    output wire  m_axi_bready,
);

    logic [63:0] line_1_address, line_2_address, next_line_1_address, next_line_2_address;
    logic line_1_contains_request, line_2_contains_request, next_line_1_contains_request, next_line_2_contains_request;
    logic last_request_made, next_last_request_made;
    logic [5:0] state, next_state;
    logic [63:0] buffer, next_buffer;
    logic [8:0] index, next_index

    logic [63:0] latched_m_axi_address, next_latched_m_axi_address;

    parameter LINE_1 = 1'd0,
                LINE_2 = 1'd1; 

    parameter IDLE = 6'd0,
                AXI_R_REQUEST = 6'd1,
                AXI_R_READ = 6'd2,
                AXI_R_HOLD = 6'd3;

    parameter W_IDLE = 6'd0,
                W_READ_REQUEST,
                W_READ,
                AXI_W_REQUEST
                AXI_W_MEM
                AXI_W_DONE
    
    // Need to manage the read shared resource between, mauybe have a third line for contains request?
    // Although line 2 and w-line will never be active at same time
    // So we can use line 2 for w_request
    // then we have a flag if its a write that we use to go into write states that write to axi

    always_ff @ (posedge clk) begin
        if (reset) begin
            state = IDLE;
        end else begin
            state <= next_state;
            last_request_made <= next_last_request_made;
            line_1_contains_request <= next_line_1_contains_request;
            line_2_contains_request <= next_line_2_contains_request;
            line_1_address <= next_line_1_address;
            line_2_address <= next_line_2_address;
            latched_m_axi_address <= next_latched_m_axi_address;
            buffer <= next_buffer;
            index <= next_index;
        end
    end
    always_comb begin
        if (!line_1_contains_request && m_axi_arvalid_1) begin
            next_line_1_contains_request = 1;
            next_line_1_address = m_axi_araddr_1;
        end
        if (!line_2_contains_request && m_axi_arvalid_2) begin
            next_line_2_contains_request = 1;
            next_line_2_address = m_axi_araddr_1;
        end

        m_axi_arready_1 = !line_1_contains_request;
        m_axi_arready_2 = !line_2_contains_request;

        case (state)
            IDLE: begin
                m_axi_rvalid_1 = 0;
                m_axi_rvalid_2 = 0
                m_axi_rdata_1 = 0;
                m_axi_rdata_2 = 0;

                m_axi_rready = 0;
                m_axi_arvalid = 0;
            end
            AXI_R_REQUEST: begin
                m_axi_araddr = latched_m_axi_address;
                m_axi_arvalid = 1;
            end
            AXI_R_READ: begin
                m_axi_rready = 1;
                m_axi_arvalid = 0;
            end
            AXI_R_HOLD: begin
                m_axi_rready = 0;
                if (last_request_made) begin // Service line 2
                    m_axi_rdata_2 = buffer;
                    m_axi_rvalid_2 = 1;
                    m_axi_rvalid_1 = 0;
                end else begin // Service line 1
                    m_axi_rdata_1 = buffer;
                    m_axi_rvalid_1 = 1;
                    m_axi_rvalid_2 = 0;
                end
            end
        endcase 
    end

    always_comb begin
        case (state)
            IDLE: begin
                if (line_1_contains_request && line_2_contains_request) begin
                    next_latched_m_axi_address = last_request_made ? line_1_address : line_2_address;
                    next_last_request_made = !last_request_made;
                    next_state = AXI_R_REQUEST;
                end else if (line_1_contains_request) begin
                    next_latched_m_axi_address = line_1_address;
                    next_last_request_made = LINE_1;
                    next_state = AXI_R_REQUEST;
                end else if (line_2_contains_request) begin
                    next_latched_m_axi_address = line_2_address;
                    next_last_request_made = LINE_2;
                    next_state = AXI_R_REQUEST;
                end
            end
            AXI_R_REQUEST: begin
                next_state = m_axi_arready ? AXI_R_READ : AXI_R_REQUEST;
                next_index = 0; 
            end
            AXI_R_READ: begin
                if(m_axi_rvalid && m_axi_rlast) begin
                    next_state = AXI_R_HOLD;
                end
            end
            AXI_R_HOLD: begin
                if (last_request_made) begin // Service line 2
                    next_state = m_axi_rready_2 ? IDLE : AXI_R_HOLD;
                    next_line_2_contains_request = 0;
                end else begin // Service line 1
                    next_state = m_axi_rready_1 ? IDLE : AXI_R_HOLD;
                    next_line_1_contains_request = 0;
                end
            end
        endcase 
    end



endmodule