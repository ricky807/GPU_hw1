#include "linkedList.h"
/* Link list node */

/* Function to push a node */
void push(struct node** head, char* new_data, int i)
{
        struct node* new_node = malloc(sizeof(struct node));
        strcpy(new_node->data, new_data);
		new_node->occurance = 1;
        new_node->next = (*head);
        (*head) = new_node;
}

void printList(struct node *head)
{
        struct node *temp = head;
        while (temp != NULL)
        {
                printf("%s , %d\n", temp->data, temp->occurance);
                temp = temp->next;
        }
}
void listToArray(struct node *head, char* strings[])
{
        struct node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
                strcpy(strings[i], temp->data);
                printf("%s \n", strings[i]);
                temp = temp->next;
                i++;
        }
}

bool contains(struct node *head, char *word)
{
        struct node *temp = head;
        while (temp != NULL)
        {
			if(strcasecmp(temp->data, word)==0)
			{
            	return true;
			}
            temp = temp->next;
        }
		return false;
}
void updateOccurance(struct node *head, char *word)
{
        struct node *temp = head;
        while (temp != NULL)
        {
			if(strcasecmp(temp->data, word)==0)
			{
            	temp->occurance++;
			}
            temp = temp->next;
        }
}

int listCount(struct node *head){
	int count = 0;
	struct node* temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void swapData(struct node* nOne, struct node* nTwo){
	char temp[BUFSIZ];
	strcpy(temp,nOne->data);
	strcpy(nOne->data,nTwo->data);
	strcpy(nTwo->data,temp);

	//this is for int
	int tem = nOne->occurance;
	nOne->occurance = nTwo->occurance;
	nTwo->occurance = tem;
}

struct node* sortedMerge(struct node* x, struct node* y)
{
    if (x == NULL) {
        return y;
    }
 
    else if (y == NULL) {
        return x;
    }
 
    struct node* res = NULL;

    if (strcasecmp(x->data, y->data) < 0)
    {
    	res = x;
    	res->next = sortedMerge(x->next, y);
    }
    else {
    	res = y;
    	res->next = sortedMerge(x, y->next);
    }
 
    return	res;
}
 
void split(struct node* head, struct node** front, struct node** back)
{
    if (head == NULL || head->next == NULL)
    {
        *front = head;
        *back = NULL;
        return;
    }
 
    struct node* prev = head;
    struct node* temp = head->next;
 
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp != NULL)
        {
            prev = prev->next;
            temp = temp->next;
        }
    }
 
    *front = head;
    *back = prev->next;
    prev->next = NULL;
}

void mergeSort(struct node** head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    struct node* x;
    struct node* y;
 
    split(*head, &x, &y);
 
    mergeSort(&x);
    mergeSort(&y);
 
    *head = sortedMerge(x, y);
}



struct node* sortedMergeOccurance(struct node* x, struct node* y)
{
    if (x == NULL) {
        return y;
    }
 
    else if (y == NULL) {
        return x;
    }
 
    struct node* res = NULL;

    if (x->occurance > y->occurance)
    {
    	res = x;
    	res->next = sortedMergeOccurance(x->next, y);
    }
    else {
    	res = y;
    	res->next = sortedMergeOccurance(x, y->next);
    }
 
    return	res;
}
 
void mergeSortOccurance(struct node** head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    struct node* x;
    struct node* y;
 
    split(*head, &x, &y);
 
    mergeSortOccurance(&x);
    mergeSortOccurance(&y);
 
    *head = sortedMergeOccurance(x, y);
}