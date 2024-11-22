// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+1,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->chgQuad (c+3,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->chgBit  (c+5,(vlTOPp->top__DOT__jump_signal));
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+7,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgBus  (c+9,((0x7fU & (IData)(vlTOPp->top__DOT____Vcellout__id_stage__ex_opcode))),7);
	vcdp->chgBus  (c+10,((0xfffffU & vlTOPp->top__DOT____Vcellout__id_stage__imm)),20);
	vcdp->chgBit  (c+11,(vlTOPp->top__DOT__next_is_word_op));
	vcdp->chgBus  (c+12,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->chgBit  (c+13,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->chgBus  (c+14,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__rf_reg2),5);
	vcdp->chgArray(c+16,(vlTOPp->top__DOT__L1_I_S_R_DATA),512);
	vcdp->chgArray(c+32,(vlTOPp->top__DOT__L2_S_R_DATA),512);
	vcdp->chgQuad (c+48,(vlTOPp->top__DOT__llc__DOT__selected_tag),52);
	vcdp->chgBus  (c+50,(vlTOPp->top__DOT__llc__DOT__selected_state),2);
	vcdp->chgBit  (c+51,(vlTOPp->top__DOT__llc__DOT__selected_block_is_valid));
	vcdp->chgBit  (c+52,(vlTOPp->top__DOT__llc__DOT__selected_block_is_dirty));
	vcdp->chgArray(c+53,(vlTOPp->top__DOT__llc__DOT__selected_data),512);
	vcdp->chgBus  (c+69,(vlTOPp->top__DOT__llc__DOT__requested_index),6);
	vcdp->chgArray(c+70,(vlTOPp->top__DOT__llc__DOT__block),566);
	vcdp->chgQuad (c+88,(vlTOPp->top__DOT__l1_I__DOT__selected_tag),52);
	vcdp->chgBit  (c+90,(vlTOPp->top__DOT__l1_I__DOT__selected_block_is_valid));
	vcdp->chgArray(c+91,(vlTOPp->top__DOT__l1_I__DOT__selected_data),512);
	vcdp->chgBus  (c+107,(vlTOPp->top__DOT__l1_I__DOT__requested_index),6);
	vcdp->chgArray(c+108,(vlTOPp->top__DOT__l1_I__DOT__block),566);
	vcdp->chgQuad (c+126,(vlTOPp->top__DOT____Vcellout__id_stage__ex_opcode),64);
	vcdp->chgBus  (c+128,(vlTOPp->top__DOT____Vcellout__id_stage__imm),21);
	vcdp->chgBus  (c+129,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+130,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+131,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+132,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
	vcdp->chgBus  (c+134,(vlTOPp->top__DOT__mem_stage__DOT__next_state),2);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+135,(vlTOPp->top__DOT__if_stage__DOT__next_state),2);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+136,(vlTOPp->top__DOT__L1_I_S_R_DATA_VALID));
	vcdp->chgBit  (c+137,(vlTOPp->top__DOT__L2_S_R_DATA_VALID));
	vcdp->chgBus  (c+138,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgQuad (c+139,(vlTOPp->top__DOT__llc__DOT__next_latched_requested_address),64);
	vcdp->chgArray(c+141,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
	vcdp->chgBus  (c+1273,(vlTOPp->top__DOT__llc__DOT__next_buffer_index),3);
	vcdp->chgBus  (c+1274,(vlTOPp->top__DOT__l1_I__DOT__next_state),3);
	vcdp->chgQuad (c+1275,(vlTOPp->top__DOT__l1_I__DOT__next_latched_requested_address),64);
	vcdp->chgQuad (c+1277,(vlTOPp->top__DOT__l1_I__DOT__next_L2_S_R_ADDR),64);
	vcdp->chgBit  (c+1279,(vlTOPp->top__DOT__l1_I__DOT__next_L2_S_R_ADDR_VALID));
	vcdp->chgArray(c+1280,(vlTOPp->top__DOT__l1_I__DOT__next_cache),36160);
	vcdp->chgBus  (c+2410,(vlTOPp->top__DOT__l1_I__DOT__next_buffer_index),3);
	vcdp->chgArray(c+2411,(vlTOPp->top__DOT__if_stage__DOT__next_instruction_buffer),512);
	vcdp->chgQuad (c+2427,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_start),64);
	vcdp->chgBit  (c+2429,(vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer));
	vcdp->chgQuad (c+2430,(vlTOPp->top__DOT__if_stage__DOT__next_S_R_ADDR),64);
	vcdp->chgBit  (c+2432,(vlTOPp->top__DOT__if_stage__DOT__next_S_R_ADDR_VALID));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+2433,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+2435,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+2437,(vlTOPp->top__DOT__next_ex_res),64);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+2439,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+2441,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+2442,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+2443,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+2445,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgBus  (c+2447,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgQuad (c+2448,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+2450,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgBus  (c+2452,(vlTOPp->top__DOT__imm),20);
	vcdp->chgBit  (c+2453,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+2454,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+2455,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+2456,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBit  (c+2457,(vlTOPp->top__DOT__is_mem_load_ex));
	vcdp->chgQuad (c+2458,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+2460,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+2462,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+2463,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBit  (c+2464,(vlTOPp->top__DOT__is_mem_load));
	vcdp->chgBus  (c+2465,(vlTOPp->top__DOT__wb_dst_reg),5);
	vcdp->chgQuad (c+2466,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+2468,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgQuad (c+2469,(vlTOPp->top__DOT__L1_I_S_R_ADDR),64);
	vcdp->chgBit  (c+2471,(vlTOPp->top__DOT__L1_I_S_R_ADDR_VALID));
	vcdp->chgQuad (c+2472,(vlTOPp->top__DOT__L2_S_R_ADDR),64);
	vcdp->chgBit  (c+2474,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID));
	vcdp->chgQuad (c+2475,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+2477,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+2479,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+2481,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+2483,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+2485,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+2487,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+2489,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+2491,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+2493,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+2495,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+2497,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+2499,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+2501,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+2503,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+2505,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+2507,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+2509,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+2511,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+2513,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+2515,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+2517,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+2519,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+2521,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+2523,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+2525,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+2527,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+2529,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+2531,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+2533,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+2535,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+2537,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+2539,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgBus  (c+2540,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgQuad (c+2541,(vlTOPp->top__DOT__llc__DOT__latched_requested_address),64);
	vcdp->chgArray(c+2543,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+3675,(vlTOPp->top__DOT__llc__DOT__buffer_index),3);
	vcdp->chgQuad (c+3676,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L2_S_R_ADDR 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+3678,((0x3fU & (IData)(vlTOPp->top__DOT__L2_S_R_ADDR))),6);
	vcdp->chgQuad (c+3679,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+3681,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+3682,((0x3fU & (IData)(vlTOPp->top__DOT__llc__DOT__latched_requested_address))),6);
	vcdp->chgBus  (c+3683,(((IData)(0x36U) + ((
						   ((IData)(1U) 
						    + (IData)(vlTOPp->top__DOT__llc__DOT__buffer_index)) 
						   << 6U) 
						  - (IData)(1U)))),32);
	vcdp->chgBus  (c+3684,(vlTOPp->top__DOT__l1_I__DOT__state),3);
	vcdp->chgQuad (c+3685,(vlTOPp->top__DOT__l1_I__DOT__latched_requested_address),64);
	vcdp->chgArray(c+3687,(vlTOPp->top__DOT__l1_I__DOT__cache),36160);
	vcdp->chgBus  (c+4817,(vlTOPp->top__DOT__l1_I__DOT__buffer_index),3);
	vcdp->chgQuad (c+4818,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L1_I_S_R_ADDR 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+4820,((0x3fU & (IData)(vlTOPp->top__DOT__L1_I_S_R_ADDR))),6);
	vcdp->chgQuad (c+4821,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_I__DOT__latched_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+4823,((0x3fU & (IData)((vlTOPp->top__DOT__l1_I__DOT__latched_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+4824,((0x3fU & (IData)(vlTOPp->top__DOT__l1_I__DOT__latched_requested_address))),6);
	vcdp->chgArray(c+4825,(vlTOPp->top__DOT__if_stage__DOT__instruction_buffer),512);
	vcdp->chgQuad (c+4841,(vlTOPp->top__DOT__if_stage__DOT__buffer_start),64);
	vcdp->chgBit  (c+4843,(vlTOPp->top__DOT__if_stage__DOT__empty_buffer));
	vcdp->chgBus  (c+4844,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgBus  (c+4845,(vlTOPp->top__DOT__ex_opcode),32);
	vcdp->chgBus  (c+4846,((0x1fffffU & VL_EXTENDS_II(21,20, vlTOPp->top__DOT__imm))),21);
	vcdp->chgBus  (c+4847,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+4848,(vlTOPp->top__DOT__mem_opcode),32);
	vcdp->chgBus  (c+4849,(vlTOPp->top__DOT__mem_stage__DOT__state),2);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+4850,(vlTOPp->clk));
	vcdp->chgBit  (c+4851,(vlTOPp->reset));
	vcdp->chgBit  (c+4852,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+4853,(vlTOPp->entry),64);
	vcdp->chgQuad (c+4855,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+4857,(vlTOPp->satp),64);
	vcdp->chgBus  (c+4859,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+4860,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+4862,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+4863,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+4864,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+4865,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+4866,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+4867,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+4868,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+4869,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+4870,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+4872,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+4873,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+4874,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+4875,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+4876,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+4877,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+4878,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+4879,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+4880,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+4881,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+4883,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+4884,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+4885,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+4886,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+4887,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+4888,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+4889,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+4890,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+4891,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+4892,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+4894,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+4895,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+4896,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+4897,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+4898,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+4899,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+4900,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+4902,(vlTOPp->m_axi_acsnoop),4);
    }
}
