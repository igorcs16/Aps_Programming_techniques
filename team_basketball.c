#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

typedef struct
{
  double Bigger;
  double Smaller;
} Compare;

void vMenu();
void vPrint_Data(double * height, char ** Names);
double Media(double * height);
//double Desvio_Padrao();
void Bigger_Smaller(double * height, Compare * stheight);

int main()
{
  char cNames[10][10];
  char *data[10];
  double iHeight[10] = {0};
  int iResp = 0;
  int i = 0;
  Compare stheight;

  memset(&cNames, 0, sizeof(cNames));

  printf("\t----Digite as informações dos jogadores----\n\n");

  for ( i = 0; i < size; i++)
  {
    printf("Nome: ");
    scanf(" %s", cNames[i]);
    printf("Altura: ");
    scanf(" %lf", &iHeight[i]);
    printf("\n");
    data[i] = cNames[i];
  }

  do
  {
    vMenu();

    scanf("%d", &iResp);

    switch(iResp)
    {
      case 1:
        vPrint_Data(iHeight, data);
        break;

      case 2:
        printf("Media das alturas do time: %.2lf\n", Media(iHeight));
        break;

      case 4:
        Bigger_Smaller(iHeight, &stheight);
        printf("Maior altura: %.2lf\nMenor altura: %.2lf\n", stheight.Bigger, stheight.Smaller);
        break;
      
      case 6:
        printf("Operacao finalizada\n");
      break;

      default:
        printf("opção incorreta, DIGITE novamente!\n");
    }

  }while(iResp != 6);

  return 0;
}

void vMenu()
{
  printf("\n\t======== TIME DE BASQUETE ========\n"
      "\t1 - Dados dos jogadores\n"
      "\t2 - Média de alturas\n"
      "\t3 - Desvio padrão das alturas\n"
      "\t4 - Maior e Menor alturas\n"
      "\t5 - Mediana das alturas\n"
      "\t6 - Finalizar\n\nDigite uma opção: ");
}

void vPrint_Data(double * height, char **Names)
{
  int iCount = 0;

  printf("\n\t---- Jogadores ----\n");

  for( iCount = 0; iCount < size; iCount++ )
    printf("Nome: %s \tAltura: %.2lf\n", Names[iCount], height[iCount]);
}

double Media(double * height)
{
  double media = 0.0;
  int i = 0, sum = 0;

  for(i = 0; i < size; i++)
    sum += height[i];
  
  media = sum / 2;

  return media;
}

void Bigger_Smaller(double * height, Compare * stheight)
{
  int i = 0;

  stheight->Smaller = 1000.00;

  for( i = 0; i < size; i++ )
  {
     if(height[i] > stheight->Bigger)
       stheight->Bigger = height[i];

     if(height[i] < stheight->Smaller)
       stheight->Smaller = height[i];
  }

}
