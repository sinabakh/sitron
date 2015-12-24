# Sitron
Sitron is a REPL Arendelle 2XIV Engine based on C++.

## Build The Code
To build the code you need to have `g++` and also few libraries mentioned in Libraries section.

Running `Makefile` by `make` command will build the code and you will have an `arendelle` binary file.

## Libraries
- [Boost Filesystem](https://github.com/boostorg/filesystem)
- [Flex](http://flex.sourceforge.net/)
- [Bison](https://www.gnu.org/software/bison/)
- [SFML](https://github.com/SFML/SFML)

## How Things Work
Everytime you run `arendelle`, the [main.cpp](https://github.com/arendelle/sitron/blob/master/main.cpp)
will be the arendelle starting point. And from there you can trace the program work flow.

Here is a brief description for folders and few files:
* [Lexer/](https://github.com/arendelle/sitron/tree/master/Lexer) :
  * [tokens.l](https://github.com/arendelle/sitron/blob/master/Lexer/tokens.cpp) It's the file where we define our Tokens.
  * [tokens.cpp](https://github.com/arendelle/sitron/blob/master/Lexer/tokens.l) A generated file from `tokens.l`.

* [Parser/](https://github.com/arendelle/sitron/tree/master/Parser) :
  * [parser.y](https://github.com/arendelle/sitron/blob/master/Parser/parser.y) It's the file where the Parsing part of code is.
  * [parser.hpp](https://github.com/arendelle/sitron/blob/master/Parser/parser.hpp) A generated file from `parser.y`.
  * [parser.cpp](https://github.com/arendelle/sitron/blob/master/Parser/parser.cpp) A generated file from `parser.y`.

* [Nodes/](https://github.com/arendelle/sitron/tree/master/Nodes): The directory where our ATS nodes codes are.

* [Objects/](https://github.com/arendelle/sitron/tree/master/Objects): The directory where actual Arendelle codes are.

* [Renderer/](https://github.com/arendelle/sitron/tree/master/Renderer): The directory where Rendering codes are.

### Not Implemented Features
* Arrays

### Buggy Features
* Whitespaces in between spaces name characters


### Features To Add
* A Colorful Render Engine

## License
     DO WHAT THE HELL YOU WANT TO PUBLIC LICENSE
      Version 2, December 2004

     Copyright (C) 2015 Sina Bakhtiari <s@arendelle.org>

     Everyone is permitted to copy and distribute Sitron or modified
     copies of this license document, and changing it is allowed as long
     as the name is changed.

     DO WHAT THE HELL YOU WANT TO PUBLIC LICENSE
     TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

     0. You just DO WHAT THE HELL YOU WANT TO.

