//This class is used to sort the numbers.
//github.com/MehdiShekari
#include <iostream>
using namespace std;
class Sort {
public:
	
	void Merge_sort(int array[], int n) {
		merge_sort_recu(array, 0, n - 1);
	}
	void Selection_sort(int array[], int n) {
		int min, temp;
		for (int i = 0; i < n - 1; i++) {
			min = i;
			for (int j = i + 1; j < n; j++) {
				if (array[j] < array[min]) {
					min = j;
				}
			}
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}
	void Bubble_sort(int array[], int n) {
		int temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = n - 1; j > i; j--) {
				if (array[j - 1] > array[j])
				{
					temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
				}
			}
		}
	}
	void Insertion_Sort(int array[], int n) {
		for (int i = 1; i < n; i++) {
			int res = array[i];
			int j = i - 1;
			while (res < array[j] && j >= 0) {
				array[j + 1] = array[j];
				--j;
			}
			array[j + 1] = res;
		}
	}
	
	void Quick_sort(int array[], int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(array, low, high);
			Quick_sort(array, low, pivot - 1);
			Quick_sort(array, pivot + 1, high);
		}
	}
	void Counting_sort(int array[], int n, int place) {
		const int max = 10;
		int output[50];
		int count[max];
		for (int i = 0; i < max; ++i)
			count[i] = 0;
		for (int i = 0; i < n; i++)
			count[(array[i] / place) % 10]++;
		for (int i = 1; i < max; i++)
			count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; i--) {
			output[count[(array[i] / place) % 10] - 1] = array[i];
			count[(array[i] / place) % 10]--;
		}

		for (int i = 0; i < n; i++)
			array[i] = output[i];
	}
	void Radix_sort(int array[], int n) {
		int max = getMax(array, n);
		for (int place = 1; max / place > 0; place *= 10)
			Counting_sort(array, n, place);
	}
private :
	int getMax(int array[], int n) {
		int max = array[0];
		for (int i = 1; i < n; i++)
			if (array[i] > max)
				max = array[i];
		return max;
	}
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
	int partition(int array[], int low, int high)
	{
		int pivot = array[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				swap(&array[i], &array[j]);
			}
		}
		swap(&array[i + 1], &array[high]);
		return (i + 1);
	}
	void merge(int *array, int low, int high, int mid)
	{
		int i, j, k, c[50];
		i = low;
		k = low;
		j = mid + 1;
		while (i <= mid && j <= high) {
			if (array[i] < array[j]) {
				c[k] = array[i];
				k++;
				i++;
			}
			else {
				c[k] = array[j];
				k++;
				j++;
			}
		}
		while (i <= mid) {
			c[k] = array[i];
			k++;
			i++;
		}
		while (j <= high) {
			c[k] = array[j];
			k++;
			j++;
		}
		for (i = low; i < k; i++) {
			array[i] = c[i];
		}
	}
	void merge_sort_recu(int *array, int low, int high) {
		int mid;
		if (low < high) {
			mid = (low + high) / 2;
			merge_sort_recu(array, low, mid);
			merge_sort_recu(array, mid + 1, high);
			merge(array, low, high, mid);
		}
	}
};
