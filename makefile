OUT1 = .
include <win-sdk.mk>

NAME=clist

SRC=src
BIN=bin
OBJ=obj

CC=cl
LB=lib

cdebug=
cflags=
cvars=

LIBS=$(WIN_SDK_LIBS)

all: init dist dll lib

init:
  if not exist $(BIN) mkdir $(BIN)
  if not exist $(OBJ) mkdir $(OBJ)

dist:
  $(CC) /Fo$(OBJ)\ $(cdebug) $(cflags) $(cvars) $(SRC)\*.c /link $(LIBS) /OUT:$(BIN)\$(NAME).exe

dll: init
  $(CC) /Fo$(OBJ)\ /LD $(SRC)\*.c /link /OUT:$(BIN)\$(NAME).dll

lib: init dll
  $(LB) /OUT:$(BIN)\$(NAME).lib $(OBJ)\*.obj

clean:
  if exist $(BIN) rmdir /s /q $(BIN)
  if exist $(OBJ) rmdir /s /q $(OBJ)
