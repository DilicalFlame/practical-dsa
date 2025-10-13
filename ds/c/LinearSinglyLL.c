#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void append(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    struct Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a node at the beginning of the list
void prepend(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to delete a node with a specific value
void removeNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
