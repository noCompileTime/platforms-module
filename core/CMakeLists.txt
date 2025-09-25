#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ..)
 target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
            target_sources(${PROJECT_NAME} PUBLIC input_manager.cpp input_actions.cpp window_manager.cpp
                                                  platform_time.cpp platform_functions.cpp)
#=======================================================================================================================