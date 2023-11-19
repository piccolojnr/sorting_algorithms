#include "sort.h"

size_t hoare_partition(int *array, size_t size, size_t start, size_t end)
{
size_t curr_indx, cmp_indx, count;
int curr, cmp, tmp, direction = 0;
curr_indx = start;
curr = array[curr_indx];
cmp_indx = end;
count = 0;
while (start != end)
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
if (count == end - start)
break;
count++;
}
print_array(array, size);
return (curr_indx);
}

void quick_sort_helper(int *array, size_t size, size_t start, size_t end)
{
size_t partition, i;
for (i = start; i < end; i++)
{
partition = hoare_partition(array, size, i, end - 1);
if (partition != start)
{
quick_sort_helper(array, size, start, partition);
start = partition + 1;
}
}
}

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_helper(array, size, 0, size);
}
