cmake_minimum_required(VERSION 3.14)

project(ChainSampleQt6 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core ConCurrent REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core ConCurrent REQUIRED)

add_executable(ChainSampleQt6
  main.cpp
  worker.h worker.cpp
  myexception.h myexception.cpp
)
target_link_libraries(ChainSampleQt6 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent)
