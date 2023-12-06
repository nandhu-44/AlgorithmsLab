#include <iostream>
using namespace std;

int linearSearch(int array[], int n, int v)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == v)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int n, v;
	cout << "Enter the size of the array: ";
	cin >> n;
	int array[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	cout << "Enter the value to be searched: ";
	cin >> v;
	int index = linearSearch(array, n, v);
	if (index == -1)
	{
		cout << "NIL" << endl;
	}
	else
	{
		cout << "Element found at index : " << index << endl;
	}
}
