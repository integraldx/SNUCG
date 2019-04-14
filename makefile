main: main.cpp Camera.* Model.* Object.* SceneManager.* Pod.* Vector3f.* Quaternion.*
	g++ -std=c++17 main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Pod.cpp Vector3f.cpp Quaternion.cpp -lglut -lGLU -lGL -w -o main

run:
	make main
	./main

clean:
	rm ./main