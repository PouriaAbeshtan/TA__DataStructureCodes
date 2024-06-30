#include <iostream>
using namespace std;
void insertionSort(int arr[], int size);
int quick(int arr[], int low, int highe);
void quickSort(int arr[], int low, int high);
void bobbleSort(int arr[] , int size);
void selectionSort(int arr[], int size);
void printArr(int arr[], int size);
void merge(int arr[], int mid, int low, int high);
void mergeSort(int arr[], int low, int high);

int linearSearch(int arr[], int size,int key);
int recursiveBinarySearch(int arr[], int key, int low, int high);
int binarySearch(int arr[],int size, int key);







int main()
{
	int arr[7] = {1,2,3,4,5,6,7};
	printArr(arr, 7);
	cout << binarySearch(arr, 7, 6);
	

  
}

void insertionSort(int arr[], int size)
{
	for (int i = 1; i<size ; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

}
int quick(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low + 1;
	int j = high;
	while (i<=j)
	{
		while (pivot > arr[i])
			i++;
		while (pivot < arr[j])
			j--;
		if (i < j)
		{
		
			int swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
		
		}
	}
	int swap = arr[j];
	arr[j] = pivot;
	arr[low] = swap;
	//pivot index
	return j;

}
void quickSort(int arr[], int low, int high)
{
	
	if (low >= high)
	{
		return;
	}
	int pivot = quick(arr, low, high);
	quickSort(arr, low, pivot -1);
	quickSort(arr, pivot +1 , high);
}
void bobbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for(int j = i+1 ; j < size ;j++)
		{
			if (arr[i]>arr[j])
			{
				int swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}
}
void selectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = i;
		for(int j = i+1; j < size ;j++)
		{
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}
		int swap = arr[i];
		arr[i] = arr[k];
		arr[k] = swap;
	}

}
void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void merge(int arr[], int mid, int low, int high)
{
	int subArray1 = mid - low + 1;
	int subArray2 = high - mid;
	
	int* arr1 = new int[subArray1];
	int* arr2 = new int[subArray2];

	for (int i = 0; i < subArray1; i++)
		arr1[i] = arr[low + i];
	for (int i = 0; i < subArray2; i++)
	arr2[i] = arr[mid + i + 1];
	
	int startIndex = low;
	int indexSubArray1 = 0;
	int indexSubArray2 = 0;
	while (indexSubArray1 < subArray1 && indexSubArray2 < subArray2)
	{
		if (arr1[indexSubArray1] > arr2[indexSubArray2])
		{
			arr[startIndex] = arr2[indexSubArray2];
			indexSubArray2++;
		}
		else
		{
			arr[startIndex] = arr1[indexSubArray1];
			indexSubArray1++;
		}
		startIndex++;
	}
	for (int i = indexSubArray1; i < subArray1; i++)
	{
		arr[startIndex] = arr1[i];
		startIndex++;
	}
	for (int i = indexSubArray2; i < subArray2; i++)
	{
		arr[startIndex] = arr2[i];
		startIndex++;
	}

	delete[] arr1;
	delete[] arr2;

}
void mergeSort(int arr[], int low, int high)
{
	int mid = (low + high) / 2;
	if (low>=high)
	{
		return;
	}
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, mid, low, high);



}

int linearSearch(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int recursiveBinarySearch(int arr[], int key, int low, int high)
{
	if (low<=high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] >= key)
			return recursiveBinarySearch(arr, key, low, mid);
		else
			return recursiveBinarySearch(arr, key, mid + 1, high);
	}
	return -1;
}
int binarySearch(int arr[], int size, int key)
{
	int low = 0;
	int high = size - 1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] >= key)
			high = mid;
		else
			low = mid + 1;
	}
	return -1;
}


