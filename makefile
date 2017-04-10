ex:apue-3-1 apue-3-3 apue-5-1 apue-5-2 apue-5-5 apue-7-1 apue-7-3 apue-8-1 apue-10-1 apue-10-7 apue-10-8 apue-11-1 apue-11-2 apue-11-3 apue-11-4 
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
apue-10-1:apue-10-1.c
	gcc -Wall -g $<	-o $@ -I.
apue-10-7:apue-10-7.c
	gcc -Wall -g $<	-o $@ -I.
apue-10-8:apue-10-8.c
	gcc -Wall -g $<	-o $@ -I.
apue-11-1:apue-11-1.c
	gcc -Wall -g $<	-o $@ -I. -pthread
apue-11-2:apue-11-2.c
	gcc -Wall -g $< -o $@ -I. -pthread
apue-11-3:apue-11-3.c
	gcc -Wall -g $< -o $@ -I. -pthread
apue-11-4:apue-11-4.c
	gcc -Wall -g $< -o $@ -I. -pthread
clean:
	rm -f apue-3-1 apue-3-3 apue-5-1 apue-5-2 apue-5-5 apue-7-1 apue-7-3  apue-8-1 apue-10-1 apue-10-7 apue-10-8 apue-11-1 apue-11-2 apue-11-3 apue-11-4  
