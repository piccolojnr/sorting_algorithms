#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, minidx;
int tmp;

if (array == NULL)
return;
for (i = 0; i < size - 1; i++)
{
minidx = i;
for (j = i + 1; j < size; j++)
{
if (array[minidx] > array[j])
{
minidx = j;
}
}
if (array[i] != array[minidx])
{
tmp = array[i];
array[i] = array[minidx];
array[minidx] = tmp;
print_array(array, size);
}
}
}
