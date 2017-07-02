﻿#ifndef SHIFT_COEFFICIENT_H
#define SHIFT_COEFFICIENT_H

class ShiftCoefficient {
 public:
  ShiftCoefficient(double x_coefficient, double y_coefficient);

  double XCoefficient() const;
  double YCoefficient() const;

 private:
  double x_coefficient_ = 0.0;
  double y_coefficient_ = 0.0;
};

#endif  // SHIFT_COEFFICIENT_H
