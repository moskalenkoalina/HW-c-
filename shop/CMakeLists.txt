cmake_minimum_required(VERSION 3.10)
project(shop)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основні програми
add_executable(shop main.cpp store.cpp)
add_executable(shop_test store_test.cpp store.cpp)

# Проста ціль для запуску тестів
add_custom_target(test
        COMMAND ./shop_test
        DEPENDS shop_test
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)