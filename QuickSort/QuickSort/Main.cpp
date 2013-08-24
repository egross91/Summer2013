/**************************************
** 
** Quick Sort
** 
**************************************/
#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

void menu();
void loadArray(int*);
void saveArray(int*);
long long quickSort(int*);
long long quickSort(int*, int, int);
int partition(int*, int, int);
int choosePivot(int*, int, int);

int main(int argc, char * argv[])
{
	int arr [10000];
	cout << "Loading Array..." << endl; 
	loadArray(arr);
	cout << "Quick Sorting..." << endl;
	long long comps = quickSort(arr);
	cout << "Saving Array..." << endl;
	saveArray(arr);
	cout << comps << endl;
	cout << "Happy Coding!";
	_getch();
	return 0;
}

void loadArray(int *arr)
{
	try		
	{
		ifstream load("QuickSort.txt", ios::binary);
		int num;
		unsigned int i = 0;
		while (load.is_open() && load.good())
		{
			load >> num;
			arr[i++] = num;
		}
		load.close();
	} 
	catch (ifstream::failure)
	{
		cerr << "Failed to load file." << endl << endl;
	}
}

void saveArray(int *arr)
{
	try
	{
		ofstream save("SortedArray.txt", ios::binary);
		unsigned int i = 0;
		while (save.is_open() && save.good() && i < 10000)
			save << arr[i++] << endl;
		
		save.close();
	}
	catch (ofstream::failure)	
	{
		cerr << "Failed saving file." << endl << endl;
	}
}

long long quickSort(int *arr)
{
	return quickSort(arr, 0, 9999);
}

long long quickSort(int *arr, int left, int right)
{
	long long comps = 0;
	if (left < right)
	{
		int pivot = partition(arr, left, right);

		comps += quickSort(arr, left, pivot-1);
		comps += (pivot - left - 1);
		comps += quickSort(arr, pivot+1, right);
		comps += (right - pivot + 1);
	}
	return comps;
}

int partition(int *arr, int left, int right)
{
	int pivot = choosePivot(arr, left, right);
	int temp;
	if (pivot != left)
	{
		temp = arr[left];
		arr[left] = arr[pivot];
		arr[pivot] = temp;
	}
	int p = arr[left];
	int i, j;
	
	i = left+1;
	j = left+1;
	for (; j <= right; ++j)
	{
		if (arr[j] < p)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i++] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[i-1];
	arr[i-1] = temp;
	return i-1;
}

int choosePivot(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	if ((right-left) == 1)
		return left;
	
	if ((arr[left] < arr[mid] && arr[mid] < arr[right]) || (arr[right] < arr[mid] && arr[mid] < arr[left]))
		return mid;
	else if ((arr[mid] < arr[left] && arr[left] < arr[right]) || (arr[right] < arr[left] && arr[left] < arr[mid]))
		return left;
	else
		return right;
}