CFLAGS = -fPIC  -mavx2 -mfma

# -mavx
# -mavx2
# -mfma

CXXFLAGS='-fPIC'

CC = gcc
SRC_DIR = src

INC_DIR = include
SRC_DIR = src
OUTPUT_DIR = build

INC = $(foreach dir,$(INC_DIR),$(wildcard $(dir)/*.c))
SRC = $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OUTPUT_DIR)/%.o)

all: CREATE_TARGET_DIRS hello_avx fmatest

# 通过gcc link 从汇编文件生成可执行文件
hello_avx: $(OUTPUT_DIR)/hello_avx.o
	$(CC) -o $(OUTPUT_DIR)/$@ $< 

fmatest: $(OUTPUT_DIR)/fmatest.o
	$(CC) -o $(OUTPUT_DIR)/$@ $< 

# 从源代码生成汇编文件
$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

CREATE_TARGET_DIRS:
	mkdir -p $(OUTPUT_DIR)

.PHONY : clean
clean:
	rm -rf $(OUTPUT_DIR)
