build: compile
	g++ main.o -o main -L "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile:
	g++ -c main.cpp -I "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\include" 