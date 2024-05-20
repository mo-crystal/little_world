os = $(shell uname)
ifeq (os, Linux)
	rm     = rm
	suffix = elf
else
	os     = Windows
	rm     = del
	suffix = exe
endif

update:
	git submodule update --init
	git submodule update --remote
	make -C ../core/mocutils copy
	make -C ../core/pyrite copy

build: *.cc
	g++ -o server.$(suffix) *.cc \
		../core/*.cc \
		-I../core

run: build
	./server.$(suffix)

clean:
	$(rm) *.$(suffix)