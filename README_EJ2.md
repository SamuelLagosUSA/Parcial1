# Sistema de Administración de Estudiantes en C

Este proyecto consta de un sistema de administración de estudiantes de una universidad.  
Cada estudiante tiene nombre, apellido, edad, código y un conjunto de calificaciones.

El objetivo principal es optimizar el uso de memoria mediante estructuras dinámicas y mecanismos de compactación.

## Características

- Uso de una estructura para representar estudiantes y la lista.  
- Asignación de memoria dinámica con `malloc`, `realloc` y `free`.  
- Ajuste de la memoria al tamaño requerido para nombres, apellidos y calificaciones.  
- Eliminación de estudiantes por código.  
- Compactación de la lista para evitar huecos.  
- Liberación de memoria al finalizar.  

## Flujo del programa

1. Inicializa la lista vacía.  
2. Crea estudiantes dinámicamente y los agrega a la lista.  
3. Muestra los estudiantes registrados.  
4. Elimina un estudiante por código.  
5. Compacta la lista para optimizar el espacio.  
6. Libera toda la memoria utilizada.  

## Conclusión

El programa muestra cómo usar la memoria de manera eficiente y dinámica en C, evitando desperdicios y asegurando la correcta liberación de los recursos.
