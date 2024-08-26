/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/



int maxArea(int* height, int heightSize) {
    int area,maxarea= 0, positionMax=0, positionHeight=0, position=1, leftposition=0, leftpositionHeight=0, leftpositionMax=0;
    ////Find the height having most place value from either side
    for(int i=1;i<heightSize; i++)
    {
        area= (i)* height[i];
        if(area>=positionMax)
        {
            positionMax= area;
            position=i;
        }
        //printf("%d,%d ",position,positionMax);
    }
    for(int i=0;i<heightSize-1; i++)
    {
        area= (heightSize-1-i)* height[i];
        if(area>=leftpositionMax)
        {
            leftpositionMax= area;
            leftposition=i;
        }
        //printf("%d,%d ",leftposition,leftpositionMax);
    }
    //printf("%d",position);
    //printf("%d ",leftposition);
    
    if(height[position]> height[leftposition])
        maxarea= height[leftposition] * (position-leftposition);
    else
        maxarea= height[position] * (position-leftposition);
    
    ////test all the heights to the right the right highest position value and left to left highest position value
    for(int k=position+1; k<heightSize; k++)
    {
        if(height[k]>= height[leftposition])
        {
            area= (k-leftposition)* height[leftposition];
            if(area>maxarea)
            {
                maxarea= area;
                position=k;
            }
        }
        else
        {
            area= (k-leftposition)* height[k];
            if(area>maxarea)
            {
                maxarea= area;
                position=k;
            }
        }
    }

    for(int m=leftposition-1; m>=0; m--)
    {
        if(height[m]>= height[position])
        {
            area= (position-m)* height[position];
            if(area>maxarea)
            {
                maxarea= area;
                leftposition=m;
            }
        }
        else
        {
            area= (position-m)* height[m];
            if(area>maxarea)
            {
                maxarea= area;
                leftposition=m;
            }
        }
    }


    return maxarea;
}
