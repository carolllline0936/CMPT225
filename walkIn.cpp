/*
 * Walkin.cpp
 * 
 * Class Description: A hospital patient system 
 * We use a List ADT
 *                   
 *                 
 *
 * Author: Danling Yang, Shiyi Zhou 
 * Team name: Crispy Chicken
 * Date: Sep 19th, Thu
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

void enter(List *thePatients){
	string thecarecard;

	//Create a new patient profile
	cout<<"Please,enter your care card number: ";
	//Remove all leading whitespace ->ws
	getline(cin>>ws,thecarecard);
	Patient thePatient(thecarecard);

	if(thecarecard=="0000000000"||thecarecard.size()!=10){
		Patient();
	}
	else{
		string aName;
	    cout<<"Please,enter your name: ";
	    getline(cin>>ws,aName);
	    thePatient.setName(aName);

	    string anAddress;
	    cout<<"Please,enter your address: ";
	    getline(cin>>ws,anAddress );
        thePatient.setAddress(anAddress);

        string aPhone;
        cout<<"Please,enter your phone: ";
        getline(cin>>ws,aPhone);
        thePatient.setPhone(aPhone);

        string anEmail;
        cout<<"Please,enter your Email: ";
        getline(cin>>ws,anEmail);
        thePatient.setEmail(anEmail);

	}
    

	// Report to user
	if (thePatients->insert(thePatient))
	{
		cout << "Patient:  " << thePatient << "has successfully added in the system." << endl;
	}
	else
	{
		cout << thePatient << "was unable to add in the system." << endl;
	}
	thePatients->printList();
  return;
}


void remove(List *thePatients) {
  string num;
  cout <<"Please enter the care card number that the patient you want to remove\n";
  cin>>num;
  if(num.size()!=10){
		cout<<"WRONG care card number"<<endl;
		return;
	}

  Patient target(num);
  



  if ( thePatients->getElementCount() > 0 ) {
    // Remove member profile from list
	Patient *toberemove = thePatients->search(target);
    if ( thePatients->remove(*toberemove) )
      cout << "Patient has now left the system." << endl;
    else
      cout << "Patient was unable to leave the system!" << endl;  
  }
  else
      cout << "There are no patients in the system yet!" << endl;  

  thePatients->printList();

  return;   
}


void modify(List *thePatients) {
	string num;
	cout << "calling modify" << endl;
	cout << "Please enter the care card number:" << endl;
	cin>>num;
	if(num.size()!=10){
		cout<<"WRONG care card number"<<endl;
		return;
	}
	//call search function to find the target first
	Patient target(num);
	Patient *tobemodified=thePatients->search(target);

	if (tobemodified != NULL){
		thePatients->modify(*tobemodified);
		cout<<"Information Update!"<<endl;
	    cout << "the patient: "<< *(thePatients->search(target))<< endl;   //Shiyi: print information after modified
	}
	else{
		cout<<"Patient not found"<<endl;
	}
	
	
	return;
}

void search(List *thePatients) {
	string carecard;
	cout << "calling search" << endl;
	cout << "please enter the CareCard number for the Patient you want to search:";
	cin >> carecard; 
	if(carecard.size()!=10){
		cout<<"WRONG care card number"<<endl;
		return;
	}
	//Patient target(carecard); shiyi: WRONG. always return 0000000000,to be entered..... if carecard not right
	Patient target(carecard);

	if (thePatients->search(target)!=NULL)
		cout << "the patient: "<< *(thePatients->search(target))<< endl;
	//show the patient's information as the return value from List.cpp
	
	else
		cout << "sorry, the patient does not find." << endl;
	return;
} 

void print(List *thePatients) {
	cout << "calling printList" << endl;
	thePatients->printList();
	return;
}


int main(){

	List* patients= new List();
	bool done= false;
	int input=0;

	while (not done){
		cout << "\n----Welcome to Walkin Clinic System!\n"<< endl;
		cout<<"to enter a new patient into the system  enter: 1 "<< endl;
		cout<<"to remove a patient from the system  enter: 2 "<< endl;
		cout<<"to search for an existing patient  enter: 3 "<< endl;
		cout<<"to modify a patient's record  enter 4 "<< endl;
		cout<<"to print all its patients by descending order of care card numbers  enter: 5"<< endl;
		cout<<"Exit enter: 6"<< endl;
		cout<<"Your choice: ";
		cin>>input;

		switch(input){
			case 1: enter(patients); break;
			case 2: remove(patients); break;
			case 3: search(patients); break;
			case 4: modify(patients); break;
			case 5: print(patients); break;
			case 6: cout << "\n----Bye!\n" << endl; done = true; break;
			default: cout << "Not sure what you mean! Please, try again!" << endl;break;
		}
		cout << "There are now " << patients->getElementCount() << " patients in system." << endl; 
	}

	return 0;
}