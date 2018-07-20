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

void list_append(List *list, char *str);
void list_insert(List *list, int index, char *str);

char *list_get(List *list, int index);

void list_removeElement(List *list, int index);
char *list_pop(List *list, int index);

int list_length(List *list);
void list_print(List *list);

#endif

