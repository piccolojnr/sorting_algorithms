#include "sort.h"
int get_max(int *array, size_t size);
void counting_radix_sort(int *array, size_t size, int exp, int *tmp);
void radix_sort(int *array, size_t size);

/**
 * get_max- Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
*/
int get_max(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * counting_radix_sort - Sort the significant digits of an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 * @exp: The current exponent being used.
 * @tmp: A buffer to store the sorted array.
*/
void counting_radix_sort(int *array, size_t size, int exp, int *tmp)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i;

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; (int)i >= 0; i--)
{
tmp[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = tmp[i];

print_array(array, size);
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
*/
void radix_sort(int *array, size_t size)
{
int *tmp, max, exp;

if (array == NULL || size < 2)
return;

tmp = malloc(sizeof(int) * size);
if (tmp == NULL)
return;

max = get_max(array, size);
for (exp = 1; max / exp > 0; exp *= 10)
counting_radix_sort(array, size, exp, tmp);

free(tmp);
}
