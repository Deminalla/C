//Input integer N. Then input N*N integers which will create a table. Find the smallest and largest numbers in each row of the table 
//Print out the coordinates of these numbers (row, column) and the nubmers themselves

#include <stdio.h>
#include <ctype.h>
void position_max_min (int row, int column, int N, int numbers[][N+1], int column_maxmin[N+1][2], int maximum[], int minimum[], int integers[]);
int main()
{
    int N;
    printf("The size of the table you would like: ");
    scanf("%d", &N);
    int numbers[N+1][N+1];
    int row, column; 
    int integers[N+1]; //how many integers there are in each row
    int column_maxmin[N+1][2]; //N-row size, the second box is to that we can put the largest number in 0th position, and the smallest in 1st place
    int minimum[N+1], maximum[N+1]; //max and min in every line
    for (row=1; row<=N; row++){
        integers[row] = 0;
        for(column=1; column<=N; column++){
        if(scanf("%d", &numbers[row][column])==1  && isspace(getchar())){  //scans until it finds a white-space 
        position_max_min (row, column, N, numbers, column_maxmin, maximum, minimum, integers); //go to a function
        }
           else while(!isspace(getchar())); //read (get rid of) the symbols until it reaches a non-white symbol
        }
    }
    for (row=1; row<=N; row++){
        if (integers[row] == 0){
            printf("No integers were inserted for the %d row\n", row);
        }
        else if (maximum[row]==minimum[row]){
        printf("The biggest and smallest of %d row are both %d, since ", row, maximum[row]);  
        if (integers[row] == 1){
            printf("only 1 integer was inserted\n");
        }     
        else printf("all the inserted integers were the same\n");
        }
        else printf("The biggest inetger of %d row is %d which is positioned in %d column and the smallest integer is %d positioned in %d column\n", row, maximum[row], column_maxmin[row][0], minimum[row], column_maxmin[row][1]);
    }
    return 0;
}
void position_max_min (int row, int column, int N, int numbers[][N+1], int column_maxmin[N+1][2], int maximum[], int minimum[], int integers[]){
    if (integers[row] == 0){ //we equate the largest & smallest numbers to the input if it was the first inserted in its row, so we have something to compare it to later on
        maximum[row]=numbers[row][column];
        minimum[row]=numbers[row][column];
        column_maxmin[row][0]=column;
        column_maxmin[row][1]=column;
    }
    else if (numbers[row][column] > maximum[row]){
        maximum[row]=numbers[row][column];
        column_maxmin[row][0]=column;
    }
    else if (numbers[row][column] < minimum[row]){
        minimum[row]=numbers[row][column];
        column_maxmin[row][1]=column;
    }
    integers[row]++;
}
