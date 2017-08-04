﻿#include <description_frame.h>

#include <QList>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent),
      color_designer_(new AtmColorDesigner),
      account_info_button_(new AtmButton("Account information", this)),
      cash_refill_button_(new AtmButton("Refill cash", this)),
      credit_app_button_(new AtmButton("Credit application", this)),
      cash_withdrawal_button_(new AtmButton("Cash withdrawal", this)),
      statement_butotn_(new AtmButton("Statement", this)),
      layout_(new QVBoxLayout) {
  RemoveButtonsVisualOffset();
  SetGridLayout();
  SetGeometries();
  ColorizeWidgets();
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DescriptionFrame::RemoveButtonsVisualOffset() {
  account_info_button_->SetOffsetSide(AtmButton::kNone);
  cash_refill_button_->SetOffsetSide(AtmButton::kNone);
  credit_app_button_->SetOffsetSide(AtmButton::kNone);
  cash_withdrawal_button_->SetOffsetSide(AtmButton::kNone);
  statement_butotn_->SetOffsetSide(AtmButton::kNone);
}

void DescriptionFrame::SetGridLayout() {
  layout_->addWidget(statement_butotn_);
  layout_->addWidget(cash_withdrawal_button_);
  layout_->addWidget(credit_app_button_);
  layout_->addWidget(cash_refill_button_);
  layout_->addWidget(account_info_button_);

  layout_->setSpacing(5);

  setLayout(layout_);
}

void DescriptionFrame::SetGeometries() {
  setGeometry(DescriptionMenuGeometry::DescriprionFrame());
}

void DescriptionFrame::ColorizeWidgets() {
  setStyleSheet(
      "DescriptionFrame {"
      "border: 1px solid red;"
      "}");

  QList<QPushButton*> button_list{account_info_button_, cash_refill_button_,
                                  credit_app_button_, cash_withdrawal_button_,
                                  statement_butotn_};
  color_designer_->PaintWidgetSet(button_list);
}
