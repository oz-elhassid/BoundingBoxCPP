CPP	:=	g++ -Wall -Wextra

.PHONY: all clean

all: tests

tests: tests.cpp BoundingBox.o
	$(CPP) -o tests tests.cpp BoundingBox.o

BoundingBox.o: BoundingBox.cpp
	$(CPP) -c -o BoundingBox.o BoundingBox.cpp

clean:
	@rm -v BoundingBox.o tests 2>/dev/null || true