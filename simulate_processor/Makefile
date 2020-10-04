CXX=g++

LIBCPPSIM= ../libcppsim-0.2.5/src/libcppsim.a
LIBCPPSIM_HEADERS= ../libccpsim-0.2.5/src/

CFLAGS=-g -Wall -Wno-deprecated  -I$(LIBCPPSIM_HEADERS)
EXEC=sim

BIN = bin
OBJ = obj

OBJS= obj/main.o obj/util.o

all: main

main: clean $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) $(LIBCPPSIM) -o $(BIN)/$(EXEC)

obj/main.o: src/main.cpp
	$(CXX) -c -o $(OBJ)/main.o src/main.cpp $(CFLAGS)

obj/processor.o: 

obj/util.o: src/util/util.cpp src/util/util.hpp
	$(CXX) -c -o $(OBJ)/util.o  src/util/util.cpp -Wno-deprecated -Wall

clean:
	rm -r -f $(BIN)/$(NAME) && \
	rm -r -f $(OBJ)/ && \
	mkdir -p $(BIN) && \
	mkdir -p $(OBJ)
