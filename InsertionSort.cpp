#include<iostream>
using namespace std;

void insertionsort(int a[], int n)
{
  int k, j;
  for (int i = 1; i < n; i++)
  {
      k=a[i];
      j = i - 1;
      while (j >= 0 && a[j] > k)
      {
          a[j + 1] = a[j];
          j = j - 1;
      }
      a[j + 1] = k;
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
    insertionsort(a, n);
    cout << "Array Sorted"<<endl<<"Here's the array"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<a[i]<<" ";
    }
    return 0;
}
