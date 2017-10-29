﻿#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <base_atm_frame.h>

#include <font_size_controller.h>

class QLabel;
class QString;
class QTimer;
class TextColorSwapper;

class SplashScreenFrame : public BaseAtmFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QWidget* parent = nullptr);
  ~SplashScreenFrame();

  void SetCompanyName(const QString& company_name);

 public slots:
  void ChangeGeometry() override;

  void BlinkAtmLabelColor();

 private:
  void SetSplashScreenSettings();
  void InitializeObjects();
  void TuneLabel();
  void PaintWidgets();
  void SetConnection();

  QTimer* color_swap_timer_ = nullptr;
  TextColorSwapper* text_color_swapper_ = nullptr;

  QLabel* version_label_ = nullptr;
  QLabel* company_name_label_ = nullptr;
  QLabel* atm_label_ = nullptr;
  QLabel* text_label_ = nullptr;

  FontSizeController font_size_controller_;

  static const int kBlinkTime = 350;
};

#endif  // SPLASH_SCREEN_FRAME_H
