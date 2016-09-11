#ifndef NOTICE_ABOUT_ERROR_H
#define NOTICE_ABOUT_ERROR_H

#include <iostream>
#include "account_info.h"
#include "system_utility.h"
#include "user_messanger.h"

using std::cout;
using std::cin;

class NoticeAboutError {
 public:
  NoticeAboutError();

  void ShowUnacceptableWithdrawal(const AccountInfo &account_info,
                                  int incorrect_sum);

  void NoticeAboutIncorrectLoginMessage() const;
  void NoticeAboutIncorrectFormatPasswordMessage() const;
  void NoticeAboutIncorrectDataMessage() const;
  void NoticeAboutIncorrectSum() const;

 private:
  SystemUtility utility_;
  UserMessanger user_messenger_;
};

#endif  // NOTICE_ABOUT_ERROR_H
