os = $(shell uname)
ifeq (os, Linux)
	rm     = rm
	suffix = elf
else
	os     = Windows
	rm     = del
	suffix = exe
endif

build: *.cc
	g++ -o server.$(suffix) *.cc \
		-I../core \
		../core/*.cc \
		-IC:\include \
		-LC:\lib \
		-lpyrite -lmocutils

run: build
	./server.$(suffix)

clean:
	$(rm) *.$(suffix)