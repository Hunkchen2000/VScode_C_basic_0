#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <time.h>
#include "BT_Tree_function.h"
//-------------------------Search-----------------------------//
BT search(BT ptr, int x)
{
 BT temp;
    temp=ptr;   
 if(ptr==NULL)
  return NULL; 
 
      if(x< temp->data)
	  {
            return search(temp->left_child,x);
	  }
   else if(x> temp->data){
          return search(temp->right_child,x);
     }
      return temp;     
}

BT search2(BT ptr, int x)
{
	BT temp;
    temp=ptr; 
	
	while(temp!=NULL)
		{
		if (temp->data==x)
			{
			return temp;           /*若找到目標，則回傳此節點*/
		 }
		else if (temp->data>x)
			{
			temp = temp->left_child;  /*若目標比此節點之data小，則向左移動*/
		}
		else
			{
			temp = temp->right_child;/*若目標比此節點之data大，則向右移動*/
		}
	}
	printf("\n can't find x\n");
	return NULL;//找不到/./.
}

BT search_father(BT ptr, int X)
{
 BT parent;
 parent = ptr; // 從ptr開始找
 while(ptr != NULL) 
 {
  if(ptr->data == X) // 找到目標
   return parent;  // 回傳此節點之父節點
  else
  {
     parent=ptr;
     if(ptr->data>X)
      { // ptr在parent左子樹
          ptr = ptr->left_child; // 往左找
      }
      else
      {
           ptr=ptr->right_child;   
      }
     }
 }
 return NULL; // 找不到
}
//=============================================================//
BT bst_insert(BT p, int x)
 {
     BT newnode;
  if(p==NULL)
  {
   newnode=(node*)malloc(sizeof(node));
   newnode->left_child=NULL;
   newnode->right_child=NULL;
   newnode->data=x;
   return newnode;
  }
  if(x<p->data)
                p->left_child=bst_insert(p->left_child,x);
                else if(x > p->data)
                p->right_child=bst_insert(p->right_child,x);
  else if(x==p->data)
  {
                p->right_child=bst_insert(p->right_child,x);
  }
 return p;
  }
 
//-------------------------LDR--------------------------------//
void inorderLDR(BT node_head)//中序走訪
{ 
		
 if(node_head!=NULL)
 {
  inorderLDR(node_head->left_child);
  printf("%5d",node_head->data);
  inorderLDR(node_head->right_child); 
 }
} 

//--------------------------DLR-------------------------------//
void inorderDLR(BT node_head)////前序走訪
{
 if(node_head!=NULL)
 {
  printf("%5d",node_head->data);
  inorderDLR(node_head->left_child);
  inorderDLR(node_head->right_child); 
 }
}
//---------------------------LRD------------------------------//

void inorderLRD(BT node_head)  //後序走訪
{
 if(node_head!=NULL)
 {
	 
     inorderLRD(node_head->left_child);
     inorderLRD(node_head->right_child);
     printf("%5d",node_head->data);
 }
}
//---------------------------------------------------------//


BT GetNode()
{
 BT NewNode;
 NewNode=(BT)malloc(sizeof(node));
 if(NewNode==NULL)
 {
  printf("Memory is not enought\n");
     exit(1);
 }
 return NewNode;
}
//-----------------------------------------------------------//
BT deleteNode(BT node_head)
{

 int Bekilled;
 int status1=1;
 printf("Please Enter the number \n\n");
 while((status1=scanf("%d",&Bekilled))!=1 ||(Bekilled<1 || Bekilled>1000) ||(search(node_head,Bekilled)==NULL))
 {
         if(status1!=1)
    scanf("%*s"); 
     printf("Please Enter again\n");  
 }
 printf("\n\n\n");
 BT father=search_father(node_head,Bekilled);
 BT ptrX=search(node_head,Bekilled);
 BT next;

    if((ptrX->left_child==NULL) && (ptrX->right_child!=NULL))
 {
   if(father->data>ptrX->data)
    father->left_child=ptrX->right_child;
   else if(father->data<ptrX->data)
	father->right_child=ptrX->right_child;
	else
	 {
		 node_head=node_head->right_child;
	 }
   free(ptrX);    
 }
 
  else if((ptrX->right_child==NULL) && (ptrX->left_child!=NULL))
 {
	 // printf("ptrX->data %d\n", ptrX->data);
	 // printf("ptrX->data %d\n", father->data);
	 // printf("ptrX->data %d\n", node_head->data);
     if(father->data>ptrX->data)
         father->left_child=ptrX->left_child;
    else if (father->data<ptrX->data)
         father->right_child=ptrX->left_child;
	 else
	 {
		 node_head=node_head->left_child;
	 }
	// printf("ptrX->data %d\n", node_head->data);
   free(ptrX);   
   //return node_head;
 }
 
 else if((ptrX->right_child==NULL)&&(ptrX->left_child==NULL))
 {
	 
  if(father->data>ptrX->data)
     father->left_child=NULL;
   else
         father->right_child=NULL;
   free(ptrX);  
  
 }
 else if((ptrX->right_child!=NULL)&&(ptrX->left_child!=NULL))
 {
  father=ptrX;
  next=ptrX->left_child;   // Ptrx=Want_delete

  while(next->right_child!=NULL)
  {
   father=next;
   next=next->right_child;
  }
  //printf("Next->value is %d\n", next->data);
      ptrX->data=next->data;
   //father->right_child=next->left_child;
   if(father!=ptrX)
   {
    father->right_child=next->left_child;
   }
   else
   {
    father->left_child=next->left_child;
   }
  free(next);
    }   
	return node_head;
}
//=========================RANDOM===============================//
int Rand(int X,int Y)//生成?机?
{
    int temp;
	int R=0;
    if(X>Y)
    { 
        temp=X;
        X=Y;
        Y=temp;
    }
	R=rand()%(Y-X+1)+X;
	//printf("%d\n",R);
    return R;
}
void show_f(BT node_head)
{
	if(node_head->data>=10000)  /* 判斷根節點是否為NULL */
	{
		//puts("No student record!");
		 printf("No student record!\n");
		return;
	}
	puts("=====SHOW DATA=====");
	inorderLDR(node_head);  /* 以中序法輸出資料 */
}
	
BT deleteNode2(BT node_head, int value)
{
 int Bekilled=value;
 BT father=search_father(node_head,Bekilled);
 BT ptrX=search(node_head,Bekilled);//找出要砍的節點//
 BT next;
	if(node_head==NULL)
	{
		return 0;
		}
		
    if((ptrX->left_child==NULL) && (ptrX->right_child!=NULL))
 {
   if(father->data>ptrX->data)
    father->left_child=ptrX->right_child;
   else if(father->data<=ptrX->data)
	father->right_child=ptrX->right_child;
	else
	 {
		 node_head=node_head->right_child;
	 }
   free(ptrX);    
 }
 
  else if((ptrX->right_child==NULL) && (ptrX->left_child!=NULL))
 {
	 // printf("ptrX->data %d\n", ptrX->data);
	 // printf("ptrX->data %d\n", father->data);
	 // printf("ptrX->data %d\n", node_head->data);
     if(father->data>ptrX->data)
         father->left_child=ptrX->left_child;
    else if (father->data<=ptrX->data)
         father->right_child=ptrX->left_child;
	 else
	 {
		 node_head=node_head->left_child;
	 }
	// printf("ptrX->data %d\n", node_head->data);
   free(ptrX);   
   //return node_head;
 }
 
 else if((ptrX->right_child==NULL)&&(ptrX->left_child==NULL))
 {
	 
  if(father->data>ptrX->data)
     father->left_child=NULL;
   else
         father->right_child=NULL;
   free(ptrX);  
  
 }
 else if((ptrX->right_child!=NULL)&&(ptrX->left_child!=NULL))
 {
  father=ptrX;
  next=ptrX->left_child;   // Ptrx=Want_delete
  while(next->right_child!=NULL)
  {
   father=next;
   next=next->right_child;
  } 
      ptrX->data=next->data;
   if(father!=ptrX)
   {
    father->right_child=next->left_child;
   }
   else
   {
    father->left_child=next->left_child;
   }
  free(next);
    }   
	return node_head;
}
