﻿#include <font_size_controller.h>

#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>

#include <QDebug>

void FontSizeController::ControllFontSize(QPushButton* widget) {
  QFontMetrics font_metrics(widget->font());
  GetInitDebugInfo();
}

void FontSizeController::ControllFontSize(QLabel* widget) {
  QFontMetrics font_metrics(widget->font());
  if (is_first_calc_) {
    iwcs_.SetIww(widget->geometry().width());
    iwcs_.SetIwh(widget->geometry().height());
    iwcs_.SetIfh(font_metrics.boundingRect(widget->text()).height());
    iwcs_.SetIfps(widget->font().pixelSize());

    GetInitDebugInfo();
    is_first_calc_ = false;
  } else {
    widget_geometry_ = widget->geometry();

    GetInitDebugInfo();
    GetDebugInfo();

    if (widget_geometry_.width() == iwcs_.Iww()) {
      qDebug() << "\n";
      qDebug() << "Widget width = Init widget width = "
               << QString::number(widget_geometry_.width());
    }
    if (widget_geometry_.height() == iwcs_.Iwh()) {
      qDebug() << "\n";
      qDebug() << "Widget height = Init height width = "
               << QString::number(widget_geometry_.height());
    }
  }
}

void FontSizeController::GetInitDebugInfo() {
  system("clear");
  qDebug() << "Init widget width: " << QString::number(iwcs_.Iww());
  qDebug() << "Init widget height: " << QString::number(iwcs_.Iwh());
  qDebug() << "Init font height: " << QString::number(iwcs_.Ifh());
  qDebug() << "Init font pixel size: " << QString::number(iwcs_.Ifps());
  qDebug() << "Init FCh: " << QString::number(iwcs_.Ifch());
  qDebug() << "Init FCw: " << QString::number(iwcs_.Ifcw());
}

void FontSizeController::GetDebugInfo() {
  qDebug() << "\n\nGeometry changed!\n\n";
  qDebug() << "Widget width: " << QString::number(widget_geometry_.width());
  qDebug() << "Widget height: " << QString::number(widget_geometry_.height());
}