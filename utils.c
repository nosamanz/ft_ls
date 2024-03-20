#include "ft_ls.h"

tFiles *sortByMtime(tFiles *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	tFiles *sortedList = NULL;

	while (head != NULL)
	{
		tFiles *current = head;
		head = head->next;

		if (sortedList == NULL || current->mtime > sortedList->mtime)
		{
			current->next = sortedList;
			sortedList = current;
		}
		else
		{
			tFiles *temp = sortedList;
			while (temp->next != NULL && current->mtime < temp->next->mtime)
				temp = temp->next;
			current->next = temp->next;
			temp->next = current;
		}
	}
	return sortedList;
}

void pushFile(tFiles **head, void *data, time_t mtime)
{
	tFiles *newNode = (tFiles *)malloc(sizeof(tFiles));
	if (newNode == NULL)
	{
		ft_printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	newNode->name = data;
	if (mtime)
		newNode->mtime = mtime;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		tFiles *current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void reverse(tFiles **head_ref)
{
	tFiles *prev = NULL;
	tFiles *current = *head_ref;
	tFiles *nextNode;

	while (current != NULL) {
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}

	*head_ref = prev;
}