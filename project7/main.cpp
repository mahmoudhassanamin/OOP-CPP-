#include <iostream>
using namespace std;
class Base
{
    int a;
protected:
    int b;
    void print(){
        cout<<"i can access protect print function in  parent"<<endl;
    }
public:
    Base (){
        a=0;
        b=0;
        cout<<"in parent constructor"<<endl;
    }
    Base(int i){
        a=i;
        b=i;
        cout<<"in parent constructor"<<endl;
    }
    ~Base(){
        cout<<"parent is dying"<<endl;
    }
    void setA(int i){
        a=i;
    }
    void setB(int i){
        b=i;
    }
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    void printing(){
        cout<<"print parent"<<endl;
    }
    void printintValues(){
        cout<<"a"<<a<<"\t b"<<b<<endl;
        print();
    }

};
class Derived:public Base
{
    int c;
public:
    Derived():Base(){
        c=0;
        cout<<"in Derived child constructor"<<endl;
    }
    Derived(int i):Base(i){
        c=i;
        cout<<"in Derived child constructor"<<endl;
    }
    ~Derived(){
        cout<<"Derived child is dying"<<endl;
    }
    void setC(int i){
        c=i;
    }
    int getC(){
        return c;
    }
    void printing (){
        cout<<"print Derived child"<<endl;
    }
    void printintValues () {
        cout<<"a:"<<getA()<<"\t b:"<<b<<"\t c:"<<c<<endl; // in Derived child not show the private only show public and protected
        print();
    }
};
class secondDerived:public Derived
{
    int d;
public:
    secondDerived():Derived(){
        d=0;
        cout<<"in second Derived child constructor"<<endl;
    }
    secondDerived(int i):Derived(i){
        d=i;
        cout<<"in second Derived child constructor"<<endl;
    }
    ~secondDerived(){
        cout<<"second Derived child is dying"<<endl;
    }
    void setD(int i){
        d=i;
    }
    int getD(int i){
        return d;
    }
    void printing (){
        cout<<"print second Derived child"<<endl;
    }
    void printintValues () {
        cout<<"a:"<<getA()<<"\t b:"<<b<<"\t c:"<<getC()<<"\t d:"<<d<<endl; // in Derived child not show the private only show public and protected
        print();
    }

};
// void printing(secondDerived obj) // if pass Base obj -> error (error: could not convert 'x' from 'Base' to 'secondDerived')

void printing(Base obj) //if -> (Base &obj)--> the constructor and destructor not ran
{
    cout<<obj.getA()<<endl;
    cout<<obj.getB()<<endl;
}

int main()
{
    secondDerived x(1);
    // printing(x); // pass to -> void printing(secondDerived obj) --> error
    Base y(1);
    printing(y);
    printing(x); //parent is dying --> parent destructor ran
    Base *ptr=&x; //valid
    // secondDerived *ptr2=&y; //error -> invalid conversion from 'Base*' to 'secondDerived*'
    x.printing();
    x.Base::printing();
    x.Derived::printing();
    ptr->printing();
    Derived z(1);
    cout<<"by parent obj only one way (Base)"<<endl;
    y.printintValues();
    cout<<"by derived obj in 2 way (Derived & Base )"<<endl;
    z.printintValues();
    z.Base::printintValues();
    cout<<"by second Derived obj in 3 way (Sec & Derived & Base )"<<endl;
    x.printintValues();
    x.Derived::printintValues();
    x.Base::printintValues();
    return 0;
}
