main: main.cpp
	g++ main.cpp Binaries/libglfw3.a -lGL -ldl -lX11 -lXrandr -lXi -lXext -lXcursor -lXxf86vm -lXinerama -lpthread -o main