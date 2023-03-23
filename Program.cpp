#include <stdio.h>
#include<stdlib.h>
#include<conio.h> //I added this library for getche method.

void modifyMatrix(int matrix[3][3]) { // modifyMatrix function negates each element in the input matrix.
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = -matrix[i][j];
        }
    }
}

void transpose(int matrix[3][3], int result[3][3]) { // transpose function computes the transpose of the input matrix and stores it in the result matrix.
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void findMaxInRow(int matrix[3][3]) { //The function finds the largest element in each row in a 3x3 matrix and prints it to the screen.
    int i, j;
    int max;

    printf("Maximum element in each row: \n");

    for (i = 0; i < 3; i++) {
        max = matrix[i][0];

        for (j = 1; j < 3; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }

        printf("Row %d: %d\n", i + 1, max);
    }
}

int isSymmetric(int matrix[3][3]) {//The isSymmetric function checks if a 3x3 matrix is ??symmetric and returns a value of 1 or 0. Returns 1 if the matrix is symmetrical, 0 otherwise.
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int determinant(int matrix[3][3]) { //determinant function calculates the determinant of the matrix.
    int det;

    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
          - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2])
          + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

    return det;
}

void inverse(int arr[3][3], float inv[3][3]) {//This method computes the inverse of the matrix
    float det = determinant(arr);
    if (det == 0) {
        printf("The matrix is not invertible.\n");
        return;
    }
    
    inv[0][0] = (arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) / det;
    inv[0][1] = (arr[0][2]*arr[2][1] - arr[0][1]*arr[2][2]) / det;
    inv[0][2] = (arr[0][1]*arr[1][2] - arr[0][2]*arr[1][1]) / det;
    inv[1][0] = (arr[1][2]*arr[2][0] - arr[1][0]*arr[2][2]) / det;
    inv[1][1] = (arr[0][0]*arr[2][2] - arr[0][2]*arr[2][0]) / det;
    inv[1][2] = (arr[0][2]*arr[1][0] - arr[0][0]*arr[1][2]) / det;
    inv[2][0] = (arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]) / det;
    inv[2][1] = (arr[0][1]*arr[2][0] - arr[0][0]*arr[2][1]) / det;
    inv[2][2] = (arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0]) / det;
    
    int i,j;
    printf("The matrix is :\n");
    for (i = 0; i < 3; i++) {
    	printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%.2f\t", inv[i][j]);
        }
        printf("\n");
    }
}

void display(int matrix[3] [3]) {
	int i,j;
    printf("The matrix is :\n");
    for (i = 0; i < 3; i++) {
    	printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][3]; //I defined variables.
    int transposed_matrix[3][3];
    float inverse_matrix[3][3];
    int i, j;
    
    printf("Enter the elements of a 3x3 matrix:\n"); //I took the first matrix as input
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    display(matrix);
    while(true){ //while loop to keep the program in the loop
        printf("\nChoose an operation to perform on the matrix:\n");
    	printf("[a] Modify matrix\n");
    	printf("[b] Transpose matrix\n");
    	printf("[c] Find maximum element in each row\n");
    	printf("[d] Check if matrix is symmetric\n");
    	printf("[e] Find determinant of matrix\n");
    	printf("[f] Find inverse of matrix\n");
    	printf("[g] Display the matrix\n");
    	printf("[q] Quit\n");
    	char choose;
    	//choose = getche(); //I tried the getche method here, but removed it for ease of use.
        scanf(" %c",&choose);
        switch (choose)
        {
        case 'a':
            modifyMatrix(matrix);
            display(matrix);
            break; 
         case 'b':
			transpose(matrix,transposed_matrix);
			display(transposed_matrix);
            break;
         case 'c':
            findMaxInRow(matrix);
            break;
         case 'd':
            printf("\nOutput due to matrix symmetry : %d \n",isSymmetric(matrix));
            break;
         case 'e':
            printf("%d",determinant(matrix));
            break;
         case 'f':
            inverse(matrix,inverse_matrix);
            break;
        case 'g':
            display(matrix);
            break;
         case 'q':
         	printf("Logged out...");
            exit(0);
            break;
        default:
        	printf("Wrong operation");
            break;
        }
    }

    return 0;
}
