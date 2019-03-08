#include "demo_plugin/factory.hpp"
#include <ImFusion/Base/Algorithm.h>   // for Algorithm
#include <vector>                      // for vector
#include "demo_plugin/algorithm.hpp"   // for PluginAlgorithm
#include "demo_plugin/controller.hpp"  // for PluginController

namespace ImFusion {
class AlgorithmController;

namespace DemoPlugin {

PluginAlgorithmFactory::PluginAlgorithmFactory() { registerAlgorithm<PluginAlgorithm>("Demo;Demo Plugin"); }

AlgorithmController* PluginControllerFactory::create(ImFusion::Algorithm* a) const {
  if (PluginAlgorithm* algorithm = dynamic_cast<PluginAlgorithm*>(a)) { return new PluginController(algorithm); }
  return nullptr;
}

}  // namespace DemoPlugin.
}  // namespace ImFusion.
