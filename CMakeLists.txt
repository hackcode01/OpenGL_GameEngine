cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME GameEngine)

project(${PROJECT_NAME})

add_subdirectory(GameEngineCore)
add_subdirectory(gameEngineEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT GameEngineEditor
)
