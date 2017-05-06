﻿#include "atm.h"

#include <account_informator.h>
#include <user_registrator.h>

void Atm::RegisterUser(const std::string& login, const std::string& password) {
  UserRegistrator::RegisterUser(&user_, login, password);
}

std::string Atm::AccountInfo(Atm::AccountData account_data) {
  AccountInformator::UpdataUserData(user_);
  switch (account_data) {
    case kLogin:
      return AccountInformator::Login();
    case kCash:
      return AccountInformator::Cash();
    case kCreditSum:
      return AccountInformator::CreditSum();
    case kCreditTerm:
      return AccountInformator::CreditTerm();
    case kInterestRate:
      return AccountInformator::InterestRate();
    case kMonthlyPayment:
      return AccountInformator::MonthlyPayment();
  }
}

std::string Atm::Statement() {
  AccountInformator::UpdataUserData(user_);
  return AccountInformator::Cash();
}
