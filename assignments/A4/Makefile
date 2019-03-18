
COMPILER = g++
C_FLAGS = -Wall -std=c++11 -g

all: test

test: test.o OutBitStream.o InBitStream.o HuffNode.o FrequencyCounter.o PriorityQueue.o QNode.o HuffmanTree.o TreeNode.o
	${COMPILER} ${C_FLAGS} -o t.out test.o OutBitStream.o InBitStream.o HuffNode.o FrequencyCounter.o PriorityQueue.o QNode.o HuffmanTree.o TreeNode.o

test.o:
	${COMPILER} ${C_FLAGS} -c test.cpp
 
OutBitStream.o: OutBitStream.h OutBitStream.cpp
	${COMPILER} ${C_FLAGS} -c OutBitStream.cpp

InBitStream.o: InBitStream.h InBitStream.cpp
	${COMPILER} ${C_FLAGS} -c InBitStream.cpp

HuffNode.o: HuffNode.h HuffNode.cpp
	${COMPILER} ${C_FLAGS} -c HuffNode.cpp

QNode.o: QNode.h QNode.cpp
	${COMPILER} ${C_FLAGS} -c QNode.cpp

FrequencyCounter.o: FrequencyCounter.h FrequencyCounter.cpp
	${COMPILER} ${C_FLAGS} -c FrequencyCounter.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	${COMPILER} ${C_FLAGS} -c PriorityQueue.cpp

HuffmanTree.o: HuffmanTree.h HuffmanTree.cpp
	${COMPILER} ${C_FLAGS} -c HuffmanTree.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	${COMPILER} ${C_FLAGS} -c TreeNode.cpp

clean:
	rm -f sim *.o
	rm -f ./t.out

dev: 
	make
	./t.out