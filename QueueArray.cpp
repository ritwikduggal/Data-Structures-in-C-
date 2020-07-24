#include<iostream>
using namespace std;

#define MAX 5

class Queue
{
  public:
    //I made a queue of capacity 5, can be changed according to wish.
    int q[MAX];
    void add();
    void remove();
    void display();
    int front;
    int end;
    Queue()
    {
      front=-1;
      end=-1;
    }
};

void Queue::add()
{
    int add_item;
    if (end == MAX - 1)
    {
     cout<<"Queue Overflow"<<endl;
    }
    else
    {
        if (front == - 1)
        {
         front = 0;
        }
        cout<<"Insert the element in queue : "<<endl;
        cin>>add_item;
        end = end + 1;
        q[end] = add_item;
    }
}

void Queue::remove()
{
    if (front == - 1 || front > end)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        cout<<"Element deleted from queue is: "<<q[front]<<endl;
        front = front + 1;
    }
}

void Queue::display()
{
    int i;
    if (front == - 1)
        cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"Queue is :"<<endl;
        for (i=front; i <=end; i++)
            cout<<q[i]<<endl;
    }
}

int main()
{
  Queue qu;
  qu.display();
  qu.add();
  qu.add();
  qu.display();
  qu.add();
  qu.add();
  qu.display();
  qu.add();
  qu.add();
  qu.display();
  qu.remove();
  qu.remove();
  qu.remove();
  qu.display();
}
