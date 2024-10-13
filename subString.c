#include <stdio.h>
#include <stdlib.h>
#define STR_MAX 80

char *converteParaDNA(char *rna) {
  int cont;
  char *dna = malloc(sizeof *dna * (STR_MAX + 1));

  for(cont=0; rna[cont]!='\0'; cont++){
    if(rna[cont]=='u') dna[cont] ='t';
    else dna[cont] = rna[cont];
  }

  dna[cont] ='\0';
  
  return dna;
}

char *converteParaRNA(char *dna) {
  int cont;
  char *rna = malloc(sizeof *rna * (STR_MAX + 1));

  for(cont=0; dna[cont]!='\0'; cont++){
    if(dna[cont]=='t') rna[cont] ='u';
    else rna[cont] = dna[cont];
  }

  rna[cont] ='\0';
  
  return rna;
}

int HeDna(char *supostoDna){
  int cont;

  for(cont=0; supostoDna[cont]!='\0'; cont++){
    if(supostoDna[cont]=='t') return 1;
  }

  return 0;
}

int verifica_nucleotideos(char *dna, char *rna) {
  char *rnaConvertido;
  int cont1, cont2, cont3 = 0, tamDna = 0, tamRnaConvertido = 0;

  if(HeDna(rna)) rnaConvertido = converteParaRNA(rna);
  else rnaConvertido = converteParaDNA(rna);

  while(rna[tamRnaConvertido]!='\0') tamRnaConvertido++;
  while(dna[tamDna]!='\0') tamDna++;

  for(cont1=0; cont1<=tamDna-tamRnaConvertido; cont1++){
    cont3 = 0;
    
    for(cont2=0; cont2<tamRnaConvertido; cont2++){
      if(dna[cont1+cont2] == rnaConvertido[cont2]) cont3++;    
    }

    if(cont3==tamRnaConvertido) return 0;
  }


  return 1;
}

int main(void) {

    char *dna = malloc(sizeof *dna * (STR_MAX + 1));
    char *rna = malloc(sizeof *rna * (STR_MAX + 1));

    scanf("%s", dna);
    scanf("%s", rna);

    if(verifica_nucleotideos(dna, rna)) {
        printf("Substring nao presente na string\n");
    } else {
        printf("Substring presente na string\n");
    }

    return 0;
}
