# ft\_isspace
## Sintaxis y explicación
### Prototipo
```c
int	ft_isspace(int c)
```
### Descripción
ft\_isspace comprueba que el entero 'c' sea casteable a unsigned char y que ese unsigned char sea un espacio, para eso hace uso de la tabla ascii., se entiende como espacio los caracteres ' ' '\t' '\n' '\v' '\f' y '\r'
## Retorno
Devuelve 1 si el entero 'c' está dentro de los valores de un unsigned char y su valor coincide entre los caracteres considerados espacios