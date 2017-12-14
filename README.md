===Bulding the lexer and the parser from scratch===

Inside this folder there is a Makefile

Run the following commands from the terminal:

  Change to the current working directory
  
  To build the project (make sure "make" is installed):
  make cppss
  
  
Note: The project has been built beforehand, so the "cppss" executable file already exists (built under gcc (Ubuntu 5.4.0-6ubuntu1~16.04.4))


===Running the executable===
  From the terminal (if current directory is ./src/frontend/lexer_and_parser) run:
    ./cppss < file.cpp
    
  "file.cpp" corresponds to a C++ file given as input to the parser. 
  The output of the operation is the parsing that tells whether the C++ program is correct or not ACCORDING TO
  the defined grammar
  
  There are several test files under the tests/ folder
  tests/pass/ contains cpp files that should pass the parser validation
  tests/fail/ contains cpp files that should fail at the parser validation
  