CC=g++
LIB=-std=c++11
create:   driver.cpp
	$(CC) $(LIB)  driver.cpp -c
	$(CC) $(LIB) driver.o  -o huffencode

run:
	./huffencode MRI

clean:
	rm driver.o
	rm huffencode
	
