ex:apue-3-1 apue-3-3 apue-5-1
apue-3-1:apue-3-1.c
	gcc -Wall -g $<	-o $@ -I.
apue-3-3:apue-3-3.c
	gcc -Wall -g $<	-o $@ -I.
apue-5-1:apue-5-1.c
	gcc -Wall -g $<	-o $@ -I.
clean:
	rm -f apue-3-1 apue-3-3 apue-5-1 
