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
    ~Complex (){
        cout <<"object died"<<endl;
    }
    void setReal(float);
    void setImg(float);
    float getReal();
    float getImg ();
    void setComplex (int r);
    void setComplex (int r,int v);
    Complex add (Complex c2);
    Complex sub (Complex c2);
    void swapC(Complex &c2);
    void swapC(Complex *c2);
    void print();
};

void Complex::setComplex (int r){
    real=img=r;
}
void Complex::setComplex (int r,int m){
    real=r;
    img=m;
}
void Complex::swapC(Complex &c2)
{
    Complex temp;
    temp.setReal(real);
    temp.setImg(img);
    setReal(c2.getReal());
    setImg(c2.getImg());
    c2.setReal(temp.getReal());
    c2.setImg(temp.getImg());

}
void Complex::swapC(Complex *c2)
{
    Complex temp;
    temp.setReal(real);
    temp.setImg(img);
    setReal(c2->getReal());
    setImg(c2->getImg());
    c2->setReal(temp.getReal());
    c2->setImg(temp.getImg());

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
Complex Complex::add (Complex c2)
{
    Complex temp;
    temp.setReal(real + c2.getReal());
    temp.setImg(img + c2.getImg());
    return temp;
}
Complex Complex::sub (Complex c2)
{
    Complex temp;
    if (real > c2.getReal())
    {
        temp.setReal(real - c2.getReal());
        temp.setImg(img - c2.getImg());
    }
    else
    {
        temp.setReal(c2.getReal() - real);
        temp.setImg(c2.getImg() - img);
    }
    return temp;
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
    Complex com1,com2,result;
    cout<<"enter real and img parts for number 1"<<endl;
    cin>>real>>img;
    com1.setReal(real);
    com1.setImg(img);
    cout <<"enter real and img parts for number 2"<<endl;
    cin>>real>>img;
    com2.setReal(real);
    com2.setImg(img);
    result=com1.add(com2);
    result.print();
    result=com1.sub(com2);
    result.print();
    com1.swapC(com2);
    cout<<"number 1";
    com1.print();
    cout<<"number 2";
    com2.print();
    com1.swapC(&com2);
    cout<<"number 1 : ";
    com1.print();
    cout<<"number 2 : ";
    com2.print();
    com1.setComplex(3);
    com2.setComplex(5);
    cout<<"the two parts are equal \ncomplex 1 : ";
    com1.print();
    cout<<"complex 2 : ";
    com2.print();
    com1.setComplex(50,60);
    com2.setComplex(70,80);
    cout<<"the two parts are NOT equal \ncomplex 1 : ";
    com1.print();
    cout<<"complex 2 : ";
    com2.print();
    return 0;
}

