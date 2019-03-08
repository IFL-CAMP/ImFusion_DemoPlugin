#include "demo_plugin/controller.hpp"          // for PluginController
#include <ImFusion/GUI/AlgorithmController.h>  // for AlgorithmController
#include <qobjectdefs.h>                       // for SIGNAL, SLOT
#include <qpushbutton.h>                       // for QPushButton
#include <memory>                              // for make_shared, shared_ptr
#include "demo_plugin/algorithm.hpp"           // for PluginAlgorithm
#include "ui_controller.h"                     // for Ui_Demo

namespace ImFusion {

namespace DemoPlugin {
PluginController::PluginController(PluginAlgorithm* algorithm) : AlgorithmController(algorithm), algorithm_(algorithm) {
  ui_ = std::make_shared<Ui_Controller>();
  ui_->setupUi(this);
}

void PluginController::init() {
  // ImFusion standard command.
  addToAlgorithmDock();

  //***GUI SET UP***
  connect(ui_->dummy_button, &QPushButton::clicked, this, &PluginController::onButtonClicked);
}

void PluginController::onButtonClicked() { algorithm_->changeMember(); }

}  // namespace DemoPlugin.
}  // namespace ImFusion.
