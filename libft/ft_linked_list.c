#include "headers/libft.h"

t_list* createNode(void* data) {
	t_list* newNode = (t_list*)malloc(sizeof(t_list));
	if (newNode == NULL) {
		ft_printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data; // Veriyi kopyala
	newNode->next = NULL;
	return newNode;
}

void push(t_list** head, void* data) {
	t_list* newNode = createNode(data);

	newNode->next = *head;
	*head = newNode;
}

void pop(t_list** head) {
	if (*head == NULL) {
		ft_printf("List is empty, cannot pop.\n");
		return;
	}

	t_list* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void removeNode(t_list** head, void* data) {
	t_list* current = *head;
	t_list* prev = NULL;

	// İlgili değeri ara
	while (current != NULL && current->data != data) {
		prev = current;
		current = current->next;
	}

	// Değer bulunduysa, düğümü çıkar
	if (current != NULL) {
		if (prev != NULL) {
			prev->next = current->next;
		} else {
			// İlk düğümü çıkarıyorsak, head'i güncelle
			*head = current->next;
		}
		free(current);
	}
}

t_list* reverseList(t_list* head) {
	t_list* prev = NULL;
	t_list* current = head;
	t_list* nextNode;

	while (current != NULL) {
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}

	return prev; // Tersine çevrilmiş liste başı
}

// Bağlı listeyi ekrana yazdıran fonksiyon
void printList(t_list* head) {
	while (head != NULL) {
		ft_printf("%p -> ", head->data);
		head = head->next;
	}
}
