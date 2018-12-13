#include <iostream>
#include <array>
#include <chrono>
#include <cmath>

using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void FULLswap(int arr[],int length)
{
	int start = 0; 
	int bigL = length;
	while (start < bigL)
	{
		int temp = arr[start];
		arr[start] = arr[bigL];
		arr[bigL] = temp;
		start++;
		bigL--;
	}


}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int arr[], int length)
{
	for (int i = 0; i < length; i++) {
		for (int k = i; k > 0 && arr[k - 1] > arr[k]; k--) {
			int temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
	}
}

void selectionSort(int arr[], int length) 
{
	for (int i = 0; i < length - 1; i++) {
		int mini = i;
		for (int k = i + 1; k < length; k++)
			if (arr[k] < arr[mini])
				mini = k;
		swap(&arr[mini], &arr[i]);
	}
}

void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length - 1; i++)
		for (int k = 0; k < length - i - 1; k++)
			if (arr[k] > arr[k + 1])
				swap(&arr[k], &arr[k + 1]);
}

void mergeArray(int arr[], int low, int mid, int high)
{
	int *Larr = NULL;
	int *Rarr = NULL;
	int LLength = mid - low + 1;
	int RLength = high - mid;
	Larr = new int[LLength];
	Rarr = new int[RLength];
	for (int i = 0; i < LLength; i++) {
		Larr[i] = arr[low + i];
	}
	for (int k = 0; k < RLength; k++) {
		Rarr[k] = arr[mid + 1 + k];
	}

	int i = 0, k = 0, startDEX = low;

	while(i<LLength && k <RLength)
	{
		if (Larr[i] <= Rarr[k])
		{
			arr[startDEX] = Larr[i];
			i++;
		}
		else
		{
			arr[startDEX] = Rarr[k];
			k++;
		}
		startDEX++;
	}
	while(i<LLength)
	{
		arr[startDEX] = Larr[i];
		i++;
		startDEX++;
	}
	while (i<RLength)
	{
		arr[startDEX] = Rarr[k];
		k++;
		startDEX++;
	}
}

void mergeSort(int arr[],int low, int high) 
{
	if (low < high) {
		int MIDT = (low + high) / 2;
		mergeSort(arr, low, MIDT);
		mergeSort(arr, MIDT + 1, high);
		mergeArray(arr, low, MIDT, high);
	}
}

int main() {
	char choice = 'y';
	 do {
		int randARR[10000];

		for (int i = 0; i < 10001; i++) {
			randARR[i] = rand() % 1000 + 1;
		}

		int n = sizeof(randARR) / sizeof(randARR[0]);

		//auto start = chrono::high_resolution_clock::now();
		//insertionSort(randARR, n);
		//bubbleSort(randARR, n);
		//selectionSort(randARR, n);
		// mergeSort(randARR, 0, n-1);
		//swap(randARR[rand() % 10000 + 1], randARR[rand() % 10000 + 1]);
		//FULLswap(randARR, n);
		auto start = chrono::high_resolution_clock::now();
	//	mergeSort(randARR,0, n-1);
		auto finish = chrono::high_resolution_clock::now();

		chrono::duration<double> elapsed = finish - start;
		std::cout << "elasped time: " << elapsed.count() << endl;
		std::cout << "type y and press enter to run program again" << endl;
		std::cin >> choice;
	 } while (choice == 'y');
	
}
