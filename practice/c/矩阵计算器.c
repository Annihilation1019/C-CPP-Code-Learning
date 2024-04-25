#include <stdio.h>
#include <stdlib.h>

int **Matrix_init(int, int);
void Matrix_free(int **, int);
void Matrix_input(int **, int, int);
void Matrix_output(int **, int, int);
int **Matrix_add(int **, int **, int, int);
int **Matrix_sub(int **, int **, int, int);
int **Matrix_mul(int **, int **, int, int, int);
int **Matrix_transpose(int **, int, int);

int main()
{
    int r, c, mode;
    printf("请输入矩阵的行数和列数：");
    scanf("%d%d", &r, &c);
    printf("请输入矩阵的运算模式：(1.加法 2.减法 3.乘法 4.转置)：");
    scanf("%d", &mode);
    switch (mode)
    {
    case 1:
        int **matrix1 = Matrix_init(r, c);
        int **matrix2 = Matrix_init(r, c);
        Matrix_input(matrix1, r, c);
        Matrix_input(matrix2, r, c);
        int **matrix_add = Matrix_add(matrix1, matrix2, r, c);
        Matrix_output(matrix_add, r, c);
        Matrix_free(matrix1, r);
        Matrix_free(matrix2, r);
        Matrix_free(matrix_add, r);
        break;
    case 2:
        int **matrix3 = Matrix_init(r, c);
        int **matrix4 = Matrix_init(r, c);
        Matrix_input(matrix3, r, c);
        Matrix_input(matrix4, r, c);
        int **matrix_sub = Matrix_sub(matrix3, matrix4, r, c);
        Matrix_output(matrix_sub, r, c);
        Matrix_free(matrix3, r);
        Matrix_free(matrix4, r);
        Matrix_free(matrix_sub, r);
        break;
    case 3:
        int r1, c1, r2, c2;
        printf("请输入第一个矩阵的行数和列数：");
        scanf("%d%d", &r1, &c1);
        printf("请输入第二个矩阵的行数和列数：");
        scanf("%d%d", &r2, &c2);
        if (c1 != r2)
        {
            printf("矩阵无法相乘\n");
            return 0;
        }
        int **matrix5 = Matrix_init(r1, c1);
        int **matrix6 = Matrix_init(r2, c2);
        Matrix_input(matrix5, r1, c1);
        Matrix_input(matrix6, r2, c2);
        int **matrix_mul = Matrix_mul(matrix5, matrix6, r1, c1, c2);
        Matrix_output(matrix_mul, r1, c2);
        Matrix_free(matrix5, r1);
        Matrix_free(matrix6, r2);
        Matrix_free(matrix_mul, r1);
        break;
    case 4:
        int **matrix = Matrix_init(r, c);
        Matrix_input(matrix, r, c);
        int **transposed = Matrix_transpose(matrix, r, c);
        Matrix_output(transposed, c, r);
        Matrix_free(matrix, r);
        Matrix_free(transposed, c);
        break;
    }
    return 0;
}

int **Matrix_init(int r, int c)
{
    int **matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int *)malloc(c * sizeof(int));
    }
    return matrix;
}

void Matrix_free(int **matrix, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void Matrix_input(int **matrix, int r, int c)
{
    printf("请输入矩阵的元素：\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void Matrix_output(int **matrix, int r, int c)
{
    printf("矩阵的元素为：\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **Matrix_add(int **matrix1, int **matrix2, int r, int c)
{
    int **matrix = Matrix_init(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix;
}

int **Matrix_sub(int **matrix1, int **matrix2, int r, int c)
{
    int **matrix = Matrix_init(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return matrix;
}

int **Matrix_mul(int **matrix1, int **matrix2, int r1, int c1, int c2)
{
    int **matrix = Matrix_init(r1, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix;
}

int **Matrix_transpose(int **matrix, int r, int c)
{
    int **transposed = Matrix_init(c, r);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}