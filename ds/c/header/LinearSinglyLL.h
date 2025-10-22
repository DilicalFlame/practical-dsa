#ifndef LINEAR_SINGLY_LL_H
#define LINEAR_SINGLY_LL_H

struct LSNode
{
    int data;
    struct LSNode *next;
};

struct LSNode *createLSNode(int val);
void appendLSNode(struct LSNode **head_ref, int data);
void prependLSNode(struct LSNode **head_ref, int data);
void removeLSNode(struct LSNode **head_ref, int key);
void displayLSLL(struct LSNode *node);
void freeLSLL(struct LSNode *head);

#endif // LINEAR_SINGLY_LL_H
