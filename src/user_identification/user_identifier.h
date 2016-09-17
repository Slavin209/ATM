#ifndef IDENTIFICATION_OF_USER_H
#define IDENTIFICATION_OF_USER_H

#include <iostream>
#include <string>
#include "system_utility.h"

using std::cin;
using std::cout;

class UserIdentifier {
  using string = std::string;

 public:
  void SetLogin(const string &login);
  void SetPassword(const string &password);

  void EnterInitialLogin();
  void EnterinitialPassword();

  string GetLogin() const;
  string GetPassword() const;

  bool IsNormalLogin();
  bool IsNormalPass();

  string GetPasswordFromUser();

 private:
  string login_ = "no_name";
  string password_ = "0000";

  SystemUtility utility_;

};

#endif  // IDENTIFICATION_OF_USER_H