IDIR		= ./include
CC			= g++
CFLAGS	= -I$(IDIR)
CPPFLAGS = -Wall

SRC_FILE = ./src

ODIR	= ./obj
LDIR 	= ./lib

LIBS	= -lm

_DEPS	= 
DEPS	= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ	= util.o lexer.o token.o node.o numeric.o expression.o integer_t.o float_t.o operator.o add_op.o main.o 
OBJ	= $(patsubst %,$(ODIR)/%,$(_OBJ))

OFILE	= result

default: all

all: $(OBJ) result

.PHONY: clean debug

debug: CFLAGS += -DDEBUG -g
debug: all

debug-run: debug
	gdb $(OFILE)

$(ODIR)/%.o: $(SRC_FILE)/%.cpp $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ $< $(CFLAGS)

result: $(OBJ)
	$(CC) $(CPPFLAGS) -o $(OFILE) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OFILE) $(ODIR)/*.o
