#include<Stdio.h>
#define size 10
typedef struct stack{
char data[size];
int top;
}STACK;
int pop(STACK *s,char b)
{
    if(s->data[s->top]==b)
    {  s->top--;
        return 1;
    }
    return 0;
}
int check(STACK *s,char b[])
{
    for(int i=0;b[i];i++)
    {
        if( b[i]=='['|| b[i]=='('|| b[i]=='{')
            {
                push(s,b[i]);
            }
            else{
                if(!isempty(s))
                {
                    return 0;
                }
                else if( b[i]=='(' && !pop(s,b[i]))
                {
                    return 0;
                }
                 else if( b[i]=='[' && !pop(s,b[i]))
                {
                    return 0;
                }
                 else if( b[i]=='{' && !pop(s,b[i]))
                {
                    return 0;
                }

            }
}

                return isempty(s);
}

int isempty(STACK *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}
void push(STACK *s,char b)
{
    s->top++;
    s->data[s->top]=b;
}


int main()
{
    STACK s;
    s.top=-1;
    char b[10];
    printf("s\n");
    scanf("%s",b);
int e=check(&s,b);
if(e==0)
{
    printf("not balanced\n");
}
else if(e==1)
{
    printf("balanced\n");
}
}
