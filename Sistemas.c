#include <stdio.h>
#define L 3
#define C 3

//Compiler version gcc  6.3.0


void LerMatriz(double A[L][C])
{
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
  double A[L][C]={3, -0.1, -0.2, 0.1, 7, -0.3, 0.3, -0.2, 10};
  double B[L][1]={7.85, -19.3, 71.4};
  double R[L][1] = {0,0,0};
  
  LerMatriz(A);
  
  for(int c = 0; c < C-1; c++)
  {
        for(int i = c+1; i < L; i++)
        {
          double fator = A[i][c]/A[c][c];
          B[i][0] -= B[c][0]*fator;
          for(int j = c+1; j < L; j++)
          {
              A[i][j] -= A[c][j] * fator;
              A[i][c] = 0;
          }
        }

  }
    
  LerMatriz(A);
  printf("%lf\n%lf\n%lf\n\n",B[0][0],B[1][0],B[2][0]);
  
  
  for(int i = L - 1; i >= 0; i--)
  {
      double soma = B[i][0];
      for(int j = i + 1; j < C; j++)
      {
          soma -= R[j][0] * A[i][j];
      }
      R[i][0] = soma/A[i][i];
  }
  
  printf("%lf\n%lf\n%lf\n",R[0][0], R[1][0], R[2][0]);
  
  return 0;
}