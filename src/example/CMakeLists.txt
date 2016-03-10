

SET(PROJECT_NAME "example")

#Add definitions
#ADD_DEFINITIONS()


#Add all files
#AUX_SOURCE_DIRECTORY(. source_file_list)
FILE(GLOB source_file_list *.cpp)
FILE(GLOB header_file_list *.h)

SET(file_list 
	${source_file_list} 
	${header_file_list}
)

#Set Link Direction
#LINK_DIRECTORYES()

#Set Link Libraries
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} debug *.lib optimized *.lib)

ADD_EXECUTABLE(${PROJECT_NAME} ${file_list})

#set target properties
#SET_TARGET_PROPERTIES(apacheMod PROPERTIES
#	VERSION 1.0.0
#	SOVERSION 3
#	OUTPUT_NAME apacheMod
#)

#set install direction
#INSTALL( TARGETS apacheMod
#         LIBRARY DESTINATION ${PRJ_LIB_INSTALL_DIR}
#         ARCHIVE DESTINATION ${PRJ_LIB_INSTALL_DIR}
#         RUNTIME DESTINATION ${PRJ_BIN_INSTALL_DIR}
#)