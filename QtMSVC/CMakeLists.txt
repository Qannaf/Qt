cmake_minimum_required(VERSION 3.17)

project(QtVTKProject)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(OpenGL)
find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6OpenGL REQUIRED)
find_package(Qt6Xml REQUIRED)
find_package(Qt6Widgets REQUIRED)

#======================= INCLUSION OF VTK ======================#
set(VTK_DIR $ENV{VTK_DIR})
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#======================= Find boost on WIN32 ======================#
if (WIN32)

	set(Boost_ADDITIONAL_VERSIONS "1.72.0" "1.47" "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
	set(OGRE_BOOST_COMPONENTS thread date_time)
	find_package(Boost 1.72.0 COMPONENTS filesystem regex)
	if (NOT Boost_FOUND)
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	else()
		include_directories(${Boost_INCLUDE_DIR})
		set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
	endif ()
	include_directories(${Boost_INCLUDE_DIR})
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
	
	file(
		GLOB_RECURSE
		Boost_DLLs
		${Boost_LIBRARY_DIRS}/*.dll)
		
	message("Boost lib in ${Boost_LIBRARY_DIRS}: ${Boost_DLLs}")
endif (WIN32)



#======================= Ogre3D 1.11.2 ======================#
#CMAKE module paths
if(WIN32)
	if("$ENV{OGRE_HOME}" STREQUAL "")
		set(CMAKE_MODULE_PATH "${OGRE_DIR}/CMake/;${CMAKE_MODULE_PATH}")
	else()
		set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
	endif("$ENV{OGRE_HOME}" STREQUAL "")
endif(WIN32)

if(UNIX)
	set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/")
	LIST(APPEND CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake")
	LIST(APPEND CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake")
endif(UNIX)
# Ogre3D 1.7.4
#find_package(OGRE REQUIRED)
#include_directories(${OGRE_INCLUDE_DIRS})

# specify which version and components you need（）
find_package(OGRE 1.12 REQUIRED COMPONENTS Bites RTShaderSystem)
# copy resource.cfg next to our binaries where OGRE looks for it
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})


#======================= ViSP ======================#





#======================= INCLUSION OF Our Code ======================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR} ${INCLUDE_DIR} ${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable(QtVTKProject WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(QtVTKProject ${SOURCES})
endif()

# Add the target includes
target_include_directories(QtVTKProject PRIVATE ${FORMS_DIR} ${INCLUDE_DIR} ${SOURCE_DIR})
#===================== LINKING LIBRARIES =======================#
target_link_libraries( QtVTKProject Qt6::OpenGL Qt6::Xml Qt6::Widgets OgreBites OgreRTShaderSystem ${QT_LIBRARIES} ${OPENGL_LIBRARIES} ${VTK_LIBRARIES} ${OGRE_LIBRARY} )




#===================== Install =======================#
