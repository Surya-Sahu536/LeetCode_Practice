/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head=NULL;
    struct ListNode* temp=NULL;
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    for(;list1!=NULL && list2!=NULL; )
    {
        struct ListNode *new= (struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        if(list1->val > list2->val)
        {
            new->val=list2->val;
            list2= list2->next;
        }
        else
        {
            new->val= list1->val;
            list1= list1->next;
        }
        if(head==NULL)
        {
            temp=new;
            head=new;    
        }
        else
        {
            temp->next=new;
            temp=temp->next;
        }
    }
    while(list2!=NULL)
    {
        struct ListNode *new= (struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        new->val= list2->val;
        list2= list2->next;
        temp->next= new;
        temp= temp->next;
    }
    while(list1!=NULL)
    {
        struct ListNode *new= (struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        new->val= list1->val;
        list1= list1->next;
        temp->next= new;
        temp= temp->next;
    }
    return head;
}