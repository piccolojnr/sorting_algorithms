#include "sort.h"
/**
 * hoare_partition - partitions the array using hoare partition scheme
 * @array: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: index of the pivot
 */
size_t hoare_partition(int *array, size_t size, size_t low, size_t high)
{
    size_t curr_indx, cmp_indx, count;
    int curr, cmp, tmp, direction = 0;

    curr_indx = low;
    curr = array[curr_indx];
    cmp_indx = high;

    count = 0;
    while (low != high)
    {
        cmp = array[cmp_indx];
        if ((!direction && curr > cmp) || (direction && cmp > curr))
        {
            tmp = array[curr_indx];
            array[curr_indx] = array[cmp_indx];
            array[cmp_indx] = tmp;
            tmp = curr_indx;
            curr_indx = cmp_indx;
            cmp_indx = tmp;
            if (direction)
                direction = 0;
            else
                direction = 1;
        }
        if (direction)
            cmp_indx++;
        else
            cmp_indx--;
        if (count == high - low)
            break;
        count++;
    }
    print_array(array, size);
    return (curr_indx);
}
/**
 * quick_sort_helper - sorts an array of integers in ascending order using
 * @array: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 */
void quick_sort_helper(int *array, size_t size, size_t low, size_t high)
{
    size_t partition, i;
    for (i = low; i < high; i++)
    {
        partition = hoare_partition(array, size, i, high - 1);
        if (partition != low)
        {
            quick_sort_helper(array, size, low, partition);
            low = partition + 1;
        }
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
    quick_sort_helper(array, size, 0, size);
}
