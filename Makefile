# 编译器
CC = gcc


# 编译参数
CFLAGS = -Wall -g


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


# 自动生成.o文件

OBJS = $(SRCS:.c=.o)



# 默认目标

all: $(TARGET)



# 链接

$(TARGET): $(OBJS)

	$(CC) $(OBJS) -o $(TARGET)



# 编译.c文件

%.o: %.c

	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@



# 清理

clean:

	rm -f $(OBJS) $(TARGET)
