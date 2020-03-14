CC=g++
LIB=-std=c++11
create:   driver.cpp
	$(CC) $(LIB) HuffmanNode.h HuffmanNode.cpp huffencode.h huffencode.cpp driver.cpp  -c
	$(CC) $(LIB) HuffmanNode.o huffencode.o driver.o  -o huffencode



test:
	$(CC) $(LIB) HuffmanNode.h HuffmanNode.cpp huffencode.h huffencode.cpp driver.cpp  -c
	$(CC) $(LIB) unitTests.h UnitTests.cpp -c
	$(CC) $(LIB) HuffmanNode.o huffencode.o UnitTests.o -o test

clean:
	rm driver.o
	rm huffencode.o
	rm huffencode.h.gch
	rm HuffmanNode.o
	rm HuffmanNode.h.gch
	rm huffencode

cleanTest:
	rm unitTests.h.gch
	rm UnitTests.o
	rm test