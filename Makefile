encoder : encoder.c
	gcc -o encoder encoder.c

.PHONY: clean 

clean: 
	rm -f *.o encoder