#include <iostream>
#include "userData.h"
#include "SystemDisplay.h"

using namespace std;

int main() {

	UserData data;  // creates an object of the UserData class
	
	// declares variables for user data values
	double initialInvestment, monthlyDeposit, annualInterest, earnedInterest, yearEndBalance;
	int years;

	// declares variables for system loop
	char userInput;
	bool running = true;


	while (running) {
		 
		displayDataInput();

		// gets user input for initial amount and stores in initialInvestment variable
		cout << "Initial Investment Amount: $";
		cin >> initialInvestment; 

		// gets user input for monthly deposit amount and stores in monthlyDeposit variable
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;

		// gets user input for interest percentage and stores in annualInterest variable
		cout << "Annual Interest: %";
		cin >> annualInterest;
		
		// gets user input for number of years and stores in years variable
		cout << "Number of years: ";
		cin >> years;
		cout << endl;

		system("pause");
		system("cls");

		// sets the data variable for the UserData class in the data obj
		data.setInitialInvestment(initialInvestment);
		data.setMonthlyDeposit(monthlyDeposit);
		data.setAnnualInterest(annualInterest);
		data.setYears(years);

		
		displayBalanceNoDeposit(data.getYears(), data);  // calls function to display graph showing NO monthly deposit data
		cout << endl << endl; 
		displayBalanceWithDeposit(data.getYears(), data); // calls function to display graph SHOWING monthly deposit data

		cout << endl << endl;
		cout << "To change investment amount, enter Y" << endl << "To quit, enter Q" << endl;  // prompts user to change data values or quit program
		cin >> userInput;

		if (userInput == 'Q' || userInput == 'q') { // if user decides to quit, running will equal false and the system loop will be exited, the program will quit
			running = false;
		}

		system("cls");
	}


	return 0;
}