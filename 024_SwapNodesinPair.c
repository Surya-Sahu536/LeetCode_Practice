/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *temp=NULL,*ptr;
    if(head==NULL || head->next==NULL)
        return head;

    temp= head->next->next;     
    head->next->next= head;     
    head= head->next;   
    head->next->next=temp;    
    
    ptr=head->next;
    //printf("%d",head->val);
    while(ptr->next!=NULL && ptr->next->next!=NULL)
    {
        temp=ptr->next->next->next;
        ptr->next->next->next= ptr->next;
        ptr->next= ptr->next->next;
        ptr->next->next->next= temp;
        ptr= ptr->next->next;
    }
    return head;
}
