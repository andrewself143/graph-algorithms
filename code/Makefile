main: main.o hash.o graph_algorithms.o node.o graph.o
	g++ -std=c++11 main.o hash.o graph_algorithms.o node.o graph.o -lsodium -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -lsodium

hash.o: hash.cpp
	g++ -std=c++11 -c hash.cpp

graph_algorithms.o: graph_algorithms.cpp graph-algs.h
	g++ -std=c++11 -c graph_algorithms.cpp

node.o: node.cpp node.h
	g++ -std=c++11 -c node.cpp

graph.o: graph.cpp graph.h
	g++ -std=c++11 -c graph.cpp

barabasi.o: barabasi.cpp
	g++ -std=c++11 -c barabasi.cpp

clean:
	rm main main.o graph.o node.o graph_algorithms.o hash.o
