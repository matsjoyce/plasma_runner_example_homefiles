cmake_minimum_required(VERSION 3.6)

project(runnerexample)

find_package(ECM 0.0.11 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(KF5 REQUIRED COMPONENTS CoreAddons Solid KIO Runner I18n)

set(example_SRCS homefiles.cpp)

add_library(plasma_runner_example_homefiles MODULE ${example_SRCS})
target_link_libraries(plasma_runner_example_homefiles KF5::Runner KF5::KIOCore KF5::KIOWidgets KF5::I18n KF5::CoreAddons)
target_link_libraries(plasma_runner_example_homefiles Qt5::Widgets)


# https://github.com/lxde/lxqt-qtplugin/blob/master/src/CMakeLists.txt
get_target_property(QT_QMAKE_EXECUTABLE ${Qt5Core_QMAKE_EXECUTABLE} IMPORTED_LOCATION)
if(NOT QT_QMAKE_EXECUTABLE)
    message(FATAL_ERROR "qmake is not found.")
endif()

# execute the command "qmake -query QT_INSTALL_PLUGINS" to get the path of plugins dir.
execute_process(COMMAND ${QT_QMAKE_EXECUTABLE} -query QT_INSTALL_PLUGINS
    OUTPUT_VARIABLE QT_PLUGINS_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(QT_PLUGINS_DIR)
    message(STATUS "Qt5 plugin directory:" "${QT_PLUGINS_DIR}")
else()
    message(FATAL_ERROR "Qt5 plugin directory cannot be detected.")
endif()


# Install the library and .desktop file
install(TARGETS plasma_runner_example_homefiles DESTINATION ${QT_PLUGINS_DIR})
install(FILES plasma-runner-example-homefiles.desktop DESTINATION ${SERVICES_INSTALL_DIR})
