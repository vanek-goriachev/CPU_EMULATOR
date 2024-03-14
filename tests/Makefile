# Название проекта
PROJECT_NAME = TESTS

CC = g++
CFLAGS = \
	-std=c++17 \
	-Wall      \
	-Wextra    \
	-Werror    \
	-I googletest/googletest/include \
	-I ../stack-library

# Исходные файлы
SOURCES = \
	1-constructors.cpp \
	2-methods.cpp \
	3-expand.cpp \
	4-user-data-type.cpp \
	5-emplace.cpp
OBJECTS = $(SOURCES:%.cpp=../build/%.o)

# Цель для сборки проекта.
$(PROJECT_NAME): $(OBJECTS) gtest
	@mkdir -p ../build
	$(CC) $(OBJECTS) -Lgoogletest/build/lib -lgtest -lgtest_main -pthread -o ../build/$(PROJECT_NAME)

gtest:
	cd googletest && mkdir -p build && cd build && cmake .. && make

# Цель для очистки проекта.
clean:
	rm -rf $(PROJECT_NAME) ../build

../build/%.o: %.cpp $(SOURCES)
	@mkdir -p ../build
	$(CC) -c $< $(CFLAGS) -o $@

test: $(PROJECT_NAME)
	../build/$(PROJECT_NAME)


