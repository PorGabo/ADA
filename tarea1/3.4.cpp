#include <iostream>
#include <cstdlib> // Necesario para utilizar realloc
using namespace std;

// Clase CVector
class CVector
{
private:
    int *m_pVect; // Puntero al buffer
    int m_nCount; // Controla cuántos elementos se están usando
    int m_nMax;   // Controla cuántos elementos se han asignado como máximo
    int m_nDelta; // Controla el incremento del tamaño

    void Init(int delta)
    {
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
        m_nDelta = delta;
    }

    void Resize()
    {
        const int delta = 10;
        int *new_pVect = new int[m_nMax + delta];
        for (int i = 0; i < m_nCount; ++i)
            new_pVect[i] = m_pVect[i];
        delete[] m_pVect;
        m_pVect = new_pVect;
        m_nMax += delta;
    }

public:
    // Constructor
    CVector(int delta = 10) {
        Init(delta);
    }

    // Destructor
    ~CVector() {
        delete[] m_pVect;
    }

    // Método para insertar un nuevo elemento en el vector
    void Insert(int elem) {
        if (m_nCount == m_nMax) // Verificar desbordamiento
            Resize();            // Redimensionar el vector antes de insertar elem
        m_pVect[m_nCount++] = elem; // Insertar el elemento al final del vector
    }

    // Método para obtener el número de elementos
    int GetCount() const {
        return m_nCount;
    }

    // Método para obtener un elemento en una posición específica
    int GetElement(int index) const {
        if (index >= 0 && index < m_nCount)
            return m_pVect[index];
        else
            return -1;
    }
};

int main()
{
    CVector vec;

    for (int i = 1; i <= 23; ++i)
        vec.Insert(i);

    cout << "Elementos insertados: ";
    for (int i = 0; i < vec.GetCount(); ++i)
        cout << vec.GetElement(i) << " ";
    cout << endl;

    return 0;
}
