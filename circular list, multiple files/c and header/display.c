#include "main.h"
#include <stdio.h>
#include <assert.h>
void display(Node *head, Node *tail) // no need for parameters, because head, data, next are already global and the only new one (temp) is created inside the function
{
    if (head == NULL)
        printf("List is empty\n");

    else
    {
        printf("List elements are: \n");
        Node *temp = head; // define a Node pointer 'temp' and initialize with head, temp as in temporary and temp doesnt work outside this else function, its like a very local variable
        assert(temp != NULL);
        while (temp->next != head)
        {
            printf("%d -> ", temp->data); 
            temp = temp->next;
        }
        printf("%d\n", temp->data); 
    }
}
