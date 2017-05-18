#include "binaryheap.h"

struct heap *heap_create(int maxsize)
{
	struct heap *h;

	h = malloc(sizeof(*h));

	if (h != NULL) {
		h->maxsize = maxsize;
		h->nnodes = 0;
		h->index = (int*) malloc(sizeof(int) * (maxsize + 1));
		h->nodes = (struct heapnode*) malloc(sizeof(*h->nodes) * (maxsize + 1));

		if (h->nodes == NULL) {
			free(h);
			return NULL;
		}
	}

	return h;
}


void heap_free(struct heap *h)
{
	free(h->index);
	free(h->nodes);
	free(h);
}


void heap_swap(struct heapnode *a, struct heapnode *b, struct heap *h)
{
	struct heapnode temp;

	temp = *a;
	*a = *b;
	*b = temp;

	int tmp;

	tmp = h->index[a->value];
	h->index[a->value] = h->index[b->value];
	h->index[b->value] = tmp;
}


struct heapnode *heap_min(struct heap *h)
{
	if (h->nnodes == 0) {
		return NULL;
	}

	return &h->nodes[1];
}


int heap_insert(struct heap *h, int key, int value)
{
	if (h->nnodes >= h->maxsize) {
		return -1;
	}

	h->nnodes++;
	h->nodes[h->nnodes].key = key;
	h->nodes[h->nnodes].value = value;
	h->index[value] = h->nnodes;

	// HepifyUp
	int i;

	for (i = h->nnodes; i > 1 && h->nodes[i].key < h->nodes[i / 2].key; i = i / 2) {
		heap_swap(&h->nodes[i], &h->nodes[i / 2], h);
	}

	return 0;
}


struct heapnode heap_extract_min(struct heap *h)
{
	if (h->nnodes == 0) {
		return (struct heapnode){0, 0};
	}

	
	struct heapnode minnode = h->nodes[1];

	h->nodes[1] = h->nodes[h->nnodes];

	h->index[h->nodes[h->nnodes].value] = 1;

	h->nnodes--;
	heap_heapify(h, 1);

	return minnode;
}


void heap_heapify(struct heap *h, int index)
{
	for (;;) {
		int left = 2 * index;
		int right = 2 * index + 1;

		// Find least key : A[index], A[left] and A[right]
		int least = index;
		if (left <= h->nnodes && h->nodes[left].key < h->nodes[index].key) {
			least = left;
		}

		if (right <= h->nnodes && h-> nodes[right].key < h->nodes[least].key) {
			least = right;
		}

		if (least == index) {
			break;
		}

		heap_swap(&h->nodes[index], &h->nodes[least], h);
		index = least;
	}
}


int heap_decrease_key(struct heap *h, int index1, int key)
{
	index1 = h->index[index1];
	
	if (h->nodes[index1].key < key) {
		return -1;
	}

	h->nodes[index1].key = key;
	for (;index1 > 1 && h->nodes[index1].key < h->nodes[index1 / 2].key; index1 = index1 / 2) {
		heap_swap(&h->nodes[index1], &h->nodes[index1 / 2], h);
	}

	return index1;
}


void heap_print(struct heap *h)
{
	int i;

	for (i = 0; i < h->nnodes; i++) {
		printf("KEY = %d VALUE = %d\n", h->nodes[i].key, h->nodes[i].value);
	}
}


struct heap *heap_build(int *a, int a_size)
{
	struct heap *temp_heap;
	temp_heap = heap_create(a_size);

	int i;

	//Устанавливаем расстояние от начальной вершины s до всех остальных в ∞
	for (i = 0; i < a_size; i++) {
		heap_insert(temp_heap, a[i], i + 1);
	}

	return temp_heap;
}
