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
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 3U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
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
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgBit  (c+2,(vlTOPp->top__DOT__mem_ready));
	vcdp->chgQuad (c+3,(vlTOPp->top__DOT__bp_val),64);
	vcdp->chgQuad (c+5,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+7,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+9,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+11,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgBit  (c+12,(vlTOPp->top__DOT__next_ecall));
	vcdp->chgBit  (c+13,(vlTOPp->top__DOT__next_pending_write));
	vcdp->chgQuad (c+14,(vlTOPp->top__DOT__next_pending_write_addr),64);
	vcdp->chgQuad (c+16,(vlTOPp->top__DOT__next_pending_write_data),64);
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__next_pending_write_size),2);
	vcdp->chgBit  (c+19,(vlTOPp->top__DOT__L1_D_S_W_COMPLETE));
	vcdp->chgBit  (c+20,(vlTOPp->top__DOT__L2_S_W_COMPLETE));
	vcdp->chgBit  (c+21,(vlTOPp->top__DOT__mem_raw_dep));
	vcdp->chgBus  (c+22,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgBus  (c+23,(vlTOPp->top__DOT__llc__DOT__next_w_state),3);
	vcdp->chgBus  (c+24,(vlTOPp->top__DOT__llc__DOT__next_r_state),3);
	vcdp->chgQuad (c+25,(vlTOPp->top__DOT__llc__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+27,(vlTOPp->top__DOT__llc__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+29,(vlTOPp->top__DOT__llc__DOT__next_latched_w_data_buffer),512);
	vcdp->chgArray(c+45,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
	vcdp->chgBus  (c+1177,(vlTOPp->top__DOT__llc__DOT__next_r_buffer_index),3);
	vcdp->chgBus  (c+1178,(vlTOPp->top__DOT__llc__DOT__next_w_buffer_index),3);
	vcdp->chgQuad (c+1179,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1181,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_index),6);
	vcdp->chgBit  (c+1182,(vlTOPp->top__DOT__llc__DOT__next_last_chosen));
	vcdp->chgBit  (c+1183,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_contains_request));
	vcdp->chgArray(c+1184,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_data),512);
	vcdp->chgQuad (c+1200,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1202,(vlTOPp->top__DOT__l1_d__DOT__next_state),3);
	vcdp->chgBus  (c+1203,(vlTOPp->top__DOT__l1_d__DOT__next_w_state),3);
	vcdp->chgQuad (c+1204,(vlTOPp->top__DOT__l1_d__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+1206,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+1208,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_data_buffer),512);
	vcdp->chgBit  (c+1224,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_contains_request));
	vcdp->chgQuad (c+1225,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_data),64);
	vcdp->chgQuad (c+1227,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1229,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_size),2);
	vcdp->chgQuad (c+1230,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1232,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_index),6);
	vcdp->chgBit  (c+1233,(vlTOPp->top__DOT__l1_d__DOT__next_evict_way));
	vcdp->chgBus  (c+1234,(vlTOPp->top__DOT__mem_stage__DOT__next_state),3);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1235,(((0x5aU == vlTOPp->top__DOT__instruction) 
				| (IData)(vlTOPp->top__DOT__ex_ready))));
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1236,(vlTOPp->top__DOT__l1_d__DOT__next_r_state),3);
	vcdp->chgArray(c+1237,(vlTOPp->top__DOT__l1_d__DOT__next_cache),72448);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp110,511,0,16);
    // Body
    {
	vcdp->chgBus  (c+3501,(vlTOPp->top__DOT__next_ex_opcode),7);
	vcdp->chgBus  (c+3502,(vlTOPp->top__DOT__next_branch_type),4);
	vcdp->chgQuad (c+3503,(vlTOPp->top__DOT__next_imm),64);
	vcdp->chgBit  (c+3505,(vlTOPp->top__DOT__next_is_word_op));
	vcdp->chgBus  (c+3506,(vlTOPp->top__DOT__next_unsigned_op),3);
	vcdp->chgBus  (c+3507,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->chgBit  (c+3508,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->chgBus  (c+3509,(vlTOPp->top__DOT__next_mem_opcode_ex),7);
	vcdp->chgBus  (c+3510,(vlTOPp->top__DOT__next_mem_operation_size_ex),4);
	vcdp->chgBit  (c+3511,(vlTOPp->top__DOT__next_ecall_ex));
	vcdp->chgBus  (c+3512,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->chgBus  (c+3513,(vlTOPp->top__DOT__rf_reg2),5);
	VL_EXTEND_WI(512,32, __Vtemp110, vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA);
	vcdp->chgArray(c+3514,(__Vtemp110),512);
	vcdp->chgBit  (c+3530,(vlTOPp->top__DOT__L1_I_S_R_DATA_VALID));
	vcdp->chgQuad (c+3531,(vlTOPp->top__DOT__L1_D_S_R_ADDR),64);
	vcdp->chgBit  (c+3533,(vlTOPp->top__DOT__L1_D_S_R_ADDR_VALID));
	vcdp->chgBit  (c+3534,(vlTOPp->top__DOT__L1_D_S_W_VALID));
	vcdp->chgQuad (c+3535,(vlTOPp->top__DOT__L1_D_S_W_ADDR),64);
	vcdp->chgQuad (c+3537,(vlTOPp->top__DOT__L1_D_S_W_DATA),64);
	vcdp->chgBus  (c+3539,(vlTOPp->top__DOT__L1_D_S_W_SIZE),4);
	vcdp->chgQuad (c+3540,(vlTOPp->top__DOT__L2_S_R_ADDR_I),64);
	vcdp->chgQuad (c+3542,(vlTOPp->top__DOT__L2_S_R_ADDR_D),64);
	vcdp->chgBit  (c+3544,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_I));
	vcdp->chgBit  (c+3545,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_D));
	vcdp->chgBit  (c+3546,(vlTOPp->top__DOT__L2_S_W_VALID));
	vcdp->chgQuad (c+3547,(vlTOPp->top__DOT__L2_S_W_ADDR),64);
	vcdp->chgArray(c+3549,(vlTOPp->top__DOT__L2_S_W_DATA),512);
	vcdp->chgBus  (c+3565,(vlTOPp->top__DOT__rf__DOT__next_ecall_state),3);
	vcdp->chgQuad (c+3566,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L2_S_W_ADDR 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+3568,(vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA),32);
	vcdp->chgBit  (c+3569,(vlTOPp->top__DOT__l1_i__DOT__r_selected_block_is_valid));
	vcdp->chgArray(c+3570,(vlTOPp->top__DOT__l1_i__DOT__r_selected_data),512);
	vcdp->chgQuad (c+3586,(vlTOPp->top__DOT__l1_i__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+3588,(vlTOPp->top__DOT__l1_i__DOT__r_selected_tag),52);
	vcdp->chgBus  (c+3590,(vlTOPp->top__DOT__l1_i__DOT__r_requested_index),6);
	vcdp->chgBus  (c+3591,(vlTOPp->top__DOT__l1_i__DOT__r_requested_offset),6);
	vcdp->chgBit  (c+3592,((VL_ULL(0x841a0) == vlTOPp->top__DOT__L1_D_S_W_ADDR)));
	vcdp->chgQuad (c+3593,(vlTOPp->top__DOT__l1_d__DOT__test3_signal),64);
	vcdp->chgQuad (c+3595,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L1_D_S_W_ADDR 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+3597,((0x3fU & (IData)((vlTOPp->top__DOT__L1_D_S_W_ADDR 
						 >> 6U)))),6);
	vcdp->chgBus  (c+3598,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+3599,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+3600,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+3601,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
	vcdp->chgBit  (c+3603,((VL_ULL(0x841a0) == vlTOPp->top__DOT__L1_D_S_R_ADDR)));
	vcdp->chgBit  (c+3604,((VL_ULL(0x959f8) == vlTOPp->top__DOT__L1_D_S_W_ADDR)));
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+3605,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->chgQuad (c+3607,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->chgBit  (c+3609,(vlTOPp->top__DOT__jump_signal));
	vcdp->chgBus  (c+3610,(vlTOPp->top__DOT__bp_reg),5);
	vcdp->chgBit  (c+3611,(vlTOPp->top__DOT__bp_add_reg_value));
	vcdp->chgBus  (c+3612,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+3613,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgQuad (c+3615,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->chgQuad (c+3617,(vlTOPp->top__DOT__L1_D_S_R_DATA),64);
	vcdp->chgBit  (c+3619,(vlTOPp->top__DOT__L1_D_S_R_DATA_VALID));
	vcdp->chgArray(c+3620,(vlTOPp->top__DOT__L2_S_R_DATA_I),512);
	vcdp->chgArray(c+3636,(vlTOPp->top__DOT__L2_S_R_DATA_D),512);
	vcdp->chgBit  (c+3652,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_I));
	vcdp->chgBit  (c+3653,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_D));
	vcdp->chgBit  (c+3654,(vlTOPp->top__DOT__ex_raw_dep));
	vcdp->chgBit  (c+3655,(vlTOPp->top__DOT__llc__DOT__conflicting_tags));
	vcdp->chgBit  (c+3656,(vlTOPp->top__DOT__llc__DOT__line1_active));
	vcdp->chgBit  (c+3657,(vlTOPp->top__DOT__llc__DOT__line2_active));
	vcdp->chgBit  (c+3658,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+3659,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+3660,(vlTOPp->top__DOT__llc__DOT__w_selected_data),512);
	vcdp->chgQuad (c+3676,(vlTOPp->top__DOT__llc__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+3678,(vlTOPp->top__DOT__llc__DOT__w_requested_index),6);
	vcdp->chgBit  (c+3679,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_valid));
	vcdp->chgBit  (c+3680,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_valid));
	vcdp->chgBit  (c+3681,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_dirty));
	vcdp->chgBit  (c+3682,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_dirty));
	vcdp->chgArray(c+3683,(vlTOPp->top__DOT__llc__DOT__r1_selected_data),512);
	vcdp->chgArray(c+3699,(vlTOPp->top__DOT__llc__DOT__r2_selected_data),512);
	vcdp->chgQuad (c+3715,(vlTOPp->top__DOT__llc__DOT__r1_requested_tag),52);
	vcdp->chgQuad (c+3717,(vlTOPp->top__DOT__llc__DOT__r2_requested_tag),52);
	vcdp->chgQuad (c+3719,(vlTOPp->top__DOT__llc__DOT__r1_selected_tag),52);
	vcdp->chgQuad (c+3721,(vlTOPp->top__DOT__llc__DOT__r2_selected_tag),52);
	vcdp->chgBus  (c+3723,(vlTOPp->top__DOT__llc__DOT__r1_requested_index),6);
	vcdp->chgBus  (c+3724,(vlTOPp->top__DOT__llc__DOT__r2_requested_index),6);
	vcdp->chgBit  (c+3725,(vlTOPp->top__DOT__llc__DOT__service_line));
	vcdp->chgBus  (c+3726,(vlTOPp->top__DOT__l1_i__DOT__next_state),3);
	vcdp->chgBus  (c+3727,(vlTOPp->top__DOT__l1_i__DOT__next_r_state),3);
	vcdp->chgQuad (c+3728,(vlTOPp->top__DOT__l1_i__DOT__next_latched_r_requested_address),64);
	vcdp->chgArray(c+3730,(vlTOPp->top__DOT__l1_i__DOT__next_cache),36160);
	vcdp->chgQuad (c+4860,(vlTOPp->top__DOT__l1_d__DOT__r_requested_tag),52);
	vcdp->chgBus  (c+4862,(vlTOPp->top__DOT__l1_d__DOT__r_requested_index),6);
	vcdp->chgBus  (c+4863,(vlTOPp->top__DOT__l1_d__DOT__r_requested_offset),6);
	vcdp->chgBit  (c+4864,(vlTOPp->top__DOT__l1_d__DOT__testing_cache_valid));
	vcdp->chgBus  (c+4865,(vlTOPp->top__DOT__if_stage__DOT__opcode),7);
	vcdp->chgQuad (c+4866,(vlTOPp->top__DOT__if_stage__DOT__imm),64);
	vcdp->chgQuad (c+4868,(vlTOPp->top__DOT__ex_stage__DOT__temp_result),64);
	vcdp->chgArray(c+4870,(vlTOPp->top__DOT__ex_stage__DOT__multiplication_result),128);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp114,511,0,16);
    // Body
    {
	vcdp->chgQuad (c+4874,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+4876,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+4877,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+4878,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+4880,(vlTOPp->top__DOT__id_bp_target),64);
	vcdp->chgQuad (c+4882,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgQuad (c+4884,(vlTOPp->top__DOT__ex_bp_target),64);
	vcdp->chgBus  (c+4886,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+4887,(vlTOPp->top__DOT__branch_type),4);
	vcdp->chgQuad (c+4888,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+4890,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgQuad (c+4892,(vlTOPp->top__DOT__imm),64);
	vcdp->chgBit  (c+4894,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+4895,(vlTOPp->top__DOT__unsigned_op),3);
	vcdp->chgBus  (c+4896,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+4897,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+4898,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBus  (c+4899,(vlTOPp->top__DOT__mem_operation_size_ex),4);
	vcdp->chgBit  (c+4900,(vlTOPp->top__DOT__ecall_ex));
	vcdp->chgQuad (c+4901,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+4903,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+4905,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+4906,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBus  (c+4907,(vlTOPp->top__DOT__mem_operation_size),4);
	vcdp->chgBus  (c+4908,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),4);
	vcdp->chgBit  (c+4909,(vlTOPp->top__DOT__ecall_mem));
	vcdp->chgBit  (c+4910,(vlTOPp->top__DOT__ecall));
	vcdp->chgBit  (c+4911,((2U == (IData)(vlTOPp->top__DOT__rf__DOT__ecall_state))));
	vcdp->chgBit  (c+4912,(vlTOPp->top__DOT__pending_write));
	vcdp->chgQuad (c+4913,(vlTOPp->top__DOT__pending_write_addr),64);
	vcdp->chgQuad (c+4915,(vlTOPp->top__DOT__pending_write_data),64);
	vcdp->chgBus  (c+4917,(vlTOPp->top__DOT__pending_write_size),2);
	vcdp->chgBit  (c+4918,((1U & (~ (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+4919,((1U & (~ (IData)(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+4920,((VL_ULL(0x296ac) == vlTOPp->top__DOT__pc)));
	vcdp->chgQuad (c+4921,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+4923,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+4925,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+4927,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+4929,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+4931,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+4933,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+4935,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+4937,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+4939,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+4941,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+4943,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+4945,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+4947,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+4949,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+4951,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+4953,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+4955,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+4957,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+4959,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+4961,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+4963,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+4965,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+4967,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+4969,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+4971,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+4973,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+4975,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+4977,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+4979,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+4981,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+4983,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+4985,(vlTOPp->top__DOT__rf__DOT__ecall_state),3);
	vcdp->chgBus  (c+4986,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgBus  (c+4987,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgBus  (c+4988,(vlTOPp->top__DOT__llc__DOT__w_state),3);
	vcdp->chgBus  (c+4989,(vlTOPp->top__DOT__llc__DOT__r_state),3);
	vcdp->chgQuad (c+4990,(vlTOPp->top__DOT__llc__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+4992,(vlTOPp->top__DOT__llc__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+4994,(vlTOPp->top__DOT__llc__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+5010,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+6142,(vlTOPp->top__DOT__llc__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+6143,(vlTOPp->top__DOT__llc__DOT__w_buffer_index),3);
	__Vtemp114[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp114[0xaU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp114[0xbU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp114[0xcU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp114[0xdU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp114[0xeU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp114[0xfU] = ((0x8d7fU >= (0xffffU & 
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
	vcdp->chgArray(c+6144,(__Vtemp114),512);
	vcdp->chgQuad (c+6160,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgQuad (c+6162,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6164,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+6165,(vlTOPp->top__DOT__llc__DOT__last_chosen));
	vcdp->chgBit  (c+6166,(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request));
	vcdp->chgArray(c+6167,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_data),512);
	vcdp->chgQuad (c+6183,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+6185,(vlTOPp->top__DOT__l1_i__DOT__state),3);
	vcdp->chgBus  (c+6186,(vlTOPp->top__DOT__l1_i__DOT__r_state),3);
	vcdp->chgQuad (c+6187,(vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address),64);
	vcdp->chgArray(c+6189,(vlTOPp->top__DOT__l1_i__DOT__cache),36160);
	vcdp->chgBus  (c+7319,(vlTOPp->top__DOT__l1_i__DOT__r_buffer_index),3);
	vcdp->chgQuad (c+7320,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+7322,((0x3fU & (IData)((vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+7323,(vlTOPp->top__DOT__l1_d__DOT__state),3);
	vcdp->chgBus  (c+7324,(vlTOPp->top__DOT__l1_d__DOT__w_state),3);
	vcdp->chgBus  (c+7325,(vlTOPp->top__DOT__l1_d__DOT__r_state),3);
	vcdp->chgQuad (c+7326,(vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+7328,(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+7330,(vlTOPp->top__DOT__l1_d__DOT__latched_w_data_buffer),512);
	vcdp->chgQuad (c+7346,((QData)((IData)((0x3fU 
						& (IData)(
							  (vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr 
							   >> 6U)))))),64);
	vcdp->chgQuad (c+7348,((QData)((IData)((0x3fU 
						& (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr))))),64);
	vcdp->chgArray(c+7350,(vlTOPp->top__DOT__l1_d__DOT__cache),72448);
	vcdp->chgBus  (c+9614,(vlTOPp->top__DOT__l1_d__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+9615,(vlTOPp->top__DOT__l1_d__DOT__w_buffer_index),3);
	vcdp->chgBit  (c+9616,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request));
	vcdp->chgQuad (c+9617,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_data),64);
	vcdp->chgQuad (c+9619,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+9621,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_size),2);
	vcdp->chgBit  (c+9622,(vlTOPp->top__DOT__l1_d__DOT__r_captured));
	vcdp->chgBit  (c+9623,(vlTOPp->top__DOT__l1_d__DOT__w_complete));
	vcdp->chgBit  (c+9624,(vlTOPp->top__DOT__l1_d__DOT__pending_cache_write));
	vcdp->chgQuad (c+9625,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+9627,((0x3fU & (IData)((vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+9628,(vlTOPp->top__DOT__l1_d__DOT__evict_way));
	vcdp->chgBus  (c+9629,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+9630,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),3);
	vcdp->chgBit  (c+9631,((VL_ULL(0x1aa6c) == vlTOPp->top__DOT__ex_instr_pc)));
	vcdp->chgBit  (c+9632,((VL_ULL(0x1ab24) == vlTOPp->top__DOT__ex_instr_pc)));
	vcdp->chgBus  (c+9633,(vlTOPp->top__DOT__mem_stage__DOT__state),3);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+9634,(vlTOPp->clk));
	vcdp->chgBit  (c+9635,(vlTOPp->reset));
	vcdp->chgBit  (c+9636,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+9637,(vlTOPp->entry),64);
	vcdp->chgQuad (c+9639,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+9641,(vlTOPp->satp),64);
	vcdp->chgBus  (c+9643,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+9644,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+9646,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+9647,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+9648,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+9649,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+9650,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+9651,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+9652,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+9653,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+9654,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+9656,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+9657,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+9658,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+9659,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+9660,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+9661,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+9662,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+9663,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+9664,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+9665,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+9667,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+9668,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+9669,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+9670,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+9671,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+9672,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+9673,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+9674,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+9675,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+9676,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+9678,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+9679,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+9680,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+9681,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+9682,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+9683,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+9684,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+9686,(vlTOPp->m_axi_acsnoop),4);
	vcdp->chgBit  (c+9687,((VL_ULL(0x3fbffe68) 
				== vlTOPp->m_axi_acaddr)));
	vcdp->chgBus  (c+9688,(vlTOPp->m_axi_acvalid),4);
    }
}
