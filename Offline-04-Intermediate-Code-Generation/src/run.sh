#!/bin/bash
yacc  -d -y 1905066.y
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex 1905066.l
echo 'Generated the scanner C file'
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
#g++ -w -g y.o l.o -fsanitize=address -o 1905066_parser
g++ y.o l.o -lfl -o 1905066_parser
echo 'All ready, running'
#valgrind --leak-check=full --show-leak-kinds=all -s ./1905066_parser  1905066_input.c
./1905066_parser  1905066_input.c