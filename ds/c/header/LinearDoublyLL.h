#ifndef LINEAR_DOUBLY_LL_H
#define LINEAR_DOUBLY_LL_H

struct LDNode
{
    int data;
    struct LDNode *next;
    struct LDNode *prev;
};

struct LDNode *createLDNode(int val);
void appendLDNode(struct LDNode **head_ref, int data);
void prependLDNode(struct LDNode **head_ref, int data);
void removeLDNode(struct LDNode **head_ref, int key);
void displayLDLL(struct LDNode *node);
void freeLDLL(struct LDNode *head);

#endif // LINEAR_DOUBLY_LL_H
