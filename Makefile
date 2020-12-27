CXX=g++
FLAGS=-std=c++20

czes: main.cpp definitions.cpp loading.cpp socket.cpp
	$(CXX) $(FLAGS) main.cpp -o czes

