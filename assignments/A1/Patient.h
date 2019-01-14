/*
 * Patient.h
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Table of Contents: 
 * 		- CONSTRUCTORS -
 * 		- SETTERS AND GETTERS -
 * 		- OTHER METHODS -
 * 
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#pragma once

#include <string>

using namespace std;


class Patient 
{
	
private:

	string name;
	string address;
	string phone;
	string email;
	string careCard;

	// Constant to control how many chars must be in the careCard string
	// static ensures only one copy of this const is created (stays stored in the same 
	// location throughout execution). Initialized to 10.
	static const int VALID_CARD_SIZE = 10; 

public:

/* 
 * You can add more methods to this public interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// ---------- CONSTRUCTORS ---------- //

	// Default Constructor
	// Description: Create a patient with a care card number of "0000000000". 
	// Postcondition: All data members set to "To be entered", 
	//                except the care card number which is set to "0000000000".       
	Patient();

	// Parameterized Constructor
	// Description: Create a patient with the given care card number.
	// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
	//                All other data members set to "To be entered".
	Patient(string aCareCard);

	// ---------- GETTERS & SETTERS ---------- //

	// Description: Returns patient's name.
	string getName() const;

	// Description: Returns patient's address.
	string getAddress() const;

	// Description: Returns patient's phone.
	string getPhone() const;

	// Description: Returns patient's email.
	string getEmail() const;
	
	// Description: Returns patient's care card.
	string getCareCard() const;

	// Description: Sets the patient's name.
	void setName(const string aName);

	// Description: Sets the patient's address.
	void setAddress(const string anAddress);

	// Description: Sets the patient's phone.
	void setPhone(const string aPhone);

	// Description: Sets the patient's email.
	void setEmail(const string anEmail);

	// ---------- OTHER METHODS ---------- //

	// Overloaded Operators
	// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if both Patient objects have the same care card number.
	bool operator == (const Patient & rhs);

	// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the care card number of "this" Patient object is > the care card 
	//              number of "rhs" Patient object.
	bool operator > (const Patient & rhs);
	
	// Description: Prints the content of "this".
    friend ostream & operator<<(ostream & os, const Patient & p);

}; // end of Patient.h