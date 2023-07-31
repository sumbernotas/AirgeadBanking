#pragma once
#ifndef AIRGEADBANKINGM4_SYSTEMDISPLAY_H
#define AIRGEADBANKINGM4_SYSTEMDISPLAY_H
#endif

#include <iostream>
#include <iomanip>

using namespace std;

void displayDataInput() { // displays the data input visuals

	for (int i = 0; i < 34; i++) {
		cout << "*";
	}
	cout << endl;

	for (int i = 0; i < 11; i++) {
		cout << "*";
	}

	cout << " Data Input ";

	for (int i = 0; i < 11; i++) {
		cout << "*";
	}

	cout << endl;
}

void displayBalanceNoDeposit(int years, UserData user) {  // displays the graph for year end balance with NO deposit
	
	double yearEndBalance;
	double initialTemp;
	double earnedInterest;

	cout << "   Balance and Interest Without Additional Monthly Deposits   " << endl;
	for (int i = 0; i < 63; i++) {
		cout << "=";
	}                                                                                                     /////////////////
	cout << endl;                                                                                         //// displays visuals for the graph
																										  /////////////////
	cout << " Year   *" << "    Year End Balance   *" << "    Year End Earned Interest" << endl;
	for (int i = 0; i < 63; i++) {
		cout << "-";
	}
	cout << endl;


	for (int i = 1; i <= years; i++) {   // generates each year balance using a loop
		yearEndBalance = user.calculateInterestNoDeposits(i) + user.getInitialInvestment();  // calculates yeat end balance
		initialTemp = user.calculateInterestNoDeposits(i - 1) + user.getInitialInvestment(); // holds the previous year end balance 
		earnedInterest = yearEndBalance - initialTemp; // calculates earned interest

		// displays year end balance and interest into graph
		cout << "  " << i << "     *         $" << fixed << setprecision(2) << yearEndBalance << "         *             $" << earnedInterest << endl;
	}


}

void displayBalanceWithDeposit(int years, UserData user) {

	double yearEndBalance;
	double earnedInterest;
	double interest;
	double yearlyEarnedInterest;

	cout << "   Balance and Interest With Additional Monthly Deposits   " << endl;
	for (int i = 0; i < 63; i++) {
		cout << "=";
	}                                                                                                          /////////////////
	cout << endl;                                                                                              //// displays visuals for the graph
																											   /////////////////
	cout << " Year   *" << "    Year End Balance   *" << "    Year End Earned Interest" << endl;
	for (int i = 0; i < 63; i++) {
		cout << "-";
	}
	cout << endl;

	yearEndBalance = user.getInitialInvestment();  // holds users initial investment amount

	for (int i = 1; i <= years; i++) {                // loops to cycle years for graph

		yearlyEarnedInterest = 0;  // holds the earned interest based on year

		for (int j = 0; j < 12; j++) {
			earnedInterest = user.calculateInterestWithDeposits(yearEndBalance);  // calculates earned interest from monthly scale
			yearlyEarnedInterest = yearlyEarnedInterest + earnedInterest;  // calculates earned interest for each year seperately
			yearEndBalance = yearEndBalance + user.getMonthlyDeposit() + earnedInterest; // calculates year end balance
		}

		// displays year end balance and interest into graph
		cout << "  " << i << "     *         $" << fixed << setprecision(2) << yearEndBalance << "       *             $" << yearlyEarnedInterest << endl;
	}


}