dep:
	git submodule update --init
	git submodule update --remote
	make -C core/mocutils install
	make -C core/pyrite install

ifeq ($(OS), Windows_NT)
	OS = Windows
	cp = copy
	mkdir = md
else
	cp = cp
	mkdir = mkdir
endif

.PHONY: FORCE

server: FORCE
	make -C ./server build
	$(mkdir) ./build

client: FORCE
	@echo please finish this function in project_root/Makefile
