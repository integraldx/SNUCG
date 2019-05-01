main: main.cpp Camera.* Model.* Object.* SceneManager.* Vector3f.* Quaternion.* SplinedObject.* SplineParser.*
	g++ -std=c++17 main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Vector3f.cpp Quaternion.cpp SplinedObject.cpp SplineParser.cpp -lglut -lGLU -lGL -w -o main

run:
	make main
	./main

clean:
	rm ./main