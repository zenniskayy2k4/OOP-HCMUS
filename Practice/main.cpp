#include "CDoiBong.h"
int main()
{
    CDoiBong db;
    db.Input();
    db.IncreasingSquadNumber("output.txt");
    ofstream outFile("OldestPlayer.txt", ios::trunc);
    db.oldestFootballer().Output(outFile);
}