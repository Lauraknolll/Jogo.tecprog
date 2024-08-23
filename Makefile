all: compile link

compile:
	g++ -IBiblioteca/include -c include/*.h 
	g++ -IBiblioteca/include -c include/Listas/*.h 
	g++ -IBiblioteca/include -c include/Gerenciador/*.h
	g++ -IBiblioteca/include -c include/Entidades/*.h  
	g++ -IBiblioteca/include -c include/Entidades/Obstaculos/*.h 
	g++ -IBiblioteca/include -c include/Entidades/Personagens/*.h 
	
	 

	g++ -IBiblioteca/include -c src/*.cpp
	g++ -IBiblioteca/include -c src/Lista/*.cpp
	g++ -IBiblioteca/include -c src/Gerenciador/*.cpp
	g++ -IBiblioteca/include -c src/Entidades/*.cpp 
	g++ -IBiblioteca/include -c src/Entidades/Obstaculos/*.cpp
	g++ -IBiblioteca/include -c src/Entidades/Personagens/*.cpp
	
link:
	g++ *.o -o main -LBiblioteca/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio