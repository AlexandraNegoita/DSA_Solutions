#include <iostream>

using namespace std;

// Implement the following structure named Point:
struct Point
{
    //public:
    int n;
    int coord_x, coord_y;//the coordinates of a point
    void reset() //places the point into the origin
    {
        coord_x = coord_y = 0;
    }
    void moveX(int x = 1) {//moves the point horizontally with x positions
        if(coord_x + x > n) {
            coord_x = 0;
        }
        coord_x += x;
    }
    void moveY(int y = 1) { // moves the point vertically with y positions
        if(coord_y + y > n) {
            coord_y = 0;
        }
        coord_y += y;
    }

    void moveXY(int x = 1, int y = 1){ // moves the point horizontally and vertically
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
// Make a program in which you implement the movement of a point within the coordinates of a rectangle
// with the dimensions  1 x N (N given by the user), starting from the origin.
// Compile and run the application!


int main()
{
    int n;
    cout << "N: " ;
    cin >> n;
    Point p1;
    p1.n = n;
    p1.coord_x = 0;
    p1.coord_y = 0;

    p1.moveX(2);
    p1.moveY(2);
    p1.print();
    p1.moveX(4);
    p1.print();
    p1.moveY(3);
    p1.print();
    return 0;
}
