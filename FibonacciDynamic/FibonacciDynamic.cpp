#include <iostream>
using namespace std;

void fibonacci(int n)
{
    unsigned long long int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    if (n <= 0)
    {
        cout << "Invalid input!" << endl;
        return;
    }
    else if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    cout << arr[0] << " " << arr[1] << " ";
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the no of terms : ";
    cin >> n;
    cout << "Fibonacci of first " << n << " terms is : ";
    fibonacci(n);
    return 0;
}