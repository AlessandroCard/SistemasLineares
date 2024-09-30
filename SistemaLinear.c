#include <stdio.h>
#define L 3
#define C 3

//Printa a matriz
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

//Troca duas linhas da matriz
void TrocarLinha(double M[L][C], int linha1, int linha2)
{
    double T[C];
    
    for(int i = 0; i < C; i++)
    {
        T[i] = M[linha1][i];
    }
    for(int i = 0; i < C; i++)
    {
        M[linha1][i] = M[linha2][i];
        M[linha2][i] = T[i];
    }
}

//Atribui um valor posto pelo usuário a uma matriz
void EscreveMatriz(int l, int c, double M[l][c])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }
}


int main()
{
  double A[L][C] = {2, 1, 1, 1, 1, 4, 0, 3, 2};
  double B[L][1] = {8, 15, 9};
  double R[L][1] = {0,0,0};
  int p = 0;

  printf("Escreva os coeficientes do sistema\n");
  EscreveMatriz(L, C, A);
  printf("Escreva a matriz de resultados\n");
  EscreveMatriz(L, 1, B);
  
  printf("Matriz antes da Eliminacao Gaussiana\n");
  LerMatriz(A);
  printf("Matriz de resultados antes da Eliminacao Gaussiana\n");
  printf("%lf\n%lf\n%lf\n\n",B[0][0],B[1][0],B[2][0]);

  //Eliminação Gaussiana
  for(int c = 0; c < C-1; c++)
  {
        for(int i = c + 1; i < L; i++)
        {
            int l = L;
            do
            {
                l--;
                if(A[c][c] == 0) //Verifica a necessidade de trocar a linha
                {
                    TrocarLinha(A, c, l);
                }
            }while(A[c][c] == 0 && l > i);
            if(l < i)
            {
                printf("Sistema indeterminado ou impossível\n");
                p = 1;
                break;
            }
            if(A[i][c] != 0)//Verifica se o elemento já está zerado
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
        if(p == 1)
        {
            break;
        }

  }
  p = 0;
  
  printf("Matriz apos a Eliminacao Gaussiana\n");
  LerMatriz(A);
  printf("Matriz de resultados apos a Eliminacao Gaussiana\n");
  printf("%lf\n%lf\n%lf\n\n",B[0][0],B[1][0],B[2][0]);
  
//Algoritmo de substituição para encontrar as incógnitas  
if(A[L - 1][C - 1] != 0)
{
    for(int i = L - 1; i >= 0; i--)
    {
        double soma = B[i][0];
        for(int j = i + 1; j < C; j++)
        {
            soma -= R[j][0] * A[i][j];
        }
        R[i][0] = soma/A[i][i];
    }

    printf("Matriz com o valor das incognitas\n%lf\n%lf\n%lf\n\n",R[0][0], R[1][0], R[2][0]);
}
else
    printf("Sistema impossivel ou indeterminado\n");
  
  
  //TrocarLinha(A, 0, 1);
  //LerMatriz(A);
  
    return 0;
}