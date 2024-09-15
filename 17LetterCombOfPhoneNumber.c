/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* Digits(int num)
{
    switch (num)
    {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8': 
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    if(digits==NULL || *digits=='\0')
    {
        *returnSize = 0;
        return NULL;
    }
    int size= strlen(digits);
    //printf("%d",*returnSize);
    *returnSize= 1;
    int sz1,sz2,sz3,sz4;
    for(int u=0; u<size;u++)
    {
        //char *letters= Digits(digits[u]);
        int sz= strlen(Digits(digits[u])); 
        *returnSize= (*returnSize) * sz;
    }
    printf(" %d",*returnSize);
    char** comb= (char**)malloc(*returnSize * sizeof(char*));
    for(int p=0;p<*returnSize;p++)
    {
        comb[p]=(char*)malloc((size+1)* sizeof(char));
        //printf("ss %s ",comb[p]);
    }
    

    char *letters1= Digits(digits[0]);
    char* letters2= NULL;
    char* letters3=NULL;
    char* letters4=NULL;
    sz1= strlen(letters1);
    if(size>=2)
    {   
        letters2= Digits(digits[1]);
        sz2= strlen(letters2); 
    }
    if(size>=3)
    {   
        letters3= Digits(digits[2]);
        sz3= strlen(letters3); 
    }
    if(size>=4)
    {   
        letters4= Digits(digits[3]);
        sz4= strlen(letters4); 
    }
    //printf(" 111 %s 222 %s 333 %s ",letters1,letters2,letters3);

    int t=0;
    for(int i=0;i<sz1;i++)
    {
        if(size>=2)
        {
            for(int j=0;j<sz2;j++)
            {
                if(size>=3)
                {
                    for(int k=0;k<sz3;k++)
                    {
                        if(size>=4)
                        {
                            for(int m=0;m<sz4;m++)
                            {
                                comb[t][0]= letters1[i];
                                comb[t][1]= letters2[j];
                                comb[t][2]= letters3[k];
                                comb[t][3]= letters4[m];
                                comb[t][4]= '\0';
                                t++;
                                printf("   i %d %d %d %c %c ",i,j,i*sz1 + j*sz2 +k*sz3 + m,letters1[0],comb[i*sz1 + j*sz2 +k*sz3 + m][0]); 
                            }
                        }
                        else
                        {
                            comb[t][0]= letters1[i];
                            comb[t][1]= letters2[j];
                            comb[t][2]= letters3[k];                         
                            comb[t][3]= '\0';                            
                            t++;
                            printf("   i %d %d %d %c %c %c ",i,j,i*sz1 + j*sz2 +k,letters1[i],letters2[j],letters3[k]);   
                        }
                    }
                }
                else
                {
                comb[i*sz1 + j][0]= letters1[i];
                comb[i*sz1 + j][1]= letters2[j];  
                comb[i*sz1 + j][2]= '\0';  
                
                //printf("   i %d j %d place %d %c %c ",i,j,i*sz1 + j,letters1[j],letters2[j]);
                }                          
            }
        }
        else
        {
        comb[i][0]= letters1[i];
        comb[i][1]= '\0';
        }
    }
        

    for(int p=0;p<*returnSize;p++)
    {
        printf("%s ",comb[p]);
    }
        
    //printf("%d %d %d %c",*returnSize,size,sizeof(comb[6]),comb[8][1]);
    /*
    if(size>=1)
    {
        char *letters1= Digits(digits[0]);
        sz1= strlen(letters1);
        int combsz1= *returnSize / sz1;
        for(int i=0;i<sz1;i++)
        {
            for(int j=0;j<combsz1; j++)
            {
                comb[j*combsz1+i][0]= letters1[i];
                printf("   i %d %d %c %c ",i,i*combsz1+j,letters1[i],comb[i*combsz1+j][0]);
            }
        }
    }
    if(size>=2)
    {
        char *letters2= Digits(digits[1]);
        sz2= strlen(letters2); 
        int combsz2= *returnSize / sz2;
        
        for(int i=0;i<sz2;i++)
        {
            for(int j=0;j<combsz2; j++)
            {
                comb[j*combsz2+i][1]= letters2[i];
                printf("   i %d %d %c %c ",i,i*combsz2+j,letters2[i],comb[i*combsz2+j][1]);
            }
        }
    }
    if(size>=3)
    {
        char *letters3= Digits(digits[2]);
        sz3= strlen(letters3); 
        int combsz3= *returnSize / sz3;
        for(int i=0;i<sz3;i++)
        {
            for(int j=0;j<combsz3; j++)
            {
                comb[i*combsz3+j][2]= letters3[i];
            }
        }
    }
    if(size>=4)
    {
        char *letters4= Digits(digits[3]);
        sz4= strlen(letters4); 
        int combsz4= *returnSize / sz4;
        for(int i=0;i<sz4;i++)
        {
            for(int j=0;j<combsz4; j++)
            {
                comb[i*combsz4+j][3]= letters4[i];
            }
        }
    }*/
    return comb;

}
