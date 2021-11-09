#include <iostream>
using namespace std;
  
void citire(int In[], int temp)
{
    int i;
    for (i = 0; i < temp; i++)
        cout << In[i] << "\t";
}

void mutare(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


int rep(int In[], int min, int max)
{
    int pivot = In[max];    
    int i = (min - 1);

    for (int j = min; j <= max - 1; j++)
    {
        if (In[j] <= pivot)
        {
            i++; 
            mutare(&In[i], &In[j]);
        }
    }
    mutare(&In[i + 1], &In[max]);
    return (i + 1);
}



void QuickSort(int In[], int min, int max)
{
    if (min < max)
    {
        int pivot = rep(In, min, max);
        QuickSort(In, min, pivot - 1);
        QuickSort(In, pivot + 1, max);
    }
}
int main()
{
    int In[] = { 13,22,3,87,24,53,68,23,75,25 };
    int n = sizeof(In) / sizeof(In[0]);
    cout << "Input: " << endl;
    citire(In, n);
    cout << endl<<endl;
    QuickSort(In, 0, n - 1);
    cout << "Rezultatul dupa QuickSort: " << endl;
    citire(In, n);
    return 0;
}