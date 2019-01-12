/*
* Circle.h
*
* Description: This class models a circle in 2d 
*
* Author: Kai Sackville-Hii
* Creation date: Jan 11, 2019
*/

class Circle {

private: 

    int xCoordinate; // x and y coordinates for the circle, these can be negative   
    int yCoordinate;
    double radius; // Center of the circle must be greater than 0.0

public: 

    /* ----- CONSTRUCTORS ----- */
    // Default constructor that creates a circle of radius 10 at position 0,0
    Circle(); 

    // Constructor with parameters for x, y, and radius
    Circle(int x, int y, double rad);

    /* ----- GETTERS ----- */
    int getX() const; // Returns the circle's x coordinate
    int getY() const; // Returns the circle's y coordinate
    double getRadius() const; // Returns the circle's radius

    /* ----- SETTERS ----- */
    // Moves the circle the given horizontal and vertical distances (therefore changing its x and y attributes)
    void move(int horiz, int vert); 

    // Changes the circle's radius to r, or to 10.0 if r is invalid
    void setRadius(double r);

    /* ----- OTHER MEMBERS ----- */
    // Computes and returns the circle's area
    double computeArea();

    // Displays the circle's attributes like this: "radius 10.0 at point x = 12, y = 17"
    void displayCircle();

    bool intersect(Circle c);
};