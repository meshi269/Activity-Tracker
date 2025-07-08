cmake_minimum_required(VERSION 3.31)  # Versione minima di CMake richiesta
project(untitled4)  # Nome del progetto

set(CMAKE_CXX_STANDARD 20)  # Imposta lo standard C++ a C++20

# Crea l'eseguibile principale con tutti i file sorgente
add_executable(untitled4
        main.cpp
        Activity.cpp
        Activity.h
        DayLog.cpp
        DayLog.h
        ActivityTest.cpp
        DayLogTest.cpp
        main_ncurses.cpp
)


add_subdirectory(lib/googletest)  # Aggiunge Google Test come sottodirectory

# Crea l'eseguibile per i test unitari
add_executable(unit_tests
        ActivityTest.cpp
        DayLogTest.cpp
        Activity.cpp
        DayLog.cpp
)

# Collega Google Test al target dei test
target_link_libraries(unit_tests gtest gtest_main)



# Configurazione per NCurses
target_link_libraries(untitled4 ${NCurses_LIBRARIES})
target_include_directories(untitled4 PRIVATE ${NCurses_INCLUDE_DIRS})


