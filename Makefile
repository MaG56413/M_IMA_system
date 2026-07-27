# 编译器
CC = gcc


# 编译参数
CFLAGS = -Wall -g -O0 -no-pie


# 目标文件
TARGET = main


# 头文件路径
INCLUDES = \
-I./cpu \
-I./exception \
-I./fault \
-I./map \
-I./wcet


# 源文件

SRCS = \
main.c \
cpu/cpu_context.c \
exception/exception.c \
fault/fault.c \
fault/fault_record.c \
map/function_map.c \
wcet/wcet.c

OBJS = $(SRCS:.c=.o)



all: $(TARGET)



$(TARGET): $(OBJS)

	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c

	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@



clean:

	rm -f $(OBJS) $(TARGET)
