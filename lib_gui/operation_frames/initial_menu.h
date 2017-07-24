﻿#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <QFrame>
#include <QRect>
#include <QVBoxLayout>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class QPushButton;
class AtmColorDesigner;
class AtmButton;
class WidgetHider;
class WidgetExtruder;

class InitialMenu : public QFrame {
  Q_OBJECT
 public:
  InitialMenu(QWidget* parent);
  ~InitialMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessDemoButtonClick();
  void Show();

 signals:
  void PassGeometryForExtrude(const QRect&);
  void PassGeometryForHide(const QRect&);
  void DemoButtonClicked();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void PaintWidgets();
  void SetFrameAnimation();
  void SetButtonsInitialSetting();
  void SetButtonGeometry();
  void SetButtonSizePolicy();

  void SetScalingProperties();
  void SetButtonFrame();

  void SetConnections();

  QFrame* button_frame_ = nullptr;
  AtmButton* sign_in_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;
  AtmButton* demo_button_ = nullptr;
  QVBoxLayout* v_layout_ = nullptr;
  AtmColorDesigner* atm_color_designer_ = nullptr;
  WidgetHider* widget_hider_ = nullptr;
  WidgetExtruder* widget_extruder_ = nullptr;

  DeltaSize delta_size_;
  WidgetBorderController border_controller_;
  GeometryComposer composer_;

  static constexpr double kHalfOfSize = 0.5;
  static constexpr double kHalfOfHeight = 0.5;
};

#endif  // INITIAL_MENU_H
