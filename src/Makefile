tokenizer: tokenizer.o main.o history.o
	cc -o tokenizer tokenizer.o main.o history.o

tokenizer.o: tokenizer.h tokenizer.c

main.o: main.c tokenizer.h history.h

history.o: history.h history.c tokenizer.h

clean:
	rm -f *.o tokenizer
