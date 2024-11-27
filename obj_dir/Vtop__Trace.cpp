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
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__next_instruction),32);
	vcdp->chgQuad (c+7,(vlTOPp->top__DOT__next_id_instr_pc),64);
	vcdp->chgBus  (c+9,(vlTOPp->top__DOT__next_ex_opcode),7);
	vcdp->chgBus  (c+10,(vlTOPp->top__DOT__next_branch_type),4);
	vcdp->chgBit  (c+11,(vlTOPp->top__DOT__next_ecall_ex));
	vcdp->chgQuad (c+12,(vlTOPp->top__DOT__next_imm),64);
	vcdp->chgBit  (c+14,(vlTOPp->top__DOT__next_is_word_op));
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__next_ex_dst_reg),5);
	vcdp->chgBit  (c+16,(vlTOPp->top__DOT__next_imm_or_reg2));
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__next_mem_opcode_ex),7);
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__next_mem_operation_size_ex),4);
	vcdp->chgQuad (c+19,(vlTOPp->top__DOT__next_ex_res),64);
	vcdp->chgBus  (c+21,(vlTOPp->top__DOT__rf_reg1),5);
	vcdp->chgBus  (c+22,(vlTOPp->top__DOT__rf_reg2),5);
	vcdp->chgArray(c+23,(vlTOPp->top__DOT__L1_I_S_R_DATA),512);
	vcdp->chgBit  (c+39,(vlTOPp->top__DOT__L1_I_S_R_DATA_VALID));
	vcdp->chgQuad (c+40,(vlTOPp->top__DOT__L1_D_S_R_DATA),64);
	vcdp->chgQuad (c+42,(vlTOPp->top__DOT__L2_S_R_ADDR_1),64);
	vcdp->chgBit  (c+44,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_1));
	vcdp->chgArray(c+45,(vlTOPp->top__DOT__L2_S_R_DATA),512);
	vcdp->chgBit  (c+61,(vlTOPp->top__DOT__ex_raw_dep));
	vcdp->chgBit  (c+62,(vlTOPp->top__DOT__llc__DOT__conflicting_tags));
	vcdp->chgBit  (c+63,(vlTOPp->top__DOT__llc__DOT__r_selected_block_is_valid));
	vcdp->chgBit  (c+64,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+65,(vlTOPp->top__DOT__llc__DOT__r_selected_block_is_dirty));
	vcdp->chgBit  (c+66,(vlTOPp->top__DOT__llc__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+67,(vlTOPp->top__DOT__llc__DOT__r_selected_data),512);
	vcdp->chgArray(c+83,(vlTOPp->top__DOT__llc__DOT__w_selected_data),512);
	vcdp->chgQuad (c+99,(vlTOPp->top__DOT__llc__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+101,(vlTOPp->top__DOT__llc__DOT__r_selected_tag),52);
	vcdp->chgQuad (c+103,(vlTOPp->top__DOT__llc__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+105,(vlTOPp->top__DOT__llc__DOT__r_requested_index),6);
	vcdp->chgBus  (c+106,(vlTOPp->top__DOT__llc__DOT__w_requested_index),6);
	vcdp->chgBus  (c+107,(vlTOPp->top__DOT__l1_i__DOT__next_state),3);
	vcdp->chgQuad (c+108,(vlTOPp->top__DOT__l1_i__DOT__next_latched_requested_address),64);
	vcdp->chgArray(c+110,(vlTOPp->top__DOT__l1_i__DOT__next_cache),36160);
	vcdp->chgBus  (c+1240,(vlTOPp->top__DOT__l1_i__DOT__next_buffer_index),3);
	vcdp->chgQuad (c+1241,(vlTOPp->top__DOT__l1_i__DOT__selected_tag),52);
	vcdp->chgBit  (c+1243,(vlTOPp->top__DOT__l1_i__DOT__selected_block_is_valid));
	vcdp->chgArray(c+1244,(vlTOPp->top__DOT__l1_i__DOT__selected_data),512);
	vcdp->chgBus  (c+1260,(vlTOPp->top__DOT__l1_i__DOT__requested_index),6);
	vcdp->chgArray(c+1261,(vlTOPp->top__DOT__l1_i__DOT__block),566);
	vcdp->chgBit  (c+1279,(vlTOPp->top__DOT__l1_d__DOT__conflicting_tags));
	vcdp->chgBit  (c+1280,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_valid));
	vcdp->chgBit  (c+1281,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_valid));
	vcdp->chgBit  (c+1282,(vlTOPp->top__DOT__l1_d__DOT__r_selected_block_is_dirty));
	vcdp->chgBit  (c+1283,(vlTOPp->top__DOT__l1_d__DOT__w_selected_block_is_dirty));
	vcdp->chgArray(c+1284,(vlTOPp->top__DOT__l1_d__DOT__r_selected_data),512);
	vcdp->chgArray(c+1300,(vlTOPp->top__DOT__l1_d__DOT__w_selected_data),512);
	vcdp->chgQuad (c+1316,(vlTOPp->top__DOT__l1_d__DOT__r_requested_tag),52);
	vcdp->chgQuad (c+1318,(vlTOPp->top__DOT__l1_d__DOT__r_selected_tag),52);
	vcdp->chgQuad (c+1320,(vlTOPp->top__DOT__l1_d__DOT__w_selected_tag),52);
	vcdp->chgBus  (c+1322,(vlTOPp->top__DOT__l1_d__DOT__r_requested_index),6);
	vcdp->chgBus  (c+1323,(vlTOPp->top__DOT__l1_d__DOT__w_requested_index),6);
	vcdp->chgArray(c+1324,(vlTOPp->top__DOT__if_stage__DOT__next_instruction_buffer),512);
	vcdp->chgQuad (c+1340,(vlTOPp->top__DOT__if_stage__DOT__next_buffer_start),64);
	vcdp->chgBit  (c+1342,(vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer));
	vcdp->chgQuad (c+1343,(vlTOPp->top__DOT__if_stage__DOT__next_S_R_ADDR),64);
	vcdp->chgBit  (c+1345,(vlTOPp->top__DOT__if_stage__DOT__next_S_R_ADDR_VALID));
	vcdp->chgBus  (c+1346,(vlTOPp->top__DOT__if_stage__DOT__next_state),2);
	vcdp->chgBus  (c+1347,(vlTOPp->top__DOT__id_stage__DOT__opcode),7);
	vcdp->chgBus  (c+1348,(vlTOPp->top__DOT__id_stage__DOT__funct3),3);
	vcdp->chgBus  (c+1349,(vlTOPp->top__DOT__id_stage__DOT__funct7),7);
	vcdp->chgQuad (c+1350,(vlTOPp->top__DOT__ex_stage__DOT__operand2),64);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1352,(((0U == vlTOPp->top__DOT__instruction) 
				| (IData)(vlTOPp->top__DOT__ex_ready))));
	vcdp->chgBit  (c+1353,(vlTOPp->top__DOT__mem_ready));
	vcdp->chgBus  (c+1354,(vlTOPp->top__DOT__mem_stage__DOT__next_state),3);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1355,(vlTOPp->top__DOT__ex_ready));
	vcdp->chgQuad (c+1356,(vlTOPp->top__DOT__next_r1_val),64);
	vcdp->chgQuad (c+1358,(vlTOPp->top__DOT__next_r2_val),64);
	vcdp->chgQuad (c+1360,(vlTOPp->top__DOT__wb_dst_val),64);
	vcdp->chgBit  (c+1362,(vlTOPp->top__DOT__wb_enable));
	vcdp->chgBit  (c+1363,(vlTOPp->top__DOT__L1_D_S_R_DATA_VALID));
	vcdp->chgBit  (c+1364,(vlTOPp->top__DOT__L1_D_S_W_READY));
	vcdp->chgBit  (c+1365,(vlTOPp->top__DOT__L1_D_S_W_COMPLETE));
	vcdp->chgQuad (c+1366,(vlTOPp->top__DOT__L2_S_R_ADDR_2),64);
	vcdp->chgBit  (c+1368,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID_2));
	vcdp->chgBit  (c+1369,(vlTOPp->top__DOT__L2_S_R_DATA_VALID));
	vcdp->chgBit  (c+1370,(vlTOPp->top__DOT__L2_S_W_READY));
	vcdp->chgBit  (c+1371,(vlTOPp->top__DOT__mem_raw_dep));
	vcdp->chgBus  (c+1372,(vlTOPp->top__DOT__llc__DOT__next_state),3);
	vcdp->chgBus  (c+1373,(vlTOPp->top__DOT__llc__DOT__next_w_state),3);
	vcdp->chgQuad (c+1374,(vlTOPp->top__DOT__llc__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+1376,(vlTOPp->top__DOT__llc__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+1378,(vlTOPp->top__DOT__llc__DOT__next_latched_w_data_buffer),512);
	vcdp->chgArray(c+1394,(vlTOPp->top__DOT__llc__DOT__next_cache),36224);
	vcdp->chgBus  (c+2526,(vlTOPp->top__DOT__llc__DOT__next_r_buffer_index),3);
	vcdp->chgBus  (c+2527,(vlTOPp->top__DOT__llc__DOT__next_w_buffer_index),3);
	vcdp->chgBus  (c+2528,(vlTOPp->top__DOT__l1_d__DOT__next_state),3);
	vcdp->chgBus  (c+2529,(vlTOPp->top__DOT__l1_d__DOT__next_w_state),3);
	vcdp->chgQuad (c+2530,(vlTOPp->top__DOT__l1_d__DOT__next_latched_r_requested_address),64);
	vcdp->chgQuad (c+2532,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_requested_address),64);
	vcdp->chgArray(c+2534,(vlTOPp->top__DOT__l1_d__DOT__next_latched_w_data_buffer),512);
	vcdp->chgArray(c+2550,(vlTOPp->top__DOT__l1_d__DOT__next_cache),36224);
	vcdp->chgBit  (c+3682,(vlTOPp->top__DOT__l1_d__DOT__next_L2_S_W_VALID));
	vcdp->chgQuad (c+3683,(vlTOPp->top__DOT__l1_d__DOT__next_L2_S_W_ADDR),64);
	vcdp->chgArray(c+3685,(vlTOPp->top__DOT__l1_d__DOT__next_L2_S_W_DATA),512);
	vcdp->chgBit  (c+3701,(vlTOPp->top__DOT__mem_stage__DOT__next_S_R_ADDR_VALID));
	vcdp->chgQuad (c+3702,(vlTOPp->top__DOT__mem_stage__DOT__next_S_R_ADDR),64);
	vcdp->chgBit  (c+3704,(vlTOPp->top__DOT__mem_stage__DOT__next_S_W_VALID));
	vcdp->chgQuad (c+3705,(vlTOPp->top__DOT__mem_stage__DOT__next_S_W_ADDR),64);
	vcdp->chgQuad (c+3707,(vlTOPp->top__DOT__mem_stage__DOT__next_S_W_DATA),64);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp110,511,0,16);
    VL_SIGW(__Vtemp114,511,0,16);
    VL_SIGW(__Vtemp118,511,0,16);
    // Body
    {
	vcdp->chgQuad (c+3709,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBit  (c+3711,(vlTOPp->top__DOT__jump_signal_applied));
	vcdp->chgBus  (c+3712,(vlTOPp->top__DOT__instruction),32);
	vcdp->chgQuad (c+3713,(vlTOPp->top__DOT__id_instr_pc),64);
	vcdp->chgQuad (c+3715,(vlTOPp->top__DOT__ex_instr_pc),64);
	vcdp->chgBus  (c+3717,(vlTOPp->top__DOT__ex_opcode),7);
	vcdp->chgBus  (c+3718,(vlTOPp->top__DOT__branch_type),4);
	vcdp->chgBit  (c+3719,(vlTOPp->top__DOT__ecall_ex));
	vcdp->chgQuad (c+3720,(vlTOPp->top__DOT__r1_val),64);
	vcdp->chgQuad (c+3722,(vlTOPp->top__DOT__r2_val),64);
	vcdp->chgQuad (c+3724,(vlTOPp->top__DOT__imm),64);
	vcdp->chgBit  (c+3726,(vlTOPp->top__DOT__is_word_op));
	vcdp->chgBus  (c+3727,(vlTOPp->top__DOT__ex_dst_reg),5);
	vcdp->chgBit  (c+3728,(vlTOPp->top__DOT__imm_or_reg2));
	vcdp->chgBus  (c+3729,(vlTOPp->top__DOT__mem_opcode_ex),7);
	vcdp->chgBus  (c+3730,(vlTOPp->top__DOT__mem_operation_size_ex),4);
	vcdp->chgQuad (c+3731,(vlTOPp->top__DOT__ex_res),64);
	vcdp->chgQuad (c+3733,(vlTOPp->top__DOT__r2_val_mem),64);
	vcdp->chgBus  (c+3735,(vlTOPp->top__DOT__mem_dst_reg),5);
	vcdp->chgBus  (c+3736,(vlTOPp->top__DOT__mem_opcode),7);
	vcdp->chgBus  (c+3737,(vlTOPp->top__DOT__mem_operation_size),4);
	vcdp->chgBus  (c+3738,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),4);
	vcdp->chgBit  (c+3739,(vlTOPp->top__DOT__ecall_mem));
	vcdp->chgBit  (c+3740,(vlTOPp->top__DOT__ecall_done));
	vcdp->chgQuad (c+3741,(vlTOPp->top__DOT__L1_I_S_R_ADDR),64);
	vcdp->chgBit  (c+3743,(vlTOPp->top__DOT__L1_I_S_R_ADDR_VALID));
	vcdp->chgQuad (c+3744,(vlTOPp->top__DOT__L1_D_S_R_ADDR),64);
	vcdp->chgBit  (c+3746,(vlTOPp->top__DOT__L1_D_S_R_ADDR_VALID));
	vcdp->chgBit  (c+3747,(vlTOPp->top__DOT__L1_D_S_W_VALID));
	vcdp->chgQuad (c+3748,(vlTOPp->top__DOT__L1_D_S_W_ADDR),64);
	vcdp->chgQuad (c+3750,(vlTOPp->top__DOT__L1_D_S_W_DATA),64);
	vcdp->chgQuad (c+3752,(vlTOPp->top__DOT__L2_S_R_ADDR),64);
	vcdp->chgBit  (c+3754,(vlTOPp->top__DOT__L2_S_R_ADDR_VALID));
	vcdp->chgBit  (c+3755,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_1));
	vcdp->chgBit  (c+3756,(vlTOPp->top__DOT__L2_S_R_DATA_VALID_2));
	vcdp->chgBit  (c+3757,(vlTOPp->top__DOT__L2_S_W_VALID));
	vcdp->chgQuad (c+3758,(vlTOPp->top__DOT__L2_S_W_ADDR),64);
	vcdp->chgQuad (c+3760,((((QData)((IData)(vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[1U])) 
				 << 0x20U) | (QData)((IData)(
							     vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[0U])))),64);
	vcdp->chgQuad (c+3762,(vlTOPp->top__DOT__rf__DOT__registers[0]),64);
	vcdp->chgQuad (c+3764,(vlTOPp->top__DOT__rf__DOT__registers[1]),64);
	vcdp->chgQuad (c+3766,(vlTOPp->top__DOT__rf__DOT__registers[2]),64);
	vcdp->chgQuad (c+3768,(vlTOPp->top__DOT__rf__DOT__registers[3]),64);
	vcdp->chgQuad (c+3770,(vlTOPp->top__DOT__rf__DOT__registers[4]),64);
	vcdp->chgQuad (c+3772,(vlTOPp->top__DOT__rf__DOT__registers[5]),64);
	vcdp->chgQuad (c+3774,(vlTOPp->top__DOT__rf__DOT__registers[6]),64);
	vcdp->chgQuad (c+3776,(vlTOPp->top__DOT__rf__DOT__registers[7]),64);
	vcdp->chgQuad (c+3778,(vlTOPp->top__DOT__rf__DOT__registers[8]),64);
	vcdp->chgQuad (c+3780,(vlTOPp->top__DOT__rf__DOT__registers[9]),64);
	vcdp->chgQuad (c+3782,(vlTOPp->top__DOT__rf__DOT__registers[10]),64);
	vcdp->chgQuad (c+3784,(vlTOPp->top__DOT__rf__DOT__registers[11]),64);
	vcdp->chgQuad (c+3786,(vlTOPp->top__DOT__rf__DOT__registers[12]),64);
	vcdp->chgQuad (c+3788,(vlTOPp->top__DOT__rf__DOT__registers[13]),64);
	vcdp->chgQuad (c+3790,(vlTOPp->top__DOT__rf__DOT__registers[14]),64);
	vcdp->chgQuad (c+3792,(vlTOPp->top__DOT__rf__DOT__registers[15]),64);
	vcdp->chgQuad (c+3794,(vlTOPp->top__DOT__rf__DOT__registers[16]),64);
	vcdp->chgQuad (c+3796,(vlTOPp->top__DOT__rf__DOT__registers[17]),64);
	vcdp->chgQuad (c+3798,(vlTOPp->top__DOT__rf__DOT__registers[18]),64);
	vcdp->chgQuad (c+3800,(vlTOPp->top__DOT__rf__DOT__registers[19]),64);
	vcdp->chgQuad (c+3802,(vlTOPp->top__DOT__rf__DOT__registers[20]),64);
	vcdp->chgQuad (c+3804,(vlTOPp->top__DOT__rf__DOT__registers[21]),64);
	vcdp->chgQuad (c+3806,(vlTOPp->top__DOT__rf__DOT__registers[22]),64);
	vcdp->chgQuad (c+3808,(vlTOPp->top__DOT__rf__DOT__registers[23]),64);
	vcdp->chgQuad (c+3810,(vlTOPp->top__DOT__rf__DOT__registers[24]),64);
	vcdp->chgQuad (c+3812,(vlTOPp->top__DOT__rf__DOT__registers[25]),64);
	vcdp->chgQuad (c+3814,(vlTOPp->top__DOT__rf__DOT__registers[26]),64);
	vcdp->chgQuad (c+3816,(vlTOPp->top__DOT__rf__DOT__registers[27]),64);
	vcdp->chgQuad (c+3818,(vlTOPp->top__DOT__rf__DOT__registers[28]),64);
	vcdp->chgQuad (c+3820,(vlTOPp->top__DOT__rf__DOT__registers[29]),64);
	vcdp->chgQuad (c+3822,(vlTOPp->top__DOT__rf__DOT__registers[30]),64);
	vcdp->chgQuad (c+3824,(vlTOPp->top__DOT__rf__DOT__registers[31]),64);
	vcdp->chgBus  (c+3826,(vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i),32);
	VL_EXTEND_WQ(512,64, __Vtemp110, (((QData)((IData)(
							   vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[1U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA[0U]))));
	vcdp->chgArray(c+3827,(__Vtemp110),512);
	vcdp->chgBus  (c+3843,(vlTOPp->top__DOT__llc__DOT__state),3);
	vcdp->chgBus  (c+3844,(vlTOPp->top__DOT__llc__DOT__w_state),3);
	vcdp->chgQuad (c+3845,(vlTOPp->top__DOT__llc__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+3847,(vlTOPp->top__DOT__llc__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+3849,(vlTOPp->top__DOT__llc__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+3865,(vlTOPp->top__DOT__llc__DOT__cache),36224);
	vcdp->chgBus  (c+4997,(vlTOPp->top__DOT__llc__DOT__r_buffer_index),3);
	vcdp->chgBus  (c+4998,(vlTOPp->top__DOT__llc__DOT__w_buffer_index),3);
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
	vcdp->chgArray(c+4999,(__Vtemp114),512);
	vcdp->chgQuad (c+5015,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+5017,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L2_S_W_ADDR 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+5019,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgBus  (c+5021,((0x3fU & (IData)((vlTOPp->top__DOT__llc__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+5022,(vlTOPp->top__DOT__l1_i__DOT__state),3);
	vcdp->chgQuad (c+5023,(vlTOPp->top__DOT__l1_i__DOT__latched_requested_address),64);
	vcdp->chgArray(c+5025,(vlTOPp->top__DOT__l1_i__DOT__cache),36160);
	vcdp->chgBus  (c+6155,(vlTOPp->top__DOT__l1_i__DOT__buffer_index),3);
	vcdp->chgQuad (c+6156,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L1_I_S_R_ADDR 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6158,((0x3fU & (IData)(vlTOPp->top__DOT__L1_I_S_R_ADDR))),6);
	vcdp->chgQuad (c+6159,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_i__DOT__latched_requested_address 
				   >> 0xcU))),52);
	vcdp->chgBus  (c+6161,((0x3fU & (IData)((vlTOPp->top__DOT__l1_i__DOT__latched_requested_address 
						 >> 6U)))),6);
	vcdp->chgBus  (c+6162,((0x3fU & (IData)(vlTOPp->top__DOT__l1_i__DOT__latched_requested_address))),6);
	vcdp->chgArray(c+6163,(vlTOPp->top__DOT____Vcellout__l1_d__L2_S_W_DATA),512);
	vcdp->chgBus  (c+6179,(vlTOPp->top__DOT__l1_d__DOT__state),3);
	vcdp->chgBus  (c+6180,(vlTOPp->top__DOT__l1_d__DOT__w_state),3);
	vcdp->chgQuad (c+6181,(vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address),64);
	vcdp->chgQuad (c+6183,(vlTOPp->top__DOT__l1_d__DOT__latched_w_requested_address),64);
	vcdp->chgArray(c+6185,(vlTOPp->top__DOT__l1_d__DOT__latched_w_data_buffer),512);
	vcdp->chgArray(c+6201,(vlTOPp->top__DOT__l1_d__DOT__cache),36224);
	__Vtemp118[0U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[1U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[2U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[3U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[4U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[5U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[6U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[7U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[8U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[9U] = ((0x8d7fU >= (0xffffU & ((IData)(0x36U) 
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
	__Vtemp118[0xaU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp118[0xbU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp118[0xcU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp118[0xdU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp118[0xeU] = ((0x8d7fU >= (0xffffU & 
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
	__Vtemp118[0xfU] = ((0x8d7fU >= (0xffffU & 
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
	vcdp->chgArray(c+7333,(__Vtemp118),512);
	vcdp->chgQuad (c+7349,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+7351,((VL_ULL(0xfffffffffffff) 
				& (vlTOPp->top__DOT__L1_D_S_W_ADDR 
				   >> 0xcU))),52);
	vcdp->chgQuad (c+7353,((VL_ULL(0xfffffffffffff) 
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
	vcdp->chgBus  (c+7355,((0x3fU & (IData)((vlTOPp->top__DOT__l1_d__DOT__latched_r_requested_address 
						 >> 6U)))),6);
	vcdp->chgArray(c+7356,(vlTOPp->top__DOT__if_stage__DOT__instruction_buffer),512);
	vcdp->chgQuad (c+7372,(vlTOPp->top__DOT__if_stage__DOT__buffer_start),64);
	vcdp->chgBit  (c+7374,(vlTOPp->top__DOT__if_stage__DOT__empty_buffer));
	vcdp->chgBus  (c+7375,(vlTOPp->top__DOT__if_stage__DOT__state),2);
	vcdp->chgBus  (c+7376,(vlTOPp->top__DOT__mem_opcode_ex),32);
	vcdp->chgBus  (c+7377,((7U & (IData)(vlTOPp->top__DOT__mem_operation_size_ex))),3);
	vcdp->chgBus  (c+7378,(vlTOPp->top__DOT__mem_stage__DOT__state),3);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+7379,(vlTOPp->clk));
	vcdp->chgBit  (c+7380,(vlTOPp->reset));
	vcdp->chgBit  (c+7381,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+7382,(vlTOPp->entry),64);
	vcdp->chgQuad (c+7384,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+7386,(vlTOPp->satp),64);
	vcdp->chgBus  (c+7388,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+7389,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+7391,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+7392,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+7393,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+7394,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+7395,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+7396,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+7397,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+7398,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+7399,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+7401,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+7402,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+7403,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+7404,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+7405,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+7406,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+7407,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+7408,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+7409,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+7410,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+7412,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+7413,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+7414,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+7415,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+7416,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+7417,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+7418,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+7419,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+7420,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+7421,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+7423,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+7424,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+7425,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+7426,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+7427,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+7428,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+7429,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+7431,(vlTOPp->m_axi_acsnoop),4);
    }
}
