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
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
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
	vcdp->chgBit  (c+6,(((0U == vlTOPp->top__DOT__instruction) 
			     | (IData)(vlTOPp->top__DOT__ex_ready))));
	vcdp->chgBit  (c+7,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgBus  (c+8,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+9,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgQuad (c+11,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+13,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__mem_stage__DOT__next_state),2);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__mem_stage__DOT__next_ctr),3);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__if_stage__DOT__next_state),2);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+18,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_start),64);
	vcdp->chgQuad (c+20,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_data),64);
	vcdp->chgBus  (c+22,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_index),6);
	vcdp->chgBit  (c+23,(vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+24,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+26,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBit  (c+27,((0U == (IData)(vlTOPp->top__DOT__mem_stage__DOT__state))));
	vcdp->chgBus  (c+28,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+29,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+31,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgBus  (c+33,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+34,((0x7fU & (IData)(((0U 
						== vlTOPp->top__DOT__instruction)
					        ? VL_ULL(0)
					        : (QData)((IData)(vlTOPp->top__DOT__instruction)))))),7);
	vcdp->chgQuad (c+35,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+37,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgBus  (c+39,(vlTOPp->top__DOT__imm),20);
	vcdp->chgBus  (c+40,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+41,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+42,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBit  (c+43,(vlTOPp->top__DOT__is_mem_load_ex));
	vcdp->chgQuad (c+44,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+46,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+48,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+49,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBit  (c+50,(vlTOPp->top__DOT__is_mem_load));
	vcdp->chgBus  (c+51,(vlTOPp->top__DOT__wb_dst_reg),5);
	vcdp->chgQuad (c+52,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+54,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgQuad (c+55,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+57,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+59,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+61,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+63,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+65,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+67,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+69,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+71,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+73,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+75,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+77,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+79,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+81,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+83,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+85,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+87,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+89,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+91,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+93,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+95,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+97,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+99,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+101,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+103,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+105,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+107,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+109,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+111,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+113,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+115,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+117,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+119,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgArray(c+120,(vlTOPp->top__DOT__if_stage__DOT__instruction_buffer),512);
	vcdp->chgQuad (c+136,(vlTOPp->top__DOT__if_stage__DOT__buffer_start),64);
	vcdp->chgBus  (c+138,(vlTOPp->top__DOT__if_stage__DOT__buffer_index),6);
	vcdp->chgBit  (c+139,(vlTOPp->top__DOT__if_stage__DOT__empty_buffer));
	vcdp->chgBus  (c+140,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgQuad (c+141,(((0U == vlTOPp->top__DOT__instruction)
			        ? VL_ULL(0) : (QData)((IData)(vlTOPp->top__DOT__instruction)))),64);
	vcdp->chgBus  (c+143,(vlTOPp->top__DOT__ex_opcode),32);
	vcdp->chgBus  (c+144,((0x1fffffU & VL_EXTENDS_II(21,20, vlTOPp->top__DOT__imm))),21);
	vcdp->chgBus  (c+145,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+146,(vlTOPp->top__DOT__mem_opcode),32);
	vcdp->chgBus  (c+147,(vlTOPp->top__DOT__mem_stage__DOT__state),2);
	vcdp->chgBus  (c+148,(vlTOPp->top__DOT__mem_stage__DOT__ctr),3);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+149,(vlTOPp->clk));
	vcdp->chgBit  (c+150,(vlTOPp->reset));
	vcdp->chgBit  (c+151,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+152,(vlTOPp->entry),64);
	vcdp->chgQuad (c+154,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+156,(vlTOPp->satp),64);
	vcdp->chgBus  (c+158,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+159,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+161,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+162,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+163,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+164,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+165,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+166,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+167,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+168,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+169,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+171,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+172,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+173,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+174,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+175,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+176,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+177,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+178,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+179,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+180,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+182,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+183,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+184,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+185,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+186,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+187,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+188,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+189,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+190,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+191,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+193,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+194,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+195,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+196,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+197,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+198,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+199,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+201,(vlTOPp->m_axi_acsnoop),4);
    }
}
