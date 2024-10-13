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
    for(contC=0; contC<qntColuna; contC++){
      mat[contL][contC] = LerFloat();
    }
  }
}

void ImprimeMatLinear(int qntLinha, int qntColuna, float *mat){
  int contL, contC;

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
      printf("%.2f ",mat[contL * qntColuna + contC]);
    }
    putchar('\n');
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

float *ConverteMat(int qntLinha, int qntColuna, float **mat){
  int contL, contC;
  float *conversao = (float *)malloc(qntLinha * qntColuna*sizeof(float));

  for(contL=0; contL<qntLinha; contL++){
    for(contC=0; contC<qntColuna; contC++){
       conversao[contL * qntColuna + contC] = mat[contL][contC];
    }
  }

  return conversao;
}  
  


int main(){
  int qntL = LerInt(), qntC = LerInt();
  float **mat = CriaMatDinamica(qntL, qntC), *transposta;

  LerMatDinamica(qntL, qntC, mat);
  transposta = ConverteMat(qntL, qntC, mat);
  ImprimeMatLinear(qntL, qntC, transposta);

  LiberaMat(mat, qntL);
  
  
  
  return 0;
}
