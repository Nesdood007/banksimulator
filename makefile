CC= g++
CCFLAGS= -g -Wall

exec: main.o Bank.o makefile
	$(CC) $(CCFLAGS) -o PQTest main.o PQ.o

main.o: main.C Bank.h
	$(CC) $(CCFLAGS) -c main.C

Bank.o: Bank.C Bank.h
	$(CC) $(CCFLAGS) -c PQ.C

Customer.o: Customer.C Customer.h
	$(CC) $(CCFLAGS) -c Customer.h

Teller.o: Teller.C Teller.h
	$(CC) $(CCFLAGS) -c Teller.h

clean:
	rm -rf *.o
