#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ..)
 target_precompile_headers(${PROJECT_NAME} PUBLIC platform_headers.hpp platform_internal.hpp)
            target_sources(${PROJECT_NAME} PUBLIC platform_functions.cpp platform_factory.cpp window_manager.cpp
                                                  input_manager.cpp input_actions.cpp input_state.cpp)
#=======================================================================================================================