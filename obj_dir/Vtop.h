// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"
#include "Vtop__Inlines.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class Vtop___024unit;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop___024unit*    	__PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(hz32768timer,0,0);
    VL_OUT8(m_axi_awlen,7,0);
    VL_OUT8(m_axi_awsize,2,0);
    VL_OUT8(m_axi_awburst,1,0);
    VL_OUT8(m_axi_awlock,0,0);
    VL_OUT8(m_axi_awcache,3,0);
    VL_OUT8(m_axi_awprot,2,0);
    VL_OUT8(m_axi_awvalid,0,0);
    VL_IN8(m_axi_awready,0,0);
    VL_OUT8(m_axi_wstrb,7,0);
    VL_OUT8(m_axi_wlast,0,0);
    VL_OUT8(m_axi_wvalid,0,0);
    VL_IN8(m_axi_wready,0,0);
    VL_IN8(m_axi_bresp,1,0);
    VL_IN8(m_axi_bvalid,0,0);
    VL_OUT8(m_axi_bready,0,0);
    VL_OUT8(m_axi_arlen,7,0);
    VL_OUT8(m_axi_arsize,2,0);
    VL_OUT8(m_axi_arburst,1,0);
    VL_OUT8(m_axi_arlock,0,0);
    VL_OUT8(m_axi_arcache,3,0);
    VL_OUT8(m_axi_arprot,2,0);
    VL_OUT8(m_axi_arvalid,0,0);
    VL_IN8(m_axi_arready,0,0);
    VL_IN8(m_axi_rresp,1,0);
    VL_IN8(m_axi_rlast,0,0);
    VL_IN8(m_axi_rvalid,0,0);
    VL_OUT8(m_axi_rready,0,0);
    VL_IN8(m_axi_acvalid,0,0);
    VL_OUT8(m_axi_acready,0,0);
    VL_IN8(m_axi_acsnoop,3,0);
    //char	__VpadToAlign33[1];
    VL_OUT16(m_axi_awid,12,0);
    VL_IN16(m_axi_bid,12,0);
    VL_OUT16(m_axi_arid,12,0);
    VL_IN16(m_axi_rid,12,0);
    //char	__VpadToAlign42[6];
    VL_IN64(entry,63,0);
    VL_IN64(stackptr,63,0);
    VL_IN64(satp,63,0);
    VL_OUT64(m_axi_awaddr,63,0);
    VL_OUT64(m_axi_wdata,63,0);
    VL_OUT64(m_axi_araddr,63,0);
    VL_IN64(m_axi_rdata,63,0);
    VL_IN64(m_axi_acaddr,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__jump_signal,0,0);
    VL_SIG8(top__DOT__jump_signal_applied,0,0);
    VL_SIG8(top__DOT__id_ready,0,0);
    VL_SIG8(top__DOT__ex_ready,0,0);
    VL_SIG8(top__DOT__mem_ready,0,0);
    VL_SIG8(top__DOT__bp_reg,4,0);
    VL_SIG8(top__DOT__bp_add_reg_value,0,0);
    VL_SIG8(top__DOT__ex_opcode,6,0);
    VL_SIG8(top__DOT__next_ex_opcode,6,0);
    VL_SIG8(top__DOT__branch_type,3,0);
    VL_SIG8(top__DOT__next_branch_type,3,0);
    VL_SIG8(top__DOT__is_word_op,0,0);
    VL_SIG8(top__DOT__next_is_word_op,0,0);
    VL_SIG8(top__DOT__unsigned_op,2,0);
    VL_SIG8(top__DOT__next_unsigned_op,2,0);
    VL_SIG8(top__DOT__ex_dst_reg,4,0);
    VL_SIG8(top__DOT__next_ex_dst_reg,4,0);
    VL_SIG8(top__DOT__imm_or_reg2,0,0);
    VL_SIG8(top__DOT__next_imm_or_reg2,0,0);
    VL_SIG8(top__DOT__mem_opcode_ex,6,0);
    VL_SIG8(top__DOT__next_mem_opcode_ex,6,0);
    VL_SIG8(top__DOT__mem_operation_size_ex,3,0);
    VL_SIG8(top__DOT__next_mem_operation_size_ex,3,0);
    VL_SIG8(top__DOT__ecall_ex,0,0);
    VL_SIG8(top__DOT__next_ecall_ex,0,0);
    VL_SIG8(top__DOT__mem_dst_reg,4,0);
    VL_SIG8(top__DOT__next_mem_dst_reg,4,0);
    VL_SIG8(top__DOT__mem_opcode,6,0);
    VL_SIG8(top__DOT__mem_operation_size,3,0);
    VL_SIG8(top__DOT__next_mem_operation_size,3,0);
    VL_SIG8(top__DOT__ecall_mem,0,0);
    VL_SIG8(top__DOT__next_ecall_mem,0,0);
    VL_SIG8(top__DOT__wb_dst_reg,4,0);
    VL_SIG8(top__DOT__wb_enable,0,0);
    VL_SIG8(top__DOT__ecall,0,0);
    VL_SIG8(top__DOT__next_ecall,0,0);
    VL_SIG8(top__DOT__pending_write,0,0);
    VL_SIG8(top__DOT__next_pending_write,0,0);
    VL_SIG8(top__DOT__pending_write_size,1,0);
    VL_SIG8(top__DOT__next_pending_write_size,1,0);
    VL_SIG8(top__DOT__rf_reg1,4,0);
    VL_SIG8(top__DOT__rf_reg2,4,0);
    VL_SIG8(top__DOT__L1_I_S_R_DATA_VALID,0,0);
    VL_SIG8(top__DOT__L1_D_S_R_ADDR_VALID,0,0);
    VL_SIG8(top__DOT__L1_D_S_R_DATA_VALID,0,0);
    VL_SIG8(top__DOT__L1_D_S_W_VALID,0,0);
    VL_SIG8(top__DOT__L1_D_S_W_SIZE,3,0);
    VL_SIG8(top__DOT__L1_D_S_W_COMPLETE,0,0);
    VL_SIG8(top__DOT__L2_S_R_ADDR_VALID_I,0,0);
    VL_SIG8(top__DOT__L2_S_R_ADDR_VALID_D,0,0);
    VL_SIG8(top__DOT__L2_S_R_DATA_VALID_I,0,0);
    VL_SIG8(top__DOT__L2_S_R_DATA_VALID_D,0,0);
    VL_SIG8(top__DOT__L2_S_W_VALID,0,0);
    VL_SIG8(top__DOT__L2_S_W_COMPLETE,0,0);
    VL_SIG8(top__DOT__ex_raw_dep,0,0);
    VL_SIG8(top__DOT__mem_raw_dep,0,0);
    VL_SIG8(top__DOT__rf__DOT__ecall_state,2,0);
    VL_SIG8(top__DOT__rf__DOT__next_ecall_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__state,2,0);
    VL_SIG8(top__DOT__llc__DOT__next_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__w_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__next_w_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__r_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__next_r_state,2,0);
    VL_SIG8(top__DOT__llc__DOT__conflicting_tags,0,0);
    VL_SIG8(top__DOT__llc__DOT__line1_active,0,0);
    VL_SIG8(top__DOT__llc__DOT__line2_active,0,0);
    VL_SIG8(top__DOT__llc__DOT__r_buffer_index,2,0);
    VL_SIG8(top__DOT__llc__DOT__next_r_buffer_index,2,0);
    VL_SIG8(top__DOT__llc__DOT__w_buffer_index,2,0);
    VL_SIG8(top__DOT__llc__DOT__next_w_buffer_index,2,0);
    VL_SIG8(top__DOT__llc__DOT__w_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__llc__DOT__w_selected_block_is_dirty,0,0);
    VL_SIG8(top__DOT__llc__DOT__w_requested_index,5,0);
    VL_SIG8(top__DOT__llc__DOT__latched_w_requested_index,5,0);
    VL_SIG8(top__DOT__llc__DOT__r1_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__llc__DOT__r2_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__llc__DOT__r1_selected_block_is_dirty,0,0);
    VL_SIG8(top__DOT__llc__DOT__r2_selected_block_is_dirty,0,0);
    VL_SIG8(top__DOT__llc__DOT__r1_requested_index,5,0);
    VL_SIG8(top__DOT__llc__DOT__r2_requested_index,5,0);
    VL_SIG8(top__DOT__llc__DOT__ac_addr_requested_index,5,0);
    VL_SIG8(top__DOT__llc__DOT__last_chosen,0,0);
    VL_SIG8(top__DOT__llc__DOT__next_last_chosen,0,0);
    VL_SIG8(top__DOT__llc__DOT__latched_s_w_contains_request,0,0);
    VL_SIG8(top__DOT__llc__DOT__next_latched_s_w_contains_request,0,0);
    VL_SIG8(top__DOT__llc__DOT__service_line,0,0);
    VL_SIG8(top__DOT__l1_i__DOT__state,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__next_state,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__r_state,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__next_r_state,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__r_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__next_r_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_i__DOT__r_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__l1_i__DOT__r_requested_index,5,0);
    VL_SIG8(top__DOT__l1_i__DOT__r_requested_offset,5,0);
    VL_SIG8(top__DOT__l1_d__DOT__state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__w_state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_w_state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_r_state,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__conflicting_tags,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_r_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__w_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_w_buffer_index,2,0);
    VL_SIG8(top__DOT__l1_d__DOT__latched_s_w_contains_request,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_latched_s_w_contains_request,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__latched_s_w_request_size,1,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_latched_s_w_request_size,1,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_captured,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_r_captured,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__w_complete,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_w_complete,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__pending_cache_write,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_pending_cache_write,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__w_selected_block_is_valid,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_selected_block_is_dirty,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__w_selected_block_is_dirty,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_requested_index,5,0);
    VL_SIG8(top__DOT__l1_d__DOT__latched_w_requested_index,5,0);
    VL_SIG8(top__DOT__l1_d__DOT__ac_addr_requested_index,5,0);
    VL_SIG8(top__DOT__l1_d__DOT__r_requested_offset,5,0);
    VL_SIG8(top__DOT__l1_d__DOT__evict_way,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__next_evict_way,0,0);
    VL_SIG8(top__DOT__l1_d__DOT__testing_cache_valid,0,0);
    VL_SIG8(top__DOT__if_stage__DOT__opcode,6,0);
    VL_SIG8(top__DOT__id_stage__DOT__opcode,6,0);
    VL_SIG8(top__DOT__id_stage__DOT__funct3,2,0);
    VL_SIG8(top__DOT__id_stage__DOT__funct7,6,0);
    VL_SIG8(top__DOT__mem_stage__DOT__state,2,0);
    VL_SIG8(top__DOT__mem_stage__DOT__next_state,2,0);
    //char	__VpadToAlign250[2];
    VL_SIG(top__DOT__instruction,31,0);
    VL_SIG(top__DOT__next_instruction,31,0);
    //char	__VpadToAlign260[4];
    VL_SIGW(top__DOT__L2_S_R_DATA_I,511,0,16);
    VL_SIGW(top__DOT__L2_S_R_DATA_D,511,0,16);
    VL_SIGW(top__DOT__L2_S_W_DATA,511,0,16);
    VL_SIG(top__DOT__rf__DOT__unnamedblk1__DOT__i,31,0);
    //char	__VpadToAlign460[4];
    VL_SIGW(top__DOT__llc__DOT__latched_w_data_buffer,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__next_latched_w_data_buffer,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__w_selected_data,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__r1_selected_data,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__r2_selected_data,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__latched_s_w_request_data,511,0,16);
    VL_SIGW(top__DOT__llc__DOT__next_latched_s_w_request_data,511,0,16);
    VL_SIGW(top__DOT__l1_i__DOT__r_selected_data,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT__latched_w_data_buffer,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT__next_latched_w_data_buffer,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT__r_selected_data,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT__w_selected_data,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT__latched_w_selected_data,511,0,16);
    VL_SIGW(top__DOT__ex_stage__DOT__multiplication_result,127,0,4);
    VL_SIG64(top__DOT__pc,63,0);
    VL_SIG64(top__DOT__next_if_pc,63,0);
    VL_SIG64(top__DOT__jump_pc,63,0);
    VL_SIG64(top__DOT__bp_val,63,0);
    VL_SIG64(top__DOT__id_instr_pc,63,0);
    VL_SIG64(top__DOT__next_id_instr_pc,63,0);
    VL_SIG64(top__DOT__id_bp_target,63,0);
    VL_SIG64(top__DOT__ex_instr_pc,63,0);
    VL_SIG64(top__DOT__next_ex_instr_pc,63,0);
    VL_SIG64(top__DOT__ex_bp_target,63,0);
    VL_SIG64(top__DOT__next_ex_bp_target,63,0);
    VL_SIG64(top__DOT__r1_val,63,0);
    VL_SIG64(top__DOT__next_r1_val,63,0);
    VL_SIG64(top__DOT__r2_val,63,0);
    VL_SIG64(top__DOT__next_r2_val,63,0);
    VL_SIG64(top__DOT__imm,63,0);
    VL_SIG64(top__DOT__next_imm,63,0);
    VL_SIG64(top__DOT__ex_res,63,0);
    VL_SIG64(top__DOT__next_ex_res,63,0);
    VL_SIG64(top__DOT__r2_val_mem,63,0);
    VL_SIG64(top__DOT__next_r2_val_mem,63,0);
    VL_SIG64(top__DOT__wb_dst_val,63,0);
    VL_SIG64(top__DOT__pending_write_addr,63,0);
    VL_SIG64(top__DOT__next_pending_write_addr,63,0);
    VL_SIG64(top__DOT__pending_write_data,63,0);
    VL_SIG64(top__DOT__next_pending_write_data,63,0);
    VL_SIG64(top__DOT__L1_D_S_R_ADDR,63,0);
    VL_SIG64(top__DOT__L1_D_S_R_DATA,63,0);
    VL_SIG64(top__DOT__L1_D_S_W_ADDR,63,0);
    VL_SIG64(top__DOT__L1_D_S_W_DATA,63,0);
    VL_SIG64(top__DOT__L2_S_R_ADDR_I,63,0);
    VL_SIG64(top__DOT__L2_S_R_ADDR_D,63,0);
    VL_SIG64(top__DOT__L2_S_W_ADDR,63,0);
    VL_SIG64(top__DOT__llc__DOT__latched_r_requested_address,63,0);
    VL_SIG64(top__DOT__llc__DOT__next_latched_r_requested_address,63,0);
    VL_SIG64(top__DOT__llc__DOT__latched_w_requested_address,63,0);
    VL_SIG64(top__DOT__llc__DOT__next_latched_w_requested_address,63,0);
    VL_SIGW(top__DOT__llc__DOT__cache,36223,0,1132);
    VL_SIGW(top__DOT__llc__DOT__next_cache,36223,0,1132);
    VL_SIG64(top__DOT__llc__DOT__w_selected_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__latched_w_requested_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__r1_requested_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__r2_requested_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__r1_selected_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__r2_selected_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__ac_addr_requested_tag,51,0);
    VL_SIG64(top__DOT__llc__DOT__latched_s_w_request_addr,63,0);
    VL_SIG64(top__DOT__llc__DOT__next_latched_s_w_request_addr,63,0);
    VL_SIG64(top__DOT__l1_i__DOT__latched_r_requested_address,63,0);
    VL_SIG64(top__DOT__l1_i__DOT__next_latched_r_requested_address,63,0);
    VL_SIGW(top__DOT__l1_i__DOT__cache,36159,0,1130);
    VL_SIGW(top__DOT__l1_i__DOT__next_cache,36159,0,1130);
    VL_SIG64(top__DOT__l1_i__DOT__r_requested_tag,51,0);
    VL_SIG64(top__DOT__l1_i__DOT__r_selected_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__latched_r_requested_address,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__next_latched_r_requested_address,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__latched_w_requested_address,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__next_latched_w_requested_address,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__test3_signal,63,0);
    VL_SIGW(top__DOT__l1_d__DOT__cache,72447,0,2264);
    VL_SIGW(top__DOT__l1_d__DOT__next_cache,72447,0,2264);
    VL_SIG64(top__DOT__l1_d__DOT__latched_s_w_request_data,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__next_latched_s_w_request_data,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__latched_s_w_request_addr,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__next_latched_s_w_request_addr,63,0);
    VL_SIG64(top__DOT__l1_d__DOT__r_requested_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__r_selected_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__w_selected_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__latched_w_requested_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__latched_w_selected_tag,51,0);
    VL_SIG64(top__DOT__l1_d__DOT__ac_addr_requested_tag,51,0);
    VL_SIG64(top__DOT__if_stage__DOT__imm,63,0);
    VL_SIG64(top__DOT__ex_stage__DOT__operand2,63,0);
    VL_SIG64(top__DOT__ex_stage__DOT__temp_result,63,0);
    VL_SIG64(top__DOT__rf__DOT__registers[32],63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__llc__DOT____Vlvbound3,1,0);
    VL_SIG8(top__DOT__llc__DOT____Vlvbound4,1,0);
    VL_SIG8(top__DOT__llc__DOT____Vlvbound6,1,0);
    VL_SIG8(top__DOT__l1_i__DOT____Vlvbound2,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound1,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound2,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound3,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound4,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound8,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound9,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound13,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound14,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound15,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound16,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound20,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound21,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound25,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound26,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound30,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound31,7,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound36,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound37,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound40,0,0);
    VL_SIG8(top__DOT__l1_d__DOT____Vlvbound41,0,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign39005[1];
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound5,15,0);
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound10,15,0);
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound17,15,0);
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound22,15,0);
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound27,15,0);
    VL_SIG16(top__DOT__l1_d__DOT____Vlvbound32,15,0);
    //char	__VpadToAlign39018[2];
    VL_SIG(top__DOT____Vcellout__l1_i__S_R_DATA,31,0);
    VL_SIG(top__DOT____Vcellinp__ex_stage__mem_opcode,31,0);
    //char	__VpadToAlign39028[4];
    VL_SIGW(top__DOT__llc__DOT____Vlvbound1,511,0,16);
    VL_SIGW(top__DOT__l1_i__DOT____Vlvbound1,511,0,16);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound6,31,0);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound11,31,0);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound18,31,0);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound23,31,0);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound28,31,0);
    VL_SIG(top__DOT__l1_d__DOT____Vlvbound33,31,0);
    VL_SIGW(top__DOT__l1_d__DOT____Vlvbound35,511,0,16);
    VL_SIGW(top__DOT__l1_d__DOT____Vlvbound39,511,0,16);
    VL_SIG(__Vm_traceActivity,31,0);
    //char	__VpadToAlign39316[4];
    VL_SIG64(top__DOT__llc__DOT____Vlvbound2,51,0);
    VL_SIG64(top__DOT__llc__DOT____Vlvbound5,63,0);
    VL_SIG64(top__DOT__llc__DOT____Vlvbound7,51,0);
    VL_SIG64(top__DOT__l1_i__DOT____Vlvbound3,51,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound7,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound12,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound19,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound24,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound29,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound34,63,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound38,51,0);
    VL_SIG64(top__DOT__l1_d__DOT____Vlvbound42,51,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign39420[4];
    Vtop__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);	///< Copying not allowed
    Vtop(const Vtop&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__11(Vtop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__9(Vtop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__10(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__12(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
