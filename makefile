main: main.cpp Camera.* Model.* Object.* SceneManager.* Util.*
	g++ main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Util.cpp -lglut -lGLU -lGL -o main