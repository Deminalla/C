/*Sudaryti ciklinį vienpusį sąrašą. Parašyti procedūrą, kuri įterpia prieš reikšme nurodytą elementą naują elementą.
Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.*/
//#define NDEBUG //turns off assert
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <assert.h>
#include "read.h"
#include "new_node.h"
void create_list(FILE *list_file);
void display();
void insert();

struct Node // node is a data that is linked to other nodes
{
    int data;
    struct Node *next; // each struct node has a data item and a pointer to the next struct node
};
struct Node *head = NULL; //list is empty
struct Node *tail = NULL;

int main()
{
    int choice, value, criteria;
    FILE *list_file;
    char *list_filename;

    list_filename = (char *)calloc(50, sizeof(char));
    assert(list_filename != NULL);

    while (1)
    {
        printf("\n*********** MENU *************\n");
        printf("1. Create circular list \n2. Display circluar list \n3. Insert element \n4. Exit\n");
        printf("Enter your choice: ");
        assert(scanf("%d", &choice) == 1 && isspace(getchar()));
        if (choice == 1)
        {
            read_file(list_file, list_filename); //read.c file
            list_file = fopen(list_filename, "r");
            head = NULL; // because we create a new list, we need to get rid of the previous one
            create_list(list_file);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            insert();
        }
        else if (choice == 4)
        {
            exit(0);
        }
    }
    fclose(list_file);
    free(list_file);
    return 0;
}
void create_list(FILE *list_file) // This function will add the new node to the list.
{
    int value;
    if ((fscanf(list_file, "%d", &value) != EOF))
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // Create new node, we allocate memory if we will give it a value 
        assert(new_node != NULL);
        new_node->data = value;      // assign a value to the new node
        if (head == NULL)            // If list is empty, both head and tail would point to new node.
        {
            head = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else
        {
            tail->next = new_node; // tail will point to new node.
            tail = new_node;       // New node will become new tail.
            tail->next = head;     // Since, it is circular linked list tail will point to head.
        }
        assert((tail->next = head) && (tail->data = value)); // make sure its a circular linked list
        create_list(list_file);    // recursion
    }
}
void insert()
{
    int found_node = 0;
    int value, criteria;
    new_node_before(&value, &criteria); //new_node.c file

    struct Node *new_node, *original;  //we dont need to allocate memory if we are just going to equalize it to a structure without dirrectly giving it a value
    assert(new_node != NULL);
    original = tail->next; // head

    if (head->data == criteria)
    {
        found_node = 1;
        new_node = (struct Node *)malloc(sizeof(struct Node)); //we allocate memory if we plan on giving it a value (->data)
        assert(new_node != NULL);

        new_node->data = value;
        new_node->next = head;
        head = new_node;
        tail->next = new_node;
        assert(head->data = value);
        assert(tail->next->data = value);
        original = original->next; // if we already added an element at the front, go forward by 1 more
    }
    do
    {
        if (original->next->data == criteria) // check if the answer after the original list's element is the number, before which we want to put an element
        {
            found_node = 1;
            new_node = (struct Node *)malloc(sizeof(struct Node));
            assert(new_node != NULL); 
            new_node->data = value;
            new_node->next = original->next; // what comes after original is the same as what comes after the new_node
            original->next = new_node;       // Adding newly allocated node after original
            original = original->next;       // if we add an element, go forward by 1 more
        }
        original = original->next;
    } while (original != tail->next);
    if (found_node == 0)
    {
        printf("%d could not be found in the list\n", criteria);
    }
}
void display() // no need for parameters, because head, data, next are already global and the only new one (temp) is created inside the function
{
    if (head == NULL)
        printf("List is empty\n");

    else
    {
        printf("List elements are: \n");
        struct Node *temp = head; // define a Node pointer 'temp' and initialize with head, temp as in temporary and temp doesnt work outside this else function, its like a very local variable
        assert(temp != NULL);
        while (temp->next != head)
        {
            printf("%d -> ", temp->data); // keep displaying temp → data until temp reaches the last node
            temp = temp->next;
        }
        printf("%d\n", temp->data); // i could also add head -> data then it would also print the first element in the list
    }
}
