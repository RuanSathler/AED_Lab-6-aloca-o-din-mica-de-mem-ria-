#include <stdio.h>
#include <stdlib.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}

float LerFloat(){
  float numLido;
  scanf("%f", &numLido);

  return numLido;
}

void ImprimeReverso(int tamanho, float* vet){
  int cont;
  for(cont=(tamanho-1); cont>=0; cont--){
    printf("%.2f ", vet[cont]);
  }
}

int main(){
  int tamanho = LerInt(), cont;
  float *vet = (float *)malloc(tamanho*sizeof(float));

  if(vet==NULL) exit(1);

  for(cont=0; cont<tamanho; cont++){
    vet[cont] = LerFloat();
  }

  ImprimeReverso(tamanho, vet);

  free(vet);
  
  return 0;
}
