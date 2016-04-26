CC= g++
CCFLAGS= -g -Wall

exec: main.o bank.o customer.o teller.o manager.o makefile
	$(CC) $(CCFLAGS) -o BankSim main.o bank.o customer.o teller.o manager.o

main.o: main.C bank.h
	$(CC) $(CCFLAGS) -c main.C

Item.o: Item.h
	$(CC) $(CCFLAGS) -c

bank.o: bank.C bank.h
	$(CC) $(CCFLAGS) -c bank.C

customer.o: customer.C customer.h
	$(CC) $(CCFLAGS) -c customer.C

teller.o: teller.C teller.h
	$(CC) $(CCFLAGS) -c teller.C

manager.o: manager.C manager.h
	$(CC) $(CCFLAGS) -c manager.C

clean:
	rm -rf *.o
