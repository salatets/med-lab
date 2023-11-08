cmake_minimum_required(VERSION 3.14)

project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Gui Qml)
qt_standard_project_setup(REQUIRES 6.5)
qt_policy(SET QTP0001 NEW)

add_subdirectory(resources)

qt_add_executable(lab
  main.cpp
)

qt6_add_qml_module(lab
    URI "main"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES Main.qml
    RESOURCES resources/images/qt.png
    SOURCES src/GoogleClient.hpp
            src/PathGenerator.hpp
            src/Stubs.hpp
            src/HttpClient.cc src/HttpClient.h)

target_include_directories(lab PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(lab PRIVATE Qt6::Core
    Qt6::Network Qt6::Gui Qt6::Qml componentsplugin)

#list(APPEND QML_IMPORT_PATH "resources/qml/components")
#list(APPEND QML_DIRS "resources/qml/components")
#set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt Creator 4.1 extra qml import paths")
#set(QML_IMPORT_PATH "${QML_IMPORT_PATH}" CACHE STRING "Qt Creator 4.1 extra qml import paths" FORCE)

include(GNUInstallDirs)
install(TARGETS lab
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
