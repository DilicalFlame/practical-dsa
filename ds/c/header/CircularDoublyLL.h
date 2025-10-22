#ifndef CIRCULAR_DOUBLY_LL_H
#define CIRCULAR_DOUBLY_LL_H

struct CDNode
{
    int data;
    struct CDNode *next;
    struct CDNode *prev;
};

struct CDNode *createCDNode(int val);
void appendCDNode(struct CDNode **head_ref, int data);
void prependCDNode(struct CDNode **head_ref, int data);
void removeCDNode(struct CDNode **head_ref, int key);
void displayCDLL(struct CDNode *node);
void freeCDLL(struct CDNode *head);

#endif // CIRCULAR_DOUBLY_LL_H
