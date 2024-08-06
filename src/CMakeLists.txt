
include(GenerateExportHeader)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(_SRCS
  qtbuttonpropertybrowser.cpp
  qteditorfactory.cpp
  qtgroupboxpropertybrowser.cpp
  qtpropertybrowser.cpp
  qtpropertybrowserutils.cpp
  qtpropertymanager.cpp
  qttreepropertybrowser.cpp
  qtvariantproperty.cpp
  )

file(GLOB _IMPL_HDRS *.h)
file(GLOB _PUBLIC_HDRS Qt*)

set(_UI_FORMS
  )

set(_RESOURCES
  qtpropertybrowser.qrc
  )
  
IF(Qt4_FOUND)
  QT4_WRAP_UI(_QT4_UI_SRCS ${_UI_FORMS})
  QT4_ADD_RESOURCES(_QT4_QRC_SRCS ${_RESOURCES})

  set(QT4_TARGET_NAME ${PROJECT_NAME}-qt4)

  add_library(${QT4_TARGET_NAME} SHARED
    ${_SRCS}
    ${_QT4_UI_SRCS}
    ${_QT4_QRC_SRCS}
    ${_IMPL_HDRS}
    )

  target_link_libraries(${QT4_TARGET_NAME} Qt4::QtGui)
ENDIF()

IF(Qt5_FOUND)
  QT5_WRAP_UI(_QT5_UI_SRCS ${_UI_FORMS})
  QT5_ADD_RESOURCES(_QT5_QRC_SRCS ${_RESOURCES})

  set(QT5_TARGET_NAME ${PROJECT_NAME}-qt5)

  add_library(${QT5_TARGET_NAME} SHARED
    ${_SRCS}
    ${_QT5_UI_SRCS}
    ${_QT5_QRC_SRCS}
    ${_IMPL_HDRS}
    )

  target_link_libraries(${QT5_TARGET_NAME} Qt5::Widgets)
ENDIF()

######################### Installation Stuff ###########################
IF(Qt4_FOUND)
  generate_export_header(${QT4_TARGET_NAME})

  install(TARGETS ${QT4_TARGET_NAME}
    EXPORT ${QT4_TARGET_NAME}Targets
    RUNTIME DESTINATION ${INSTALL_BIN_DIR}
    LIBRARY DESTINATION ${INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
    INCLUDES DESTINATION ${INSTALL_INCLUDE_DIR}
  )
ENDIF()

IF(Qt5_FOUND)
  generate_export_header(${QT5_TARGET_NAME})

  install(TARGETS ${QT5_TARGET_NAME}
    EXPORT ${QT5_TARGET_NAME}Targets
    RUNTIME DESTINATION ${INSTALL_BIN_DIR}
    LIBRARY DESTINATION ${INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
    INCLUDES DESTINATION ${INSTALL_INCLUDE_DIR}
  )
ENDIF()

install(
  FILES
    ${_PUBLIC_HDRS}
    ${_IMPL_HDRS}
  DESTINATION
    ${INSTALL_INCLUDE_DIR}
  COMPONENT
    Devel
)

