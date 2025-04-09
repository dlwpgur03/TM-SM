#include <stdio.h>

int main()
{

    int row, col;
    int i, j;

    // 행렬 입력
    printf("행과 열을 입력하시오.(최대 10씩)");
    if (scanf("%d %d", &row, &col) != 2 || row <= 0 || col <= 0 || row > 10 || col > 10)
    {
        printf("잘못된 입력입니다. 1 x 1 ~ 10 x 10 사이의 값을 입력하시오.\n");
        return 1;
    }

    // 행렬 (N x N)입력
    int A[10][10];
    printf("행렬 A를 입력하시오.(%d x %d)\n", row, col);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &A[i][j]);

    // 행렬 (N x N)출력
    printf("\n[행렬 A 출력]\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%10d", A[i][j]);
        printf("\n");
    }

    // 행렬 -> 전치행렬
    int At[10][10];
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            At[j][i] = A[i][j];

    // 전치행렬 출력
    printf("\n[전치행렬 At 출력]\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
            printf("%10d", At[i][j]);
        printf("\n");
    }

    // 행렬 -> 희소행렬
    int smA[100][3];
    int count_smA = 0;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (A[i][j] != 0)
            {
                smA[count_smA][0] = i;
                smA[count_smA][1] = j;
                smA[count_smA][2] = A[i][j];
                count_smA++;
            }

    // 희소행렬 출력
    printf("\n[희소행렬 smA 출력]\n");
    for (i = 0; i < count_smA; i++)
        printf("([%d, %d] - %d)\n", smA[i][0], smA[i][1], smA[i][2]);

    // 전치행렬 -> 희소행렬
    int sm_At[100][3];
    int count_At = 0;
    for (i = 0; i < col; i++)
        for (j = 0; j < row; j++)
            if (At[i][j] != 0)
            {
                sm_At[count_At][0] = i;
                sm_At[count_At][1] = j;
                sm_At[count_At][2] = At[i][j];
                count_At++;
            }

    // 전치행렬 -> 희소행렬 출력
    printf("\n[전치 후 희소행렬 sm_At 출력]\n");
    for (i = 0; i < count_At; i++)
        printf("([%d, %d] - %d)\n", sm_At[i][0], sm_At[i][1], sm_At[i][2]);

    // 희소행렬 -> 전치행렬
    int smA_t[100][3];
    for (i = 0; i < count_smA; i++)
    {
        smA_t[i][0] = smA[i][1];
        smA_t[i][1] = smA[i][0];
        smA_t[i][2] = smA[i][2];
    }

    // 희소행렬 -> 전치행렬 출력
    printf("\n[희소 후 전치행렬 smA_t 출력]\n");
    for (i = 0; i < count_smA; i++)
        printf("([%d, %d] - %d)\n", smA_t[i][0], smA_t[i][1], smA_t[i][2]);

    // sm_At와 smA_t 결과 비교
    int comp = 1;
    if (count_smA != count_At)
    {
        comp = 0;
    }
    else
    {
        for (i = 0; i < count_smA; i++)
        {
            int same = 0;
            for (j = 0; j < count_At; j++)
            {
                if (smA_t[i][0] == sm_At[j][0] && smA_t[i][1] == sm_At[j][1] && smA_t[i][2] == sm_At[j][2])
                {
                    same = 1;
                    break;
                }
            }
            if (!same)
            {
                comp = 0;
                break;
            }
        }
    }

    // 비교 결과 출력
    printf("\n[비교 결과]\n");
    if (comp)
        printf("비교 결과 일치합니다.\n");
    else
        printf("비교 결과 다릅니다.\n");
    return 0;
}