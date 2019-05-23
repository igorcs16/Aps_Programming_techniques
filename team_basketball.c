#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

void vMenu();
void vPrint_Data(double * height, char ** Names);
double Media(double * height);

int main()
{
  char cNames[10][10];
  char *data[10];
  double iHeight[10] = {0};
  int iResp = 0;
  int i = 0;

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
        printf("Media das alturas do time: %lf", Media(iHeight));
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
    printf("Nome: %s \tAltura: %lf\n", Names[iCount], height[iCount]);
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
