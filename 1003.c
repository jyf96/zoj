#include<stdio.h>
#define false 0
#define true 1
int GlobalFlag = false;
int WhoIsWin(int a,int b,int size)
{
    //printf("%d %d %d\n");
    int flag = false;
    if(size <= 1)
    {
        if(b>1)
        {
            return false;
        }
        else
        {
            if(a>1)
            {
                return true;
            }
            else
            {
                GlobalFlag = false;
                return false;
            }   
        }
    }
    if(a%size == 0)
    {
        flag |= WhoIsWin(a/size,b,size-1);
    }
    if(b%size == 0)
    {
        flag |= WhoIsWin(a,b/size,size-1);
    }
    flag |= WhoIsWin(a,b,size-1);
    return flag;
}
int main()
{
    int a,b,temp;
    while (scanf("%d%d",&a,&b) == 2)
    {
        GlobalFlag = true;
        if(a<b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        temp = (WhoIsWin(a,b,100) == false ? a:b);
        if(GlobalFlag == false)
        {
            temp = a;
        }
        printf("%d\n",temp);
    }
    return 0;
}