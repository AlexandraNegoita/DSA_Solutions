#include <iostream>

using namespace std;

// Change the class Point from the previous lab by using templates (the x and y coordinates are of type T).
template <typename T>
class Point{
    private:
        T N;
        T coordX, coordY;

    public:

        Point(){}
        Point(T x, T y)
        {
            this->coordX=x;
            this->coordY=y;
        }
        ~Point(){}
        void reset(){
            coordX = coordY = 0;
        }

        void moveX(T x){
            if(coordX + x > N){
                coordX = 0;
                return;
            }
            coordX += x;
        }

        void moveY(T y){
            if(coordY + y > N){
                coordY = 0;
                return;
            }
            coordY += y;
        }

        void moveXY(T x, T y){
            if(coordX + x > N || coordY + y > N){
                reset();
                return;
            }
            moveX(x);
            moveY(y);
        }

        void print(){
            cout << coordX << " ";
            cout << coordY << endl;
        }

        //getters
        T getX()
        {
            return coordX;
        }
        T getY()
        {
            return coordY;
        }
        //setters
        void setX(T x)
        {
            this->coordX=x;
        }
        void setY(T y)
        {
            this->coordY=y;
        }
        void setN(T N)
        {
            this->N=N;
        }
};

int main()
{
    float n;
    cout << "N: " ;
    cin >> n;
    Point <float> p2;

    Point <int> p1;

    p1.setN(n);
    p1.setX(0);
    p1.setY(0);

    p1.moveX(2);
    p1.moveY(2);
    p1.print();
    p1.moveX(4);
    p1.print();
    p1.moveY(3);
    p1.print();

    cout << "P2:" <<  endl;
    p2.setN(2.1);
    p2.setX(0.5);
    p2.setY(0.6);

    p2.print();
    return 0;
}
