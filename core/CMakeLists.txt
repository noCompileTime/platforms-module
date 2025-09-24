#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ..)
 target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
            target_sources(${PROJECT_NAME} PUBLIC input_manager.cpp input_actions.cpp input_mouse.cpp window_manager.cpp
                                                  platform_functions.cpp platform_time.cpp)
#=======================================================================================================================