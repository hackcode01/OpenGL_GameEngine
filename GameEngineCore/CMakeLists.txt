cmake_minimum_required(VERSION 3.15)

set(ENGINE_PROJECT_NAME GameEngineCore)

set(ENGINE_PUBLIC_INCLUDES
    Includes/GameEngineCore/App.hpp
    Includes/GameEngineCore/Log.hpp
    Includes/GameEngineCore/Event.hpp
    Includes/GameEngineCore/Camera.hpp
    Includes/GameEngineCore/Keys.hpp
    Includes/GameEngineCore/Input.hpp
)

set(ENGINE_PRIVATE_INCLUDES
    Includes/GameEngineCore/Window.hpp
    Includes/GameEngineCore/Modules/UIModule.hpp
    Includes/GameEngineCore/Rendering/OpenGL/RendererOpenGL.hpp
    Includes/GameEngineCore/Rendering/OpenGL/shaderProgram.hpp
    Includes/GameEngineCore/Rendering/OpenGL/VertexBuffer.hpp
    Includes/GameEngineCore/Rendering/OpenGL/VertexArray.hpp
    Includes/GameEngineCore/Rendering/OpenGL/IndexBuffer.hpp
    Includes/GameEngineCore/Rendering/OpenGL/Texture2D.hpp
)

set(ENGINE_PRIVATE_SOURCES
    Src/GameEngineCore/App.cpp
    Src/GameEngineCore/Window.cpp
    Src/GameEngineCore/Input.cpp
    Src/GameEngineCore/Modules/UIModule.cpp
    Src/GameEngineCore/Camera.cpp
    Src/GameEngineCore/Rendering/OpenGL/RendererOpenGL.cpp
    Src/GameEngineCore/Rendering/OpenGL/ShaderProgram.cpp
    Src/GameEngineCore/Rendering/OpenGL/VertexBuffer.cpp
    Src/GameEngineCore/Rendering/OpenGL/VertexArray.cpp
    Src/GameEngineCore/Rendering/OpenGL/IndexBuffer.cpp
    Src/GameEngineCore/Rendering/OpenGL/Texture2D.cpp
)

set(ENGINE_ALL_SOURCES
    ${ENGINE_PUBLIC_INCLUDES}
    ${ENGINE_PRIVATE_INCLUDES}
    ${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
    ${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${ENGINE_ALL_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC Includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE Src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../External/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../External/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../External/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../External/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)

set(IMGUI_INCLUDES
    ../External/imgui/imgui.h
    ../External/imgui/backends/imgui_impl_glfw.h
    ../External/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
    ../External/imgui/imgui.cpp
    ../External/imgui/backends/imgui_impl_glfw.cpp
    ../External/imgui/backends/imgui_impl_opengl3.cpp
    ../External/imgui/imgui_draw.cpp
    ../External/imgui/imgui_tables.cpp
    ../External/imgui/imgui_widgets.cpp
    ../External/imgui/imgui_demo.cpp
)

add_library(im_gui STATIC
    ${IMGUI_INCLUDES}
    ${IMGUI_SOURCES}
)

target_include_directories(im_gui PUBLIC ../External)
target_include_directories(im_gui PUBLIC ../External/imgui)

target_link_libraries(im_gui PRIVATE glad glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE im_gui)
