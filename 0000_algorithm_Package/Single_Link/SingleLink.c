#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "SingleLink.h"
// typedef struct node
// {
//     int number;
//     struct node *next_node;
// } Node;
Node *addatendlist(Node *first,int NUM ) //��C�إߨ�� 
{
	Node *current;//=(Node *)malloc(sizeof(Node));
	Node *NewNode=(Node *)malloc(sizeof(Node));//�إ߷s�`�I
	NewNode->next_node=NULL;
    NewNode->number=NUM;
    //NewNode->next_node=NULL;
  
	if(first==NULL)
	{ 
		first=NewNode;
		
		return first;
	}
	  else
	  {  
		   current=first;
		   while(current->next_node!=NULL)
		   {
			   current=current->next_node;
			   }
			   
		      current->next_node=NewNode;    
		  
		  }
	return first;
  }


Node *insertBefortTarget(Node *first , Node *Target) //��C�إߨ�� 
{
	 int Number=0;
	 Node *NewNode=(Node *)malloc(sizeof(Node));
	 Node *current=first;
	 printf("Please Enter the Number\n");
	 scanf("%d",&Number);
	 NewNode->number=Number;
	if(first==NULL && Target==NULL)
	{
		return NULL;
		}
		while(current->next_node!=Target)
		{
			current=current->next_node;
			}
	 	
		 current->next_node=NewNode;
		 NewNode->next_node=Target;
		return first; 
	}

//--------------------------------------------------------------------//
Node *Traverse_Chain(Node *first)
{
	  Node *node=first;
	  int counter=0;
	   while(node!=NULL)
	   {
		  printf("......Linker[%d]==%d\n", counter,node->number);
		  node=node->next_node;
		  counter++;
		}
		return first;
	}
	
Node *Search_Target(Node *first , int target_number)
{
	Node *target=first;

	while(target->next_node!=NULL)
	{
		 if((target->number==target_number))
		 {
			 printf("find the target\n");
			 return target;   
		 }
        target=target->next_node;
	}
//		 printf("Cant't  Find the target (Target_Aim)....\n");
//		 assert((target==NULL));
	return target;
	}

Node *deleteNode(Node *first,Node *Target)
{
	Node *ptr=first;
	// ���ݬO���O�̫�@��//
	if(Target->next_node==NULL)
	{
		while(ptr->next_node!=Target)
		{
			ptr=ptr->next_node;
			
		}
		free(Target);
		ptr->next_node=NULL;
		return first;
		}
		
		
	if(first==NULL) 
	 { //�p�G��C�O�Ū��A�h�L�XNothing to delete! */ 
		printf("Nothing to delete!\n");
		return NULL;
	 } 
	 if(Target==first)
	   {  //�p�G�R�����O�Ĥ@�Ӹ`�I 
		 first=first->next_node;//��first���V�U�@�Ӹ`�I(NULL) 
	   }
	  else
	  {
		while(ptr->next_node!=Target)
		{ //���n�R�����`�I���e�@�Ӹ`�I 
			ptr=ptr->next_node;
		}
		ptr->next_node=Target->next_node; //���s�]�wptr��next���� 
	  }
	  free(Target);
	  
	  return first;
}