###################### InstallProjectConfig  ###########################

include(CMakePackageConfigHelpers)

SET(INSTALL_PKGCONFIG_DIR ${INSTALL_LIB_DIR}/pkgconfig)

if(Qt4_FOUND)
  set(QT4_TARGET_NAME ${PROJECT_NAME}-qt4)

  configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${QT4_TARGET_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${QT4_TARGET_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CMAKE_DIR}
    )

  install(EXPORT ${QT4_TARGET_NAME}Targets
    DESTINATION ${INSTALL_CMAKE_DIR}
    )

  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${QT4_TARGET_NAME}Config.cmake
    DESTINATION ${INSTALL_CMAKE_DIR}
    COMPONENT Devel
    )

  set(TARGET_NAME ${QT4_TARGET_NAME})
  set(PKGCONFIG_REQUIRES QtCore QtGui)
  set(PKGCONFIG_LIBS )
  set(PKGCONFIG_CFLAGS )
  configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${QT4_TARGET_NAME}.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/${QT4_TARGET_NAME}.pc
    INSTALL_DESTINATION ${INSTALL_PKGCONFIG_DIR}
    )

  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${QT4_TARGET_NAME}.pc
    DESTINATION ${INSTALL_PKGCONFIG_DIR}
    )

endif()

if(Qt5_FOUND)
  set(QT5_TARGET_NAME ${PROJECT_NAME}-qt5)

  configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${QT5_TARGET_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${QT5_TARGET_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CMAKE_DIR}
    )

  install(EXPORT ${QT5_TARGET_NAME}Targets
    DESTINATION ${INSTALL_CMAKE_DIR}
    )

  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${QT5_TARGET_NAME}Config.cmake
    DESTINATION ${INSTALL_CMAKE_DIR}
    COMPONENT Devel
    )

  set(TARGET_NAME ${QT5_TARGET_NAME})
  set(PKGCONFIG_REQUIRES Qt5Core Qt5Gui Qt5Widgets)
  set(PKGCONFIG_LIBS )
  set(PKGCONFIG_CFLAGS )
  configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${QT5_TARGET_NAME}.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/${QT5_TARGET_NAME}.pc
    INSTALL_DESTINATION ${INSTALL_PKGCONFIG_DIR}
    )

  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${QT5_TARGET_NAME}.pc
    DESTINATION ${INSTALL_PKGCONFIG_DIR}
    )

endif()

