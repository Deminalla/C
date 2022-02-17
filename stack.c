#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10 // if there is a limit in stack elements

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *top[100] = {0};

void push(int j, int stack[], int *status);
void pop(int j, int stack[], int status);
void peek(int j, int stack[], int status);
void check(int j, int stack[], int choice2, int *status);
void delete (int j, int stack[]);

int main()
{
    int choice, choice2, value;
    int status = -3;
    int i = 0, j;
    int stack[100] = {0};

    while (1){
        printf("\n*********** MENU *************\n");
        printf("1. Create stack \n2. Push \n3. Pop \n4. Peek \n5. Delete stack\n6. Check if stack is empty/full \n7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1 && isspace(getchar())){
            if (choice == 1){
                printf("Enter stack number: ");
                scanf("%d", &i);
                if (stack[i] < 1){
                    stack[i] = 1;
                    status=-3; //stack exists but we dont know if full/empty/eh
                }
                else printf("Stack already exists");
            }
            else if (choice == 2){
                printf("Which stack to push to: ");
                scanf("%d", &j);
                check(j, stack, 2, &status);
                push(j, stack, &status);
            }
            else if (choice == 3){
                printf("Which stack to pop out of: ");
                scanf("%d", &j);
                check(j, stack, 1, &status);
                pop(j, stack, status);
            }
            else if (choice == 4){
                printf("Which stack to peek at: ");
                scanf("%d", &j);
                check(j, stack, 1, &status);
                peek(j, stack, status);
            }
            else if (choice == 5){
                printf("Which stack to delete: ");
                scanf("%d", &j);
                if (stack[j] >= 1){
                    delete (j, stack);
                }
                else{
                    printf("Such stack does not exist\n");
                }
            }
            else if (choice == 6){
                printf("Which stack to check: ");
                scanf("%d", &j);
                printf("1. Empty \n2. Full \n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                check(j, stack, choice2, &status);
                if (status != -1){
                if (choice2 == 1){
                    if (status!=0){
                        printf("Stack is not empty\n");
                    }}
                else if (choice2 == 2){
                    if (status!=2){
                        printf("Stack is not full\n"); // if there is a limit in stack elements
                    }}
                }}
            else if (choice == 7){
                exit(0);
            }
        }
        else while (!isspace(getchar()));
    }
    return 0;
}
void push(int j, int stack[], int *status){
    if ((*status) == 0 || (*status) == 1){
    int value;
    Node *new_node;
    printf("Enter value: ");
    scanf("%d", &value);
    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = top[j];
    top[j] = new_node; //push to the top
    stack[j]++;
    }
}
void pop(int j, int stack[], int status){
    if (status > 0){
        printf("%d is out of stack\n", top[j]->data);
        stack[j]--; //dec stack element nr
        top[j] = top[j]->next; //previous element is now top
    }
}
void peek(int j, int stack[], int status){
    if (status > 0){
        printf("%d is the top of stack", top[j]->data);
    }
}
void check(int j, int stack[], int choice2, int *status){
    if (stack[j] < 1){
        printf("Such stack doesn't exist\n");
        (*status) = -1;
    }
    else{
        if (choice2 == 1){
            if (top[j] == NULL){
                printf("Stack is empty\n");
                (*status) = 0;
            }
        }
        else if (choice2 == 2){
            if (stack[j] - 1 >= MAX){ // if there is a limit in stack elements
                printf("Stack overflow\n");
                (*status) = 2;
            }
        }
        if ((*status) == -3){ 
            (*status) = 1; //not full and not empty
        }
    }
}
void delete (int j, int stack[]){
    stack[j] = 0;
    top[j] = NULL;
}
