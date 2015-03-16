# Install script for directory: /home/el/Vision/opencv/modules

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
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/el/Vision/opencv/build/modules/androidcamera/.androidcamera/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/calib3d/.calib3d/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/core/.core/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudaarithm/.cudaarithm/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudabgsegm/.cudabgsegm/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudacodec/.cudacodec/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudafeatures2d/.cudafeatures2d/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudafilters/.cudafilters/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudaimgproc/.cudaimgproc/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudalegacy/.cudalegacy/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudaobjdetect/.cudaobjdetect/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudaoptflow/.cudaoptflow/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudastereo/.cudastereo/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudawarping/.cudawarping/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/cudev/.cudev/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/features2d/.features2d/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/flann/.flann/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/highgui/.highgui/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/imgcodecs/.imgcodecs/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/imgproc/.imgproc/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/java/.java/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/ml/.ml/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/objdetect/.objdetect/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/photo/.photo/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/python/.python/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/shape/.shape/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/stitching/.stitching/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/superres/.superres/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/ts/.ts/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/video/.video/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/videoio/.videoio/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/videostab/.videostab/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/viz/.viz/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/world/.world/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/core/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/flann/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/imgproc/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/ml/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/photo/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/video/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/imgcodecs/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/shape/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/videoio/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/highgui/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/objdetect/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/superres/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/ts/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/features2d/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/calib3d/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/java/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/stitching/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/videostab/cmake_install.cmake")
  INCLUDE("/home/el/Vision/opencv/build/modules/python2/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

