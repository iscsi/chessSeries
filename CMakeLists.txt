cmake_minimum_required (VERSION 3.4)
project (chessSeries)
add_executable(chessSeries src/main.cpp src/board.h src/types.h src/bitboard.h)
add_definitions(-DHOME -D_CRT_SECURE_NO_WARNINGS) 
