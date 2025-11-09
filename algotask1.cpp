#include <iostream>
#include <string>
using namespace std;

int main() {
    string characters = "a,a,a,b,c,d,c,e,e,f,d";
    char tchtr;
    int count = 0;

    cout << "Enter the character you want to search for: ";
    cin >> tchtr;

    for (char ch :  characters ) {
        if (ch == tchtr) {
            count++;
        }
    }

    cout << "The character '" << tchtr << "' has " << count << " times " << endl;
 cout<<"rohit roy"<<endl;
    return 0;
}
