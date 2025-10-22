#include <stdio.h>
#include <stdlib.h>
#include "../header/CircularSinglyLL.h"

struct CSNode *createCSNode(int val)
{
    struct CSNode *newNode = (struct CSNode *)malloc(sizeof(struct CSNode));
    if (!newNode)
    {
        perror("Out of RAM.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// implementation: Insert after head, swap data, then move head forward
void appendCSNode(struct CSNode **head_ref, int data)
{
    struct CSNode *newNode = createCSNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }
    // Insert new node after head
    newNode->next = (*head_ref)->next;
    (*head_ref)->next = newNode;
    
    // Swap data between head and new node
    int temp = (*head_ref)->data;
    (*head_ref)->data = newNode->data;
    newNode->data = temp;
    
    // Move head forward to new node (which now has old head's data)
    *head_ref = newNode;
}

// implementation: Insert after head and swap data
void prependCSNode(struct CSNode **head_ref, int data)
{
    struct CSNode *newNode = createCSNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }
    // Insert new node after head
    newNode->next = (*head_ref)->next;
    (*head_ref)->next = newNode;
    
    // Swap data between head and new node
    int temp = (*head_ref)->data;
    (*head_ref)->data = newNode->data;
    newNode->data = temp;
}

void removeCSNode(struct CSNode **head_ref, int key)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct CSNode *temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp->data == key)
    {
        // If only one node
        if (temp->next == *head_ref)
        {
            free(temp);
            *head_ref = NULL;
            return;
        }

        // Find last node
        struct CSNode *last = *head_ref;
        while (last->next != *head_ref)
        {
            last = last->next;
        }
        last->next = temp->next;
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    prev = temp;
    temp = temp->next;
    while (temp != *head_ref && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == *head_ref)
    {
        printf("Key %d not found\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

void displayCSLL(struct CSNode *node)
{
    if (node == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct CSNode *start = node;
    do
    {
        printf("%d -> ", node->data);
        node = node->next;
    } while (node != start);
    printf("(HEAD)\n");
}

void freeCSLL(struct CSNode *head)
{
    if (head == NULL)
        return;

    struct CSNode *current = head;
    struct CSNode *next;
    struct CSNode *start = head;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != start);
}
