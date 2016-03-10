

SET(COMMON_LIST
	${PROJECT_SOURCE_DIR}/src/common/CommonFunctions.h
	${PROJECT_SOURCE_DIR}/src/common/CommonFunctions.cpp
)
SOURCE_GROUP(COMMON_SRCS FILES ${COMMON_LIST})


IF(BUILD_DYNAMIC)

MACRO(START_EXAMPLE)

    	INCLUDE_DIRECTORIES($ENV{OSG_HOME}/include)
	LINK_DIRECTORIES($ENV{OSG_HOME}/lib)
	
	FILE(GLOB source_file_list ${PROJECT_NAME}/*.cpp)
	FILE(GLOB header_file_list ${PROJECT_NAME}/*.h)
	MESSAGE(STATUS  ${PROJECT_NAME}-"this is source file list: " ${source_file_list})
	
	SET(file_list 
	${source_file_list}
	${header_file_list}
	${PROJECT_SOURCE_DIR}/src/common/CommonFunctions.h
	${PROJECT_SOURCE_DIR}/src/common/CommonFunctions.cpp
	)

	ADD_EXECUTABLE(${PROJECT_NAME} ${file_list})
IF(WIN32)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
		debug osgd.lib optimized osg.lib
		debug osgViewerd.lib optimized osgViewer.lib
		debug OpenThreadsd.lib optimized OpenThreads.lib
		debug osgUtild.lib optimized osgUtil.lib
		debug osgTextd.lib optimized osgText.lib
		debug osgGAd.lib optimized osgGA.lib
		debug osgDBd.lib optimized osgDB.lib
	)
ENDIF(WIN32)
if(UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
		debug libosg.so optimized libosg.so
		debug libosgViewer.so	optimized libosgViewer.so
		debug libOpenThreads.so	optimized libOpenThreads.so
		debug libosgUtil.so	optimized libosgUtil.so
		debug libosgText.so	optimized libosgText.so
		debug libosgGA.so	optimized libosgGA.so 
		debug libosgDB.so	optimized libosgDB.so
	)
ENDIF(UNIX)

ENDMACRO(START_EXAMPLE)

#MESSAGE(STATUS "This is additionan include path" ${CMAKE_INCLUDE_PATH})

ADD_SUBDIRECTORY(example)
SET(PROJECT_NAME "exam01")
START_EXAMPLE()

SET(PROJECT_NAME "exam02")
START_EXAMPLE()

SET(PROJECT_NAME "billboard")
START_EXAMPLE()

SET(PROJECT_NAME "geometry")
START_EXAMPLE()

SET(PROJECT_NAME "bump_mapping")
START_EXAMPLE()

SET(PROJECT_NAME "shadow")
START_EXAMPLE()

SET(PROJECT_NAME "skybox")
START_EXAMPLE()

SET(PROJECT_NAME "water")
START_EXAMPLE()

SET(PROJECT_NAME "cloud")
START_EXAMPLE()

SET(PROJECT_NAME "octree")
START_EXAMPLE()

SET(PROJECT_NAME "occlusion")
START_EXAMPLE()

ENDIF()

