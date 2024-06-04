ifeq ($(OS), Windows_NT)
	OS     = Windows
	rm     = del
	suffix = exe
	ws2_32 = -lws2_32
else
	rm     = rm
	suffix = elf
endif

build: *.cc
	g++ -o client.$(suffix) *.cc \
		-I../core \
		../core/*.cc \
		../core/basic/*.cc \
		../core/controllers/*.cc \
		../core/impl_actors/*.cc \
		-IC:\include \
		-LC:\lib \
		-L../tool \
		-lpyrite -lmocutils -leasyx -D$(OS) $(ws2_32)

run: build
	./client.$(suffix)

clean:
	$(rm) *.$(suffix)