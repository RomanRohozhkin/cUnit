#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ci_linkedList.h"

Node *node_create() {
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    
    node->data = NULL;
    node->next = NULL;
    
    return node;
}

void node_delete(Node *node) {
    assert(node != NULL);
    free(node);
}

List *list_create() {
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    list->first = NULL;
    return list;
}

void list_delete(List *list) {
    assert(list != NULL);
    
    Node *node = list->first;
    Node *next;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void list_append(List *list, void *str) {
    assert(list != NULL);
    assert(str != NULL);
    
    if (list->first == NULL) {
        Node *node = node_create();
        list->first = node;
    }
    
    Node *node = list->first;
    while (node->next != NULL) {
        node = node->next;
    }
    
    node->data = str;
    node->next = node_create();
}

void list_insert(List *list, int index, void *str) {
    assert(list != NULL);
    assert(str !=NULL);
    assert(index >= index);
    assert(index <= list_length(list));
    
    if (index == 0) {
        Node *after = list->first;
        list->first = node_create();
        list->first->data = str;
        list->first->next = after;
    } else if (index == list_length(list)) {
        list_append(list, str);
    } else {
        Node *before = list->first;
        Node *after = list->first->next;
        while (index > 1) {
            index--;
            before = before->next;
            after = after->next;
        }
        before->next = node_create();
        before->next->data = str;
        before->next->next = after;
    }
}

char *list_get(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < list_length(list));
    
    Node *node = list->first;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node->data;
}

void list_removeElement(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < list_length(list));
    
    if (index == 0) {
        Node *node = list->first;
        list->first = list->first->next;
        node_delete(node);
    } else {
        Node *before = list->first;
        while (index > 1) {
            before = before->next;
            index--;
        }
        Node *node = before->next;
        before->next = before->next->next;
        node_delete(node);
    }
}

char *list_pop(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < list_length(list));
    
    if (index == 0) {
        Node *node = list->first;
        list->first = list->first->next;
        char *data = node->data;
        node_delete(node);
        return data;
    } else {
        Node *before = list->first;
        while (index > 1) {
            before = before->next;
            index--;
        }
        Node *node = before->next;
        before->next = before->next->next;
        char *data = node->data;
        node_delete(node);
        return data;
    }
}

int list_length(List *list) {
    assert(list != NULL);
    
    Node *node = list->first;
    int length = 0;
    while (node->next != NULL) {
        length++;
        node = node->next;
    }   
    return length;
}

void list_print(List *list) {
    assert(list != NULL);
    
    printf("[");
    Node *node = list->first;
    while (node->next != NULL) {
        printf("%s", node->data);
        node = node->next;
        if (node->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

