#include <iostream>
#include <string>
#include <cctype> 

// Se crea la función para definir la primera vocal interna //
char obtenerPrimeraVocalInterna(const std::string& palabra) {
    for (char c : palabra) {
        c = std::toupper(c); 
        // Se convierte a letra mayúscula en caso de requerirse
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return c;
        }
    }
    // En caso de no existir una vocal interna, se sustituye por la letra X //
    return 'X';
}

// Se defina la función para generar el RFC // 
std::string generarRFC(const std::string& apPaterno, const std::string& apMaterno, const std::string& primerNombre, int dia, int mes, int anio) {
    std::string rfc;

    // Se definen los primeros 2 caracteres del RFC //
    
    // Se obtiene la rimera letra del apellido paterno (1era posición) //
    rfc += std::toupper(apPaterno[0]); 
    // Se obtiene la primera vocal interna del apellido paterno (2da posición) //
    rfc += obtenerPrimeraVocalInterna(apPaterno); 

    // Se obtiene la inicial del apellido materno (3ra posición) //
    if (apMaterno.empty()) {
        // Si no hay apellido materno, se sustituye por la letra X //
        rfc += 'X'; 
    } else {
     // Se obtiene la inicial del apellido materno (3ra posición) //
        rfc += std::toupper(apMaterno[0]); 
    }

    // Se obtiene la inicial del nombre (4ta posición) //
    char inicialNombre = std::toupper(primerNombre[0]);
    if (inicialNombre == 'X') {
        rfc += 'X'; 
    } else {
        rfc += inicialNombre;
    }

    // Se obtienen los últimos 2 dígitos del año de nacimiento (5ta y 6ta posición) //
    rfc += std::to_string(anio % 100); 

    // Se obtienen los 2 dígitos del mes de nacimiento (7ma y 8va posición) //
    rfc += (mes < 10 ? "0" : "") + std::to_string(mes);

    // Se obtienen los 2 dígitos del día de nacimiento (9na y 10ma posición)
    rfc += (dia < 10 ? "0" : "") + std::to_string(dia);

    // Para este proyecto no se generará la homoclave //

    return rfc;
}

int main() {
    std::string apellidoPaterno, apellidoMaterno, primerNombre;
    int dia, mes, anio;

    // Se registran los datos del empleado //
    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Ingrese el apellido materno (si no tiene, pulse ENTER para omitir: ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Ingrese el primer nombre: ";
    std::getline(std::cin, primerNombre);
    std::cout << "Ingrese el dia de nacimiento (dd): ";
    std::cin >> dia;
    std::cout << "Ingrese el mes de nacimiento (mm): ";
    std::cin >> mes;
    std::cout << "Ingrese el año de nacimiento (yyyy): ";
    std::cin >> anio;

    // Se calcula el RFC y se imprime el resultado //
    std::string rfcGenerado = generarRFC(apellidoPaterno, apellidoMaterno, primerNombre, dia, mes, anio);
    std::cout << "RFC: " << rfcGenerado << std::endl;

    return 0;
}
