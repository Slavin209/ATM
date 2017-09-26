﻿#include <calculator.h>

#include <math.h>

Calculator::Calculator()
    : credit_sum_(0),
      credit_interest_rate_(0.0),
      amount_of_months_(0),
      monthly_payment_(0.0),
      percent_coefficient_(0.0) {}

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_months_ = amount_of_months;

  CalculateMonthlyPayment();
}

double Calculator::MonthlyPayment() const { return monthly_payment_; }

void Calculator::CalculateMonthlyPayment() {
  CalculatePercentsCoefficient();
  monthly_payment_ = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

void Calculator::CalculatePercentsCoefficient() {
  percent_coefficient_ = credit_interest_rate_ / 100;
}

/// Annuity credit payment formula
///
///               D * i / m
/// Y = ------------------------------
///       1 - 1 / ( 1 + i / m )^n*m
///
/// D - sum of credit
/// i - interest rate as coefficient (percents / 100%)
/// m - percentage payments per year equal 12 (12 month per year)
/// n - credit term in years
///

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation =
      credit_sum_ * (percent_coefficient_ / kMonthsPerYear);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  double denominator = kOne + (percent_coefficient_ / kMonthsPerYear);
  double result = kOne - (kOne / pow(denominator, amount_of_months_));
  return result;
}

void Calculator::Reset() {
  credit_sum_ = 0;
  credit_interest_rate_ = 0.0;
  amount_of_months_ = 0;
  monthly_payment_ = 0.0;
  percent_coefficient_ = 0.0;
}
