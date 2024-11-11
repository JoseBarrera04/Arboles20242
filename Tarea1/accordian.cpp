/**
 * @author Jose Barrera Ramos
 * Ingenieria en Sistemas
 * Accordian - Tarea 1
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void procesarCartas(vector<stack<string>>& baraja, int& i);
void printResultado(vector<stack<string>>& baraja);

/**
 * @brief
 */
int main() {
    string carta = "";
    bool flag = false;

    while(flag == false) {
        vector<stack<string>> baraja(52);
        for(int i = 0; i < 52 && flag == false; i++) {
            cin >> carta;
            if(carta == "#") {
                flag = true;
            } else {
                baraja[i].push(carta);
            }
        }

        for(int i = 0; i < baraja.size() && flag == false;) {
            procesarCartas(baraja, i);
        }

        if(flag == false) {
            printResultado(baraja);
        }
    }
    return 0;
}

/**
 * @brief Se procesan las cartas según las reglas del juego
 * @param baraja Una lista de pilas que representa las pilas de cartas
 * @param i Posicion de la lista de pilas
 */
void procesarCartas(vector<stack<string>>& baraja, int& i) {
    if(i - 3 >= 0 && (baraja[i].top()[0] == baraja[i - 3].top()[0] || baraja[i].top()[1] == baraja[i - 3].top()[1])) {
        baraja[i - 3].push(baraja[i].top());
        baraja[i].pop();
        if(baraja[i].empty()) {
            baraja.erase(baraja.begin() + i);
        }
        i -= 3;
    } else if(i - 1 >= 0 && (baraja[i].top()[0] == baraja[i - 1].top()[0] || baraja[i].top()[1] == baraja[i - 1].top()[1])) {
        baraja[i - 1].push(baraja[i].top());
        baraja[i].pop();
        if(baraja[i].empty()) {
            baraja.erase(baraja.begin() + i);
        }
        i -= 1;
    } else {
        i++;
    }
}

/**
 * @brief Imprime el resultado
 * @param baraja Una lista de pilas que representa las pilas de cartas
 */
void printResultado(vector<stack<string>>& baraja) {
    string numStacks = "";

    int sizeBaraja = baraja.size();
    for(int i = 0; i < sizeBaraja; i++) {
        numStacks += to_string(baraja[i].size());
        if(i != sizeBaraja - 1) numStacks += " ";
    }

    cout << endl;
    if(sizeBaraja == 1) {
        cout << sizeBaraja << " pile remaining: " << numStacks << endl;
    } else {
        cout << sizeBaraja << " piles remaining: " << numStacks << endl;
    }
}