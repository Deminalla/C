// Input integer N. Then input N*N integers which will create a table. Find the smallest and largest numbers in each row of the table
// Print out the coordinates of these numbers (row, column) and the nubmers themselves
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isspace                                                                                                                                                                                            //for isspace
void validation(int row, int column, int N, int number[][N + 1], int decimals[]);                                                                                                                             // to check wehter input is a decimal or not
void position_max_min(int row, int column, int N, int number[][N + 1], int column_max[][N + 1], int column_min[][N + 1], int maximum[], int minimum[]);                                                       // find in which column the max and min are positioned
void search_of_repetition(int i, int j, int N, int multiple_max, int multiple_min, int column_max[][N + 1], int column_min[][N + 1], int row, int column, int maximum[], int minimum[], int number[][N + 1]); // to see if man min were repeated in the line, if so, find the columns
void output(int row, int N, int maximum[], int minimum[], int i, int column_max[][N + 1], int column_min[][N + 1]);
int main()
{
    int N;

    printf("Input the size of the table: "); // N*N
    scanf("%d", N);
    int number[N + 1][N + 1];
    int decimals[N + 1]; // the number of decimals in a row
    int row, column;
    int minimum[N + 1], maximum[N + 1];                     // max and min in every line
    int column_max[N + 1][N + 1], column_min[N + 1][N + 1]; // the columns of max min in each row
    int multiple_max, multiple_min;                         // to check if theres more than 1 max min in each line
    int i, j;
    printf("Input %d rows, which will have %d decimals:\n", N, N);
    for (row = 1; row <= N; row++)
    {
        validation(row, column, N, number, decimals);
        if (decimals[row] < N)
        {
            printf("Wrong data, please input the whole line again: ");
            row--; // so we can input the same row again
        }
        else
            position_max_min(row, column, N, number, column_max, column_min, maximum, minimum);
    }
    search_of_repetition(i, j, N, multiple_max, multiple_min, column_max, column_min, row, column, maximum, minimum, number);
    output(row, N, maximum, minimum, i, column_max, column_min);
    return 0;
}
void validation(int row, int column, int N, int number[][N + 1], int decimals[])
{
    decimals[row] = 0;
    for (column = 1; column <= N; column++)
    {
        if (scanf("%d", &number[row][column]) == 1 && isspace(getchar()))
        {
            decimals[row]++;
        }
        else
            while (!isspace(getchar())); // read (get rid of) the symbols until it reaches a non-white symbol
    }
}
void position_max_min(int row, int column, int N, int number[][N + 1], int column_max[][N + 1], int column_min[][N + 1], int maximum[], int minimum[])
{
    for (column = 1; column <= N; column++) // we equate the largest & smallest numbers to the first input in its row, so we have something to compare it to later on
    {
        if (column == 1)
        {
            maximum[row] = number[row][column];
            minimum[row] = number[row][column];
            column_max[row][0] = column;
            column_min[row][0] = column;
        }
        else if (number[row][column] > maximum[row])
        {
            maximum[row] = number[row][column];
            column_max[row][0] = column;
        }
        else if (number[row][column] < minimum[row])
        {
            minimum[row] = number[row][column];
            column_min[row][0] = column;
        }
    }
}
void search_of_repetition(int i, int j, int N, int multiple_max, int multiple_min, int column_max[][N + 1], int column_min[][N + 1], int row, int column, int maximum[], int minimum[], int number[][N + 1])
{
    for (row = 1; row <= N; row++)
    {
        i = 1; // for startes 1 because there will automatically be at least 1 max min so we have to check if there are more than that
        j = 1;
        multiple_max = 0;
        multiple_min = 0;
        column_max[row][i] = 0;
        column_min[row][j] = 0;
        for (column = 1; column <= N; column++)
        {
            if (maximum[row] == number[row][column])
            {
                multiple_max++;
            }
            if (minimum[row] == number[row][column])
            {
                multiple_min++;
            }
            if (multiple_max > i)
            {
                column_max[row][i] = column; // we save the position in i-th place
                i++;
                column_max[row][i] = 0; // because in the output while cycle it will go until it reaches 0
            }
            if (multiple_min > j)
            {
                column_min[row][j] = column;
                j++;
                column_min[row][j] = 0;
            }
        }
    }
}
void output(int row, int N, int maximum[], int minimum[], int i, int column_max[][N + 1], int column_min[][N + 1])
{
    for (row = 1; row <= N; row++)
    {
        if (maximum[row] == minimum[row])
        {
            printf("%d row has no maximum or minimum decimal because all the inserted numbers were the same\n", row);
        }
        else
        {
            printf("%d row's largest number is %d positioned in %d", row, maximum[row], column_max[row][0]);
            i = 1;
            while (column_max[row][i])
            {
                printf(", %d", column_max[row][i]);
                i++;
            }
            printf(" column and the smallest is %d positioned in %d", minimum[row], column_min[row][0]);
            i = 1;
            while (column_min[row][i])
            {
                printf(", %d", column_min[row][i]);
                i++;
            }
            printf(" column\n");
        }
    }
}
