#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Node *head = NULL;
Node *tail = NULL;
void test_create(FILE *list_file, int *value_array);
void test_insert(int value, int criteria, int *value_array);

int main()
{
    FILE *list_file;
    list_file = fopen("test1.txt", "r");
    create_list(list_file, &head, &tail); // create.c file

    rewind(list_file); //gets the position back to the beginning of the file
    int *value_array;
    value_array = (int *)calloc(50, sizeof(int));
    assert(value_array != NULL);
    test_create(list_file, value_array);

    test_insert(3, 8, value_array); // 3 before 8
    
    free(value_array);
    fclose(list_file);
    return 0;
}
void test_create(FILE *list_file, int *value_array)
{
    Node *test_new_node;
    int node_nr = 0;
    while (fscanf(list_file, "%d", (value_array + node_nr)) != EOF) // save all the elements in an array
    {
        node_nr++; // the amount of elements in file should equal to the nr of list elements
    }
    int i = 0;
    test_new_node = head;
    for (int i = 0; i <= node_nr - 1; i++)
    {
        assert(test_new_node->data = (*(value_array + i))); // check array to see if the list elements are put in the correct order
        test_new_node = test_new_node->next;
    }
}
void test_insert(int value, int criteria, int *value_array) 
{
    int insertion = 0;
    Node *new_node, *original; // original is the one i created (from the file)
    original = tail->next;     // head
    if (head->data == criteria)
    {
        insertion = 1;
        new_node = (Node *)malloc(sizeof(Node));
        assert(new_node != NULL);

        new_node->data = value;
        new_node->next = head;
        head = new_node;
        tail->next = new_node;
        assert(head->data = value);                    // if the first element is the new inserted one
        assert(tail->next->data = value);              // if the list is circular
        assert((*value_array) = new_node->next->data); // if the previous first element is now after the inserted one
        assert((*value_array) = head->next->data);     // if the first element is the new inserted one (a different testing method)
        original = original->next;                     // if smth was inserted we need to move forward by one so it doesnt test the same element forever
    }
    do
    {
        if (original->next->data == criteria) // if the next element is the one before which we need to insert
        {
            insertion = 1;
            new_node = (Node *)malloc(sizeof(Node));
            assert(new_node != NULL);
            new_node->data = value;
            new_node->next = original->next;         // what comes after original is the same as what comes after the new_node
            original->next = new_node;               // new element after the one on which we are now (it's before criteria)
            assert(criteria = new_node->next->data); // did we put the new element BEFORE the appropriate position
            original = original->next;               // if smth was inserted we need to move forward by one so it doesnt test the same element forever
        }
        original = original->next;
    } while (original != tail->next);
    assert(insertion == 1); // just to make sure if an insertion occured
}
