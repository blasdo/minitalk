# ft\_isalnum
## Sintaxis y explicación
### Prototipo
```c
int	ft_isalnum(int c);
```
### Descripción
ft\_isalnum comprueba que el entero 'c' sea casteable a unsigned char y que ese unsigned char sea un caracter alphabetico o un digito según [ft_isalpha](ft_isalpha.md) o [ft_isdigit](ft_isdigit.nd)
## Retorno
Devuelve 1 si el entero 'c' está dentro de los valores de un unsigned char y que su valor coincida con el de un caracter alphanumérico