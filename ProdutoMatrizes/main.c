#include <stdio.h>

int main() {
    int linhas1, linhas2, colunas1, colunas2;
    
    printf("Digite a quantidade de linhas da matriz I: ");
    scanf("%d", &linhas1);
    printf("Digite a quantidade de colunas da matriz I: ");
    scanf("%d%*c", &colunas1);
    
    printf("Digite a quantidade de linhas da matriz II: ");
    scanf("%d", &linhas2);
    printf("Digite a quantidade de colunas da matriz II: ");
    scanf("%d%*c", &colunas2);
    
    if(linhas2 == colunas1){
        int matriz1[linhas1][colunas1], matriz2[linhas2][colunas2], matriz3[linhas1][colunas2];
        
        printf("\nDigite a matriz I com a seguinte configuracao:\n\n");
        for(int i = 0; i<linhas1; i++){
            for(int j=0; j<colunas1; j++){
                printf("a%d%d ", i+1, j+1);
            }
            printf("\n");
        }
        
        printf("\n");
        for(int i=0; i<linhas1; i++){
            for(int j=0; j<linhas1; j++){
                scanf("%d", &matriz1[i][j]);
            }
        }
        
        
        printf("\nDigite a matriz II com a seguinte configuracao:\n\n");
        for(int i = 0; i<linhas2; i++){
            for(int j=0; j<colunas2; j++){
                printf("a%d%d ", i+1, j+1);
            }
            printf("\n");
        }
        
        printf("\n");
        for(int i=0; i<linhas2; i++){
            for(int j=0; j<colunas2; j++){
                scanf("%d", &matriz2[i][j]);
            }
        }
        
        for(int i=0; i<linhas1; i++){
            for(int j=0; j<colunas2; j++){
                int temp = 0;
                for(int k = 0; k < colunas2; k++){
                    temp += matriz1[i][k] * matriz2[k][j];
                }
                matriz3[i][j] = temp;
            }
        }

        printf("\n\n");
        for(int i=0; i<linhas1; i++){
            for(int j = 0; j<colunas2; j++)
                printf("%d ", matriz3[i][j]);
            
            printf("\n");
        }
        
        
    }else printf("\nImpossivel fazer a nultiplicacao");
    return 0;
}