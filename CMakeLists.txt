cmake_minimum_required(VERSION 3.14)

project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Gui Qml)
qt_standard_project_setup()
qt_policy(SET QTP0001 OLD)

add_subdirectory(components)

qt_add_executable(lab
  main.cpp
  Stubs.hpp
  PathGenerator.hpp
  httpclient.h httpclient.cpp
  GoogleClient.hpp
  components/Button.qml
  main.qml
)
qt6_add_qml_module(lab URI lab QML_FILES main.qml RESOURCES qt.png NO_RESOURCE_TARGET_PATH)

target_link_libraries(lab PRIVATE Qt6::Core
    Qt6::Network Qt6::Gui Qt6::Qml components)

#set(QML_IMPORT_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE STRING "" FORCE)



include(GNUInstallDirs)
install(TARGETS lab
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
