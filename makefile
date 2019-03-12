main: main.cpp Display.hpp Display.cpp
	g++ main.cpp Display.cpp Input.cpp -lglut -lGL -o main