# Memory-pool phased test

This sample emits `[OO_TEST]` markers to GoldHEN KLog and keeps the process
alive after each phase. A missing `pass` marker identifies the phase that
failed or crashed.

The current runtime phase calls `sceKernelMemoryPoolGetBlockStats` once. The
remaining memory-pool APIs are referenced for import coverage and should be
added as isolated phases only after their argument safety is established.

The package must include `libc.prx` and `libSceFios2.prx` in `sce_module/`,
plus the normal `sce_sys/about/right.sprx` and icon assets.
