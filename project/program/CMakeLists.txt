cmake_minimum_required(VERSION 3.4)
project(ParcelLockerSource)
set(SOURCE_FILES src/main.cpp src/mainwindow.cpp include/mainwindow.h ui/mainwindow.ui src/orderdialog.cpp include/orderdialog.h ui/orderdialog.ui src/registerdialog.cpp include/registerdialog.h ui/registerdialog.ui ui/logindialog.ui src/logindialog.cpp include/logindialog.h src/admindialog.cpp include/admindialog.h ui/admindialog.ui src/parcellockerdialog.cpp include/parcellockerdialog.h ui/parcellockerdialog.ui src/showlockersdialog.cpp include/showlockersdialog.h ui/showlockersdialog.ui src/checkorders.cpp include/checkorders.h ui/checkorders.ui src/showclientorders.cpp include/showclientorders.h ui/showclientorders.ui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(ParcelLockerSource ${SOURCE_FILES})

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
include_directories(
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(ParcelLockerSource ParcelLockerLib Qt5::Widgets Qt5::Core ParcelLockerLib)
target_include_directories(ParcelLockerSource PUBLIC include)