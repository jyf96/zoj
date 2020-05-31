#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
char T[6][6];
int max;
int check(int x,int y)
{
  int flag = 1;
  if(T[x][y]=='X'||T[x][y]=='O')
  {
    return 0;
  }
  int i;
  for(i=0;i<x;i++)
  {
    if(T[i][y]=='O')
    {
      flag = 0;
    }
    if(T[i][y]=='X')
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    return flag;
  }
  for(i = N-1;i > x;i--)
  {
    if(T[i][y]=='O')
    {
      flag = 0;
    }
    if(T[i][y]=='X')
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    return flag;
  }
  for(i=0;i<y;i++)
  {
    if(T[x][i]=='O')
    {
      flag = 0;
    }
    if(T[x][i]=='X')
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    return flag;
  }
  for(i = N-1;i > y;i--)
  {
    if(T[x][i]=='O')
    {
      flag = 0;
    }
    if(T[x][i]=='X')
    {
      flag = 1;
    }
  }
  return flag;
}
int dfs(int x,int y)
{
  if(y>=N)
  {
    x++;
    y -= N;
    if(x>=N)
    {
      return 0;
    }
  }
  int sum1 = 0,sum2 = 0;
  if(check(x,y))
  {
    T[x][y]='O';
    sum1 = dfs(x,y+1)+1;
    T[x][y]='.';
  }
  sum2 = dfs(x,y+1);
  return  sum1>sum2?sum1:sum2;
}
int main()
{
  int i;
  while(1 == scanf("%d",&N))
  {
    memset(T,0,sizeof(T));
    max =0;

    if(N == 0 || N < 0)
    {
      break;
    }
    for(i = 0;i < N ;i++)
    {
      scanf("%s",T[i]);
    }
    int ret = dfs(0,0);
    printf("%d\n",ret);
  }
  return 0;
}