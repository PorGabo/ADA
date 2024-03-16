#include <iostream>
#include <cstdlib> // Necesario para utilizar realloc
using namespace std;

// Class CVector definition
class CVector
{
    private:
        int *m_pVect,
        // Pointer to the buffer
        // Control how many elements are actually used
        // Control how many are allocated as maximum
        // To control the growing
        m_nCount,
        m_nMax,
        m_nDelta;
        void Init(int delta); // Init our private variables, etc
        void Resize();        // Resize the vector when occurs an overflow
    public:
        CVector(int delta = 10);  // Constructor
        void Insert(int elem);    // Insert a new element
        int GetCount();
        int GetElement(int index);
        // More methods go here
};

CVector::CVector(int delta)
{
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

void CVector::Insert(int elem)
{
    if( m_nCount == m_nMax )    // Verify the overflow
        Resize();               // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize()
{
    const int delta = 10;
    int *new_gpVect = new int[m_nMax + delta];
    for (int i = 0; i < m_nCount; ++i)
        new_gpVect[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = new_gpVect;
    m_nMax += delta;
}

// Método para obtener el número de elementos
int CVector::GetCount()
{
    return m_nCount;
}

// Método para obtener un elemento en una posición específica
int CVector::GetElement(int index)
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        return -1;
}

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
