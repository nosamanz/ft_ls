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

	// If the list is empty or the new node is alphabetically first
	if (*head == NULL || ft_strncmp((char *)data, (char *)((*head)->name), ft_strlen((char *)data)) < 0)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	// Find the correct position in alphabetical order
	tFiles *current = *head;
	while (current->next != NULL &&
			ft_strncmp((char *)data, (char *)(current->next->name), ft_strlen((char *)data)) > 0)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;
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

void remove_last_slashes(char *str)
{
	size_t len = ft_strlen(str);
	while (str[len - 1] == '/')
	{
		str[len - 1] = '\0';
		len--;
	}
}