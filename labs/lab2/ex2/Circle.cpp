/*
* Circle.cpp
*
* Description: This is the class implementation for Circle.h
*
* Author: Kai Sackville-Hii
* Creation date: Jan 11, 2019
*/

#include <iostream>
#include <math.h>
#include "Circle.h"    

using namespace std;

Circle::Circle()
{
    xCoordinate = 0;
    yCoordinate = 0;
    radius = 10;
}

Circle::Circle(int x, int y, double rad)
{
    xCoordinate = x;
    yCoordinate = y;
    radius = rad;
}

int Circle::getX() const
{
    return(xCoordinate);
}

int Circle::getY() const
{
    return(yCoordinate);
}

double Circle::getRadius() const 
{
    return(radius);
}

void Circle::move(int horiz, int vert)
{
    // maybe to some edge case tests?
    xCoordinate += horiz;
    yCoordinate += vert;
}

void Circle::setRadius(double r) 
{
    radius = r;
}

double Circle::computeArea() 
{
    return(M_PI * pow(radius, 2.0));
}

void Circle::displayCircle()
{
    cout << "radius " << radius << " at point x=" << xCoordinate << ", y=" << yCoordinate << endl;
}

bool Circle::intersect(Circle c)
{   
    int x0 = xCoordinate;
    int y0 = yCoordinate;
    double r0 = radius;

    int x1 = c.getX();
    int y1= c.getY();
    double r1 = c.getRadius();

    double dist = sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));

    // if circles are seperate or one contains the other
    if(dist > r0 + r1 || dist < abs(r0 - r1)) 
    {
        return(false);
    }
    // else the intersect
    else
    {
        return(true);
    }
}