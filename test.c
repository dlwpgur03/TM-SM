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
