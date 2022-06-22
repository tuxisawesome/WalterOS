#include "kernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;
    
    GlobalRenderer->Print("WalterOS Core 16"); GlobalRenderer->Next();

    // Code goes below...




    

    while(true);
}