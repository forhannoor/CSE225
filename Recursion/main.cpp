#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int n);
int factorial(int n);
int sumDigits(int n);
int findMin(int a[], int size);
void decimalToBinary(int n);
double sumSeries(int n); // 1 + 1/2 + 1/4 + 1/8 + ... + 1/2n

int main()
{
    int n;
    cout<<"Fibonacci term#";
    cin>>n;
    cout<<"Fibonacchi term: "<<fibonacci(n)<<endl;

    cout<<"Factorial: ";
    cin>>n;
    cout<<"Factorial: "<<factorial(n)<<endl;

    cout<<"Sum of digits: ";
    cin>>n;
    cout<<"Sum of digits: "<<sumDigits(n)<<endl;

    int a[] = {5, 4, 3, 7, 2, 0, 6, 5};
    cout<<"Find minimum: "<<findMin(a, 8)<<endl;

    cout<<"Decimal: ";
    cin>>n;
    cout<<"Binary: ";
    decimalToBinary(n);

    cout<<"\nSum of series: ";
    cin>>n;
    cout<<"Sum of series: "<<sumSeries(n)<<endl;

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
        cout<<n % 2;
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