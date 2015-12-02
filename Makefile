-include ./Objects/subdir.mk
-include ./Nodes/subdir.mk

all: low-level

low-level: lexparse high-level

high-level:
	@echo 'Building Code Without Rebuilding Lexparser!'
	g++ -std=c++11 -g -o  arendelle ./Parser/parser.cpp ./Lexer/tokens.cpp  $(CPP_SRC) main.cpp -lboost_system -lboost_filesystem

lexparse: parser lexer

parser:
	@echo 'YACC Bison Building'
	bison -d -o ./Parser/parser.cpp ./Parser/parser.y

lexer:
	@echo 'LEX Flex Building'
	flex -o ./Lexer/tokens.cpp ./Lexer/tokens.l
