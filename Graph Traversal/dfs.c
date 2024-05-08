#include<stdio.h>
#include<stdlib.h>

int m[5][5] = {{0,1,1,0,0}, {1,0,0,1,1}, {1,0,0,0,1}, {0,1,0,0,0}, {0,1,1,0,0}};
int visited[5];
void dfs(int m[5][5], int v, int source)
{
int i;
visited[source] = 1;
     printf("%d\t", source);
for(i=0; i<v; i++)
{
    if(m[source][i] == 1 && visited[i] == 0)
 {
    // printf("%d\t", i);
     dfs(m, v, i);
}
}
}
int main()
{
int i;
int source = 4;

int v = 5;
for (i= 0; i < v; i ++)   visited[i] = 0;
     printf("The DFS Traversal is: \n");

     dfs(m, v, source);
return 0;
}

