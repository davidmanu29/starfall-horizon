cmake_minimum_required(VERSION 3.31.0)

project(StarfallHorizon
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

# create var
set(STARFALL_HORIZON_GAME_TARGET_NAME StarfallHorizonGame)

add_subdirectory(StarfallHorizon)