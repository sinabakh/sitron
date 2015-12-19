-include ./Objects/subdir.mk
-include ./Nodes/subdir.mk
-include ./Renderer/subdir.mk

all: low-level

low-level: lexparse high-level

high-level:
	@echo 'Building Code Without Rebuilding Lexparser!'
	g++ -std=c++11 -g -o  arendelle ./Parser/parser.cpp ./Lexer/tokens.cpp  $(CPP_SRC) main.cpp -lboost_system -lboost_filesystem -lsfml-graphics -lsfml-window -lsfml-system -lpthread

lexparse: parser lexer

parser:
	@echo 'YACC Bison Building'
	bison -d -o ./Parser/parser.cpp ./Parser/parser.y

lexer:
	@echo 'LEX Flex Building'
	flex -o ./Lexer/tokens.cpp ./Lexer/tokens.l

windows-64:
	x86_64-w64-mingw32-g++ -std=c++11 -g -o  arendelle.exe ./Parser/parser.cpp ./Lexer/tokens.cpp  $(CPP_SRC) main.cpp  /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-window.so -lboost_filesystem -lsfml-system -lpthread