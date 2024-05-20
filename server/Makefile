os = $(shell uname)
ifeq (os, Linux)
	rm     = rm
	suffix = elf
else
	os     = Windows
	rm     = del
	suffix = exe
endif

dep:
	git submodule update --init
	git submodule update --remote
	make -C ../core/mocutils install
	make -C ../core/pyrite install

build: *.cc
	g++ -o server.$(suffix) *.cc \
		../core/*.cc \
		-I../core \
		-lpyrite -lmocutils

run: build
	./server.$(suffix)

clean:
	$(rm) *.$(suffix)