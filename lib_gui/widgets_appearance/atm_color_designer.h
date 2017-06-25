﻿#ifndef ATM_COLOR_DESIGNER_H
#define ATM_COLOR_DESIGNER_H

#include <QList>

class QLabel;
class QPushButton;
class QFrame;
class QMainWindow;
class QDialog;
class QString;
class InitialMenuFrame;

class AtmColorDesigner {
 public:
  AtmColorDesigner();

  void SetBackgroundColor(QMainWindow* main_window);
  void SetBackgroundColor(QDialog* dialog);

  void PaintWidgetSet(QList<QLabel*> label_list) const;
  void PaintWidgetSet(QList<QPushButton*> button_list) const;
  void PaintWidgetSet(QList<QFrame*> frame_list) const;

  void PaintInitialFrame(InitialMenuFrame* frame) const;
};

#endif  // ATM_COLOR_DESIGNER_H
