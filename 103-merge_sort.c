#include "sort.h"
void copy_array(int *arr, size_t begin, size_t end, int *buffer);
void top_down_split_merge(int *arr, size_t begin, size_t end, int *buffer);
void top_down_merge(int *buffer, size_t begin,
size_t middle, size_t end, int *arr);

/**
 * copy_array - copies an array
 * @arr: array to copy
 * @begin: beginning of the array
 * @end: end of the array
 * @buffer: buffer to store the copy
*/
void copy_array(int *arr, size_t begin, size_t end, int *buffer)
{
size_t i;

for (i = begin; i < end; i++)
buffer[i] = arr[i];
}

/**
 * top_down_split_merge - splits and merges an array
 * @arr: array to split and merge
 * @begin: beginning of the array
 * @end: end of the array
 * @buffer: buffer to store the merged array
*/
void top_down_split_merge(int *arr, size_t begin, size_t end, int *buffer)
{
size_t middle;

if (end - begin <= 1)
return;

middle = (end + begin) / 2;

top_down_split_merge(arr, begin, middle, buffer);
top_down_split_merge(arr, middle, end, buffer);

top_down_merge(buffer, begin, middle, end, arr);
}

/**
 * top_down_merge - merges two sorted arrays into one
 * @buffer: buffer to store the merged array
 * @begin: beginning of the first array
 * @middle: end of the first array
 * @end: end of the second array
 * @arr: array to merge
*/
void top_down_merge(int *buffer, size_t begin,
size_t middle, size_t end, int *arr)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(arr + begin, middle - begin);

printf("[right]: ");
print_array(arr + middle, end - middle);

for (i = begin, j = middle; i < middle && j < end; k++)
{
if (arr[i] < arr[j])
buffer[k] = arr[i++];
else
buffer[k] = arr[j++];
}
for (; i < middle; i++)
buffer[k++] = arr[i];
for (; j < end; j++)
buffer[k++] = arr[j];
for (i = begin, k = 0; i < end; i++)
arr[i] = buffer[k++];
printf("[Done]: ");

print_array(arr + begin, end - begin);
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * merge sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
int *buffer;

buffer = malloc(size * sizeof(int));
if (buffer == NULL)
return;

copy_array(array, 0, size, buffer);
top_down_split_merge(array, 0, size, buffer);

free(buffer);
}
