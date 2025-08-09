#=======================================================================================================================
target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
    target_link_libraries(${PROJECT_NAME} PUBLIC gdi32 opengl32 user32)
           target_sources(${PROJECT_NAME} PUBLIC window.cpp)
#=======================================================================================================================