# Название проекта
PROJECT_NAME = DEMONSTRATION

CC = g++
CFLAGS = \
	-std=c++17 \
	-Wall      \
	-Wextra    \
	-Werror

# Исходные файлы
SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=build/%.o)

# Цель для сборки проекта.
$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o ./build/$(PROJECT_NAME)

# Цель для очистки проекта.
clean:
	rm -rf $(PROJECT_NAME) build

build/%.o: %.cpp $(SOURCES)
	@mkdir -p ./build
	$(CC) -c $< $(CFLAGS) -o $@

run: $(PROJECT_NAME)
	build/$(PROJECT_NAME)
