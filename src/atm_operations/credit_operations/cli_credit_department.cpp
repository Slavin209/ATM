﻿#include "cli_credit_department.h"

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  const int result_of_check = GetResultOfUserCheck(*user);

  if (result_of_check == state_.kPositiveCheck) {
  } else if (result_of_check == state_.kCreditExist) {
    messenger_.RefuseACreditBasedOnAnotherCredit();
    messenger_.ShowIncorrectCashInformation(user->GetCash());
  } else if (result_of_check == state_.kInappropriateBalance) {
    messenger_.RefuseACreditBasedOnCash(user->GetCash());
  } else if (result_of_check == state_.kInvalidCheck) {
    messenger_.UnavailableCreditState();
  }
}
