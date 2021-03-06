cmake_minimum_required(VERSION 3.3.0)
project(demo_plugin)

find_package(ImFusionLib REQUIRED)

if(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_INSTALL_RPATH "/Applications/ImFusionSuite.app/Contents/Frameworks")
endif(APPLE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Define and configure the targets
set(PLUGIN_SOURCES
	src/algorithm.cpp
	src/controller.cpp
	src/factory.cpp
	src/plugin.cpp
	src/controller.ui
)

set(PLUGIN_HEADERS
        include/${PROJECT_NAME}/algorithm.hpp
        include/${PROJECT_NAME}/controller.hpp
        include/${PROJECT_NAME}/factory.hpp
        include/${PROJECT_NAME}/plugin.hpp
)

# Define target library
add_library(${PROJECT_NAME} SHARED ${PLUGIN_SOURCES} ${PLUGIN_HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14)

target_include_directories(${PROJECT_NAME} PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

# Link agains the ImFusionLib and selected modules/plugins. If other modules are needed, add them to your Plugin.
target_link_libraries(${PROJECT_NAME} PRIVATE ImFusionLib)

# Check if this is needed, how this is provided or how this should be provided.
imfusion_set_common_target_properties()
imfusion_provide_ide_instructions()

# Install step
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
