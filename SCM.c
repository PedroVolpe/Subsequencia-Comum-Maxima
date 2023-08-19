#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SCM(char* X, char* Y, int m, int n, int** c, char** b) {
    int i, j;
    for (i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '-';
            } else {
                if (c[i][j - 1] > c[i - 1][j]) {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = '<';
                } else {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = '^';
                }
            }
        }
    }
  return c[m][n];
}

int main() {
    int tamX;
    printf("Informe o tamanho maximo da primeira subsequencia: ");
    scanf("%d", &tamX);

    int tamY;
    printf("Informe o tamanho maximo da segunda subsequencia: ");
    scanf("%d", &tamY);
  
    char X[tamX]; 
    char Y[tamY]; 
  
    printf("Informe a primeira Subsequencia: ");
    scanf("%s", X);
  
    printf("Informe a segunda Subsequencia: ");
    scanf("%s", Y);

    int** c = (int**)malloc((tamX + 1) * sizeof(int*));
    char** b = (char**)malloc((tamX + 1) * sizeof(char*));

    for (int i = 0; i <= tamX; i++) {
        c[i] = (int*)malloc((tamY + 1) * sizeof(int));
        b[i] = (char*)malloc((tamY + 1) * sizeof(char));
    }

    int res = SCM(X, Y, tamX, tamY, c, b);
  
    printf("\nA Subsequência Comum Máxima é de: %d caracteres",res);
  
  
    for (int i = 0; i <= tamX; i++) {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);

    return 0;
}