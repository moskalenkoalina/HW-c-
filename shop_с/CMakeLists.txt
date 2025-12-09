cmake_minimum_required(VERSION 3.10)
project(shopc C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Налаштування для компілятора
if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Основний виконуваний файл програми магазину
add_executable(shopc main.c store.c)

# Окремий виконуваний файл для тестів
add_executable(shopc_test store_test.c)


# Додаткові цілі для зручності
add_custom_target(test
        COMMAND ./shopc_test
        DEPENDS shopc_test
        COMMENT "Running tests..."
)

add_custom_target(run
        COMMAND ./shopc
        DEPENDS shopc
        COMMENT "Running main program..."
)

add_custom_target(clean-all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
        COMMENT "Cleaning all build files..."
)