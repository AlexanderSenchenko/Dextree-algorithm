#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdlib.h>
#include <stdio.h>

struct heapnode {
	int key; // Priority (key)
	int value; // Data
};

struct heap {
	int *index; // Массив индексов для доступа к элементам кучи по индексу за константное время
	int maxsize; // Array size
	int nnodes; // Number of keys
	struct heapnode *nodes; // Nodes: [0..maxsize]
};

struct heap *heap_create(int maxsize);
void heap_free(struct heap *h);
void heap_swap(struct heapnode *a, struct heapnode *b, struct heap *h);
int heap_insert(struct heap *h, int key, int value);
struct heapnode *heap_min(struct heap *h);
struct heapnode heap_extract_min(struct heap *h);
void heap_heapify(struct heap *h, int index);
int heap_decrease_key(struct heap *h, int index, int key);
void heap_print(struct heap *h);
struct heap *heap_build(int *a, int a_size);

#endif
