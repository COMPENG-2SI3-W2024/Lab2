CC = g++
CFLAGS = -I. -I../inc -g
OBJ = objPos.o objPosArrayList.o objPosDLinkedList.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o 
DEPS = *.h
#POSTLINKER = -lncurses   ## uncomment this if on Linux
EXEC = Project

%.o: %.cpp $(DEPENDS)
	$(CC) -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) ${POSTLINKER}

clean :
	rm -rf ${OBJ} ${EXEC} ${EXEC}.exe

