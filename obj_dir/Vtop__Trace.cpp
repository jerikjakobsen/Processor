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
					      >> 3U))))) {
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
    VL_SIGW(__Vtemp111,511,0,16);
    VL_SIGW(__Vtemp112,511,0,16);
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->top__DOT__next_ex_opcode),7);
	vcdp->chgBus  (c+2,(vlTOPp->top__DOT__next_branch_type),4);
	vcdp->chgBit  (c+3,(vlTOPp->top__DOT__next_ecall_ex));
	vcdp->chgQuad (c+4,(vlTOPp->top__DOT__next_imm),64);
	vcdp->chgBit  (c+6,(vlTOPp->top__DOT__next_is_word_op));
	vcdp->chgBus  (c+7,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->chgBit  (c+8,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->chgBus  (c+9,(vlTOPp->top__DOT__next_mem_opcode_ex),7);
	vcdp->chgBus  (c+10,(vlTOPp->top__DOT__next_mem_operation_size_ex),4);
	vcdp->chgBus  (c+11,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->chgBus  (c+12,(vlTOPp->top__DOT__rf_reg2),5);
	VL_EXTEND_WI(512,32, __Vtemp111, vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA);
	vcdp->chgArray(c+13,(__Vtemp111),512);
	vcdp->chgBit  (c+29,(vlTOPp->top__DOT__L1_I_S_R_DATA_VALID));
	vcdp->chgQuad (c+30,(vlTOPp->top__DOT__L1_D_S_R_ADDR),64);
	vcdp->chgBit  (c+32,(vlTOPp->top__DOT__L1_D_S_R_ADDR_VALID));
	vcdp->chgBit  (c+33,(vlTOPp->top__DOT__L1_D_S_W_VALID));
	vcdp->chgQuad (c+34,(vlTOPp->top__DOT__L1_D_S_W_ADDR),64);
	vcdp->chgQuad (c+36,(vlTOPp->top__DOT__L1_D_S_W_DATA),64);
	vcdp->chgQuad (c+38,(vlTOPp->top__DOT__L2_S_R_ADDR_I),64);
	vcdp->chgQuad (c+40,(vlTOPp->top__DOT__L2_S_R_ADDR_D),64);
	vcdp->chgBit  (c+42,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_I));
	vcdp->chgBit  (c+43,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_D));
	vcdp->chgBit  (c+44,(vlTOPp->top__DOT__L2_S_W_VALID));
	vcdp->chgQuad (c+45,(vlTOPp->top__DOT__L2_S_W_ADDR),64);
	vcdp->chgQuad (c+47,((((QData)((IData)(vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[1U])) 
			       << 0x20U) | (QData)((IData)(
							   vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[0U])))),64);
	VL_EXTEND_WQ(512,64, __Vtemp112, (((QData)((IData)(
							   vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[1U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[0U]))));
	vcdp->chgArray(c+49,(__Vtemp112),512);
	vcdp->chgQuad (c+65,((VL_ULL(0xfffffffffffff) 
			      & (vlTOPp->top__DOT__L2_S_W_ADDR 
				 >> 0xcU))),52);
	vcdp->chgBus  (c+67,(vlTOPp->top__DOT____Vcellout__l1_i__S_R_DATA),32);
	vcdp->chgBit  (c+68,(vlTOPp->top__DOT__l1_i__DOT__r_selected_block_is_valid));
	vcdp->chgArray(c+69,(vlTOPp->top__DOT__l1_i__DOT__r_selected_data),512);
	vcdp->chgQuad (c+85,(vlTOPp->top__DOT__l1_i__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+87,(vlTOPp->top__DOT__l1_i__DOT__r_selected_tag),52);
	vcdp->chgBus  (c+89,(vlTOPp->top__DOT__l1_i__DOT__r_requested_index),6);
	vcdp->chgBus  (c+90,(vlTOPp->top__DOT__l1_i__DOT__r_requested_offset),6);
	vcdp->chgArray(c+91,(vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA),512);
	vcdp->chgQuad (c+107,((VL_ULL(0xfffffffffffff) 
			       & (vlTOPp->top__DOT__L1_D_S_W_ADDR 
				  >> 0xcU))),52);
	vcdp->chgBus  (c+109,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+110,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+111,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+112,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
	vcdp->chgBus  (c+114,(vlTOPp->top__DOT__mem_stage__DOT__S_W_SIZE),2);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+115,(((0U == vlTOPp->top__DOT__instruction) 
			       | (IData)(vlTOPp->top__DOT__ex_ready))));
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+116,(vlTOPp->top__DOT__llc__DOT__next_r_buffer_index),3);
	vcdp->chgBus  (c+117,(vlTOPp->top__DOT__llc__DOT__next_w_buffer_index),3);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+118,(vlTOPp->top__DOT__llc__DOT__next_w_state),3);
	vcdp->chgBus  (c+119,(vlTOPp->top__DOT__llc__DOT__next_r_state),3);
	vcdp->chgArray(c+120,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+1252,(vlTOPp->top__DOT__next_if_pc),64);
	vcdp->chgQuad (c+1254,(vlTOPp->top__DOT__jump_pc),64);
	vcdp->chgBit  (c+1256,(vlTOPp->top__DOT__jump_signal));
	vcdp->chgBit  (c+1257,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgBit  (c+1258,(vlTOPp->top__DOT__mem_ready));
	vcdp->chgBus  (c+1259,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+1260,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgQuad (c+1262,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+1264,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+1266,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->chgQuad (c+1268,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+1270,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgQuad (c+1271,(vlTOPp->top__DOT__L1_D_S_R_DATA),64);
	vcdp->chgBit  (c+1273,(vlTOPp->top__DOT__L1_D_S_R_DATA_VALID));
	vcdp->chgBit  (c+1274,(vlTOPp->top__DOT__L1_D_S_W_COMPLETE));
	vcdp->chgArray(c+1275,(vlTOPp->top__DOT__L2_S_R_DATA_I),512);
	vcdp->chgArray(c+1291,(vlTOPp->top__DOT__L2_S_R_DATA_D),512);
	vcdp->chgBit  (c+1307,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_I));
	vcdp->chgBit  (c+1308,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_D));
	vcdp->chgBit  (c+1309,(vlTOPp->top__DOT__L2_S_W_COMPLETE));
	vcdp->chgBit  (c+1310,(vlTOPp->top__DOT__ex_raw_dep));
	vcdp->chgBit  (c+1311,(vlTOPp->top__DOT__mem_raw_dep));
	vcdp->chgBus  (c+1312,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgQuad (c+1313,(vlTOPp->top__DOT__llc__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+1315,(vlTOPp->top__DOT__llc__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+1317,(vlTOPp->top__DOT__llc__DOT__next_latched_w_data_buffer),512);
	vcdp->chgBit  (c+1333,(vlTOPp->top__DOT__llc__DOT__conflicting_tags));
	vcdp->chgBit  (c+1334,(vlTOPp->top__DOT__llc__DOT__line1_active));
	vcdp->chgBit  (c+1335,(vlTOPp->top__DOT__llc__DOT__line2_active));
	vcdp->chgBit  (c+1336,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+1337,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+1338,(vlTOPp->top__DOT__llc__DOT__w_selected_data),512);
	vcdp->chgQuad (c+1354,(vlTOPp->top__DOT__llc__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+1356,(vlTOPp->top__DOT__llc__DOT__w_requested_index),6);
	vcdp->chgBit  (c+1357,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_valid));
	vcdp->chgBit  (c+1358,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_valid));
	vcdp->chgBit  (c+1359,(vlTOPp->top__DOT__llc__DOT__r1_selected_block_is_dirty));
	vcdp->chgBit  (c+1360,(vlTOPp->top__DOT__llc__DOT__r2_selected_block_is_dirty));
	vcdp->chgArray(c+1361,(vlTOPp->top__DOT__llc__DOT__r1_selected_data),512);
	vcdp->chgArray(c+1377,(vlTOPp->top__DOT__llc__DOT__r2_selected_data),512);
	vcdp->chgQuad (c+1393,(vlTOPp->top__DOT__llc__DOT__r1_requested_tag),52);
	vcdp->chgQuad (c+1395,(vlTOPp->top__DOT__llc__DOT__r2_requested_tag),52);
	vcdp->chgQuad (c+1397,(vlTOPp->top__DOT__llc__DOT__r1_selected_tag),52);
	vcdp->chgQuad (c+1399,(vlTOPp->top__DOT__llc__DOT__r2_selected_tag),52);
	vcdp->chgBus  (c+1401,(vlTOPp->top__DOT__llc__DOT__r1_requested_index),6);
	vcdp->chgBus  (c+1402,(vlTOPp->top__DOT__llc__DOT__r2_requested_index),6);
	vcdp->chgBit  (c+1403,(vlTOPp->top__DOT__llc__DOT__next_last_chosen));
	vcdp->chgBit  (c+1404,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_contains_request));
	vcdp->chgArray(c+1405,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_data),512);
	vcdp->chgQuad (c+1421,(vlTOPp->top__DOT__llc__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBit  (c+1423,(vlTOPp->top__DOT__llc__DOT__service_line));
	vcdp->chgBus  (c+1424,(vlTOPp->top__DOT__l1_i__DOT__next_state),3);
	vcdp->chgBus  (c+1425,(vlTOPp->top__DOT__l1_i__DOT__next_r_state),3);
	vcdp->chgQuad (c+1426,(vlTOPp->top__DOT__l1_i__DOT__next_latched_r_requested_address),64);
	vcdp->chgArray(c+1428,(vlTOPp->top__DOT__l1_i__DOT__next_cache),36160);
	vcdp->chgBus  (c+2558,(vlTOPp->top__DOT__l1_d__DOT__next_state),3);
	vcdp->chgBus  (c+2559,(vlTOPp->top__DOT__l1_d__DOT__next_w_state),3);
	vcdp->chgBus  (c+2560,(vlTOPp->top__DOT__l1_d__DOT__next_r_state),3);
	vcdp->chgQuad (c+2561,(vlTOPp->top__DOT__l1_d__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+2563,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+2565,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_data_buffer),512);
	vcdp->chgBit  (c+2581,(vlTOPp->top__DOT__l1_d__DOT__conflicting_tags));
	vcdp->chgArray(c+2582,(vlTOPp->top__DOT__l1_d__DOT__next_cache),36224);
	vcdp->chgBit  (c+3714,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_contains_request));
	vcdp->chgQuad (c+3715,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_data),64);
	vcdp->chgQuad (c+3717,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_addr),64);
	vcdp->chgBus  (c+3719,(vlTOPp->top__DOT__l1_d__DOT__next_latched_s_w_request_size),2);
	vcdp->chgBit  (c+3720,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_valid));
	vcdp->chgBit  (c+3721,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+3722,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_dirty));
	vcdp->chgBit  (c+3723,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+3724,(vlTOPp->top__DOT__l1_d__DOT__r_selected_data),512);
	vcdp->chgArray(c+3740,(vlTOPp->top__DOT__l1_d__DOT__w_selected_data),512);
	vcdp->chgQuad (c+3756,(vlTOPp->top__DOT__l1_d__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+3758,(vlTOPp->top__DOT__l1_d__DOT__r_selected_tag),52);
	vcdp->chgQuad (c+3760,(vlTOPp->top__DOT__l1_d__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+3762,(vlTOPp->top__DOT__l1_d__DOT__r_requested_index),6);
	vcdp->chgBus  (c+3763,(vlTOPp->top__DOT__l1_d__DOT__w_requested_index),6);
	vcdp->chgBus  (c+3764,(vlTOPp->top__DOT__l1_d__DOT__r_requested_offset),6);
	vcdp->chgBus  (c+3765,(vlTOPp->top__DOT__mem_stage__DOT__next_state),3);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp116,511,0,16);
    VL_SIGW(__Vtemp120,511,0,16);
    // Body
    {
	vcdp->chgQuad (c+3766,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+3768,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+3769,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+3770,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+3772,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgBus  (c+3774,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+3775,(vlTOPp->top__DOT__branch_type),4);
	vcdp->chgBit  (c+3776,(vlTOPp->top__DOT__ecall_ex));
	vcdp->chgQuad (c+3777,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+3779,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgQuad (c+3781,(vlTOPp->top__DOT__imm),64);
	vcdp->chgBit  (c+3783,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+3784,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+3785,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+3786,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBus  (c+3787,(vlTOPp->top__DOT__mem_operation_size_ex),4);
	vcdp->chgQuad (c+3788,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+3790,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+3792,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+3793,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBus  (c+3794,(vlTOPp->top__DOT__mem_operation_size),4);
	vcdp->chgBus  (c+3795,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),4);
	vcdp->chgBit  (c+3796,(vlTOPp->top__DOT__ecall_mem));
	vcdp->chgBit  (c+3797,(vlTOPp->top__DOT__ecall_done));
	vcdp->chgBit  (c+3798,((1U & (~ (IData)(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request)))));
	vcdp->chgBit  (c+3799,((1U & (~ (IData)(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request)))));
	vcdp->chgQuad (c+3800,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+3802,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+3804,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+3806,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+3808,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+3810,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+3812,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+3814,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+3816,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+3818,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+3820,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+3822,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+3824,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+3826,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+3828,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+3830,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+3832,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+3834,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+3836,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+3838,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+3840,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+3842,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+3844,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+3846,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+3848,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+3850,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+3852,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+3854,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+3856,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+3858,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+3860,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+3862,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+3864,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	vcdp->chgBus  (c+3865,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgBus  (c+3866,(vlTOPp->top__DOT__llc__DOT__w_state),3);
	vcdp->chgBus  (c+3867,(vlTOPp->top__DOT__llc__DOT__r_state),3);
	vcdp->chgQuad (c+3868,(vlTOPp->top__DOT__llc__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+3870,(vlTOPp->top__DOT__llc__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+3872,(vlTOPp->top__DOT__llc__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+3888,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+5020,(vlTOPp->top__DOT__llc__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+5021,(vlTOPp->top__DOT__llc__DOT__w_buffer_index),3);
	__Vtemp116[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp116[0xaU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp116[0xbU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp116[0xcU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp116[0xdU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp116[0xeU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp116[0xfU] = ((0x8d7fU >= (0xffffU & 
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
	vcdp->chgArray(c+5022,(__Vtemp116),512);
	vcdp->chgQuad (c+5038,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgQuad (c+5040,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+5042,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBit  (c+5043,(vlTOPp->top__DOT__llc__DOT__last_chosen));
	vcdp->chgBit  (c+5044,(vlTOPp->top__DOT__llc__DOT__latched_s_w_contains_request));
	vcdp->chgArray(c+5045,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_data),512);
	vcdp->chgQuad (c+5061,(vlTOPp->top__DOT__llc__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+5063,(vlTOPp->top__DOT__l1_i__DOT__state),3);
	vcdp->chgBus  (c+5064,(vlTOPp->top__DOT__l1_i__DOT__r_state),3);
	vcdp->chgQuad (c+5065,(vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address),64);
	vcdp->chgArray(c+5067,(vlTOPp->top__DOT__l1_i__DOT__cache),36160);
	vcdp->chgBus  (c+6197,(vlTOPp->top__DOT__l1_i__DOT__r_buffer_index),3);
	vcdp->chgQuad (c+6198,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6200,((0x3fU & (IData)((vlTOPp->top__DOT__l1_i__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+6201,(vlTOPp->top__DOT__l1_d__DOT__state),3);
	vcdp->chgBus  (c+6202,(vlTOPp->top__DOT__l1_d__DOT__w_state),3);
	vcdp->chgBus  (c+6203,(vlTOPp->top__DOT__l1_d__DOT__r_state),3);
	vcdp->chgQuad (c+6204,(vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+6206,(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+6208,(vlTOPp->top__DOT__l1_d__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+6224,(vlTOPp->top__DOT__l1_d__DOT__cache),36224);
	vcdp->chgBus  (c+7356,(vlTOPp->top__DOT__l1_d__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+7357,(vlTOPp->top__DOT__l1_d__DOT__w_buffer_index),3);
	vcdp->chgBit  (c+7358,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_contains_request));
	vcdp->chgQuad (c+7359,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_data),64);
	vcdp->chgQuad (c+7361,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_addr),64);
	vcdp->chgBus  (c+7363,(vlTOPp->top__DOT__l1_d__DOT__latched_s_w_request_size),2);
	vcdp->chgBit  (c+7364,(vlTOPp->top__DOT__l1_d__DOT__r_captured));
	vcdp->chgBit  (c+7365,(vlTOPp->top__DOT__l1_d__DOT__w_complete));
	vcdp->chgBit  (c+7366,(vlTOPp->top__DOT__l1_d__DOT__pending_cache_write));
	__Vtemp120[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp120[0xaU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp120[0xbU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp120[0xcU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp120[0xdU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp120[0xeU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp120[0xfU] = ((0x8d7fU >= (0xffffU & 
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
	vcdp->chgArray(c+7367,(__Vtemp120),512);
	vcdp->chgQuad (c+7383,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+7385,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgBus  (c+7387,((0x3fU & (IData)((vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+7388,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgBus  (c+7389,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+7390,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),3);
	vcdp->chgBus  (c+7391,(vlTOPp->top__DOT__mem_stage__DOT__state),3);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+7392,(vlTOPp->clk));
	vcdp->chgBit  (c+7393,(vlTOPp->reset));
	vcdp->chgBit  (c+7394,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+7395,(vlTOPp->entry),64);
	vcdp->chgQuad (c+7397,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+7399,(vlTOPp->satp),64);
	vcdp->chgBus  (c+7401,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+7402,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+7404,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+7405,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+7406,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+7407,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+7408,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+7409,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+7410,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+7411,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+7412,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+7414,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+7415,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+7416,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+7417,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+7418,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+7419,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+7420,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+7421,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+7422,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+7423,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+7425,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+7426,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+7427,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+7428,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+7429,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+7430,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+7431,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+7432,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+7433,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+7434,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+7436,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+7437,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+7438,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+7439,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+7440,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+7441,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+7442,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+7444,(vlTOPp->m_axi_acsnoop),4);
    }
}
