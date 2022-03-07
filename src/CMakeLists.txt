 #cmake .. -DCMAKE_BUILD_TYPE=Release
#cmake --build . --verbose --config Release
#cmake .. -DCMAKE_BUILD_TYPE=debug
#cmake --build . --verbose --config debug


message (${CMAKE_SYSTEM_NAME} "-" ${CMAKE_SYSTEM_VERSION} )
cmake_minimum_required(VERSION 3.5)
add_executable(CircleBuffer circleBuffer.cpp)




























