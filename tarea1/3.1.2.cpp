//Dynamic Vectors and global variables

#include <iostream>
using namespace std;

int *gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

void Resize()
{
    const int delta = 10;
    int *new_gpVect = new int[gnMax + delta];
    for (int i = 0; i < gnCount; ++i)
        new_gpVect[i] = gpVect[i];
    delete[] gpVect;
    gpVect = new_gpVect;
    gnMax += delta;
}

void insert(int x)
{
    if ( gnCount == gnMax )
        Resize();
    gpVect[gnCount++] = x;
}



int main()
{
    std::cout<<"hellom!"<<endl;
    for (int i = 1; i <= 13; ++i)
        insert(i);
    std::cout << "Elementos insertados: ";
    for (int i = 0; i < gnCount; ++i)
        std::cout<<gpVect[i]<<" ";
    std::cout<<endl;
    delete[] gpVect;
    return 0;
}
