CFLAGS=`pkg-config --cflags gtk+-3.0` -g
LDFLAGS=`pkg-config --libs gtk+-3.0` -lm -lX11 -g
BIN=ldesk
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

$(BIN): $(OBJS)
	gcc -o $(BIN) $(OBJS) $(LDFLAGS)

%.o: %.c %.h

clean:
	rm -f $(BIN) $(OBJS)
