CXX=g++
FLAGS=

czes: main.cpp definitions.cpp socket.cpp
	$(CXX) $(FLAGS) main.cpp -o czes

