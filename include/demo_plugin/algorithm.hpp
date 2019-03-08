#pragma once

#include <ImFusion/Base/Algorithm.h>  // for IoAlgorithm
#include <ImFusion/Base/DataList.h>   // for DataList

namespace ImFusion {
class Algorithm;
class Properties;

namespace DemoPlugin {

class PluginAlgorithm : public ImFusion::Algorithm {
public:
  /// Creates the algorithm instance
  PluginAlgorithm();

  static bool createCompatible(const DataList& data, Algorithm** a = nullptr);

  /// Applies the processing
  void compute() override;

  /// Make the resulting data available here
  void output(DataList& data_out) override;

  /// Methods implementing the Configurable interface
  void configure(const Properties* p) override;
  void configuration(Properties* p) const override;

  void changeMember();

private:
  int placeholder_{0};
};

}  // namespace DemoPlugin.
}  // namespace ImFusion.
