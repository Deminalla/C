#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void create_list(FILE *list_file, Node **head, Node **tail) // This function will add the new node to the list.
{
    int value;
    if ((fscanf(list_file, "%d", &value) != EOF))
    {
        Node *new_node = (Node *)malloc(sizeof(Node)); // Create new node, we allocate memory if we will give it a value 
        assert(new_node != NULL);
        new_node->data = value;      // assign a value to the new node
        if ((*head) == NULL)            // If list is empty, both head and tail would point to new node.
        {
            (*head) = new_node;
            (*tail) = new_node;
            new_node->next = (*head);
        }
        else
        {
            Node *temp;
            temp = (*tail);
            temp->next= new_node; // tail will point to new node.
            (*tail) = new_node;       // New node will become new tail.
            new_node->next = (*head);     // Since, it is circular linked list tail will point to head.
        }
        assert(((*tail)->next = (*head)) && ((*tail)->data = value)); // make sure its a circular linked list
        create_list(list_file, head, tail);    // recursion
    }
}
