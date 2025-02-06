# Install script for directory: C:/ncs/v2.7.0/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/ncs/toolchains/ce3b5ff664/opt/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/arch/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/soc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/subsys/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/drivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/nrf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/mcuboot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/trusted-firmware-m/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/azure-sdk-for-c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/cirrus-logic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/suit-processor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/memfault-firmware-sdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/canopennode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/chre/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/lz4/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/nanopb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/zscilib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/cmsis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/cmsis-dsp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/cmsis-nn/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/hal_nordic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/hal_st/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/hal_wurthelektronik/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/libmetal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/liblc3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/loramac-node/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/lvgl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/mipi-sys-t/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/nrf_hw_models/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/open-amp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/picolibc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/segger/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/tinycrypt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/uoscore-uedhoc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/zcbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/nrfxlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/modules/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/cmake/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/cmake/usage/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/ulise/repos/-Hadar_Cohen_demo/i2c_slave/nrf52/build_nrf52_slave/zephyr/cmake/reports/cmake_install.cmake")
endif()

