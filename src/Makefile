CC?=gcc
CFLAGS=-g -Wall -O3
TARGET?=test

$(TARGET):test.o hash_table.o linked_list.o
	$(CC)  $(CFLAGS) $^ -o $@
test.o:test.c hash_table.o linked_list.o
	$(CC) $(CFLAGS) -c $^
hash_talbe.o:hash_table.c linked_list.o
	$(CC) $(CFLAGS) -c $^
linked_list.o:linked_list.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(TARGET)
