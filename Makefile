all: compile link execute

compile:
	g++ -c src/Entidades/Personagens/*.cpp src/Entidades/Obstaculos/*.cpp src/Entidades/*.cpp src/Fases/*.cpp src/Gerenciador/*.cpp src/Menus/*.cpp src/Lista/*.cpp src/*.cpp -I "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\include"

link:
	g++ *.o -Wall -o main -L "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

execute: 
	./main
	cls

clear-windows:
	del *.o
	cls

clear-linux:
	rm	-rf	*.o
	clear