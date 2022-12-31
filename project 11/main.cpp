#include <iostream>

using namespace std;
template <class T>
class Stack
{
    int tos;
    int size;
    T *st;
    static int discounter;
    static int concounter;
public:
    Stack(int n)
    {
        tos=0;
        size=n;
        st=new T[size];
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
        st=new T[size];
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
        st=new T[size];
        for (int i=0 ; i<size ; i++){
            st[i]=s.st[i];
        }
        return *this;
    }
    void push (T num)
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
    T pop ()
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
    template <class U>
    friend void viewContent(Stack<U> obj);
};
template <class T>
int Stack<T>::discounter=0;
template <class T>
int Stack<T>::concounter=0;
template <class U>
void viewContent(Stack<U> obj)
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
    Stack<int> s1(size);
    Stack<string> s2(size);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push("mahmoud");
    s2.push("hassan");
    s2.push("amin");
    cout<<"stack 1"<<endl;
    viewContent(s1);
    cout<<"stack 2"<<endl;
    viewContent(s2);
    return 0;
}
