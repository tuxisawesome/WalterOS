#include "kernelUtil.h"
#include "memory/heap.h"
#include "scheduling/pit/pit.h"
#include "ahci/ahci.h"
extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    GlobalRenderer->Print("WalterOS Core 20"); GlobalRenderer->Next();
    GlobalRenderer->Print("Walter Brobson, 2023"); GlobalRenderer->Next();
    while(true){
        asm ("hlt");
    }

}