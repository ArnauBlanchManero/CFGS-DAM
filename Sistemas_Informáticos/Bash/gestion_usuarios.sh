#!/bin/bash

# Menú
eleccion=0

while ((eleccion != 4)) # Hasta que no pongas 4 para salir, el menú se repite
do
    echo -e "¿Qué acción quieres hacer?\n1. Crear usuario\n2. Eliminar usuario\n3. Listar todos los usuarios\n4. Salir\nOpción: "
    read eleccion  # Se espera que escribas 1, 2, 3 o 4

    case $eleccion in
        1)
            # Crear usuarios y asignarlos a un grupo
            echo "Nombre del usuario: "
            read usuario
            echo "Grupo del usuario: "
            read grupo

            sudo adduser $usuario   # Se necesita sudo para crear un usuario
            sudo groupadd $grupo 2>/dev/null # Solo si el grupo no existe
            sudo usermod -aG $grupo $usuario # Añadir el usuario al grupo
            ;;
        2)
            # Eliminar usuarios
            echo "Nombre del usuario a eliminar: "
            read usuario
            sudo userdel -r $usuario  # Se necesita sudo para eliminar un usuario
            ;;
        3)
            # Listar usuarios y su información
            cat /etc/passwd  # No necesita sudo
            ;;
        4)
            echo "Saliendo..." # Simplemente sale
            ;;
        *)
            # El asterisco maneja opciones inválidas
            echo "Opción inválida, introduce 1, 2, 3 o 4"
            ;;
    esac
done

