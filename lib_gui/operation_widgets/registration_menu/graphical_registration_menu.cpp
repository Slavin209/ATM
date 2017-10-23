﻿#include <graphical_registration_menu.h>

#include <QWidget>

#include <atm_composer.h>
#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      registration_description_(new RegistrationDescription(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
  SetConnections();

  registration_description_->close();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());
  AtmComposer::ComposeBackButton(GetBackButton());
  AtmComposer::StretchWidget(RegistrationMenuGeometry::RegistrationFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);

  //  operation_frame_delta_size_ =
  //      registration_composer_.ComposeDeltaSizeForDescription(
  //          GetBackButtonGeometry(), delta_size);
  // registration_description_->ChangeGeometry(operation_frame_delta_size_);

  // BaseComposer::ComposeWidget(RegistrationMenuGeometry::RegistrationFrame(),
  // this);
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), registration_description_, SLOT(Show()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(close()));
}
