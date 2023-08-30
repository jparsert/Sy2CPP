cmake_minimum_required(VERSION 3.22.1)
include(FetchContent)

project(Sy2CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

# adding antler cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Donwload generator jar
FetchContent_Declare(
        antlr_jar
        URL https://www.antlr.org/download/antlr-4.13.0-complete.jar
        DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/_deps
        DOWNLOAD_NO_EXTRACT TRUE)
FETCHCONTENT_MAKEAVAILABLE(antlr_jar)
set(ANTLR4_JAR_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/_deps/antlr-4.13.0-complete.jar)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# Specify the version of the antlr4 library needed for this project.
# By default the latest version of antlr4 will be used.  You can specify a
# specific, stable version by setting a repository tag value or a link
# to a zip file containing the libary source.
set(ANTLR4_TAG 4.13.0)
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/4.13.0.zip)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${ANTLR4_JAR_LOCATION})
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

antlr_target(antlrsygus ${src_dir}/SyGuSv21.g4 VISITOR TRUE)


# add directories for generated include files
include_directories(${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR_antlrsygus_OUTPUT_DIR} )



set(sources
        ${src_dir}/AstPrinter.cpp ${src_dir}/symbol_table.cpp ${src_dir}/ast.cpp
        ${src_dir}/resolvers.cpp ${src_dir}/general_utility.cpp ${src_dir}/typing.cpp
        ${src_dir}/exceptions.cpp ${src_dir}/Sy2CPP.cpp)

set(headers
        ${src_dir}/AstPrinter.h ${src_dir}/symbol_table.h ${src_dir}/ast.h
        ${src_dir}/resolvers.h ${src_dir}/general_utility.h ${src_dir}/typing.h
        ${src_dir}/exceptions.h ${src_dir}/Sy2CPP.h)

set(public-headers
        ${src_dir}/AstPrinter.h ${src_dir}/symbol_table.h ${src_dir}/ast.h
        ${src_dir}/resolvers.h ${src_dir}/typing.h ${src_dir}/exceptions.h
        ${src_dir}/Sy2CPP.h)


#the executable used for testing etc.
add_executable(Sy2CPP ${src_dir}/main.cpp
        ${ANTLR_antlrsygus_CXX_OUTPUTS}
        ${sources} ${headers} )
add_dependencies(Sy2CPP antlr4_shared)
target_link_libraries(Sy2CPP PRIVATE antlr4_shared)

##############################
####### SHARED LIBRARY #######
add_library(Sy2CPP-shared SHARED
        ${sources}  ${ANTLR_antlrsygus_CXX_OUTPUTS})

set_target_properties(Sy2CPP-shared PROPERTIES
        OUTPUT_NAME sy2cpp)

target_compile_options(Sy2CPP-shared PRIVATE -Wno-return-type)

target_link_libraries(Sy2CPP-shared PRIVATE antlr4-runtime antlr4_shared)
target_include_directories(Sy2CPP-shared PUBLIC ${src_dir})
###### INSTALL LIB ######

# dir is relative to CMAKE_INSTALL_PREFIX (/usr/local)
install(TARGETS Sy2CPP-shared
        LIBRARY DESTINATION "/usr/lib"
        ARCHIVE DESTINATION "/usr/lib"
        )

# Install header files
install(FILES ${public-headers} DESTINATION "/usr/include/Sy2CPP/")


##############################
####### STATIC LIBRARY #######
add_library(Sy2CPP-static STATIC
        ${sources}  ${ANTLR_antlrsygus_CXX_OUTPUTS})

target_compile_options(Sy2CPP-static PRIVATE -Wno-return-type)


set_target_properties(Sy2CPP-static PROPERTIES
        OUTPUT_NAME sy2cpp)

target_link_libraries(Sy2CPP-static PRIVATE antlr4-runtime antlr4_shared)
target_include_directories(Sy2CPP-static PUBLIC ${src_dir})
###### INSTALL LIB ######

# dir is relative to CMAKE_INSTALL_PREFIX (/usr/local)
install(TARGETS Sy2CPP-static
        LIBRARY DESTINATION "/usr/lib"
        ARCHIVE DESTINATION "/usr/lib"
        )

# Install header files
install(FILES ${public-headers} DESTINATION "/usr/include/Sy2CPP/")

