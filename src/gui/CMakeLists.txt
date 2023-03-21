cmake_minimum_required(VERSION 3.5)

project(3d_Viewer VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/aligadzhiev/Qt/QtDesignStudio/qt6_design_studio_reduced_version/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)

set(PROJECT_SOURCES
        main.cpp
        appwindow.cpp
        appwindow.h
        appwindow.ui
        openglwidget.cpp
        openglwidget.h

        ../core/main.h
        ../core/parser.c
        ../core/other.c

         ./QtGifImage-master/src/3rdParty/giflib/dgif_lib.c
         ./QtGifImage-master/src/3rdParty/giflib/egif_lib.c
         ./QtGifImage-master/src/3rdParty/giflib/gif_err.c
         ./QtGifImage-master/src/3rdParty/giflib/gif_lib.h
         ./QtGifImage-master/src/3rdParty/giflib/gif_hash.c
         ./QtGifImage-master/src/3rdParty/giflib/gifalloc.c
         ./QtGifImage-master/src/3rdParty/giflib/quantize.c
         ./QtGifImage-master/src/gifimage/qgifglobal.h
         ./QtGifImage-master/src/gifimage/qgifimage.h
         ./QtGifImage-master/src/gifimage/qgifimage_p.h
         ./QtGifImage-master/src/gifimage/qgifimage.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3d_Viewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3d_Viewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3d_Viewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3d_Viewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3d_Viewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::OpenGL)

set_target_properties(3d_Viewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS 3d_Viewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3d_Viewer)
endif()
