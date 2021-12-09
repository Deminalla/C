/*Sudaryti ciklinį vienpusį sąrašą. Parašyti procedūrą, kuri įterpia prieš reikšme nurodytą elementą naują elementą.
Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.*/
//#define NDEBUG //turns off assert
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <assert.h>
#include "main.h" //a header is almost like a library that makes your functions, standard ones. Its just a file that contains your function
void insert();

Node *head = NULL; //gloabl
Node *tail = NULL;

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
            if (head!=NULL){ 
                printf ("1. Delete previous list \n2. Add to previous list \n");
                printf("Enter your choice: ");
                assert(scanf("%d", &choice) == 1 && isspace(getchar()));
                if (choice==1){
                     head = NULL; //jeigu trinam
                }
            }
            read_file(list_file, list_filename); //read.c file
            list_file = fopen(list_filename, "r");
            create_list(list_file, &head, &tail); //create.c file
        }
        else if (choice == 2)
        {
            display(head, tail); //display.c file
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
void insert()
{
    int value, criteria, insertion = 0;
    new_node_before(&value, &criteria); //node_input.c file

    Node *new_node, *original;  //we dont need to allocate memory if we are just going to equalize it to a structure without dirrectly giving it a value
    original = tail->next; // head

    if (head->data == criteria)
    {
        insertion = 1;
        new_node = (Node *)malloc(sizeof(Node)); //we allocate memory if we plan on giving it a value (->data)
        assert(new_node != NULL);

        new_node->data = value;
        new_node->next = head;
        head = new_node;
        tail->next = new_node;
        original = original->next; // if we already added an element at the front, go forward by 1 more
    }
    do
    {
        if (original->next->data == criteria) // check if the answer after the original list's element is the number, before which we want to put an element
        {
            insertion = 1;
            new_node = (Node *)malloc(sizeof(Node));
            assert(new_node != NULL); 
            new_node->data = value;
            new_node->next = original->next; // what comes after original is the same as what comes after the new_node
            original->next = new_node;       // Adding newly allocated node after original
            original = original->next;       // if we add an element, go forward by 1 more
        }
        original = original->next;
    } while (original != tail->next);
    if (insertion == 0)
    {
        printf("%d could not be found in the list\n", criteria);
    }
}
