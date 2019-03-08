#include "demo_plugin/algorithm.hpp"
#include <ImFusion/Base/AlgorithmListener.h>  // for AlgorithmListener
#include <ImFusion/Base/Log.h>                // for LOG_INFO
#include <ImFusion/Base/Properties.h>         // for Properties
#include <vector>                             // for vector

namespace ImFusion {
class Algorithm;

namespace DemoPlugin {

PluginAlgorithm::PluginAlgorithm() { configureDefaults(); }

bool PluginAlgorithm::createCompatible(const DataList& data, Algorithm** a) {
  // Check requirements to create the algorithm
  if (data.size() != 0) {
    return false;
  }  // TODO what is this actually checking? Does it avoid to create READ
     // plugins on un-empty data?

  // Requirements are met, create the algorithm if asked
  if (a) { *a = new PluginAlgorithm(); }  // TODO is this disposed by someone?
  return true;
}

void PluginAlgorithm::compute() {}

void PluginAlgorithm::output(DataList& /*unused*/) {}

// This methid restors the member parameters when a workspace file is loaded.
// We can store previous configurations in a workspace file and load them here.
void PluginAlgorithm::configure(const Properties* p) {
  if (p == nullptr) { return; }
  p->param("placeholder", placeholder_);
  // Notify all listeners that  parameters have changed.
  for (auto& listener : m_listeners) { listener->algorithmParametersChanged(); }
}

// Retrieve member variable values from saved workspace.
void PluginAlgorithm::configuration(Properties* p) const {
  // This method is necessary to store our settings in a workspace file.
  if (p == nullptr) { return; }
  p->setParam("placeholder", placeholder_, 0);
}

void PluginAlgorithm::changeMember() {
  ++placeholder_;
  LOG_INFO("changeMember() called!");
}

}  // namespace DemoPlugin.
}  // namespace ImFusion.
