# Configura tu terminal
Modifica el fichero ~/.bashrc
# Moverse por la Terminal
- `ls -a` - Muestra archivos ocultos
- `ls -R` - Ejecuta `ls` recursivamente en todas las subcarpetas
- `cd [name]` - Cambia de directorio
- `pwd` - Te dice el directorio en el que estás

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
- `sed 's/palabra1/palabra2/g' [file]` - Sustituye la palabra2 por la palabra1 del fichero
- `diff -y [file] [file]` - Muestra las diferencias de los dos ficheros

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
~~~
$ grep "error" file1.txt | head -n 5 > output3.txt
$ cat output3.txt
Línea 1 con error
Línea 2 con error
Línea 3 con error
Línea 4 con error
Línea 5 con error
~~~
4. Cuenta el número de archivos `.txt` en el directorio actual y guarda el resultado en `output4.txt`.
~~~
$ ls *.txt | wc -w > output4.txt
$ cat output4.txt
9
~~~
5. Ordena las líneas del archivo `file1.txt` alfabéticamente, elimina duplicados, y guarda el resultado en `output5.txt`.
~~~
$ sort file1.txt | uniq > output5.txt
$ cat output5.txt
DEBUG: Línea de prueba 10
DEBUG: Línea de prueba 20
DEBUG: Línea de prueba 30
DEBUG: Línea de prueba 40
DEBUG: Línea de prueba 50
Línea 1 con error
Línea 11 con error
Línea 12 con error
Línea 13 con error
Línea 14 con error
Línea 15 con error
Línea 16 con error
Línea 17 con error
Línea 18 con error
Línea 19 con error
Línea 2 con error
Línea 21 con error
Línea 22 con error
Línea 23 con error
Línea 24 con error
Línea 25 con error
Línea 26 con error
Línea 27 con error
Línea 28 con error
Línea 29 con error
Línea 3 con error
Línea 31 con error
Línea 32 con error
Línea 33 con error
Línea 34 con error
Línea 35 con error
Línea 36 con error
Línea 37 con error
Línea 38 con error
Línea 39 con error
Línea 4 con error
Línea 41 con error
Línea 42 con error
Línea 43 con error
Línea 44 con error
Línea 45 con error
Línea 46 con error
Línea 47 con error
Línea 48 con error
Línea 49 con error
Línea 5 con error
Línea 6 con error
Línea 7 con error
Línea 8 con error
Línea 9 con error
~~~
6. Divide el archivo `file6_large.txt` en dos archivos: uno con las primeras 100 líneas (`out6.1.txt`) y otro con el resto (`out.6.txt`).
~~~
$ head -n 100 file6_large.txt > out6.1.txt
$ cat out6.1.txt
Línea 1
Línea 2
Línea 3
Línea 4
Línea 5
Línea 6
Línea 7
Línea 8
Línea 9
Línea 10
Línea 11
Línea 12
Línea 13
Línea 14
Línea 15
Línea 16
Línea 17
Línea 18
Línea 19
Línea 20
Línea 21
Línea 22
Línea 23
Línea 24
Línea 25
Línea 26
Línea 27
Línea 28
Línea 29
Línea 30
Línea 31
Línea 32
Línea 33
Línea 34
Línea 35
Línea 36
Línea 37
Línea 38
Línea 39
Línea 40
Línea 41
Línea 42
Línea 43
Línea 44
Línea 45
Línea 46
Línea 47
Línea 48
Línea 49
Línea 50
Línea 51
Línea 52
Línea 53
Línea 54
Línea 55
Línea 56
Línea 57
Línea 58
Línea 59
Línea 60
Línea 61
Línea 62
Línea 63
Línea 64
Línea 65
Línea 66
Línea 67
Línea 68
Línea 69
Línea 70
Línea 71
Línea 72
Línea 73
Línea 74
Línea 75
Línea 76
Línea 77
Línea 78
Línea 79
Línea 80
Línea 81
Línea 82
Línea 83
Línea 84
Línea 85
Línea 86
Línea 87
Línea 88
Línea 89
Línea 90
Línea 91
Línea 92
Línea 93
Línea 94
Línea 95
Línea 96
Línea 97
Línea 98
Línea 99
Línea 100
~~~
~~~
$ sed '1,100d' file6_large.txt > out6.2.txt
$ cat out6.2.txt
Línea 101
Línea 102
Línea 103
Línea 104
Línea 105
Línea 106
Línea 107
Línea 108
Línea 109
Línea 110
Línea 111
Línea 112
Línea 113
Línea 114
Línea 115
Línea 116
Línea 117
Línea 118
Línea 119
Línea 120
Línea 121
Línea 122
Línea 123
Línea 124
Línea 125
Línea 126
Línea 127
Línea 128
Línea 129
Línea 130
Línea 131
Línea 132
Línea 133
Línea 134
Línea 135
Línea 136
Línea 137
Línea 138
Línea 139
Línea 140
Línea 141
Línea 142
Línea 143
Línea 144
Línea 145
Línea 146
Línea 147
Línea 148
Línea 149
Línea 150
Línea 151
Línea 152
Línea 153
Línea 154
Línea 155
Línea 156
Línea 157
Línea 158
Línea 159
Línea 160
Línea 161
Línea 162
Línea 163
Línea 164
Línea 165
Línea 166
Línea 167
Línea 168
Línea 169
Línea 170
Línea 171
Línea 172
Línea 173
Línea 174
Línea 175
Línea 176
Línea 177
Línea 178
Línea 179
Línea 180
Línea 181
Línea 182
Línea 183
Línea 184
Línea 185
Línea 186
Línea 187
Línea 188
Línea 189
Línea 190
Línea 191
Línea 192
Línea 193
Línea 194
Línea 195
Línea 196
Línea 197
Línea 198
Línea 199
Línea 200
~~~
7. Elimina todas las líneas en blanco del archivo `file4.txt` y guarda el resultado en `output7.txt`.
~~~
$ grep -v "^$" file4.txt > output7.txt
$ cat output7.txt
Línea 1
Línea 2
Línea 4
Línea 5
Línea 7
Línea 8
Línea 10
Línea 11
Línea 13
Línea 14
Línea 16
Línea 17
Línea 19
Línea 20
Línea 22
Línea 23
Línea 25
Línea 26
Línea 28
Línea 29
Línea 31
Línea 32
Línea 34
Línea 35
Línea 37
Línea 38
Línea 40
~~~
8. Reemplaza todas las comas por tabulaciones en el archivo `file2.csv` y guarda el resultado en `output8.csv`.
~~~
$ sed 's/,/\t/g' file2.csv > output8.csv
$ cat output8.csv
nombre  edad    ciudad
Persona1        21      Ciudad1
Persona2        22      Ciudad2
Persona3        23      Ciudad3
Persona4        24      Ciudad4
Persona5        25      Ciudad5
Persona6        26      Ciudad6
Persona7        27      Ciudad7
Persona8        28      Ciudad8
Persona9        29      Ciudad9
Persona10       30      Ciudad10
Persona11       31      Ciudad11
Persona12       32      Ciudad12
Persona13       33      Ciudad13
Persona14       34      Ciudad14
Persona15       35      Ciudad15
Persona16       36      Ciudad16
Persona17       37      Ciudad17
Persona18       38      Ciudad18
Persona19       39      Ciudad19
Persona20       40      Ciudad20
Persona21       41      Ciudad21
Persona22       42      Ciudad22
Persona23       43      Ciudad23
Persona24       44      Ciudad24
Persona25       45      Ciudad25
Persona26       46      Ciudad26
Persona27       47      Ciudad27
Persona28       48      Ciudad28
Persona29       49      Ciudad29
Persona30       50      Ciudad30
~~~
9. Inserta el prefijo "INICIO:" antes de cada línea que comience con una vocal en el archivo `file5.txt` y guarda el resultado en `output9.txt`.
~~~
$ grep [AEIOU] file5.txt | sed 's/^/INICIO: /' > output9.txt
$ cat output9.txt
INICIO: Una línea 1
INICIO: Otra línea 2
INICIO: Ejemplo línea 3
INICIO: Otra línea 4
~~~
10. Cuenta cuántas líneas en el archivo `file1.txt` contienen la palabra "ERROR" y guarda el resultado en `output10.txt`.
~~~
$ grep -c "error" file1.txt > output10.txt
$ cat output10.txt
45
~~~
11. Crea un script que muestre el número total de archivos en el directorio actual y escribe el resultado en `output11.txt`.
~~~
$ ls | wc -w > output11.txt
$ cat output11.txt
21
~~~
12. Encuentra líneas duplicadas en el archivo `file7_duplicates.txt`, muestra cuántas veces se repiten, y guarda el resultado en `output12.txt`.
~~~
$ sort file7_duplicates.txt | uniq -cd > output12.txt
$ cat output12.txt
15 Línea repetida
~~~
13. Extrae las primeras 100 líneas del archivo `file6_large.txt` y guarda el resultado en `output13.txt`.
~~~
$ cat file6_large.txt | head -n 100 > output13.txt
$ cat output13.txt
Línea 1
Línea 2
Línea 3
Línea 4
Línea 5
Línea 6
Línea 7
Línea 8
Línea 9
Línea 10
Línea 11
Línea 12
Línea 13
Línea 14
Línea 15
Línea 16
Línea 17
Línea 18
Línea 19
Línea 20
Línea 21
Línea 22
Línea 23
Línea 24
Línea 25
Línea 26
Línea 27
Línea 28
Línea 29
Línea 30
Línea 31
Línea 32
Línea 33
Línea 34
Línea 35
Línea 36
Línea 37
Línea 38
Línea 39
Línea 40
Línea 41
Línea 42
Línea 43
Línea 44
Línea 45
Línea 46
Línea 47
Línea 48
Línea 49
Línea 50
Línea 51
Línea 52
Línea 53
Línea 54
Línea 55
Línea 56
Línea 57
Línea 58
Línea 59
Línea 60
Línea 61
Línea 62
Línea 63
Línea 64
Línea 65
Línea 66
Línea 67
Línea 68
Línea 69
Línea 70
Línea 71
Línea 72
Línea 73
Línea 74
Línea 75
Línea 76
Línea 77
Línea 78
Línea 79
Línea 80
Línea 81
Línea 82
Línea 83
Línea 84
Línea 85
Línea 86
Línea 87
Línea 88
Línea 89
Línea 90
Línea 91
Línea 92
Línea 93
Línea 94
Línea 95
Línea 96
Línea 97
Línea 98
Línea 99
Línea 100
~~~
14. Busca todas las líneas que contengan números en el archivo `file1.txt` y guarda el resultado en `output14.txt`.
~~~
$ grep [0-9] file1.txt > output14.txt
$ cat output14.txt
Línea 1 con error
Línea 2 con error
Línea 3 con error
Línea 4 con error
Línea 5 con error
Línea 6 con error
Línea 7 con error
Línea 8 con error
Línea 9 con error
DEBUG: Línea de prueba 10
Línea 11 con error
Línea 12 con error
Línea 13 con error
Línea 14 con error
Línea 15 con error
Línea 16 con error
Línea 17 con error
Línea 18 con error
Línea 19 con error
DEBUG: Línea de prueba 20
Línea 21 con error
Línea 22 con error
Línea 23 con error
Línea 24 con error
Línea 25 con error
Línea 26 con error
Línea 27 con error
Línea 28 con error
Línea 29 con error
DEBUG: Línea de prueba 30
Línea 31 con error
Línea 32 con error
Línea 33 con error
Línea 34 con error
Línea 35 con error
Línea 36 con error
Línea 37 con error
Línea 38 con error
Línea 39 con error
DEBUG: Línea de prueba 40
Línea 41 con error
Línea 42 con error
Línea 43 con error
Línea 44 con error
Línea 45 con error
Línea 46 con error
Línea 47 con error
Línea 48 con error
Línea 49 con error
DEBUG: Línea de prueba 50
~~~
15. Convierte el archivo `file2.csv` en un archivo delimitado por punto y coma y guarda el resultado en `output15.csv`.
~~~
$ sed 's/,/;/g' file2.csv > output15.csv
$ cat output15.csv
nombre;edad;ciudad
Persona1;21;Ciudad1
Persona2;22;Ciudad2
Persona3;23;Ciudad3
Persona4;24;Ciudad4
Persona5;25;Ciudad5
Persona6;26;Ciudad6
Persona7;27;Ciudad7
Persona8;28;Ciudad8
Persona9;29;Ciudad9
Persona10;30;Ciudad10
Persona11;31;Ciudad11
Persona12;32;Ciudad12
Persona13;33;Ciudad13
Persona14;34;Ciudad14
Persona15;35;Ciudad15
Persona16;36;Ciudad16
Persona17;37;Ciudad17
Persona18;38;Ciudad18
Persona19;39;Ciudad19
Persona20;40;Ciudad20
Persona21;41;Ciudad21
Persona22;42;Ciudad22
Persona23;43;Ciudad23
Persona24;44;Ciudad24
Persona25;45;Ciudad25
Persona26;46;Ciudad26
Persona27;47;Ciudad27
Persona28;48;Ciudad28
Persona29;49;Ciudad29
Persona30;50;Ciudad30
~~~
16. Inserta un prefijo "MODIFICADO:" antes de las líneas que contengan la palabra "ERROR" en el archivo `file1.txt` y guarda el resultado en `output16.txt`.
~~~
$ sed '/error/s/^/MODIFICADO: /' file1.txt > output16.txt
$ cat output16.txt
MODIFICADO: Línea 1 con error
MODIFICADO: Línea 2 con error
MODIFICADO: Línea 3 con error
MODIFICADO: Línea 4 con error
MODIFICADO: Línea 5 con error
MODIFICADO: Línea 6 con error
MODIFICADO: Línea 7 con error
MODIFICADO: Línea 8 con error
MODIFICADO: Línea 9 con error
DEBUG: Línea de prueba 10
MODIFICADO: Línea 11 con error
MODIFICADO: Línea 12 con error
MODIFICADO: Línea 13 con error
MODIFICADO: Línea 14 con error
MODIFICADO: Línea 15 con error
MODIFICADO: Línea 16 con error
MODIFICADO: Línea 17 con error
MODIFICADO: Línea 18 con error
MODIFICADO: Línea 19 con error
DEBUG: Línea de prueba 20
MODIFICADO: Línea 21 con error
MODIFICADO: Línea 22 con error
MODIFICADO: Línea 23 con error
MODIFICADO: Línea 24 con error
MODIFICADO: Línea 25 con error
MODIFICADO: Línea 26 con error
MODIFICADO: Línea 27 con error
MODIFICADO: Línea 28 con error
MODIFICADO: Línea 29 con error
DEBUG: Línea de prueba 30
MODIFICADO: Línea 31 con error
MODIFICADO: Línea 32 con error
MODIFICADO: Línea 33 con error
MODIFICADO: Línea 34 con error
MODIFICADO: Línea 35 con error
MODIFICADO: Línea 36 con error
MODIFICADO: Línea 37 con error
MODIFICADO: Línea 38 con error
MODIFICADO: Línea 39 con error
DEBUG: Línea de prueba 40
MODIFICADO: Línea 41 con error
MODIFICADO: Línea 42 con error
MODIFICADO: Línea 43 con error
MODIFICADO: Línea 44 con error
MODIFICADO: Línea 45 con error
MODIFICADO: Línea 46 con error
MODIFICADO: Línea 47 con error
MODIFICADO: Línea 48 con error
MODIFICADO: Línea 49 con error
DEBUG: Línea de prueba 50
~~~
17. Extrae las líneas del archivo `file3.txt` que contengan números pares y guarda el resultado en `output17.txt`.
~~~
$ grep [24680]'\b' file3.txt > output17.txt
$ cat output17.txt
2
4
6
8
10
12
14
16
18
20
22
24
26
28
30
~~~
18. Busca recursivamente en todos los subdirectorios del directorio actual archivos que contengan la palabra "ERROR" y guarda las coincidencias en `output18.txt`.
~~~
$ grep -r error * > output18.txt
$ cat output18.txt
file1.txt:Línea 1 con error
file1.txt:Línea 2 con error
file1.txt:Línea 3 con error
file1.txt:Línea 4 con error
file1.txt:Línea 5 con error
file1.txt:Línea 6 con error
file1.txt:Línea 7 con error
file1.txt:Línea 8 con error
file1.txt:Línea 9 con error
file1.txt:Línea 11 con error
file1.txt:Línea 12 con error
file1.txt:Línea 13 con error
file1.txt:Línea 14 con error
file1.txt:Línea 15 con error
file1.txt:Línea 16 con error
file1.txt:Línea 17 con error
file1.txt:Línea 18 con error
file1.txt:Línea 19 con error
file1.txt:Línea 21 con error
file1.txt:Línea 22 con error
file1.txt:Línea 23 con error
file1.txt:Línea 24 con error
file1.txt:Línea 25 con error
file1.txt:Línea 26 con error
file1.txt:Línea 27 con error
file1.txt:Línea 28 con error
file1.txt:Línea 29 con error
file1.txt:Línea 31 con error
file1.txt:Línea 32 con error
file1.txt:Línea 33 con error
file1.txt:Línea 34 con error
file1.txt:Línea 35 con error
file1.txt:Línea 36 con error
file1.txt:Línea 37 con error
file1.txt:Línea 38 con error
file1.txt:Línea 39 con error
file1.txt:Línea 41 con error
file1.txt:Línea 42 con error
file1.txt:Línea 43 con error
file1.txt:Línea 44 con error
file1.txt:Línea 45 con error
file1.txt:Línea 46 con error
file1.txt:Línea 47 con error
file1.txt:Línea 48 con error
file1.txt:Línea 49 con error
output1.txt:Línea 1 con error
output1.txt:Línea 2 con error
output1.txt:Línea 3 con error
output1.txt:Línea 4 con error
output1.txt:Línea 5 con error
output1.txt:Línea 6 con error
output1.txt:Línea 7 con error
output1.txt:Línea 8 con error
output1.txt:Línea 9 con error
output1.txt:Línea 11 con error
output1.txt:Línea 12 con error
output1.txt:Línea 13 con error
output1.txt:Línea 14 con error
output1.txt:Línea 15 con error
output1.txt:Línea 16 con error
output1.txt:Línea 17 con error
output1.txt:Línea 18 con error
output1.txt:Línea 19 con error
output1.txt:Línea 21 con error
output1.txt:Línea 22 con error
output1.txt:Línea 23 con error
output1.txt:Línea 24 con error
output1.txt:Línea 25 con error
output1.txt:Línea 26 con error
output1.txt:Línea 27 con error
output1.txt:Línea 28 con error
output1.txt:Línea 29 con error
output1.txt:Línea 31 con error
output1.txt:Línea 32 con error
output1.txt:Línea 33 con error
output1.txt:Línea 34 con error
output1.txt:Línea 35 con error
output1.txt:Línea 36 con error
output1.txt:Línea 37 con error
output1.txt:Línea 38 con error
output1.txt:Línea 39 con error
output1.txt:Línea 41 con error
output1.txt:Línea 42 con error
output1.txt:Línea 43 con error
output1.txt:Línea 44 con error
output1.txt:Línea 45 con error
output1.txt:Línea 46 con error
output1.txt:Línea 47 con error
output1.txt:Línea 48 con error
output1.txt:Línea 49 con error
output14.txt:Línea 1 con error
output14.txt:Línea 2 con error
output14.txt:Línea 3 con error
output14.txt:Línea 4 con error
output14.txt:Línea 5 con error
output14.txt:Línea 6 con error
output14.txt:Línea 7 con error
output14.txt:Línea 8 con error
output14.txt:Línea 9 con error
output14.txt:Línea 11 con error
output14.txt:Línea 12 con error
output14.txt:Línea 13 con error
output14.txt:Línea 14 con error
output14.txt:Línea 15 con error
output14.txt:Línea 16 con error
output14.txt:Línea 17 con error
output14.txt:Línea 18 con error
output14.txt:Línea 19 con error
output14.txt:Línea 21 con error
output14.txt:Línea 22 con error
output14.txt:Línea 23 con error
output14.txt:Línea 24 con error
output14.txt:Línea 25 con error
output14.txt:Línea 26 con error
output14.txt:Línea 27 con error
output14.txt:Línea 28 con error
output14.txt:Línea 29 con error
output14.txt:Línea 31 con error
output14.txt:Línea 32 con error
output14.txt:Línea 33 con error
output14.txt:Línea 34 con error
output14.txt:Línea 35 con error
output14.txt:Línea 36 con error
output14.txt:Línea 37 con error
output14.txt:Línea 38 con error
output14.txt:Línea 39 con error
output14.txt:Línea 41 con error
output14.txt:Línea 42 con error
output14.txt:Línea 43 con error
output14.txt:Línea 44 con error
output14.txt:Línea 45 con error
output14.txt:Línea 46 con error
output14.txt:Línea 47 con error
output14.txt:Línea 48 con error
output14.txt:Línea 49 con error
output16.txt:MODIFICADO: Línea 1 con error
output16.txt:MODIFICADO: Línea 2 con error
output16.txt:MODIFICADO: Línea 3 con error
output16.txt:MODIFICADO: Línea 4 con error
output16.txt:MODIFICADO: Línea 5 con error
output16.txt:MODIFICADO: Línea 6 con error
output16.txt:MODIFICADO: Línea 7 con error
output16.txt:MODIFICADO: Línea 8 con error
output16.txt:MODIFICADO: Línea 9 con error
output16.txt:MODIFICADO: Línea 11 con error
output16.txt:MODIFICADO: Línea 12 con error
output16.txt:MODIFICADO: Línea 13 con error
output16.txt:MODIFICADO: Línea 14 con error
output16.txt:MODIFICADO: Línea 15 con error
output16.txt:MODIFICADO: Línea 16 con error
output16.txt:MODIFICADO: Línea 17 con error
output16.txt:MODIFICADO: Línea 18 con error
output16.txt:MODIFICADO: Línea 19 con error
output16.txt:MODIFICADO: Línea 21 con error
output16.txt:MODIFICADO: Línea 22 con error
output16.txt:MODIFICADO: Línea 23 con error
output16.txt:MODIFICADO: Línea 24 con error
output16.txt:MODIFICADO: Línea 25 con error
output16.txt:MODIFICADO: Línea 26 con error
output16.txt:MODIFICADO: Línea 27 con error
output16.txt:MODIFICADO: Línea 28 con error
output16.txt:MODIFICADO: Línea 29 con error
output16.txt:MODIFICADO: Línea 31 con error
output16.txt:MODIFICADO: Línea 32 con error
output16.txt:MODIFICADO: Línea 33 con error
output16.txt:MODIFICADO: Línea 34 con error
output16.txt:MODIFICADO: Línea 35 con error
output16.txt:MODIFICADO: Línea 36 con error
output16.txt:MODIFICADO: Línea 37 con error
output16.txt:MODIFICADO: Línea 38 con error
output16.txt:MODIFICADO: Línea 39 con error
output16.txt:MODIFICADO: Línea 41 con error
output16.txt:MODIFICADO: Línea 42 con error
output16.txt:MODIFICADO: Línea 43 con error
output16.txt:MODIFICADO: Línea 44 con error
output16.txt:MODIFICADO: Línea 45 con error
output16.txt:MODIFICADO: Línea 46 con error
output16.txt:MODIFICADO: Línea 47 con error
output16.txt:MODIFICADO: Línea 48 con error
output16.txt:MODIFICADO: Línea 49 con error
output2.txt:Línea 1 con error
output2.txt:Línea 2 con error
output2.txt:Línea 3 con error
output2.txt:Línea 4 con error
output2.txt:Línea 5 con error
output2.txt:Línea 6 con error
output2.txt:Línea 7 con error
output2.txt:Línea 8 con error
output2.txt:Línea 9 con error
output2.txt:Línea 11 con error
output2.txt:Línea 12 con error
output2.txt:Línea 13 con error
output2.txt:Línea 14 con error
output2.txt:Línea 15 con error
output2.txt:Línea 16 con error
output2.txt:Línea 17 con error
output2.txt:Línea 18 con error
output2.txt:Línea 19 con error
output2.txt:Línea 21 con error
output2.txt:Línea 22 con error
output2.txt:Línea 23 con error
output2.txt:Línea 24 con error
output2.txt:Línea 25 con error
output2.txt:Línea 26 con error
output2.txt:Línea 27 con error
output2.txt:Línea 28 con error
output2.txt:Línea 29 con error
output2.txt:Línea 31 con error
output2.txt:Línea 32 con error
output2.txt:Línea 33 con error
output2.txt:Línea 34 con error
output2.txt:Línea 35 con error
output2.txt:Línea 36 con error
output2.txt:Línea 37 con error
output2.txt:Línea 38 con error
output2.txt:Línea 39 con error
output2.txt:Línea 41 con error
output2.txt:Línea 42 con error
output2.txt:Línea 43 con error
output2.txt:Línea 44 con error
output2.txt:Línea 45 con error
output2.txt:Línea 46 con error
output2.txt:Línea 47 con error
output2.txt:Línea 48 con error
output2.txt:Línea 49 con error
output3.txt:Línea 1 con error
output3.txt:Línea 2 con error
output3.txt:Línea 3 con error
output3.txt:Línea 4 con error
output3.txt:Línea 5 con error
output5.txt:Línea 1 con error
output5.txt:Línea 11 con error
output5.txt:Línea 12 con error
output5.txt:Línea 13 con error
output5.txt:Línea 14 con error
output5.txt:Línea 15 con error
output5.txt:Línea 16 con error
output5.txt:Línea 17 con error
output5.txt:Línea 18 con error
output5.txt:Línea 19 con error
output5.txt:Línea 2 con error
output5.txt:Línea 21 con error
output5.txt:Línea 22 con error
output5.txt:Línea 23 con error
output5.txt:Línea 24 con error
output5.txt:Línea 25 con error
output5.txt:Línea 26 con error
output5.txt:Línea 27 con error
output5.txt:Línea 28 con error
output5.txt:Línea 29 con error
output5.txt:Línea 3 con error
output5.txt:Línea 31 con error
output5.txt:Línea 32 con error
output5.txt:Línea 33 con error
output5.txt:Línea 34 con error
output5.txt:Línea 35 con error
output5.txt:Línea 36 con error
output5.txt:Línea 37 con error
output5.txt:Línea 38 con error
output5.txt:Línea 39 con error
output5.txt:Línea 4 con error
output5.txt:Línea 41 con error
output5.txt:Línea 42 con error
output5.txt:Línea 43 con error
output5.txt:Línea 44 con error
output5.txt:Línea 45 con error
output5.txt:Línea 46 con error
output5.txt:Línea 47 con error
output5.txt:Línea 48 con error
output5.txt:Línea 49 con error
output5.txt:Línea 5 con error
output5.txt:Línea 6 con error
output5.txt:Línea 7 con error
output5.txt:Línea 8 con error
output5.txt:Línea 9 con error
subdir1/file_in_subdir1_error.txt:Línea 1 con error
subdir1/file_in_subdir1_error.txt:Línea 2 con error
subdir1/file_in_subdir1_error.txt:Línea 3 con error
subdir1/file_in_subdir1_error.txt:Línea 4 con error
subdir1/file_in_subdir1_error.txt:Línea 5 con error
subdir1/file_in_subdir1_error.txt:Línea 6 con error
subdir1/file_in_subdir1_error.txt:Línea 7 con error
subdir1/file_in_subdir1_error.txt:Línea 8 con error
subdir1/file_in_subdir1_error.txt:Línea 9 con error
subdir1/file_in_subdir1_error.txt:Línea 11 con error
subdir1/file_in_subdir1_error.txt:Línea 12 con error
subdir1/file_in_subdir1_error.txt:Línea 13 con error
subdir1/file_in_subdir1_error.txt:Línea 14 con error
subdir1/file_in_subdir1_error.txt:Línea 15 con error
subdir1/file_in_subdir1_error.txt:Línea 16 con error
subdir1/file_in_subdir1_error.txt:Línea 17 con error
subdir1/file_in_subdir1_error.txt:Línea 18 con error
subdir1/file_in_subdir1_error.txt:Línea 19 con error
subdir1/file_in_subdir1_error.txt:Línea 21 con error
subdir1/file_in_subdir1_error.txt:Línea 22 con error
subdir1/file_in_subdir1_error.txt:Línea 23 con error
subdir1/file_in_subdir1_error.txt:Línea 24 con error
subdir1/file_in_subdir1_error.txt:Línea 25 con error
subdir1/file_in_subdir1_error.txt:Línea 26 con error
subdir1/file_in_subdir1_error.txt:Línea 27 con error
subdir1/file_in_subdir1_error.txt:Línea 28 con error
subdir1/file_in_subdir1_error.txt:Línea 29 con error
subdir1/file_in_subdir1_error.txt:Línea 31 con error
subdir1/file_in_subdir1_error.txt:Línea 32 con error
subdir1/file_in_subdir1_error.txt:Línea 33 con error
subdir1/file_in_subdir1_error.txt:Línea 34 con error
subdir1/file_in_subdir1_error.txt:Línea 35 con error
subdir1/file_in_subdir1_error.txt:Línea 36 con error
subdir1/file_in_subdir1_error.txt:Línea 37 con error
subdir1/file_in_subdir1_error.txt:Línea 38 con error
subdir1/file_in_subdir1_error.txt:Línea 39 con error
subdir1/file_in_subdir1_error.txt:Línea 41 con error
subdir1/file_in_subdir1_error.txt:Línea 42 con error
subdir1/file_in_subdir1_error.txt:Línea 43 con error
subdir1/file_in_subdir1_error.txt:Línea 44 con error
subdir1/file_in_subdir1_error.txt:Línea 45 con error
subdir1/file_in_subdir1_error.txt:Línea 46 con error
subdir1/file_in_subdir1_error.txt:Línea 47 con error
subdir1/file_in_subdir1_error.txt:Línea 48 con error
subdir1/file_in_subdir1_error.txt:Línea 49 con error
~~~
19. Extrae las últimas 50 líneas del archivo `file6_large.txt` y guarda el resultado en `output19.txt`.
~~~
$ tail -n 50 file6_large.txt > output19.txt
$ cat output19.txt
Línea 151
Línea 152
Línea 153
Línea 154
Línea 155
Línea 156
Línea 157
Línea 158
Línea 159
Línea 160
Línea 161
Línea 162
Línea 163
Línea 164
Línea 165
Línea 166
Línea 167
Línea 168
Línea 169
Línea 170
Línea 171
Línea 172
Línea 173
Línea 174
Línea 175
Línea 176
Línea 177
Línea 178
Línea 179
Línea 180
Línea 181
Línea 182
Línea 183
Línea 184
Línea 185
Línea 186
Línea 187
Línea 188
Línea 189
Línea 190
Línea 191
Línea 192
Línea 193
Línea 194
Línea 195
Línea 196
Línea 197
Línea 198
Línea 199
Línea 200
~~~
20. Lista todos los archivos, incluidos los ocultos, de forma recursiva desde el directorio actual y guarda el resultado en `output20.txt`.
~~~
$ ls -aR > output20.txt
$ cat output20.txt
.:
.
..
.hidden_dir
file1.txt
file2.csv
file3.txt
file4.txt
file5.txt
file6_large.txt
file7_duplicates.txt
out6.1.txt
out6.2.txt
output1.txt
output10.txt
output11.txt
output12.txt
output13.txt
output14.txt
output15.csv
output16.txt
output17.txt
output18.txt
output19.txt
output2.txt
output20.txt
output3.txt
output4.txt
output5.txt
output7.txt
output8.csv
output9.txt
subdir1
subdir2

./.hidden_dir:
.
..
hidden_file.txt

./subdir1:
.
..
file_in_subdir1.txt
file_in_subdir1_error.txt

./subdir2:
.
..
.hidden
file_in_subdir2.txt

./subdir2/.hidden:
.
..
hidden_file_subdir2.txt
~~~