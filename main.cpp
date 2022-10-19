#include <iostream>
#include <string>
#define MAX 20
using namespace std;

void push(char);
char pop();
string in2prefix(string);
char stk[MAX];
int top = -1;
bool isFull();
bool isEmpty();

bool isFull()
{
    if(top == MAX -1)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(top== -1)
        return true;
    else
        return false;
}

void push(char oper)
{
    if(isFull())
    {
        cout<<" ";
    }
    else
    {
        top++;
        stk[top] = oper;
    }
}

char pop()
{
    char ch;
    if(isEmpty())
    {
        cout<< " ";
    }
    else
    {
        ch = stk[top];
        stk[top]= '\0';
        top--;
        return ch;
    }
    return 0;
}

string in2prefix(string infix)
{
    int i = 0;
    string pst = "";

    while(infix[i]!='\0')
    {
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z')
        {
            pst.insert(pst.end(),infix[i]);
            i++;
        }
        else if(infix[i] == '*' )
        {
            pop();
            i++;
        }
    }

    while(top != -1)
    {
        pst.insert(pst.begin(),pop());
    }
    cout<<"\nSetelah diperbaiki : " << pst <<endl;
    return pst;
}

int main()
{
    string infix,prefix;
    cout << "Pesan rusak : ";
    cin>>infix;
    prefix = in2prefix(infix);
    return 0;
}
