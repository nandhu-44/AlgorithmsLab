#include <iostream>
using namespace std;

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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
    insertionSort(arr, n);
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