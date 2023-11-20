/**
 * Point.cpp
 *
 * EECS 183
 * Lab 7
 * Taken from Project 4: CoolPics
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 * Contains functions of rectangle
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

//default constructor
Point::Point() {
    x = 0;
    y = 0;
}

// non default constructor
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

//setters and getters
void Point::setX(int xVal) {
    x = checkRange(xVal);
    return;
}

int Point::getX() {
    return x;
}    

void Point::setY(int yVal) {
    y = checkRange(yVal);
    return;
}
    
int Point::getY() {
    return y;
}

//read in
void Point::read(istream& ins) {
    char a;
    ins >> a >> x >> a >> y >> a;
    x = checkRange(x);
    y = checkRange(y);
    return;
}    

//write out
void Point::write(ostream& outs) {
    x = checkRange(x);
    y = checkRange(y);
    outs << "(" << x << "," << y << ")";
    return;
}

//checkRange
int Point::checkRange(int val) {
    if(val >= 0 && val < DIMENSION){
        return val;
    }
    else if(val < 0){
        return 0;
    }
    else{
        return DIMENSION - 1;
    } 
}


// Your code goes above this line!!!
// Don't change the implementations below!!!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
