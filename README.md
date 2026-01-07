*Este proyecto ha sido creado como parte del currículo de 42 por digonza2*

# ft_printf #

## Descripción ##

En este proyecto se ha programado desde cero la función **printf** en C de la libreria ```<stdio.h>```. Esta función imprime por pantalla una cadena de carácteres fija o variable dependiendo de sus argumentos. Para elegir que tipo de variable se va a imprimir se utilizan las siguientes conversiones:
* **%c** para imprimir un solo carácter.
* **%s** para imprimir una cadena de carácteres (como se define por defecto en C).
* **%p** el puntero void * dado como argumento se imprime en formato hexadecimal.
* **%d** para imprimir un número decimal (base 10).
* **%i** para imprimir un entero en base 10.
* **%u** para imprimir un número decimal (base 10) sin signo.
* **%x** para imprimir un número hexadecimal (base 16) en minúsculas.
* **%X** para imprimir un número hexadecimal (base 16) en mayúsculas.
* **%%** para imprimir el símbolo del porcentaje.

## Instrucciones ##

Para poder utilizar esta función en tus proyectos debes añadir la libreria al inicio de tu programa.
```c
#include "ft_printf.h"
```
Además debes crear la libreria teniendo todos los archivos (de este proyecto) en el mismo directorio:
```bash
make all clean
```
Esto creará un archivo llamado `libftprintf.a` y debes compilarlo junto con tu programa:
```bash
cc <tu_programa>.c libftprintf.a -o <nombre>
```
Ejecuta tu programa:
```bash
./<nombre>
```
(Puedes poner el nombre que quieras en los elementos entre "< >").

Las normas de este proyecto son:
* **make all** Compila la libreria y crea todos los archivos *.o.
* **make clean** Elimina todos los archivos *.o creados.
* **make fclean** Elimina todos los archivos *.o creados y la libreria libftprintf.a.
* **make del** Elimina tus archivos ejecutables acabados en *.out (por defecto es a.out)
* **make re** Elimina todo (hace fclean) y despues vuelve a crearlo todo (hace all).

## Recursos ##

* [Documentacion de argumentos variables](https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170) - Documentación de Microsoft.
* [Manual del printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Documentación oficial de la función printf.
* [Documentación sobre el complemento A2](https://angelmicelti.github.io/4ESO/EDI/complemento_a_2.html) - Comprender los numeros hexadecimales para %p, %x y %X

## Algoritmo y estructura del proyecto ##

El código está dividido en 5 archivos .c con funciones "similares" para estructurar bien el proyecto.

### Archivos ###
### 1 - `ft_printf.c` ###
Contiene la lógica principal y las funciones principales del proyecto.

#### 1. `int	ft_printf(char const *str, ...)` ####
* **Función:** Es la función principal.
* **Algoritmo:**
    1.  Inicia los argumentos variables (...).
    2.  Comienza a escribir el str y si encuentra un `%` llama a la función `ft_formats` para tratar el siguiente carácter.
    3.  Devuelve la longitud que se ha impreso.

#### 2. `int	ft_formats(va_list args, const char c)` ####
* **Función:** Llama a otras funciones dependiendo del carácter c. Actúa de "puente".
* **Algoritmo:**
    1.  En función del carácter que se encuentra hace una cosa:
        * **c** - Llama a `ft_print_char`.
        * **s** - Llama a `ft_print_str`.
        * **p** - Llama a `ft_print_punt`.
        * **d** - Llama a `ft_putnbr`.
        * **i** - Llama a `ft_putnbr`.
        * **u** - Llama a `ft_putnbr_bs` usando la base decimal "0123456789".
        * **x** - Llama a `ft_putnbr_bs` usando la base hexadecimal minúscula "0123456789abcdef".
        * **X** - Llama a `ft_putnbr_bs` usando la base hexadecimal mayúscula "0123456789ABCDEF".
        * **%** - Llama a `ft_print_percent`.
    2.  Devuelve el número de carácteres escrito.

#### 3. `int	ft_print_char(const int c)` ####
* **Función:** Imprime un carácter.
* **Algoritmo:**
	1.  Utiliza `write` para escribir el carácter `c`.
	2.  Devuelve siempre 1.

#### 4. `int	ft_print_str(const char *s)` ####
* **Función:** Imprime una cadena de carácteres.
* **Algoritmo:**
	1.  Llama a la función `ft_print_char` en cada carácter de `s`.
	2.  Si `s` es *NULL*, llama a la función `ft_null`.
	3.  Devuelve el tamaño de la cadena leída.

### 2 - `numbers.c` ###
Contiene toda la gestión de números.

#### 1. `int	ft_putnbr(int n)` ####
* **Función:** Imprime un entero.
* **Algoritmo:**
	1.  Verífica que el entero no es el INT_MIN (-2147483648), si lo es, llama a la función `ft_putminint`.
	2.  Mira si el número es negativo, si lo es, esribe el signo "-" y lo multiplica por "-1".
	3.  Si el número es mayor o igual que 10, usamos la recursividad llamando el número dividido entre 10.
	4.  Llamamos a la función `ft_putnbr_bs` usando el módulo de nuestro número y la base decimal.
	5.  Devolvemos el número de carácteres impresos.

#### 2. `int	ft_putnbr_bs(const unsigned long long n, const char *base)` ####
* **Función:** Imprime cualquier número positivo en cualquier base.
* **Algoritmo:**
	1.  Tiene una lógica similar al `ft_putnbr`pero sin administrar negativos.
	2.  Llama a la función `ft_strlen` para calcular la longitud de la `base` utilizada.
	3. Utiliza la recursividad igual que `ft_putnbr` pero dividiendo entre la longitud de la `base`.
	4.  Imprime los números llamando a `ft_print_char` pasandole como parámetro la posición en la `base` del número a imprimir.
	5.  Devuelve el número de carácteres impresos.

#### 3. `int	ft_print_punt(const unsigned long long n)` ####
* **Función:** Imprime una dirección de memoria.
* **Algoritmo:**
	1.  Verifica que el puntero exista, sino, llama a `ft_nil`.
	2.  Imprime el prefijo "0x" y despues llama a `ft_putnbr_bs` pasándole la base decimal "0123456789".

### 3 - `utils.c` ###
Contiene todas las funciones auxiliares utiles para el proyecto.

#### 1. `size_t	ft_strlen(const char *s)` ####
* **Función:** Cuenta el número de carácteres de la cadena `s`. Función importada de la libft.
* **Algoritmo:** Suma uno por cada carácter de la cadena y devuelve ese número cuando la cadena se acaba.

#### 2. `int	ft_null(void)` ####
* **Función:** Escribe `(null)` y devuelve `6`.

#### 3. `int	ft_nil(void)` ####
* **Función:** Escribe `(nil)` y devuelve `5`.

#### 4. `int	ft_print_percent(void)` ####
* **Función:** Escribe `%` y devuelve `1`.

#### 5. `int	ft_putminint(void)` ####
* **Función:** Escribe `-2147483648` y devuelve `11`.
