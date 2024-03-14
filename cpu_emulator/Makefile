# Название проекта
PROJECT_NAME = ../build/emulator

CC = g++
CFLAGS = \
	-std=c++17 \
	-Wall      \
	-Wextra    \
	-Werror    \
	-I $(abspath ./include) \
	-I $(abspath ../stack-library) \


# Исходные файлы
INCLUDES = \
	include/utils.hpp \
	include/arch.hpp \
	include/command.hpp \
	include/parser.hpp

SOURCES = \
    src/arch.cpp \
    src/command.cpp \
    src/emulator.cpp \
    src/parser.cpp \
    src/utils.cpp

OBJECTS = $(SOURCES:src/%.cpp=../build/%.o)

default: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	@mkdir -p ../build
	$(CC) $(OBJECTS) -o ../build/$(PROJECT_NAME)

../build/%.o: src/%.cpp $(SOURCES)
	@mkdir -p ../build
	$(CC) -c $< $(CFLAGS) -o $@

# Цель для очистки проекта.
clean:
	rm -rf $(PROJECT_NAME) ../build

run: $(PROJECT_NAME)
	../build/$(PROJECT_NAME) $(PROGRAM_FILE)
