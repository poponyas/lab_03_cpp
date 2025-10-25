FROM gcc:12.2.0

# Установка системных зависимостей
RUN apt-get update && apt-get install -y \
    cmake \
    git \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Установка Google Test
RUN apt-get update && apt-get install -y \
    libgtest-dev \
    && cd /usr/src/gtest \
    && cmake CMakeLists.txt \
    && make \
    && cp lib/*.a /usr/lib \
    && rm -rf /usr/src/gtest

# Создание рабочей директории
WORKDIR /workspace/lab03

# Копирование файлов проекта
COPY . .

# Настройка прав доступа
RUN chmod -R 755 /workspace/lab03

# Установка стандарта C++17 по умолчанию
ENV CXXFLAGS="-std=c++17 -Wall -Wextra -Wpedantic"

CMD ["/bin/bash"]