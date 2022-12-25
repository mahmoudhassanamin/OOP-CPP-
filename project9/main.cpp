#include <iostream>

using namespace std;

class GeoShape
{
protected:
    float dim1;
    float dim2;
    float constant;
public:
    GeoShape()
    {
        dim1=0;
        dim2=0;
        constant=0;
    }
    GeoShape(float d)
    {
        dim1=dim2=d;
        constant=0;
    }
    GeoShape(float d1,float d2)
    {
        dim1=d1;
        dim2=d2;
        constant=0;
    }
    ~GeoShape()
    {
        cout<<"a shape is dying"<<endl;
    }
    void setDim1(float d){
        dim1=d;
    }
    void setDim2(float d){
        dim2=d;
    }
    float getDim1 () {
        return dim1;
    }
    float getDim2 () {
        return dim2;
    }
    int calculateArea()
    {
        cout<<"Shape Not defined"<<endl;
        return 0;
    }

};
class Triangle:public GeoShape
{
public:
    Triangle():GeoShape()
    {
        constant=0.5;
    }
    Triangle(float d1,float d2):GeoShape(d1,d2)
    {
        constant=0.5;
    }
    ~Triangle()
    {
        cout<<"a Triangle is dying"<<endl;
    }
    int calculateArea()
    {
        return (constant * dim1 * dim2);
    }
};
class Rect:public GeoShape
{
public:
    Rect():GeoShape()
    {
        constant=1;
    }
    Rect(float d1,float d2):GeoShape(d1,d2)
    {
        constant=1;
    }
    ~Rect()
    {
        cout<<"a Rect is dying"<<endl;
    }
    void setRectDim(float d1,float d2)
    {
        dim1=d1;
        dim2=d2;
    }
    float getRectDim1 ()
    {
        return dim1;
    }
    float getRectDim2 ()
    {
        return dim2;
    }
    int calculateArea()
    {
        return (constant * dim1 * dim2);
    }

};
class Square:private Rect
{
public:
    Square():Rect()
    { }
    Square(float d):Rect(d,d)
    { }
    ~Square()
    {
        cout<<"a square is dying"<<endl;
    }
    void setSquareDim (float d)
    {
        dim1=dim2=d;
    }
    float getSquareDim ()
    {
        return dim1;
    }
    int calculateArea()
    {
        return (constant * dim1 * dim2);
    }

};
class Circle :private GeoShape
{
    public:
    Circle():GeoShape()
    { }
    Circle(float r):GeoShape(r)
    {
        constant=3.1428571428;
    }
    ~Circle()
    {
        cout<<"a Circle is dying"<<endl;
    }
    void setCircleRidus (float r)
    {
        dim1=dim2=r;
    }
    float getCircleRidus()
    {
        return dim1;
    }
    int calculateArea()
    {
        return ( constant* dim1* dim2);
    }

};
int main()
{
    Triangle t1(2,8);
    cout<<"Triangle area = "<<t1.calculateArea()<<endl;
    Rect r1(2,3);
    cout<<"Rect area = "<<r1.calculateArea()<<endl;
    Square s1(3);
    cout<<"Square area = "<<s1.calculateArea()<<endl;
    Circle c1(7);
    cout<<"Circle area = "<<c1.calculateArea()<<endl;
    return 0;
}
