
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

void display(int D[4][4])
{
        for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
          printf("%d\t",D[i][j]);
      }
      printf("\n");
    }
}


int warshal(int D[4][4])
{
for(int k=0;k<4;k++)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            D[i][j]=D[i][j]||(D[i][k]&&D[k][j]);
        }
    }
}
}
int main()
{
    int D[4][4]={{0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0}};;
    D[4][4]=warshal(D);
    printf("Wagshal matrix\n");
    display(D);

   //  D[4][4]=floyd(D);


    return 0;

}
