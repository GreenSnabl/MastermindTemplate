#include "Mastermind.h"
using std::cout;
using std::cin;
using std::vector;
using std::string;



void clear_int_stream() {
    if (cin.fail()) {
        cin.clear();
        for (char ch; cin >> ch;)

                return;
    }
}

int get_int() {
    int input = 0;                      
    while (true) {
        if (cin >> input) return input;
        clear_int_stream();
        return -1;
    }
}

int get_int(int low, int high) {
    while (true) {
        int n = get_int();
        if (low <= n && n <= high) return n;
        else {cin.ignore(1000, '\n'); cout << "\nKeine Gültige Eingabe!\n\n"; return -1;}
    }

}






/*/
void Mastermind::chooseMode()
{
    int select;
    cout << "Wählen Sie den Spielmodus:\n(1) Zahlencode\n(2) Buchstabencode\n";
    select = get_int(1,2);
    switch (select)
    {
        case 1: case 2: play(select); break;
        case 3: return;
    }
}
*/

