#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;

struct Clerk
{
    char surname[32];
    int birthday[3];
    int experience;
};

Clerk* AddStruct(Clerk* Obj, const int amount);
void setData(Clerk* Obj, const int amount);
void showData(const Clerk* Obj, const int amount);
Clerk* findMaxExp(Clerk* Obj, const int amount);
void writeToTxt(Clerk* Obj, const int amount);

int main()
{
    setlocale(LC_ALL, "");

    Clerk* OurClerks = 0;
    int clerksAmount = 0;
    int YesOrNot = 0;

    do
    {
        OurClerks = AddStruct(OurClerks, clerksAmount);
        setData(OurClerks, clerksAmount);

        clerksAmount++;

        cout << "Continue input (1 - yep, 0 - nope): ";
        cin >> YesOrNot;
        cin.get();
    }
    while (YesOrNot != 0);

    system("cls");

    Clerk* coolestClerk = new Clerk;
    coolestClerk = findMaxExp(OurClerks, clerksAmount);

    showData(OurClerks, clerksAmount);
    cout << "The most experienced clerk:" << '\n' << endl;
    showData(coolestClerk, 1);
    writeToTxt(OurClerks, clerksAmount);

    delete coolestClerk;
    delete[] OurClerks;
    return 0;
}

Clerk* AddStruct(Clerk* Obj, const int amount)
{
    if (amount == 0)
    {
        Obj = new Clerk[amount + 1];
    }
    else
    {
        Clerk* tempObj = new Clerk[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i];
        }
        delete [] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Clerk* Obj, const int amount)
{
    cout << "Surname: ";
    cin.getline(Obj[amount].surname, 32);
    cout << "Day of birth: ";
    cin >> Obj[amount].birthday[0];
    cout << "Month of birth: ";
    cin >> Obj[amount].birthday[1];
    cout << "Year of birth: ";
    cin >> Obj[amount].birthday[2];
    cout << "Experience: ";
    cin >> Obj[amount].experience;
    cin.get();
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Clerk* Obj, const int amount)
{

    cout << "№  " << "Surname\t" << "Birthday\t" << "Experience\t" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        wcout << i + 1 << "  " << Obj[i].surname << '\t' << Obj[i].birthday[0] << "." << Obj[i].birthday[1] << "." << Obj[i].birthday[2] << '\t' << Obj[i].experience << endl;
    }
    cout << '\n' << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Clerk* findMaxExp(Clerk* Obj, const int amount)
{
    int maxIndex = 0;
    for (int i = 1; i < amount; i++)
    {
        if (Obj[i].experience > Obj[maxIndex].experience)
            maxIndex = i;
    }
    return &(Obj[maxIndex]);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void writeToTxt(Clerk* Obj, const int amount)
{
    ofstream fout("text.txt", ios_base::out | ios_base::trunc);
    fout << "№  " << "Surname\t" << "Birthday\t" << "Experience\t" << endl;
    fout << "========================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        fout << i + 1 << "  " << Obj[i].surname << '\t' << Obj[i].birthday[0] << "." << Obj[i].birthday[1] << "." << Obj[i].birthday[2] << '\t' << Obj[i].experience << endl;
    }
    fout.close();
}
