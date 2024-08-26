/**
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-2^31 <= x <= 2^31 - 1

 */

int reverse(int x){
    int y=0,digits=0, rem=0;
    //bool positive= true;
    if(x== -2147483648)   // converting this to positive will exceed limit
        return 0;
    //if(x<0)
    //{   
        //positive= false;
        //x= -1 *x;
    //}
    while(x!=0)
    {
        //if(digits>=8)
        //{
            if(y> 214748364 || y< -214748364)
            {
                return 0;
            }
            if( y == 214748364)
            {
                if(x%10 >= 7)
                    return 0;
            }
        //}
        //if(digits>9)
         //return 0;
        rem=x%10;
        y= y*10 + rem;
        x= x/10;
        //digits++;
    }
    //if(!positive)
    //{
        //printf("%d", y);
        //y = -1 * y;
    //} 
    return y;
}
