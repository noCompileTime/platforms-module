#=======================================================================================================================
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN VC_EXTRALEAN NOMINMAX)
 target_precompile_headers(${PROJECT_NAME} PRIVATE headers.hpp)
     target_link_libraries(${PROJECT_NAME} PRIVATE gdi32 opengl32 user32)
            target_sources(${PROJECT_NAME} PRIVATE window.cpp window_context.cpp window_events.cpp window_input.cpp
                                                   platform_functions.cpp platform_factory.cpp)
#=======================================================================================================================