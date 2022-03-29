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
  

#include "Form.h"


Form::Form(double t_initial, double t_deposit, double t_interest, double t_years) :
	m_initialAmount{ t_initial }, m_monthlyDeposit{ t_deposit }, m_annualInterest{ t_interest }, m_numOfYears{ t_years }{}

double Form::initialAmount() const { return m_initialAmount; }
double Form::monthlyDeposit() const { return m_monthlyDeposit; }
double Form::annualInterest() const { return m_annualInterest; }
double Form::numberYears() const { return m_numOfYears; }

void Form::setInitialAmount(const double& t_value) { m_initialAmount = t_value; }
void Form::setMonthlyDeposit(const double& t_value) { m_monthlyDeposit = t_value; }
void Form::setAnnualInterest(const double& t_value) { m_annualInterest = t_value; }
void Form::setNumberYears(const double& t_value) { m_numOfYears = t_value; }

