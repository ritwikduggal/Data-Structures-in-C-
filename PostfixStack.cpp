#include<iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;


class Evaluation
{
	public:
		int stk[50];
		int top;
		char str[50];
    void push(int item);
    int pop();
    //if I wrote operator it invokes the declaration of specifying a operator, hence I used a typo version Operatr
    int operatr(int a,int b, char opr);
    int calculatePostfix();
		Evaluation()
    {
			top = -1;
    }
};

void Evaluation::push(int item)
{
	top++;
	stk[top] = item;
}

int Evaluation::pop()
{
	int item = stk[top];
	top--;
	return item;
}

int Evaluation::operatr(int a,int b,char opr)
{
	switch(opr)
  {
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
    case '%':return a%b;
		default: return 0;
	}
}

int Evaluation::calculatePostfix()
{
	int index = 0;
	while(str[index]!='\0')
  {
		if(isdigit(str[index]))
    {
			push(str[index]-'0');
		}
		else
    {
			int x = pop();
			int y = pop();
			int result = operatr(x,y,str[index]);
			push(result);
		}
		index++;
	}
	return pop();
}

int main()
{
	Evaluation eval;
	cout << "Enter the postfix: ";
	cin >> eval.str;
	int result = eval.calculatePostfix();
	cout << "the result is " << result;
  getch();
}
