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

_OBJ_UTIL 	= color.o util.o
_OBJ_INTR		= lexer.o parser.o interpreter.o
_OBJ_OBJS		= token.o object.o expression.o
_OBJ_TYPES	= type.o integer_t.o float_t.o boolean_t.o string_t.o null_t.o
_OBJ_OPTRS	= 

_OBJ	= $(_OBJ_UTIL) $(_OBJ_INTR) $(_OBJ_OBJS) $(_OBJ_TYPES) $(_OBJ_OPTRS) main.o 
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
