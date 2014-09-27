#oe makefile
CC			= clang
CPP			= clang++
CFLAGS		= -g3 \
			  -Wall \
			  -Wno-write-strings
CPPFLAGS	= -g3 \
			  -Wall \
			  -Wno-write-strings
SLIBS		= 
DLIBS		= 

OUT			= pcat
OBJ_DIR		= obj
INC_DIRS	= 
A_DIR		= lib
BIN_DIR		= bin

#object lists
C_SOURCES	= 
CPP_SOURCES	= main.cpp \
			  bit_ops.cpp

OBJS		:= $(patsubst %, $(OBJ_DIR)/%, $(C_SOURCES:%.c=%.o))
OBJS		+= $(patsubst %, $(OBJ_DIR)/%, $(CPP_SOURCES:%.cpp=%.o))
OBJS		+= $(patsubst %, $(A_DIR)/%, $(SLIBS))
BINS		:= $(patsubst %, $(BIN_DIR)/%, $(OUT))


all: $(OBJS) BIN

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/$(OUT)

#make the c files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(foreach d, $(INC_DIRS), -I $d) -c -o $@ $<

#make the cpp files
$(OBJ_DIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(foreach d, $(INC_DIRS), -I $d) -c -o $@ $<

BIN:
	$(CPP) $(CFLAGS) $(OBJS) $(foreach d, $(INC_DIRS), -I $d) $(foreach l, $(DLIBS), -l $l) -o $(BINS)


