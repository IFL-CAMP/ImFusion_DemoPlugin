#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>  // for AlgorithmContr...
#include <ImFusion/Base/AlgorithmFactory.h>            // for AlgorithmFactory

namespace ImFusion {
class Algorithm;
class AlgorithmController;

namespace DemoPlugin {

class PluginAlgorithmFactory : public AlgorithmFactory {
public:
  PluginAlgorithmFactory();
};

class PluginControllerFactory : public AlgorithmControllerFactory {
public:
  virtual ImFusion::AlgorithmController* create(ImFusion::Algorithm* a) const override;
};

}  // namespace DemoPlugin.
}  // namespace ImFusion.
