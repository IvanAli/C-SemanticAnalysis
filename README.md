# C++98 semantic analyzer

For my Compilers project, I took on a subset (big enough) of the C++98 programming language. The reduced grammar found in the Yacc/Bison file is based off that from "The C++ programming language" by B. Stroustrup and [this](http://www.nongnu.org/hcb/ "Hyperlinked C++ BNF Grammar") fabulous website that made it easier to understand the grammar hollistically.

## Bulding the lexer and the parser from scratch

Inside this folder there is a Makefile

Run the following commands from the terminal:

-Change to the current working directory
  
-To build the project (make sure "make" is installed):
  make cppss
  
  
Note: The project has been built beforehand, so the "cppss" executable file already exists (built under gcc (Ubuntu 5.4.0-6ubuntu1~16.04.4))


## Running the executable
  From the terminal run:
    ./cppss < file.cpp
    
  "file.cpp" corresponds to a C++ file given as input to the parser. 
  The output of the operation is the parsing that tells whether the C++ program is correct or not according to
  the defined grammar
  
  There are several test files (valid and unvalid C++ programs) under the tests/ folder. These are meant to be used to verify that the parsing and the semantic analysis is done correctly.
  - tests/pass/ contains cpp files that should pass the parser validation
  - tests/fail/ contains cpp files that should fail the parser validation

  
## Todo
As the scope was bigger than expected, I decided to deliver work up to this point. Machine code generation is the next step to do, which can be done either through the help of **LLVM** or a hand-crafted translation to the RISC instruction set.
  

