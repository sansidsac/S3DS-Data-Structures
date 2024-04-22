#include <stdio.h>
struct polynomial
{
    int coeff;
    int degree;
};

void polynomial_addition(struct polynomial p1[], int m, struct polynomial p2[], int n, struct polynomial result[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (p1[i].degree == p2[j].degree)
        {
            result[k].degree = p1[i].degree;
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if (p1[i].degree > p2[j].degree)
        {
            result[k].degree = p1[i].degree;
            result[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else
        {
            result[k].degree = p2[j].degree;
            result[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
    }

    while (i < m)
    {
        result[k].degree = p1[i].degree;
        result[k].coeff = p1[i].coeff;
        i++;
        k++;
    }

    while (j < n)
    {
        result[k].degree = p2[j].degree;
        result[k].coeff = p2[j].coeff;
        j++;
        k++;
    }
}

void display_polynomial(struct polynomial p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%dx^%d ", p[i].coeff, p[i].degree);
    }
    printf("\n");
}

int main()
{
    int m, n, i;
    struct polynomial p1[50], p2[50], result[100];

    printf("Enter the number of terms in first polynomial : ");
    scanf("%d", &m);
    printf("Enter coefficients and its corresponding powers of first polynomial : ");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &p1[i].coeff, &p1[i].degree);
    }

    printf("Enter the number of terms in second polynomial : ");
    scanf("%d", &n);
    printf("Enter coefficients and its corresponding powers of second polynomial : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &p2[i].coeff, &p2[i].degree);
    }

    polynomial_addition(p1, m, p2, n, result);

    printf("Resultant polynomial : \n");
    display_polynomial(result, m + n - 1);

    return 0;
}