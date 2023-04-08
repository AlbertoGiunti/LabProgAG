cmake_minimum_required(VERSION 3.24)
project(LabProgAG)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_Tests)

set(SOURCE_FILES Utente.cpp Utente.h ListaSpesa.cpp ListaSpesa.h Prodotto.cpp Prodotto.h Observer.h Subject.h TipoProdotto.cpp TipoProdotto.h)

add_executable(LabProgAG main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProgAG core)

