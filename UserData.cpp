#include <iostream>
#include <math.h>
#include <iomanip>
#include "UserData.h"


using namespace std;


void UserData::setInitialInvestment(double t_initial) {  // sets value for initial investment
	this->m_initialInvestment = t_initial;
}

void UserData::setMonthlyDeposit(double t_monthly) {  // sets value for monthly deposit
	this->m_monthlyDeposit = t_monthly;
}

void UserData::setAnnualInterest(double t_interest) {  // sets value for annual interest
	this->m_annualInterest = t_interest;
}

void UserData::setYears(int t_years) {  // sets value for years
	this->m_years = t_years;
}

double UserData::getInitialInvestment() {  // gets the value for initial investments
	return m_initialInvestment;
}

double UserData::getMonthlyDeposit() {  // gets the value for monthly deposit
	return m_monthlyDeposit;
}

double UserData::getAnnualInterest() { // gets the value for annual interest
	return m_annualInterest;
}

int UserData::getYears() { // gets the value for years
	return m_years;
}

double UserData::calculateInterestNoDeposits(int t_year) {  // calculates the interest amount without monthly deposit
	double interest = this->m_annualInterest / 100;
	return this->m_initialInvestment * pow(1 + (interest / 1), t_year) - 1;
}

double UserData::calculateInterestWithDeposits(double t_initial) {  // calculates the interest amount with monthly deposit
	double interest = this->m_annualInterest / 100;
	return (t_initial + this->m_monthlyDeposit) * (interest / 12);
}