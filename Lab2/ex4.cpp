#include <iostream>

using namespace std;

// For Exercise 3, replace struct with class and compile and run the application.
// Add getters, setters and constructors to the class and test them.

class Point
{
private:
    int n;
    int coord_x, coord_y;
public:
    Point() {}
    ~Point() {}

    int getN() {
        return this->n;
    }
    void setN(int n) {
        this->n = n;
    }

    int getX() {
        return this->coord_x;
    }
    void setX(int x) {
        this->coord_x = x;
    }

    int getY() {
        return this->coord_y;
    }
    void setY(int y) {
        this->coord_y = y;
    }

    void reset()
    {
        coord_x = coord_y = 0;
    }

    void moveX(int x = 1) {
        if(coord_x + x > n) {
            coord_x = 0;
        }
        coord_x += x;
    }

    void moveY(int y = 1) {
        if(coord_y + y > n) {
            coord_y = 0;
        }
        coord_y += y;
    }

    void moveXY(int x = 1, int y = 1){
        if(coord_x + x > n || coord_y + y > n) {
            reset();
        }
        moveX(x);
        moveY(y);
    }
    void print() {
        cout << "\nThe current coordinates are: \n\tX: " << coord_x << "\n\tY: " << coord_y;
    }
};



int main()
{
    int n;
    cout << "N: " ;
    cin >> n;
    Point p1;
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
    return 0;
}
