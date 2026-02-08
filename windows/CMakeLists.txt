#=======================================================================================================================
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN VC_EXTRALEAN NOMINMAX)
 target_precompile_headers(${PROJECT_NAME} PRIVATE platform_headers.hpp platform_internal.hpp)
     target_link_libraries(${PROJECT_NAME} PRIVATE gdi32 opengl32 user32)
            target_sources(${PROJECT_NAME} PRIVATE platform_functions.cpp platform_factory.cpp platform_monitor.cpp
                                                   window.cpp window_events.cpp window_context.cpp window_input.cpp)
#=======================================================================================================================