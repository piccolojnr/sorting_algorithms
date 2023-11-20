#include "sort.h"
void get_max(int *array, size_t size, int *max);
void get_count(int *array, size_t size, int *count, size_t range);

/**
 * get_max - Get the maximum and minimum values in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @max: A pointer to the maximum value.
 */
void get_max(int *array, size_t size, int *max)
{
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > *max)
{
*max = array[i];
}
}
}
/**
 * get_count - Count the number of occurrences of each value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @count: An array to store the counts.
 * @range: The range of values in the array.
 */
void get_count(int *array, size_t size, int *count, size_t range)
{
size_t i, j, k;
for (i = 0; i < range; i++)
count[i] = 0;
for (j = 0; j < size; j++)
count[array[j]]++;
for (k = 1; k < range; k++)
count[k] += count[k - 1];
count[0] = 0;
}
/**
 * counting_sort - Sort an array of integers in ascending order using
 * counting sort.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
size_t i, j;
int max = array[0];
size_t range;
int *count, *output;
if (array == NULL || size < 2)
{
return;
}

get_max(array, size, &max);

range = max + 1;
count = (int *)malloc(range *sizeof(int));
output = (int *)malloc(size * sizeof(int));
if (count == NULL || output == NULL)
{
free(count);
free(output);
return;
}
get_count(array, size, count, range);
print_array(count, range);
for (i = 0; i < size; i++)
{
output[count[array[i]] - 1] = array[i];
}
for (j = 0; j < size; j++)
{
array[j] = output[j];
}
free(count);
free(output);
}
