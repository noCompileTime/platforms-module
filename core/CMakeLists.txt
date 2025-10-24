#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ..)
 target_precompile_headers(${PROJECT_NAME} PUBLIC platform_headers.hpp)
            target_sources(${PROJECT_NAME} PUBLIC platform_time.cpp platform_functions.cpp platform_factory.cpp
                                                  input_manager.cpp input_actions.cpp window_manager.cpp)
#=======================================================================================================================