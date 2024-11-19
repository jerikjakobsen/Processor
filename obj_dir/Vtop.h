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
    VL_SIG8(top__DOT__ex_opcode,6,0);
    VL_SIG8(top__DOT__ex_dst_reg,4,0);
    VL_SIG8(top__DOT__next_ex_dst_reg,4,0);
    VL_SIG8(top__DOT__imm_or_reg2,0,0);
    VL_SIG8(top__DOT__next_imm_or_reg2,0,0);
    VL_SIG8(top__DOT__mem_opcode_ex,6,0);
    VL_SIG8(top__DOT__is_mem_load_ex,0,0);
    VL_SIG8(top__DOT__next_is_mem_load_ex,0,0);
    VL_SIG8(top__DOT__mem_dst_reg,4,0);
    VL_SIG8(top__DOT__next_mem_dst_reg,4,0);
    VL_SIG8(top__DOT__mem_opcode,6,0);
    VL_SIG8(top__DOT__is_mem_load,0,0);
    VL_SIG8(top__DOT__next_is_mem_load,0,0);
    VL_SIG8(top__DOT__wb_dst_reg,4,0);
    VL_SIG8(top__DOT__next_wb_dst_reg,4,0);
    VL_SIG8(top__DOT__wb_enable,0,0);
    VL_SIG8(top__DOT__next_wb_enable,0,0);
    VL_SIG8(top__DOT__rf_reg1,4,0);
    VL_SIG8(top__DOT__rf_reg2,4,0);
    VL_SIG8(top__DOT__if_stage__DOT__buffer_index,5,0);
    VL_SIG8(top__DOT__if_stage__DOT__next_buffer_index,5,0);
    VL_SIG8(top__DOT__if_stage__DOT__empty_buffer,0,0);
    VL_SIG8(top__DOT__if_stage__DOT__next_empty_buffer,0,0);
    VL_SIG8(top__DOT__if_stage__DOT__state,1,0);
    VL_SIG8(top__DOT__if_stage__DOT__next_state,1,0);
    VL_SIG8(top__DOT__mem_stage__DOT__state,1,0);
    VL_SIG8(top__DOT__mem_stage__DOT__next_state,1,0);
    VL_SIG8(top__DOT__mem_stage__DOT__ctr,2,0);
    VL_SIG8(top__DOT__mem_stage__DOT__next_ctr,2,0);
    //char	__VpadToAlign149[3];
    VL_SIG(top__DOT__instruction,31,0);
    VL_SIG(top__DOT__next_instruction,31,0);
    VL_SIG(top__DOT__imm,19,0);
    VL_SIG(top__DOT__rf__DOT__unnamedblk1__DOT__i,31,0);
    VL_SIGW(top__DOT__if_stage__DOT__instruction_buffer,511,0,16);
    VL_SIG64(top__DOT__pc,63,0);
    VL_SIG64(top__DOT__next_if_pc,63,0);
    VL_SIG64(top__DOT__jump_pc,63,0);
    VL_SIG64(top__DOT__id_instr_pc,63,0);
    VL_SIG64(top__DOT__next_id_instr_pc,63,0);
    VL_SIG64(top__DOT__ex_instr_pc,63,0);
    VL_SIG64(top__DOT__next_ex_instr_pc,63,0);
    VL_SIG64(top__DOT__r1_val,63,0);
    VL_SIG64(top__DOT__next_r1_val,63,0);
    VL_SIG64(top__DOT__r2_val,63,0);
    VL_SIG64(top__DOT__next_r2_val,63,0);
    VL_SIG64(top__DOT__ex_res,63,0);
    VL_SIG64(top__DOT__next_ex_res,63,0);
    VL_SIG64(top__DOT__r2_val_mem,63,0);
    VL_SIG64(top__DOT__next_r2_val_mem,63,0);
    VL_SIG64(top__DOT__wb_dst_val,63,0);
    VL_SIG64(top__DOT__next_wb_dst_val,63,0);
    VL_SIG64(top__DOT__if_stage__DOT__buffer_start,63,0);
    VL_SIG64(top__DOT__if_stage__DOT__next_buffer_start,63,0);
    VL_SIG64(top__DOT__if_stage__DOT__next_buffer_data,63,0);
    VL_SIG64(top__DOT__rf__DOT__registers[32],63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG8(__Vtable1_top__DOT__mem_stage__DOT__next_ctr[32],2,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__mem_stage__DOT__next_state[32],1,0);
    VL_SIG8(top__DOT____Vcellout__id_stage__mem_opcode,0,0);
    VL_SIG8(__Vtableidx1,4,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign655[1];
    VL_SIG(top__DOT____Vcellout__id_stage__imm,20,0);
    VL_SIG(top__DOT____Vcellinp__ex_stage__mem_opcode,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    //char	__VpadToAlign668[4];
    VL_SIG64(top__DOT____Vcellout__id_stage__ex_opcode,63,0);
    VL_SIG8(__Vtablechg1[32],1,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign716[4];
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
    static void	_combo__TOP__4(Vtop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
