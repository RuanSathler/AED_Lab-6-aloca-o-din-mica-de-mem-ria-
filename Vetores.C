#include <stdio.h>
#include <stdlib.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}


int* somente_pares(int tamanho, int * v, int *npares){
  int cont, cont2 = 0;
  int *vet = (int *)malloc(tamanho*sizeof(int));
  if(vet == NULL) exit(1);
  
  for(cont=0; cont<tamanho; cont++){
    if((v[cont]%2)==0){
      vet[cont2] = v[cont];
      *npares +=1;
      cont2 +=1;
    }
  }

  return vet;
}

int main(){
  int cont, npares, tamanho = LerInt();
  int *vet, *vetPar;

  vet = (int *)malloc(tamanho*sizeof(int));
  if(vet==NULL) exit(1);

  for(cont=0; cont<tamanho; cont++){
    vet[cont] = LerInt();
  }

  vetPar = somente_pares(tamanho, vet, &npares);
  
  for(cont=0; cont<npares; cont++){
    printf("%d ", vetPar[cont]);
  }

  free(vet);
  free(vetPar);
  return 0;
}
