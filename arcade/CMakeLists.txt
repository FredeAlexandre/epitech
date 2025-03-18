cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)


file(GLOB_RECURSE TEST_SOURCES *.t.cpp)
file(GLOB_RECURSE SRC_COMMON src/common/**.cpp)
list(REMOVE_ITEM SRC_COMMON ${TEST_SOURCES})

project(arcade VERSION 1.0)
file(GLOB_RECURSE SRC_FILES src/core/**.cpp)
list(REMOVE_ITEM SRC_FILES ${TEST_SOURCES})
add_executable(arcade ${SRC_FILES} ${SRC_COMMON})
target_include_directories(arcade PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(arcade PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/core/include)

file(GLOB_RECURSE SRC_NCURSES src/graphicals/ncurses/**.cpp)
list(REMOVE_ITEM SRC_NCURSES ${TEST_SOURCES})
add_library(arcade_ncurses SHARED ${SRC_NCURSES} ${SRC_COMMON})
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})
target_include_directories(arcade_ncurses PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_SDL2 src/graphicals/sdl2/**.cpp)
list(REMOVE_ITEM SRC_SDL2 ${TEST_SOURCES})
add_library(arcade_sdl2 SHARED ${SRC_SDL2} ${SRC_COMMON})
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_include_directories(arcade_sdl2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_SFML src/graphicals/SFML/**.cpp)
list(REMOVE_ITEM SRC_SFML ${TEST_SOURCES})
add_library(arcade_sfml SHARED ${SRC_SFML} ${SRC_COMMON})
set(BUILD_SHARED_LIBS TRUE)
find_package(SFML 2.5
    COMPONENTS
    system window graphics network audio REQUIRED
)
target_link_libraries(arcade_sfml sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_include_directories(arcade_sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_SNAKE src/games/snake/**.cpp)
list(REMOVE_ITEM SRC_SNAKE ${TEST_SOURCES})
add_library(arcade_snake SHARED ${SRC_SNAKE} ${SRC_COMMON})
target_include_directories(arcade_snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_snake PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_NIBBLER src/games/nibbler/**.cpp)
list(REMOVE_ITEM SRC_NIBBLER ${TEST_SOURCES})
add_library(arcade_nibbler SHARED ${SRC_NIBBLER} ${SRC_COMMON})
target_include_directories(arcade_nibbler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_nibbler PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_MENU src/core/Menu.cpp)
list(REMOVE_ITEM SRC_MENU ${TEST_SOURCES})
add_library(arcade_menu SHARED ${SRC_MENU} ${SRC_COMMON})
target_include_directories(arcade_menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(arcade_menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/core/include)
set_target_properties(arcade_menu PROPERTIES PREFIX "")

file(GLOB_RECURSE SRC_CORE src/core/**.cpp)
list(REMOVE_ITEM SRC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/src/core/main.cpp)
list(REMOVE_ITEM SRC_CORE ${TEST_SOURCES})