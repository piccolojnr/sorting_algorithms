#include "sort.h"
void swap(int *a, int *b);
void bitonic_split(int *array, size_t size,
size_t start, size_t count, int dir);
void bitonic_merge(int *array, size_t size,
size_t start, size_t count, int dir);

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
*/
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bitonic_split - splits a bitonic sequence into two halves
 * @array: array to sort
 * @size: size of the array
 * @start: starting index of the sequence
 * @count: length of the sequence
 * @dir: direction of sorting
*/
void bitonic_split(int *array, size_t size,
size_t start, size_t count, int dir)
{
size_t m = count / 2;

if (count > 1)
{
printf("Merging [%lu/%lu] (%s):\n", count, size, (dir == 1) ? "UP" : "DOWN");
print_array(array + start, count);

bitonic_split(array, size, start, m, 1);

bitonic_split(array, size, start + m, m, 0);
bitonic_merge(array, size, start, count, dir);

printf("Result [%lu/%lu] (%s):\n", count, size, (dir == 1) ? "UP" : "DOWN");
print_array(array + start, count);
}
}
/**
 * bitonic_merge - sorts a bitonic sequence
 * @array: array to sort
 * @size: size of the array
 * @start: starting index of the sequence
 * @count: length of the sequence
 * @dir: direction of sorting
*/
void bitonic_merge(int *array, size_t size,
size_t start, size_t count, int dir)
{
size_t i, m = count / 2;
if (count > 1)
{
for (i = start; i < start + m; i++)
{
if ((dir == 1 && array[i] > array[i + m]) ||
(dir == 0 && array[i] < array[i + m]))
{
swap(&array[i], &array[i + m]);
}
}
bitonic_merge(array, size, start, m, dir);
bitonic_merge(array, size, start + m, m, dir);
}
}
/**
 * bitonic_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
*/
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
bitonic_split(array, size, 0, size, 1);
}
