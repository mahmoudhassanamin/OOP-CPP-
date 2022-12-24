#include <iostream>

using namespace std;
class Point{
    int x;
    int y;
public:
    void setX(int i){
        x=i;
    }
    void setY(int i){
        y=i;
    }
    int getX(){
    return x;
    }
    int getY(){
    return y;
    }
    Point(int i=0,int j=0){
        x=i;
        y=j;
        cout<<"at point constructor"<<endl;
        cout<<"x : "<<x<<endl<<"y : "<<y<<endl;
    }
    ~Point(){
        cout<<"a point is dying"<<endl;
        cout<<"x : "<<x<<endl<<"y : "<<y<<endl;
    }
};
class Line {
    Point start;
    Point end;
public:
    Line(int x1=0,int y1=0,int x2=0,int y2=0):start(x1,y1),end(x2,y2){
        cout<<"at line constructor"<<endl;
    }
    ~Line(){
        cout<<"a line is dying"<<endl;
    }

    void draw(){
        cout<<"Line draw"<<endl;
    }
};
class Rect {
    Point ul;
    Point lr;
public:
    Rect(int x1=0,int y1=0,int x2=0,int y2=0):ul(x1,y1),lr(x2,y2)
    {
        cout<<"at Rect constructor"<<endl;
    }
    ~Rect(){
        cout<<"a Rect is dying"<<endl;
    }
    void draw(){
        cout<<"Rect draw"<<endl;
    }
};
class Circle{
    Point c;
    int r;
public:
    Circle(int x=0,int y=0,int i=0):c(x,y){
        r=i;
        cout<<"at Circle constructor"<<endl;
    }
    ~Circle(){
        cout<<"a Circle is dying"<<endl;
    }
    void draw(){
        cout<<"circle draw"<<endl;
    }
};
class Picture{
    Line *pl;
    Rect *pr;
    Circle *pc;
    int lnum;
    int rnum;
    int cnum;
public:
    Picture(int l=0,int r=0 ,int c=0,Line *PL= NULL ,Rect *PR= NULL ,Circle *PC= NULL ){
        lnum=l;
        rnum=r;
        cnum=c;
        pl=PL;
        pr=PR;
        pc=PC;
    }
    void setLines(int n,Line *l){
        lnum=n;
        pl=l;
    }
    void setRect(int n,Rect *r){
        rnum=n;
        pr=r;
    }
    void setCircle(int n,Circle *c){
        cnum=n;
        pc=c;
    }
    ~Picture(){
        cout<<"a picture is dying"<<endl;
    }
    void paint(){
        cout<<"picture"<<endl;
        int i;
        for( i=0 ; i < lnum ; i++ ){
            pl[i].draw();
        }
        for( i=0 ; i < lnum ; i++ ){
            pr[i].draw();
        }
        for( i=0 ; i < lnum ; i++ ){
            pc[i].draw();
        }
        cout<<"end of picture"<<endl;
    }

};

int main()
{
    Line l1;
    l1.draw();
    Rect r1;
    r1.draw();
    Circle c1;
    c1.draw();
    Line l(1,2,3,4) ;
    Rect r[2]={Rect(1,2,3,4),Rect(5,6,7,8)};
    Circle c[3]={Circle(9,10,5),Circle(11,12,5),Circle(13,14,5)};
    Picture p1(1,2,3,&l,&r[0],&c[0]);
    p1.paint();
    Picture p2;
    p2.paint();
    return 0;
}
