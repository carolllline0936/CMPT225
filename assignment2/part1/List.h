/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Elements are kept in descending sorted order of element's search key.
 *
 * Author: Shiyi Zhou, Danling Yang
 * Date: Sep 26, 2019
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:

	int MAX_ELEMENTS;     // Small capacity so can test when data collection becomes full
	int *elementCount;     // Current total sum of elements in all arrays
	int *capacity;         // Actual maximum capacity of each element subarray 

	Patient **element;    // Data structure with capacity of MAX_ELEMENTS

public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default constructor
	List();

	// Copy constructor
	List(const List& lst);

	// Destructor
	~List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.     
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.  
	bool insert(Patient& newElement);

	//  Description: Returns the position of the element in the list 
	int getPosition(const Patient& Element);

	// Description: modify a patient's record
    bool modify(Patient& toBeModified);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
	
	// Description: Prints all elements stored in List.
	void printList();

}; // end List.h  