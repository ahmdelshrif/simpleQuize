#include <iostream>
#include <cstdlib>
using namespace std;
enum ChekEnum { warka, topa, makas };
int Readraoud(string massage)
{
    int num;
    cout << massage;
    cin >> num;
    cout << "\n";
    return num;
}
ChekEnum Readrand(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;
    return ChekEnum(randnum);
}
ChekEnum Readfromuser()
{
    int player;
    cout << "chose number : " << "  [0] warka " << "  [1]topa " << "  [2]makas " <<"?";
    cin >> player;
    return (ChekEnum)player;
}
void wannnerorlosr(ChekEnum player, ChekEnum user ,int num, int &wanner ,int &loser ,int &fiar)
{
    
  
        if ((player == ChekEnum::warka) && (user == ChekEnum::topa))
        {
            cout << "\nYou are Winner\n"<< endl << "------------------------------------" << endl;
            system("color 2F");
            wanner=wanner+1;
        }
        else if ((player == ChekEnum::makas) && (user == ChekEnum::topa))
        {
            cout << "\nYou are Loser\n "<< endl << "-----------------------------------" << endl;
            system("color 4F");
            loser=loser+1;
        }
        else if ((player == ChekEnum::topa) && (user == ChekEnum::topa))
        {
            cout << "\nYou and user Fiar\n " << endl << "--------------------------------" << endl;
            fiar=fiar+1;
            system("color 3F");
        }
        else if ((player == ChekEnum::warka) && (user == ChekEnum::makas))
        {
            cout << "\nYou are Loser\n"<< endl << "-----------------------------------" << endl;
            system("color 4F");
            loser=loser+1;
        }
        else if ((player == ChekEnum::topa) && (user == ChekEnum::makas))
        {

            cout << "\nYou are Winner\n "<< endl << "-----------------------------------" << endl;
            system("color 2F");
            wanner=wanner+1;
        }
        else if ((player == ChekEnum::makas) && (user == ChekEnum::makas))
        {
            cout << "\nYou and user Fiar\n " << endl << "-----------------------------------" << endl;
            fiar=fiar+1;
            system("color 3F");
        }
        else if ((player == ChekEnum::topa) && (user == ChekEnum::warka))
        {
            cout << "\nYou are Loser\n"<< endl << "--------------------------------------" << endl;
            system("color 4F");
            loser=loser+1;
        }
        else if ((player == ChekEnum::makas) && (user == ChekEnum::warka))
        {

            cout << "\nYou are Winner \n"<< endl << "-------------------------------------" << endl;
            system("color 2F");
            wanner=wanner+1;
        }
        else if ((player == ChekEnum::warka) && (user == ChekEnum::warka)) {
            cout << "\nYou and user Fiar \n" << endl << "-------------------------------------" << endl;
            fiar = fiar + 1;
            system("color 3F");
        }
    
}
void StartGame()
{
    
    bool A;
    do {
        int winner = 0; int loser = 0; int fir = 0;
        int num = Readraoud("how many to want play round ?");
        int counter = 1;
        for (num; num > 0; num--) {
            cout << "Round [" << counter << "] Is Start GO :) " << "\n" << endl;
            ChekEnum randpaly = Readrand(0, 2);
            ChekEnum player = Readfromuser();
            cout << "\nUser chose : " << randpaly << endl;
            wannnerorlosr(player, randpaly, num, winner, loser, fir);
            counter++;
        }
        cout << "\t------------------------------------------------------" << endl;
        cout << "\t the game over :( " << endl;
        cout << "\t------------------------------------------------------" << endl;
        cout << "\t-----------------[Game Resulte]-----------------------" << endl;
        cout << "\tYou wanner Game  : " << winner << endl;
        cout << "\tYou loser Game   : " << loser << endl;
        cout << "\tYou fair Game    : " << fir << "\n" << endl;
        if (winner > loser)
        {
            cout << "\tYou are won :)"<<endl;
        }
        else if(loser>winner)
        {
            cout << "\tYou are loser:("<<endl;
        }
        else {
            cout << "\tNO WON You And computer Loser HAHAHAHAH"<<endl;
        }
        cout << "\t-----------------------------------------------------" << endl;
        cout << "\tDo You Want Play Agein ? " << "Y/N" << endl;
        cin >> A;

    } while (A == 1);
       
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}
