add_subdirectory(tmath)

add_executable(sdlgame 
    main.cpp
    game.cpp
    texture2d.cpp
    bat.cpp
    entity.cpp
    keystate.cpp
    ball.cpp
)

target_include_directories(sdlgame PRIVATE "include")
target_link_libraries(sdlgame PRIVATE tmath)
target_link_libraries(sdlgame PRIVATE SDL2::SDL2)
target_link_libraries(sdlgame PRIVATE SDL2_image::SDL2_image)

if (WIN32)
    add_compile_definitions(WINDOWS)
    add_custom_command(
        TARGET sdlgame POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:sdlgame>"
        VERBATIM
    )
    add_custom_command(
        TARGET sdlgame POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2_image::SDL2_image>" "$<TARGET_FILE_DIR:sdlgame>"
        VERBATIM
    )
endif()

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/res
    ${PROJECT_BINARY_DIR}/src/res
    COMMENT "Copying resources into binary directory")

add_dependencies(sdlgame copy_resources)