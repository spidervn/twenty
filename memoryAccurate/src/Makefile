TARGET=memory_accu
CC=g++
CPPFLAGS=
LDFLAGS=-lcurses -lform -lpanel
# LIBS=

OBJS=memaccu_ui.o memaccu.o
SRC=.memaccu_ui.cpp memaccu.cpp
INCLUDES=

$(TARGET): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ): $(SRC) $(INCLUDES)
	$(CC) $(CPPFLAGS) -c $(@:.o=.cpp) $(LDFLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)
