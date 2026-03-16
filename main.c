#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <zlib.h>

void* tarefa_thread(void* arg) {
    char* nome = (char*)arg;
    for (int i = 0; i < 3; i++) {
        printf("[Thread %s] Executando passo %d...\n", nome, i + 1);
        sleep(1);
    }
    return NULL;
}

int main() {

    pthread_t t1, t2;

    printf("Versão da Zlib em uso: %s\n", zlibVersion());


    pthread_create(&t1, NULL, tarefa_thread, "A");
    pthread_create(&t2, NULL, tarefa_thread, "B");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Projeto finalizado com sucesso.\n");
    return 0;
}
