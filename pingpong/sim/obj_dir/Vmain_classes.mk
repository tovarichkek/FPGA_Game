# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vmain.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vmain \
	Vmain___024root__DepSet_h8b02a3a0__0 \
	Vmain___024root__DepSet_h3334316c__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vmain___024root__Slow \
	Vmain___024root__DepSet_h8b02a3a0__0__Slow \
	Vmain___024root__DepSet_h3334316c__0__Slow \
	Vmain___024root__DepSet_h3334316c__1__Slow \
	Vmain___024root__DepSet_h3334316c__2__Slow \
	Vmain___024root__DepSet_h3334316c__3__Slow \
	Vmain___024root__DepSet_h3334316c__4__Slow \
	Vmain___024root__DepSet_h3334316c__5__Slow \
	Vmain___024root__DepSet_h3334316c__6__Slow \
	Vmain___024root__DepSet_h3334316c__7__Slow \
	Vmain___024root__DepSet_h3334316c__8__Slow \
	Vmain___024root__DepSet_h3334316c__9__Slow \
	Vmain___024root__DepSet_h3334316c__10__Slow \
	Vmain___024root__DepSet_h3334316c__11__Slow \
	Vmain___024root__DepSet_h3334316c__12__Slow \
	Vmain___024root__DepSet_h3334316c__13__Slow \
	Vmain___024root__DepSet_h3334316c__14__Slow \
	Vmain___024root__DepSet_h3334316c__15__Slow \
	Vmain___024root__DepSet_h3334316c__16__Slow \
	Vmain___024root__DepSet_h3334316c__17__Slow \
	Vmain___024root__DepSet_h3334316c__18__Slow \
	Vmain___024root__DepSet_h3334316c__19__Slow \
	Vmain___024root__DepSet_h3334316c__20__Slow \
	Vmain___024root__DepSet_h3334316c__21__Slow \
	Vmain___024root__DepSet_h3334316c__22__Slow \
	Vmain___024root__DepSet_h3334316c__23__Slow \
	Vmain___024root__DepSet_h3334316c__24__Slow \
	Vmain___024root__DepSet_h3334316c__25__Slow \
	Vmain___024root__DepSet_h3334316c__26__Slow \
	Vmain___024root__DepSet_h3334316c__27__Slow \
	Vmain___024root__DepSet_h3334316c__28__Slow \
	Vmain___024root__DepSet_h3334316c__29__Slow \
	Vmain___024root__DepSet_h3334316c__30__Slow \
	Vmain___024root__DepSet_h3334316c__31__Slow \
	Vmain___024root__DepSet_h3334316c__32__Slow \
	Vmain___024root__DepSet_h3334316c__33__Slow \
	Vmain___024root__DepSet_h3334316c__34__Slow \
	Vmain___024root__DepSet_h3334316c__35__Slow \
	Vmain___024root__DepSet_h3334316c__36__Slow \
	Vmain___024root__DepSet_h3334316c__37__Slow \
	Vmain___024root__DepSet_h3334316c__38__Slow \
	Vmain___024root__DepSet_h3334316c__39__Slow \
	Vmain___024root__DepSet_h3334316c__40__Slow \
	Vmain___024root__DepSet_h3334316c__41__Slow \
	Vmain___024root__DepSet_h3334316c__42__Slow \
	Vmain___024root__DepSet_h3334316c__43__Slow \
	Vmain___024root__DepSet_h3334316c__44__Slow \
	Vmain___024root__DepSet_h3334316c__45__Slow \
	Vmain___024root__DepSet_h3334316c__46__Slow \
	Vmain___024root__DepSet_h3334316c__47__Slow \
	Vmain___024root__DepSet_h3334316c__48__Slow \
	Vmain___024root__DepSet_h3334316c__49__Slow \
	Vmain___024root__DepSet_h3334316c__50__Slow \
	Vmain___024root__DepSet_h3334316c__51__Slow \
	Vmain___024root__DepSet_h3334316c__52__Slow \
	Vmain___024root__DepSet_h3334316c__53__Slow \
	Vmain___024root__DepSet_h3334316c__54__Slow \
	Vmain___024root__DepSet_h3334316c__55__Slow \
	Vmain___024root__DepSet_h3334316c__56__Slow \
	Vmain___024root__DepSet_h3334316c__57__Slow \
	Vmain___024root__DepSet_h3334316c__58__Slow \
	Vmain___024root__DepSet_h3334316c__59__Slow \
	Vmain___024root__DepSet_h3334316c__60__Slow \
	Vmain___024root__DepSet_h3334316c__61__Slow \
	Vmain___024root__DepSet_h3334316c__62__Slow \
	Vmain___024root__DepSet_h3334316c__63__Slow \
	Vmain___024root__DepSet_h3334316c__64__Slow \
	Vmain___024root__DepSet_h3334316c__65__Slow \
	Vmain___024root__DepSet_h3334316c__66__Slow \
	Vmain___024root__DepSet_h3334316c__67__Slow \
	Vmain___024root__DepSet_h3334316c__68__Slow \
	Vmain___024root__DepSet_h3334316c__69__Slow \
	Vmain___024root__DepSet_h3334316c__70__Slow \
	Vmain___024root__DepSet_h3334316c__71__Slow \
	Vmain___024root__DepSet_h3334316c__72__Slow \
	Vmain___024root__DepSet_h3334316c__73__Slow \
	Vmain___024root__DepSet_h3334316c__74__Slow \
	Vmain___024root__DepSet_h3334316c__75__Slow \
	Vmain___024root__DepSet_h3334316c__76__Slow \
	Vmain___024root__DepSet_h3334316c__77__Slow \
	Vmain___024root__DepSet_h3334316c__78__Slow \
	Vmain___024root__DepSet_h3334316c__79__Slow \
	Vmain___024root__DepSet_h3334316c__80__Slow \
	Vmain___024root__DepSet_h3334316c__81__Slow \
	Vmain___024root__DepSet_h3334316c__82__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vmain__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
