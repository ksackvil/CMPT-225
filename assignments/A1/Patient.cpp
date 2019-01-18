/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Table of Contents: 
 * 		- CONSTRUCTORS        - line 22
 * 		- SETTERS AND GETTERS - line 60
 * 		- OVERLOADS           - line 116
 * 
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#include <iostream>
#include <string>
#include "Patient.h"

// ---------- CONSTRUCTORS ---------- //

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() 
{
	careCard = "0000000000";
	name = "To be entered";
	address = "To be entered";
	phone  = "To be entered";
	email = "To be entered";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) 
{
	// Test if card is correct size;
	if(aCareCard.size() != VALID_CARD_SIZE)
	{
		cout << "ERROR: invalid card length, care card set to '0000000000'\n";
		careCard = "0000000000";
	}
	else
	{
		careCard = aCareCard;
	}

	name = "To be entered";
	address = "To be entered";
	phone  = "To be entered";
	email = "To be entered";
}

// ---------- GETTERS & SETTERS ---------- //

// Description: Returns patient's name.
string Patient::getName() const
{
	return(name);
}

// Description: Returns patient's address.
string Patient::getAddress() const
{
	return(address);
}

// Description: Returns patient's phone.
string Patient::getPhone() const
{
	return(phone);
}

// Description: Returns patient's email.
string Patient::getEmail() const
{
	return(email);
}

// Description: Returns patient's care card.
string Patient::getCareCard() const
{
	return(careCard);
}

// Description: Sets the patient's name.
void Patient::setName(const string aName)
{
	name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress)
{
	address = anAddress;
}

// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone)
{
	phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail)
{
	email = anEmail;
}

// ---------- OVERLOADS ---------- //

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) 
{
	
	// Compare both Patient objects
	if (this->careCard == rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) 
{
	
	// Compare both Patient objects
	if (this->careCard > rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) 
{
	os << p.getCareCard() << " - Patient: " 
		<< p.getName() << ", "
		<< p.getAddress() << ", "
		<< p.getPhone() << ", "
		<< p.getEmail() << endl;

	return os;

} // end of operator<<

// end of Patient.cpp