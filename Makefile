TARGET := main
SRC_DIR := src
SRC := menu.cpp enemyEngine.cpp SFMLgraph.cpp gameEngine.cpp levelEngine.cpp playerEngine.cpp globals.cpp
OBJ := $(SRC:%.cpp=%.o)
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
CXXFLAGS = -pthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

.PHONY: all clean install uninstall debug print


all: $(TARGET)

clean:
	rm -rf *.o

$(OBJ): $(SRC)
	clang++ -c $(TARGET).cpp $(SRC) -Iinclude/

print:
	echo $(SRC)
	echo $(OBJ)

$(TARGET): $(OBJ)
	echo "compiling and assembling sources"
	clang++ $(TARGET).o $(OBJ) -o $(TARGET) $(CXXFLAGS)
	echo "linking sources"

debug:
	echo "compiling and assembling sources"
	g++ -c $(TARGET).cpp -g -DDEBUG -I$(SFML_PATH)/include
	echo "linking sources"
	g++ $(TARGET).o -g -o $(TARGET) -L$(SFML_PATH)/lib -pthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
	rm $(TARGET).o

installLibs:
	export LD_LIBRARY_PATH=$(SFML_PATH)/lib:$(LD_LIBRARY_PATH)
