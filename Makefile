dep:
	git submodule update --init
	git submodule update --remote
	make -C core/mocutils install
	make -C core/pyrite install
