PROD = -Ofast
DEBUG = -g
CC = g++
INCLUDES = -I./

.PHONY: all debug clean

factorize: intfact.cpp
	@${CC} ${PROD} $< -o $@ ${INCLUDES}

debug: intfact.cpp
	@${CC} ${DEBUG} $< -o factorize ${INCLUDES}

clean:
	@-rm -f ./factorize  %.out core %.core
