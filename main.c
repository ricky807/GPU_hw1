#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include <stdbool.h>
#include <ctype.h>

struct node * extractOneLine(struct node *head, char *aline)
{
    int inWord = 0;
    //my word list
    int i = 0;
    int start = 0;
    int wordLen = 0;      
    while(aline[i] != '\n' && aline[i] != '\0')
    {   
        if(isalpha(aline[i]))
        {
            if(inWord == 0)
            {
                start = i;
                inWord = 1;
            }
            wordLen++;
        }
        else if(inWord == 1)
        {
            char newWord[100];
            //substring(newWord, aline, start, i);
            strncpy(newWord, (aline + start), wordLen);
            newWord[wordLen] = '\0';
            
            wordLen = 0;
            inWord = 0;
            

            
            if(wordLen != 1 || newWord[0] == 'A' || newWord[0] == 'I' || newWord[0] == 'a' || newWord[0] == 'i')
            {
                if(!contains(head, newWord))
                {
                    push(&head, newWord, 1);
                }
                else
                {
                    updateOccurance(head, newWord);
                }
            }

            
            
        }
        i++;
    }
    
    char newWord[100];
    //substring(newWord, aline, start, i);
    strncpy(newWord, (aline + start), wordLen);
    newWord[wordLen] = '\0';
    if(newWord[0] == '\0')
    {
        return head;
    }
    
    wordLen = 0;
    inWord = 0;
    
    if(wordLen != 1 || newWord[0] == 'A' || newWord[0] == 'I' || newWord[0] == 'a' || newWord[0] == 'i')
    {
        if(!contains(head, newWord))
        {
            push(&head, newWord, 1);
        }
        else
        {
            updateOccurance(head, newWord);
        }
    }
    
    return head;
    
}
void createOutput(struct node *head, FILE * output)
{
    if(output == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    struct node *temp = head;
           fputs("|----------------|-----------|\n", output);
    while (temp != NULL)
    {
            fprintf(output, "|%-16s", temp->data);
            fputs("|", output);
            fprintf(output, "%-11d|\n", temp->occurance);
            fputs("|----------------|-----------|\n", output);
            temp = temp->next;
    }
    fclose(output);
}
int main( int argc, char* argv[] )
{
    
    if (argc < 2)
    {
        printf("Usage: prime upbound\n");
        exit(-1);
    }
    FILE *file = fopen(argv[1], "r");
    int c;
    char *aline = NULL;
    size_t len = 0;
    struct node* head = NULL;
    
    while(getline(&aline, &len, file) != -1)
    {   
    	head = extractOneLine(head, aline);
        
    }
    //time to get the files
    mergeSort(&head);
    FILE * alpha = fopen("sortedWord.txt", "w");
    createOutput(head, alpha);

    mergeSortOccurance(&head);
    FILE * occurance = fopen("sortedOccur.txt", "w");
    createOutput(head, occurance); 
    free(head);
}
