*Este proyecto ha sido creado como parte del currículo de 42 por ,<sehurtad>.*

# get_next_line

## Descripción

**get_next_line** es un proyecto del currículo de 42 cuyo objetivo es implementar una función capaz de leer un descriptor de archivo línea a línea utilizando únicamente las funciones permitidas por el enunciado.

La función debe conservar la información que aún no ha sido procesada entre llamadas mediante una variable estática, permitiendo devolver una única línea en cada invocación hasta alcanzar el final del archivo o producirse un error.

Este proyecto introduce conceptos fundamentales de la programación en C, como la gestión dinámica de memoria, el uso de variables estáticas, la manipulación de cadenas y la lectura mediante la llamada al sistema `read()`.

### Prototipo

```c
char *get_next_line(int fd);
```

La función:

- Devuelve la siguiente línea disponible del descriptor de archivo.
- Incluye el carácter `\n` cuando este existe.
- Devuelve la última línea aunque el archivo no termine con un salto de línea.
- Devuelve `NULL` cuando se alcanza el final del archivo o se produce un error.

---

## Instrucciones

### Compilación

Compilar el proyecto con:

```bash
make
```

También es posible compilar manualmente especificando el tamaño del buffer:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

### Uso

Ejemplo de utilización:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

La función puede utilizarse tanto con archivos como con la entrada estándar (`stdin`).

---

## Decisiones técnicas

La implementación se divide en cuatro funciones principales:

- **read_buffer()**: realiza las llamadas a `read()` y almacena la información en un buffer persistente (`stash`).
- **extract_line()**: extrae la siguiente línea completa que será devuelta al usuario.
- **clean_stash()**: elimina del `stash` la línea ya devuelta y conserva únicamente la información pendiente de procesar.
- **get_next_line()**: coordina el flujo completo de lectura.

La persistencia de la información entre llamadas se consigue mediante una variable estática que mantiene los datos pendientes hasta que son consumidos.

---

## Recursos

### Documentación

- Manual de `read()`:
  https://man7.org/linux/man-pages/man2/read.2.html

- Manual de `malloc()`:
  https://man7.org/linux/man-pages/man3/malloc.3.html

- Manual de `free()`:
  https://man7.org/linux/man-pages/man3/free.3.html

- Manual de `open()`:
  https://man7.org/linux/man-pages/man2/open.2.html

- The Linux Programming Interface – Michael Kerrisk.

---

### Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizó **ChatGPT (OpenAI)** como herramienta de apoyo.

Su utilización se limitó a:

- Resolver dudas conceptuales sobre la gestión de memoria.
- Guiar el proceso de depuración mediante la interpretación de errores de Valgrind.
- Realización del readme.md

La implementación final, el diseño del algoritmo y la resolución de los errores fueron realizados de forma manual.

---

## Autor

**Sebastià Hurtado**

Alumno de **42 Barcelona**