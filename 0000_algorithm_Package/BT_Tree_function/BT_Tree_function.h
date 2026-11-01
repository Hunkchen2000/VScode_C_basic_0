struct Node
{
 int data;	
 //char name[10];
 struct Node *left_child;
 struct Node *right_child;
};
typedef struct Node node;
typedef node *BT;

BT search(BT ptr, int x);
BT search_father(BT ptr, int X);
BT bst_insert(BT p, int x);
void inorderLDR(BT node_head);
void inorderDLR(BT node_head);
void inorderLRD(BT node_head);
BT GetNode();
BT deleteNode(BT node_head);
int Rand(int X,int Y);//•Õ¶®?…Û?;
void show_f(BT node_head);
BT deleteNode2(BT node_head, int value);
