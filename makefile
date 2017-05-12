LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: thegame

#compile utils
utils.o: utils/utils.cpp
	g++ -c "utils/utils.cpp" -o utils.o 
#compile debug
sfDebug.o: debug/sfDebug.cpp
	g++ -c "debug/sfDebug.cpp" -o sfDebug.o

#compile all states 
gameState.o: gameState.cpp
	g++ -c "gameState.cpp" -o gameState.o 

gameOverState.o: states/gameOverState.cpp
	g++ -c "states/gameOverState.cpp" -o gameOverState.o

loaderState.o: states/loaderState.cpp
	g++ -c "states/loaderState.cpp" -o loaderState.o

menuState.o: states/menuState.cpp
	g++ -c "states/menuState.cpp" -o menuState.o

playState.o: states/playState.cpp
	g++ -c "states/playState.cpp" -o playState.o
        
testState.o: states/testState.cpp
	g++ -c "states/testState.cpp" -o testState.o        

#compile managers 
gameManager.o: gameManager.cpp
	g++ -c "gameManager.cpp" -o gameManager.o 

#compile main 
main.o: main.cpp
	g++ -c "main.cpp" -o main.o
#create executable

thegame: utils.o sfDebug.o gameState.o gameOverState.o loaderState.o menuState.o playState.o testState.o gameManager.o main.o
	@echo "** Building the game"
	g++ -o thegame main.o utils.o sfDebug.o gameState.o gameOverState.o loaderState.o menuState.o playState.o testState.o gameManager.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame *.o

install:
	@echo '** Installing...'
	cp thegame /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/thegame