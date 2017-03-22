SRCS = h1.c h2.c
OBJS = $(SRCS:.c=.o)
OBJS = h1.o h2.o

all: link
	./a.out

link: $(OBJS)
	gcc $(OBJS)

clean:
	rm *.o *.out *.a

