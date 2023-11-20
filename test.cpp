/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

void file_check();
void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Circle();
    test_Rectangle();
    test_Line();
    test_Triangle();
    file_check();
    return;
}

void file_check() {

    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("data1.txt");

    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open data1.txt" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    ins.close();
    
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
         << "," << p1.getY()
         << ")" << endl;
    
    return;
}

void test_Color() {
    cout << "######################################################" << endl;
    cout << "Now testing Color" << endl;
    Color c1;
    cout << "Expected: 0 0 0, Actual: " << c1 << endl;
    
    Color c2(10, 20, 30);
    cout << "Expected: 10 20 30, Actual: " << c2 << endl;

    c1.setBlue(175);
    cout << "Expected: 175, Actual: " << c1.getBlue() << endl;

    c1.setRed(260);
    cout << "Expected: 255, Actual: " << c1.getRed() << endl;
    c1.setRed(-260);
    cout << "Expected: 0, Actual: " << c1.getRed() << endl;
    c1.setGreen(260);
    cout << "Expected: 255, Actual: " << c1.getGreen() << endl;
    c1.setGreen(-260);
    cout << "Expected: 0, Actual: " << c1.getGreen() << endl;

    c1.setBlue(260);
    cout << "Expected: 255, Actual: " << c1.getGreen() << endl;
    c1.setBlue(-260);
    cout << "Expected: 0, Actual: " << c1.getGreen() << endl;

    
    cout << "Expected: 0, Actual: ";
    cout << c1.getGreen() << endl;
}

void test_Circle(){
    cout << "######################################################" << endl;
    cout << "Now testing Circle" << endl;
    
    Circle c1;
    cout << "Expected: (0,0) 0 000, Actual: " << c1.getCenter()
    << " " << c1.getRadius() << " " << c1.getColor() << endl;
    
    int r = 5;
    Point pt(1,4);
    Point pt2(111,20);
    Color c(255, 255, 0);
    Color color2(0, 0, 255);
    
    Circle c2(pt, r, c);
    cout << "Expected: (1,4) 5 2552550, Actual: " << c2.getCenter()
    << " " << c2.getRadius() << " " << c2.getColor() << endl;
    
    Circle c4(pt2, r, color2);
    cout << "Expected: (1,4) 5 00255, Actual: " << c4.getCenter()
    << " " << c4.getRadius() << " " << c4.getColor() << endl;
    
    
    c1.setCenter(pt);
    cout << "Expected: (1,4), Actual: " << c1.getCenter() << endl;
    
    c1.setRadius(r);
    cout << "Expected:5, Actual: " << c1.getRadius() << endl;
    int r2 = -5;
    c1.setRadius(r2);
    cout << "Expected:5, Actual: " << c1.getRadius() << endl;

    Circle c3(pt, r2, c);
    cout << "Expected: (1,4) 5 35130, Actual: " << c2.getCenter()
    << " " << c2.getRadius() << " " << c2.getColor() << endl;

}

void test_Rectangle(){
    cout << "######################################################" << endl;
    cout << "Now testing Rectangle" << endl;
    Point p1(1,10);
    Point p2(2,30);
    Color c(2,45,150);
    Color c2(0,43,23);
    Color c3(2,45,56);
    Color c4(45,56,76);
    
    
    Rectangle r1;
    cout << "Expected: (0,0) (0,0) 000 000 000 000" << endl << "Actual:   ";
    cout << r1.getStart() << " " << r1.getEnd() << " " << r1.getColorTopLeft()
    << " " << r1.getColorTopRight() << " " << r1.getColorBottomRight()
    << " " << r1.getColorBottomLeft() << endl;
    
    Rectangle r2(p1, p2, c);
    cout << "Expected: (1,10) (2,30) 245150 245150 245150 245150"
    << endl << "Actual:   ";
    cout << r2.getStart() << " " << r2.getEnd() << " " << r2.getColorTopLeft()
    << " " << r2.getColorTopRight() << " " << r2.getColorBottomRight()
    << " " << r2.getColorBottomLeft() << endl;

    Rectangle r3(p1, p2, c, c2, c3, c4);
    cout << "Expected: (1,10) (2,30) 245150 04323 24556 455676" <<
    endl << "Actual:   ";
    cout << r3.getStart() << " " << r3.getEnd() << " " << r3.getColorTopLeft()
    << " " << r3.getColorTopRight() << " " << r3.getColorBottomRight()
    << " " << r3.getColorBottomLeft() << endl;

    
    r1.setColor(c);
    cout << "Expected: 245150 245150 245150 245150" << endl << "Actual:   ";
    cout << r1.getColorTopLeft() << " " << r1.getColorTopRight() << " " 
    << r1.getColorBottomRight() << " " << r1.getColorBottomLeft() << endl << endl;
    r1.setStart(p2);
    cout << "Expected: (2,30), Actual: " << r1.getStart() << endl;
    
}

void test_Line(){
    cout << "######################################################" << endl;
    cout << "Now testing Line" << endl;
    Point p1(1,10);
    Point p2(2,30);
    Color c(2,45,150);

    Line l1;
    cout << "Expected: (0,0) (0,0) 000 Actual: " << l1.getStart() << " "
    << l1.getEnd() << " " << l1.getColor() << endl;
    
    Line l2(p1, p2, c);
    cout << "Expected: (1,10) (2,30) 2451450 Actual: " << l2.getStart()
    << " " << l2.getEnd()
    << " " << l2.getColor() << endl;
    
    cout << "Expected: (1, 10), Actual: " << l2.getStart() << endl;
    
    l1.setEnd(p2);
    cout << "Expected: (2,30), Actual: " << l1.getEnd();
    
    cout << "Expected: (0,0) (0,0) 0 0 0 Actual: ";
    l1.write(cout);
    cout << endl << endl;
}

void test_Triangle(){
    cout << "######################################################" << endl;
    cout << "Now testing Triangle" << endl;
    Point p1(1,10);
    Point p2(2,30);
    Point p3(3,45);
    Color c(2,45,150);
    Color c2(0,43,23);
    Color c3(2,45,56);
    
    Triangle t0;
    
    Triangle t1(p1, p2, p3, c);
    cout << "Expected: (1,10) (2,30) (3,45) 245150" << endl
    << "Actual:   "<< t1.getVertexOne() << " " << t1.getVertexTwo()
    << " " << t1.getVertexThree() << " " << t1.getVertexOneColor() << endl;
    
    Triangle t2(p1, c, p2, c2, p3, c3);
    cout << "Expected: (1,10) 245150 (2,30) 04323 (3,45) 24556"
    << endl << "Actual:   "
    << t2.getVertexOne() << " " << t2.getVertexOneColor() << " " << t2.getVertexTwo()
    << " " << t2.getVertexTwoColor() << " " << t2.getVertexThree() << " "
    << t2.getVertexThreeColor() << endl;
    
    
    cout << "Expected: (1,10), Actual: " << t1.getVertexOne() << endl;
    cout << "Expected: 24556, Actual: " << t2.getVertexThreeColor() << endl;
    cout << "Expected: 04323, Actual: " << t2.getVertexTwoColor() << endl;
    cout << "Expected: 245150, Actual: " << t2.getVertexOneColor() << endl;
    
    
    t0.setVertexOne(p1);
    cout << "Expected: (1,10), Actual: " << t0.getVertexOne() << endl;
    t0.setVertexTwo(p2);
    cout << "Expected: (2,30), Actual: " << t0.getVertexTwo() << endl;
    t0.setVertexThree(p3);
    cout << "Expected: (3,45), Actual: " << t0.getVertexThree() << endl;

    
    
    cout << "Expected: T(1,10) 2 45 150 (2,30) 2 45 150 (3,45) 2 45 150"
    << endl << "Actual:   ";
    t1.write(cout);
    cout << endl;

}
