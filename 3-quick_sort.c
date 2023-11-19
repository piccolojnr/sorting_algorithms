#include "sort.h"
/**
 * lomuto_partition - partitions the array using Lomuto partition scheme
 * @low: starting index of the array
 * @high: ending index of the array
 *
 * Return: index of the pivot
 */
size_t lomuto_partition(int *arr, int low, int high, size_t size)
{
int i = low - 1, aux, j;

for (j = low; j <= high - 1; j++)
{
if (arr[j] < arr[high])
{
i++;
if (i < j)
{
aux = arr[i];
arr[i] = arr[j];
arr[j] = aux;
print_array(arr, size);
}
}
}
if (arr[i + 1] > arr[high])
{
aux = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = aux;
print_array(arr, size);
}

return (i + 1);
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
