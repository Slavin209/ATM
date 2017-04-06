﻿#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include <string>

#include "console_editor.h"

class CreditMessanger {
  using string = std::string;

 public:
  void RefuseACredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(int maximal_sum_of_credit) const;

  void SuggestToConfirmACredit() const;
  void ShowCreditTitle(const string& user_login, int sum_of_credit) const;

  void ShowEnrollACredit() const;
  void ShowRefuseACredit(int sum_of_cash) const;

  void ShowRepealACreadit() const;

  void ShowTableOfCredit(double pay_per_month, double amount_of_months) const;

  void ShowSumCreditInfo() const;
  void ShowMonthCreditInfo() const;

  void ShowResultOfUserChoice(int decision_of_user) const;

  void ShowIncorrectCashInformation(int cash) const;

  /// new code
  void ShowUnavailableCreditInfo() const;

 private:
  static const int kHalfASecond = 500;
  static const int kSleep = 75;
  static const int kNull = 0;

  ConsoleEditor console_editor_;
};

#endif  // CREDIT_MESSANGER_H
