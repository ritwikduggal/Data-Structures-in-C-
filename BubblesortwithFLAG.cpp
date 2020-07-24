#include<iostream>
using namespace std;

void swp(int *a, int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void BSort(int a[], int n)
{
  bool FLAG=0;
  for(int i=0; i<n; i++)
  {
    FLAG=0;
    for(int j=0; j<n-i-1; j++)
    {
      if (a[j] > a[j+1])
      {
        swp(&a[j], &a[j+1]);
        FLAG=1;
      }
    }
    if(FLAG!=1)
    {
      break;
    }
  }
}

int main()
{
  //We can use realloc function for a dynamic array too, code given below, but I wanted to do it differently.
  //more=(int*)realloc(numbers,count*sizeof(int));
  int n;
  cout<<"How many elements do you want?"<<endl;
  cin>>n;
  cout<<"Enter the elements of array"<<endl;
  int a[n];
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  BSort(a, n);
  cout<<"Here is the sorted array: ";
  for(int i=0; i<n; i++)
  {
    cout<<a[i]<<" ";
  }
}
