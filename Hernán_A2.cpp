#include <iostream>
using namespace std;

int main() {
    char Continuar;  /* Variable que determina si el programa debe de
    continuar la ejecución */
    
    do {
        // Se definen las variables para ingresar los 2 valores requeridos
        double número1, número2;

        // Se le solicita al usuario el ingreso del primer valor
        cout << "Escribe el primer número: ";
        cin >> número1;

        // Se le solicita al usuario el ingreso del segundo valor
        cout << "Escribe el segundo número: ";
        cin >> número2;

        // Se realizan las operaciones aritméticas básicas
        double suma = número1 + número2;
        double resta = número1 - número2;
        double multiplicación = número1 * número2;
        double división;

        // Se verifica que el divisor no sea cero
        if (número2 != 0) {
            división = número1 / número2;
            
        } else {
            
            // Se muestra un mensaje de error //
            cout << "Error: No es posible dividir entre 0." << endl;
            división = 0; 
        }

        // Se realiza la impresión de los resultados //
        cout << "La suma es: " << suma << endl;
        cout << "La resta es: " << resta << endl;
        cout << "La multiplicación es: " << multiplicación << endl;
        cout << "La división es: " << división << endl;

        // Preguntar al usuario si desea realizar otra operación //
        cout << "¿Deseas realizar otra operación? (s/n): ";
        cin >> Continuar;

        // Se le pregunta la usuario si requiere realizar otra operación //
    } while (Continuar == 'S' || Continuar == 's');  

    return 0;
}
