SRC=src
BIN=bin
OUT=clist.exe
OBJ=obj

CC=cl
cdebug=
cflags=
cvars=
LIBS="D:\Program Files (x86)\Windows Kits\10\Lib\10.0.14393.0\um\x86\User32.Lib"  \
     "D:\Program Files (x86)\Windows Kits\10\Lib\10.0.14393.0\um\x86\Gdi32.Lib"

all: init dist

init:
  if not exist $(BIN) mkdir $(BIN)
  if not exist $(OBJ) mkdir $(OBJ)

dist:
  $(CC) /Fo$(OBJ)\ $(cdebug) $(cflags) $(cvars) $(SRC)\*.c /link $(LIBS) /OUT:$(BIN)\$(OUT)

clean:
  if exist $(BIN) rmdir /s /q $(BIN)
  if exist $(OBJ) rmdir /s /q $(OBJ)
