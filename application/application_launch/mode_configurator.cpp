﻿#include <mode_configurator.h>

std::string ModeConfigurator::config_file_ = "app_config.txt";

ModeConfigurator::ModeConfigurator() {
  stream_.open(config_file_);
  ReadConfiguration();
  AnalyzeConfigFile();
}

int ModeConfigurator::GetUIMode() const { return ui_mode_; }

void ModeConfigurator::ReadConfiguration() {
  if (stream_.is_open()) {
    std::getline(stream_, config_string_);
  }
}

void ModeConfigurator::AnalyzeConfigFile() {
  if (config_string_ == "Mode: cli") {
    ui_mode_ = kConsoleMode;
  } else if (config_string_ == "Mode: gui") {
    ui_mode_ = kGraphicalMode;
  }
}
