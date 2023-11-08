find_package(Qt6 REQUIRED COMPONENTS Qml)

qt_add_library(components STATIC)
qt6_add_qml_module(components
    URI "components"
    VERSION 1.0
    QML_FILES Button.qml)
