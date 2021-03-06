﻿#ifndef ATM_COMPOSER_H
#define ATM_COMPOSER_H

#include <QRect>

#include <back_button_composer.h>
#include <delta_size.h>
#include <geometry_composer.h>
#include <side.h>

class AtmButton;
class QWidget;

class AtmComposer {
 public:
  static void SetDeltaSize(const DeltaSize& delta_size);
  static void ComposeBackButton(AtmButton* back_button);
  static void ShiftWidget(const QRect& initial_geometry,
                          unsigned int shift_side,
                          double x_shift_factor,
                          double y_shift_factor,
                          QWidget* widget);
  static void StretchWidget(const QRect& initial_geometry,
                            unsigned int stretch_side,
                            double x_stretch_factor,
                            double y_stretch_factor,
                            QWidget* widget);
  static void SetScalingProperties(unsigned int shift_side,
                                   unsigned int stretch_side,
                                   bool keep_at_center);
  static void ScaleWidget(const QRect& initial_geometry,
                          double x_shift_factor,
                          double y_shift_factor,
                          double x_stretch_factor,
                          double y_stretch_factor,
                          QWidget* widget);
  static DeltaSize GetDeltaSize();
  static DeltaSize GetBackButtonDeltaSize();

 private:
  static BackButtonComposer kBackButtonComposer;
  static GeometryComposer kShiftComposer;
  static GeometryComposer kStretchComposer;
  static GeometryComposer kScaleComposer;

  static DeltaSize kDeltaSize;
};

#endif  // ATM_COMPOSER_H
