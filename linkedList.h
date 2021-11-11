#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
        char data[40];
        int occurance;
        struct node* next;
};

void push(struct node** head_ref, char* new_data, int i);
void printList(struct node *head);
int listCount(struct node *head);
void sortLinkedList(struct node** currP);
void sortByOccurance(struct node** currP);
void swapData(struct node* nOne, struct node* nTwo);
bool contains(struct node *head, char *word);
void listToArray(struct node *head, char* strings[]);
void updateOccurance(struct node *head, char *word);

struct node* sortedMerge(struct node* x, struct node* y);
void split(struct node* head, struct node** front, struct node** back);
void mergeSort(struct node** head);

struct node* sortedMergeOccurance(struct node* x, struct node* y);
void mergeSortOccurance(struct node** head);