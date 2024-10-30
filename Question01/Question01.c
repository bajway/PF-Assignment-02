/*
Name: Kashif Mehmood
Roll No: 24K-2539
Date: 25/10/24
Desc: Finding the second smallest number in the array
*/
#include<stdio.h>
int main() {
    int num[5], i, j; //Declaring variables
    
    //Input elements
    for (i = 0; i < 5; i++) {
        do {
            printf("Enter the %d element **should be less than 10000**: ", i + 1);
            scanf("%d", &num[i]);
            if (num[i] > 9999) //Applying condition for number 
            {
                printf("Error: Please enter a value less than or equal to 9999.\n");
            } //End if
        } //End do
         while (num[i] > 9999);
    } //End for
    //Bubble sorting in descending oder
    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (num[j] < num[j + 1]) //For descending order
            { 
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            } //End if
        }//End for
    }
    // Printing sorted array
    printf("Sorted array (in descending order): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", num[i]);
    } //End for
    printf("\nSecond smallest element in the array: %d", num[3]);
    return 0;
}//End main
