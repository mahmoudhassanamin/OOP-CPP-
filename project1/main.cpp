#include <iostream>
using namespace std;
class Complex{
    float real;
    float img;
    public :
        void setReal(float);
        void setImg(float);
        float getReal();
        float getImg () ;
        Complex add (Complex c2);
        Complex sub (Complex c2);
        //swap Fun
        void print();
};

//Complex swapC(Complex c2){
//
//}
//void swapC(Complex &c1,Complex &c2){
//
//}
//void swapC(Complex *,Complex *){
//
//}
void Complex::setReal(float r){
    real=r;
}
void Complex::setImg(float r){
    img=r;
}
float Complex::getReal(){
    return real;
}
float Complex::getImg () {
    return img;
}
Complex Complex::add (Complex c2){
    Complex temp;
    temp.setReal(real + c2.getReal());
    temp.setImg(img + c2.getImg());
    return temp;
}
Complex Complex::sub (Complex c2){
    Complex temp;
    if (real > c2.getReal()){
        temp.setReal(real - c2.getReal());
        temp.setImg(img - c2.getImg());
    }
    else {
        temp.setReal(c2.getReal() - real);
        temp.setImg(c2.getImg() - img);
    }
    return temp;
}
void Complex::print (){
    if (img <0){
        cout <<"result :"<<real<<img<<"i"<<endl;
    }
    else {
        cout <<"result :"<<real<<"+"<<img<<"i"<<endl;
    }
}

int main()
{
    float real,img;
    Complex com1,com2 ,result;
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
    return 0;
}
