#include <stdio.h> // Подключение ввода/вывода
#include <stdlib.h> // Подключение stdlib для malloc
#include <math.h>
void stepBGaussMatrix(double*, int, int, int); // Предварительное описание функции
void stepFGaussMatrix(double*, int, int, int);
void addmulstrMatrix(double*, int, int, int, int, double); // Предварительное описание функции
void mulMatrix(double*, int, int, int, double); // Предварительное описание функции
void BGaussMatrix(double*, int, int); // Предварительное описание функции
void FGaussMatrix(double*, int, int); // Предварительное описание функции
int findNZMatrix(double*, int, int, int); // Предварительное описание функции
void chgstrMatrix(double*, int, int, int, int); // Предварительное описание функции
double detMatrix(double*, int, int);

int main(void)
{
    FILE* in; 	// Указатель на файл исходных данных
    FILE* out;  // Указатель на файл результатов
    double* A;  // Описание имени матрицы
    int q = 1; 	// признак успешности чтения очередного числа
    int N = 0, M = 0; 	// число строк и столбцов матрицы
    int i, j; 	// переменные для перебора элементов в цикле for
    out = fopen("output.txt", "w");
    if ((in = fopen("input.txt", "r")) == NULL) return -1;
    if ((fscanf(in, "%d%d", &N, &M) == EOF) || N < 1 || M < 1 || N + 1 != M) return -1;// размер матрицы 
    A = (double*)malloc(N * M * sizeof(double));// выделение N*M*8байт для А
    for (i = 0; i < N * M; i++) q = fscanf(in, "%lf", &A[i]);
    if ((q == 1) && (feof(in)))
    {   // все элементы матрицы А прочитаны успешно
        FGaussMatrix(A, N, M);
        if (fabs(detMatrix(A, N, M)) >= 0.00001)
        {
            BGaussMatrix(A, N, M);
            for (i = 0; i < N; i++)
            {
                if (fabs(A[i * M + M - 1]) < 0.000001)A[i * M + M - 1] = 0;
                fprintf(out, "%lf ", A[i * M + M - 1]);
            } // вывод матрицы А
            fprintf(out, "\n"); // с новой строки
        }
        else fprintf(out, "Not found");

        free(A);
    }
    else return -1;   // ошибочные данные
    fclose(in); fclose(out);
    return 0;
}
// Обработка матрицы A из N строк и M столбцов

void BGaussMatrix(double a[], int n, int m)
{
    int j; // индексы для манипуляции с элементами
    for (int k = n - 1; k >= 0; k--)
    {
        mulMatrix(a, n, m, k, 1 / a[k * m + k]);
        for (j = k - 1; j >= 0; j--)
        {
            addmulstrMatrix(a, n, m, j, k, -a[j * m + k]);
        }
    }

    return;
}

double detMatrix(double a[], int n, int m)
{
    int i; // индексы для манипуляции с элементами
    double p = 1;
    for (i = 0; i < n; i++)
    {
        p *= a[i * m + i];
    }

    return p;
}

void FGaussMatrix(double a[], int n, int m)
{
    int j; // индексы для манипуляции с элементами
    int k;
    for (k = 0; k < n; k++)
    {
        if ((a[k * m + k] <= 0.00001) && (a[k * m + k] >= -0.00001))
        {
            int l = findNZMatrix(a, n, m, k);
            if (l == k) continue;
            chgstrMatrix(a, n, m, k, l);
        }

        for (j = k + 1; j < n; j++)
        {
            addmulstrMatrix(a, n, m, j, k, -a[j * m + k] / a[k * m + k]);
        }
    }
    return;
}
void addmulstrMatrix(double a[], int n, int m, int k, int l, double x)
{
    int j;
    for (j = m * k; j < m * (k + 1); j++)
    {
        a[j] += a[j + m * (l - k)] * x;
    }
    return;
}

void chgstrMatrix(double a[], int n, int m, int k, int l)
{
    int j;
    double t;// индексы для манипуляции с элементами
    if (k == l)
        return;
    for (j = m * k; j < m * (k + 1); j++)
    {
        t = a[j];
        a[j] = a[j + m * (l - k)];
        a[j + m * (l - k)] = t;
    }


    return;
}

int findNZMatrix(double* a, int n, int m, int k)
{
    int j;
    for (j = k + 1; j < n; j++)
    {
        if ((a[j * m + k] >= 0.00001) || (a[j * m + k] <= -0.00001))
            return j;
    }
    return k;
}

void mulMatrix(double a[], int n, int m, int k, double x)
{
    int j; // индексы для манипуляции с элементами
    for (j = m * k; j < (m * (k + 1)); j++)
    {
        a[j] *= x;
    }

    return;
}
