OBJS= main.o myscreen.o myform.o myfile.o mylist.o user.o line.o mymenu.o mymenubar.o
LIBS= -Lwlib -lmywin -lcurses
CFLAGS= -Iwlib -g
CC=g++
TARGET=app
.cpp.o: 
	$(CC) $(CFLAGS) -c $<
$(TARGET): $(OBJS) wlib/libmywin.a
	(cd wlib; make)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
clean:
	rm -f $(OBJS) $(TARGET)
