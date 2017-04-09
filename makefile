ex:apue-3-1 apue-3-3 apue-5-1 apue-5-2 apue-5-5 apue-7-1 apue-7-3 apue-8-1 
apue-3-1:apue-3-1.c
	gcc -Wall -g $<	-o $@ -I.
apue-3-3:apue-3-3.c
	gcc -Wall -g $<	-o $@ -I.
apue-5-1:apue-5-1.c
	gcc -Wall -g $<	-o $@ -I.
apue-5-2:apue-5-2.c
	gcc -Wall -g $<	-o $@ -I.
apue-5-5:apue-5-5.c
	gcc -Wall -g $<	-o $@ -I.
apue-7-1:apue-7-1.c
	gcc -Wall -g $<	-o $@ -I.
apue-7-3:apue-7-3.c
	gcc -Wall -g $<	-o $@ -I.
apue-8-1:apue-8-1.c
	gcc -Wall -g $<	-o $@ -I.
clean:
	rm -f apue-3-1 apue-3-3 apue-5-1 apue-5-2 apue-5-5 apue-7-1 apue-7-3  apue-8-1 
