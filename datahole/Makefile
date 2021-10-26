TARGET=datahole

CFLAGS = -g -O2 -std=c99

$(TARGET): $(TARGET).c
	gcc $^ -o $@ $(CFLAGS)

clean:
	$(RM) $(TARGET) file.hole
