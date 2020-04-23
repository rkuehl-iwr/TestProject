cmake_minimum_required(VERSION 3.10)
project(TestProject LANGUAGES CXX DESCRIPTION "Simple c++ test project")

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
        set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()



add_executable(testProj main.cpp
    OpenGLWindow.cpp
    OpenGLWindow.h)

add_definitions(${Qt5Widgets_DEFINITIONS})
target_include_directories(testProj PRIVATE ${Qt5Widgets_INCLUDES})

add_definitions(${Qt5OpenGL_DEFINITIONS})
target_include_directories(testProj PRIVATE ${Qt5OpenGL_INCLUDES})

add_dependencies(testProj OpenGL::GL)

target_link_libraries(testProj PRIVATE ${Qt5Widgets_LIBRARIES} ${Qt5OpenGL_LIBRARIES} ${Qt5Gui_LIBRARIES} OpenGL::GL)

qt5_import_plugins(testProj INCLUDE Qt5::QSvgIconPlugin Qt5::QSvgPlugin)

install(TARGETS testProj DESTINATION bin)
