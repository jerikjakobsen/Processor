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
    VL_SIGW(__Vtemp110,511,0,16);
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
	VL_EXTEND_WI(512,32, __Vtemp110, vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA);
	vcdp->chgArray(c+14,(__Vtemp110),512);
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
	vcdp->chgBus  (c+97,((0x3fU & (IData)((vlTOPp->top__DOT__L1_D_S_W_ADDR 
					       >> 6U)))),6);
	vcdp->chgBus  (c+98,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+99,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+100,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+101,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
	vcdp->chgBit  (c+103,((VL_ULL(0x841a0) == vlTOPp->top__DOT__L1_D_S_R_ADDR)));
	vcdp->chgBit  (c+104,((VL_ULL(0x3fbffe68) == vlTOPp->top__DOT__L1_D_S_W_ADDR)));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+105,(((0x5aU == vlTOPp->top__DOT__instruction) 
			       | (IData)(vlTOPp->top__DOT__ex_ready))));
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+106,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgBit  (c+107,(vlTOPp->top__DOT__mem_ready));
	vcdp->chgQuad (c+108,(vlTOPp->top__DOT__bp_val),64);
	vcdp->chgQuad (c+110,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+112,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+114,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+116,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgBit  (c+117,(vlTOPp->top__DOT__next_ecall));
	vcdp->chgBit  (c+118,(vlTOPp->top__DOT__L1_D_S_W_COMPLETE));
	vcdp->chgBit  (c+119,(vlTOPp->top__DOT__L2_S_W_COMPLETE));
	vcdp->chgBit  (c+120,(vlTOPp->top__DOT__mem_raw_dep));
	vcdp->chgBus  (c+121,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgBus  (c+122,(vlTOPp->top__DOT__llc__DOT__next_w_state),3);
	vcdp->chgBus  (c+123,(vlTOPp->top__DOT__llc__DOT__next_r_state),3);
	vcdp->chgQuad (c+124,(vlTOPp->top__DOT__llc__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+126,(vlTOPp->top__DOT__llc__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+128,(vlTOPp->top__DOT__llc__DOT__next_latched_w_data_buffer),512);
	vcdp->chgArray(c+144,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
	vcdp->chgBus  (c+1276,(vlTOPp->top__DOT__llc__DOT__next_r_buffer_index),3);
	vcdp->chgBus  (c+1277,(vlTOPp->top__DOT__llc__DOT__next_w_buffer_index),3);
	vcdp->chgQuad (c+1278,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1280,(vlTOPp->top__DOT__llc__DOT__ac_addr_requested_index),6);
	vcdp->chgBit  (c+1281,(vlTOPp->top__DOT__llc__DOT__next_last_chosen));
	vcdp->chgBit  (c+1282,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_contains_request));
	vcdp->chgArray(c+1283,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_data),512);
	vcdp->chgQuad (c+1299,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1301,(vlTOPp->top__DOT__l1_d__DOT__next_state),3);
	vcdp->chgBus  (c+1302,(vlTOPp->top__DOT__l1_d__DOT__next_w_state),3);
	vcdp->chgQuad (c+1303,(vlTOPp->top__DOT__l1_d__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+1305,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+1307,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_data_buffer),512);
	vcdp->chgBit  (c+1323,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_contains_request));
	vcdp->chgQuad (c+1324,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_data),64);
	vcdp->chgQuad (c+1326,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+1328,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_size),2);
	vcdp->chgQuad (c+1329,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_tag),52);
	vcdp->chgBus  (c+1331,(vlTOPp->top__DOT__l1_d__DOT__ac_addr_requested_index),6);
	vcdp->chgBit  (c+1332,(vlTOPp->top__DOT__l1_d__DOT__next_evict_way));
	vcdp->chgBus  (c+1333,(vlTOPp->top__DOT__mem_stage__DOT__next_state),3);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1334,(vlTOPp->top__DOT__l1_d__DOT__next_r_state),3);
	vcdp->chgArray(c+1335,(vlTOPp->top__DOT__l1_d__DOT__next_cache),72448);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+3599,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->chgQuad (c+3601,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->chgBit  (c+3603,(vlTOPp->top__DOT__jump_signal));
	vcdp->chgBus  (c+3604,(vlTOPp->top__DOT__bp_reg),5);
	vcdp->chgBit  (c+3605,(vlTOPp->top__DOT__bp_add_reg_value));
	vcdp->chgBus  (c+3606,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+3607,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgQuad (c+3609,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->chgQuad (c+3611,(vlTOPp->top__DOT__L1_D_S_R_DATA),64);
	vcdp->chgBit  (c+3613,(vlTOPp->top__DOT__L1_D_S_R_DATA_VALID));
	vcdp->chgArray(c+3614,(vlTOPp->top__DOT__L2_S_R_DATA_I),512);
	vcdp->chgArray(c+3630,(vlTOPp->top__DOT__L2_S_R_DATA_D),512);
	vcdp->chgBit  (c+3646,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_I));
	vcdp->chgBit  (c+3647,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_D));
	vcdp->chgBit  (c+3648,(vlTOPp->top__DOT__ex_raw_dep));
	vcdp->chgBit  (c+3649,(vlTOPp->top__DOT__llc__DOT__conflicting_tags));
	vcdp->chgBit  (c+3650,(vlTOPp->top__DOT__llc__DOT__line1_active));
	vcdp->chgBit  (c+3651,(vlTOPp->top__DOT__llc__DOT__line2_active));
	vcdp->chgBit  (c+3652,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+3653,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+3654,(vlTOPp->top__DOT__llc__DOT__w_selected_data),512);
	vcdp->chgQuad (c+3670,(vlTOPp->top__DOT__llc__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+3672,(vlTOPp->top__DOT__llc__DOT__w_requested_index),6);
	vcdp->chgBit  (c+3673,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_valid));
	vcdp->chgBit  (c+3674,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_valid));
	vcdp->chgBit  (c+3675,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_dirty));
	vcdp->chgBit  (c+3676,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_dirty));
	vcdp->chgArray(c+3677,(vlTOPp->top__DOT__llc__DOT__r1_selected_data),512);
	vcdp->chgArray(c+3693,(vlTOPp->top__DOT__llc__DOT__r2_selected_data),512);
	vcdp->chgQuad (c+3709,(vlTOPp->top__DOT__llc__DOT__r1_requested_tag),52);
	vcdp->chgQuad (c+3711,(vlTOPp->top__DOT__llc__DOT__r2_requested_tag),52);
	vcdp->chgQuad (c+3713,(vlTOPp->top__DOT__llc__DOT__r1_selected_tag),52);
	vcdp->chgQuad (c+3715,(vlTOPp->top__DOT__llc__DOT__r2_selected_tag),52);
	vcdp->chgBus  (c+3717,(vlTOPp->top__DOT__llc__DOT__r1_requested_index),6);
	vcdp->chgBus  (c+3718,(vlTOPp->top__DOT__llc__DOT__r2_requested_index),6);
	vcdp->chgBit  (c+3719,(vlTOPp->top__DOT__llc__DOT__service_line));
	vcdp->chgBus  (c+3720,(vlTOPp->top__DOT__l1_i__DOT__next_state),3);
	vcdp->chgBus  (c+3721,(vlTOPp->top__DOT__l1_i__DOT__next_r_state),3);
	vcdp->chgQuad (c+3722,(vlTOPp->top__DOT__l1_i__DOT__next_latched_r_requested_address),64);
	vcdp->chgArray(c+3724,(vlTOPp->top__DOT__l1_i__DOT__next_cache),36160);
	vcdp->chgQuad (c+4854,(vlTOPp->top__DOT__l1_d__DOT__r_requested_tag),52);
	vcdp->chgBus  (c+4856,(vlTOPp->top__DOT__l1_d__DOT__r_requested_index),6);
	vcdp->chgBus  (c+4857,(vlTOPp->top__DOT__l1_d__DOT__r_requested_offset),6);
	vcdp->chgBit  (c+4858,(vlTOPp->top__DOT__l1_d__DOT__testing_cache_valid));
	vcdp->chgBus  (c+4859,(vlTOPp->top__DOT__if_stage__DOT__opcode),7);
	vcdp->chgQuad (c+4860,(vlTOPp->top__DOT__if_stage__DOT__imm),64);
	vcdp->chgQuad (c+4862,(vlTOPp->top__DOT__ex_stage__DOT__temp_result),64);
	vcdp->chgArray(c+4864,(vlTOPp->top__DOT__ex_stage__DOT__multiplication_result),128);
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
	vcdp->chgQuad (c+4868,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+4870,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+4871,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+4872,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+4874,(vlTOPp->top__DOT__id_bp_target),64);
	vcdp->chgQuad (c+4876,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgQuad (c+4878,(vlTOPp->top__DOT__ex_bp_target),64);
	vcdp->chgBus  (c+4880,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+4881,(vlTOPp->top__DOT__branch_type),4);
	vcdp->chgQuad (c+4882,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+4884,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgQuad (c+4886,(vlTOPp->top__DOT__imm),64);
	vcdp->chgBit  (c+4888,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+4889,(vlTOPp->top__DOT__unsigned_op),3);
	vcdp->chgBus  (c+4890,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+4891,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+4892,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBus  (c+4893,(vlTOPp->top__DOT__mem_operation_size_ex),4);
	vcdp->chgBit  (c+4894,(vlTOPp->top__DOT__ecall_ex));
	vcdp->chgQuad (c+4895,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+4897,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+4899,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+4900,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBus  (c+4901,(vlTOPp->top__DOT__mem_operation_size),4);
	vcdp->chgBus  (c+4902,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),4);
	vcdp->chgBit  (c+4903,(vlTOPp->top__DOT__ecall_mem));
	vcdp->chgBit  (c+4904,(vlTOPp->top__DOT__ecall));
	vcdp->chgBit  (c+4905,((2U == (IData)(vlTOPp->top__DOT__rf__DOT__ecall_state))));
	vcdp->chgBit  (c+4906,((1U & (~ (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+4907,((1U & (~ (IData)(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+4908,((VL_ULL(0x296ac) == vlTOPp->top__DOT__pc)));
	vcdp->chgQuad (c+4909,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+4911,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+4913,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+4915,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+4917,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+4919,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+4921,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+4923,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+4925,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+4927,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+4929,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+4931,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+4933,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+4935,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+4937,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+4939,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+4941,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+4943,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+4945,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+4947,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+4949,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+4951,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+4953,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+4955,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+4957,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+4959,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+4961,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+4963,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+4965,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+4967,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+4969,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+4971,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+4973,(vlTOPp->top__DOT__rf__DOT__ecall_state),3);
	vcdp->chgBus  (c+4974,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgBus  (c+4975,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgBus  (c+4976,(vlTOPp->top__DOT__llc__DOT__w_state),3);
	vcdp->chgBus  (c+4977,(vlTOPp->top__DOT__llc__DOT__r_state),3);
	vcdp->chgQuad (c+4978,(vlTOPp->top__DOT__llc__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+4980,(vlTOPp->top__DOT__llc__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+4982,(vlTOPp->top__DOT__llc__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+4998,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+6130,(vlTOPp->top__DOT__llc__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+6131,(vlTOPp->top__DOT__llc__DOT__w_buffer_index),3);
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
	vcdp->chgArray(c+6132,(__Vtemp114),512);
	vcdp->chgQuad (c+6148,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgQuad (c+6150,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6152,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+6153,(vlTOPp->top__DOT__llc__DOT__last_chosen));
	vcdp->chgBit  (c+6154,(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request));
	vcdp->chgArray(c+6155,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_data),512);
	vcdp->chgQuad (c+6171,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+6173,(vlTOPp->top__DOT__l1_i__DOT__state),3);
	vcdp->chgBus  (c+6174,(vlTOPp->top__DOT__l1_i__DOT__r_state),3);
	vcdp->chgQuad (c+6175,(vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address),64);
	vcdp->chgArray(c+6177,(vlTOPp->top__DOT__l1_i__DOT__cache),36160);
	vcdp->chgBus  (c+7307,(vlTOPp->top__DOT__l1_i__DOT__r_buffer_index),3);
	vcdp->chgQuad (c+7308,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+7310,((0x3fU & (IData)((vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+7311,(vlTOPp->top__DOT__l1_d__DOT__state),3);
	vcdp->chgBus  (c+7312,(vlTOPp->top__DOT__l1_d__DOT__w_state),3);
	vcdp->chgBus  (c+7313,(vlTOPp->top__DOT__l1_d__DOT__r_state),3);
	vcdp->chgQuad (c+7314,(vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+7316,(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+7318,(vlTOPp->top__DOT__l1_d__DOT__latched_w_data_buffer),512);
	vcdp->chgQuad (c+7334,((QData)((IData)((0x3fU 
						& (IData)(
							  (vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr 
							   >> 6U)))))),64);
	vcdp->chgQuad (c+7336,((QData)((IData)((0x3fU 
						& (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr))))),64);
	vcdp->chgArray(c+7338,(vlTOPp->top__DOT__l1_d__DOT__cache),72448);
	vcdp->chgBus  (c+9602,(vlTOPp->top__DOT__l1_d__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+9603,(vlTOPp->top__DOT__l1_d__DOT__w_buffer_index),3);
	vcdp->chgBit  (c+9604,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request));
	vcdp->chgQuad (c+9605,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_data),64);
	vcdp->chgQuad (c+9607,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+9609,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_size),2);
	vcdp->chgBit  (c+9610,(vlTOPp->top__DOT__l1_d__DOT__r_captured));
	vcdp->chgBit  (c+9611,(vlTOPp->top__DOT__l1_d__DOT__w_complete));
	vcdp->chgBit  (c+9612,(vlTOPp->top__DOT__l1_d__DOT__pending_cache_write));
	vcdp->chgQuad (c+9613,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+9615,((0x3fU & (IData)((vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+9616,(vlTOPp->top__DOT__l1_d__DOT__evict_way));
	vcdp->chgBus  (c+9617,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgBus  (c+9618,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+9619,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),3);
	vcdp->chgBit  (c+9620,((VL_ULL(0x4bc8c) == vlTOPp->top__DOT__ex_instr_pc)));
	vcdp->chgBus  (c+9621,(vlTOPp->top__DOT__mem_stage__DOT__state),3);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+9622,(vlTOPp->clk));
	vcdp->chgBit  (c+9623,(vlTOPp->reset));
	vcdp->chgBit  (c+9624,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+9625,(vlTOPp->entry),64);
	vcdp->chgQuad (c+9627,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+9629,(vlTOPp->satp),64);
	vcdp->chgBus  (c+9631,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+9632,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+9634,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+9635,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+9636,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+9637,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+9638,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+9639,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+9640,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+9641,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+9642,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+9644,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+9645,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+9646,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+9647,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+9648,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+9649,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+9650,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+9651,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+9652,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+9653,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+9655,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+9656,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+9657,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+9658,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+9659,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+9660,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+9661,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+9662,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+9663,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+9664,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+9666,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+9667,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+9668,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+9669,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+9670,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+9671,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+9672,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+9674,(vlTOPp->m_axi_acsnoop),4);
	vcdp->chgBit  (c+9675,((VL_ULL(0x3fbffe68) 
				== vlTOPp->m_axi_acaddr)));
	vcdp->chgBus  (c+9676,(vlTOPp->m_axi_acvalid),4);
    }
}
