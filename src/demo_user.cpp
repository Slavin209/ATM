#include "demo_user.h"

#include <iostream>
#include <limits>
#include <string>

#include "system_utility.h"

using std::cin;
using std::cout;
using std::string;

static const int kExit = 2;
static const int kInvalidChoice = 0;

static void WriteTextWithDelay(const string &text) {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(5);
  }
  cout << "\n";
}

void DemoUser::ShowDemoMenu() const {
  cout << "\t################ Demo Transaction menu ###################\n"
          "\t#                                                        #\n"
          "\t#  1. Account information            2. Refill           #\n"
          "\t#  ----------------------            ------------        #\n"
          "\t#  3. Credit application             4. Withdrawal       #\n"
          "\t#  ----------------------            ------------        #\n"
          "\t#  5. Statement                      6. Exit             #\n"
          "\t#                                                        #\n"
          "\t#                   7. Create Account                    #\n"
          "\t#                                                        #\n"
          "\t##########################################################\n\n"
          "\t# Enter: ";
}

void DemoUser::ShowWelcomeMessage() const {
  WriteTextWithDelay(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu:\n");

  WriteTextWithDelay("# Please, choose interested you chapter:\n");
}

void DemoUser::ShowDemoMode() {
  ClearScreen();
  ShowWelcomeMessage();

  for (;;) {
    ShowDemoMenu();
    if (UserDecideToExit()) {
      break;
    }
    ClearScreen();
  }
}

bool DemoUser::UserDecideToExit() {
  int choice = GetValueFromUser();
  if (choice == 1) {
    return DemoAccountInfo();
  } else if (choice == 2) {
    return DemoRefill();
  } else if (choice == 3) {
    return DemoCreditApp();
  } else if (choice == 4) {
    return DemoWidthdrawal();
  } else if (choice == 5) {
    return DemoStatement();
  } else if (choice == 6) {
    return UserWantToExitProgram();
  } else if (choice == 7) {
    return StartRegistration();
  } else {
    return ShowIncorrectMessage();
  }
}

bool DemoUser::DemoAccountInfo() const {
  ClearScreen();

  ShowDemoAccountInfo();

  return SuggestUserToExit();
}

bool DemoUser::SuggestUserToExit() const {
  WriteTextWithDelay(
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.\n");
  cout << "# Enter: ";

  return GetResultFromUser();
}

bool DemoUser::GetResultFromUser() const {
  bool result_of_choice = false;
  int user_want_to_exit = GetValueFromUser();
  for (;;) {
    if (user_want_to_exit == 1) {
      break;
    } else if (user_want_to_exit == kExit) {
      ShowExitMessage();
      Sleep(1000);
      result_of_choice = true;
      break;
    } else {
      cout << "# Incorrect input, please try again:\n"
              "# Enter: ";
      user_want_to_exit = GetValueFromUser();
    }
  }

  return result_of_choice;
}

int DemoUser::GetValueFromUser() const {
  return ConvertLineToChoice(GetLineFromUser());
}

int DemoUser::ConvertLineToChoice(const string &line) const {
  if (LineNotEmpty(line)) {
    try {
      return std::stoi(line);
    } catch (const std::invalid_argument &) {
    }
  }

  return kInvalidChoice;
}

bool DemoUser::LineNotEmpty(const string &str) const {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return !str.empty();
}

string DemoUser::GetLineFromUser() const {
  string line;
  getline(cin, line);

  return line;
}

bool DemoUser::UserWantToRegistrate() const { return user_want_to_registrate; }

bool DemoUser::UserWantToExitProgram() const { return true; }

bool DemoUser::StartRegistration() {
  user_want_to_registrate = true;
  return user_want_to_registrate;
}

void DemoUser::ClearScreen() const { system("clear"); }

void DemoUser::ShowDemoAccountInfo() const {
  WriteTextWithDelay(
      "# This section show your account information.\n"
      "# For example, it's look like this:\n");
  cout << "--------------------------------------------\n";
  cout << "# Login: Mr. Anderson\n";
  Sleep(100);
  cout << "# Password: 7623\n";
  Sleep(100);
  cout << "# Balance $: 7450\n";
  Sleep(100);
  cout << "# Credit $: 20000\n";
  cout << "# Monthly payment $: 2280\n";
  cout << "# Credit term: 20 month(s)\n";
  cout << "--------------------------------------------\n\n";
  Sleep(100);

  WriteTextWithDelay(
      "# As you can see, your account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n");
}

void DemoUser::ShowExitMessage() const {
  WriteTextWithDelay(
      "\n# Thank you for using our ATM system,\n"
      "# have a nice day!\n\n");
}

void DemoUser::ShowInfoAboutRefill() const {
  WriteTextWithDelay(
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:");
  cout << "--------------------------------------------\n"
          " Entered sum: 1000 $\n"
          "--------------------------------------------\n"
          " (If sum a valid, money will be tranferred)\n\n";
}

bool DemoUser::DemoRefill() const {
  ClearScreen();
  ShowInfoAboutRefill();
  return SuggestUserToExit();
}

bool DemoUser::DemoCreditApp() const {
  ClearScreen();

  WriteTextWithDelay(
      "# Our bank may allow you to get a loan on the amount\n"
      "# of not more than 15x of your cash on account at the "
      "# moment.\n\n"
      "# For example: \n"
      "# If your balance at the moment equal $2000, you may\n"
      "# get a $30000 loan on individual conditions.\n\n");

  return SuggestUserToExit();
}

bool DemoUser::DemoWidthdrawal() const {
  ClearScreen();

  WriteTextWithDelay(
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n");

  return SuggestUserToExit();
}

bool DemoUser::DemoStatement() const {
  ClearScreen();

  WriteTextWithDelay(
      "# Standart statement which contain information\n"
      "# about your cash.\n");

  return SuggestUserToExit();
}

bool DemoUser::ShowIncorrectMessage() const {
  WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit");
  cout << "\t# Enter: ";

  int choice = GetValueFromUser();
  if (choice == 1) {
    return false;
  } else if (choice == 2) {
    return true;
  } else {
    WriteTextWithDelay("\n\t#Incorrect input, reload the program.\n");
    return true;
  }
}
