#include <iostream>
#include<vector>
using namespace std;

void add(vector<int> adj[], int source, int destination)
{
   adj[source].push_back(destination);
}

void trpsG(vector<int> adj[],vector<int> transpose[], int n)
{
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<adj[i].size(); j++)
    {
      add(transpose, adj[i][j], i);
    }
  }
}

int main()
{
  int n, s, d;
  cout<<"Enter number of vertices"<<endl;
  cin>>n;
  vector<int> a[n];
  vector<int> trps[n];
  cout<<"Enter source and destination vertex"<<endl;
  cin>>s>>d;
  add(a,s,d);
  cout<<endl;
  cin>>s>>d;
  add(a,s,d);
  cout<<endl;
  cin>>s>>d;
  add(a,s,d);
  cout<<endl;
  cin>>s>>d;
  add(a,s,d);
  cout<<endl;
  cin>>s>>d;
  add(a,s,d);
  cout<<endl;
  cout<<"Graph"<<endl;
  for (int i=0; i<n; i++)
  {
    cout<<i<<"- -";
    for(int j=0; j<a[i].size(); j++)
     {
       cout<<a[i][j]<<" ";
       cout<<endl;
      }
  }
  cout<<endl<<"Transpose of graph taking adjacency list of given graph"<<endl;
  trpsG(a, trps, n);
  for (int i=0; i<n; i++)
  {
    cout << i << "- -";
    for (int j=0; j<a[i].size(); j++)
    cout << a[i][j] << " ";
    cout <<endl;
  }
}
