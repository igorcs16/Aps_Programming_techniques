#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 10 

typedef struct
{
  double Bigger;
  double Smaller;
} Compare;

void vMenu();
void vPrint_Data(double * height, char ** Names);
void Bigger_Smaller(double * height, Compare * stheight);
void selectionSort(double * vet, int n);
double Media(double * height);
double Standard_deviation(double * height);
double Median(double * height);

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
        printf("Media das alturas do time: %.2lf m\n", Media(iHeight));
      break;

      case 3:
        printf("Desvio padrão: %.4lf\n", Standard_deviation(iHeight));
        break;

      case 4:
        Bigger_Smaller(iHeight, &stheight);
        printf("Maior altura: %.2lf m\nMenor altura: %.2lf m\n", stheight.Bigger, stheight.Smaller);
      break;
      
      case 5:
        printf("Mediana das alturas: %.2lf\n", Median(iHeight));
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
    printf("Nome: %s \tAltura: %.2lf m\n", Names[iCount], height[iCount]);
}

double Media(double * height)
{
  double media = 0.0, sum = 0;
  int i = 0;

  for(i = 0; i < size; i++)
    sum += height[i];
  
  media = sum / size;

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

double Median(double * height)
{
  double height_aux[size] = {0};

  memcpy(height_aux, height, sizeof(height_aux));

  selectionSort(height_aux, size);

  if(size % 2 == 0)
    return (height_aux[size/2] + height_aux[size/2 - 1]) / 2;

  return height_aux[size/2];
} 

void selectionSort(double * vet, int n)
{
  int i = 0, j = 0, menor = 0;
  double aux = 0.0;

  for ( i = 0; i < n-1; i++)
  {
    menor = i;
    for ( j = i + 1; j < n; j++)
    {
      if ( vet[j] < vet[menor] )
        menor = j;
    }
  
    aux = vet[menor];
    vet[menor] = vet[i];
    vet[i] = aux;
  }

}

double Standard_deviation(double * height)
{
  int i = 0;
  double media = 0.0, d_p = 0.0;
  
  media = Media(height);

  for ( i = 0; i < size; i++ )
    d_p += pow(height[i] - media, 2);

  d_p = sqrt(d_p / size);

  return d_p;
}
