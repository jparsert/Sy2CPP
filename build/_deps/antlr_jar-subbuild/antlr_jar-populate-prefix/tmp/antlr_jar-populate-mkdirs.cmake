# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-src"
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-build"
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix"
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix/tmp"
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix/src/antlr_jar-populate-stamp"
  "/home/julian/coding/Sy2CPP/build/_deps"
  "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix/src/antlr_jar-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix/src/antlr_jar-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/julian/coding/Sy2CPP/build/_deps/antlr_jar-subbuild/antlr_jar-populate-prefix/src/antlr_jar-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
