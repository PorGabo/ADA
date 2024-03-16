#include <iostream>
using namespace std;

// Funciones de operación
float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0) 
        return a / b;
    else
    {
        cerr << "Error: Division by zero!" << endl;
        return 0; // Se devuelve 0 en caso de división por cero
    }
}

// User type to simplify the declaration
typedef float (*lpfnOperation)(float, float);

int main()
{
    // CVector of pointer to functions
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};

    float a, b, c;
    int opt;

    // Introducir los operandos
    cout << "Enter the operands: ";
    cin >> a >> b;

    // Introducir la operación 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
    cout << "Enter the operation (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    cin >> opt;

    // Verificar la validez de la opción
    if (opt >= 0 && opt < 4) {
        // Llamar a la función de operación seleccionada a través del puntero de función
        c = (*vpf[opt])(a, b);
        cout << "Result: " << c << endl;
    } else {
        cerr << "Error: Invalid operation!" << endl;
    }

    return 0;
}
