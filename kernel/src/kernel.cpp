#include "kernelUtil.h"
#include "memory/heap.h"
#include "scheduling/pit/pit.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;
    
    GlobalRenderer->Print("WalterOS Core 16"); GlobalRenderer->Next();

    // Code goes below...

    PIT::SetDivisor(65535);
    GlobalRenderer->Print(to_hstring((uint64_t)bootInfo->rsdp));  
    GlobalRenderer->Next();

    GlobalRenderer->Print(to_hstring((uint64_t)malloc(0x8000)));
    GlobalRenderer->Next();
    void* address = malloc(0x8000);
    GlobalRenderer->Print(to_hstring((uint64_t)address));
    GlobalRenderer->Next();
    GlobalRenderer->Print(to_hstring((uint64_t)malloc(0x100)));
    GlobalRenderer->Next();

    free(address);

    GlobalRenderer->Print(to_hstring((uint64_t)malloc(0x8000)));
    GlobalRenderer->Next();


    for (int t = 0; t < 200; t++) {
        GlobalRenderer->Print("g");
        PIT::Sleep(10);
    }
    while(true);
}