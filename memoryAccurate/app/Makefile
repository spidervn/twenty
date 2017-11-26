TARGET=app
CC=g++
CFLAGS=-Wall -I/usr/include/GL -fpermissive
LDFLAGS=-lcurses -lmenu -lpanel -lform
# LIBS=

OBJS=main.o
SRC=main.cpp
INCLUDES=

caro3d: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(@:.o=.cpp) $(LDFLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)