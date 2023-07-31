#pragma once
#ifndef AIRGEADBANKINGM4_USERDATA_H
#define AIRGEADBANKINGM4_USERDATA_H
#endif

//defines the class for holding all user data

class UserData {
	public:  // declares public functions within class
		void setInitialInvestment(double t_initial);
		void setMonthlyDeposit(double t_monthly);
		void setAnnualInterest(double t_interest);
		void setYears(int t_years);

		double getInitialInvestment();
		double getMonthlyDeposit();
		double getAnnualInterest();
		int getYears();

		double calculateInterestNoDeposits(int t_year);
		double calculateInterestWithDeposits(double t_initial);

	private: // declares private variables within class
		double m_initialInvestment;
		double m_monthlyDeposit;
		double m_annualInterest;
		int m_years;

};