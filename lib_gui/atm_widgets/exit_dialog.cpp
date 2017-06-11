﻿#include "exit_dialog.h"
#include "ui_exit_dialog.h"

#include <QApplication>
#include <QList>
#include <QString>

#include <initial_property_installer.h>
#include <painter.h>
#include <widget_center_arranger.h>
#include <widget_color.h>

ExitDialog::ExitDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::ExitDialog) {
  ui->setupUi(this);
  setWindowTitle("Exit");
  SetInitialProperties();
  PaintWidgets();
  SetConnections();
}

ExitDialog::~ExitDialog() { delete ui; }

void ExitDialog::SetExitDialogAppearance(const QString& main_color,
                                         const QString& secondary_color,
                                         const QString& additional_color) {
  color_designer_.CustomizeColorSet(
      WidgetColor(main_color, secondary_color, additional_color));
  PaintWidgets();
}

void ExitDialog::SetBackgroundImage(const QString& background_image) {
  Painter::ChangeBackgroundImage(this, background_image);
}

void ExitDialog::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
}

void ExitDialog::ShowWidgetOnCenterAt(const QRect& widget_geometry) {
  WidgetCenterArranger::MoveToCenterRelativelyOf(this, widget_geometry);
  show();
}

void ExitDialog::SetConnections() {
  connect(ui->button_yes, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(ui->button_no, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitDialog::SetInitialProperties() {
  InitialPropertyInstaller::SetInitialProperties(this, 300, 150);
}

void ExitDialog::PaintWidgets() {
  QList<QLabel*> label_list = {ui->message_screen};
  QList<QPushButton*> button_list = {ui->button_yes, ui->button_no};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(label_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(frame_list);
}