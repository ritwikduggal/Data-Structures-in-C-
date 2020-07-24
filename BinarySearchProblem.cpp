#include<iostream>
using namespace std;

int BSearch(int a[], int s, int n, int k)
{
    if(n>=s)
    {
      int mid =s+(n - s)/2;
      if(a[mid]==k)
      {
        return mid;
      }
      if(a[mid]>k)
      {
        return BSearch(a, s, mid - 1, k);
      }
      if(a[mid]<=k)
      {
        return BSearch(a, mid + 1, n, k);
      }
    }
    return -1;
}

int main()
{
  int a[50], n;
  cout<<"How many elements do you want?"<<endl;
  cin>>n;
  cout<<"Enter the elements of array"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  cout<<"Which element do you want to find?"<<endl;
  int k;
  cin>>k;
  cout<<"Which position do you want me to start from?"<<endl;
  int s;
  cin>>s;
  int ans=BSearch(a, s, n-1, k);
  if(ans!=-1)
  {
    cout<<"Found, at position: "<<ans<<endl;
    for(int i=ans; i<n; i++)
    {
      a[i]=a[i+1];
    }
    cout<<"Removed, here is the new list"<<endl;
    n--;
    for(int i=0; i<n; i++)
    {
      cout<<a[i];
    }

  }
  else
  {
    int kp;
    cout<<"Not present, which position do you want to add it?"<<endl;
    cin>>kp;
    for(int i=kp; i<n; i++)
    {
      a[i+1]=a[i];
    }
    a[kp]=k;
    cout<<"Added, here is the new list"<<endl;
    n++;
    for(int i=0; i<n; i++)
    {
      cout<<a[i];
    }
  }
}
