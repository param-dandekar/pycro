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

_OBJ_PARSER	= 
_OBJ_INTR		= token.o
_OBJ_TYPES	= object.o expression.o type.o integer_t.o
_OBJ_OPTRS	= 

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
