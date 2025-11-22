add_executable(${STARFALL_HORIZON_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/Spaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/Spaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerSpaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerSpaceship.cpp
)

target_include_directories(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC ${STARFALL_HORIZON_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(
		TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND 
		${CMAKE_COMMAND} -E copy_directory
		$<TARGET_FILE_DIR:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(${STARFALL_HORIZON_ENGINE_TARGET_NAME} ${STARFALL_HORIZON_GAME_TARGET_NAME})

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
	TARGET ${STARFALL_HORIZON_GAME_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${RESOURCE_SRC_DIR}
	$<TARGET_FILE_DIR:${STARFALL_HORIZON_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
	"config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)