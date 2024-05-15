program: derle calistir


derle:
	g++ -I ./include/ -o ./lib/KonsoldaGoster.o -c ./src/KonsoldaGoster.cpp
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/DosyaYazdir.o -c ./src/DosyaYazdir.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiDugum.o -c ./src/SatirListesiDugum.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiDugum.o -c ./src/YoneticiDugum.cpp

	g++ -I ./include/ -o ./bin/main ./lib/KonsoldaGoster.o ./lib/Exception.o ./lib/DosyaYazdir.o ./lib/SatirListesi.o ./lib/SatirListesiDugum.o ./lib/YoneticiListesi.o  ./lib/YoneticiDugum.o   ./src/main.cpp

calistir:
	./bin/main