    /*
 * List.cpp
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


#include<iostream>
#include<string>
#include<string.h>
#include "List.h"


// Default constructor
List::List(){
    this->MAX_ELEMENTS=10;
    this-> elementCount=0;
    this->capacity = 3;
    this-> element = new Patient[this->capacity];//@danling change here!!
}
 
//destructor
List::~List(){
    delete[] this-> element;
    this-> MAX_ELEMENTS=0;
    this->capacity=0;
    this-> elementCount=0;//@danling change here!!
}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const{
    return elementCount;
}

// Description: get the position of an patient
// Postcondition: return the position if successfully found or return false
int List ::getPosition(Patient& Element){
    for (int pos=0;pos<elementCount;pos++){
        if (Element==element[pos]){
            return pos;
        }
    }
    //dosen't find the element or error happen
    return -1;
}
//==============================================//
//==============================================//
//======ONLY INSERT AT THE END OF THE LIST======//
//==============================================//
//==============================================//

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(Patient& newElement){



    if (elementCount>=MAX_ELEMENTS)
        return false;

    element[elementCount]=newElement;
    elementCount++;
   
    if (static_cast<float>(elementCount)/capacity >= 0.8){
        if (capacity*2<=MAX_ELEMENTS)
            capacity *= 2;
        else
            capacity = MAX_ELEMENTS;
        Patient* temp = new Patient[capacity];
        for (int i = 0; i < elementCount; i++){
            temp[i] = this->element[i];
        }
        delete[] element;
        element = temp;

    }
    //sort list here
    for (int i=0;i<elementCount;i++){
        for (int j=i+1;j<elementCount;j++){
            if((element[j].getCareCard())>=(element[i].getCareCard())){
                Patient temp=element[j];
                element[j]=element[i];
                element[i]=temp;
            }
        }
    }

    return true;

}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented. 
bool List::remove(Patient& toBeRemoved ){
   
    //CAN_BE_REMOVE except empty list
    bool canberemove=(elementCount>0);//bool canberemove=(elementCount>1);
    
    int pos=getPosition(toBeRemoved);
    if (pos==-1) canberemove=0;

    if(canberemove){
        for (int Newpos=pos;Newpos<elementCount-1;Newpos++){
        
            element[Newpos]=element[Newpos+1];

        }
        elementCount--;
        
    }
    return canberemove;


}

// Description: Remove all elements.
void List::removeAll() {
    delete[] this->element;
    this->element = new Patient[capacity];
   elementCount=0;
} 


//Description: search the patients by their carecard number
//Precondition: either the patient is in the system or not
//Postcodition: return the patient's profile if found
Patient* List::search(Patient& target){
    for (int i=0;i<elementCount;i++){
        if(element[i].getCareCard()==target.getCareCard()) 
            {return &element[i];}//@danling & is required

    }
    return NULL;

}

// Description: modify a patient's record
// Precondition: carecard number must not be modified
// Postcondition: new records(name, address, email, phone) have been replaced correctly
bool List::modify(Patient& toBeModified){
    string name, address, phone, email;
    string answer;
    for (int i=0; i < elementCount; i++){
        if ( element[i]==toBeModified )
        {
    
            cout <<"Do you want to modify the patient's name? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new name: ";
                getline(cin>>ws,name );//cin >> name;
                element[i].setName(name);
            }
            cout <<"Do you want to modify the patient's address? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new address: ";
                getline(cin>>ws,address );//cin >> address;
                element[i].setAddress(address);
            }
            cout <<"Do you want to modify the patient's phone number? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new phone number: ";
                getline(cin>>ws,phone );//cin >> phone;
                element[i].setPhone(phone);
            }
            cout <<"Do you want to modify the patient's email? Please enter 1 for Yes or 2 for No" << endl;
            cin >> answer;
            if (answer == "1")
            {
                cout << "Enter new email: ";
                getline(cin>>ws,email );//cin >> email;
                element[i].setEmail(email);
            }
            return true;
        }
    }
    return false;
}


// Description: Prints all elements stored in List by descending order of care card numbers.
void List::printList(){


    for (int i=0;i<elementCount;i++){
        cout<<element[i]<<endl;

    }


}