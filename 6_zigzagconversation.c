/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/


char* convert(char* s, int numRows) {
    if(numRows==1)
        return s;
    char result[1000]="\0";
    char strs[numRows][500];
    int i;
    int len= strlen(s);
    int itr= (numRows-1)*2;  //4
    if(numRows==2)
    {
        //itr=3;
        int ind=0;
        for(int t=0;t<len;t+=2)
            result[ind++]=s[t];
        for(int t=1;t<len;t+=2)
            result[ind++]=s[t];
        return strdup(result);
    }
    //printf("a%d %d ",len,itr);

    
    for(int j=0;j<numRows;j++)
    {
        strcpy(strs[j],"\0");
        //printf("_uu%s %s ",strs[j], result);
    }
    for(i=0; i<len;i++)
    {
        int index= i/itr;  //0  0   0   0   1   1   1   1
        int pos= i%itr;   //0   1   2   3   0   1   2   3     
        if(pos<numRows)
        {
            if(pos==0 || pos== numRows-1)
                strs[pos%numRows][index]= s[i];
            else
                strs[pos%numRows][index*2] = s[i];
        }
        else
            //printf("33 %d %d ",numRows+1-pos,index*2+1);
            strs[itr-pos][(index*2)+1]=s[i];
    }

    for(int k=0;k<numRows;k++)
    {
        int index= (len-1)/itr;  //0  0   0   0   1   1   1   1
        int pos= (len-1)%itr;   //0   1   2   3   0   1   2   3     
        if(k==0 || k== numRows-1)
        {
            //printf("1111 ");
            if(pos>=k)
                strs[k][index+1]= '\0';
            else
                strs[k][index]= '\0';
        }
        else
        {
            //printf("2222 ");
            if(pos<k)
                strs[k][index*2] = '\0';
            else if(k>=(itr-pos))
                strs[k][index*2+2]= '\0';
            else
                strs[k][index*2+1]= '\0';
        }
    }
    for(int j=0;j<numRows;j++)
        strcat(result,strs[j]);
        //printf("_%s %s ",strs[j], result);
    
    
    //printf("  %s ",result);
    return strdup(result);
}
