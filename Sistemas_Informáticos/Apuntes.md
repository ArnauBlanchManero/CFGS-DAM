# Configura tu terminal
Modifica el fichero ~/.bashrc
# Moverse por la Terminal
- `ls -a` - Muestra archivos ocultos
- `ls -R` - Ejecuta `ls` recursivamente en todas las subcarpetas
- `cd [name]` - Cambia de directorio

# Gestionar Ficheros
- `rm [file]` - Elimina el fichero
- `cat [file]` - Muestra el contenido
- `grep [palabra] [file]` - Busca la palabra del el contenido del fichero
- `nano [file]` - Editar el fichero
- `head -n [numero] [file]` - Muestra el número de líneas que has indicado del fichero
- `fail [file]` - Muestra el final del fichero
- `less [file]` - Muestra el fichero y te permite moverte arriba y abajo
- `wc [file]` - Cuenta palabras, líneas, bytes...
- `sort [file]` - Ordena
- `uniq [file]` - Quita duplicados
- `man [comando]` - Te muestra el manual del comando
- `sed 's/palabra1/palabra2/' [file]` - Sustituye la palabra 2 por la palabra 1 del fichero

# Metacaracteres
- `*` - Selecciona todo
- `^` - Marca el inicio de línea
- `$` - Marca el fin de la línea
- `|` - Tubería para pasar la salida de un comano a la entrada de otro (pipes)
- `>` - Redireccionar

# Ejercicios
1. Encuentra todas las líneas que terminen con "error" en el archivo `file1.txt` y guarda el resultado en `output1.txt`.
~~~
$ grep "error$" file1.txt > output1.txt
$ cat output1.txt
Línea 1 con error
Línea 2 con error
Línea 3 con error
Línea 4 con error
Línea 5 con error
Línea 6 con error
Línea 7 con error
Línea 8 con error
Línea 9 con error
Línea 11 con error
Línea 12 con error
Línea 13 con error
Línea 14 con error
Línea 15 con error
Línea 16 con error
Línea 17 con error
Línea 18 con error
Línea 19 con error
Línea 21 con error
Línea 22 con error
Línea 23 con error
Línea 24 con error
Línea 25 con error
Línea 26 con error
Línea 27 con error
Línea 28 con error
Línea 29 con error
Línea 31 con error
Línea 32 con error
Línea 33 con error
Línea 34 con error
Línea 35 con error
Línea 36 con error
Línea 37 con error
Línea 38 con error
Línea 39 con error
Línea 41 con error
Línea 42 con error
Línea 43 con error
Línea 44 con error
Línea 45 con error
Línea 46 con error
Línea 47 con error
Línea 48 con error
Línea 49 con error
~~~
2. Reemplaza todas las ocurrencias de "DEBUG" por "INFO" en el archivo `file1.txt` y guarda el resultado en `output2.txt`.
~~~
$ sed 's/DEBUG/INFO/' file1.txt > output2.txt
$ cat output2.txt
Línea 1 con error
Línea 2 con error
Línea 3 con error
Línea 4 con error
Línea 5 con error
Línea 6 con error
Línea 7 con error
Línea 8 con error
Línea 9 con error
INFO: Línea de prueba 10
Línea 11 con error
Línea 12 con error
Línea 13 con error
Línea 14 con error
Línea 15 con error
Línea 16 con error
Línea 17 con error
Línea 18 con error
Línea 19 con error
INFO: Línea de prueba 20
Línea 21 con error
Línea 22 con error
Línea 23 con error
Línea 24 con error
Línea 25 con error
Línea 26 con error
Línea 27 con error
Línea 28 con error
Línea 29 con error
INFO: Línea de prueba 30
Línea 31 con error
Línea 32 con error
Línea 33 con error
Línea 34 con error
Línea 35 con error
Línea 36 con error
Línea 37 con error
Línea 38 con error
Línea 39 con error
INFO: Línea de prueba 40
Línea 41 con error
Línea 42 con error
Línea 43 con error
Línea 44 con error
Línea 45 con error
Línea 46 con error
Línea 47 con error
Línea 48 con error
Línea 49 con error
~~~
3. Muestra las primeras 5 líneas de `file1.txt` que contengan "ERROR" y guarda el resultado en `output3.txt`.

4. Cuenta el número de archivos `.txt` en el directorio actual y guarda el resultado en `output4.txt`.

5. Ordena las líneas del archivo `file1.txt` alfabéticamente, elimina duplicados, y guarda el resultado en `output5.txt`.

6. Divide el archivo `file6_large.txt` en dos archivos: uno con las primeras 100 líneas (`out6.1.txt`) y otro con el resto (`out.6.txt`).

7. Elimina todas las líneas en blanco del archivo `file4.txt` y guarda el resultado en `output7.txt`.

8. Reemplaza todas las comas por tabulaciones en el archivo `file2.csv` y guarda el resultado en `output8.csv`.

9. Inserta el prefijo "INICIO:" antes de cada línea que comience con una vocal en el archivo `file5.txt` y guarda el resultado en `output9.txt`.

10. Cuenta cuántas líneas en el archivo `file1.txt` contienen la palabra "ERROR" y guarda el resultado en `output10.txt`.

11. Crea un script que muestre el número total de archivos en el directorio actual y escribe el resultado en `output11.txt`.

12. Encuentra líneas duplicadas en el archivo `file7_duplicates.txt`, muestra cuántas veces se repiten, y guarda el resultado en `output12.txt`.

13. Extrae las primeras 100 líneas del archivo `file6_large.txt` y guarda el resultado en `output13.txt`.

14. Busca todas las líneas que contengan números en el archivo `file1.txt` y guarda el resultado en `output14.txt`.

15. Convierte el archivo `file2.csv` en un archivo delimitado por punto y coma y guarda el resultado en `output15.csv`.

16. Inserta un prefijo "MODIFICADO:" antes de las líneas que contengan la palabra "ERROR" en el archivo `file1.txt` y guarda el resultado en `output16.txt`.

17. Extrae las líneas del archivo `file3.txt` que contengan números pares y guarda el resultado en `output17.txt`.

18. Busca recursivamente en todos los subdirectorios del directorio actual archivos que contengan la palabra "ERROR" y guarda las coincidencias en `output18.txt`.

19. Extrae las últimas 50 líneas del archivo `file6_large.txt` y guarda el resultado en `output19.txt`.

20. Lista todos los archivos, incluidos los ocultos, de forma recursiva desde el directorio actual y guarda el resultado en `output20.txt`.