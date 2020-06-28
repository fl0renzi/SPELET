#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;
int bets;
int startingmoney = 1000;
int winner;
int loser;
int number;
bool continueplay = true;
int const minnumber = 1, maxnumber = 36;
int random;
string val;


void numbersgame() {
    srand(time(nullptr));
    random = rand() % (maxnumber - minnumber + 1) + minnumber;
    cout << "V\x84lj en siffra mellan 1-36 :" << endl;
    cin >> number;
    cout << "Siffran \x84r ";

    cout << random;
    cout << "\n";

    if (random == number) {
        winner = bets * 10 + startingmoney;
        startingmoney = winner;
        cout << "Du har vunnit!" << endl;
        cout << "Din kassa har \x94kat med ";
        cout << bets * 10;
        cout << "kr" << endl;


    } else {
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora denna omg\x86ngen!" << endl;
        cout << "Din kassa har minskat med ";
        cout << bets;
        cout << "kr" << endl;
    }
    cout << "Vill du spela igen? j/n ";
    cin >> val;
    if (val == "j") {
        continueplay;
    } else if (val == "n") {
        cout << "Du har valt att avsluta programmet!";
        exit(0);
    }
}

void blacknumber() // Funktion för jämna nummer
{
    srand(time(nullptr));
    random = rand() % (maxnumber - minnumber + 1) + minnumber;

    cout << "Siffran \x84r ";

    if (random % 2 == 0) {

        cout << random << " vilket \x84r ett j\x84mt nummer";
        cout << "\n";
        winner = startingmoney + bets * 2;
        startingmoney = winner;
        cout << "Du vann ";
        cout << bets * 2;
        cout << "kr" << endl;

    } else {
        cout << random << " vilket \x84r ett oj\x84mt nummer";
        cout << "\n";
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora ";
        cout << bets;
        cout << "kr" << endl;
    }
    cout << "Vill du spela igen? j/n ";
    cin >> val;
    if (val == "j") {
        continueplay;
    } else if (val == "n") {
        cout << "Du har valt att avsluta programmet!";
        exit(0);
    }
}

void rednumber() // Funktion för ojämna nummer
{
    srand(time(nullptr));
    random = rand() % (maxnumber - minnumber + 1) + minnumber;
    cout << "Siffran \x84r ";
    if (random % 2 == 0) {
        cout << random << " vilket \x84r ett j\x84mt nummer";
        cout << "\n";
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora ";
        cout << bets;
        cout << "kr" << endl;
    } else {
        cout << random << " vilket \x84r ett oj\x84mt nummer";
        cout << "\n";
        winner = startingmoney + bets * 2;
        startingmoney = winner;
        cout << "Du vann ";
        cout << bets * 2;
        cout << "kr" << endl;
    }
    cout << "Vill du spela igen? j/n ";
    cin >> val;
    if (val == "j") {
        continueplay;
    } else if (val == "n") {
        cout << "Du har valt att avsluta programmet!";
        exit(0);
    }
}


int main() {
    {

        cout << "<<<--- V\x84lkommen till Roulette spelet ! --->>>" << endl;
        while (continueplay) {
            if (startingmoney <= 0) {
                cout << "Slut p\x86 pengar!";
                exit(0); //
            }
            cout << "Du har " << startingmoney;
            cout << "kr kvar att spela f\x94r" << endl;
            cout << "Placera ett bet: 100,300 eller 500 " << endl;
            cin >> bets;
            if (bets > startingmoney) {

                cout << "Du har inte cash for det" << endl;
                cout << "Avslutar programmet for din skull";
                exit(0);
            } else {
                while (bets != 100 && bets != 300 && bets != 500) {
                    cout << "Du m\x86ste ange 100, 300 eller 500kr " << endl;
                    cout << "F\x94rsok igen" << endl;

                    cin >> bets;
                }
            }

            cout << endl
                 << "1 - Straight up Ett singelspel p\x86 valfritt nummer.\n"
                 << " 2 - Spela p\x86 j\x84mna nummer - Svart. \n"
                 << " 3 - Spela p\x86 oj\x84mna nummer - Rod. \n"
                 << " 4 - Avsluta programmet.\n"
                 << " G\x94r ett val (1-4)";
            cout << " och bekrafta med Enter";
            cout << "\n";


            int menyval;
            cin >> menyval;

            switch (menyval) {
                case 1:
                    numbersgame();
                    break;
                case 2:
                    blacknumber();
                    break;
                case 3:
                    rednumber();
                    break;
                case 4:
                    cout << "Du har valt att avsluta programmet";
                    exit(0);
                default:
                    cout << "Inget val gjort " << endl;

            }
        }
    }
}
