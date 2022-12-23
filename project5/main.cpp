#include <iostream>

using namespace std;
class Stack
{
    int tos;
    int size;
    int *st;
    static int discounter;
    static int concounter;
public:
    Stack(int n)
    {
        tos=0;
        size=n;
        st=new int[size];
        concounter++;
        cout<<"number of calls of Constructor : "<<Stack::getConcounter()<<endl;
    }
    ~Stack()
    {
        discounter++;
        delete [] st;
        cout<<"number of calls of Discounter : "<<Stack::getDiscounter()<<endl;
        cout<<"object died"<<endl;
    }
    // copy constractor
    Stack(Stack &z)
    {
        tos=z.tos;
        size=z.size;
        st=new int[size];
        for(int i=0 ; i<size ; i++)
        {
            st[i]=z.st[i];
        }
        concounter++;
        cout<<"number of calls of Constructor : "<<Stack::getConcounter()<<endl;
    }
    static int getDiscounter ()
    {
        return discounter;
    }
    static int getConcounter ()
    {
        return concounter;
    }
    Stack& operator = (Stack &s){
        tos=s.tos;
        size=s.size;
        st=new int[size];
        for (int i=0 ; i<size ; i++){
            st[i]=s.st[i];
        }
        return *this;
    }
    void push (int num)
    {
        if (tos<size)
        {
            st[tos]=num;
            tos++;
        }
        else
        {
            cout<<"stack is FULL"<<endl;
        }
    }
    int pop ()
    {
        if (tos>0)
        {
            tos--;
            return st[tos];
        }
        else
        {
            cout<<"stack is EMPTY"<<endl;
        }
    }
    friend void viewContent(Stack obj);
};
int Stack::discounter=0;
int Stack::concounter=0;
void viewContent(Stack obj)
{
    for(int i=0 ; i<obj.size ; i++)
    {
        cout<<"element "<<i<<": "<<obj.st[i]<<endl;
    }
}
int main()
{
    int size;
    cout<<"enter size of your stack : ";
    cin>>size;
    Stack s1(size);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack s2(size),s3(size);
    s3=s2=s1;
    cout<<"stack 1"<<endl;
    viewContent(s1);
    cout<<"stack 2"<<endl;
    viewContent(s2);
    cout<<"stack 3"<<endl;
    viewContent(s3);
    return 0;
}
