#include <iostream>
#include <stdio.h>

int main() 
{
    char continuar; /* Variable que determina si el programa
    debe de continuar la ejecución */

    do {
        // Se define la variable de la edad del usuario
        int edad;

        // Se le solicita al usuario que ingrese su edad
        std::cout << "¿Qué edad tiene usted?";
        std::cin >> edad;

        // Se verifica si el usuario es mayor de edad o menor
        if (edad >= 18) {
            
            /* Se confirma que el usuario es mayor de edad
            y se muestra el mensaje */
            std::cout << "Usted es mayor de edad." << std::endl;
            
        } else {
            
            /* Se identifica que el usuario es menor de edad 
            y se muestra el mensaje */
            std::cout << "Usted es menor de edad." << std::endl;
        }

        // Se le pregunta al usuario si requiere ingresar otra edad //
        std::cout << "¿Desea ingresar otra edad? (S/N):";
        std::cin >> continuar;

    } while (continuar == 'S' || continuar == 's'); 
    
    /* El programa se ejecuta nuevamente si la respuesta es 's' o 'S',
    en caso contrario, termina la ejecución */

    return 0;
}
