/* --- THIS CODE WILL NOT COMPILE ---
*  This was created beacuse of a leisure course.
*  There is code intentionally omitted for the sake
*  of learning. There is residual Inverse counting 
*  code to help the audience decipher what to implement
*  to fill in the gaps. The purpose is to aid, not 
*  answer.
*/
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void loadIntArray(int*);
void saveIntArray(int*);
long long mergeSort(int*, int*);
long long mergeSort(int*, int*, int, int);
long long merge(int*, int*, int, int, int);

int main(int argc, char * argv[])
{
	int arr [100000];
	cout << "Loading File..." << endl;
	loadIntArray(arr);

	// We know the array will be of size 100,000 because the file includes 1 - 100,000.
	long long ret = mergeSort(arr, temp);
	cout << "Saving Sorted File..." << endl;

	saveIntArray(arr);  
	cout << ret << endl;
	cout << "Happy Coding!";
	_getch();
	return 0;
}

void loadIntArray(int *ints)
{
	ifstream loadFile("IntegerArray.txt", ios::binary);
	int num;
	int i = 0;
	while (loadFile.is_open() && loadFile.good())
	{
		loadFile >> num;
		ints[i++] = num;
	}
	loadFile.close();
}

void saveIntArray(int *ints)
{
	ofstream saveFile("SortedArray.txt", ios::binary);
	unsigned int i = 0;
	while (saveFile.is_open() && saveFile.good() && i < 100000)
		saveFile << ints[i++] << endl;

	saveFile.close();
}

long long mergeSort(int *arr, int *temp)
{
	return mergeSort(arr, temp, 0, 99999);
}

long long mergeSort(int *arr, int *temp, int left, int right)
{
	int mid;
	long long inv_cnt = 0;
	if (left < right)
	{
		mid = (left+right) / 2;
		inv_cnt += // Split to make a subarray of left half of arr[] using recursion.
		inv_cnt += // Split to make a subarray of right half of arr[] using recustion.
		inv_cnt += // merge(int*, int*, int, int, int) the newly created array with all the newly created ones using recursion.
	}
	return inv_cnt; // Get the total number of inversions for the arr[].
}

long long merge(int *arr, int *temp, int left, int mid, int right)
{
	long long inv_cnt = 0;
	int i, j, k;
	i = left; // Start of left side of the arr[]'s indexes.
	j = mid; // Start of right side of the arr[]'s indexes.
	k = left; // The whole temp[]'s indexes.

	while (i<=mid-1 && j<=right)
	{
		if (arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			inv_cnt = inv_cnt + /* for every element left in arr[] for this element */;
		}
	}
	while (i<=mid-1) // If the last bit of the first half of arr[] didn't finish copying.
		temp[k++] = arr[i++];
	while (j<=right) // If the last bit of the second half of arr[] didn't finish copying.
		temp[k++] = arr[j++];
	for (i = left; i <= right; ++i)
		arr[i] = temp[i];
	return inv_cnt;
}