/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


bool isSame(char fst, char snd)
{
    if(fst=='('&&snd==')' || fst=='{'&&snd=='}' || fst=='['&&snd==']')
        return true;
    return false;
}
bool isValid(char* s) {
    int len= strlen(s);
    if(s[0]==')' || s[0]== '}' || s[0]==']' || len%2==1)
        return false;
    char stack[10001];
    int p2=0,stacktrace=-1;
    //while(s[p1]!='\0' && s[p2]!='\0')
    while(p2<len)
    {
        printf(" %d %d ",stacktrace,p2);
        if(s[p2]==')' || s[p2]=='}' || s[p2]==']')
        {
            if(stacktrace==-1)
                return false;
            if(isSame(stack[stacktrace],s[p2]))
                stacktrace--;
            else
                return false;
        }
        else
        {
            stacktrace++;
            stack[stacktrace]=s[p2];
            if(p2==len-1)
                return false;
        }
        p2++;
    }
    if(stacktrace!=-1)
        return false;
    return true;

    /*while(p1<len && p2<len)
    {
        printf(" %d %d %d %d ",p1,p2,s1,s2);
        if(isSame(s[p1],s[p2])==1)
        {
            if(s[p1]=='(' || s[p1]=='{' || s[p1]=='[')
            {
                p1=p2+1;
                s1=p2+1;
                p2=p2+2;
                s2=p2+2;
                if(p1==len-1 ) 
                    return false;
            }
            else
            {
                if(p2==len-1)
                    return false;
                p1--;
                p2++;
            }
        }
        else if(isSame(s[p1],s[p2])==-1)
        {
            return false;
        }
        else
        {
            if(p2==len-1)
                return false;
            p1++;
            p2++;
            s2= s2+1;
        }
    }*/
}
