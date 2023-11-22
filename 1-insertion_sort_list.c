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
 * insertion_sort_list - sorts a linked list in ascending order
 * @list: header
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *tmp1, *tmp2, *tmp3;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = *list;
while (current)
{
tmp2 = current->prev;
tmp1 = current;
if (tmp2 && (tmp1->n < tmp2->n))
{
/* Swap tmp1 and tmp2 */
swap_values(list, tmp1, tmp2);
print_list(*list);
tmp1 = current;
current = tmp2;
tmp3 = tmp1;
while (tmp3)
{
tmp2 = tmp1->prev;
tmp1 = tmp3;
if (tmp2 && (tmp1->n < tmp2->n))
{
swap_values(list, tmp1, tmp2);
print_list(*list);
tmp3 = tmp2;
}
else
break;
tmp3 = tmp3->prev;
}
}
current = current->next;
}
}
