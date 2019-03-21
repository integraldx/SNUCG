main: main.cpp Display.hpp Display.cpp Input.cpp Input.hpp
	g++ main.cpp SceneManager.cpp Model.cpp Object.cpp Input.cpp -lglut -lGLU -lGL -o main