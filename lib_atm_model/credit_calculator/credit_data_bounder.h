﻿#ifndef CREDIT_DATA_BOUNDER_H
#define CREDIT_DATA_BOUNDER_H

class CreditDataBounder {
 public:
  CreditDataBounder();

  int LowerCreditSum() const;
  int UpperCreditSum() const;
  double LowerInterestRate() const;
  double UpperInterestRate() const;
  int LowerAmountOfMonth() const;
  int UpperAmountOfMonth() const;

 private:
  int lower_credit_sum_bound_;
  int upper_credit_sum_bound_;
  double lower_interest_rate_bound_;
  double upper_interest_rate_bound_;
  int lower_amount_of_month_bound_;
  int upper_ampunt_of_month_bound_;
};

#endif  // CREDIT_DATA_BOUNDER_H
