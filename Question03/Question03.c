/*Name: Kashif Mehmood
Roll No: 24K-2539
Date: 25/10/24
Desc: Compressing words*/
#include<stdio.h>
#include<string.h>
void compress(char word[][100], int total_word);
int main(){
    int size_of_word, total_words;
    printf("Enter the number of words: ");
    scanf("%d", &total_words);

    printf("Enter the size of the largest word: ");
    scanf("%d", &size_of_word);
    getchar();
    char word[total_words][size_of_word];
    for (int i = 0; i < total_words; i++)
    {
        printf("Enter %d index word: ",i+1 );
        fgets(word[i], size_of_word + 1, stdin);
        // Remove newline character if present
        word[i][strcspn(word[i], "\n")] = '\0';
    }
    compress(word ,total_words) ;
    return 0;
} //End main
void compress(char word[][100], int total_word){
    int length, count=1;
    int total_reduced_count;
    char compressed_word[total_word][100];

    for(int i = 0; i < total_word; i++)
    {
        length=strlen(word[i]);
        int k = 0, reduced_count=0;
        for(int j = 0; j < length; j++ )
        {
          int count = 1;
            while (j + 1 < length && word[i][j] == word[i][j + 1]) {
                count++;
                j++;
            }
            compressed_word[i][k++] = word[i][j]; 
         if (count > 1) {
                compressed_word[i][k++] = count + '0';  // Convert count to char and store
                reduced_count += (count - 1);  // Count the characters saved
            }
            
        }
            compressed_word[i][k] = '\0';
    }
        for (int i = 0; i < total_word; i++)
        {
            printf("%s\n", compressed_word[i]);
    }
    printf("Number of characters reduced:");
} //End compress
