cmake_minimum_required (VERSION 3.6)
project(connect4-game)

if(NOT SLEEPY_DISCORD_CMAKE)
	add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/Final)
endif()
#https://stackoverflow.com/questions/51380520/how-to-write-cmake-for-multiple-cpp-files-and-headers-in-different-folders


set(my_includes 
"./includes/headers/constants.h"
"./includes/headers/connect4.h"
"./includes/headers/client.h"
)
set(my_cpps 
"./includes/src/client.cpp"
"./includes/src/connect4.cpp"
"./includes/src/main.cpp")

add_executable(connect4-game
	${my_includes} ${my_cpps}
)

include_directories("./includes")

target_link_libraries(connect4-game
	sleepy-discord
)
