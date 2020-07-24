#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
	class QNode
	{
	  public:
			int data;
	    QNode* next;
	    QNode(int d)
	    {
	        data = d;
	        next = NULL;
	    }
  };
public:
		QNode *front, *end;
    void insert(int x);
    void remove();
		Queue()
    {
        front = NULL;
				end = NULL;
    }
};
void Queue :: insert(int x)
{

		QNode* temp = new QNode(x);

		if (end == NULL)
		{
				front = temp;
				end = temp;
		}
		end->next = temp;
		end = temp;
}

void Queue :: remove()
{
		if (front == NULL)
		{
				return;
     }

		QNode* temp = front;
		front = front->next;

		if (front == NULL)
		{
				end = NULL;
    }

		delete (temp);
}

int main()
{

    Queue q;
    q.insert(10);
    q.insert(20);
    q.remove();
    q.remove();
    q.insert(30);
    q.insert(40);
    q.insert(50);
    q.remove();
    cout << "Queue Front: "<< (q.front)->data << endl;
    cout << "Queue End: "<< (q.end)->data;
}
