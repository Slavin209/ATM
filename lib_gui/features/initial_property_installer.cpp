﻿#include <initial_property_installer.h>

#include <QWidget>

#include <widget_centerer.h>

void InitialPropertyInstaller::SetInitialProperties(QWidget* widget,
                                                    int widget_width,
                                                    int widget_height) {
  widget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  widget->resize(widget_width, widget_height);
  WidgetCenterer::MoveToCenter(widget);
}