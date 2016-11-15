#include "withdrawal_messenger.h"

#include <iostream>

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  std::cout << "\t#Sum($): " << sum_of_cash << "\n";
}

void WithdrawalMessenger::ShowPasswordString() const {
  std::cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void WithdrawalMessenger::ShowIncorrectPasswordMessage() const {
  text_editor_.ClearScreen();
  text_editor_.WriteTextWithDelay("\n\t# Sorry, entered password is incorrect.\n");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() const {
  std::cout << "\n\t# Please, enter the required sum: ";
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                                   int sum_of_withdrawal) {
  text_editor_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  std::cout << "\t# Sum($): " << sum_of_cash << "\n";
  std::cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}