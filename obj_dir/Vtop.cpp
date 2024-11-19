// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//--------------------
// STATIC VARIABLES

VL_ST_SIG8(Vtop::__Vtable1_top__DOT__mem_stage__DOT__next_ctr[32],2,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__mem_stage__DOT__next_state[32],1,0);

//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL (__PVT____024unit, Vtop___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vtop::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at top.sv:103
    vlTOPp->m_axi_arburst = 2U;
    // INITIAL at top.sv:104
    vlTOPp->m_axi_arsize = 3U;
    // INITIAL at top.sv:105
    vlTOPp->m_axi_arlen = 7U;
    // INITIAL at top.sv:271
    VL_WRITEF("Initializing top, entry point = 0x%x\n",
	      64,vlTOPp->entry);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__jump_signal_applied,0,0);
    VL_SIG8(__Vdlyvset__top__DOT__rf__DOT__registers__v0,0,0);
    VL_SIG8(__Vdlyvdim0__top__DOT__rf__DOT__registers__v32,4,0);
    VL_SIG8(__Vdlyvset__top__DOT__rf__DOT__registers__v32,0,0);
    //char	__VpadToAlign28[4];
    VL_SIG64(__Vdlyvval__top__DOT__rf__DOT__registers__v32,63,0);
    // Body
    __Vdly__top__DOT__jump_signal_applied = vlTOPp->top__DOT__jump_signal_applied;
    __Vdlyvset__top__DOT__rf__DOT__registers__v0 = 0U;
    __Vdlyvset__top__DOT__rf__DOT__registers__v32 = 0U;
    // ALWAYS at pipeline_fetch.sv:38
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__if_stage__DOT__buffer_start = VL_ULL(0);
	vlTOPp->top__DOT__if_stage__DOT__buffer_index = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[1U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[2U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[3U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[4U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[5U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[6U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[7U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[8U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[9U] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xaU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xbU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xcU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xdU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xeU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[0xfU] = 0U;
	vlTOPp->top__DOT__if_stage__DOT__state = 0U;
	vlTOPp->top__DOT__if_stage__DOT__empty_buffer = 1U;
    } else {
	vlTOPp->top__DOT__if_stage__DOT__buffer_start 
	    = vlTOPp->top__DOT__if_stage__DOT__next_buffer_start;
	vlTOPp->top__DOT__if_stage__DOT__empty_buffer 
	    = vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer;
	vlTOPp->top__DOT__if_stage__DOT__buffer_index 
	    = vlTOPp->top__DOT__if_stage__DOT__next_buffer_index;
	VL_ASSIGNSEL_WIIQ(64,(0x1ffU & ((((IData)(vlTOPp->top__DOT__if_stage__DOT__next_buffer_index) 
					  << 6U) - (IData)(1U)) 
					- (IData)(0x3fU))), vlTOPp->top__DOT__if_stage__DOT__instruction_buffer, vlTOPp->top__DOT__if_stage__DOT__next_buffer_data);
	vlTOPp->top__DOT__if_stage__DOT__state = vlTOPp->top__DOT__if_stage__DOT__next_state;
    }
    // ALWAYS at register_file.sv:19
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__rf__DOT__unnamedblk1__DOT__i = 0x20U;
	__Vdlyvset__top__DOT__rf__DOT__registers__v0 = 1U;
    } else {
	if (vlTOPp->top__DOT__wb_enable) {
	    __Vdlyvval__top__DOT__rf__DOT__registers__v32 
		= vlTOPp->top__DOT__wb_dst_val;
	    __Vdlyvset__top__DOT__rf__DOT__registers__v32 = 1U;
	    __Vdlyvdim0__top__DOT__rf__DOT__registers__v32 
		= vlTOPp->top__DOT__wb_dst_reg;
	}
    }
    // ALWAYSPOST at register_file.sv:23
    if (__Vdlyvset__top__DOT__rf__DOT__registers__v0) {
	vlTOPp->top__DOT__rf__DOT__registers[0U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[1U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[2U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[3U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[4U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[5U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[6U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[7U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[8U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[9U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xaU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xbU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xcU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xdU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xeU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0xfU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x10U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x11U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x12U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x13U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x14U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x15U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x16U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x17U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x18U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x19U] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1aU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1bU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1cU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1dU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1eU] = VL_ULL(0);
	vlTOPp->top__DOT__rf__DOT__registers[0x1fU] = VL_ULL(0);
    }
    if (__Vdlyvset__top__DOT__rf__DOT__registers__v32) {
	vlTOPp->top__DOT__rf__DOT__registers[__Vdlyvdim0__top__DOT__rf__DOT__registers__v32] 
	    = __Vdlyvval__top__DOT__rf__DOT__registers__v32;
    }
    // ALWAYS at top.sv:199
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__pc = vlTOPp->entry;
    } else {
	vlTOPp->top__DOT__wb_dst_reg = vlTOPp->top__DOT__next_wb_dst_reg;
	vlTOPp->top__DOT__wb_dst_val = vlTOPp->top__DOT__next_wb_dst_val;
	vlTOPp->top__DOT__wb_enable = vlTOPp->top__DOT__next_wb_enable;
	if ((0U == (IData)(vlTOPp->top__DOT__mem_stage__DOT__state))) {
	    vlTOPp->top__DOT__ex_res = vlTOPp->top__DOT__next_ex_res;
	    vlTOPp->top__DOT__r2_val_mem = vlTOPp->top__DOT__next_r2_val_mem;
	    vlTOPp->top__DOT__mem_dst_reg = vlTOPp->top__DOT__next_mem_dst_reg;
	    vlTOPp->top__DOT__mem_opcode = (0x7fU & vlTOPp->top__DOT____Vcellinp__ex_stage__mem_opcode);
	    vlTOPp->top__DOT__is_mem_load = vlTOPp->top__DOT__next_is_mem_load;
	    __Vdly__top__DOT__jump_signal_applied = 0U;
	}
	if (vlTOPp->top__DOT__ex_ready) {
	    if (vlTOPp->top__DOT__jump_signal) {
		vlTOPp->top__DOT__ex_opcode = 0U;
		vlTOPp->top__DOT__ex_instr_pc = VL_ULL(0);
		vlTOPp->top__DOT__r1_val = VL_ULL(0);
		vlTOPp->top__DOT__r2_val = VL_ULL(0);
		vlTOPp->top__DOT__imm = 0U;
		vlTOPp->top__DOT__ex_dst_reg = 0U;
		vlTOPp->top__DOT__imm_or_reg2 = 0U;
		vlTOPp->top__DOT__mem_opcode_ex = 0U;
		vlTOPp->top__DOT__is_mem_load_ex = 0U;
	    } else {
		vlTOPp->top__DOT__ex_opcode = (0x7fU 
					       & (IData)(vlTOPp->top__DOT____Vcellout__id_stage__ex_opcode));
		vlTOPp->top__DOT__ex_instr_pc = vlTOPp->top__DOT__next_ex_instr_pc;
		vlTOPp->top__DOT__r1_val = vlTOPp->top__DOT__next_r1_val;
		vlTOPp->top__DOT__r2_val = vlTOPp->top__DOT__next_r2_val;
		vlTOPp->top__DOT__imm = (0xfffffU & vlTOPp->top__DOT____Vcellout__id_stage__imm);
		vlTOPp->top__DOT__ex_dst_reg = vlTOPp->top__DOT__next_ex_dst_reg;
		vlTOPp->top__DOT__imm_or_reg2 = vlTOPp->top__DOT__next_imm_or_reg2;
		vlTOPp->top__DOT__mem_opcode_ex = vlTOPp->top__DOT____Vcellout__id_stage__mem_opcode;
		vlTOPp->top__DOT__is_mem_load_ex = vlTOPp->top__DOT__next_is_mem_load_ex;
	    }
	}
	if (vlTOPp->top__DOT__id_ready) {
	    if (((IData)(vlTOPp->top__DOT__jump_signal) 
		 & (~ (IData)(vlTOPp->top__DOT__jump_signal_applied)))) {
		vlTOPp->top__DOT__pc = vlTOPp->top__DOT__jump_pc;
		vlTOPp->top__DOT__instruction = 0U;
		vlTOPp->top__DOT__id_instr_pc = VL_ULL(0);
	    } else {
		vlTOPp->top__DOT__pc = vlTOPp->top__DOT__next_if_pc;
		vlTOPp->top__DOT__instruction = vlTOPp->top__DOT__next_instruction;
		vlTOPp->top__DOT__id_instr_pc = vlTOPp->top__DOT__next_id_instr_pc;
	    }
	} else {
	    if (((IData)(vlTOPp->top__DOT__jump_signal) 
		 & (~ (IData)(vlTOPp->top__DOT__jump_signal_applied)))) {
		vlTOPp->top__DOT__pc = vlTOPp->top__DOT__jump_pc;
		vlTOPp->top__DOT__instruction = 0U;
		vlTOPp->top__DOT__id_instr_pc = VL_ULL(0);
		__Vdly__top__DOT__jump_signal_applied = 1U;
	    }
	}
    }
    vlTOPp->top__DOT__jump_signal_applied = __Vdly__top__DOT__jump_signal_applied;
    // ALWAYS at register_file.sv:34
    vlTOPp->top__DOT__next_r1_val = vlTOPp->top__DOT__rf__DOT__registers
	[vlTOPp->top__DOT__rf_reg1];
    // ALWAYS at register_file.sv:35
    vlTOPp->top__DOT__next_r2_val = vlTOPp->top__DOT__rf__DOT__registers
	[vlTOPp->top__DOT__rf_reg2];
    // ALWAYS at pipeline_ex.sv:46
    vlTOPp->top__DOT__next_r2_val_mem = vlTOPp->top__DOT__r2_val;
    // ALWAYS at pipeline_ex.sv:45
    vlTOPp->top__DOT__next_mem_dst_reg = vlTOPp->top__DOT__ex_dst_reg;
    vlTOPp->top__DOT____Vcellinp__ex_stage__mem_opcode 
	= vlTOPp->top__DOT__mem_opcode_ex;
    // ALWAYS at pipeline_ex.sv:44
    vlTOPp->top__DOT__next_is_mem_load = vlTOPp->top__DOT__is_mem_load_ex;
    // ALWAYS at pipeline_decode.sv:28
    vlTOPp->top__DOT____Vcellout__id_stage__ex_opcode 
	= ((0U == vlTOPp->top__DOT__instruction) ? VL_ULL(0)
	    : (QData)((IData)(vlTOPp->top__DOT__instruction)));
    // ALWAYS at pipeline_ex.sv:48
    if ((0xaU == (IData)(vlTOPp->top__DOT__ex_opcode))) {
	vlTOPp->top__DOT__jump_signal = 1U;
	vlTOPp->top__DOT__jump_pc = (VL_ULL(0xa) * (QData)((IData)(vlTOPp->top__DOT__ex_opcode)));
    } else {
	if ((0x64U == (IData)(vlTOPp->top__DOT__ex_opcode))) {
	    vlTOPp->top__DOT__jump_signal = 1U;
	    vlTOPp->top__DOT__jump_pc = (VL_ULL(5) 
					 * (QData)((IData)(vlTOPp->top__DOT__ex_opcode)));
	} else {
	    vlTOPp->top__DOT__jump_signal = 0U;
	}
    }
    // ALWAYS at pipeline_fetch.sv:54
    if ((((~ (IData)(vlTOPp->top__DOT__if_stage__DOT__empty_buffer)) 
	  & (vlTOPp->top__DOT__pc >= vlTOPp->top__DOT__if_stage__DOT__buffer_start)) 
	 & (vlTOPp->top__DOT__pc < (vlTOPp->top__DOT__if_stage__DOT__buffer_start 
				    + ((QData)((IData)(vlTOPp->top__DOT__if_stage__DOT__buffer_index)) 
				       << 3U))))) {
	vlTOPp->top__DOT__next_instruction = (0x7fffffffU 
					      & (((0U 
						   == 
						   (0x1fU 
						    & (IData)(
							      ((vlTOPp->top__DOT__pc 
								- vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
							       << 3U))))
						   ? 0U
						   : 
						  (vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[
						   ((IData)(1U) 
						    + 
						    (0xfU 
						     & ((IData)(
								((vlTOPp->top__DOT__pc 
								  - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								 << 3U)) 
							>> 5U)))] 
						   << 
						   ((IData)(0x20U) 
						    - 
						    (0x1fU 
						     & (IData)(
							       ((vlTOPp->top__DOT__pc 
								 - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								<< 3U)))))) 
						 | (vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[
						    (0xfU 
						     & ((IData)(
								((vlTOPp->top__DOT__pc 
								  - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								 << 3U)) 
							>> 5U))] 
						    >> 
						    (0x1fU 
						     & (IData)(
							       ((vlTOPp->top__DOT__pc 
								 - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								<< 3U))))));
	vlTOPp->top__DOT__next_id_instr_pc = vlTOPp->top__DOT__pc;
	vlTOPp->top__DOT__next_if_pc = (VL_ULL(4) + vlTOPp->top__DOT__pc);
    } else {
	vlTOPp->top__DOT__next_instruction = 0U;
	vlTOPp->top__DOT__next_id_instr_pc = VL_ULL(0);
	vlTOPp->top__DOT__next_if_pc = vlTOPp->top__DOT__pc;
	if (((VL_ULL(0) != vlTOPp->top__DOT__pc) & 
	     (0U == (IData)(vlTOPp->top__DOT__if_stage__DOT__state)))) {
	    vlTOPp->top__DOT__if_stage__DOT__next_state = 1U;
	}
    }
    // ALWAYS at pipeline_memory.sv:27
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__mem_stage__DOT__state = 0U;
	vlTOPp->top__DOT__mem_stage__DOT__ctr = 0U;
    } else {
	vlTOPp->top__DOT__mem_stage__DOT__state = vlTOPp->top__DOT__mem_stage__DOT__next_state;
	vlTOPp->top__DOT__mem_stage__DOT__ctr = vlTOPp->top__DOT__mem_stage__DOT__next_ctr;
    }
    // ALWAYS at pipeline_memory.sv:40
    if ((1U <= (IData)(vlTOPp->top__DOT__mem_opcode))) {
	vlTOPp->top__DOT__mem_stage__DOT__next_state = 1U;
    }
    // ALWAYS at pipeline_ex.sv:42
    vlTOPp->top__DOT__ex_ready = ((0U == (IData)(vlTOPp->top__DOT__ex_opcode)) 
				  | (0U == (IData)(vlTOPp->top__DOT__mem_stage__DOT__state)));
    // ALWAYS at pipeline_memory.sv:45
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->top__DOT__mem_stage__DOT__ctr) 
			     << 2U) | (IData)(vlTOPp->top__DOT__mem_stage__DOT__state));
    if ((1U & vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1])) {
	vlTOPp->top__DOT__mem_stage__DOT__next_ctr 
	    = vlTOPp->__Vtable1_top__DOT__mem_stage__DOT__next_ctr
	    [vlTOPp->__Vtableidx1];
    }
    if ((2U & vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1])) {
	vlTOPp->top__DOT__mem_stage__DOT__next_state 
	    = vlTOPp->__Vtable1_top__DOT__mem_stage__DOT__next_state
	    [vlTOPp->__Vtableidx1];
    }
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at register_file.sv:34
    vlTOPp->top__DOT__next_r1_val = vlTOPp->top__DOT__rf__DOT__registers
	[vlTOPp->top__DOT__rf_reg1];
    // ALWAYS at register_file.sv:35
    vlTOPp->top__DOT__next_r2_val = vlTOPp->top__DOT__rf__DOT__registers
	[vlTOPp->top__DOT__rf_reg2];
    // ALWAYS at pipeline_ex.sv:46
    vlTOPp->top__DOT__next_r2_val_mem = vlTOPp->top__DOT__r2_val;
    // ALWAYS at pipeline_ex.sv:45
    vlTOPp->top__DOT__next_mem_dst_reg = vlTOPp->top__DOT__ex_dst_reg;
    vlTOPp->top__DOT____Vcellinp__ex_stage__mem_opcode 
	= vlTOPp->top__DOT__mem_opcode_ex;
    // ALWAYS at pipeline_ex.sv:44
    vlTOPp->top__DOT__next_is_mem_load = vlTOPp->top__DOT__is_mem_load_ex;
    // ALWAYS at pipeline_decode.sv:28
    vlTOPp->top__DOT____Vcellout__id_stage__ex_opcode 
	= ((0U == vlTOPp->top__DOT__instruction) ? VL_ULL(0)
	    : (QData)((IData)(vlTOPp->top__DOT__instruction)));
    // ALWAYS at pipeline_ex.sv:48
    if ((0xaU == (IData)(vlTOPp->top__DOT__ex_opcode))) {
	vlTOPp->top__DOT__jump_signal = 1U;
	vlTOPp->top__DOT__jump_pc = (VL_ULL(0xa) * (QData)((IData)(vlTOPp->top__DOT__ex_opcode)));
    } else {
	if ((0x64U == (IData)(vlTOPp->top__DOT__ex_opcode))) {
	    vlTOPp->top__DOT__jump_signal = 1U;
	    vlTOPp->top__DOT__jump_pc = (VL_ULL(5) 
					 * (QData)((IData)(vlTOPp->top__DOT__ex_opcode)));
	} else {
	    vlTOPp->top__DOT__jump_signal = 0U;
	}
    }
    // ALWAYS at pipeline_fetch.sv:54
    if ((((~ (IData)(vlTOPp->top__DOT__if_stage__DOT__empty_buffer)) 
	  & (vlTOPp->top__DOT__pc >= vlTOPp->top__DOT__if_stage__DOT__buffer_start)) 
	 & (vlTOPp->top__DOT__pc < (vlTOPp->top__DOT__if_stage__DOT__buffer_start 
				    + ((QData)((IData)(vlTOPp->top__DOT__if_stage__DOT__buffer_index)) 
				       << 3U))))) {
	vlTOPp->top__DOT__next_instruction = (0x7fffffffU 
					      & (((0U 
						   == 
						   (0x1fU 
						    & (IData)(
							      ((vlTOPp->top__DOT__pc 
								- vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
							       << 3U))))
						   ? 0U
						   : 
						  (vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[
						   ((IData)(1U) 
						    + 
						    (0xfU 
						     & ((IData)(
								((vlTOPp->top__DOT__pc 
								  - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								 << 3U)) 
							>> 5U)))] 
						   << 
						   ((IData)(0x20U) 
						    - 
						    (0x1fU 
						     & (IData)(
							       ((vlTOPp->top__DOT__pc 
								 - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								<< 3U)))))) 
						 | (vlTOPp->top__DOT__if_stage__DOT__instruction_buffer[
						    (0xfU 
						     & ((IData)(
								((vlTOPp->top__DOT__pc 
								  - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								 << 3U)) 
							>> 5U))] 
						    >> 
						    (0x1fU 
						     & (IData)(
							       ((vlTOPp->top__DOT__pc 
								 - vlTOPp->top__DOT__if_stage__DOT__buffer_start) 
								<< 3U))))));
	vlTOPp->top__DOT__next_id_instr_pc = vlTOPp->top__DOT__pc;
	vlTOPp->top__DOT__next_if_pc = (VL_ULL(4) + vlTOPp->top__DOT__pc);
    } else {
	vlTOPp->top__DOT__next_instruction = 0U;
	vlTOPp->top__DOT__next_id_instr_pc = VL_ULL(0);
	vlTOPp->top__DOT__next_if_pc = vlTOPp->top__DOT__pc;
	if (((VL_ULL(0) != vlTOPp->top__DOT__pc) & 
	     (0U == (IData)(vlTOPp->top__DOT__if_stage__DOT__state)))) {
	    vlTOPp->top__DOT__if_stage__DOT__next_state = 1U;
	}
    }
    // ALWAYS at pipeline_fetch.sv:69
    if ((2U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	if ((1U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	    vlTOPp->m_axi_rready = 1U;
	    if (vlTOPp->m_axi_rvalid) {
		if (vlTOPp->top__DOT__if_stage__DOT__empty_buffer) {
		    vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer = 0U;
		}
		vlTOPp->top__DOT__if_stage__DOT__next_buffer_data 
		    = vlTOPp->m_axi_rdata;
		vlTOPp->top__DOT__if_stage__DOT__next_buffer_index 
		    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__if_stage__DOT__buffer_index)));
		vlTOPp->top__DOT__if_stage__DOT__next_state 
		    = ((IData)(vlTOPp->m_axi_rlast)
		        ? 0U : 3U);
	    } else {
		vlTOPp->top__DOT__if_stage__DOT__next_state = 2U;
	    }
	} else {
	    vlTOPp->m_axi_arvalid = 0U;
	    vlTOPp->top__DOT__if_stage__DOT__next_state 
		= ((IData)(vlTOPp->m_axi_rvalid) ? 3U
		    : 2U);
	}
    } else {
	if ((1U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	    vlTOPp->m_axi_araddr = vlTOPp->top__DOT__pc;
	    vlTOPp->top__DOT__if_stage__DOT__next_buffer_start 
		= vlTOPp->top__DOT__pc;
	    vlTOPp->top__DOT__if_stage__DOT__next_state = 2U;
	    vlTOPp->m_axi_arvalid = 1U;
	}
    }
    // ALWAYS at pipeline_memory.sv:40
    if ((1U <= (IData)(vlTOPp->top__DOT__mem_opcode))) {
	vlTOPp->top__DOT__mem_stage__DOT__next_state = 1U;
    }
    // ALWAYS at pipeline_ex.sv:42
    vlTOPp->top__DOT__ex_ready = ((0U == (IData)(vlTOPp->top__DOT__ex_opcode)) 
				  | (0U == (IData)(vlTOPp->top__DOT__mem_stage__DOT__state)));
    // ALWAYS at pipeline_memory.sv:45
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->top__DOT__mem_stage__DOT__ctr) 
			     << 2U) | (IData)(vlTOPp->top__DOT__mem_stage__DOT__state));
    if ((1U & vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1])) {
	vlTOPp->top__DOT__mem_stage__DOT__next_ctr 
	    = vlTOPp->__Vtable1_top__DOT__mem_stage__DOT__next_ctr
	    [vlTOPp->__Vtableidx1];
    }
    if ((2U & vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1])) {
	vlTOPp->top__DOT__mem_stage__DOT__next_state 
	    = vlTOPp->__Vtable1_top__DOT__mem_stage__DOT__next_state
	    [vlTOPp->__Vtableidx1];
    }
    // ALWAYS at pipeline_decode.sv:24
    vlTOPp->top__DOT__id_ready = ((0U == vlTOPp->top__DOT__instruction) 
				  | (IData)(vlTOPp->top__DOT__ex_ready));
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_combo__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at pipeline_fetch.sv:69
    if ((2U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	if ((1U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	    vlTOPp->m_axi_rready = 1U;
	    if (vlTOPp->m_axi_rvalid) {
		if (vlTOPp->top__DOT__if_stage__DOT__empty_buffer) {
		    vlTOPp->top__DOT__if_stage__DOT__next_empty_buffer = 0U;
		}
		vlTOPp->top__DOT__if_stage__DOT__next_buffer_data 
		    = vlTOPp->m_axi_rdata;
		vlTOPp->top__DOT__if_stage__DOT__next_buffer_index 
		    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__if_stage__DOT__buffer_index)));
		vlTOPp->top__DOT__if_stage__DOT__next_state 
		    = ((IData)(vlTOPp->m_axi_rlast)
		        ? 0U : 3U);
	    } else {
		vlTOPp->top__DOT__if_stage__DOT__next_state = 2U;
	    }
	} else {
	    vlTOPp->m_axi_arvalid = 0U;
	    vlTOPp->top__DOT__if_stage__DOT__next_state 
		= ((IData)(vlTOPp->m_axi_rvalid) ? 3U
		    : 2U);
	}
    } else {
	if ((1U & (IData)(vlTOPp->top__DOT__if_stage__DOT__state))) {
	    vlTOPp->m_axi_araddr = vlTOPp->top__DOT__pc;
	    vlTOPp->top__DOT__if_stage__DOT__next_buffer_start 
		= vlTOPp->top__DOT__pc;
	    vlTOPp->top__DOT__if_stage__DOT__next_state = 2U;
	    vlTOPp->m_axi_arvalid = 1U;
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at pipeline_decode.sv:24
    vlTOPp->top__DOT__id_ready = ((0U == vlTOPp->top__DOT__instruction) 
				  | (IData)(vlTOPp->top__DOT__ex_ready));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    hz32768timer = VL_RAND_RESET_I(1);
    entry = VL_RAND_RESET_Q(64);
    stackptr = VL_RAND_RESET_Q(64);
    satp = VL_RAND_RESET_Q(64);
    m_axi_awid = VL_RAND_RESET_I(13);
    m_axi_awaddr = VL_RAND_RESET_Q(64);
    m_axi_awlen = VL_RAND_RESET_I(8);
    m_axi_awsize = VL_RAND_RESET_I(3);
    m_axi_awburst = VL_RAND_RESET_I(2);
    m_axi_awlock = VL_RAND_RESET_I(1);
    m_axi_awcache = VL_RAND_RESET_I(4);
    m_axi_awprot = VL_RAND_RESET_I(3);
    m_axi_awvalid = VL_RAND_RESET_I(1);
    m_axi_awready = VL_RAND_RESET_I(1);
    m_axi_wdata = VL_RAND_RESET_Q(64);
    m_axi_wstrb = VL_RAND_RESET_I(8);
    m_axi_wlast = VL_RAND_RESET_I(1);
    m_axi_wvalid = VL_RAND_RESET_I(1);
    m_axi_wready = VL_RAND_RESET_I(1);
    m_axi_bid = VL_RAND_RESET_I(13);
    m_axi_bresp = VL_RAND_RESET_I(2);
    m_axi_bvalid = VL_RAND_RESET_I(1);
    m_axi_bready = VL_RAND_RESET_I(1);
    m_axi_arid = VL_RAND_RESET_I(13);
    m_axi_araddr = VL_RAND_RESET_Q(64);
    m_axi_arlen = VL_RAND_RESET_I(8);
    m_axi_arsize = VL_RAND_RESET_I(3);
    m_axi_arburst = VL_RAND_RESET_I(2);
    m_axi_arlock = VL_RAND_RESET_I(1);
    m_axi_arcache = VL_RAND_RESET_I(4);
    m_axi_arprot = VL_RAND_RESET_I(3);
    m_axi_arvalid = VL_RAND_RESET_I(1);
    m_axi_arready = VL_RAND_RESET_I(1);
    m_axi_rid = VL_RAND_RESET_I(13);
    m_axi_rdata = VL_RAND_RESET_Q(64);
    m_axi_rresp = VL_RAND_RESET_I(2);
    m_axi_rlast = VL_RAND_RESET_I(1);
    m_axi_rvalid = VL_RAND_RESET_I(1);
    m_axi_rready = VL_RAND_RESET_I(1);
    m_axi_acvalid = VL_RAND_RESET_I(1);
    m_axi_acready = VL_RAND_RESET_I(1);
    m_axi_acaddr = VL_RAND_RESET_Q(64);
    m_axi_acsnoop = VL_RAND_RESET_I(4);
    top__DOT__pc = VL_RAND_RESET_Q(64);
    top__DOT__next_if_pc = VL_RAND_RESET_Q(64);
    top__DOT__jump_pc = VL_RAND_RESET_Q(64);
    top__DOT__jump_signal = VL_RAND_RESET_I(1);
    top__DOT__jump_signal_applied = VL_RAND_RESET_I(1);
    top__DOT__id_ready = VL_RAND_RESET_I(1);
    top__DOT__ex_ready = VL_RAND_RESET_I(1);
    top__DOT__instruction = VL_RAND_RESET_I(32);
    top__DOT__next_instruction = VL_RAND_RESET_I(32);
    top__DOT__id_instr_pc = VL_RAND_RESET_Q(64);
    top__DOT__next_id_instr_pc = VL_RAND_RESET_Q(64);
    top__DOT__ex_instr_pc = VL_RAND_RESET_Q(64);
    top__DOT__next_ex_instr_pc = VL_RAND_RESET_Q(64);
    top__DOT__ex_opcode = VL_RAND_RESET_I(7);
    top__DOT__r1_val = VL_RAND_RESET_Q(64);
    top__DOT__next_r1_val = VL_RAND_RESET_Q(64);
    top__DOT__r2_val = VL_RAND_RESET_Q(64);
    top__DOT__next_r2_val = VL_RAND_RESET_Q(64);
    top__DOT__imm = VL_RAND_RESET_I(20);
    top__DOT__ex_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__next_ex_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__imm_or_reg2 = VL_RAND_RESET_I(1);
    top__DOT__next_imm_or_reg2 = VL_RAND_RESET_I(1);
    top__DOT__mem_opcode_ex = VL_RAND_RESET_I(7);
    top__DOT__is_mem_load_ex = VL_RAND_RESET_I(1);
    top__DOT__next_is_mem_load_ex = VL_RAND_RESET_I(1);
    top__DOT__ex_res = VL_RAND_RESET_Q(64);
    top__DOT__next_ex_res = VL_RAND_RESET_Q(64);
    top__DOT__r2_val_mem = VL_RAND_RESET_Q(64);
    top__DOT__next_r2_val_mem = VL_RAND_RESET_Q(64);
    top__DOT__mem_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__next_mem_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__mem_opcode = VL_RAND_RESET_I(7);
    top__DOT__is_mem_load = VL_RAND_RESET_I(1);
    top__DOT__next_is_mem_load = VL_RAND_RESET_I(1);
    top__DOT__wb_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__next_wb_dst_reg = VL_RAND_RESET_I(5);
    top__DOT__wb_dst_val = VL_RAND_RESET_Q(64);
    top__DOT__next_wb_dst_val = VL_RAND_RESET_Q(64);
    top__DOT__wb_enable = VL_RAND_RESET_I(1);
    top__DOT__next_wb_enable = VL_RAND_RESET_I(1);
    top__DOT__rf_reg1 = VL_RAND_RESET_I(5);
    top__DOT__rf_reg2 = VL_RAND_RESET_I(5);
    top__DOT____Vcellout__id_stage__mem_opcode = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__id_stage__imm = VL_RAND_RESET_I(21);
    top__DOT____Vcellout__id_stage__ex_opcode = VL_RAND_RESET_Q(64);
    top__DOT____Vcellinp__ex_stage__mem_opcode = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    top__DOT__rf__DOT__registers[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    top__DOT__rf__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512,top__DOT__if_stage__DOT__instruction_buffer);
    top__DOT__if_stage__DOT__buffer_start = VL_RAND_RESET_Q(64);
    top__DOT__if_stage__DOT__next_buffer_start = VL_RAND_RESET_Q(64);
    top__DOT__if_stage__DOT__next_buffer_data = VL_RAND_RESET_Q(64);
    top__DOT__if_stage__DOT__buffer_index = VL_RAND_RESET_I(6);
    top__DOT__if_stage__DOT__next_buffer_index = VL_RAND_RESET_I(6);
    top__DOT__if_stage__DOT__empty_buffer = VL_RAND_RESET_I(1);
    top__DOT__if_stage__DOT__next_empty_buffer = VL_RAND_RESET_I(1);
    top__DOT__if_stage__DOT__state = VL_RAND_RESET_I(2);
    top__DOT__if_stage__DOT__next_state = VL_RAND_RESET_I(2);
    top__DOT__mem_stage__DOT__state = VL_RAND_RESET_I(2);
    top__DOT__mem_stage__DOT__next_state = VL_RAND_RESET_I(2);
    top__DOT__mem_stage__DOT__ctr = VL_RAND_RESET_I(3);
    top__DOT__mem_stage__DOT__next_ctr = VL_RAND_RESET_I(3);
    __Vtableidx1 = VL_RAND_RESET_I(5);
    __Vtablechg1[0] = 1U;
    __Vtablechg1[1] = 3U;
    __Vtablechg1[2] = 0U;
    __Vtablechg1[3] = 0U;
    __Vtablechg1[4] = 1U;
    __Vtablechg1[5] = 3U;
    __Vtablechg1[6] = 0U;
    __Vtablechg1[7] = 0U;
    __Vtablechg1[8] = 1U;
    __Vtablechg1[9] = 3U;
    __Vtablechg1[10] = 0U;
    __Vtablechg1[11] = 0U;
    __Vtablechg1[12] = 1U;
    __Vtablechg1[13] = 3U;
    __Vtablechg1[14] = 0U;
    __Vtablechg1[15] = 0U;
    __Vtablechg1[16] = 1U;
    __Vtablechg1[17] = 3U;
    __Vtablechg1[18] = 0U;
    __Vtablechg1[19] = 0U;
    __Vtablechg1[20] = 1U;
    __Vtablechg1[21] = 3U;
    __Vtablechg1[22] = 0U;
    __Vtablechg1[23] = 0U;
    __Vtablechg1[24] = 1U;
    __Vtablechg1[25] = 3U;
    __Vtablechg1[26] = 0U;
    __Vtablechg1[27] = 0U;
    __Vtablechg1[28] = 1U;
    __Vtablechg1[29] = 3U;
    __Vtablechg1[30] = 0U;
    __Vtablechg1[31] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[0] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[1] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[2] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[3] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[4] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[5] = 2U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[6] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[7] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[8] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[9] = 3U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[10] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[11] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[12] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[13] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[14] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[15] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[16] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[17] = 5U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[18] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[19] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[20] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[21] = 6U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[22] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[23] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[24] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[25] = 7U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[26] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[27] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[28] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[29] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[30] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_ctr[31] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[0] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[1] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[2] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[3] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[4] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[5] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[6] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[7] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[8] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[9] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[10] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[11] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[12] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[13] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[14] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[15] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[16] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[17] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[18] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[19] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[20] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[21] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[22] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[23] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[24] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[25] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[26] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[27] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[28] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[29] = 1U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[30] = 0U;
    __Vtable1_top__DOT__mem_stage__DOT__next_state[31] = 0U;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_configure_coverage\n"); );
}
