﻿#include <registration_inspector.h>

#include <registration_standard.h>

ATM::RegistrationStatus RegistrationInspector::InspectLoginString(
    const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login.length())) {
    return ATM::RegistrationStatus::kShortLogin;
  } else if (IsLoginLong(login.length())) {
    return ATM::RegistrationStatus::kLongLogin;
  }

  if (IsStringContainSpecialSymbols()) {
    return ATM::RegistrationStatus::kSpecialSymbols;
  } else if (IsStringBeginWithSpace()) {
    return ATM::RegistrationStatus::kBeginWithSpace;
  } else if (IsStringEndWithSpace()) {
    return ATM::RegistrationStatus::kEndWithSpace;
  }

  if (IsStringContainAdjacentSpaces()) {
    return ATM::RegistrationStatus::kAdjacentSpaces;
  }

  if (IsStringContainOnlyDigits()) {
    return ATM::RegistrationStatus::kContainOnlyDigits;
  }

  return ATM::RegistrationStatus::kCorrectLogin;
}

ATM::RegistrationStatus RegistrationInspector::InspectPasswordString(
    const std::string& password) {}

bool RegistrationInspector::IsLoginShort(int login_length) const {
  return login_length < RegistrationStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(int login_length) const {
  return login_length > RegistrationStandard::MaxLoginLength();
}

bool RegistrationInspector::IsStringContainSpecialSymbols() const {
  return string_analyzer_.IsStringContainSpecialSymbols();
}

bool RegistrationInspector::IsStringBeginWithSpace() const {
  return string_analyzer_.IsStringBeginWithSpace();
}

bool RegistrationInspector::IsStringEndWithSpace() const {
  return string_analyzer_.IsStringEndWithSpace();
}

bool RegistrationInspector::IsStringContainAdjacentSpaces() const {
  return string_analyzer_.IsStringContainAdjacentSpaces();
}

bool RegistrationInspector::IsStringContainOnlyDigits() const {
  return string_analyzer_.IsStringContainOnlyDigits();
}
