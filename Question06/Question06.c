/*
Name: Kashif Mehmood
Roll No: 24K-2539
Date: 25/10/24
Desc: Matchstick game
*/
#include<stdio.h>
int probabilty(int number);
int main(){
    int stk;
    printf("Enter the number of match sticks: ");
    scanf("%d", &stk);
    int choice = probabilty(stk); // function call
    if (choice==-1)
        printf("It is not possible for A to win");
    else
    printf("Player A should pick %d sticks for winning", choice);
    return 0;
}// End main

int probabilty(int number){
    if (number%5==0)
        return -1;

    if (number%5!=0)
        return number % 5;
    
} //End function