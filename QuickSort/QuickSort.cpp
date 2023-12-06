#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right);

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
    quickSort(arr, 0, n - 1);
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

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIdx = partition(arr, left, right);
        quickSort(arr, left, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, right);
    }
}