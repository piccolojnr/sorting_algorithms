#include "sort.h"
/**
 * shell_sort_helper - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * @gap: gap between elements to be sorted
 */
void shell_sort_helper(int *array, size_t size, ssize_t gap)
{
ssize_t i, j;
int tmp;
for (i = gap; i < (ssize_t)size; i++)
{
tmp = array[i];
for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
{
array[j] = array[j - gap];
}
array[j] = tmp;
}
}
/**
 * shell_sort - sorts an array of integers in ascending order using the
 * shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
ssize_t gap;
if (array == NULL || size < 2)
return;
for (gap = 1; gap <= (ssize_t)size / 3; gap = gap * 3 + 1)
;
for (; gap > 0; gap /= 3)
{
shell_sort_helper(array, size, gap);
print_array(array, size);
}
}
