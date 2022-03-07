#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "sort.h"
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* provided functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void make_heap(int *array, size_t size);
void radix_sort(int *array, size_t size);
unsigned int pow_10(unsigned int powten);
unsigned int count_sort(int *array, size_t size, unsigned int sort);

#endif
