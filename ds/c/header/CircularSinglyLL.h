#ifndef CIRCULAR_SINGLY_LL_H
#define CIRCULAR_SINGLY_LL_H

struct CSNode
{
    int data;
    struct CSNode *next;
};

struct CSNode *createCSNode(int val);
void appendCSNode(struct CSNode **head_ref, int data);
void prependCSNode(struct CSNode **head_ref, int data);
void removeCSNode(struct CSNode **head_ref, int key);
void displayCSLL(struct CSNode *node);
void freeCSLL(struct CSNode *head);

#endif // CIRCULAR_SINGLY_LL_H
