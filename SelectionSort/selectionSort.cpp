#include <iostream>
using namespace std;

void selectionSort(int array[], int n)
{
    int minId;
    for (int i = 0; i < n - 1; i++)
    {
        minId = i;

        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minId])
            {
                minId = j;
            }
        }
        if (minId != i)
        {
            swap(array[i], array[minId]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "Sorted Array : [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}