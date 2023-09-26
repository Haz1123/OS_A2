
##
 # startup code provided by Paul Miller for COSC1114 - Operating Systems
 # Principles
 ##

# provide make targets here to build the two programs 

all: clear_executable fifo sjf rr clean

*.o: *.cpp
	g++ -Wall -Werror -std=c++2a -pedantic -g -c *.cpp

fifo:
	g++ -Wall -Werror -std=c++2a -pedantic -g -o ./fifo ./src/drivers/fifo_main.cpp ./src/common/*.cpp

sjf:
	g++ -Wall -Werror -std=c++2a -pedantic -g -o ./sjf ./src/drivers/sjf_main.cpp ./src/common/*.cpp

rr:
	g++ -Wall -Werror -std=c++2a -pedantic -g -o ./rr ./src/drivers/rr_main.cpp ./src/common/*.cpp


clean:
	rm -rf *.o

clear_executable:
	rm -f fifo
	rm -f sjf
	rm -f rr

run_experiment:
	for number in 1 2 3 4 5 6 7 8 9 0; do \
		./fifo ./datafiles/datafile_$$number > ./results/fifo_$$number; \
	done
	for number in 1 2 3 4 5 6 7 8 9 0; do \
		./rr 25 ./datafiles/datafile_$$number > ./results/rr_$$number; \
	done
	for number in 1 2 3 4 5 6 7 8 9 0; do \
		./sjf ./datafiles/datafile_$$number > ./results/sjf_$$number; \
	done