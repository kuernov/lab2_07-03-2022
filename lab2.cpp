#include <iostream>

using namespace std;
class samochod
{
public:
    samochod(void) : bieg(1), predkosc(0), czy_silnik_wlaczony(false) {}
    void uruchom();
    void wylacz();
    void przyspiesz();
    void hamuj();
    friend void wyswietl_bieg(samochod pojazd);
    friend ostream& operator << (ostream& os, const samochod& pojazd);
private:
    bool czy_silnik_wlaczony;
    int bieg;
    int predkosc;
    void biegNastepny();
    void biegPoprzedni();
};

ostream& operator<<(ostream& os, const samochod& pojazd)
{
    cout << "Aktualny stan to: bieg = " << pojazd.bieg << ", predkosc = " << pojazd.predkosc << endl;
    return os;
}

void wyswietl_bieg(samochod pojazd)
{
    cout << "aktualny bieg: " << pojazd.bieg << endl;
    cout << pojazd.predkosc;
}

void samochod::biegNastepny()
{
    if (bieg < 6 && predkosc%20==0)
    {
        bieg++;
    }
}

void samochod::biegPoprzedni()
{
    if (bieg > 1 && predkosc % 20 != 0)
        bieg--;
}

void samochod::uruchom()
{
    czy_silnik_wlaczony = true;
}

void samochod::wylacz()
{
    czy_silnik_wlaczony = false;
}

void samochod::przyspiesz()
{
    if (czy_silnik_wlaczony == true && predkosc<100)
    {   
        predkosc += 10;
        biegNastepny();
    }
    else if (czy_silnik_wlaczony==false)
        cout << "silnik jest wylaczony!!" << endl;
}

void samochod::hamuj()
{
    if (predkosc != 0)
    {
        predkosc -= 10;
        biegPoprzedni();
    }
    else
        cout << "samochod stoi w miejscu" << endl;
}
void menu()
{
    cout << "1-Uruchom auto" << endl;
    cout << "2-Wylacz auto" << endl;
    cout << "3-przyspiesz" << endl;
    cout << "4-hamuj" << endl;
    cout << "5-wyswietl bieg" << endl;
    cout << "0-koniec" << endl;
}

int main()
{
    samochod pojazd;
    int option;
    do
    {
        menu();
        cin >> option;
        switch (option)
        {
        case 1:
            pojazd.uruchom();
            break;
        case 2:
            pojazd.wylacz();
            break;
        case 3:
            pojazd.przyspiesz();
            break;
        case 4:
            pojazd.hamuj();
            break;
        case 5:
            wyswietl_bieg(pojazd);
            break;
        case 6:
            cout << pojazd;
            break;
        }
    } while (option != 0);
    return 0;
}

