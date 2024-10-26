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

_OBJ_PARSER	= token.o parse_state.o parser.o 
_OBJ_INTR		= node.o interpreter.o
_OBJ_TYPES	= type.o expression.o integer_t.o float_t.o
_OBJ_OPTRS	= operator.o add_op.o

_OBJ	= util.o $(_OBJ_PARSER) $(_OBJ_INTR) $(_OBJ_TYPES) $(_OBJ_OPTRS) main.o 
OBJ	= $(patsubst %,$(ODIR)/%,$(_OBJ))

OFILE	= pycro

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
