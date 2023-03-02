add_library(
    tmath 
    src/vector2.cpp
)

target_include_directories(tmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
