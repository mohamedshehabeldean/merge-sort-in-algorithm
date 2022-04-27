#include<iostream>
using namespace std;
void merge(int a[], int start, int q, int end)
{
	 int n1 = (q - start) + 1;
	 int n2 = (end - q);
	 int* l = new int[n1];
	 int*r = new int[n2];
	for (int i = 0; i < n1; i++)
		l[i] = a[start + i];   
	for (int j = 0; j < n2; j++)
		r[j] = a[q + 1 + j];
	int i = 0;
	int j = 0;
	int k = start;
	while (i < n1 && j < n2)
	{
		if (l[i] >= r[j])
		{
			a[k] = l[i];
			i++;

		}
		else
		{
			a[k] = r[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		a[k] = l[i];
		i++;
		k++;


	}

	while (j < n2)
	{
		a[k] = r[j];
		j++;
		k++;


	}


}

void merge_sort(int a[], int start, int end)
{
	int q;
	if (start < end)
	{
		q = start+(end-start) / 2;
		merge_sort(a, start, q);
		merge_sort(a, q + 1, end);
		merge(a, start, q, end);
	}


}
void printarray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

}





void main() {
	int arr[] = {99,6,76,15,58,35,86};
	int n = sizeof(arr) / sizeof(arr[1]);
	merge_sort(arr, 0, n - 1);
	
	printarray(arr, n);



}