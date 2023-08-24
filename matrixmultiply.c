#include <stdio.h>

int main (){

    //get dimensions of first matrix
    int rowNumber = 0;
    int columnNumber = 0;
    printf("How many rows will the first matrix have?\n");
    scanf("%d", &rowNumber);
    printf("How many columns will the first matrix have?\n");
    scanf("%d", &columnNumber);

    //get contents of first matrix
    int firstMatrix [rowNumber][columnNumber];
    for (int i = 0; i<rowNumber; i++){
        for (int j = 0; j<columnNumber; j++){
            printf("What is the entry in the first matrix at row %d and column %d?\n", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    //get dimensions of second matrix and ensure compatability with those of first matrix
    printf("How many rows will the second matrix have?\n");
    scanf("%d", &rowNumber);
    if (rowNumber != columnNumber) {
        printf("Incompatible matrix dimensions");
        return 0;
    }
    printf("How many columns will the second matrix have?\n");
    scanf("%d", &columnNumber);

    //get contents of second matrix
    int secondMatrix[rowNumber][columnNumber];
    for (int i = 0; i<rowNumber; i++){
        for (int j = 0; j<columnNumber; j++){
            printf("What is the entry in the first matrix at row %d and column %d?\n", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    //perform matrix multiplication
    int multipliedMatrix [sizeof(firstMatrix)/sizeof(firstMatrix[0])][sizeof(secondMatrix[0])/sizeof(secondMatrix[0][0])];
    for (int i=0; i<sizeof(firstMatrix)/sizeof(firstMatrix[0]); i++){
        for (int j=0; j<sizeof(secondMatrix[0])/sizeof(secondMatrix[0][0]); j++){
            int sum = 0;
            for (int k=0; k<sizeof(firstMatrix[0])/sizeof(firstMatrix[0][0]); k++) {
                sum = sum + (firstMatrix[i][k] * secondMatrix[k][j]);
            }
            multipliedMatrix[i][j] = sum;
        }
    }

    //print first matrix
    printf("First Matrix:\n");
    for (int i=0; i<sizeof(firstMatrix)/sizeof(firstMatrix[0]); i++){
        for (int j=0; j<sizeof(firstMatrix[0])/sizeof(firstMatrix[0][0]); j++){
            printf("%d ", firstMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //print second matrix
    printf("Second Matrix:\n");
    for (int i=0; i<sizeof(secondMatrix)/sizeof(secondMatrix[0]); i++){
        for (int j=0; j<sizeof(secondMatrix[0])/sizeof(secondMatrix[0][0]); j++){
            printf("%d ", secondMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //print resulting matrix
    printf("Result:\n");
    for (int i=0; i<sizeof(multipliedMatrix)/sizeof(multipliedMatrix[0]); i++){
        for (int j=0; j<sizeof(multipliedMatrix[0])/sizeof(multipliedMatrix[0][0]); j++){
            printf("%d ", multipliedMatrix[i][j]);
        }
        printf("\n");
    }
}