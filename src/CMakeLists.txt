cmake_minimum_required(VERSION 3.10.2)
project(WebSocketPOC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17 -O3")
message( ${CMAKE_CURRENT_SOURCE_DIR} )

find_package(Boost REQUIRED COMPONENTS system thread filesystem)

# add_library(Logger SHARED Logger.cpp)
# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS})
# endif()

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

add_executable(${PROJECT_NAME} main.cpp)
# add_executable(main main.cpp WebsocketProducer.cpp)

#Add -lssl -lcrypto to build
target_link_libraries(${PROJECT_NAME} PUBLIC ssl crypto)

#include local lib location
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/lib/ )

##########################################
