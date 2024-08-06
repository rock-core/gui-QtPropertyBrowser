
SET(example_name demo)

SET(KIT_SRCS
  main.cpp
  )

SET(KIT_resources
  demo.qrc
  )

IF(Qt4_FOUND)
  QT4_ADD_RESOURCES(KIT_QRC_SRCS_QT4 ${KIT_resources})

  ADD_EXECUTABLE(${example_name}-qt4 ${KIT_SRCS} ${KIT_QRC_SRCS_QT4})
  TARGET_LINK_LIBRARIES(${example_name}-qt4 ${PROJECT_NAME}-qt4)
ENDIF()

IF(Qt5_FOUND)
  QT5_ADD_RESOURCES(KIT_QRC_SRCS_QT5 ${KIT_resources})

  ADD_EXECUTABLE(${example_name}-qt5 ${KIT_SRCS} ${KIT_QRC_SRCS_QT5})
  TARGET_LINK_LIBRARIES(${example_name}-qt5 ${PROJECT_NAME}-qt5)
ENDIF()
