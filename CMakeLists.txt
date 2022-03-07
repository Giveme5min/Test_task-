
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(circle_buffer
  LANGUAGES CXX
  )

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# добовляем каталог src
add_subdirectory(src)

































