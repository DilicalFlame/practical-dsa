#ifndef LINEAR_SINGLY_LL_H
#define LINEAR_SINGLY_LL_H

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val);
void appendLSNode(struct Node **head_ref, int data);
void prependLSNode(struct Node **head_ref, int data);
void removeLSNode(struct Node **head_ref, int key);
void displayLSLL(struct Node *node);
void freeLSLL(struct Node *head);

#endif // LINEAR_SINGLY_LL_H
