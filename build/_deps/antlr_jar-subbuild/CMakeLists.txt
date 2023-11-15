# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.27.7)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(antlr_jar-populate NONE)



include(ExternalProject)
ExternalProject_Add(antlr_jar-populate
                     "UPDATE_DISCONNECTED" "False" "EXTERNALPROJECT_INTERNAL_ARGUMENT_SEPARATOR" "URL" "https://www.antlr.org/download/antlr-4.13.1-complete.jar" "DOWNLOAD_DIR" "/home/julian/coding/Sy2CPP/build/_deps" DOWNLOAD_NO_EXTRACT YES
                    SOURCE_DIR          "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-src"
                    BINARY_DIR          "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


ExternalProject_Get_Property(antlr_jar-populate DOWNLOADED_FILE)
get_filename_component(dlFileName "${DOWNLOADED_FILE}" NAME)

ExternalProject_Add_Step(antlr_jar-populate copyfile
  COMMAND    "/usr/bin/cmake" -E copy_if_different
             "<DOWNLOADED_FILE>" "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-src"
  DEPENDEES  patch
  DEPENDERS  configure
  BYPRODUCTS "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-src/${dlFileName}"
  COMMENT    "Copying file to SOURCE_DIR"
)

