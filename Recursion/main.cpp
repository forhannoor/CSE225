#include <cmath>
#include <cstdio>
#include <iostream>

int fibonacci(int n);
int factorial(int n);
int sumDigits(int n);
int findMin(int a[], int size);
void decimalToBinary(int n);
double sumSeries(int n);

int main()
{
    int n;
    printf("Fibonacci term#");
    scanf("%d", &n);
    printf("Fibonacci term: %d\n", fibonacci(n));
    printf("Factorial:");
    scanf("%d", &n);
    printf("Factorial: %d\n", factorial(n));
    printf("Sum of digits:");
    scanf("%d", &n);
    printf("Sum of digits: %d\n", sumDigits(n));
    int a[] = {5, 4, 3, 7, 2, 0, 6, 5};
    printf("Find minimum: %d\n", findMin(a, 8));
    printf("Decimal: ");
    scanf("%d", &n);
    printf("Binary:");
    decimalToBinary(n);
    printf("Sum of series: ");
    scanf("%d", &n);
    printf("Sum of series: %ld\n", sumSeries(n));
    return 0;
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int sumDigits(int n)
{
    if(n != 0)
    {
        return (n % 10 + sumDigits(n / 10));
    }

    return 0;
}

int findMin(int a[], int size)
{
    if(size == 1)
    {
        return a[size - 1];
    }

    int c = a[size - 1];
    int d = findMin(a, size - 1);

    return (c < d) ? c : d;
}

void decimalToBinary(int n)
{
    if(n > 0)
    {
        decimalToBinary(n / 2);
        printf("%d", n % 2);
    }
}

double sumSeries(int n)
{
    if(n == 0)
    {
        return 1;
    }

    else
    {
        return (1 / pow(2, n)) + sumSeries(n - 1);
    }
}