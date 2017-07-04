﻿#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QRect;

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text, QWidget* widget = nullptr);

  ~AtmButton();

 protected:
  void focusInEvent(QFocusEvent*);
  void focusOutEvent(QFocusEvent*);

  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  static const int x_offset_ = 5;
};

#endif  // ATM_BUTTON_H
