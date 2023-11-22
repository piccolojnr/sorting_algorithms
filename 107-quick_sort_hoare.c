#include "sort.h"
#include <math.h>

void swap_ints(int *a, int *b);
size_t hoare_partition(int *array, size_t size,
size_t left, size_t right);
void quick_sort_hoare_helper(int *array, size_t size,
size_t left, size_t right);
void quick_sort_hoare(int *array, size_t size);
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * hoare_partition - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
*/
size_t hoare_partition(int *array, size_t size,
size_t left, size_t right)
{
int pivot, above, below;

pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
swap_ints(array + above, array + below);
print_array(array, size);
}
}

return (above);
}

/**
 * quick_sort_hoare_helper - Implement the quicksort
 * algorithm through recursion.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
*/
void quick_sort_hoare_helper(int *array, size_t size,
size_t left, size_t right)
{
size_t pivot;
if (left < right && (int)left >= 0 && (int)right >= 0)
{
pivot = hoare_partition(array, size, left, right);

quick_sort_hoare_helper(array, size, left, pivot - 1);
quick_sort_hoare_helper(array, size, pivot + 1, right);
}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: The array to be sorted.
 * @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_hoare_helper(array, size, 0, size - 1);
}
