cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(hello_world)

# Silence noise from arduino-esp32 build
idf_build_set_property(COMPILE_OPTIONS "-Wmissing-field-initializers" APPEND)