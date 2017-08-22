﻿#ifndef CONFIRMATION_REGISTRATION_MESSENGER_H
#define CONFIRMATION_REGISTRATION_MESSENGER_H

#include <string>

class ConfirmationRegistrationMessenger {
 public:
  static void ShowConfirmationMessage(const std::string& login_string,
                                      const std::string& password_string);

 private:
  static int maximal_string_length_;
};

#endif  // CONFIRMATION_REGISTRATION_MESSENGER_H