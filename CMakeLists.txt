cmake_minimum_required(VERSION 2.8)
project(translator)
set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
aux_source_directory(src/ CURR_SRC)

add_executable(translator ${CURR_SRC})
target_link_libraries(translator ${CURL_LIBRARIES})
