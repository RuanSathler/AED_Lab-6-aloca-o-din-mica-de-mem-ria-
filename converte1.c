#include<stdio.h>
#include<stdlib.h>

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

void LerMatDinamica(float **mat, int qntLinha, int qntColuna){
  int contL, contC;
  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
    mat[contL][contC] = LerFloat();
    }
  }
}

void imprimeMatDinamica(float **mat, int qntLinha, int qntColuna){
  int contL, contC;
  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
    printf("%.2f ", mat[contL][contC]);
    }
    putchar('\n');
  }
}

float **CriaMatDinamica(int qntLinha, int qntColuna){
  int cont;
  
  float **mat = (float **)malloc(qntLinha*sizeof(float *));
  if(mat==NULL) exit(1);

  for(cont=0; cont<qntLinha; cont++){
    mat[cont] = (float *)malloc(qntColuna*sizeof(float));
    if(mat[cont]==NULL) exit(1);
  }

  return mat;
}

void LiberaMatDinamica(float **mat, int qntLinha){
  int cont;

  for(cont=0; cont<qntLinha; cont++){
    free(mat[cont]);
  }

  free(mat);
}

float **transposta(int qntLinha, int qntColuna, float** mat){
  int contC, contL;
  float** transposta = CriaMatDinamica(qntColuna, qntLinha);

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
    transposta[contC][contL] = mat[contL][contC];
    }
  }
  
  return transposta;
}

int main(){

  int qntLinha = LerInt(), qntColuna = LerInt();
  float **mat = CriaMatDinamica(qntLinha, qntColuna);

  LerMatDinamica(mat, qntLinha, qntColuna);
  mat = transposta(qntLinha, qntColuna, mat);
  imprimeMatDinamica(mat, qntColuna, qntLinha);

  LiberaMatDinamica(mat, qntLinha);
  
  return 0;
}
