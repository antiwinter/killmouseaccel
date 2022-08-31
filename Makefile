
all:
	gcc -Wno-deprecated-declarations -framework IOKit -framework CoreFoundation main.c
