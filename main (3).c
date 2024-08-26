/*
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-2^31 <= x <= 2^31 - 1

*/



bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0)) //negative nos are not pallidrone
        return false;
    int rem = x%10;
    int num, rev=0;;
    num= x;
    //int reverse= Reverse(&num, 0);

    while(num/10!=0)  //not adding the 1st digit for reversing as it exceeds the int size
    {
        rev= rev* 10 + num%10;
        num= num/10;
    }

    x/=10;  // removing the last digit of the number
    //printf("r %d %d %d %d ",x,rev,rem,num);
    
    if(x==rev && rem==num)  //checking both number and reversed no, 1st digit and last digit
        return true;
    return false;
}

int Reverse(int* num, int rev)   //recursive function to reverse- not used
{
    int rem=0;
    if((*num)/10!=0)
    {
        rem= (*num)%10;
        rev= rev*10 + rem;
        printf(" %d  %d  %d p ",num, rev,rem);
        return Reverse(*num/10, rev);
    }
    return rev;
}