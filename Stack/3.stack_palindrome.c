#include<stdio.h>
#define size 100
typedef struct stack{
char data[size];
int top;

}STACK;
void push(STACK *s)
{

    printf("enter\n");
    scanf(" %c",&s->data[s->top]);

}
void pop(STACK *s)
{
   int x=s->top;
   int y=0;
   while(x>y)
    { //printf("% c %c \n",s->data[x],s->data[y]);
      if(s->data[x]!= s->data[y])
      {
          printf("not palindrome\n");
          return;
      }
      x--;y++;
    }
    printf("palindrome\n");
}


int main(){
 STACK s;
 int n;
printf("enter the size\n");
scanf("%d",&n);
s.top=-1;
for(int i=1;i<=n;i++)
{
// printf("%d\n",i);
   s.top++;
   push(&s);
}
pop(&s);
}
