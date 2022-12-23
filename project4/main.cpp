#include <iostream>
using namespace std;
class Complex
{
private :
    float real;
    float img;
public :
    Complex ()
    {
        real=0;
        img=0;
    }
    void setReal(float);
    void setImg(float);
    float getReal();
    float getImg ();
    void setComplex (int r);
    void setComplex (int r,int v);
    friend Complex operator + (float n,Complex c);
    friend Complex operator - (float n,Complex c);
    void print();
    Complex operator+( Complex &c){
        Complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    Complex operator -( Complex &c){
        Complex temp;
        temp.real=real-c.real;
        temp.img=img-c.img;
        return temp;
    }
    Complex operator +(float n){
        Complex temp;
        temp.real=real+n;
        temp.img=img;
        return temp;
    }
    Complex operator - (float n){
        Complex temp;
        temp.real=real-n;
        temp.img=img;
        return temp;
    }
    int operator == (Complex c){
        if (real==c.real && img==c.img){
            return 1;
        }
        else {
            return 0;
        }
    }
    void operator += (Complex c){
        real=real+c.real;
        img=img+c.img;
    }
    Complex operator ++ (){
        real++;
        return *this;
    }
    Complex operator ++ (int){
        Complex temp=*this;
        real++;
        return temp;
    }
    Complex operator -- (){
        real--;
        return *this;
    }
    Complex operator -- (int){
        Complex temp=*this;
        real--;
        return temp;
    }
    operator float(){
        return this->real;
    }
};
Complex operator + (float n,Complex c){
    Complex temp;
    temp.real=c.real+n;
    temp.img=c.img;
    return temp;
}
Complex operator - (float n,Complex c){
    Complex temp;
    temp.real=n-c.real;
    temp.img=c.img;
    return temp;
}
void Complex::setReal(float r)
{
    real=r;
}
void Complex::setImg(float r)
{
    img=r;
}
float Complex::getReal()
{
    return real;
}
float Complex::getImg ()
{
    return img;
}

void Complex::print ()
{
    if (img <0)
    {
        cout<<real<<img<<"i"<<endl;
    }
    else
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
}

int main()
{
    float real,img;
    Complex c1,c2,c3;
    cout<<"enter real and img parts for number 1"<<endl;
    cin>>real>>img;
    c1.setReal(real);
    c1.setImg(img);
    cout <<"enter real and img parts for number 2"<<endl;
    cin>>real>>img;
    c2.setReal(real);
    c2.setImg(img);
    c3 = c1 + c2;
    cout<<"c3 = c1 + c2 = ";
    c3.print();
    c3 = c1 -c2;
    cout<<"c3 = c1 - c2 = ";
    c3.print();
    c3 = c1 + 5;
    cout<<"c3 = c1 + 5 = ";
    c3.print();
    c3 = c1 -5;
    cout<<"c3 = c1 - 5 = ";
    c3.print();
    c3 = 5 + c1;
    cout<<"c3 = 5 + c1 = ";
    c3.print();
    c3 = 5-c1;
    cout<<"c3 = 5 - c1 = ";
    c3.print();
    cout<<"if(c1 == c2) : "<<(c1 == c2)<<endl;
    c1+=c2;
    cout<<"c1 += c2 = ";
    c1.print();
    c3=++c1;
    cout<<"c3=++c1 = ";
    c3.print();
    c3=--c1;
    cout<<"c3=--c1 = ";
    c3.print();
    c3=c1++;
    cout<<"c3=c1++ = ";
    c3.print();
    c3=c1--;
    cout<<"c3=c1-- = ";
    c3.print();
    cout<<"(float)c1 : "<<(float)c1<<endl;

    return 0;
}
