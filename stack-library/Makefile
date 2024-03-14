# Название проекта
PROJECT_NAME = LOGGER_CLASS

CC = g++
CFLAGS = \
	-std=c++17 \
	-Wall      \
	-Wextra    \
	-Werror

# Исходные файлы
INCLUDES = Stack.hpp

SOURCES = logger_class.cpp

OBJECTS = $(SOURCES:%.cpp=../build/%.o)

default: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	@mkdir -p ../build
	$(CC) $(OBJECTS) -o ../build/$(PROJECT_NAME)

../build/%.o: %.cpp $(SOURCES)
	@mkdir -p ../build
	$(CC) -c $< $(CFLAGS) -o $@

# Цель для очистки проекта.
clean:
	rm -rf $(PROJECT_NAME) ../build

run: $(PROJECT_NAME)
	../build/$(PROJECT_NAME)
