#include "lists.h"

/**
 * free_listint - this is a function that frees a linked list
 * @head: listint_t this is the  list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
