//Matriz mágica

#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    int i,j;
	printf("Matriz:\n");
    for ( i = 0; i < FILAS; i++) {
        int sumaFila = 0;
        for ( j = 0; j < COLUMNAS; j++) {
            printf("  %d  ", matriz[i][j]);
            sumaFila += matriz[i][j];
        }
        printf("\n");
    }
    
	for ( i = 0; i < FILAS; i++) {
        int sumaFila = 0;
        for ( j = 0; j < COLUMNAS; j++) {
            sumaFila += matriz[i][j];
        }
        printf("Suma fila %d: %d\n", i + 1, sumaFila);
    }
        
    for ( j = 0; j < COLUMNAS; j++) {
        int sumaColumna = 0;
        for ( i = 0; i < FILAS; i++) {
            sumaColumna += matriz[i][j];
        }
        printf("Suma columna %d: %d  \n", j + 1, sumaColumna);
    }
    printf("\n");
}

int esMatrizMagica(int matriz[FILAS][COLUMNAS]) {
   	int i,j,k=0;
    int suma = 0;
    int sumas[FILAS + COLUMNAS + 2] = {0}; 

    
    for ( j = 0; j < COLUMNAS; j++) {
        suma += matriz[0][j];
    }

    for ( i = 0; i < FILAS; i++) {
        int sumaFila = 0;
        int sumaColumna = 0;

        for ( j = 0; j < COLUMNAS; j++) {
            sumaFila += matriz[i][j]; 
            sumaColumna += matriz[j][i]; 
            if (i == j) {
                sumas[FILAS + COLUMNAS] += matriz[i][j]; 
            }
            if (i + j == FILAS - 1) {
                sumas[FILAS + COLUMNAS + 1] += matriz[i][j]; 
            }
        }

        sumas[k++] = sumaFila; 
        sumas[k++] = sumaColumna; 
    }

    for ( i = 1; i < FILAS + COLUMNAS + 2; i++) {
        if (sumas[i] != suma) {
            return 0; 
        }
    }

    return 1; 
}

int sumaDiagonal(int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;
    for (i = 0; i < FILAS && i < COLUMNAS; i++) {
        suma += matriz[i][i];
    }
    return suma;
}
int sumaDiagonaldos(int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;
    for (i = 0; i < FILAS && i < COLUMNAS; i++) {
        suma += matriz[i][COLUMNAS - i - 1];
    }
    return suma;
}
int main() {
    int i,j,k;
	int matriz[FILAS][COLUMNAS];

    printf("Ingrese los valores para la matriz 3x3:\n");

    for ( i = 0; i < FILAS; i++) {
        for ( j = 0; j < COLUMNAS; j++) {
            printf("Ingrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
    imprimirMatriz(matriz);
	printf("Suma de la diagonal: %d\n", sumaDiagonal(matriz));
    printf("Suma de la diagonal secundaria: %d\n", sumaDiagonaldos(matriz));
	if (esMatrizMagica(matriz)) {
        printf("\nLa matriz es magica\n");
    } else {
        printf("\n La matriz NO es magica.\n");
    }

    return 0;
}


