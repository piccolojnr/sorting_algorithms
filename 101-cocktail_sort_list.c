#include "sort.h"
/**
 * swap_values - swaps two nodes (tmp1 and tmp2) in a doubly linked list
 * @list: header
 * @tmp1: node 1
 * @tmp2: node 2
 */
void swap_values(listint_t **list, listint_t *tmp1, listint_t *tmp2)
{
if (tmp1->next)
tmp1->next->prev = tmp2;
if (tmp2->prev)
tmp2->prev->next = tmp1;
tmp2->next = tmp1->next;
tmp1->prev = tmp2->prev;
tmp2->prev = tmp1;
tmp1->next = tmp2;
if (!tmp1->prev)
*list = tmp1;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * @list: header
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *curr, *tmp1, *tmp2;
int swapped = 1;
while (swapped)
{
swapped = 0;
curr = *list;
while (curr->next)
{
if (curr->n > curr->next->n)
{
tmp1 = curr;
tmp2 = curr->next;
swap_values(list, tmp2, tmp1);
print_list(*list);
curr = tmp2;
swapped = 1;
}
curr = curr->next;
}
if (!swapped)
break;
swapped = 0;
while (curr->prev)
{
if (curr->n < curr->prev->n)
{
tmp1 = curr;
tmp2 = curr->prev;
swap_values(list, tmp1, tmp2);
print_list(*list);
curr = tmp2;
swapped = 1;
}
curr = curr->prev;
}
}
}
