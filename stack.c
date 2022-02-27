#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *top[500] = {0};

void push(int j, int stack[], int status[]);
void pop(int j, int stack[], int status[]);
void display(int j, int stack[], int status[]);
void check(int j, int stack[], int choice2, int status[], int max[]);
void delete (int j, int stack[]);

int main(){
    int choice, choice2, value, i = 0, j;
    int status[500]; //exists, empty, full
    int stack[500] = {0}; //element nr in each stack
    int max[500] = {0}; //element limit

    while (1){
        printf("\n*********** MENU *************\n");
        printf("1. Create stack \n2. Push \n3. Pop \n4. View \n5. Delete stack\n6. Check if stack is empty/full \n7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1 && isspace(getchar())){
            if (choice == 1){
                printf("Which stack to create: ");
                scanf("%d", &i);
                if (stack[i] < 1){
                    stack[i] = 1;
                    printf("Enter element limit: ");
                    scanf("%d", &max[i]); //how many elements do you want
                }
                else printf("Stack already exists\n");
            }
            else if (choice == 2){
                printf("Which stack to push to: ");
                scanf("%d", &j);
                check(j, stack, 2, status, max);
                push(j, stack, status);
            }
            else if (choice == 3){
                printf("Which stack to pop out of: ");
                scanf("%d", &j);
                check(j, stack, 1, status, max);
                pop(j, stack, status);
            }
            else if (choice == 4){
                printf("Which stack to look at: ");
                scanf("%d", &j);
                check(j, stack, 1, status, max);
                display(j, stack, status);
            }
            else if (choice == 5){
                printf("Which stack to delete: ");
                scanf("%d", &j);
                if (stack[j] >= 1){ //top[j]==NULL should work the same?
                    delete (j, stack);
                }
                else printf("Such stack does not exist\n");
            }
            else if (choice == 6){
                printf("Which stack to check: ");
                scanf("%d", &j);
                printf("1. Empty \n2. Full \nEnter your choice: ");
                scanf("%d", &choice2);
                check(j, stack, choice2, status, max);
                if (status[j] != 0){
                if (choice2 == 1){
                    if (status[j]==-1){
                        printf("Stack is not empty\n");
                    }}
                else if (choice2 == 2){
                    if (status[j]==-2){
                        printf("Stack is not full\n"); 
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
void push(int j, int stack[], int status[]){
    if (status[j] != 0 && status[j] == -2){
    int value;
    Node *new_node;
    printf("Enter value: ");
    scanf("%d", &value);
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL){
        printf("Memory could not be allocated\nFailed to push\n");
    }
    else {
    new_node->data = value;
    new_node->next = top[j];
    top[j] = new_node; //push to the top
    stack[j]++;
    }
    }
}
void pop(int j, int stack[], int status[]){
    if (status[j] != 0 && status[j] == -1){
        printf("%d is out of stack\n", top[j]->data);
        stack[j]--; //dec stack element nr
        Node* temp;
        temp = top[j];
        top[j] = top[j]->next; //previous element is now top
        free(temp);
    }
}
void display(int j, int stack[], int status[]){
    if (status[j] != 0 && status[j] == -1){
            Node* temp = top[j];
            while (temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
            }
    }
}
void check(int j, int stack[], int choice2, int status[], int max[]){
    if (stack[j] < 1){
        printf("Such stack doesn't exist\n");
        status[j] = 0;
    }
    else{
        if (choice2 == 1){
            if (top[j] == NULL){
                printf("Stack is empty\n");
                status[j] = 1;
            }
            else status[j] = -1; //not empty
        }
        else if (choice2 == 2){
            if (stack[j] - 1 >= max[j]){  //-1 since when we create its stack[i] = 1
                printf("Stack is full\n");
                status[j] = 2;
            }
            else status[j] = -2; //not full
        }
    }
}
void delete (int j, int stack[]){
    Node* temp = top[j];
    Node* next = NULL;
    while (temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    stack[j] = 0;
    top[j] = NULL;
}
