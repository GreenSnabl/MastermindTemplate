#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "functions.hpp"
#include <vector>
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::vector; using std::string;


void clear_int_stream();
int get_int(int, int);

template <typename T>
class Mastermind {
public:
    Mastermind(vector<T> base, int size) : code_size{size}, codebase{base} {}
    
    T get_code_unit() {
        T temp;
        cin >> temp;
        for(int i = 0; i < codebase.size(); ++i)
            if(temp == codebase[i]) return temp;
        cout << "Ungültiger Wert!" << temp << "\n";
    }

    vector<T> get_code()
    {

        while (true) {
            vector<T> codeVec;            
            for (int i = 0; i < code_size; ++i)
                codeVec.push_back(get_code_unit());
            if (isValidInput(codeVec, code_size)) return codeVec;
            cout << "Bitte geben Sie einen gültigen Code ein!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    void play() {
        cout << "Geben Sie den Lösungscode ein:\n";
        solution = get_code();
        string flood;
        string floodsign = "#";
        for (int i = 0; i < 500; ++i) {
            flood = "";
            if (i < 250) {
                for (int j = 0; j < i; ++j)
                    flood += floodsign;
            } else {
                flood == floodsign;
                for (int j = 250; j < 749 - i; ++j)
                    flood += floodsign;
            }
            flood += floodsign + "\n\n";
            cout << flood;
        }

        for (int counter = 0; counter < 8; ++counter) {
            vector<T> guess;
            cout << "Runde " << counter + 1
                    << "\n\nWie lautet ihr Tipp?\n";
            guess = get_code();
            cout << "\n\nIhr Tipp:\t\t";
            for (int i = 0; i < code_size; ++i)
                cout << guess[i];
            cout    << "\nSchwarze Marker:\t" << black(solution, guess)
                    << "\nWeiße Marker:\t\t" << white(solution, guess) << "\n\n";
            if (guess == solution) {
                cout << "\nDer Code wurde geknackt!\n\n************************************\n*******  Spieler 2 gewinnt!  *******\n************************************\n\n\n";
                return;
            }
        }
        cout << "\nSpieler 2 konnte den Code nicht innerhalb von 8 Runden knacken. \n\nLösungscode: ";
       for (int i = 0; i < code_size; ++i)
            cout << solution[i];
        cout<<"\n\n************************************\n*******  Spieler 1 gewinnt!  *******\n************************************\n\n\n";
    }



    void help()
    {
    cout << "\t\t*** Mastermind  ---  Spielregeln  --- Spiel für 2 Personen   ***\n\n\n"
         << "\t\tZu Spielbeginn legt Spieler 1 einen 4-stelligen Lösungscode fest.\n\n"
         << "\t\tDer Lösungscode besteht aus den Ziffern \"1-6\".\n\n"
         << "\t\tJede Ziffer darf maximal einmalig verwendet werden.\n\n\n"
         << "\t\tSpieler 2 stehen nun 8 Raterunden  zur Verfügung.\n\n"
         << "\t\tNach jeder Runde erhält Spieler 2 Tipps in Form von schwarzen und weißen Markern.\n\n"
         << "\t\tEin weißer Marker zeigt an, dass eine korrekte Ziffer an einer falschen Position getippt wurde.\n\n"
         << "\t\tEin schwarzer Marker zeigt an, dass eine korrekte Ziffer an der korrekten Stelle getippt wurde.\n\n"
         << "\t\tSchafft es Spieler 2 nicht den Code innerhalb von 8 Runden zu erraten, hat Spieler 1 das Spiel gewonnen.\n\n";
    }

    void menu() {
    int select;
    cout << "..Mastermind..\n\n";
    while (true) {
        cout << "Hauptmenü\n\n"
                << "(1) Neues Spiel\n"
                << "(2) Spielregeln\n"
                << "(3) Beenden\n";
        select = get_int(1,3);
        switch (select) {
            case 1: play(); break;
            case 2: help(); break;
            case 3: return;
        }
    }
    }
        
private:
    vector<T> solution;
    vector<T> codebase;
    int code_size;

};

template <typename T>
struct Game{
    public:
    Game()
    {
    vector<int> base;
    for (int i = 1; i < 7; ++i)
        base.push_back(i);
    Mastermind<T> m(base,4);
    m.menu();
    }
    Game(vector<T> base, int size = 4)
    {
    for(int i = 0; i < base.size(); ++i)
        cout << base[i] << "\n";
    Mastermind<T> m(base, size);
    m.menu();
    }
       
};








#endif /* MASTERMIND_H */

