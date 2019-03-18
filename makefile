main: main.cpp Display.hpp Display.cpp Input.cpp Input.hpp
	g++ main.cpp Display.cpp Input.cpp -lglut -lGLU -lGL -o main