#include <stdio.h>
#include <stdlib.h>
#include "../header/LinearDoublyLL.h"

struct LDNode *createLDNode(int val)
{
    struct LDNode *newNode = (struct LDNode *)malloc(sizeof(struct LDNode));
    if (!newNode)
    {
        perror("Out of RAM.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendLDNode(struct LDNode **head_ref, int data)
{
    struct LDNode *newNode = createLDNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    struct LDNode *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void prependLDNode(struct LDNode **head_ref, int data)
{
    struct LDNode *newNode = createLDNode(data);
    newNode->next = *head_ref;
    if (*head_ref != NULL)
    {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

void removeLDNode(struct LDNode **head_ref, int key)
{
    struct LDNode *temp = *head_ref;

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    // If key not present 
    if (temp == NULL)
    {
        printf("Key %d not found\n", key);
        return;
    }

    // If node to be deleted is head node
    if (*head_ref == temp)
    {
        *head_ref = temp->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void displayLDLL(struct LDNode *node)
{
    printf("NULL <-> ");
    while (node != NULL)
    {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeLDLL(struct LDNode *head)
{
    struct LDNode *current = head;
    struct LDNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
