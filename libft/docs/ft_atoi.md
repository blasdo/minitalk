# ft\_atoi
## Sintaxis y explicación
### Prototipo
```c
int ft_atoi(char *str)
```
### Descripción
ft\_atoi convierte la cadena de caracteres terminada en null 'str' en un int.\
Se acepta perfectamente que haya varios espacios (entiendase espacio como [ft_isspace](ft_isspace.md)), también acepta que haya un signo (+ o -) pero no puede soportar mas de un signo, si el signo es '-' el número es negativo, si es '+' es positivo, se entiende como positivo cualquier número sin signo.
### Retorno
Devuelve el entero representado en 'str' como un int.
### Ejemplo
Para el string "1234\0" devuelve el int 1234.
Para el string "-1234\0" devuelve el int -1234.
Para el string "+1234\0" devuelve el int 1234.