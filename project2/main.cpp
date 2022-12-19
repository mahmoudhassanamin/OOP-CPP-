#include <iostream>

using namespace std;

class Stack {
    private :
        int tos;
        int *st;
        int size;
        static int counter;
    public :
        Stack(int n){
            tos=0;
            size=n;
            st=new int[size];
            counter ++;
        }
        ~Stack(){
            delete [] st;
        }
        static int getCounter() {
            return counter ;
        }
        void push (int num){
            if(tos<size){
                st[tos]=num;
                tos++;
            }
            else {
                cout<<"stack is FULL"<<endl;
            }
        }
        int pop (){
            if(tos>0){
                tos--;
                return st[tos];
            }
            else{
                cout<<"stack is empty"<<endl;
            }
            return 0;
        }

};
int Stack::counter = 0;
int main()
{
    int size;
    cout<<"enter size of your stack : ";
    cin>>size;
    Stack s1(size);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout<<"element 2 : "<<s1.pop()<<endl;
    cout<<"element 1 : "<<s1.pop()<<endl;
    cout<<"element 0 : "<<s1.pop()<<endl;
    Stack s2(size);
    cout<<"you have "<<Stack::getCounter() <<" stack";

    return 0;
}
