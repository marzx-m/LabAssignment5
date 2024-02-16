/*
Mariam Befekadu
Lab Assignment 4
COP 3502 
02/08/24
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

//Returns the number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


//If the linked list is head -> |a|->|b|->|c|, then toCString function will return "abc".
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));

    int i = 0;
    while (head != NULL) {
        str[i++] = head->letter;
        head = head->next;
    }
    str[i] = '\0';
    return str;
}

//Inserts character to the linkedlist.
//If the linked list is head -> |a|->|b|->|c|, then insertChar(&head, 'x') will update the linked list as follows:
//head -> |a|->|b|->|c|->|x|.
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//Deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    while (*pHead != NULL) {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    if (inFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    fscanf(inFile, " %d", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is: %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!\n");
            break;
        }
    }
    fclose(inFile);

    return 0;
}
