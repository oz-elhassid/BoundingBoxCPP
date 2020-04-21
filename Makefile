CPP	:=	g++ -Wall -Wextra

.PHONY: all check clean

all: tests

tests: tests.cpp BoundingBox.o
	$(CPP) -o tests tests.cpp BoundingBox.o

BoundingBox.o: BoundingBox.cpp
	$(CPP) -c -o BoundingBox.o BoundingBox.cpp

check: tests
	./tests

clean:
	@rm -v BoundingBox.o tests 2>/dev/null || true
