#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Función que ejecutará el hilo (imprime del 10,000 al 1)
void* tarea_hilo(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo -> %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo;
    int resultado;

    // Crear el hilo secundario
    resultado = pthread_create(&hilo, NULL, tarea_hilo, NULL);
    if (resultado != 0) {
        perror("Error al crear el hilo");
        exit(EXIT_FAILURE);
    }

    // Proceso principal (imprime del 1 al 10,000)
    for (int i = 1; i <= 10000; i++) {
        printf("Principal -> %d\n", i);
    }

    // Esperar a que el hilo termine su ejecución antes de cerrar el programa
    pthread_join(hilo, NULL);

    printf("\n--- Programa finalizado correctamente ---\n");
    return 0;
}