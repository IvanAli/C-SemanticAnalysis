cpp.tab.c cpp.tab.h: cpp.y
	bison -d cpp.y

lex.yy.c: cpp.l cpp.tab.h
	flex cpp.l

cppss: lex.yy.c cpp.tab.c cpp.tab.h
	g++ cpp.tab.c lex.yy.c -lfl -o cppss