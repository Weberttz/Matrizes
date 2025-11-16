#include <stdio.h>

int elevado(int base, int expoente){
    int resultado = 1;
    for(int i=0; i<expoente; i++){
        resultado*= base;
    }
    return resultado;
}

int calcularDet(int ordem, float matrizA[][ordem]){
    int determinante = 0;
    float matrizM[ordem-1][ordem-1];
    
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
            }
        }
        if (ordem > 1)
            determinante += matrizA[0][j]*elevado(-1, j+2)*calcularDet(ordem-1, matrizM);
        else
            determinante = matrizA[0][0];
    }
    
    return determinante;
}

void calcularInversa(int det, int ordem, float matrizAdjunta[][ordem]){
    float matrizInversa[ordem][ordem];
    
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            matrizInversa[i][j] = matrizAdjunta[j][i]/det;
            if(matrizInversa[i][j] == -0)
                matrizInversa[i][j] = 0;
        }
    }

    for(int i=0; i<ordem; i++){
        for(int j = 0; j<ordem; j++){
            printf("%.2f ", matrizInversa[i][j]);
        }
        printf("\n");
    }
}

void calcularAdjunta(int ordem, float matrizA[][ordem]){
    float matrizAdjunta[ordem][ordem];
    float matrizAux[ordem-1][ordem-1];
    int det = calcularDet(ordem, matrizA);

    printf("\n");
    for(int i = 0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            for(int k=0; k<ordem-1; k++){
                int m = 0;
                for(int l=0; l<ordem-1; l++){
                    int encontrou = 0, n = 0;
                    while(encontrou == 0){
                        if(m != i){
                            int encontrou2 = 0;
                            while(encontrou2 == 0){
                                if(n != j){
                                    matrizAux[k][l] = matrizA[m][n];
                                    encontrou2++;
                                    encontrou++;
                                }
                                n++;
                            }
                        }
                        m++;
                    }
                }
            }
            matrizAdjunta[i][j] = elevado(-1, i+j+2)*calcularDet(ordem-1, matrizAux);
        }
    }

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            printf("%.2f ", matrizAdjunta[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    calcularInversa(det, ordem, matrizAdjunta);
}

int main() {
    int ordem, determinante;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);
    
    float matrizA[ordem][ordem];
    
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
            scanf("%f", &matrizA[i][j]);
        }
    }
    
    determinante = calcularDet(ordem, matrizA);
    if(determinante != 0)
        calcularAdjunta(ordem, matrizA);
    else{
        printf("Essa matriz nao e invertivel");
        return 0;
    }
    
    return 0;
}