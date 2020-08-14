build:
	g++ -std=c++14 -pedantic -Wall ./src/*.cpp -o game -lSDL2
	make run

run:
	./game
	make clean

clean:
	rm game
