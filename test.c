#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 희소 행렬 구조체 정의
typedef struct {
    int row;
    int col;
    int value;
} Sparse;

// 💡 일반 행렬 출력
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 💡 전치 행렬 만들기 (행과 열 바꾸기)
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; // 💡행렬 전치!
        }
    }
}

// 💡 일반 행렬 → 희소 행렬로 바꾸기
int convertToSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, Sparse sparse[MAX_SIZE]) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++; // 💡0이 아닌 값만 저장
            }
        }
    }
    return k;
}

// 💡 희소 행렬 출력
void printSparse(Sparse sparse[MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) -> %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

// 💡 희소 행렬 비교 (같은지 확인)
int compareSparse(Sparse a[MAX_SIZE], int aSize, Sparse b[MAX_SIZE], int bSize) {
    if (aSize != bSize) return 0;

    for (int i = 0; i < aSize; i++) {
        if (a[i].row != b[i].row || a[i].col != b[i].col || a[i].value != b[i].value) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    Sparse sparse1[MAX_SIZE], sparse2[MAX_SIZE], sparse3[MAX_SIZE];
    int sparse1Size, sparse2Size, sparse3Size;

    // 💬 사용자에게 행렬 크기 입력받기
    printf("행렬의 행 수를 입력하세요: ");
    scanf("%d", &rows);
    printf("행렬의 열 수를 입력하세요: ");
    scanf("%d", &cols);

    // 💬 행렬 데이터 입력
    printf("행렬의 요소를 입력하세요 (각 요소를 공백으로 구분):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 1. 입력한 행렬 출력
    printf("\n1. 입력한 행렬:\n");
    printMatrix(matrix, rows, cols);

    // 2. 💡 전치 행렬 만들기 & 출력
    transposeMatrix(matrix, rows, cols, transposed);
    printf("\n2. 전치 행렬:\n");
    printMatrix(transposed, cols, rows);

    // 3. 💡 입력 행렬을 희소 행렬로 바꾸기
    sparse1Size = convertToSparse(matrix, rows, cols, sparse1);
    printf("\n3. 입력 행렬의 희소 표현:\n");
    printSparse(sparse1, sparse1Size);

    // 4. 💡 전치 행렬도 희소 행렬로 바꾸기
    sparse2Size = convertToSparse(transposed, cols, rows, sparse2);
    printf("\n4. 전치 행렬의 희소 표현:\n");
    printSparse(sparse2, sparse2Size);

    // 5. 💡 전치 희소 행렬을 따로 또 만들기 (사실 4와 동일)
    sparse3Size = convertToSparse(transposed, cols, rows, sparse3);
    printf("\n5. 희소 행렬의 전치:\n");
    printSparse(sparse3, sparse3Size);

    // 6. 💡 희소 전치 결과 비교
    if (compareSparse(sparse3, sparse3Size, sparse2, sparse2Size)) {
        printf("\n6. 결과: 같습니다\n");
    } else {
        printf("\n6. 결과: 틀립니다\n");
    }

    return 0;
}
