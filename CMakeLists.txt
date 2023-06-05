cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(Thread_Consumer_Product)

set(${PROJECT_NAME}_srcs
    src/Logger.cpp
    src/CustomGuard.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} 
    ${${PROJECT_NAME}_srcs}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/headers/
)