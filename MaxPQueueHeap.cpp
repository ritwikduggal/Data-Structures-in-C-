#include <iostream>
using namespace std;

//used swp to avoid invoking inbuilt swap function of c++
void swp(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int t_size = 15;
int heap_size = 0;
const int INF = 100000;

int get_right_child(int a[], int i)
{
  if((((2*i)+1) < t_size) && (i >= 1))
  {
    return (2*i)+1;
  }
  return -1;
}

int get_left_child(int a[], int i)
{
    if(((2*i) < t_size) && (i >= 1))
    {
        return 2*i;
    }
    return -1;
}

int get_parent(int a[], int i)
{
  if ((i > 1) && (i < t_size))
  {
    return i/2;
  }
  return -1;
}

void max_heapify(int a[], int i)
{
  int left_child_i = get_left_child(a, i);
  int right_child_i = get_right_child(a, i);
  int largest = i;

  if ((left_child_i <= heap_size) && (left_child_i>0))
  {
    if (a[left_child_i] > a[largest])
    {
      largest = left_child_i;
    }
  }

  if ((right_child_i <= heap_size && (right_child_i>0)))
  {
    if (a[right_child_i] > a[largest])
    {
      largest = right_child_i;
    }
  }

  if (largest != i)
  {
    swp(&a[i], &a[largest]);
    max_heapify(a, largest);
  }
}

void build_max_heap(int a[])
{
  int i;
  for(i=heap_size/2; i>=1; i--)
  {
    max_heapify(a, i);
  }
}

int maximum(int a[])
{
  return a[1];
}

int extract_max(int a[])
{
  int maxm = a[1];
  a[1] = a[heap_size];
  heap_size--;
  max_heapify(a, 1);
  return maxm;
}

void increase_k(int a[], int i, int k)
{
  a[i] = k;
  while((i>1) && (a[get_parent(a, i)] < a[i])) {
    swp(&a[i], &a[get_parent(a, i)]);
    i = get_parent(a, i);
  }
}

void decrease_k(int a[], int i, int k)
{
  a[i] = k;
  max_heapify(a, i);
}

void insert(int a[], int k)
{
  heap_size++;
  a[heap_size] = -1*INF;
  increase_k(a, heap_size, k);
}

void print_heap(int a[])
{
  for(int i=1; i<=heap_size; i++)
  {
    cout<<a[i]<<endl;;
  }
  cout<<endl;
}

int main()
{
  int a[t_size];
  cout<<"Enter to insert"<<endl;
  int k;
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cin>>k;
  insert(a, k);
  cout<<"Inserting..."<<endl;
  cout<<"Here's the heap"<<endl;
  print_heap(a);

  cout<<"Increasing..."<<endl;
  increase_k(a, 5, 22);
  cout<<"Here's the heap"<<endl;
  print_heap(a);

  cout<<"Decreasing..."<<endl;
  decrease_k(a, 1, 13);
  cout<<"Here's the heap"<<endl;
  print_heap(a);

  cout<<"Max"<<endl;
  cout<<maximum(a)<<endl;
  cout<<extract_max(a)<<endl;

  print_heap(a);

  cout<<"Extracting max..."<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  cout<<extract_max(a)<<endl;
  return 0;
}
