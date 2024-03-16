#include <iostream>
#include <cstdlib> // Necesario para utilizar realloc
using namespace std;

struct Vector
{
    int *m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing
};


void Insert(Vector *pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verificar si hay overflow
        Resize(pThis); // Redimensionar el vector antes de insertar elem
    // Insertar el elemento al final de la secuencia
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector *pThis)
{
    pThis->m_pVect = (int *)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    // Aumentar en delta la cantidad máxima de elementos
    pThis->m_nMax += pThis->m_nDelta;
}

int main()
{
    Vector vec;
    vec.m_pVect = NULL;
    vec.m_nCount = 0;
    vec.m_nMax = 0;
    vec.m_nDelta = 10;

    for (int i = 1; i <= 13; ++i)
        Insert(&vec, i);

    cout << "Elementos insertados: ";
    for (int i = 0; i < vec.m_nCount; ++i)
        cout << vec.m_pVect[i] << " ";
    cout << endl;
    free(vec.m_pVect);

    return 0;
}