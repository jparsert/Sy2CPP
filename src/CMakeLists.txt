cmake_minimum_required(VERSION 3.24)
include(FetchContent)

project(Sy2CPP)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# ANTLR
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)


FetchContent_Declare(
        antlr_jar
        URL https://www.antlr.org/download/antlr-4.11.1-complete.jar
        DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/_deps
        DOWNLOAD_NO_EXTRACT TRUE
# URL_HASH xxxx
)

FETCHCONTENT_MAKEAVAILABLE(antlr_jar)

set(ANTLR4_JAR_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/_deps/antlr-4.11.1-complete.jar)

# generate parser
antlr4_generate(
        antlrsygus
        ${CMAKE_CURRENT_SOURCE_DIR}/parsing/SyGuSv21.g4
        BOTH
        FALSE
        TRUE
)

# add directories for generated include files
include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_antlrsygus} )

# z3
find_package(Z3 REQUIRED)


set(sources
        ${CMAKE_SOURCE_DIR}/parsing/AstPrinter.cpp
        ${CMAKE_SOURCE_DIR}/symbol_table.cpp
        ${CMAKE_SOURCE_DIR}/ast.cpp
        ${CMAKE_SOURCE_DIR}/resolvers.cpp
        ${CMAKE_SOURCE_DIR}/general_utility.cpp
        ${CMAKE_SOURCE_DIR}/typing.cpp
        ${CMAKE_SOURCE_DIR}/exceptions.cpp
        Sy2CPP.cpp)

set(headers
        ${CMAKE_SOURCE_DIR}/parsing/AstPrinter.h
        ${CMAKE_SOURCE_DIR}/symbol_table.h
        ${CMAKE_SOURCE_DIR}/ast.h
        ${CMAKE_SOURCE_DIR}/resolvers.h
        ${CMAKE_SOURCE_DIR}/general_utility.h
        ${CMAKE_SOURCE_DIR}/typing.h
        ${CMAKE_SOURCE_DIR}/exceptions.h
        ${CMAKE_SOURCE_DIR}/Sy2CPP.h)

set(public-headers
        ${CMAKE_SOURCE_DIR}/parsing/AstPrinter.h
        ${CMAKE_SOURCE_DIR}/symbol_table.h
        ${CMAKE_SOURCE_DIR}/ast.h
        ${CMAKE_SOURCE_DIR}/resolvers.h
        ${CMAKE_SOURCE_DIR}/typing.h
        ${CMAKE_SOURCE_DIR}/exceptions.h
        ${CMAKE_SOURCE_DIR}/Sy2CPP.h)





#the executable used for testing etc.
add_executable(Sy2CPP main.cpp
        ${ANTLR4_SRC_FILES_antlrsygus}
        ${sources} ${headers} )

# add required runtime library
add_dependencies(Sy2CPP antlr4_shared)
target_link_libraries(Sy2CPP PRIVATE antlr4_shared z3)


####### STATIC LIBRARY #######
set(LIB_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib/${CMAKE_BUILD_TYPE})

add_library(Sy2CPP-static STATIC
        ${ANTLR4_SRC_FILES_antlrsygus}
        ${sources})


set_target_properties(Sy2CPP-static PROPERTIES
        OUTPUT_NAME sy2cpp
        CLEAN_DIRECT_OUTPUT 1
        )

set_target_properties(Sy2CPP-static PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_PATH}
        )


target_include_directories(Sy2CPP-static PRIVATE
        ${ANTLR4_INCLUDE_DIR_antlrsygus}/*.h
        )

target_include_directories(Sy2CPP-static PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

target_link_libraries(Sy2CPP-static PRIVATE
        antlr4_shared)

###### INSTALL LIB ######

# dir is relative to CMAKE_INSTALL_PREFIX (/usr/local)
install(TARGETS Sy2CPP-static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )


# Install header files
install(FILES ${public-headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/Sy2CPP/)
