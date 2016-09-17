#ifndef NOTICE_ABOUT_ERROR_H
#define NOTICE_ABOUT_ERROR_H

#include <iostream>
#include "system_utility.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class NoticeAboutError {
 public:
  NoticeAboutError();

  void ShowUnacceptableWithdrawal(int amount_of_cash, int incorrect_sum);

  void NoticeAboutIncorrectLoginMessage() const;
  void NoticeAboutIncorrectFormatPasswordMessage() const;
  void NoticeAboutIncorrectDataMessage() const;
  void NoticeAboutIncorrectSum() const;

  bool ShowIncorrectDataMessage();

 private:
  SystemUtility utility_;
  UserMessenger user_messenger_;
};

#endif  // NOTICE_ABOUT_ERROR_H