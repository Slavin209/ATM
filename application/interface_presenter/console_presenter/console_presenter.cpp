﻿#include <console_presenter.h>

ConsolePresenter::ConsolePresenter() {
  initial_menu_ = std::unique_ptr<ConsoleInitialMenu>(new ConsoleInitialMenu);
}

void ConsolePresenter::RunApplication() {
  initial_menu_->DisplaySplashScreen();
  for (;;) {
    initial_menu_->RunInitialMenu();
    RunSubMenu(initial_menu_->GetSubMenu());
    if (user_want_exit_) {
      initial_menu_->DisplayFarewellMessage();
      break;
    }
  }
}

void ConsolePresenter::RunSubMenu(int sub_menu) {
  if (sub_menu == ConsoleInitialMenu::kLoginMenu) {
    login_menu_.RunLoginMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kRegistrationMenu) {
    registration_menu_.RunRegistrationMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kDemoMenu) {
    description_menu_.RunDescriptionMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kExit) {
    user_want_exit_ = true;
  }
}
