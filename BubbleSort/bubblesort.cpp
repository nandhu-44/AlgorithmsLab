#include <iostream>
using namespace std;

void bubbleSort(int array[], int n);

int main()
{
	int n;
	cout << "Enter the size of array : ";
	cin >> n;
	int array[n];
	cout << "Enter the elements of the array : ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	bubbleSort(array, n);
	cout << "Sorted Array: [";
	for (int i = 0; i < n; i++)
	{
		cout << array[i];
		if (i != n - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
};

void bubbleSort(int array[], int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapped = true;
				swap(array[j], array[j + 1]);
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}
