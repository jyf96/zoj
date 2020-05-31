#include <stdio.h>
#include <string.h>

char buff[1000];
char OutPut[1000];
char OptBuff[1000];
int n, in,out,top;
void Opt(char *s1, char *s2)
{
    //printf("*in = %d,out = %d,n = %d\n",in,out,n);
    //printf("**s1=%s s2=%s buff=%s OutPut=%s OptBuff=%s\n",s1,s2,buff,OutPut,OptBuff);
    if(in<n)
    {
        OptBuff[in+out] = 'i';
        in++;
        buff[top] = s1[in-1];
        top++;
        Opt(s1,s2);
        top--;
        buff[top]=0;
        in--;
        OptBuff[in+out] = 0;
    }
    if(out<in)
    {
        OptBuff[in+out] = 'o';
        out++;
        OutPut[out-1] = buff[top-1];
        buff[top-1] = 0;
        top--;
        Opt(s1,s2);
        top++;
        buff[top-1] = OutPut[out-1];
        OutPut[out-1] = 0;
        out--;
    }
    if(in == n && out == n)
    {
        if(0 == strcmp(OutPut,s2))
        {
            int i;
            for(i = 0;i< 2*n;i++)
            {
                printf("%c ",OptBuff[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    char s1[1000], s2[1000];
    memset(s1, 0, 1000);
    memset(s2, 0, 1000);
    while (scanf("%s%s", s1, s2) == 2)
    {
        memset(buff, 0, 1000);
        memset(OutPut, 0, 1000);
        memset(OptBuff, 0, 1000);
        in = 0,out = 0,top=0;
        printf("[\n");
        n = strlen(s1);
        if (n == strlen(s2))
        {
            Opt(s1, s2);
        }
        printf("]\n");
        memset(s1, 0, 1000);
        memset(s2, 0, 1000);
    }
    return 0;
}