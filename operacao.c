#include <stdio.h>
#include <stdlib.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}

char LerChar(){
  char charr;
  scanf(" %c", &charr);

  return charr;
}

int *CriaVetIntDinamico(int tamanho){
  int *vet = (int*)malloc(tamanho*sizeof(int));
  if(vet==NULL) exit(1);

  return vet;
}

char *CriaVetCharDinamico(int tamanho){
  char *vet = (char*)malloc(tamanho*sizeof(char));
  if(vet==NULL) exit(1);
  
  return vet;
}

void LerVetIntDinamico(int *vet, int tamanho){
  int cont;
  
  for(cont=0; cont<tamanho; cont++){
    vet[cont] = LerInt();
  }
}

void LerVetCharDinamico(char *vet, int tamanho){
  int cont;
  
  for(cont=0; cont<tamanho; cont++){
    vet[cont] = LerChar();
  }
  
}
  
int main(void) {
  int tamanho = LerInt(), *vet = CriaVetIntDinamico(tamanho), cont;
  float acumulador;
  char *vet2 = CriaVetCharDinamico(tamanho-1);

  LerVetIntDinamico(vet, tamanho);
  LerVetCharDinamico(vet2, (tamanho-1));

    for(cont=0; cont<tamanho; cont++){
    printf("%d ",vet[cont]);
  }

  putchar('\n');
    for(cont=0; cont<(tamanho-1); cont++){
    printf("%c",vet2[cont]);
  }
  acumulador = vet[0];
  putchar('\n');
    
  for(cont=0; cont<(tamanho-1); cont++){
    switch(vet2[cont]){
      case '-':
            acumulador = acumulador-vet[cont+1];
            continue;
      case '+':
            acumulador = acumulador+vet[cont+1];
            continue;
      case '*':
            acumulador = acumulador*vet[cont+1];
            continue;
      case '/':
            acumulador = acumulador/vet[cont+1];
            continue;
    }
  }

  printf("%.2f", acumulador);
  return 0;
  
}
