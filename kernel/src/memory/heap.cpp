#include "heap.h"
#include "../paging/PageTableManager.h"
#include "../paging/PageFrameAllocator.h"
void* heapStart;
void* heapEnd;
HeapSegHdr* LastHdr;

void InitializeHeap(void* heapAddress, size_t pageCount) {
    void* pos= heapAddress;

    for (size_t i = 0; i < pageCount; i++) {
        g_PageTableManager.MapMemory(pos, GlobalAllocator.RequestPage());
        pos = (void*)((size_t)pos + 0x1000);
    }

    size_t heapLength = pageCount * 0x1000;

    heapStart = heapAddress;
    heapEnd = (void*)((size_t)heapStart + heapLength);
    HeapSegHdr* startSeg = (HeapSegHdr*)heapAddress;
    startSeg->length = heapLength - sizeof(HeapSegHdr);
    startSeg->next = NULL;
    startSeg->last = NULL;
    startSeg->free = true;
    LastHdr = startSeg;
}