all: main.o GerenciadorGrafico.o
	g++ main.o GerenciadorGrafico.o -o main -L "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

main.o: src\main.cpp
	g++ -c src\main.cpp -I "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\include"

GerenciadorGrafico.o: src\Gerenciador\GerenciadorGrafico.cpp
	g++ -c src\Gerenciador\GerenciadorGrafico.cpp -I "C:\Users\samsu\OneDrive\Documentos\SFML-2.6.1\include"

clean:
	rm	-f	*.o	main