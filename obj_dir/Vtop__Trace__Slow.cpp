// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+149,"clk",-1);
	vcdp->declBit  (c+150,"reset",-1);
	vcdp->declBit  (c+151,"hz32768timer",-1);
	vcdp->declQuad (c+152,"entry",-1,63,0);
	vcdp->declQuad (c+154,"stackptr",-1,63,0);
	vcdp->declQuad (c+156,"satp",-1,63,0);
	vcdp->declBus  (c+158,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+159,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+161,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+162,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+163,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+164,"m_axi_awlock",-1);
	vcdp->declBus  (c+165,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+166,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+167,"m_axi_awvalid",-1);
	vcdp->declBit  (c+168,"m_axi_awready",-1);
	vcdp->declQuad (c+169,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+171,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+172,"m_axi_wlast",-1);
	vcdp->declBit  (c+173,"m_axi_wvalid",-1);
	vcdp->declBit  (c+174,"m_axi_wready",-1);
	vcdp->declBus  (c+175,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+176,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+177,"m_axi_bvalid",-1);
	vcdp->declBit  (c+178,"m_axi_bready",-1);
	vcdp->declBus  (c+179,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+180,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+182,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+183,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+184,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+185,"m_axi_arlock",-1);
	vcdp->declBus  (c+186,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+187,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+188,"m_axi_arvalid",-1);
	vcdp->declBit  (c+189,"m_axi_arready",-1);
	vcdp->declBus  (c+190,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+191,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+193,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+194,"m_axi_rlast",-1);
	vcdp->declBit  (c+195,"m_axi_rvalid",-1);
	vcdp->declBit  (c+196,"m_axi_rready",-1);
	vcdp->declBit  (c+197,"m_axi_acvalid",-1);
	vcdp->declBit  (c+198,"m_axi_acready",-1);
	vcdp->declQuad (c+199,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+201,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+202,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+204,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+149,"top clk",-1);
	vcdp->declBit  (c+150,"top reset",-1);
	vcdp->declBit  (c+151,"top hz32768timer",-1);
	vcdp->declQuad (c+152,"top entry",-1,63,0);
	vcdp->declQuad (c+154,"top stackptr",-1,63,0);
	vcdp->declQuad (c+156,"top satp",-1,63,0);
	vcdp->declBus  (c+158,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+159,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+161,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+162,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+163,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+164,"top m_axi_awlock",-1);
	vcdp->declBus  (c+165,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+166,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+167,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+168,"top m_axi_awready",-1);
	vcdp->declQuad (c+169,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+171,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+172,"top m_axi_wlast",-1);
	vcdp->declBit  (c+173,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+174,"top m_axi_wready",-1);
	vcdp->declBus  (c+175,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+176,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+177,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+178,"top m_axi_bready",-1);
	vcdp->declBus  (c+179,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+180,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+182,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+183,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+184,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+185,"top m_axi_arlock",-1);
	vcdp->declBus  (c+186,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+187,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+188,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+189,"top m_axi_arready",-1);
	vcdp->declBus  (c+190,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+191,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+193,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+194,"top m_axi_rlast",-1);
	vcdp->declBit  (c+195,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+196,"top m_axi_rready",-1);
	vcdp->declBit  (c+197,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+198,"top m_axi_acready",-1);
	vcdp->declQuad (c+199,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+201,"top m_axi_acsnoop",-1,3,0);
	vcdp->declQuad (c+24,"top pc",-1,63,0);
	vcdp->declQuad (c+1,"top next_if_pc",-1,63,0);
	vcdp->declQuad (c+3,"top jump_pc",-1,63,0);
	vcdp->declBit  (c+5,"top jump_signal",-1);
	vcdp->declBit  (c+26,"top jump_signal_applied",-1);
	vcdp->declBit  (c+6,"top id_ready",-1);
	vcdp->declBit  (c+7,"top ex_ready",-1);
	vcdp->declBit  (c+27,"top mem_ready",-1);
	vcdp->declBus  (c+28,"top instruction",-1,31,0);
	vcdp->declBus  (c+8,"top next_instruction",-1,31,0);
	vcdp->declQuad (c+29,"top id_instr_pc",-1,63,0);
	vcdp->declQuad (c+9,"top next_id_instr_pc",-1,63,0);
	vcdp->declQuad (c+31,"top ex_instr_pc",-1,63,0);
	vcdp->declQuad (c+205,"top next_ex_instr_pc",-1,63,0);
	vcdp->declBus  (c+33,"top ex_opcode",-1,6,0);
	vcdp->declBus  (c+34,"top next_ex_opcode",-1,6,0);
	vcdp->declQuad (c+35,"top r1_val",-1,63,0);
	vcdp->declQuad (c+11,"top next_r1_val",-1,63,0);
	vcdp->declQuad (c+37,"top r2_val",-1,63,0);
	vcdp->declQuad (c+13,"top next_r2_val",-1,63,0);
	vcdp->declBus  (c+39,"top imm",-1,19,0);
	vcdp->declBus  (c+207,"top next_imm",-1,19,0);
	vcdp->declBus  (c+40,"top ex_dst_reg",-1,4,0);
	vcdp->declBus  (c+208,"top next_ex_dst_reg",-1,4,0);
	vcdp->declBit  (c+41,"top imm_or_reg2",-1);
	vcdp->declBit  (c+209,"top next_imm_or_reg2",-1);
	vcdp->declBus  (c+42,"top mem_opcode_ex",-1,6,0);
	vcdp->declBus  (c+210,"top next_mem_opcode_ex",-1,6,0);
	vcdp->declBit  (c+43,"top is_mem_load_ex",-1);
	vcdp->declBit  (c+211,"top next_is_mem_load_ex",-1);
	vcdp->declQuad (c+44,"top ex_res",-1,63,0);
	vcdp->declQuad (c+212,"top next_ex_res",-1,63,0);
	vcdp->declQuad (c+46,"top r2_val_mem",-1,63,0);
	vcdp->declQuad (c+37,"top next_r2_val_mem",-1,63,0);
	vcdp->declBus  (c+48,"top mem_dst_reg",-1,4,0);
	vcdp->declBus  (c+40,"top next_mem_dst_reg",-1,4,0);
	vcdp->declBus  (c+49,"top mem_opcode",-1,6,0);
	vcdp->declBus  (c+42,"top next_mem_opcode",-1,6,0);
	vcdp->declBit  (c+50,"top is_mem_load",-1);
	vcdp->declBit  (c+43,"top next_is_mem_load",-1);
	vcdp->declBus  (c+51,"top wb_dst_reg",-1,4,0);
	vcdp->declBus  (c+214,"top next_wb_dst_reg",-1,4,0);
	vcdp->declQuad (c+52,"top wb_dst_val",-1,63,0);
	vcdp->declQuad (c+215,"top next_wb_dst_val",-1,63,0);
	vcdp->declBit  (c+54,"top wb_enable",-1);
	vcdp->declBit  (c+217,"top next_wb_enable",-1);
	vcdp->declBus  (c+218,"top rf_reg1",-1,4,0);
	vcdp->declBus  (c+219,"top rf_reg2",-1,4,0);
	vcdp->declBit  (c+149,"top rf clk",-1);
	vcdp->declBit  (c+150,"top rf reset",-1);
	vcdp->declBus  (c+218,"top rf reg1",-1,4,0);
	vcdp->declBus  (c+219,"top rf reg2",-1,4,0);
	vcdp->declQuad (c+11,"top rf val1",-1,63,0);
	vcdp->declQuad (c+13,"top rf val2",-1,63,0);
	vcdp->declBit  (c+54,"top rf write_enable",-1);
	vcdp->declQuad (c+52,"top rf write_value",-1,63,0);
	vcdp->declBus  (c+51,"top rf write_register",-1,4,0);
	vcdp->declBit  (c+220,"top rf write_ready",-1);
	{int i; for (i=0; i<32; i++) {
		vcdp->declQuad (c+55+i*2,"top rf registers",(i+0),63,0);}}
	vcdp->declBus  (c+119,"top rf unnamedblk1 i",-1,31,0);
	vcdp->declBus  (c+203,"top if_stage ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top if_stage DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+221,"top if_stage BUFFER_SIZE",-1,31,0);
	vcdp->declBit  (c+149,"top if_stage clk",-1);
	vcdp->declBit  (c+150,"top if_stage reset",-1);
	vcdp->declQuad (c+24,"top if_stage pc",-1,63,0);
	vcdp->declQuad (c+1,"top if_stage next_if_pc",-1,63,0);
	vcdp->declBus  (c+8,"top if_stage instruction",-1,31,0);
	vcdp->declQuad (c+9,"top if_stage next_stage_pc",-1,63,0);
	vcdp->declBit  (c+189,"top if_stage m_axi_arready",-1);
	vcdp->declQuad (c+180,"top if_stage m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+188,"top if_stage m_axi_arvalid",-1);
	vcdp->declQuad (c+191,"top if_stage m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+194,"top if_stage m_axi_rlast",-1);
	vcdp->declBit  (c+195,"top if_stage m_axi_rvalid",-1);
	vcdp->declBit  (c+196,"top if_stage m_axi_rready",-1);
	vcdp->declBus  (c+222,"top if_stage IDLE",-1,1,0);
	vcdp->declBus  (c+223,"top if_stage REQUEST",-1,1,0);
	vcdp->declBus  (c+224,"top if_stage WAIT",-1,1,0);
	vcdp->declBus  (c+225,"top if_stage READ",-1,1,0);
	vcdp->declArray(c+120,"top if_stage instruction_buffer",-1,511,0);
	vcdp->declQuad (c+136,"top if_stage buffer_start",-1,63,0);
	vcdp->declQuad (c+18,"top if_stage next_buffer_start",-1,63,0);
	vcdp->declQuad (c+20,"top if_stage next_buffer_data",-1,63,0);
	vcdp->declBus  (c+138,"top if_stage buffer_index",-1,5,0);
	vcdp->declBus  (c+22,"top if_stage next_buffer_index",-1,5,0);
	vcdp->declBit  (c+139,"top if_stage empty_buffer",-1);
	vcdp->declBit  (c+23,"top if_stage next_empty_buffer",-1);
	vcdp->declBus  (c+140,"top if_stage state",-1,1,0);
	vcdp->declBus  (c+17,"top if_stage next_state",-1,1,0);
	vcdp->declBus  (c+203,"top id_stage ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top id_stage DATA_WIDTH",-1,31,0);
	vcdp->declBit  (c+149,"top id_stage clk",-1);
	vcdp->declBit  (c+150,"top id_stage reset",-1);
	vcdp->declBit  (c+6,"top id_stage ready",-1);
	vcdp->declBit  (c+7,"top id_stage next_stage_ready",-1);
	vcdp->declBus  (c+28,"top id_stage instruction",-1,31,0);
	vcdp->declQuad (c+29,"top id_stage instruction_pc",-1,63,0);
	vcdp->declQuad (c+205,"top id_stage next_stage_pc",-1,63,0);
	vcdp->declQuad (c+141,"top id_stage ex_opcode",-1,63,0);
	vcdp->declBus  (c+218,"top id_stage r1_reg",-1,4,0);
	vcdp->declBus  (c+219,"top id_stage r2_reg",-1,4,0);
	vcdp->declBus  (c+208,"top id_stage dst_reg",-1,4,0);
	vcdp->declBus  (c+226,"top id_stage imm",-1,20,0);
	vcdp->declBit  (c+209,"top id_stage imm_or_reg2",-1);
	vcdp->declBit  (c+227,"top id_stage mem_opcode",-1);
	vcdp->declBit  (c+211,"top id_stage is_mem_load",-1);
	vcdp->declBus  (c+203,"top ex_stage ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top ex_stage DATA_WIDTH",-1,31,0);
	vcdp->declBit  (c+149,"top ex_stage clk",-1);
	vcdp->declBit  (c+150,"top ex_stage reset",-1);
	vcdp->declBit  (c+7,"top ex_stage ready",-1);
	vcdp->declBit  (c+27,"top ex_stage next_stage_ready",-1);
	vcdp->declBit  (c+5,"top ex_stage jump_signal",-1);
	vcdp->declQuad (c+3,"top ex_stage jump_pc",-1,63,0);
	vcdp->declBus  (c+143,"top ex_stage opcode",-1,31,0);
	vcdp->declQuad (c+31,"top ex_stage instruction_pc",-1,63,0);
	vcdp->declQuad (c+35,"top ex_stage r1_val",-1,63,0);
	vcdp->declQuad (c+37,"top ex_stage r2_val",-1,63,0);
	vcdp->declBus  (c+144,"top ex_stage imm",-1,20,0);
	vcdp->declBus  (c+40,"top ex_stage dst_reg",-1,4,0);
	vcdp->declBit  (c+41,"top ex_stage imm_or_reg2",-1);
	vcdp->declBus  (c+145,"top ex_stage mem_opcode",-1,31,0);
	vcdp->declBit  (c+43,"top ex_stage is_mem_load",-1);
	vcdp->declQuad (c+212,"top ex_stage ex_res",-1,63,0);
	vcdp->declQuad (c+37,"top ex_stage r2_val_mem",-1,63,0);
	vcdp->declBus  (c+40,"top ex_stage mem_dst_reg",-1,4,0);
	vcdp->declBus  (c+145,"top ex_stage next_mem_opcode",-1,31,0);
	vcdp->declBit  (c+43,"top ex_stage next_is_mem_load",-1);
	vcdp->declBus  (c+203,"top mem_stage ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+203,"top mem_stage DATA_WIDTH",-1,31,0);
	vcdp->declBit  (c+149,"top mem_stage clk",-1);
	vcdp->declBit  (c+150,"top mem_stage reset",-1);
	vcdp->declBit  (c+27,"top mem_stage ready",-1);
	vcdp->declQuad (c+44,"top mem_stage ex_res",-1,63,0);
	vcdp->declQuad (c+46,"top mem_stage r2_val",-1,63,0);
	vcdp->declBus  (c+48,"top mem_stage dst_reg",-1,4,0);
	vcdp->declBus  (c+146,"top mem_stage opcode",-1,31,0);
	vcdp->declBit  (c+50,"top mem_stage is_load",-1);
	vcdp->declBus  (c+214,"top mem_stage wb_dst_reg",-1,4,0);
	vcdp->declQuad (c+215,"top mem_stage wb_dst_val",-1,63,0);
	vcdp->declBit  (c+217,"top mem_stage wb_enable",-1);
	vcdp->declBus  (c+222,"top mem_stage IDLE",-1,1,0);
	vcdp->declBus  (c+223,"top mem_stage RW_OP",-1,1,0);
	vcdp->declBus  (c+147,"top mem_stage state",-1,1,0);
	vcdp->declBus  (c+15,"top mem_stage next_state",-1,1,0);
	vcdp->declBus  (c+148,"top mem_stage ctr",-1,2,0);
	vcdp->declBus  (c+16,"top mem_stage next_ctr",-1,2,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullQuad (c+1,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->fullQuad (c+3,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->fullBit  (c+5,(vlTOPp->top__DOT__jump_signal));
	vcdp->fullBit  (c+6,(((0U == vlTOPp->top__DOT__instruction) 
			      | (IData)(vlTOPp->top__DOT__ex_ready))));
	vcdp->fullBit  (c+7,(vlTOPp->top__DOT__ex_ready));
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->fullQuad (c+9,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->fullQuad (c+11,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->fullQuad (c+13,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->fullBus  (c+15,(vlTOPp->top__DOT__mem_stage__DOT__next_state),2);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__mem_stage__DOT__next_ctr),3);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__if_stage__DOT__next_state),2);
	vcdp->fullQuad (c+18,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_start),64);
	vcdp->fullQuad (c+20,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_data),64);
	vcdp->fullBus  (c+22,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_index),6);
	vcdp->fullBit  (c+23,(vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer));
	vcdp->fullQuad (c+24,(vlTOPp->top__DOT__pc),64);
	vcdp->fullBit  (c+26,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->fullBit  (c+27,((0U == (IData)(vlTOPp->top__DOT__mem_stage__DOT__state))));
	vcdp->fullBus  (c+28,(vlTOPp->top__DOT__instruction),32);
	vcdp->fullQuad (c+29,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->fullQuad (c+31,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->fullBus  (c+33,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->fullBus  (c+34,((0x7fU & (IData)(((0U 
						 == vlTOPp->top__DOT__instruction)
						 ? VL_ULL(0)
						 : (QData)((IData)(vlTOPp->top__DOT__instruction)))))),7);
	vcdp->fullQuad (c+35,(vlTOPp->top__DOT__r1_val),64);
	vcdp->fullQuad (c+37,(vlTOPp->top__DOT__r2_val),64);
	vcdp->fullBus  (c+39,(vlTOPp->top__DOT__imm),20);
	vcdp->fullBus  (c+40,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->fullBit  (c+41,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->fullBus  (c+42,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->fullBit  (c+43,(vlTOPp->top__DOT__is_mem_load_ex));
	vcdp->fullQuad (c+44,(vlTOPp->top__DOT__ex_res),64);
	vcdp->fullQuad (c+46,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->fullBus  (c+48,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->fullBus  (c+49,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->fullBit  (c+50,(vlTOPp->top__DOT__is_mem_load));
	vcdp->fullBus  (c+51,(vlTOPp->top__DOT__wb_dst_reg),5);
	vcdp->fullQuad (c+52,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->fullBit  (c+54,(vlTOPp->top__DOT__wb_enable));
	vcdp->fullQuad (c+55,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->fullQuad (c+57,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->fullQuad (c+59,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->fullQuad (c+61,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->fullQuad (c+63,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->fullQuad (c+65,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->fullQuad (c+67,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->fullQuad (c+69,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->fullQuad (c+71,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->fullQuad (c+73,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->fullQuad (c+75,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->fullQuad (c+77,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->fullQuad (c+79,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->fullQuad (c+81,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->fullQuad (c+83,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->fullQuad (c+85,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->fullQuad (c+87,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->fullQuad (c+89,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->fullQuad (c+91,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->fullQuad (c+93,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->fullQuad (c+95,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->fullQuad (c+97,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->fullQuad (c+99,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->fullQuad (c+101,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->fullQuad (c+103,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->fullQuad (c+105,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->fullQuad (c+107,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->fullQuad (c+109,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->fullQuad (c+111,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->fullQuad (c+113,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->fullQuad (c+115,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->fullQuad (c+117,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->fullBus  (c+119,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->fullArray(c+120,(vlTOPp->top__DOT__if_stage__DOT__instruction_buffer),512);
	vcdp->fullQuad (c+136,(vlTOPp->top__DOT__if_stage__DOT__buffer_start),64);
	vcdp->fullBus  (c+138,(vlTOPp->top__DOT__if_stage__DOT__buffer_index),6);
	vcdp->fullBit  (c+139,(vlTOPp->top__DOT__if_stage__DOT__empty_buffer));
	vcdp->fullBus  (c+140,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->fullQuad (c+141,(((0U == vlTOPp->top__DOT__instruction)
				 ? VL_ULL(0) : (QData)((IData)(vlTOPp->top__DOT__instruction)))),64);
	vcdp->fullBus  (c+143,(vlTOPp->top__DOT__ex_opcode),32);
	vcdp->fullBus  (c+144,((0x1fffffU & VL_EXTENDS_II(21,20, vlTOPp->top__DOT__imm))),21);
	vcdp->fullBus  (c+145,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->fullBus  (c+146,(vlTOPp->top__DOT__mem_opcode),32);
	vcdp->fullBus  (c+147,(vlTOPp->top__DOT__mem_stage__DOT__state),2);
	vcdp->fullBus  (c+148,(vlTOPp->top__DOT__mem_stage__DOT__ctr),3);
	vcdp->fullBit  (c+149,(vlTOPp->clk));
	vcdp->fullBit  (c+150,(vlTOPp->reset));
	vcdp->fullBit  (c+151,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+152,(vlTOPp->entry),64);
	vcdp->fullQuad (c+154,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+156,(vlTOPp->satp),64);
	vcdp->fullBus  (c+158,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+159,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+161,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+162,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+163,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+164,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+165,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+166,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+167,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+168,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+169,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+171,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+172,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+173,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+174,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+175,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+176,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+177,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+178,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+179,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+180,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+182,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+183,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+184,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+185,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+186,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+187,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+188,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+189,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+190,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+191,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+193,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+194,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+195,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+196,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+197,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+198,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+199,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+201,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+202,(0xdU),32);
	vcdp->fullBus  (c+203,(0x40U),32);
	vcdp->fullBus  (c+204,(8U),32);
	vcdp->fullQuad (c+205,(vlTOPp->top__DOT__next_ex_instr_pc),64);
	vcdp->fullBus  (c+207,((0xfffffU & vlTOPp->top__DOT____Vcellout__id_stage__imm)),20);
	vcdp->fullBus  (c+208,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->fullBit  (c+209,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->fullBus  (c+210,(vlTOPp->top__DOT____Vcellout__id_stage__mem_opcode),7);
	vcdp->fullBit  (c+211,(vlTOPp->top__DOT__next_is_mem_load_ex));
	vcdp->fullQuad (c+212,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->fullBus  (c+214,(vlTOPp->top__DOT__next_wb_dst_reg),5);
	vcdp->fullQuad (c+215,(vlTOPp->top__DOT__next_wb_dst_val),64);
	vcdp->fullBit  (c+217,(vlTOPp->top__DOT__next_wb_enable));
	vcdp->fullBus  (c+218,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->fullBus  (c+219,(vlTOPp->top__DOT__rf_reg2),5);
	vcdp->fullBit  (c+220,(1U));
	vcdp->fullBus  (c+221,(0x200U),32);
	vcdp->fullBus  (c+222,(0U),2);
	vcdp->fullBus  (c+223,(1U),2);
	vcdp->fullBus  (c+224,(2U),2);
	vcdp->fullBus  (c+225,(3U),2);
	vcdp->fullBus  (c+226,(vlTOPp->top__DOT____Vcellout__id_stage__imm),21);
	vcdp->fullBit  (c+227,(vlTOPp->top__DOT____Vcellout__id_stage__mem_opcode));
    }
}
