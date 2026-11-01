#ifndef _SingleLink_
#define _SingleLink_
typedef struct node
{
    int number;
    struct node *next_node;
} Node;
Node *addatendlist(Node *first, int NUM);
Node *Search_Target(Node *first , int target_number);
Node *Traverse_Chain(Node *first);
Node *deleteNode(Node *first,Node *Target);
Node *insertBefortTarget(Node *first , Node *Target);
#endif