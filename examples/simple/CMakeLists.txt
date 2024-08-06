SET(example_name simple)

SET(KIT_SRCS
  main.cpp
  )
  
IF(Qt4_FOUND)
  ADD_EXECUTABLE(${example_name}-qt4 ${KIT_SRCS})
  TARGET_LINK_LIBRARIES(${example_name}-qt4 ${PROJECT_NAME}-qt4)
ENDIF()

IF(Qt5_FOUND)
  ADD_EXECUTABLE(${example_name}-qt5 ${KIT_SRCS})
  TARGET_LINK_LIBRARIES(${example_name}-qt5 ${PROJECT_NAME}-qt5)
ENDIF()
