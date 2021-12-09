//update    the whole file :D
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
    create_list(list_file, &head, &tail); // create.c failas

    rewind(list_file); //atsuka poziciją į failo pradžią
    int *value_array;
    value_array = (int *)calloc(50, sizeof(int));
    assert(value_array != NULL);
    test_create(list_file, value_array);

    test_insert(3, 8, value_array); // 3 prieš 8
    
    free(value_array);
    fclose(list_file);
    return 0;
}
void test_create(FILE *list_file, int *value_array)
{
    Node *test_new_node;
    int node_nr = 0;
    while (fscanf(list_file, "%d", (value_array + node_nr)) != EOF) // visus sąrašo elementus išsaugoju masyve
    {
        node_nr++; // kiek elementų faile, tai tiek ir turi būti sąraše
    }
    int i = 0;
    test_new_node = head;
    for (int i = 0; i <= node_nr - 1; i++)
    {
        assert(test_new_node->data = (*(value_array + i))); // pagal masyvą tikrinu, ar visi elementai sąraše teisingai sudėlioti
        test_new_node = test_new_node->next;
    }
}
void test_insert(int value, int criteria, int *value_array) // jis panašus į tą kuris main.c, bet skirtumas tame, kad čia neprašo input'o ir čia yra assertų
{
    int insertion = 0;
    Node *new_node, *original; // original tai mano sukurtas (iš failo)
    original = tail->next;     // arba head
    if (head->data == criteria)
    {
        insertion = 1;
        new_node = (Node *)malloc(sizeof(Node)); // we allocate memory if we plan on giving it a value (->data)
        assert(new_node != NULL);

        new_node->data = value;
        new_node->next = head;
        head = new_node;
        tail->next = new_node;
        assert(head->data = value);                    // ar pradinis elementas yra naujas įterptasis
        assert(tail->next->data = value);              // ar ciklinis, kad po paskutinio eina naujas įterptasis
        assert((*value_array) = new_node->next->data); // ar buvęs pirmasis narys dabar eina po įterptojo
        assert((*value_array) = head->next->data);     // ar pradinis elementas yra naujas įterptasis (tikrinimas skirtingu metodu)
        original = original->next;                     // jeigu jau prisidėjo elementas, tai reik judint sąrašą vienu į priekį, kad netikrintų amžinai tą pątį elementą
    }
    do
    {
        if (original->next->data == criteria) // jeigu sekantis elementas yra tas, prieš kurį turim įterpti
        {
            insertion = 1;
            new_node = (Node *)malloc(sizeof(Node));
            assert(new_node != NULL);
            new_node->data = value;
            new_node->next = original->next;         // what comes after original is the same as what comes after the new_node
            original->next = new_node;               // naują elementą dedam po elemento, kuriame esam (jis yra prieš criteria)
            assert(criteria = new_node->next->data); // ar įdėjom naują elementą PRIEŠ reikiamą vietą
            original = original->next;               // jeigu jau prisidėjo elementas, tai reik judint sąrašą vienu į priekį, kad netikrintų amžinai tą pątį elementą
        }
        original = original->next;
    } while (original != tail->next);
    assert(insertion == 1); // kad įsitikinčiau ar sąraše rado prieš ką dėti naują elementą ar ne
}
