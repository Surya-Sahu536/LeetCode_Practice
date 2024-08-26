/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

unsigned long long GetNo(struct ListNode *ptr)
{
    unsigned long long num=0;
    if(ptr->next!=NULL)
        num= GetNo(ptr->next);
    num= num*10 + ptr->val;
    //printf("  %d  ",num);
    return num;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned long long firstNo, secondNo, Sum;
    int p=0,q=0, count1, count2, count3=0, lesser, carry=0;
    struct ListNode *head, *ptr, *temp;
    int Arr1[200]; int Arr2[200]; int Arr3[200];
    ptr=NULL; head=NULL;
    count1 = 0; count2=0;

    ////Get value of both numbers, add, then convert to linked list
    ////Does not support for bigger values test case
    /*firstNo = GetNo(l1);
    //printf("%d ",firstNo);
    secondNo = GetNo(l2);
    //printf("%d ", secondNo);
    Sum= firstNo + secondNo;
    struct ListNode *sumList;
    if(Sum==0)
    {
        temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val= 0;
        temp->next = NULL;
        return temp;
    }
    while(Sum!=0)
    {
        temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val= Sum%10;
        temp->next = NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr->next=temp;
        }
        ptr= temp;
        Sum /=10;
    }*/

    ////Convert linked list to array, add array elements by order to new array, convert new array to linked list
    for(ptr=l1; ptr!=NULL; ptr=ptr->next)
        Arr1[count1++]=ptr->val;
    for(ptr=l2; ptr!=NULL; ptr=ptr->next)
        Arr2[count2++]=ptr->val;
    if(count1>count2)
        lesser=count2;
    else
        lesser=count1;
    for(int i=0; i< lesser; i++)
    {
        int sum= Arr1[i]+ Arr2[i] + carry;
        Arr3[i]= sum % 10;
        carry= sum /10;
    }
    if(count1<count2)
    {
        for(int i=lesser; i< count2; i++)
        {
            int sum= Arr2[i] + carry;
            Arr3[i]= sum % 10;
            carry= sum /10;
        }
        count3= count2;
    }
    else if(count1>count2)
    {
        for(int i=lesser; i< count1; i++)
        {
            int sum= Arr1[i] + carry;
            Arr3[i]= sum % 10;
            carry= sum /10;
        }
        count3 = count1;
    }
    else
    {
        count3= count1;
    }
    //printf("a%da b%db c%dc",count1, count2, count3);
    if(carry>0)
        Arr3[count3++]=carry;

    //for(int i=0; i<count3; i++)
      //  printf("%d ",Arr3[i]);

    for(int i=0; i<count3; i++)
    {
        temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val= Arr3[i];
        temp->next = NULL;
        if(head==NULL)
            head=temp;
        else
            ptr->next=temp;
        ptr= temp;
    }

    //for(ptr=head; ptr!=NULL; ptr=ptr->next)
      //  printf("%d",ptr->val);
    return head;
}

