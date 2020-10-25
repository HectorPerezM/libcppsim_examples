CXX=g++

LIBCPPSIM= ../libcppsim-0.2.5/src/libcppsim.a
LIBCPPSIM_HEADERS= ../libccpsim-0.2.5/src/

CFLAGS=-g -Wall -Wno-deprecated  -I$(LIBCPPSIM_HEADERS)
EXEC=sim

BIN = bin
OBJ = obj

OBJS= obj/main.o obj/util.o obj/processor.o obj/taskGenerator.o obj/task.o obj/monitor.o obj/log.o

all: main

main: clean $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) $(LIBCPPSIM) -o $(BIN)/$(EXEC)

obj/main.o: src/main.cpp
	$(CXX) -c -o $(OBJ)/main.o src/main.cpp $(CFLAGS)


obj/log.o: src/log/log.cpp
	$(CXX) -c -o $(OBJ)/log.o src/log/log.cpp $(CFLAGS)

obj/monitor.o: src/monitor/monitor.cpp
	$(CXX) -c -o $(OBJ)/monitor.o src/monitor/monitor.cpp $(CFLAGS)

obj/task.o: src/task/task.cpp
	$(CXX) -c -o $(OBJ)/task.o src/task/task.cpp 

obj/taskGenerator.o: src/taskGenerator/taskGenerator.cpp
	$(CXX) -c -o $(OBJ)/taskGenerator.o src/taskGenerator/taskGenerator.cpp $(CFLAGS)

obj/processor.o: src/processor/processor.cpp
	$(CXX) -c -o $(OBJ)/processor.o src/processor/processor.cpp $(CFLAGS)

obj/util.o: src/util/util.cpp src/util/util.hpp
	$(CXX) -c -o $(OBJ)/util.o  src/util/util.cpp -Wno-deprecated -Wall

clean:
	rm -r -f $(BIN)/$(NAME) && \
	rm -r -f $(OBJ)/ && \
	mkdir -p $(BIN) && \
	mkdir -p $(OBJ)
