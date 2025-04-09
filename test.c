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
    // 행렬 크기와 반복문을 위한 변수 선언
    int row, col; // 행렬 A의 행과 열 개수
    int i, j;     // 반복문 변수

    // 1. 행렬 크기와 행렬 A 입력
    printf("행과 열을 입력하세요: "); // 입력 요청 메시지
    scanf("%d %d", &row, &col);       // 행과 열 입력 받기

    int a[row][col];                  // 행렬 A 선언
    printf("행렬 A를 입력하세요:\n"); // 행렬 입력 요청 메시지
    for (i = 0; i < row; i++)         // 행 반복
        for (j = 0; j < col; j++)     // 열 반복
            scanf("%d", &a[i][j]);    // 행렬 요소 입력

    // 2. 행렬 A 출력
    printf("\n[행렬 A 출력]\n"); // 출력 제목
    for (i = 0; i < row; i++)    // 행 반복
    {
        for (j = 0; j < col; j++)    // 열 반복
            printf("%3d ", a[i][j]); // 요소 출력 (간격 조정 포함)
        printf("\n");                // 다음 행으로 이동
    }

    // 3. 행렬 A의 전치 행렬 생성
    int at[col][row];             // 전치 행렬 A^T 선언
    for (i = 0; i < row; i++)     // 행렬 A의 행 반복
        for (j = 0; j < col; j++) // 행렬 A의 열 반복
            at[j][i] = a[i][j];   // 전치된 요소 할당

    printf("\n[전치 행렬 A^T 출력]\n"); // 출력 제목
    for (i = 0; i < col; i++)           // 전치 행렬의 행 반복
    {
        for (j = 0; j < row; j++)     // 전치 행렬의 열 반복
            printf("%3d ", at[i][j]); // 요소 출력 (간격 조정 포함)
        printf("\n");                 // 다음 행으로 이동
    }

    // 4. 행렬 A 희소화
    int sparseA[row * col][3];    // 희소 행렬 표현 선언
    int countA = 0;               // 0이 아닌 요소 개수 초기화
    for (i = 0; i < row; i++)     // 행렬 A의 행 반복
        for (j = 0; j < col; j++) // 행렬 A의 열 반복
            if (a[i][j] != 0)     // 0이 아닌 요소 확인
            {
                sparseA[countA][0] = i;       // 행 인덱스 저장
                sparseA[countA][1] = j;       // 열 인덱스 저장
                sparseA[countA][2] = a[i][j]; // 값 저장
                countA++;                     // 개수 증가
            }

    printf("\n[희소 행렬 A 출력]\n");                                          // 출력 제목
    for (i = 0; i < countA; i++)                                               // 희소 행렬 반복
        printf("(%d, %d, %d)\n", sparseA[i][0], sparseA[i][1], sparseA[i][2]); // 행, 열, 값 출력

    // 5. 전치 행렬 A^T 희소화
    int sparseAT[row * col][3];   // 전치 행렬 희소 표현 선언
    int countAT = 0;              // 전치 행렬의 0이 아닌 요소 개수 초기화
    for (i = 0; i < col; i++)     // 전치 행렬의 행 반복
        for (j = 0; j < row; j++) // 전치 행렬의 열 반복
            if (at[i][j] != 0)    // 0이 아닌 요소 확인
            {
                sparseAT[countAT][0] = i;        // 행 인덱스 저장
                sparseAT[countAT][1] = j;        // 열 인덱스 저장
                sparseAT[countAT][2] = at[i][j]; // 값 저장
                countAT++;                       // 개수 증가
            }

    printf("\n[전치 후 희소 행렬 출력]\n");                                       // 출력 제목
    for (i = 0; i < countAT; i++)                                                 // 희소 행렬 반복
        printf("(%d, %d, %d)\n", sparseAT[i][0], sparseAT[i][1], sparseAT[i][2]); // 행, 열, 값 출력

    // 6. 희소 행렬 A의 전치
    int transSparseA[row * col][3]; // 희소 행렬 전치 선언
    for (i = 0; i < countA; i++)    // 희소 행렬 반복
    {
        transSparseA[i][0] = sparseA[i][1]; // 행과 열 인덱스 교환
        transSparseA[i][1] = sparseA[i][0];
        transSparseA[i][2] = sparseA[i][2]; // 값 유지
    }

    printf("\n[희소 후 전치 행렬 출력]\n");                                                   // 출력 제목
    for (i = 0; i < countA; i++)                                                              // 희소 전치 행렬 반복
        printf("(%d, %d, %d)\n", transSparseA[i][0], transSparseA[i][1], transSparseA[i][2]); // 행, 열, 값 출력

    // 7. 두 희소 전치 결과 비교
    int same = 1;          // 두 전치 결과가 같은지 여부를 나타내는 플래그
    if (countA != countAT) // 개수가 다른지 확인
    {
        same = 0; // 플래그를 false로 설정
    }
    else
    {
        for (i = 0; i < countA; i++) // 첫 번째 희소 전치 반복
        {
            int found = 0;                // 요소가 발견되었는지 확인하는 플래그
            for (j = 0; j < countAT; j++) // 두 번째 희소 전치 반복
            {
                if (transSparseA[i][0] == sparseAT[j][0] && // 행 인덱스 비교
                    transSparseA[i][1] == sparseAT[j][1] && // 열 인덱스 비교
                    transSparseA[i][2] == sparseAT[j][2])   // 값 비교
                {
                    found = 1; // 요소 발견
                    break;
                }
            }
            if (!found) // 요소가 발견되지 않으면 플래그를 false로 설정
            {
                same = 0;
                break;
            }
        }
    }

    printf("\n[비교 결과]\n"); // 비교 결과 출력
    if (same)
        printf("같습니다.\n"); // 희소 전치 결과가 같으면 출력
    else
        printf("다릅니다.\n"); // 희소 전치 결과가 다르면 출력

    return 0; // 프로그램 종료
}
