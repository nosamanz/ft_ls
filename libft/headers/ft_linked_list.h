#ifndef FT_LINKED_LIST
#define FT_LINKED_LIST

typedef struct s_list {
	void*			data;
	struct s_list*	next;
} t_list;

t_list* createNode(void* data);
void push(t_list** head, void* data);
void pop(t_list** head);
void removeNode(t_list** head, void* data);
void printList(t_list* head);
t_list* reverseList(t_list* head);

#endif
