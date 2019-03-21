main: main.cpp
	g++ main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Util.cpp -lglut -lGLU -lGL -o main