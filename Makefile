COMPILER = g++
OPTIONS = -std=c++20
COMPILE =  $(COMPILER) $(OPTIONS)



app:
	$(COMPILE) -std=c++20 src/*.cpp -o app -I/include -Iinclude/headers -Llib -lmingw32 -lSDL2main -lSDL2