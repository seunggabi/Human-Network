OBJS=controller.o view.o screen.o container.o editbox.o checkbox.o button.o console.o string.o component.o box.o button.o console.o dialog.o label.o radio.o radiogroup.o changebox.o textarea.o menubar.o menu.o menuitem.o
LIBS= -lcurses
CFLAGS= -g
CC=g++
TARGET=libmywin.a
.cpp.o: 
	$(CC) $(CFLAGS) -c $<
$(TARGET): $(OBJS)
	ar -r $(TARGET) $(OBJS)
clean:
	rm -f $(OBJS) $(TARGET)
