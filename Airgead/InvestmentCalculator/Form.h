/**
 * Author:		Chris Trimmer
 * Course:		CS-210-H7406 (Programming Languages)
 * Semester:	22EW4
 * Professor:	Professor Bary Pollack
 * Date:		28Mar2022
 *
 * Title:	Project 2 (Airgead Investment Calculator)
 *
 */


#ifndef INVESTMENTCALCULATOR_FORM_H
#define INVESTMENTCALCULATOR_FORM_H

#include <memory>

using std::shared_ptr;

class Form {

private:
	double m_initialAmount{};
	double m_monthlyDeposit{};
	double m_annualInterest{};
	double m_numOfYears{};

public:

	Form(double t_initial, double t_deposit, double t_interest, double t_years);

	Form() = delete;
	Form(const Form&) = delete;
	Form(Form&&) = delete;
	Form& operator=(const Form&) = delete;
	Form& operator=(Form&&) = delete;

	static std::shared_ptr<Form>& GetInstance(double t_initial, double t_deposit, double t_interest, double t_years) {
		static std::shared_ptr<Form> form(new Form(t_initial, t_deposit, t_interest, t_years));
		return form;
	}

	double initialAmount() const;
	double monthlyDeposit() const;
	double annualInterest() const;
	double numberYears() const;

	void setInitialAmount(const double& t_value);
	void setMonthlyDeposit(const double& t_value);
	void setAnnualInterest(const double& t_value);
	void setNumberYears(const double& t_value);

	// Destructor
	~Form() {}
};



#endif	INVESTMENTCALCULATOR_FORM_H
