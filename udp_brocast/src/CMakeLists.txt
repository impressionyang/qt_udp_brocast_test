##########################################################################################
#                                       create by impressionyang
#                                       2020 01 05
##########################################################################################

#set minimum cmake compile version
cmake_minimum_required(VERSION 3.14)

#include(FindPkgConfig)

#set target app name
set(TARGET_NAME udp_brocast)

#use c++ 17 stander
set(CMAKE_CXX_STANDERD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include this priject on
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#auto genarate ui.h file
set(CMAKE_AUTOUIC ON)

#auto genarete moc file
set(CMAKE_AUTOMOC ON)

#auto genarate .qrc file on
set(CMAKE_AUTORCC ON)

# set QT type
set(QT Core Gui Widgets Network DBus Sql)

#cmake install
set(CMAKE_INSTALL_PREFIX /usr)

#add package lib
find_package(Qt5 REQUIRED ${QT})

# add a source file subdirectory
add_subdirectory(utilities)

#set all resources files
file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
file(GLOB_RECURSE FORMS "*.ui")
file(GLOB_RECURSE RESOURCES "*.qrc")


#genarate a app
add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})

#add QT5 dependes
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network Qt5::DBus Qt5::Sql)
#qt5_use_modules(${TARGET_NAME} ${QT})

