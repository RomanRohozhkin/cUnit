#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

Node *node_create();
void node_delete(Node *node);

typedef struct List {
    struct Node *first;
} List;

List *list_create();
void list_delete(List *list);

void list_append(List *list, void *str);
void list_insert(List *list, int index, void *str);

void *list_get(List *list, int index);

void list_removeElement(List *list, int index);
void *list_pop(List *list, int index);

int list_length(List *list);
void list_print(List *list);

#endif
