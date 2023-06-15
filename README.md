# Syntax Guided Synthesis library for C++

Feel free to write pull requests or write issues for feature requests.

This is a library for the SyGuS format. Mostly for parsing and getting an AST as well as a symbol table.
I hope to be able to extend this library further to also include interfaces to solvers etc.
Some of the features of this library include:
* Supporting Indexed Identifiers
* No boost library
* C++20 (not fully as most compilers don't support everything yet f.e. modules)


### USAGE:
Download repo,  run `cmake`, `make`, and `make install`

With CMAKE in the project use `FetchContent`
```
...
include(FetchContent)
...
FetchContent_Declare(Sy2CPP
        GIT_REPOSITORY https://github.com/jparsert/Sy2CPP
        GIT_TAG main
)
FetchContent_MakeAvailable(Sy2CPP)

...

target_link_libraries(sometarget PRIVATE Sy2CPP-shared)
```

### Guidlines
* use modern c++
* References where possible
* raw pointers where memory is not managed and references are not possible
* smart pointers where memory is managed
* STL where possible
* never use new/malloc/delete use make_shared/ etc.

### Currently Supported Theories
* LIA (tested on LIA/LIA_INV of private REPO)


### Requrirements
* c++ supporting standard 2020
* antlr4 runtime
* ...


#### Easy TODOs
* "Adequate" variable stack datatype for SymbolTable
* check if symbol already in the signature (in a lot of define/declare commands)
* check that variables are distinct (in binders and arguments).
* constexpr constructors for EitherIdentififer/Sort and Function/Sort/Symbol Descriptors

### TODO
* TESTING!!!
* Parametric sorts
* More Theories