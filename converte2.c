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

void LerMatDinamica(int qntLinha, int qntColuna, float **mat){
  int contL, contC;

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntLinha; contC++){
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

void LerMatLinear(int qntLinha, int qntColuna, float *mat){
  int contL, contC;

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
      mat[contL * qntColuna + contC] = LerFloat();
    }
  }  
}

float **CriaMatDinamica(int qntLinha, int qntColuna){
  int cont;
  float **mat = (float**)malloc(qntLinha*sizeof(float *));
  if(mat==NULL) exit(1);

  for(cont=0; cont<qntLinha; cont++){
    mat[cont] = (float*)malloc(qntColuna*sizeof(float));
    if(mat[cont]==NULL) exit(1);
  }

  return mat;
}

void LiberaMat(float **mat, int qntLinha){
  int cont;
  
  for(cont=0; cont<qntLinha; cont++){
    free(mat[cont]);
  }

  free(mat);
}

float **conveteMat(int qntLinha, int qntColuna, float *mat){
  int contL, contC;
  float **conversao = CriaMatDinamica(qntLinha, qntColuna);

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
      conversao[contL][contC] = mat[contL * qntColuna + contC];
    }
  }

  return conversao;
}  
  


int main(){
  int qntL = LerInt(), qntC = LerInt();
  
  float **conversao, mat[qntL*qntC];

  LerMatLinear(qntL, qntC, mat);
  conversao = conveteMat(qntL, qntC, mat);
  imprimeMatDinamica(conversao, qntL, qntC);

  LiberaMat(conversao, qntL); 
  
  
  return 0;
}
