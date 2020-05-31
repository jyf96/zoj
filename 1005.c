#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE (1000+1)
typedef struct 
{
    int bIsCreated;
    int bIsVisited;
    int x,y;
    int x_pre,y_pre;
    int Opt;
}Point;
Point Table[MAX_SIZE][MAX_SIZE];

Point *queue[MAX_SIZE];
int first,next;

char *Show[] = 
{
    "fill A\n",
    "fill B\n",
    "empty A\n",
    "empty B\n",
    "pour A B\n",
    "pour B A\n",
    "success\n"
};

#define Check(x,y,x_next,y_next) _Check(x,y,x_next,y_next,i)
#define CreatePoint(p,x,y,x_pre,y_pre) _CreatePoint(p,x,y,x_pre,y_pre,i)

void _CreatePoint(Point *p,int x,int y,int x_pre,int y_pre,int i)
{
    //printf("x=%d,y=%d,x_pre = %d,y_pre = %d\n",x,y,x_pre,y_pre);
    queue[next] = p;
    next++;
    p->bIsCreated = 1;
    p->x = x;
    p->y = y;
    p->x_pre = x_pre;
    p->y_pre = y_pre;
    p->Opt = i;
}
void _Check(int x,int y,int x_next,int y_next,int i)
{
    if(Table[x_next][y_next].bIsCreated == 0)
    {
        CreatePoint(&(Table[x_next][y_next]),x_next,y_next,x,y);
    }
}
void Opt(int Ca,int Cb,int N)
{
    int x,y;
    int x_next,y_next;
    while(first<next)
    {
        x = queue[first]->x;
        y = queue[first]->y;
        queue[first]->bIsVisited = 1;
        first++;

        if(y == N)
        {
            break;
        }
        int i = 0;
        Check(x,y,Ca,y);
        i++;
        Check(x,y,x,Cb);
        i++;
        Check(x,y,0,y);
        i++;
        Check(x,y,x,0);
        i++;
        //a往b倒
        if(x+y>Cb)
        {
            Check(x,y,x+y-Cb,Cb);

        }
        else if(x+y < Cb)
        {
            Check(x,y,0,x+y);
        }
        else
        {
            Check(x,y,0,Cb);
        }
        i++;
        //b往a倒
        if(x+y>Ca)
        {
            Check(x,y,Ca,x+y-Ca);
        }
        else if(x+y < Ca)
        {
            Check(x,y,x+y,0);
        }
        else
        {
            Check(x,y,Ca,0);
        }
    }
    if(y==N)
    {
        int stack[1000] = {0};
        int top = 0;
        stack[top] = 6;
        top++;
        while(x!=0 || y!=0)
        {
            stack[top] =  Table[x][y].Opt;
            top++;
            x_next = Table[x][y].x_pre;
            y_next = Table[x][y].y_pre;
            x = x_next;
            y = y_next;
        }
        while(top>0)
        {
            top--;
            printf("%s",Show[stack[top]]);
        }
    }
}
int main()
{
    int Ca,Cb,N;
    while(3 == scanf("%d%d%d",&Ca,&Cb,&N))
    {
        memset(Table,0,MAX_SIZE*MAX_SIZE*sizeof(Point));
        memset(queue,0,MAX_SIZE*sizeof(Point *));
        first = 0,next = 0;
        int i = 0;
        CreatePoint(&(Table[0][0]),0,0,0,0);
        Opt(Ca,Cb,N);
    }
    return 0;
}