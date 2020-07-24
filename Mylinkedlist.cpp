#include<iostream>
using namespace std;

template<typename T>
class MLList
{
  public:
    const T & operator[](unsigned index);
    void InsertFront(const T & data);
    void InsertBefore(const T & data, int n);
    void DeleteAfter(int n);
  private:
    class MLLNode
    {
      public:
          const T data;
          MLLNode *next;
          MLLNode(const T & data) : data(data), next(nullptr) { }
    };
    MLLNode *head_;
};

template<typename T>
const T & MLList<T>::operator[](unsigned index)
 {
  MLLNode *ptr = head_;
  while (index > 0 && ptr->next != nullptr)
   {
    ptr = ptr->next;
    index--;
   }
   return ptr->data;
 }

template<typename T>
void MLList<T> :: InsertFront(const T & data)
{
  MLLNode *node = new MLLNode(data);
  node -> next = head_;
  head_ = node;
}

template<typename T>
void MLList<T> :: InsertBefore(const T & data, int n)
{
  MLLNode *node = new MLLNode(data);
  MLLNode *ptr = head_;
  if(n==0)
  {
    node -> next = head_;
    head_ = node;
  }
  else
  {
    MLLNode *ptr2 = ptr;
    for(int i=0; i<n; i++)
    {
      ptr2 = ptr;
      ptr = ptr -> next;
    }
    ptr2 -> next = node;
    node -> next = ptr;
  }
}

template<typename T>
void MLList<T> :: DeleteAfter(int n)
{
  MLLNode *ptr = head_;
  if(n==0)
  {
    ptr= ptr->next;
    head_ = ptr;
  }
  else
  {
    MLLNode *ptr2 = ptr;
    for(int i=0; i<n; i++)
    {
      ptr2 = ptr;
      ptr = ptr -> next;
    }
    ptr= ptr-> next;
    ptr2 -> next = ptr;

  }
}

int main()
{
  int n;
  MLList<int> L;
  L.InsertFront(5);
  L.InsertFront(5);
  L.InsertFront(5);
  L.InsertFront(5);
  L.InsertFront(5);
  cout<<"Enter a number to add: "<<endl;
  cin>>n;
  cout<<"At what position do you want the data?"<<endl;
  int y;
  cin>>y;
  L.InsertBefore(n ,y);
  cout<<"You entered: "<<L[y]<<endl;
 int k;
 cout<<"Enter which element's next, do you want to delete: ";
 cin>>k;
  L.DeleteAfter(k);
  cout<<"Now, the entry "<<k<<" is: "<<L[k]<<endl;

  return 0;
}
