#=======================================================================================================================
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN VC_EXTRALEAN)
 target_precompile_headers(${PROJECT_NAME} PRIVATE headers.hpp)
     target_link_libraries(${PROJECT_NAME} PRIVATE gdi32 opengl32 user32)
            target_sources(${PROJECT_NAME} PRIVATE platforms_factory.cpp window.cpp window_events.cpp window_input.cpp)
#=======================================================================================================================