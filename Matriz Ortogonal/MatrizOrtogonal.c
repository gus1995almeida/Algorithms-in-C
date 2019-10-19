#include <stdio.h>

int generateMatrix(int matrix[3][3]){

    FILE *entryFile;

    entryFile = fopen("MatrizM.txt", "r");

    if(entryFile != NULL){

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

            fscanf(entryFile, "%d", &matrix[i][j]);

            }
        }

         fclose(entryFile);
         return 1;

    }else{

        return 0;

    }
      
}

void ftransposedMatrix(int matrix[3][3], int transposedMatrix[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            transposedMatrix[j][i] = matrix[i][j];

        }
    }

}

void fmultiplicationMatrix(int matrix[3][3], int transposedMatrix[3][3], int multiplicationMatrix[3][3]){

    int sum = 0, result;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            for(int k = 0; k < 3; k ++){

                result = matrix[i][k] * transposedMatrix[k][j];
                sum = sum + result;

            }

            multiplicationMatrix[i][j] = sum;
            sum = 0;

        }
    }

}

int orthogonalMatrix(int multiplicationMatrix[3][3]){

    int flag = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            if(i != j){

                if(multiplicationMatrix[i][j] != 0){

                    return (flag = 1);

                }

            }else{

                if(multiplicationMatrix[i][j] != 1){

                    flag = 1;
                    return flag;

                }

            }

        }
    }

    return flag;

}

void main(){

    int number;
    int matrix[3][3], transposedMatrix[3][3], multiplicationMatrix[3][3];
    
    if(generateMatrix(matrix)){

        ftransposedMatrix(matrix, transposedMatrix);
        fmultiplicationMatrix(matrix, transposedMatrix, multiplicationMatrix);
    
        if(orthogonalMatrix(multiplicationMatrix)){

            printf("A matriz nao e ORTOGONAL!");

        }else{

            printf("A matriz e ORTOGONAL!");

        }

    }else{

        printf("Arquivo Inexistente!");

    }
    

}

