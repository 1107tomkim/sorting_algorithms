#include "sort.h"

/**
 * heap_sort - Sorts array of in in ascending order
 * @array: list of int
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

/**
 * sift_down - Sorts heap so parents val is greater than child
 * @array: list of int
 * @start: start of array
 * @end: end of array
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t left_child, right_child, swap;
	int temp;

	while ((left_child = (2 * start) + 1) <= end)
	{
		swap = start;
		right_child = left_child + 1;
		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child <= end && array[swap] < array[right_child])
			swap = right_child;
		if (swap == start)
			return;
		temp = array[start];
		array[start] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		start = swap;
	}
}

/**
 * make_heap - make heap from unsorted array
 * @array: array used to make heap
 * @size: size of array
 */
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		sift_down(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}
