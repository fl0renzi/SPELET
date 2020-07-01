#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;
int bets;// Lagrar alla insatser som spelaren gör
int startingmoney = 1000; // Startkassan som användaren får, i detta fall enligt uppgift 1000kr
int winner;// variable för att lagra vinnade spel
int loser; // variable för att lagra förlorade spel
int number; // variable för när användare väljer ett nummer mellan 1-36
bool continueplay = true; // bool för att spelet ska loopa hela tiden
int const minnumber = 1, maxnumber = 36; // konstanter för att slumpa nummer
int random; // lagrar de slumpmässiga numret
string val; // variable om användaren vill fortsätta spela

// numbersgame för funktionen för 1-36 spelet
void numbersgame() {
    srand(time(nullptr));
    random = rand() % (maxnumber - minnumber + 1) + minnumber; // Funktion för att slumpmässigt genera ett tal 1-36
    cout << "V\x84lj en siffra mellan 1-36 :" << endl;
    cin >> number;
    cout << "Siffran \x84r "; cout << random;
    cout << "\n";

    // IF-sats som kollar ifall spelaren har vunnit samt ökar kassa med 10ggr pengarna
    if (random == number)//
    {
        winner = bets * 10 + startingmoney;
        startingmoney = winner;
        cout << "Du har vunnit!" << endl;
        cout << "Din kassa har \x94kat med ";
        cout << bets * 10;
        cout << "kr" << endl;

    // Om siffran inte stämmer dras bettet av kassan
    } else {
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora denna omg\x86ngen!" << endl;
        cout << "Din kassa har minskat med ";
        cout << bets;
        cout << "kr" << endl;
    }
    // Kontroll fråga om användaren vill forsätta spela annars stängs progammet ner
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

// Kollar ifall siffrarn är ett jämt nummer vilket i detta spel resulterar i en vinst
    if (random % 2 == 0) {

        cout << random << " vilket \x84r ett j\x84mt nummer";
        cout << "\n";
        winner = startingmoney + bets * 2;
        startingmoney = winner;
        cout << "Du vann ";
        cout << bets * 2;
        cout << "kr" << endl;
// Om siffran inte är ett jämt nummer så måste siffran vara ojämn
    } else {
        cout << random << " vilket \x84r ett oj\x84mt nummer";
        cout << "\n";
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora ";
        cout << bets;
        cout << "kr" << endl;
    }
    // Kontroll fråga om användaren vill forsätta spela annars stängs progammet ner
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
    // Funktion för att genera ett nummer mellan 1-36
    srand(time(nullptr));
    random = rand() % (maxnumber - minnumber + 1) + minnumber;
    cout << "Siffran \x84r ";
   // Kollar ifall siffrarn är ett jämt nummer vilket i detta spel resulterar i en förlust
    if (random % 2 == 0) {
        cout << random << " vilket \x84r ett j\x84mt nummer";
        cout << "\n";
        loser = startingmoney - bets;
        startingmoney = loser;
        cout << "Du f\x94lora ";
        cout << bets;
        cout << "kr" << endl;
      //  Om siffran inte är ett jämt nummer så måste siffran vara ojämn vilket ger en vinst
    } else {
        cout << random << " vilket \x84r ett oj\x84mt nummer";
        cout << "\n";
        winner = startingmoney + bets * 2;
        startingmoney = winner;
        cout << "Du vann ";
        cout << bets * 2;
        cout << "kr" << endl;
    }
    // Kontroll fråga om användaren vill forsätta spela annars stängs progammet ner
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
        // Välkomsmeddelande för användaren som bara visar spelet en gång
        cout << "<<<--- V\x84lkommen till Roulette spelet ! --->>>" << endl;
        cout << "<<<--- Gjort av Johan Elvemo version 0.1 pre alpha --->>>" << endl;
        // While loop som gör att spelaren kan spela flera gånger
        while (continueplay) {
          // Kontroll för att kolla ifall användaren har några pengar kvar
            if (startingmoney <= 0) {
                cout << "Slut p\x86 pengar!";
                exit(0); //
            }
        // Användaren placerar ett bet
            cout << "Du har " << startingmoney;
            cout << "kr kvar att spela f\x94r" << endl;
            cout << "Placera ett bet: 100,300 eller 500 " << endl;
            cin >> bets;
        // Kollar ifall bettet är större än vad användaren har i kassan    
            if (bets > startingmoney) {

                cout << "Du har inte cash for det" << endl;
                cout << "Avslutar programmet for din skull";
                exit(0);
                
            } else {
                // Kontrollerar att bettet är 100,300 eller 500kr och programmet fortsätter inte förräns rätt summa är anvigen
                while (bets != 100 && bets != 300 && bets != 500) {
                    cout << "Du m\x86ste ange 100, 300 eller 500kr " << endl;
                    cout << "F\x94rsok igen" << endl;

                    cin >> bets;
                }
            }
            /* Meny för att bestämma vilken typ av spel som användaren vill spela
               Går även att avsluta programmet från denna meny
               */
            cout << endl
                 << "1 - Straight up Ett singelspel p\x86 valfritt nummer.\n"
                 << " 2 - Spela p\x86 j\x84mna nummer - Svart. \n"
                 << " 3 - Spela p\x86 oj\x84mna nummer - Rod. \n"
                 << " 4 - Avsluta programmet.\n"
                 << " G\x94r ett val (1-4)";
            cout << " och bekrafta med Enter";
            cout << "\n";

            // När användare har gjort ett val går det till denna Swtich meny som anropar olika funktion för de olika spelen
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
