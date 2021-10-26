TARGET=mem_alloc

CFLAGS = -g -O2 -std=c99

all: image

$(TARGET): mem_alloc.c
	gcc $^ -o $@ $(CFLAGS)

image: $(TARGET)
	docker build -t $(TARGET):v1 .

clean:
	$(RM) $(TARGET)
	docker stop $(TARGET)
	docker rm $(TARGET)
	docker rmi $(TARGET):v1