#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void create_list(FILE *list_file, Node **head, Node **tail) // this function will add the new node to the list.
{
    int value;
    if ((fscanf(list_file, "%d", &value) != EOF))
    {
        Node *new_node = (Node *)malloc(sizeof(Node)); 
        assert(new_node != NULL);
        new_node->data = value; // assign a value to the new_node
        if ((*head) == NULL)    // if list is empty, both head and tail would point to new_node
        {
            (*head) = new_node;
            (*tail) = new_node;
            new_node->next = (*head);
        }
        else
        {
            Node *temp;
            temp = (*tail);
            temp->next = new_node;    
            (*tail) = new_node;       // new_node will become new tail.
            new_node->next = (*head); // since, it is circular linked list, tail has to point to head.
        }
        create_list(list_file, head, tail);                           // recursion
    }
}
