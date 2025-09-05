# README – Análisis comparativo de dos métodos de ordenamiento

## Descripción

Los estudiantes están ordenados en orden descendente por nota y, en caso de igualdad, por nombre en orden ascendente.  
Se emplea en dos paradigmas:

- Imperativo (Python)  
- Declarativo/Funcional (Haskell)  

---

## Comparación

**Claridad**  
- Python imprime los elementos paso a paso.  
- Haskell es más conciso con `sortBy`, concentrándose en la lógica de comparación.  

**Abstracción**  
- Python trabaja a bajo nivel, manejando índices y asignaciones.  
- Haskell es más abstracto y delega el algoritmo a la librería.  

**Datos**  
- Python usa listas mutables.  
- Haskell utiliza listas inmutables, sin efectos colaterales.  

**Eficiencia**  
- Python (bubble sort): O(n²).  
- Haskell (`sortBy`): O(n log n).  

---

## Conclusión

- Python es claro y fácil de seguir, pero menos eficiente.  
- Haskell es más expresivo, extensible y eficiente, aunque requiere mayor abstracción.  
