# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/work_app/ESP_IDF/Espressif/frameworks/esp-idf-v5.2.1/components/bootloader/subproject"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/tmp"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/src"
  "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Code/ESP_Project/03_MPU6050/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
