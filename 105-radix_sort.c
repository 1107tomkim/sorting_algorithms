#include "sort.h"

/**
 * radix_sort - sort array of int in ascending order
 * @array: list of int
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = count_sort(array, size, i);
		print_array(array, size);
	}
}

/**
 * pow_10 - multiplies a val to the 10th power
 * @powten: int used to calculated 10th power of
 * Return: 10th power of the int val
 */
unsigned int pow_10(unsigned int powten)
{
	unsigned int i, result;

	result = 1;
	for (i = 0; i < powten; i++)
		result *= 10;
	return (result);
}

/**
 * count_sort - sorts array of int in ascending order using count sort algo
 * @array: int of array
 * @size: size of array
 * @sort: val to sort by
 * Return: 1 if more sorting is needed, else 0
 */
unsigned int count_sort(int *array, size_t size, unsigned int sort)
{
	int i, count[10] = {0};
	int *copy = NULL;
	size_t j, temp, total = 0;
	unsigned int pos1, pos2, fort = 0;

	pos2 = pow_10(sort - 1);
	pos1 = pos2 * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] / pos1 != 0)
			fort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % pos1) / pos2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(copy[j] % pos1) / pos2]] = copy[j];
		count[(copy[j] % pos1) / pos2] += 1;
	}
	free(copy);
	return (fort);
}
