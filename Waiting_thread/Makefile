CC = gcc
CFLAGS = -Wall -Wextra -pthread

SRCDIR = .

SRCS = $(SRCDIR)/main.c $(SRCDIR)/child_thread.c
OBJS = $(SRCS:.c=.o)

TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
