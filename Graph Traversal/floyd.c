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

int floyd(int D[4][4])
{
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(D[i][j]>(D[i][k]+D[k][j]))

                    D[i][j]=D[i][k]+D[k][j];
            }
        }
    }
    return D;
}
int warshal(int D[4][4])
{

}
int main()
{
    int D[4][4]={{0,9999,3,9999},{2,0,9999,9999},{9999,7,0,1},{6,9999,9999,0}};
    D[4][4]=floyd(D);
    printf("Floyd's matrix\n");
    display(D);
//
    //D[4][4]={{0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0}};
   // printf("Warshal's matrix\n");
     D[4][4]=floyd(D);


    return 0;

}
