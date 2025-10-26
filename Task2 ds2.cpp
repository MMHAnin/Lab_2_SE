#include <iostream>
using namespace std;

int main()
{
    int sizeA, sizeB;

    cout << "Enter the size of the first array: ";
    cin >> sizeA;

    int A[sizeA];

    cout << "Enter " << sizeA << " elements for the first array: ";
    for (int i = 0; i < sizeA; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> sizeB;

    int B[sizeB];

    cout << "Enter " << sizeB << " elements for the second array: ";
    for (int i = 0; i < sizeB; i++)
    {
        cin >> B[i];
    }

    cout << "Common elements: ";
    bool printed = false;

    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if (A[i] == B[j])
            {

                bool alreadyPrinted = false;
                for (int k = 0; k < i; k++)
                {
                    if (A[k] == A[i])
                    {
                        alreadyPrinted = true;
                        break;
                    }
                }
                if (!alreadyPrinted)
                {
                    cout << A[i] << " ";
                    printed = true;
                }
                break;
            }
        }
    }

    if (!printed)
    {
        cout << "No common element!";
    }

    cout << endl;
    return 0;
}
