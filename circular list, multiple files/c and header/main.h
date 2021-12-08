#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
struct Node 
{
    int data;
    struct Node *next; 
};
typedef struct Node Node; //update  pridėjau typedef, kaip ir sakėt, tai jau užteks rašyt tik Node vietoj struct Node

void new_node_before(int *value, int *criteria);
void read_file(FILE *list_file, char *list_filename);
void display(Node *head, Node *tail);

#endif
