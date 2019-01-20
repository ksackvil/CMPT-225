#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    Circle *arr;       // Pointer to Circles, initialize to nothing.
    int capacity = 0;         // Size needed for array
    int size = 0;


    cout << "Enter array capacity: ";
    cin >> capacity;          // Read in the size
    arr = new Circle[capacity];  // Allocate n ints and save ptr in a.

    for (int i=0; i<capacity; i++) 
    {
        int x_in = 0;
        int y_in = 0;
        double rad_in = 0.0;
        char cont = '\0';

        cout << "\nEnter values for arr[" << i << "]? (y/n) ";
        cin >> cont;

        if( cont == 'y')
        {
            cout << "\nX coor: ";

            cin >> x_in;

            cout << "Y coor: ";

            cin >> y_in;

            cout << "Radius: ";

            cin >> rad_in;

            arr[i] = Circle(x_in, y_in, rad_in);    // Initialize all elements defaults to 0.

            size++;
        }
        else
        {
            break;
        }
    }

    for (int i=0; i<capacity; i++) 
    {
        if(i+1 > size)
        {
            cout << "\nElement " << i << " is empty\n";
        }
        else 
        {
            cout << "\nElement " << i << endl
                << "X: " << arr[i].getX() << endl
                << "Y: " << arr[i].getY() << endl
                << "Radius: " << arr[i].getRadius() << endl;
        }

    }
    cout << endl;

    cout << "Capacity: " << capacity << endl
        << "Size: " << size << endl
        << "Empty Cells: " << capacity - size << endl;
    
    delete [] arr;  // When done, free memory pointed to by a.
    arr = NULL;     // Clear a to prevent using invalid memory reference.

    return(0);
}

