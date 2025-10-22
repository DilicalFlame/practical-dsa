#include <stdio.h>
#include <stdlib.h>
#include "../header/CircularDoublyLL.h"

struct CDNode *createCDNode(int val)
{
    struct CDNode *newNode = (struct CDNode *)malloc(sizeof(struct CDNode));
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

void appendCDNode(struct CDNode **head_ref, int data)
{
    struct CDNode *newNode = createCDNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    struct CDNode *last = (*head_ref)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head_ref;
    (*head_ref)->prev = newNode;
}

void prependCDNode(struct CDNode **head_ref, int data)
{
    struct CDNode *newNode = createCDNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    struct CDNode *last = (*head_ref)->prev;
    newNode->next = *head_ref;
    newNode->prev = last;
    last->next = newNode;
    (*head_ref)->prev = newNode;
    *head_ref = newNode;
}

void removeCDNode(struct CDNode **head_ref, int key)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct CDNode *temp = *head_ref;

    // Search for the node to be deleted
    do
    {
        if (temp->data == key)
        {
            // If only one node
            if (temp->next == temp)
            {
                free(temp);
                *head_ref = NULL;
                return;
            }

            // Update pointers
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // If deleting head node
            if (temp == *head_ref)
            {
                *head_ref = temp->next;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head_ref);

    printf("Key %d not found\n", key);
}

void displayCDLL(struct CDNode *node)
{
    if (node == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct CDNode *start = node;
    printf("(HEAD) <-> ");
    do
    {
        printf("%d <-> ", node->data);
        node = node->next;
    } while (node != start);
    printf("(HEAD)\n");
}

void freeCDLL(struct CDNode *head)
{
    if (head == NULL) return;

    struct CDNode *current = head;
    struct CDNode *next;
    struct CDNode *start = head;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != start);
}
