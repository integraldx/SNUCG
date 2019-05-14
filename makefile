main: main.cpp Camera.* Model.* Object.* SceneManager.* Vectorf.* Quaternion.* SplineParser.* Material.* SphereObject.*
	g++ -std=c++17 main.cpp SceneManager.cpp Model.cpp Object.cpp Camera.cpp Vectorf.cpp Quaternion.cpp SplineParser.cpp Material.cpp SphereObject.cpp -lglut -lGLU -lGL -w -o main

run:
	make main
	./main iceCream.txt

clean:
	rm ./main
