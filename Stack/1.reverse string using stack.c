#include<stdio.h>
#define size 100
typedef struct stack{
char data[size];
int top;
}STACK;
void push(STACK *s,char word[])
{

    for(int i=0;word[i];i++)
    {
        s->top++;
        s->data[s->top]=word[i];
        //printf("%c\n",word[i]);

    }
}
void pop(STACK *s,char word[])
{
    int i=0;
    while(s->top!=-1)
    {
        word[i]=s->data[s->top];
        s->top--;
       // printf("%c\n",word[i]);
        i++;
       // printf("%d\n",i);
    }
               printf("after %s\n",word);
}


int main()
{
    char word[100];
    STACK s;
    s.top=-1;
    printf("enter\n");
    scanf("%s",&word);

    push(&s,word);
  //  printf("%d",s.top);
    printf("before %s\n",word);
    pop(&s,word);

}
