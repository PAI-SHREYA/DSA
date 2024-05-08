#include<stdio.h>
#define size 100
typedef struct stack
{
    int data[size];
    int top;
}STACK;
void binary(STACK *s,int m)
{
    while(m)
    {
        push(s,m%2);
        m=m/2;
    }
}
void push(STACK *s,int m)
{
    s->top++;
    s->data[s->top]=m;
}
void pop(STACK *s,int m)
{
    printf("%d in binary is\n",m);
    while(s->top!=-1)
    {
        printf("%d",s->data[s->top]);
        s->top--;
    }
}



int main()
{
    STACK s;
    int m;
    s.top=-1;
    printf("enter\n");
    scanf( "%d",&m);
    binary(&s,m);
    pop(&s,m);
}
