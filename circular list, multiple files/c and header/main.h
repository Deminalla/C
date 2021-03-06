#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node; // from now on struct Node is simply Node

void new_node_before(int *value, int *criteria);             // node_input.c
void read_file(FILE *list_file, char *list_filename);        // read.c
void display(Node *head, Node *tail);                        // display.c
void create_list(FILE *list_file, Node **head, Node **tail); // create.c

#endif
