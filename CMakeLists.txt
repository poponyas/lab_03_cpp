cmake_minimum_required(VERSION 3.10)
project(Lab03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение отладочной информации
set(CMAKE_BUILD_TYPE Debug)

# Основная программа
add_executable(lab03
    main.cpp
    src/Trapeze.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/FiguresArray.cpp
)

target_include_directories(lab03 PRIVATE include)

# Тесты
enable_testing()

find_package(GTest REQUIRED)

add_executable(tests
    tests/test_figures.cpp
    src/Trapeze.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/FiguresArray.cpp
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests GTest::GTest GTest::Main)

add_test(NAME FigureTests COMMAND tests)