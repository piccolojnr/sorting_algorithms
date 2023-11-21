#include "sort.h"

void heapify(int *arr, size_t size);
void sift_down(int *arr, size_t size, size_t root, size_t end);
void swap(int *arr, size_t i, size_t j);

/**
 * swap - Swaps two elements in an array.
 * @arr: The array.
 * @i: The index of the first element.
 * @j: The index of the second element.
 */
void swap(int *arr, size_t i, size_t j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

/**
 * heapify - Builds a max heap from an array.
 * @arr: The array.
 * @size: The size of the array.
 */
void heapify(int *arr, size_t size)
{
size_t start;
start = (size - 2) / 2;
while (start > 0)
{
start--;
sift_down(arr, size, start, size);
}
}

/**
 * sift_down - Sifts a node down the heap.
 * @arr: The array.
 * @size: The size of the array.
 * @root: The index of the root node.
 * @end: The index of the last node.
 */
void sift_down(int *arr, size_t size, size_t root, size_t end)
{
size_t child;
while (root * 2 + 1 < end)
{
child = root * 2 + 1;
if (child + 1 < end && arr[child + 1] > arr[child])
child++;
if (arr[root] < arr[child])
{
swap(arr, root, child);
print_array(arr, size);
root = child;
}
else
return;
}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
size_t end;
if (array == NULL || size < 2)
return;
heapify(array, size);
end = size;
while (end > 1)
{
end--;
swap(array, 0, end);
print_array(array, size);
sift_down(array, size, 0, end);
}
}
