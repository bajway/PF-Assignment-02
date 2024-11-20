/*
Name: Kashif Mehmood
Roll No: 24K-2539
Date: 25/10/24
Desc: Finding the anagrams
*/
#include <stdio.h>
#include<string.h>

int main()
{
int number, k, l;
int ptr=0;

printf("Enter the number of words: ");
scanf("%d",&number);

char arr[number][100];

int increament=0;

for(int i = 0; i < number; i++)
{
	printf("Enter the %d word: ",i+1);
	scanf("%s", &arr[i]);
}
for(int i = number-1; i >= 0; i--)
{
	if(arr[i][0]!=' ')
	{
		int len1 = strlen(arr[i]);
	
		printf("[%s",arr[i]);
		
		for(int j= i-1 ; j >= 0 ;j--)
		{
			int len2 = strlen(arr[i]);

			for(int k = 0; arr[i][k] != '\0'; k++)
			{
				for(int l=0; arr[j][l]!='\0'; l++) 
				if(arr[i][k] == arr[j][l]) 
				break;
				  if(arr[j][l] == '\0')  
				  break;
			}    
		        if(arr[i][ k] == '\0' && len1 == len2)	
				{
		            printf(",%s",arr[j]);
		            
			        while(arr[j][increament] != '\0')
					{
	            		arr[j][increament]=' ';
		            	increament++;
					}
					increament=0;
	            }						             
	    }
	            printf("],");
	}
}
    return 0;
} //End main