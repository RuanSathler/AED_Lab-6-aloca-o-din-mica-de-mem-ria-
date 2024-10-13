#include <stdio.h>
#include <stdlib.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}

void LerVetor(int *vet, int tamanho){
  int cont;
  for(cont=0; cont<tamanho; cont++){
    vet[cont] = LerInt();
  }
}

int* soma(int *vet1, int *vet2, int tamanho){
  int cont;
  int *vet = (int *)malloc(tamanho*sizeof(int));

  for(cont=0; cont<tamanho; cont++){
    vet[cont] = vet1[cont] + vet2[cont];
  }

  return vet;
}

int main(){
  int cont, tamanho = LerInt(), vet1[tamanho], vet2[tamanho];

  LerVetor(vet1, tamanho);
  LerVetor(vet2, tamanho);

  int *vetSoma = soma(vet1, vet2, tamanho);
  
  for(cont=0; cont<tamanho; cont++){
    printf("%d ", vetSoma[cont]);
  }
   
  return 0;
}
