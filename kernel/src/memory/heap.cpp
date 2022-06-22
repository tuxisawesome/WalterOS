#include "heap.h"
#include "../paging/PageTableManager.h"
#include "../paging/PageFrameAllocator.h"
void InitializeHeap(void* heapAddress, size_t pageCount) {
    void* pos= heapAddress;
    for (size_t i = 0; i < pageCount; i++) {
        g_PageTableManager.MapMemory(pos, GlobalAllocator.RequestPage());
    }
}