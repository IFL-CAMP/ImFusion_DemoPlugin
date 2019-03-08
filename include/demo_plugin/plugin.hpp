#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>  // for AlgorithmContr...
#include <ImFusion/Base/AlgorithmFactory.h>            // for AlgorithmFactory
#include <ImFusion/Base/ImFusionPlugin.h>              // for ImFusionPlugin
#include <memory>                                      // for unique_ptr

namespace ImFusion {
namespace DemoPlugin {
class Plugin : public ImFusionPlugin {
public:
  Plugin();
  virtual ~Plugin() override = default;

  virtual const AlgorithmFactory* getAlgorithmFactory() override;

  virtual const AlgorithmControllerFactory* getAlgorithmControllerFactory() override;

private:
  std::unique_ptr<AlgorithmFactory> algorithm_factory_{nullptr};
  std::unique_ptr<AlgorithmControllerFactory> algorithm_controller_factory_{nullptr};
};
}  // namespace DemoPlugin.
}  // namespace ImFusion.
