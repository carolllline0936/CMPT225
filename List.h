/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is a position-oriented list
 *
 * Author: Danling Yang, Shiyi Zhou 
 * Team name: Crispy Chicken
 * Date: Sep 19th, Thu
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include "Patient.h"


using namespace std;


class List  {

private:

/* 
 * You can add more attributes to this class, 
 * but you cannot remove the attributes below 
 * nor can you change them.
 */

	//static const //
	int MAX_ELEMENTS; // Small capacity so can test when data collection becomes full
	                                   // As we are testing the code of our assignment, we can change the value given to this constant.
	Patient *element;    // Data structure with capacity of MAX_ELEMENTS
	int elementCount;                  // Current element count in element array
	int capacity;                      // Actual maximum capacity of element array   
	
public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default constructor
	List();
	~List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	//  Description: Returns the position of the element in the list 
	int getPosition(Patient& Element);

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(Patient& target);

	// Description: modify a patient's record
    bool modify(Patient& toBeModified);
	
	// Description: Prints all elements stored in List by descending order of care card numbers.
	void printList();

}; // end List.h