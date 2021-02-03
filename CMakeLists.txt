cmake_minimum_required(VERSION 3.0.0)
project(rpg_adventure VERSION 0.1.0)

include(CTest)
include_directories(include)
find_package(Boost COMPONENTS system filesystem REQUIRED serialization)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib )
enable_testing()

#add_library(Character src/v1/Character.cpp)
#add_library(InGame src/v1/InGame.cpp)
#target_link_libraries(InGame Character)

add_executable(game_start src/v1/main.cpp src/v1/Character.cpp src/v1/InGame.cpp) 
target_link_libraries(game_start ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

