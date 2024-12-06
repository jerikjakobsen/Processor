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
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 2U)) | (vlTOPp->__Vm_traceActivity 
					      >> 3U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp128,511,0,16);
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->top__DOT__next_ex_opcode),7);
	vcdp->chgBus  (c+2,(vlTOPp->top__DOT__next_branch_type),4);
	vcdp->chgQuad (c+3,(vlTOPp->top__DOT__next_imm),64);
	vcdp->chgBit  (c+5,(vlTOPp->top__DOT__next_is_word_op));
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__next_unsigned_op),3);
	vcdp->chgBus  (c+7,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->chgBit  (c+8,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->chgBus  (c+9,(vlTOPp->top__DOT__next_mem_opcode_ex),7);
	vcdp->chgBus  (c+10,(vlTOPp->top__DOT__next_mem_operation_size_ex),4);
	vcdp->chgBit  (c+11,(vlTOPp->top__DOT__next_ecall_ex));
	vcdp->chgBus  (c+12,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->chgBus  (c+13,(vlTOPp->top__DOT__rf_reg2),5);
	VL_EXTEND_WI(512,32, __Vtemp128, vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA);
	vcdp->chgArray(c+14,(__Vtemp128),512);
	vcdp->chgBit  (c+30,(vlTOPp->top__DOT__L1_I_S_R_DATA_VALID));
	vcdp->chgQuad (c+31,(vlTOPp->top__DOT__L1_D_S_R_ADDR),64);
	vcdp->chgBit  (c+33,(vlTOPp->top__DOT__L1_D_S_R_ADDR_VALID));
	vcdp->chgBit  (c+34,(vlTOPp->top__DOT__L1_D_S_W_VALID));
	vcdp->chgQuad (c+35,(vlTOPp->top__DOT__L1_D_S_W_ADDR),64);
	vcdp->chgQuad (c+37,(vlTOPp->top__DOT__L1_D_S_W_DATA),64);
	vcdp->chgBus  (c+39,(vlTOPp->top__DOT__L1_D_S_W_SIZE),4);
	vcdp->chgQuad (c+40,(vlTOPp->top__DOT__L2_S_R_ADDR_I),64);
	vcdp->chgQuad (c+42,(vlTOPp->top__DOT__L2_S_R_ADDR_D),64);
	vcdp->chgBit  (c+44,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_I));
	vcdp->chgBit  (c+45,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_D));
	vcdp->chgBit  (c+46,(vlTOPp->top__DOT__L2_S_W_VALID));
	vcdp->chgQuad (c+47,(vlTOPp->top__DOT__L2_S_W_ADDR),64);
	vcdp->chgArray(c+49,(vlTOPp->top__DOT__L2_S_W_DATA),512);
	vcdp->chgBus  (c+65,(vlTOPp->top__DOT__rf__DOT__next_ecall_state),3);
	vcdp->chgQuad (c+66,((VL_ULL(0xfffffffffffff) 
			      & (vlTOPp->top__DOT__L2_S_W_ADDR 
				 >> 0xcU))),52);
	vcdp->chgBus  (c+68,(vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA),32);
	vcdp->chgBit  (c+69,(vlTOPp->top__DOT__l1_i__DOT__r_selected_block_is_valid));
	vcdp->chgArray(c+70,(vlTOPp->top__DOT__l1_i__DOT__r_selected_data),512);
	vcdp->chgQuad (c+86,(vlTOPp->top__DOT__l1_i__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+88,(vlTOPp->top__DOT__l1_i__DOT__r_selected_tag),52);
	vcdp->chgBus  (c+90,(vlTOPp->top__DOT__l1_i__DOT__r_requested_index),6);
	vcdp->chgBus  (c+91,(vlTOPp->top__DOT__l1_i__DOT__r_requested_offset),6);
	vcdp->chgBit  (c+92,((VL_ULL(0x841a0) == vlTOPp->top__DOT__L1_D_S_W_ADDR)));
	vcdp->chgQuad (c+93,(vlTOPp->top__DOT__l1_d__DOT__test3_signal),64);
	vcdp->chgQuad (c+95,((VL_ULL(0xfffffffffffff) 
			      & (vlTOPp->top__DOT__L1_D_S_W_ADDR 
				 >> 0xcU))),52);
	vcdp->chgBus  (c+97,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+98,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+99,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+100,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
	vcdp->chgBit  (c+102,((VL_ULL(0x841a0) == vlTOPp->top__DOT__L1_D_S_R_ADDR)));
	vcdp->chgBit  (c+103,((VL_ULL(0x3fbffe68) == vlTOPp->top__DOT__L1_D_S_W_ADDR)));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+104,(((0x5aU == vlTOPp->top__DOT__instruction) 
			       | (IData)(vlTOPp->top__DOT__ex_ready))));
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+105,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgBit  (c+106,(vlTOPp->top__DOT__mem_ready));
	vcdp->chgQuad (c+107,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+109,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+111,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+113,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgBit  (c+114,(vlTOPp->top__DOT__next_ecall));
	vcdp->chgBit  (c+115,(vlTOPp->top__DOT__L1_D_S_W_COMPLETE));
	vcdp->chgBit  (c+116,(vlTOPp->top__DOT__L2_S_W_COMPLETE));
	vcdp->chgBit  (c+117,(vlTOPp->top__DOT__mem_raw_dep));
	vcdp->chgBus  (c+118,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgBus  (c+119,(vlTOPp->top__DOT__llc__DOT__next_w_state),3);
	vcdp->chgBus  (c+120,(vlTOPp->top__DOT__llc__DOT__next_r_state),3);
	vcdp->chgQuad (c+121,(vlTOPp->top__DOT__llc__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+123,(vlTOPp->top__DOT__llc__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+125,(vlTOPp->top__DOT__llc__DOT__next_latched_w_data_buffer),512);
	vcdp->chgArray(c+141,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
	vcdp->chgBus  (c+1273,(vlTOPp->top__DOT__llc__DOT__next_r_buffer_index),3);
	vcdp->chgBus  (c+1274,(vlTOPp->top__DOT__llc__DOT__next_w_buffer_index),3);
	vcdp->chgQuad (c+1275,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1277,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_index),6);
	vcdp->chgBit  (c+1278,(vlTOPp->top__DOT__llc__DOT__next_last_chosen));
	vcdp->chgBit  (c+1279,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_contains_request));
	vcdp->chgArray(c+1280,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_data),512);
	vcdp->chgQuad (c+1296,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1298,(vlTOPp->top__DOT__l1_d__DOT__next_state),3);
	vcdp->chgBus  (c+1299,(vlTOPp->top__DOT__l1_d__DOT__next_w_state),3);
	vcdp->chgQuad (c+1300,(vlTOPp->top__DOT__l1_d__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+1302,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+1304,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_data_buffer),512);
	vcdp->chgBit  (c+1320,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_contains_request));
	vcdp->chgQuad (c+1321,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_data),64);
	vcdp->chgQuad (c+1323,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1325,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_size),2);
	vcdp->chgQuad (c+1326,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1328,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_index),6);
	vcdp->chgBus  (c+1329,(vlTOPp->top__DOT__mem_stage__DOT__next_state),3);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1330,(vlTOPp->top__DOT__l1_d__DOT__next_r_state),3);
	vcdp->chgArray(c+1331,(vlTOPp->top__DOT__l1_d__DOT__next_cache),36224);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+2463,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->chgQuad (c+2465,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->chgBit  (c+2467,(vlTOPp->top__DOT__jump_signal));
	vcdp->chgBus  (c+2468,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+2469,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgQuad (c+2471,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->chgQuad (c+2473,(vlTOPp->top__DOT__L1_D_S_R_DATA),64);
	vcdp->chgBit  (c+2475,(vlTOPp->top__DOT__L1_D_S_R_DATA_VALID));
	vcdp->chgArray(c+2476,(vlTOPp->top__DOT__L2_S_R_DATA_I),512);
	vcdp->chgArray(c+2492,(vlTOPp->top__DOT__L2_S_R_DATA_D),512);
	vcdp->chgBit  (c+2508,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_I));
	vcdp->chgBit  (c+2509,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_D));
	vcdp->chgBit  (c+2510,(vlTOPp->top__DOT__ex_raw_dep));
	vcdp->chgBit  (c+2511,(vlTOPp->top__DOT__llc__DOT__conflicting_tags));
	vcdp->chgBit  (c+2512,(vlTOPp->top__DOT__llc__DOT__line1_active));
	vcdp->chgBit  (c+2513,(vlTOPp->top__DOT__llc__DOT__line2_active));
	vcdp->chgBit  (c+2514,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+2515,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+2516,(vlTOPp->top__DOT__llc__DOT__w_selected_data),512);
	vcdp->chgQuad (c+2532,(vlTOPp->top__DOT__llc__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+2534,(vlTOPp->top__DOT__llc__DOT__w_requested_index),6);
	vcdp->chgBit  (c+2535,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_valid));
	vcdp->chgBit  (c+2536,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_valid));
	vcdp->chgBit  (c+2537,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_dirty));
	vcdp->chgBit  (c+2538,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_dirty));
	vcdp->chgArray(c+2539,(vlTOPp->top__DOT__llc__DOT__r1_selected_data),512);
	vcdp->chgArray(c+2555,(vlTOPp->top__DOT__llc__DOT__r2_selected_data),512);
	vcdp->chgQuad (c+2571,(vlTOPp->top__DOT__llc__DOT__r1_requested_tag),52);
	vcdp->chgQuad (c+2573,(vlTOPp->top__DOT__llc__DOT__r2_requested_tag),52);
	vcdp->chgQuad (c+2575,(vlTOPp->top__DOT__llc__DOT__r1_selected_tag),52);
	vcdp->chgQuad (c+2577,(vlTOPp->top__DOT__llc__DOT__r2_selected_tag),52);
	vcdp->chgBus  (c+2579,(vlTOPp->top__DOT__llc__DOT__r1_requested_index),6);
	vcdp->chgBus  (c+2580,(vlTOPp->top__DOT__llc__DOT__r2_requested_index),6);
	vcdp->chgBit  (c+2581,(vlTOPp->top__DOT__llc__DOT__service_line));
	vcdp->chgBus  (c+2582,(vlTOPp->top__DOT__l1_i__DOT__next_state),3);
	vcdp->chgBus  (c+2583,(vlTOPp->top__DOT__l1_i__DOT__next_r_state),3);
	vcdp->chgQuad (c+2584,(vlTOPp->top__DOT__l1_i__DOT__next_latched_r_requested_address),64);
	vcdp->chgArray(c+2586,(vlTOPp->top__DOT__l1_i__DOT__next_cache),36160);
	vcdp->chgBit  (c+3716,(vlTOPp->top__DOT__l1_d__DOT__conflicting_tags));
	vcdp->chgBit  (c+3717,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_valid));
	vcdp->chgBit  (c+3718,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+3719,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_dirty));
	vcdp->chgBit  (c+3720,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+3721,(vlTOPp->top__DOT__l1_d__DOT__r_selected_data),512);
	vcdp->chgArray(c+3737,(vlTOPp->top__DOT__l1_d__DOT__w_selected_data),512);
	vcdp->chgQuad (c+3753,(vlTOPp->top__DOT__l1_d__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+3755,(vlTOPp->top__DOT__l1_d__DOT__r_selected_tag),52);
	vcdp->chgQuad (c+3757,(vlTOPp->top__DOT__l1_d__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+3759,(vlTOPp->top__DOT__l1_d__DOT__r_requested_index),6);
	vcdp->chgBus  (c+3760,(vlTOPp->top__DOT__l1_d__DOT__w_requested_index),6);
	vcdp->chgBus  (c+3761,(vlTOPp->top__DOT__l1_d__DOT__r_requested_offset),6);
	vcdp->chgQuad (c+3762,(vlTOPp->top__DOT__ex_stage__DOT__temp_result),64);
	vcdp->chgArray(c+3764,(vlTOPp->top__DOT__ex_stage__DOT__multiplication_result),128);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp132,511,0,16);
    VL_SIGW(__Vtemp136,511,0,16);
    // Body
    {
	vcdp->chgQuad (c+3768,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+3770,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+3771,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+3772,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+3774,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgBus  (c+3776,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+3777,(vlTOPp->top__DOT__branch_type),4);
	vcdp->chgQuad (c+3778,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+3780,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgQuad (c+3782,(vlTOPp->top__DOT__imm),64);
	vcdp->chgBit  (c+3784,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+3785,(vlTOPp->top__DOT__unsigned_op),3);
	vcdp->chgBus  (c+3786,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+3787,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+3788,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBus  (c+3789,(vlTOPp->top__DOT__mem_operation_size_ex),4);
	vcdp->chgBit  (c+3790,(vlTOPp->top__DOT__ecall_ex));
	vcdp->chgQuad (c+3791,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+3793,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+3795,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+3796,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBus  (c+3797,(vlTOPp->top__DOT__mem_operation_size),4);
	vcdp->chgBus  (c+3798,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),4);
	vcdp->chgBit  (c+3799,(vlTOPp->top__DOT__ecall_mem));
	vcdp->chgBit  (c+3800,(vlTOPp->top__DOT__ecall));
	vcdp->chgBit  (c+3801,((2U == (IData)(vlTOPp->top__DOT__rf__DOT__ecall_state))));
	vcdp->chgBit  (c+3802,((1U & (~ (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+3803,((1U & (~ (IData)(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+3804,((VL_ULL(0x296ac) == vlTOPp->top__DOT__pc)));
	vcdp->chgQuad (c+3805,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+3807,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+3809,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+3811,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+3813,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+3815,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+3817,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+3819,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+3821,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+3823,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+3825,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+3827,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+3829,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+3831,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+3833,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+3835,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+3837,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+3839,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+3841,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+3843,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+3845,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+3847,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+3849,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+3851,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+3853,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+3855,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+3857,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+3859,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+3861,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+3863,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+3865,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+3867,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+3869,(vlTOPp->top__DOT__rf__DOT__ecall_state),3);
	vcdp->chgBus  (c+3870,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgBus  (c+3871,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgBus  (c+3872,(vlTOPp->top__DOT__llc__DOT__w_state),3);
	vcdp->chgBus  (c+3873,(vlTOPp->top__DOT__llc__DOT__r_state),3);
	vcdp->chgQuad (c+3874,(vlTOPp->top__DOT__llc__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+3876,(vlTOPp->top__DOT__llc__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+3878,(vlTOPp->top__DOT__llc__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+3894,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+5026,(vlTOPp->top__DOT__llc__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+5027,(vlTOPp->top__DOT__llc__DOT__w_buffer_index),3);
	__Vtemp132[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(1U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 (0x7ffU & (((IData)(0x36U) 
					     + ((IData)(0x236U) 
						* (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					    >> 5U))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(2U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(1U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(3U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(2U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(4U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(3U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(5U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(4U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(6U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(5U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(7U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(6U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(8U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(7U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(9U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(8U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					((IData)(0xaU) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__llc__DOT__cache[
				 ((IData)(9U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp132[0xaU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0xbU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xaU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp132[0xbU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0xcU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xbU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp132[0xcU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0xdU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xcU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp132[0xdU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0xeU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xdU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp132[0xeU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0xfU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xeU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp132[0xfU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__llc__DOT__cache[
					  ((IData)(0x10U) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__llc__DOT__cache[
				   ((IData)(0xfU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
			     : 0U);
	vcdp->chgArray(c+5028,(__Vtemp132),512);
	vcdp->chgQuad (c+5044,((VL_ULL(0xfffffffffffff) 
				& ((0x8d7fU >= (0xffffU 
						& ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))
				    ? (((0U == (0x1fU 
						& ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))
					 ? VL_ULL(0)
					 : ((QData)((IData)(
							    vlTOPp->top__DOT__llc__DOT__cache[
							    ((IData)(2U) 
							     + 
							     (0x7ffU 
							      & (((IData)(0x236U) 
								  * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)) 
								 >> 5U)))])) 
					    << ((IData)(0x40U) 
						- (0x1fU 
						   & ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))) 
				       | (((QData)((IData)(
							   vlTOPp->top__DOT__llc__DOT__cache[
							   ((IData)(1U) 
							    + 
							    (0x7ffU 
							     & (((IData)(0x236U) 
								 * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)) 
								>> 5U)))])) 
					   << ((0U 
						== 
						(0x1fU 
						 & ((IData)(0x236U) 
						    * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))
					        ? 0x20U
					        : ((IData)(0x20U) 
						   - 
						   (0x1fU 
						    & ((IData)(0x236U) 
						       * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)))))) 
					  | ((QData)((IData)(
							     vlTOPp->top__DOT__llc__DOT__cache[
							     (0x7ffU 
							      & (((IData)(0x236U) 
								  * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index)) 
								 >> 5U))])) 
					     >> (0x1fU 
						 & ((IData)(0x236U) 
						    * (IData)(vlTOPp->top__DOT__llc__DOT__latched_w_requested_index))))))
				    : VL_ULL(0)))),52);
	vcdp->chgQuad (c+5046,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+5048,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+5049,(vlTOPp->top__DOT__llc__DOT__last_chosen));
	vcdp->chgBit  (c+5050,(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request));
	vcdp->chgArray(c+5051,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_data),512);
	vcdp->chgQuad (c+5067,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+5069,(vlTOPp->top__DOT__l1_i__DOT__state),3);
	vcdp->chgBus  (c+5070,(vlTOPp->top__DOT__l1_i__DOT__r_state),3);
	vcdp->chgQuad (c+5071,(vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address),64);
	vcdp->chgArray(c+5073,(vlTOPp->top__DOT__l1_i__DOT__cache),36160);
	vcdp->chgBus  (c+6203,(vlTOPp->top__DOT__l1_i__DOT__r_buffer_index),3);
	vcdp->chgQuad (c+6204,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6206,((0x3fU & (IData)((vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+6207,(vlTOPp->top__DOT__l1_d__DOT__state),3);
	vcdp->chgBus  (c+6208,(vlTOPp->top__DOT__l1_d__DOT__w_state),3);
	vcdp->chgBus  (c+6209,(vlTOPp->top__DOT__l1_d__DOT__r_state),3);
	vcdp->chgQuad (c+6210,(vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+6212,(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+6214,(vlTOPp->top__DOT__l1_d__DOT__latched_w_data_buffer),512);
	vcdp->chgQuad (c+6230,((QData)((IData)((0x3fU 
						& (IData)(
							  (vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr 
							   >> 6U)))))),64);
	vcdp->chgQuad (c+6232,((QData)((IData)((0x3fU 
						& (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr))))),64);
	vcdp->chgArray(c+6234,(vlTOPp->top__DOT__l1_d__DOT__cache),36224);
	vcdp->chgBus  (c+7366,(vlTOPp->top__DOT__l1_d__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+7367,(vlTOPp->top__DOT__l1_d__DOT__w_buffer_index),3);
	vcdp->chgBit  (c+7368,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request));
	vcdp->chgQuad (c+7369,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_data),64);
	vcdp->chgQuad (c+7371,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+7373,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_size),2);
	vcdp->chgBit  (c+7374,(vlTOPp->top__DOT__l1_d__DOT__r_captured));
	vcdp->chgBit  (c+7375,(vlTOPp->top__DOT__l1_d__DOT__w_complete));
	vcdp->chgBit  (c+7376,(vlTOPp->top__DOT__l1_d__DOT__pending_cache_write));
	__Vtemp136[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(1U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 (0x7ffU & (((IData)(0x36U) 
					     + ((IData)(0x236U) 
						* (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					    >> 5U))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(2U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(1U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(3U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(2U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(4U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(3U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(5U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(4U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(6U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(5U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(7U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(6U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(8U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(7U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(9U) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(8U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			   ? (((0U == (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			        ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					((IData)(0xaU) 
					 + (0x7ffU 
					    & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
					<< ((IData)(0x20U) 
					    - (0x1fU 
					       & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
			      | (vlTOPp->top__DOT__l1_d__DOT__cache[
				 ((IData)(9U) + (0x7ffU 
						 & (((IData)(0x36U) 
						     + 
						     ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						    >> 5U)))] 
				 >> (0x1fU & ((IData)(0x36U) 
					      + ((IData)(0x236U) 
						 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			   : 0U);
	__Vtemp136[0xaU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0xbU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xaU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp136[0xbU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0xcU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xbU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp136[0xcU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0xdU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xcU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp136[0xdU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0xeU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xdU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp136[0xeU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0xfU) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xeU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	__Vtemp136[0xfU] = ((0x8d7fU >= (0xffffU & 
					 ((IData)(0x36U) 
					  + ((IData)(0x236U) 
					     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
			     ? (((0U == (0x1fU & ((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))
				  ? 0U : (vlTOPp->top__DOT__l1_d__DOT__cache[
					  ((IData)(0x10U) 
					   + (0x7ffU 
					      & (((IData)(0x36U) 
						  + 
						  ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
						 >> 5U)))] 
					  << ((IData)(0x20U) 
					      - (0x1fU 
						 & ((IData)(0x36U) 
						    + 
						    ((IData)(0x236U) 
						     * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))) 
				| (vlTOPp->top__DOT__l1_d__DOT__cache[
				   ((IData)(0xfU) + 
				    (0x7ffU & (((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))) 
					       >> 5U)))] 
				   >> (0x1fU & ((IData)(0x36U) 
						+ ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
			     : 0U);
	vcdp->chgArray(c+7377,(__Vtemp136),512);
	vcdp->chgQuad (c+7393,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+7395,((VL_ULL(0xfffffffffffff) 
				& ((0x8d7fU >= (0xffffU 
						& ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))
				    ? (((0U == (0x1fU 
						& ((IData)(0x236U) 
						   * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))
					 ? VL_ULL(0)
					 : ((QData)((IData)(
							    vlTOPp->top__DOT__l1_d__DOT__cache[
							    ((IData)(2U) 
							     + 
							     (0x7ffU 
							      & (((IData)(0x236U) 
								  * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)) 
								 >> 5U)))])) 
					    << ((IData)(0x40U) 
						- (0x1fU 
						   & ((IData)(0x236U) 
						      * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))) 
				       | (((QData)((IData)(
							   vlTOPp->top__DOT__l1_d__DOT__cache[
							   ((IData)(1U) 
							    + 
							    (0x7ffU 
							     & (((IData)(0x236U) 
								 * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)) 
								>> 5U)))])) 
					   << ((0U 
						== 
						(0x1fU 
						 & ((IData)(0x236U) 
						    * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))
					        ? 0x20U
					        : ((IData)(0x20U) 
						   - 
						   (0x1fU 
						    & ((IData)(0x236U) 
						       * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)))))) 
					  | ((QData)((IData)(
							     vlTOPp->top__DOT__l1_d__DOT__cache[
							     (0x7ffU 
							      & (((IData)(0x236U) 
								  * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index)) 
								 >> 5U))])) 
					     >> (0x1fU 
						 & ((IData)(0x236U) 
						    * (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_index))))))
				    : VL_ULL(0)))),52);
	vcdp->chgBus  (c+7397,((0x3fU & (IData)((vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+7398,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgBus  (c+7399,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+7400,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),3);
	vcdp->chgBit  (c+7401,((VL_ULL(0x1aa6c) == vlTOPp->top__DOT__ex_instr_pc)));
	vcdp->chgBus  (c+7402,(vlTOPp->top__DOT__mem_stage__DOT__state),3);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+7403,(vlTOPp->clk));
	vcdp->chgBit  (c+7404,(vlTOPp->reset));
	vcdp->chgBit  (c+7405,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+7406,(vlTOPp->entry),64);
	vcdp->chgQuad (c+7408,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+7410,(vlTOPp->satp),64);
	vcdp->chgBus  (c+7412,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+7413,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+7415,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+7416,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+7417,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+7418,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+7419,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+7420,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+7421,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+7422,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+7423,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+7425,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+7426,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+7427,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+7428,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+7429,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+7430,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+7431,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+7432,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+7433,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+7434,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+7436,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+7437,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+7438,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+7439,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+7440,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+7441,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+7442,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+7443,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+7444,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+7445,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+7447,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+7448,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+7449,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+7450,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+7451,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+7452,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+7453,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+7455,(vlTOPp->m_axi_acsnoop),4);
	vcdp->chgBit  (c+7456,((VL_ULL(0x3fbffe68) 
				== vlTOPp->m_axi_acaddr)));
	vcdp->chgBus  (c+7457,(vlTOPp->m_axi_acvalid),4);
    }
}
