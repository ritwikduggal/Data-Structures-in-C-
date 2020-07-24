#include <iostream>
using namespace std;

//named it swp instead of swap to avoid calling the inbuilt c++ function Swap.
void swp(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int left, int right)
{
    int pivot = a[right];
    int i = (left - 1);
    for (int j = left; j <= right - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swp(&a[i], &a[j]);
        }
    }
    swp(&a[i + 1], &a[right]);
    return (i + 1);
}

void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int p;
				p=partition(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}

int main()
{
    int n;
		cout<<"Enter number of elements"<<endl;
		cin>>n;
		int a[n];
		cout<<"Enter the Elements"<<endl;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
    quickSort(a, 0, n - 1);
    cout << "Array Sorted"<<endl<<"Here's the array"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<a[i]<<" ";
    }
    return 0;
}
