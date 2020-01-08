OUT1 = .
include <win-sdk.mk>

SRC=src
BIN=bin
OUT=clist.exe
OBJ=obj

CC=cl
cdebug=
cflags=
cvars=
LIBS=$(WIN_SDK_LIBS)

all: init dist

init:
  if not exist $(BIN) mkdir $(BIN)
  if not exist $(OBJ) mkdir $(OBJ)

dist:
  $(CC) /Fo$(OBJ)\ $(cdebug) $(cflags) $(cvars) $(SRC)\*.c /link $(LIBS) /OUT:$(BIN)\$(OUT)

clean:
  if exist $(BIN) rmdir /s /q $(BIN)
  if exist $(OBJ) rmdir /s /q $(OBJ)
