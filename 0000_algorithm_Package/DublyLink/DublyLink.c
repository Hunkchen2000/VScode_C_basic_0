#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DublyLink.h"

// struct dlist                      /* ���V��C���c�ŧi   */
// {
//    int data;                      /* �`�I���           */
// //   struct dlist *next;           /* ���V�U�@�`�I������ */
// //   struct dlist *prev;            /* ���V�e�@�`�I������ */
//     struct dlist *next;           /* ���V�U�@�`�I������ */
//     struct dlist *prev;            /* ���V�e�@�`�I������ */
// };
// typedef struct dlist dnode;       /* ���V��C�s���A     */
// typedef dnode *dlink;             /* ���V��C���зs���A */
// /* �ϥΰ}�C�ȫإ����V�쵲��C */
// /* ���V�쵲��C����� */
void printdlist(dlink head,dlink now)
{
	//system("cls");
   while ( head != NULL )         /* ��C���X�j��       */
   {
      if ( head == now )          /* ��ܥثe�`�I���   */
         printf("-[%d]",head->data);  /* ��ܸ`�I���    */
      else
         printf("-[%d]",head->data);  /* ��ܸ`�I���    */
      head = head->next;         /* ���V�U�@�Ӹ`�I     */
   }
   //printf("\n");                  /* ����               */
}
dlink createdlist(int *array,int len)
{
   dlink head;                    /* ���V��C������     */
   dlink before;                  /* �e�@�`�I������     */
   dlink new_node;                /* �s�`�I������       */
   //dlink current; 
   int i;
   /* �إ߲Ĥ@�Ӹ`�I, �M�t�m�`�I�O���� */
   head = ( dlink ) malloc(sizeof(dnode));
   if ( head==NULL )
   { 
	   return NULL;      /* �ˬd�O�������     */
   }
   head->data = array[0];         /* �إ߸`�I���e       */
   head->next = NULL;            /* �]�w���Ъ��       */
   head->prev = NULL;             /* �]�w���Ъ��       */
   before = head;
   //current=before->next;                 /* ���V�Ĥ@�Ӹ`�I     */
  //int list[10] = {75,98,77,10,57,50,40,81,91,99};   /* �}�C���e    */
    
   for ( i = 1; i < len; i++ )    /* �ΰj��إߨ䥦�`�I */
   {  /* �t�m�`�I�O���� */
      new_node = ( dlink ) malloc(sizeof(dnode));
      new_node->data = array[i];  /* �إ߸`�I���e       */
      new_node->next = NULL;     /* �]�w���Ъ��       */
      new_node->prev = before;    /* �N�s�`�I���V�e�`�I */
      before->next = new_node;   /* �N�e�`�I���V�s�`�I */
	  before = new_node;          /* �s�`�I�����e�`�I   */

   }
   return new_node;                   /* �Ǧ^��C�_�l����   */
}
//----------------------------------------------------------------------//
dlink createdlist2(dlink head,int value)
{
    dlink current= malloc(sizeof(*current));
    dlink new_node= malloc(sizeof(*new_node));   
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = value;
     if (new_node == NULL) {
        return NULL;   // �γB�z���~
    }
   if(head==NULL)
 	{
		head=new_node;
        return head;
	}
	else
	{ 
		current=head;
		while((current->next)!=NULL)
		{ 
			current=current->next;
		}
		 current->next=new_node;
       new_node->prev=current;
       new_node->next=NULL;
	}
  	
	//  new_node = ( dlink ) malloc(sizeof(dnode));
    //  new_node->data =value;  
    //  new_node->next = NULL;     
    //  new_node->prev = before;    
    //  before->next = new_node;   
	//  before = new_node;         
  
  return head;
  
}
/*  �ϥΫ��Ы��V�Q�n�䪺�ؼ�    */
dlink Search_Target(dlink head , int target_number)
{
   dlink target=head;
   while(target->next!=NULL)
   {
       if((target->data==target_number))
       {
          return target;
       }
       else
       {
          target=target->next;
       }

   }
     if((target->next==NULL)&&(target->data!=target_number))
       {
          printf("Element %d is not present in the list\n",target_number);
					//assert((target==NULL));
               return head;
       }

   return target;
}
/*  �ϥ�DeleteElement    */
dlink DeleteElement(dlink head , dlink Target)
{
   dlink current;
   current=head;
   if(head==NULL)
   {
      return NULL;
   }
   if(Target==head)
   {
      head=head->next;
      head->prev=NULL;
      free(Target);
      return head;
   }
   while(current!=NULL)
   {
       if(current==Target)
       {
          current->prev->next=current->next;
          if(current->next!=NULL)
          {
             current->next->prev=current->prev;
          }
          free(current);
          return head;
       }
       else
       {
          current=current->next;
       }
   }
      assert((current==NULL));

   return NULL;
}
dlink InsertAfterElement1(dlink head , dlink Target,int value)
{
   dlink current;
   dlink new_node= malloc(sizeof(*new_node));   
   new_node->prev = NULL;
   new_node->next = NULL;
   new_node->data = value;
     if (new_node == NULL) {

        return NULL;   // �γB�z���~
    }
   current=head;
   if(head==NULL)
   {
      return NULL;
   }
   while(current!=NULL)
   {
       if(current==Target)
       {
          new_node->next=current->next;
          new_node->prev=current;
          current->next=new_node;
          if(new_node->next!=NULL)
          {
             new_node->next->prev=new_node;
          }
          return head;
       }
       else
       {
          current=current->next;
       }
   }
      assert((current==NULL));

   return NULL;
}
dlink InsertBeforeElement1(dlink head , dlink Target,int value)
{
   dlink current;
   dlink new_node= malloc(sizeof(*new_node));   
   new_node->prev = NULL;
   new_node->next = NULL;
   new_node->data = value;
     if (new_node == NULL) {

        return NULL;   // �γB�z���~
    }
   current=head;
   if(head==NULL)
   {
      return NULL;
   }
   while(current!=NULL)
   {
       if(current==Target)
       {
          new_node->next=current;
          new_node->prev=current->prev;
          current->prev=new_node;
          if(new_node->prev!=NULL)
          {
             new_node->prev->next=new_node;
          }
          else
          {
             head=new_node;
          }
          return head;
       }
       else
       {
          current=current->next;
       }
   }
      assert((current==NULL));

   return NULL;
}
dlink ConnectLink_head_to_tail(dlink head)
{
  /*  �����V�쵲�Y���s���A�@�_,��printList�|�i�J���`�� */
        dlink reference ;
        reference=head;
         while(reference->next!=NULL)
	   		{
	   			reference=reference->next;
	   			}

        reference->next=head;//Target��next�s����first
	     head->prev=reference;//first��prev�s����Target            
   return head;
}
int count_nodes(dlink head)/* �p�����V�쵲��C���`�I�ƶq */
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}
dlink MergeTwoLists(dlink head1,dlink head2)/* �X�֨�����V�쵲��C�̷ӨC���쵲�����j�p�ƦC */
{
    dlink MergeLink = NULL;
    dlink current1 = head1;
    dlink current2 = head2;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data <= current2->data)
        {
            MergeLink = createdlist2(MergeLink, current1->data);
            current1 = current1->next;
        }
        else
        {
            MergeLink = createdlist2(MergeLink, current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        MergeLink = createdlist2(MergeLink, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        MergeLink = createdlist2(MergeLink, current2->data);
        current2 = current2->next;
    }

    return MergeLink;
}
dlink MergeTwoListTailToHead(dlink MergeLink,dlink head1,dlink head2)/* �X�֨�����V�쵲��C */
{
    dlink current1 = head1;
    dlink current2 = head2;

    while (current1 != NULL)
    {
        MergeLink = createdlist2(MergeLink, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        MergeLink = createdlist2(MergeLink, current2->data);
        current2 = current2->next;
    }

    return MergeLink;
}