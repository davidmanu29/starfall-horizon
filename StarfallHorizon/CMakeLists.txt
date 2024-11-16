add_executable(${STARFALL_HORIZON_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC sfml-audio)
target_link_libraries(${STARFALL_HORIZON_GAME_TARGET_NAME} PUBLIC sfml-network)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(
		TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND 
		${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(sfml-graphics ${STARFALL_HORIZON_GAME_TARGET_NAME})
CopyLibToTarget(sfml-window ${STARFALL_HORIZON_GAME_TARGET_NAME})
CopyLibToTarget(sfml-system ${STARFALL_HORIZON_GAME_TARGET_NAME})
CopyLibToTarget(sfml-audio ${STARFALL_HORIZON_GAME_TARGET_NAME})
CopyLibToTarget(sfml-network ${STARFALL_HORIZON_GAME_TARGET_NAME})