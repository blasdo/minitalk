# ft\_isalpha
## Sintaxis y explicación
### Prototipo
```c
int	ft_isalpha(int c);
```
### Descripción
ft\_isalpha comprueba que el entero 'c' sea casteable a unsigned char y que ese unsigned char sea un caracter alphabetico (de la 'a' a la 'z' sin pasar por la 'ñ' tanto en mayusculas como en minusculas)
## Retorno
Devuelve 1 si el entero 'c' está dentro de los valores de un unsigned char y su valor en la tabla ascii es el de un caracter alfabetico