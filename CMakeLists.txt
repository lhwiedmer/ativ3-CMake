cmake_minimum_required(VERSION 3.10)
project(ExemploThreads C)

# 1. Dependência de Compilação: Buscar o pacote de Threads do sistema
find_package(Threads REQUIRED)

find_package(ZLIB REQUIRED)

# 2. Adicionar o executável
add_executable(meu_programa main.c)

# 3. Linkar a biblioteca encontrada ao nosso alvo
# Isso garante que o flag -lpthread (ou equivalente) seja adicionado

target_include_directories(meu_programa PRIVATE ${ZLIB_INCLUDE_DIRS})

target_link_libraries(meu_programa PRIVATE Threads::Threads ${ZLIB_LIBRARIES})
