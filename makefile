CC= g++
CCFLAGS= -g -Wall

exec: main.o Bank.o Customer.o Teller.o Manager.o makefile
	$(CC) $(CCFLAGS) -o BankSim main.o Bank.o Customer.o Teller.o Manager.o

main.o: main.C Bank.h
	$(CC) $(CCFLAGS) -c main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c Item.C

Bank.o: Bank.C Bank.h
	$(CC) $(CCFLAGS) -c Bank.C

Customer.o: Customer.C Customer.h
	$(CC) $(CCFLAGS) -c Customer.C

Teller.o: Teller.C Teller.h
	$(CC) $(CCFLAGS) -c Teller.C

Manager.o: Manager.C Manager.h
	$(CC) $(CCFLAGS) -c Manager.C

clean:
	rm -rf *.o
