#include <orbis/libkernel.h>

static volatile uintptr_t api_refs[] = {
    (uintptr_t)&sceKernelMemoryPoolExpand,
    (uintptr_t)&sceKernelMemoryPoolReserve,
    (uintptr_t)&sceKernelMemoryPoolCommit,
    (uintptr_t)&sceKernelMemoryPoolDecommit,
    (uintptr_t)&sceKernelMemoryPoolBatch,
    (uintptr_t)&sceKernelMemoryPoolGetBlockStats,
};

static void log_text(const char *text)
{
    sceKernelDebugOutText(0, text);
}

static void log_result(int phase, int32_t result)
{
    sceKernelDebugOutText(0, "[OO_TEST] phase=%d result rc=0x%x\n", phase,
                          (uint32_t)result);
}

int main(void)
{
    (void)api_refs;
    log_text("[OO_TEST] phase=01 begin imports\n");
    log_text("[OO_TEST] phase=01 pass\n");

    log_text("[OO_TEST] phase=02 begin GetBlockStats\n");
    OrbisKernelMemoryPoolBlockStats stats = {};
    const int32_t result = sceKernelMemoryPoolGetBlockStats(&stats, sizeof(stats));
    log_result(2, result);
    log_text("[OO_TEST] phase=02 pass\n");

    log_text("[OO_TEST] complete\n");
    for (;;) {
    }
}
