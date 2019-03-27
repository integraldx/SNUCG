main: main.cpp Camera.* Model.* Object.* SceneManager.* Util.* Pod.*
	g++ main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Util.cpp Pod.cpp -lglut -lGLU -lGL -o main

run:
	make main
	./main

clean:
	rm ./main