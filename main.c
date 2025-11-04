#include <stdio.h>

int elevado(int base, int expoente){
    int resultado = 1;
    for(int i=0; i<expoente; i++){
        resultado*= base;
    }
    return resultado;
}
int calcularDet(int ordem, int matrizA[][ordem]){
    int determinante = 0, encontrado;
    int matrizM[ordem-1][ordem-1];
    
    for(int i=0; i<ordem-1; i++){
        for(int j=0; j<ordem-1; j++){
            matrizM[i][j] = 0;
        }
    }
    
    for(int j=0; j<ordem; j++){
        for(int k=0; k<ordem-1; k++){
            int m = 0;
            for(int l=0; l<ordem-1; l++){
                int encontrou = 0;
                while(encontrou == 0){
                    if(m != j){
                        matrizM[k][l] = matrizA[k+1][m];
                        encontrou++;
                    }
                    m++;
                }
                //printf("%d ", matrizM[k][l]);
            }
            //printf("\n");
        }
        if (ordem > 1)
        determinante += matrizA[0][j]*elevado(-1, j+2)*calcularDet(ordem-1, matrizM);
        else
        determinante = matrizA[0][0];
    }
    
    return determinante;
}

int main() {
    int ordem, determinante;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);
    
    int matrizA[ordem][ordem];
    
    printf("\n");
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            printf("a%d%d ", i+1, j+1);
        }
        printf("\n");
    }
    
    printf("\n");
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }
    
    determinante = calcularDet(ordem, matrizA);
    
    printf("\n%d", determinante);
    
    return 0;
}