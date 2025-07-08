cmake_minimum_required(VERSION 3.31)  # Versione minima di CMake richiesta
project(Laboratorio)  # Nome del progetto

set(CMAKE_CXX_STANDARD 20)  # Imposta lo standard C++ a C++20

# Crea l'eseguibile principale con tutti i file sorgente
add_executable(Laboratorio
        main.cpp
        Activity.cpp
        Activity.h
        DayLog.cpp
        DayLog.h
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
target_link_libraries(Laboratorio ${NCursesw_LIBRARIES})
target_include_directories(Laboratorio PRIVATE ${NCursesw_INCLUDE_DIRS})
target_link_libraries(Laboratorio PRIVATE ncursesw)

