#include "menu.h"
#include <stdio.h>
int menu(int choice){
printf("\n*********** MENU *************\n");
        printf("1. Create circular list \n2. Display circluar list \n3. Insert element \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        return choice;
}
