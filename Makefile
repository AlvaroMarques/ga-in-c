
gAlg:
	cc -c chromossome.c -o build/chromossome.o;
	cc -c population.c -o build/population.o;
	cc -c main.c -o build/main.o;
	cc -o build/geneticAlg build/chromossome.o build/population.o build/main.o;
	./build/geneticAlg
