/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is a position-oriented list
 *
 * Author: Danling Yang, Shiyi Zhou 
 * Date: Sep 26, 2019
 */


#include<iostream>
#include<string>
#include<string.h>
#include "List.h"


// Default constructor
List::List(){

    this-> MAX_ELEMENTS=10;
    this-> elementCount = new int[10];
    this-> capacity = new int[10];
    for (int i = 0; i < 10; i++){
        this->elementCount[i] = 0;
        this->capacity[i] = 3;
    }
    this-> element= new Patient*[10];
    for (int i = 0; i < 10; i++)
    {
        element[i]=new Patient[capacity[i]];
    }
}


List::List(const List& lst){


	this->elementCount = new int[10];
	this->capacity = new int[10];
	this->element = new Patient * [10];


    this-> MAX_ELEMENTS = lst.MAX_ELEMENTS;


	for (int i = 0; i < 10; i++) {
		this->elementCount[i] = lst.elementCount[i];
		this->capacity[i] = lst.capacity[i];
	}


	for (int i = 0; i < 10; i++)
	{
		element[i] = new Patient[capacity[i]];
		for (int j = 0; j < elementCount[i]; j++) {
			this->element[i][j] = lst.element[i][j];
		}
	}

}

//destructor
List::~List(){
    for (int i=0; i<10; i++){
        delete[] this-> element[i];
    }
    delete[] this-> element;
    delete[] this-> capacity;
    delete[] this-> elementCount;
    this-> MAX_ELEMENTS=0;
}


// Description: Returns the total element count currently stored in List.
int List::getElementCount() const{
    int sum = 0; 
    for (int i=0; i<10; i++){
        sum += elementCount[i];
    }
    return sum;
}


// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(Patient& newElement){
	cout << "Inserting " << newElement << endl;
    string careCard = newElement.getCareCard();
    int num = static_cast<int>(careCard[0])-48;

    for (int i=0;i<elementCount[num];i++){
        if (newElement.getCareCard()==element[num][i].getCareCard()){
            cout<<"there is a same carecard numeber! bad input"<<endl;
            return false;
        }
    }//update: no same carecard number should be in the list
	
    if (static_cast<float>(elementCount[num]) / capacity[num] >= 0.8)
    {  
        capacity[num]*=2;
        Patient* temp = new Patient[capacity[num]];

		for (int i = 0; i < elementCount[num]; i++) {
			temp[i] = element[num][i];
		}
		delete[] element[num];
		element[num] = temp;
    }
    int i = elementCount[num];
	if(i==0){
        element[num][0]=newElement;
    }
    else{
        while (i>=1&&newElement.getCareCard()<=element[num][i-1].getCareCard()){
            element[num][i]=element[num][i-1];
            i--;
        }
        element[num][i] = newElement;
    }
	elementCount[num]++;


    return true;
}



// Description: get the position of an patient
// Postcondition: return the position if successfully found or return false
int List ::getPosition(const Patient& Element){
	string careCard = Element.getCareCard();
    int num = static_cast<int>(careCard[0])-48;
    for (int pos=0;pos<elementCount[num];pos++){
        if (element[num][pos]==Element){
            return pos;
        }
    }
    //dosen't find the element or error happen
    return -1;
}



// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented. 
bool List::remove( const Patient& toBeRemoved ){

	if (search(toBeRemoved) == NULL)
		return false;

    int num = static_cast<int>(toBeRemoved.getCareCard()[0])-48;
	Patient* temp = new Patient[capacity[num]];
	bool found = false;


	for (int i = 0; i < elementCount[num]; i++) {
        //update: may compare the card number
		if (element[num][i].getCareCard()== toBeRemoved.getCareCard()) {
			found = true;
            cout<<toBeRemoved.getCareCard()<<"is found!"<<endl;
            elementCount[num]--;//update (problems:remove, then 000..,tbm,tbm, in the list)
		}
        if(found){
            temp[i]=element[num][i+1];
        }
        else{
            temp[i]=element[num][i];
        }
	}
    
    delete[] element[num];
    element[num]=temp;
    
    return true;
}


// Description: Remove all elements.
void List::removeAll(){
    for (int i=0; i<10; i++){
        delete[] this-> element[i];
		this->elementCount[i] = 0;
		this->element[i] = new Patient[capacity[i]];
    }
   
}


//Description: search the patients by their carecard number
//Precondition: either the patient is in the system or not
//Postcodition: return the patient's profile if found
Patient* List::search(const Patient& target){
    int num = static_cast<int>(target.getCareCard()[0])-48;
    for (int i = 0; i < elementCount[num]; i++)
    {
        if (element[num][i]==target)
        {
            return &element[num][i];
        }
    }
    return NULL;
}


// Description: modify a patient's record
// Precondition: carecard number must not be modified
// Postcondition: new records(name, address, email, phone) have been replaced correctly
bool List::modify(Patient& toBeModified){
    string name, address, phone, email;
    string answer;
    int num = static_cast<int>(toBeModified.getCareCard()[0])-48;

    for (int i=0; i < elementCount[num]; i++){
        if ( element[num][i]==toBeModified )
        {
    
            cout <<"Do you want to modify the patient's name? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new name: ";
                getline(cin>>ws,name );//cin >> name;
                element[num][i].setName(name);
            }
            cout <<"Do you want to modify the patient's address? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new address: ";
                getline(cin>>ws,address );//cin >> address;
                element[num][i].setAddress(address);
            }
            cout <<"Do you want to modify the patient's phone number? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new phone number: ";
                getline(cin>>ws,phone );//cin >> phone;
                element[num][i].setPhone(phone);
            }
            cout <<"Do you want to modify the patient's email? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new email: ";
                getline(cin>>ws,email );//cin >> email;
                element[num][i].setEmail(email);
            }
            return true;
        }
    }
    return false;
}


// Description: Prints all elements stored in List by descending order of care card numbers.
void List::printList(){
    for (int i=9;i>=0;i--){
        for( int j=elementCount[i]-1; j>=0;j--){
            cout << element[i][j] << endl;
        }
    }
}
