project(HyperHockey)
cmake_minimum_required(VERSION 2.8)
add_definitions(-DDLIB_NO_GUI_SUPPORT)

aux_source_directory(. SRC_LIST)
#file(GLOB_RECURSE GAME_CODE "Game/*")
file(GLOB_RECURSE SFLIB "SFWin/*pp")
file(GLOB_RECURSE DEVLIB2 "DevLib2/*pp")
add_executable(${PROJECT_NAME} ${SRC_LIST} "dlib/all/source.cpp" ${SFLIB} ${DEVLIB2})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_mod" ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
