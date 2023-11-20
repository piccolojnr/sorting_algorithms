#include "sort.h"
void swap_values(listint_t **list, listint_t *second, listint_t *first);

/**
 * swap_values - swaps two nodes (tmp1 and tmp2) in a doubly linked list
 * @list: header
 * @second: node 1
 * @first: node 2
 */
void swap_values(listint_t **list, listint_t *second, listint_t *first)
{
if (second->next)
second->next->prev = first;
if (first->prev)
first->prev->next = second;
first->next = second->next;
second->prev = first->prev;
first->prev = second;
second->next = first;
if (!second->prev)
*list = second;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * @list: header
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *curr, *tmp1, *tmp2;
int swapped = 1;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (swapped)
{
swapped = 0;
for (curr = *list; curr->next; curr = curr->next)
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
}
if (!swapped)
break;
swapped = 0;
for (; curr->prev; curr = curr->prev)
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
}
}
}
