TARGET = main
OBJF = main.o lcd.o gpio.o
CFLAGS = -g -Wall
LIBS = -lm
CC = gcc

all: $(TARGET)

$(TARGET): $(OBJF)
	$(CC) -o $(TARGET) $(OBJF) $(LIBS)

clean:
	rm -f $(OBJF)
