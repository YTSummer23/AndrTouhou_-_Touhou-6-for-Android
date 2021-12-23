TARGET = main

.PHONY: all clean installLibs debug

all: target

clean:
	rm -rf $(TARGET)

target: 
	echo "compiling and assembling sources"
	g++ -c $(TARGET).cpp
	echo "linking sources"
	g++ $(TARGET).o -o $(TARGET) -pthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
	rm $(TARGET).o

debug:
	echo "compiling and assembling sources"
	g++ -c $(TARGET).cpp -g -DDEBUG -I$(SFML_PATH)/include
	echo "linking sources"
	g++ $(TARGET).o -g -o $(TARGET) -L$(SFML_PATH)/lib -pthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
	rm $(TARGET).o

installLibs: #need for nothing, if you installed SFML in a standard path. Anyway, it is useless, since you should write this in console yourself
	export LD_LIBRARY_PATH=$(SFML_PATH)/lib:$(LD_LIBRARY_PATH)
