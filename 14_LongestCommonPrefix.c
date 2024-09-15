/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/



char* longestCommonPrefix(char** strs, int strsSize) {
    char str[201]="";
    //if(strsSize==1)
      //  return strs[0];
    int firstSize= strlen(strs[0]);
    for(int i=1;i<strsSize;i++)
    {
        for(int j=0;j<firstSize ;j++)
        {
            if(strs[i][j]!=strs[0][j] || strs[1][j]=='\0')
            {
                firstSize = j;
                break;
            }  
        }
        printf("%s %s %d ",strs[i],strs[0],firstSize);
        
    }
    for (int k=0;k<firstSize;k++)
        str[k]= strs[0][k];
        //printf("%s",str);
    return strdup(str);
    
    /*char str[200]="";
    int firstSize= sizeof(strs[0]) / sizeof(strs[0][0]);
    for(int i=0;i<firstSize;i++)
    {
        char compare= strs[0][i];
        for(int j=0;j<strsSize;j++)
        {
            if(strs[j][i]!=compare)
                goto end;  
        }
        str[i]= compare;
    }
    end :
        printf("%s",str);
    return strdup(str);*/
}
