#include<iostream>
using namespace std;

class student
{
public:
   student(){ }
   int roll;
   char name[30];
   float cgpi;
   int sem;
   void getData();
   void displayData();
};

void student :: getData()
{
   cout<<endl<<"Enter Roll No. ";
   cin>>roll;
   cout<<endl<<"Enter Name: ";
   cin>>name;
   cout<<endl<<"Enter Semester: ";
   cin>>sem;
   cout<<endl<<"Enter CGPI: ";
   cin>>cgpi;
   cout<<endl;
}

void student :: displayData()
{
   cout<<endl<<"Roll No. "<<roll<<endl;
   cout<<"Name: "<<name<<endl;
   cout<<"Sem: "<<sem<<endl;
   cout<<"CGPI: "<<cgpi<<endl;
}

int main()
{
   int n;
   cout<<"Enter number of students: ";
   cin>>n;
   student s[20];
   for (int i=0; i <n; i++)
    {
      s[i].getData();
    }

   cout<<"Enter cutoff value: ";
   int c;
   cin>>c;
   cout<<endl;
   for (int i=0; i<n; i++)
    {
      if(s[i].cgpi>=c)
      {
        s[i].displayData();
      }
    }
    int kp;
    cout<<"Which position do you want to add the student?"<<endl;
    cin>>kp;
    for(int i=kp; i<n; i++)
    {
      s[i+1]=s[i];
    }
    cout<<"Enter details of student"<<endl;
    s[kp].getData();
    cout<<"Added, here is the new list"<<endl;
    n++;
    for(int i=0; i<n; i++)
    {
      s[i].displayData();
    }

   return 0;
}
