all: compile link execute

compile:
	g++ -c include/Entidades/Personagens/*.h include/Entidades/Obstaculos/*.h include/Entidades/*.h include/Fases/*.h include/Gerenciador/*.h include/Listas/*.h include/*.h -I Biblioteca\include
	g++ -c src/Entidades/Personagens/*.cpp src/Entidades/Obstaculos/*.cpp src/Entidades/*.cpp src/Fases/*.cpp src/Gerenciador/*.cpp src/Lista/*.cpp src/*.cpp -I Biblioteca\include

link:
	g++ *.o -Wall -o main -L Biblioteca\lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

execute: 
	./main
	cls

clear-windows:
	del *.o
	cls

clear-linux:
	rm -rf *.o
	clear