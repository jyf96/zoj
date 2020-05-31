#include<stdio.h>
int main()
{
  int a,b;
  while(scanf("%d%d",&a,&b)==2)
  {
    printf("%lld\n",(long long int)a+(long long int)b);
  }
  return 0;
}