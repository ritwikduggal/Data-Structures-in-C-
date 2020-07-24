#include<iostream>
using namespace std;

void selectionsort(int a[], int n)
{
  for(int k=0; k<n; k++)
  {
    int mini=a[k], index=k, temp;
    for(int i=k; i<n; i++)
    {
      if(a[i]<mini)
      {
        mini=a[i];
        index=i;
      }
    }
    temp=a[index];
    a[index]=a[k];
    a[k]=temp;
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
    selectionsort(a, n);
    cout << "Array Sorted"<<endl<<"Here's the array"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<a[i]<<" ";
    }
    return 0;
}
