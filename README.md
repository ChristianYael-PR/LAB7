# Laboratorio 7: Huffman

## Objetivo

Desarrollar un programa en C++ que implemente el algoritmo de compresión de Huffman para reducir el tamaño de un archivo de texto. El programa debe leer un archivo, calcular las frecuencias de los caracteres, construir el árbol de Huffman, codificar el contenido, comprimirlo, y luego decodificarlo usando el mismo árbol para verificar su integridad.

---

## Fundamento Teórico

El algoritmo de Huffman es una técnica de compresión sin pérdida, basada en la frecuencia de aparición de los símbolos en un archivo. Fue desarrollado por David A. Huffman en 1952 y se considera óptimo para la compresión basada en codificación de longitud variable.

### Principales conceptos:

- **Frecuencia de caracteres:** Se cuenta cuántas veces aparece cada carácter en el texto.
- **Árbol de Huffman:** Se crea un árbol binario donde los caracteres más frecuentes tienen códigos binarios más cortos, y los menos frecuentes, códigos más largos.
- **Codificación:** Se genera un diccionario donde cada símbolo es reemplazado por su código binario único.
- **Decodificación:** Se utiliza el árbol de Huffman para traducir el texto comprimido de vuelta a su forma original.

Este método garantiza una compresión eficiente sin pérdida de datos y es utilizado en formatos como ZIP, JPEG, MP3, entre otros.

---

## Desarrollo de la práctica

El programa realiza los siguientes pasos:

### 1. Lectura del archivo
Se abre un archivo llamado `texto.txt`, que contiene al menos 50 palabras, y se carga su contenido en memoria.

### 2. Cálculo de frecuencias
Se recorren los caracteres del texto para contar cuántas veces aparece cada símbolo, almacenando los resultados en un mapa.

### 3. Construcción del árbol de Huffman
Se construye un árbol binario de Huffman a partir del diccionario de frecuencias usando una cola de prioridad para combinar los nodos con menor frecuencia.

### 4. Generación de códigos
A cada símbolo se le asigna un código binario único, obtenido del recorrido del árbol de Huffman. Esto se almacena en una tabla de codificación.

### 5. Codificación del texto
Se reemplaza cada carácter del texto original por su código binario correspondiente. El resultado es una secuencia comprimida en bits.

### 6. Tasa de compresión
Se calcula el tamaño del archivo original (en bits) y el tamaño del texto comprimido. A partir de eso se obtiene la **tasa de compresión**, que indica la eficiencia del proceso.

### 7. Escritura en archivo
El texto codificado se guarda en un archivo llamado `codificado.txt`.

### 8. Decodificación
Se lee el archivo `codificado.txt` y se reconstruye el texto original utilizando el árbol de Huffman generado previamente.

## Texto:

Red Dead Redemption 2 es un videojuego de acción-aventura de mundo abierto desarrollado y publicado por Rockstar Games. El juego es la tercera entrada de la serie Red Dead y una precuela del juego Red Dead Redemption de 2010. La historia está ambientada en una representación ficticia de los Estados Unidos en 1899 y sigue las hazañas de Arthur Morgan, un forajido y miembro de la pandilla Van der Linde, que debe lidiar con el declive del Salvaje Oeste mientras intenta sobrevivir contra las fuerzas gubernamentales, pandillas rivales y otros adversarios.

## Resultado:

### Codificación:
11110101001010110111000101000001010110111101010010101001011000110101011101000010001111001101100110100111111100111100111100111010100101010000101110000011111001110010001011010101001100001111001111000100111101110111001000110110011000000111011000011101110111101010001101010100110101100011110011101000101100000110000100100010110111001011010101001111100001010101001011101111010001010001011010110101100110100111101100011101010011110000010100010110011010001001011101111010001011110010110110111111101110000101110011100000000101100100111111011011111001100111111011101110000011111001110010001011010011111110111010001101011110001011111001000101000110100001110111010100010100001101010100110111010001101111110001010100100110111101010010101101110001010000010101101011010110011110011000110011010010110011110001111100111010001101010100111011101110000011111001110010001011011110101001010110111000101000001010110111101010010101001011000110101011101000010001111010101001100110110001101110011001000110111010110111110011100010001101110001101001111110111001001010100000110100111111011111110111011011010110000101100011000010010000111011100010100001101000011110011110011000110010110001101001011001111110000111011100011110001001111011101110010001111011100111010011110010111010011110001000001101010100110111010010111111100110011111111101110001010001011111110011001101001101001010001011111110100001111001100100011100110011011110110111111010110101101111101001110010011111001101110100011111110111000110001110011010001111011111100110000011111110101010011001110011101011011111100011011110101110101101100001001011110010000001111110110110011110011110111001110010010100011100000100101000101101011010110101100010010010110001100001010010110101010011011101000110011010000001110100100111011110100011001101101100000111101010100010111001110001010000111010100111101101100110010110111110011010101000110001001101110101001010010000001011101111000010001111010011101110101010011110011101010001110110011010101001110111001110000100011101011101000111000010011001100101010011111101111001101011000100100001110111010100011111110010000111011110000111011100011011111001001100001011000111010100011101010001011101111000010001110111010100011011101000111111101110011101111100010111100110100011111110111001001111011000100010100110001011001000011101110001110110011111111101101100110100000011101001001110111101000111111100101010001110100011101100111111101011010110001010111010100101111111000010100111011000101111110000101010000101111110110111
### Decodificación:
Red Dead Redemption 2 es un videojuego de acción-aventura de mundo abierto desarrollado y publicado por Rockstar Games. El juego es la tercera entrada de la serie Red Dead y una precuela del juego Red Dead Redemption de 2010. La historia está ambientada en una representación ficticia de los Estados Unidos en 1899 y sigue las hazañas de Arthur Morgan, un forajido y miembro de la pandilla Van der Linde, que debe lidiar con el declive del Salvaje Oeste mientras intenta sobrevivir contra las fuerzas gubernamentales, pandillas rivales y otros adversarios.

---

## Conclusiones

- La implementación del algoritmo de Huffman demuestra cómo las estructuras de datos (como árboles binarios y colas de prioridad) pueden aplicarse a problemas reales como la compresión de información.
- Se comprobó que el algoritmo es completamente reversible, garantizando que el archivo original puede recuperarse exactamente.
- Esta práctica refuerza la importancia de elegir el algoritmo adecuado según las características de los datos, ya que Huffman es más eficiente cuando hay símbolos con frecuencias muy dispares.
- El trabajo también mostró cómo manipular archivos, transformar texto en representaciones binarias y aplicar recorridos recursivos para codificación y decodificación.

---

## Archivos del proyecto

- `texto.txt` – Archivo original con el texto sin comprimir.
- `codificado.txt` – Archivo con el contenido comprimido en binario.
- `LAB7.cpp` – Código fuente principal que realiza todo el proceso.
