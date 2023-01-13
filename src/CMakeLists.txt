cmake_minimum_required(VERSION 3.24)

project(physer)

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


# add generated source files
add_executable( physer main.cpp ${ANTLR4_SRC_FILES_antlrsygus}
        verification/sygus_smt_rep.cpp verification/sygus_smt_rep.h
        parsing/to_string_printer.cpp parsing/to_string_printer.h
        exceptions/unsupported_feature.cpp exceptions/unsupported_feature.h exceptions/not_implemented.cpp
            exceptions/not_implemented.h
        parsing/SymbolTable.cpp parsing/SymbolTable.h parsing/ast.cpp parsing/ast.h exceptions/IOException.cpp exceptions/IOException.h utils/IOHelpers.h utils/IOHelpers.cpp exceptions/UnknownSymbol.cpp exceptions/UnknownSymbol.h parsing/resolvers.cpp parsing/resolvers.h)

# add required runtime library
add_dependencies( physer antlr4_shared)

target_link_libraries( physer PRIVATE antlr4_shared z3)