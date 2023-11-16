//Problema 1: Matriz 5x7 y que realiza operaciones

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 7

void matrices(int matriz[FILAS][COLUMNAS]) {
    srand(time(NULL)); 
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 10; 
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaDiagonal(int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;
    for (i = 0; i < FILAS && i < COLUMNAS; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

int sumaPrimeraFila(int matriz[FILAS][COLUMNAS]) {
    int j, suma = 0;
    for (j = 0; j < COLUMNAS; j++) {
        suma += matriz[0][j];
    }
    return suma;
}

int sumaUltimaColumna(int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;
    for (i = 0; i < FILAS; i++) {
        suma += matriz[i][COLUMNAS - 1];
    }
    return suma;
}

void sumaCadaFila(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma;
    printf("Suma de cada fila:\n");
    for (i = 0; i < FILAS; i++) {
        suma = 0;
        for (j = 0; j < COLUMNAS; j++) {
            suma+= matriz[i][j];
        }
        printf("Fila %d: %d\n", i + 1, suma);
    }
}

void sumaCadaColumna(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma;
    printf("Suma de cada columna:\n");
    for (j = 0; j < COLUMNAS; j++) {
        suma = 0;
        for (i = 0; i < FILAS; i++) {
            suma+= matriz[i][j];
        }
        printf("Columna %d: %d\n", j + 1, suma);
    }
}

int sumaFilasPares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (i = 1; i < FILAS; i += 2) {
        for (j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaColumnasImpares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (j = 0; j < COLUMNAS; j += 2) {
        for (i = 0; i < FILAS; i++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaFilasImpares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (i = 1; i < FILAS; i += 2) {
        for (j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaColumnasPares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (j = 0; j < COLUMNAS; j += 2) {
        for (i = 0; i < FILAS; i++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangularSuperior(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = i; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangularInferior(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j <= i; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int main() {
    int matriz[FILAS][COLUMNAS];

    printf("Matriz generada:\n");
    matrices(matriz);

    printf("\nSuma de la diagonal principal: %d\n", sumaDiagonal(matriz));
    printf("Suma de la primera fila: %d\n", sumaPrimeraFila(matriz));
    printf("Suma de la ultima columna: %d\n", sumaUltimaColumna(matriz));
    printf("----------------------\n");
    
	sumaCadaFila(matriz); 
    printf("Suma de las filas pares (Filas 2 y 4): %d\n", sumaFilasPares(matriz));
    printf("----------------------\n");
    
	sumaCadaColumna(matriz); 
    printf("Suma de las columnas impares (Columas 1,3,5 y 7): %d\n", sumaColumnasImpares(matriz));
    printf("----------------------\n");
	
	printf("Suma de la diagonal: %d\n", sumaDiagonal(matriz));
    printf("Suma del triangular superior: %d\n", sumaTriangularSuperior(matriz));
    
	printf("----------------------\n");
	printf("Suma de la diagonal: %d\n", sumaDiagonal(matriz));
	printf("Suma del triangular inferior: %d\n", sumaTriangularInferior(matriz));

    return 0;
}


