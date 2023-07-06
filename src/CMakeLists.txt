cmake_minimum_required(VERSION 3.19)
project(viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.2.3/bin")

find_package(Qt6 COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(
        viewer

        main.cpp

        Model/Object_Handler/Recorder/strategy_recorder.h
        Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.cc
        Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.h
        Model/Object_Handler/Modifier/affine_transformation.cc
        Model/Object_Handler/Modifier/affine_transformation.h
        Model/Object_Handler/common.h
        Model/Object_Handler/object_facade.cc
        Model/Object_Handler/object_facade.h

        Controller/Object_Controller/object_controller.cc
        Controller/Object_Controller/object_controller.h

        View/Object_Observer/object_observer.cc
        View/Object_Observer/object_observer.h
        View/Viewer/viewer.cc
        View/Viewer/viewer.h
        View/Interaction_Panel/Style_Panel/style_panel.cc
        View/Interaction_Panel/Style_Panel/style_panel.h
        View/Interaction_Panel/Modification_Panel/modification_panel.cc
        View/Interaction_Panel/Modification_Panel/modification_panel.h)

target_link_libraries(viewer PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)