CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT(QtPropertyBrowser
   DESCRIPTION
   "A property browser framework enabling the user to edit a set of properties.")

########################### Misc. Configs ##############################
# Add custom cmake files folder
SET (PROJECT_CMAKE_DIR ${PROJECT_SOURCE_DIR}/cmake)
SET (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_CMAKE_DIR}")

# Add custom Compile Settings and flags
INCLUDE(CompileSettings)

# Add custom Install Settings
INCLUDE(InstallSettings)

##################### Look for required libraries ######################

# Add QT dependencies
FIND_PACKAGE(Qt4 COMPONENTS QtGui)
FIND_PACKAGE(Qt5 COMPONENTS Widgets)

######################### Add Primary Targets ##########################
ADD_SUBDIRECTORY(src)

########################## Add the Examples ############################
OPTION (BUILD_EXAMPLES "Build Examples" ON)
IF(BUILD_EXAMPLES)
  ADD_SUBDIRECTORY(examples)
ENDIF()

######################### Installation Stuff ###########################
INCLUDE(InstallProjectConfig)

###################### Add uninstall target ############################
ADD_CUSTOM_TARGET(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${PROJECT_CMAKE_DIR}/cmake_uninstall.cmake)

##################### Show Configuration Summary ######################
MESSAGE(STATUS "===============================================================")
MESSAGE(STATUS "================  Configuration Summary  ======================")
MESSAGE(STATUS "Project Name:       ${PROJECT_NAME}")
MESSAGE(STATUS "Build type:         ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "Build type Flags:   ${CMAKE_BUILD_TYPE_FLAGS}")
MESSAGE(STATUS "C++ compile flags:  ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "Install Path:       ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "Build Examples:     ${BUILD_EXAMPLES}")
IF(Qt4_FOUND)
  MESSAGE(STATUS "QT4 Version:        ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
  MESSAGE(STATUS "QT4 INCLUDE DIRS:   ${QT_INCLUDES}")
  MESSAGE(STATUS "QT4 DEFS:           ${QT_DEFINITIONS}")
ENDIF()
IF(Qt5_FOUND)
  MESSAGE(STATUS "QT5 Version:        ${Qt5Widgets_VERSION_STRING}")
  MESSAGE(STATUS "QT5 INCLUDE DIRS:   ${Qt5Widgets_INCLUDE_DIRS}")
  MESSAGE(STATUS "QT5 COMPILE DEFS:   ${Qt5Widgets_COMPILE_DEFINITIONS}")
  MESSAGE(STATUS "QT5 DEFS:           ${Qt5Widgets_DEFINITIONS}")
  MESSAGE(STATUS "QT5 EXE FLAGS:      ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
ENDIF()
