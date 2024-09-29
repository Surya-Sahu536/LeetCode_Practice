/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/

int strStr(char* haystack, char* needle) {
    int len= strlen(needle);
    int length = strlen(haystack);
    if(len>length)
        return -1;
    for(int i=0,j=0,ind=0; i<length; )
    {
        //printf(" %d %d %d ", ind, i, j);
        if(haystack[i]==needle[j])
        {
            if(j==len-1)
                return ind;
            j++;
            i++;
        }
        else
        {
            j=0;
            ind++;
            i=ind;
        }
    }
    return -1;
}