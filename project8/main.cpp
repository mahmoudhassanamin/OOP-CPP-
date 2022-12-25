#include <iostream>

using namespace std;
class Shape{
protected:
    string color;
public:
    Shape(){
        color="white";
        cout<<"in parent constructor"<<endl;
    }
    Shape(string c){
        color=c;
        cout<<"in parent constructor"<<endl;
    }
    ~Shape(){
        cout<<"in parent destructor"<<endl;
    }
    void setColor(string c){
        color=c;
    }
    string getColor(){
        return color;
    }
    void draw(){
        cout<<"shap not exist"<<endl;
    }

};
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
    Point(){
        x=0;
        y=0;
        cout<<"at point constructor"<<endl;
        cout<<"x : "<<x<<endl<<"y : "<<y<<endl;
    }
    Point(int i,int j){
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
class Line:public Shape
{
    Point start;
    Point end;
public:
    Line():Shape(),start(),end(){
        cout<<"at line constructor"<<endl;
    }
    Line(int x1,int y1,int x2,int y2,string c):Shape(c),start(x1,y1),end(x2,y2){
        cout<<"at line constructor"<<endl;
    }
    ~Line(){
        cout<<"a line is dying"<<endl;
    }

    void draw(){
        cout<<"Line draw"<<endl;
        cout<<"color : "<<color<<endl;
    }
};
class Rect:public Shape
{
    Point ul;
    Point lr;
public:
    Rect():Shape(),ul(),lr()
    {
        cout<<"at Rect constructor"<<endl;
    }
    Rect(int x1,int y1,int x2,int y2,string c):Shape(c),ul(x1,y1),lr(x2,y2)
    {
        cout<<"at Rect constructor"<<endl;
    }
    ~Rect(){
        cout<<"a Rect is dying"<<endl;
    }
    void draw(){
        cout<<"Rect draw"<<endl;
        cout<<"color : "<<color<<endl;
    }
};
class Circle:public Shape
{
    Point c;
    int r;
public:
    Circle():Shape(),c(){
        r=0;
        cout<<"at Circle constructor"<<endl;
    }
    Circle(int x,int y,int i,string co):Shape(co),c(x,y){
        r=i;
        cout<<"at Circle constructor"<<endl;
    }
    ~Circle(){
        cout<<"a Circle is dying"<<endl;
    }
    void draw(){
        cout<<"circle draw"<<endl;
        cout<<"color : "<<color<<endl;
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
    Picture(){
        lnum=0;
        rnum=0;
        cnum=0;
        pl= NULL;
        pr= NULL;
        pc= NULL;
    }
    Picture(int l,int r,int c,Line *PL,Rect *PR,Circle *PC){
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
        cout<<"start picture"<<endl;
        int i;
        for( i=0 ; i < lnum ; i++ ){
            pl[i].draw();
        }
        for( i=0 ; i < rnum ; i++ ){
            pr[i].draw();
        }
        for( i=0 ; i < cnum ; i++ ){
            pc[i].draw();
        }
        cout<<"end of picture"<<endl;
    }

};


int main()
{
    Line l1;
    Rect r1;
    Circle c1;
    Line l(1,2,3,4,"veskos") ;
    Rect r[2]={Rect(1,2,3,4,"btngany"),Rect(5,6,7,8,"rose")};
    Circle c[3]={Circle(9,10,5,"black"),Circle(11,12,5,"3adsy"),Circle(13,14,5,"meshmeshy")};
    Picture p1(1,2,3,&l,r,c);
    p1.paint();
    Picture p2;
    p2.paint();

    return 0;
}
