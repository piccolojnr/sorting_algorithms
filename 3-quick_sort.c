#include "sort.h"
/**
 * lomuto_partition - partitions the array using Lomuto partition scheme
 * @arr: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: index of the pivot
 */
size_t lomuto_partition(int *arr, int low, int high, size_t size)
{
int i = low, tmp, j;

for (j = low; j <= high - 1; j++)
{
if (arr[j] < arr[high])
{
if (i < j)
{
tmp = arr[i];
arr[i] = arr[j];
arr[j] = tmp;
print_array(arr, size);
}
i++;
}
}
if (arr[i] > arr[high])
{
tmp = arr[i];
arr[i] = arr[high];
arr[high] = tmp;
print_array(arr, size);
}

return (i);
}
/**
 * quick_sort_helper - sorts an array of integers in ascending order using
 * @arr: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 */
void quick_sort_helper(int *arr, int low, int high, size_t size)
{
size_t pivot_index;
if (low < high)
{
pivot_index = lomuto_partition(arr, low, high, size);
quick_sort_helper(arr, pivot_index + 1, high, size);
quick_sort_helper(arr, low, pivot_index - 1, size);
}
}
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_helper(array, 0, size - 1, size);
}
