cmake_minimum_required(VERSION 3.24)

project(Sy2CPP)

set(CMAKE_CXX_STANDARD 20)


# ANTLR
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

set(ANTLR4_JAR_LOCATION )
set(ANTLR4_JAR_LOCATION ${PROJECT_SOURCE_DIR}/../libs/antlr-4.11.1-complete.jar)
# generate lexer

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
        )

set(headers
        ${CMAKE_SOURCE_DIR}/parsing/AstPrinter.h
        ${CMAKE_SOURCE_DIR}/symbol_table.h
        ${CMAKE_SOURCE_DIR}/ast.h
        ${CMAKE_SOURCE_DIR}/resolvers.h
        ${CMAKE_SOURCE_DIR}/general_utility.h
        ${CMAKE_SOURCE_DIR}/typing.h
        ${CMAKE_SOURCE_DIR}/exceptions.h
        )


# for the executable used for testing etc.
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


###### INSTALL LIB ######

# dir is relative to CMAKE_INSTALL_PREFIX (/usr/local)
install(TARGETS Sy2CPP-static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

set(public-headers
        ${headers})

# Install header files
install(FILES ${public-headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/Sy2CPP/)
