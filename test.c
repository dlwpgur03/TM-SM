// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// // 희소 행렬 구조체 정의
// typedef struct {
//     int row;
//     int col;
//     int value;
// } Sparse;

// // 💡 일반 행렬 출력
// void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// // 💡 전치 행렬 만들기 (행과 열 바꾸기)
// void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             transposed[j][i] = matrix[i][j]; // 💡행렬 전치!
//         }
//     }
// }

// // 💡 일반 행렬 → 희소 행렬로 바꾸기
// int convertToSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, Sparse sparse[MAX_SIZE]) {
//     int k = 0;
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             if (matrix[i][j] != 0) {
//                 sparse[k].row = i;
//                 sparse[k].col = j;
//                 sparse[k].value = matrix[i][j];
//                 k++; // 💡0이 아닌 값만 저장
//             }
//         }
//     }
//     return k;
// }

// // 💡 희소 행렬 출력
// void printSparse(Sparse sparse[MAX_SIZE], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("(%d, %d) -> %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
//     }
// }

// // 💡 희소 행렬을 직접 전치시키기
// int transposeSparse(Sparse input[MAX_SIZE], int size, Sparse output[MAX_SIZE]) {
//     for (int i = 0; i < size; i++) {
//         output[i].row = input[i].col;   // 행 <-> 열 교환
//         output[i].col = input[i].row;
//         output[i].value = input[i].value;
//     }
//     return size;
// }

// // 💡 희소 행렬 비교 (같은지 확인)
// int compareSparse(Sparse a[MAX_SIZE], int aSize, Sparse b[MAX_SIZE], int bSize) {
//     if (aSize != bSize) return 0;

//     for (int i = 0; i < aSize; i++) {
//         if (a[i].row != b[i].row || a[i].col != b[i].col || a[i].value != b[i].value) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main() {
//     int rows, cols;
//     int matrix[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
//     Sparse sparse1[MAX_SIZE], sparse2[MAX_SIZE], sparse3[MAX_SIZE];
//     int sparse1Size, sparse2Size, sparse3Size;

//     // 💬 사용자에게 행렬 크기 입력받기
//     printf("행렬의 행 수를 입력하세요: ");
//     scanf("%d", &rows);
//     printf("행렬의 열 수를 입력하세요: ");
//     scanf("%d", &cols);

//     // 💬 행렬 데이터 입력
//     printf("행렬의 요소를 입력하세요 (각 요소를 공백으로 구분):\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     // 1. 입력한 행렬 출력
//     printf("\n1. 입력한 행렬:\n");
//     printMatrix(matrix, rows, cols);

//     // 2. 💡 전치 행렬 만들기 & 출력
//     transposeMatrix(matrix, rows, cols, transposed);
//     printf("\n2. 전치 행렬:\n");
//     printMatrix(transposed, cols, rows);

//     // 3. 💡 입력 행렬을 희소 행렬로 바꾸기
//     sparse1Size = convertToSparse(matrix, rows, cols, sparse1);
//     printf("\n3. 입력 행렬의 희소 표현:\n");
//     printSparse(sparse1, sparse1Size);

//     // 4. 💡 전치 행렬도 희소 행렬로 바꾸기
//     sparse2Size = convertToSparse(transposed, cols, rows, sparse2);
//     printf("\n4. 전치 행렬의 희소 표현:\n");
//     printSparse(sparse2, sparse2Size);

//     // 5. 💡 희소 행렬을 직접 전치시키기
//     sparse3Size = transposeSparse(sparse1, sparse1Size, sparse3);
//     printf("\n5. 희소 행렬의 전치:\n");
//     printSparse(sparse3, sparse3Size);

//     // 6. 💡 희소 전치 결과 비교
//     if (compareSparse(sparse3, sparse3Size, sparse2, sparse2Size)) {
//         printf("\n6. 결과: 같습니다\n");
//     } else {
//         printf("\n6. 결과: 틀립니다\n");
//     }

//     return 0;
// }

//--------------------------------------------------------------------------------------------------------

// #include <stdio.h>

// void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }
// }

// void printMatrix(int rows, int cols, int matrix[rows][cols]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             transposed[j][i] = matrix[i][j];
//         }
//     }
// }

// void sparseMatrix(int rows, int cols, int matrix[rows][cols], int sparse[rows][cols]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             sparse[i][j] = (matrix[i][j] != 0) ? matrix[i][j] : 0;
//         }
//     }
// }

// int compareMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             if (matrix1[i][j] != matrix2[i][j]) {
//                 return 0; // 다름
//             }
//         }
//     }
//     return 1; // 같음
// }

// int main() {
//     int rows, cols;
//     printf("행렬의 행과 열 크기를 입력하세요: ");
//     scanf("%d %d", &rows, &cols);

//     int matrix[rows][cols], transposed[cols][rows], sparse[rows][cols], sparseTransposed[cols][rows];

//     printf("행렬 A를 입력하세요:\n");
//     inputMatrix(rows, cols, matrix);

//     printf("입력한 행렬 A:\n");
//     printMatrix(rows, cols, matrix);

//     transposeMatrix(rows, cols, matrix, transposed);
//     printf("행렬 A의 전치 행렬:\n");
//     printMatrix(cols, rows, transposed);

//     sparseMatrix(rows, cols, matrix, sparse);
//     printf("행렬 A의 희소 행렬:\n");
//     printMatrix(rows, cols, sparse);

//     sparseMatrix(cols, rows, transposed, sparseTransposed);
//     printf("행렬 A의 전치 행렬의 희소 행렬:\n");
//     printMatrix(cols, rows, sparseTransposed);

//     int areEqual = compareMatrices(rows, cols, sparse, transposed);
//     printf("희소 행렬과 전치 행렬 비교 결과: %s\n", areEqual ? "같습니다" : "다릅니다");

//     return 0;
// }

//--------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
    int row, col;
    int i, j;

    // 1. 행렬 A 입력
    printf("행과 열을 입력하세요: ");
    scanf("%d %d", &row, &col);

    int a[row][col];
    printf("행렬 A를 입력하세요:\n");
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    // 2. 행렬 A 출력
    printf("\n[행렬 A 출력]\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }

    // 3. 전치 행렬 만들기
    int at[col][row];
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            at[j][i] = a[i][j];

    printf("\n[전치 행렬 A^T 출력]\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
            printf("%3d ", at[i][j]);
        printf("\n");
    }

    // 4. 행렬 A 희소화
    int sparseA[row * col][3];
    int countA = 0;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (a[i][j] != 0)
            {
                sparseA[countA][0] = i;
                sparseA[countA][1] = j;
                sparseA[countA][2] = a[i][j];
                countA++;
            }

    printf("\n[희소 행렬 A 출력]\n");
    for (i = 0; i < countA; i++)
        printf("(%d, %d, %d)\n", sparseA[i][0], sparseA[i][1], sparseA[i][2]);

    // 5. 전치한 행렬 at → 희소화
    int sparseAT[row * col][3];
    int countAT = 0;
    for (i = 0; i < col; i++)
        for (j = 0; j < row; j++)
            if (at[i][j] != 0)
            {
                sparseAT[countAT][0] = i;
                sparseAT[countAT][1] = j;
                sparseAT[countAT][2] = at[i][j];
                countAT++;
            }

    printf("\n[전치 후 희소 행렬 출력]\n");
    for (i = 0; i < countAT; i++)
        printf("(%d, %d, %d)\n", sparseAT[i][0], sparseAT[i][1], sparseAT[i][2]);

    // 6. 희소 행렬 A → 전치
    int transSparseA[row * col][3];
    for (i = 0; i < countA; i++)
    {
        transSparseA[i][0] = sparseA[i][1]; // col
        transSparseA[i][1] = sparseA[i][0]; // row
        transSparseA[i][2] = sparseA[i][2]; // value
    }

    printf("\n[희소 후 전치 행렬 출력]\n");
    for (i = 0; i < countA; i++)
        printf("(%d, %d, %d)\n", transSparseA[i][0], transSparseA[i][1], transSparseA[i][2]);

    // 7. 두 희소 전치 결과 비교
    int same = 1;
    if (countA != countAT)
    {
        same = 0;
    }
    else
    {
        for (i = 0; i < countA; i++)
        {
            int found = 0;
            for (j = 0; j < countAT; j++)
            {
                if (transSparseA[i][0] == sparseAT[j][0] &&
                    transSparseA[i][1] == sparseAT[j][1] &&
                    transSparseA[i][2] == sparseAT[j][2])
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                same = 0;
                break;
            }
        }
    }

    printf("\n[비교 결과]\n");
    if (same)
        printf("같습니다.\n");
    else
        printf("다릅니다.\n");

    return 0;
}
