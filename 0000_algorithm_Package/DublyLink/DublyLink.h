#ifndef _DublyLink_
#define _DublyLink_
struct dlist                      /* 雙向串列結構宣告   */
{
   int data;                      /* 節點資料           */
//   struct dlist *next;           /* 指向下一節點的指標 */
//   struct dlist *prev;            /* 指向前一節點的指標 */
    struct dlist *next;           /* 指向下一節點的指標 */
    struct dlist *prev;            /* 指向前一節點的指標 */
};
typedef struct dlist dnode;       /* 雙向串列新型態     */
typedef dnode *dlink;   
void printdlist(dlink head,dlink now);/* 顯示雙向鏈結串列內容 */
dlink createdlist(int *array,int len);/*使用陣列元素建立雙向鏈結串列 */
dlink createdlist2(dlink head,int value);/*使用單一值建立雙向鏈結串列 */
dlink Search_Target(dlink head , int target_number);/*  使用指標指向想要找的目標    */
dlink DeleteElement(dlink head , dlink Target);/*  使用DeleteElement    */
dlink InsertAfterElement1(dlink head , dlink Target,int value);/* 插入元素指定元素的前面 */                                                                                                                                                    
dlink InsertBeforeElement1(dlink head , dlink Target,int value);/* 插入元素指定元素的後面 */
dlink ConnectLink_head_to_tail(dlink head);/* 將雙向鏈結串列的頭部連接到尾部 */
dlink MergeTwoLists(dlink head1,dlink head2);/* 合併兩個雙向鏈結串列依照每個鏈結元素大小排列 */
dlink MergeTwoListTailToHead(dlink MergeLink,dlink head1,dlink head2);/* 合併兩個雙向鏈結串列 */
int count_nodes(dlink head);/* 計算雙向鏈結串列的節點數量 */
#endif