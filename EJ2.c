#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *nombre;
    char *apellido;
    uint8_t edad;
    uint32_t codigo;
    float *califs;
    size_t n_califs;
} Alumno;

char* copiar_texto(const char* s) {
    char* p = malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

Alumno* crear_alumno(const char* nombre, const char* apellido, uint8_t edad, uint32_t codigo, float* califs, size_t n_califs) {
    Alumno* a = malloc(sizeof(Alumno));
    a->nombre = copiar_texto(nombre);
    a->apellido = copiar_texto(apellido);
    a->edad = edad;
    a->codigo = codigo;
    a->n_califs = n_califs;
    a->califs = malloc(n_califs * sizeof(float));
    for (size_t i = 0; i < n_califs; i++) a->califs[i] = califs[i];
    return a;
}

void liberar_alumno(Alumno* a) {
    free(a->nombre);
    free(a->apellido);
    free(a->califs);
    free(a);
}

typedef struct {
    Alumno** items;
    size_t usados;
    size_t capacidad;
    size_t huecos;
} Lista;

void lista_init(Lista* l) {
    l->items = NULL;
    l->usados = l->capacidad = l->huecos = 0;
}

void lista_agregar(Lista* l, Alumno* a) {
    if (l->usados == l->capacidad) {
        l->capacidad = l->capacidad ? l->capacidad * 2 : 4;
        l->items = realloc(l->items, l->capacidad * sizeof(Alumno*));
    }
    l->items[l->usados++] = a;
}

void lista_eliminar(Lista* l, uint32_t codigo) {
    for (size_t i = 0; i < l->usados; i++) {
        if (l->items[i] && l->items[i]->codigo == codigo) {
            liberar_alumno(l->items[i]);
            l->items[i] = NULL;
            l->huecos++;
            while (l->usados > 0 && l->items[l->usados - 1] == NULL) {
                l->usados--;
                l->huecos--;
            }
            return;
        }
    }
}

void lista_compactar(Lista* l) {
    size_t j = 0;
    for (size_t i = 0; i < l->usados; i++) {
        if (l->items[i]) {
            l->items[j++] = l->items[i];
        }
    }
    l->usados = j;
    l->huecos = 0;
    Alumno** tmp = realloc(l->items, l->usados * sizeof(Alumno*));
    if (tmp) {
        l->items = tmp;
        l->capacidad = l->usados;
    }
}

void lista_liberar(Lista* l) {
    for (size_t i = 0; i < l->usados; i++) {
        if (l->items[i]) liberar_alumno(l->items[i]);
    }
    free(l->items);
}

void mostrar_lista(Lista* l) {
    for (size_t i = 0; i < l->usados; i++) {
        Alumno* a = l->items[i];
        if (!a) continue;
        printf("ID:%u %s %s, edad:%u califs:", a->codigo, a->nombre, a->apellido, a->edad);
        for (size_t j = 0; j < a->n_califs; j++) {
            printf(" %.1f", a->califs[j]);
        }
        printf("\n");
    }
}

int main() {
    Lista lista; lista_init(&lista);

    float notas1[] = {4.5, 3.2, 5.0};
    float notas2[] = {3.0, 2.5};
    float notas3[] = {5.0};

    lista_agregar(&lista, crear_alumno("Jacques", "Berman", 20, 1, notas1, 3));
    lista_agregar(&lista, crear_alumno("Omar", "Perez", 22, 2, notas2, 2));
    lista_agregar(&lista, crear_alumno("Arturo", "Morgan", 19, 3, notas3, 1));

    printf("Lista inicial:\n");
    mostrar_lista(&lista);

    lista_eliminar(&lista, 2);

    printf("\nDespues de eliminar:\n");
    mostrar_lista(&lista);

    lista_compactar(&lista);

    printf("\nDespues de compactar:\n");
    mostrar_lista(&lista);

    lista_liberar(&lista);
    return 0;
}
