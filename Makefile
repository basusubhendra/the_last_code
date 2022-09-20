PROD = -Ofast
DEBUG = -g
CC = g++
INCLUDES = -I./
LIBS = -lgmp -lm

.PHONY: all debug clean

factorize: intfact.cpp
	@${CC} ${PROD} $< -o $@ ${INCLUDES} ${LIBS}

debug: intfact.cpp
	@${CC} ${DEBUG} $< -o factorize ${INCLUDES} ${LIBS}

clean:
	@-rm -f ./factorize  %.out core %.core
