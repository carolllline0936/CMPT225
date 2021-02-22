/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Danling Yang, Shiyi Zhou 
 * Team name: Crispy Chicken
 * Date: Sep 19th, Thu
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
	name="To be entered";
	address="To be entered";
	phone="To be entered";
	email="To be entered";
	carecard="0000000000";

// You need to complete this method.

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
	

	if (aCareCard.size()!=10 || aCareCard=="0000000000"){
		//@Shiyi update here, have to add statement : aCareCard!="0000000000"; or the enter function will go wrong 
		//output will be 0000000000- , , ,
		carecard="0000000000";
		name="To be entered";
	    address="To be entered";
	    phone="To be entered";
	    email="To be entered";
	}
	else{
		carecard= aCareCard;
	}
	
// You need to complete this method.

}


//Getters
string Patient::getName() const{
	return name;
}

string Patient::getAddress() const{
	return address;
}

string Patient::getPhone() const{
	return phone;
}

string Patient::getEmail() const{
	return email;
}

string Patient::getCareCard() const{
	return carecard;
}


//Settters

void Patient::setName(const string aName){
	name=aName;
}


void Patient::setAddress(const string anAddress){
	address=anAddress;

}

void Patient::setPhone(const string aPhone){
	phone=aPhone;
}
void Patient::setEmail(const string anEmail){
	email=anEmail;
}
// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->carecard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->carecard > rhs.getCareCard();
	
} // end of operator >

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.carecard << ", Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp