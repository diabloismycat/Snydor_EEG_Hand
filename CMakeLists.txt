cmake_minimum_required(VERSION 3.10)

project(Snydor_EEG_Hand)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(/Users/adora/Desktop/eigen-5.0.0)

add_executable(Snydor_EEG_Hand
    src/main.cpp
    src/CSVReader.cpp
    src/EEGBuffer.cpp
    src/MatrixConverter.cpp
    src/ICA.cpp
)