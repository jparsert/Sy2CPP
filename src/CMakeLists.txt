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


# for the executable used for testing etc.
add_executable(Sy2CPP main.cpp ${ANTLR4_SRC_FILES_antlrsygus}
        parsing/AstPrinter.cpp parsing/AstPrinter.h
        exceptions/unsupported_feature.cpp exceptions/unsupported_feature.h exceptions/not_implemented.cpp
            exceptions/not_implemented.h
        symbol_table.cpp symbol_table.h ast.cpp ast.h exceptions/UnknownSymbol.cpp exceptions/UnknownSymbol.h resolvers.cpp resolvers.h exceptions/wrong_arguments.cpp exceptions/wrong_arguments.h general_utility.cpp general_utility.h typing.cpp typing.h exceptions/typing_error.cpp exceptions/typing_error.h exceptions.cpp exceptions.h)

# add required runtime library
add_dependencies(Sy2CPP antlr4_shared)
target_link_libraries(Sy2CPP PRIVATE antlr4_shared z3)

