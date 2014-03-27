# Install script for directory: /home/davito/Documents/Verificacion/PinaVM

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/toplevel/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/frontend/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/utils/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/external/basic/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/backends/TwetoBackend/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/backends/42Backend/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/backends/PromelaBackend/cmake_install.cmake")
  INCLUDE("/home/davito/Documents/Verificacion/Proyecto/backends/SimpleBackend/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/davito/Documents/Verificacion/Proyecto/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/davito/Documents/Verificacion/Proyecto/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
