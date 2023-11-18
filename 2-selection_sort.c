#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j;
int tmp1, tmp2;
if (array == NULL)
return;
for (i = 0; i < size; i++)
{
tmp1 = array[i];
for (j = i + 1; j < size; j++)
{
if (tmp1 > array[j])
{
tmp2 = array[j];
array[j] = tmp1;
tmp1 = tmp2;
}
}
array[i] = tmp1;
print_array(array, size);
}
}
