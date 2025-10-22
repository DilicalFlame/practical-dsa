#include <stdio.h>
#include <stdlib.h>
#include "../header/LinearSinglyLL.h"

struct LSNode *createLSNode(int val)
{
    struct LSNode *newNode = (struct LSNode *)malloc(sizeof(struct LSNode));
    if (!newNode)
    {
        perror("Out of RAM.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void appendLSNode(struct LSNode **head_ref, int data)
{
    struct LSNode *newNode = createLSNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    struct LSNode *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void prependLSNode(struct LSNode **head_ref, int data)
{
    struct LSNode *newNode = createLSNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to remove a node with a specific key
void removeLSNode(struct LSNode **head_ref, int key)
{
    struct LSNode *temp = *head_ref, *prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
    {
        printf("Key %d not found\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayLSLL(struct LSNode *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeLSLL(struct LSNode *head)
{
    struct LSNode *current = head;
    struct LSNode *next;

    while (current != NULL)
    {
        next = current->next; // Store next node
        free(current);        // Free current node
        current = next;       // Move to next node
    }
}