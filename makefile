CFLAGS := -lglfw -lglad -ggdb3
OUT := p

lesson1: lesson-1.c
	cc $? -o ${OUT} ${CFLAGS}