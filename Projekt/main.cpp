#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <conio.h>

using namespace std;
//funkcja zczytujaca dane za pomoca wektora
vector<int> read_data(istream& in, int n)
{
    vector<int> ret;

    for(int i = 0; i < n || n < 0; i++) //
    {
        int x;
        if (in >> x)
            ret.push_back(x); //
        else
            break;
    }
    return ret;
}
//funkcja sortujaca wektor
vector<int> sort_by_first_appearance(const vector<int>& vec)
{
    vector<int> ret = vec; // przypisanie wektora do zmiennej ret

    map<int, size_t> first_seen; // tworzenie mapy ktora bedzie pamietala pierwsze wystapienia elementow
    size_t idx{};
    for(auto const& element : vec)
    {
        first_seen.insert({element, idx++}); // prawidlowe przypisanie pierwszego elementu
    }

    sort(begin(ret), end(ret), [&](auto const& l, auto const& r) // posortowanie wedlug wystapeinia pierwszego elementu za pomoca funkcji sort zawartej w bibliotece algorithm
    {
        return first_seen[l] < first_seen[r]; // zwracanie posortowania
    });
    return ret; //zwraca prawidlowy wynik
}
//funkcja wyswietlajaca wektor
void display_vec(const vector<int>& vec) // funckja wyswietlajaca wektor
{
  for(int v : vec)
    {
        cout << v << " ";
    }
}
//funkcja sprawdzajaca poprawnosc algorytmu liczb ponizej
void run_tests() // fucnkja sprawdzajaca liczby
{
    vector<int> a = {4,2,4,11,4,5,2,3,1,2,1};
    vector<int> b = {4,4,4,2,2,2,11,5,3,1,1};

    auto a_sorted = sort_by_first_appearance(a);

    cout << "Do posortowania: " << endl;
    display_vec(a);
    cout << endl;
    cout << "Po posortowaniu: " << endl;
    display_vec(a_sorted);
    cout << endl;
    cout << "Oczekiwano: " << endl;
    display_vec(b);
    cout << endl;
    cout << "Wynik: " << boolalpha << (a_sorted == b) << endl; // sprawdza czy "posortowany" wektor zgadza sie z wprowadzanym wektorem testowanym wektorem. jesli tak wypisze true, w przeciwnym wypadku false
}

int main()
{
    ofstream plik("wyniki.txt"); // deklarowanie pliku
    char choice;
    cout << "Wybierz tryb:" << endl;
    cout << " 1. Liczby z klawiatury" << endl;
    cout << " 2. Liczby z pliku" << endl;
    cout << " 3. Testuj" << endl;

    vector<int> nums;

    choice=getch();
    switch(choice) // switch ktory pozwala wybrac co mozemy zrobic
    {
    case '1':
    {
        int n;
        cout<<endl;
        cout << """Podaj ile liczb(przy wprowadzeniu '-1' wczyta liczby, az sie skoncza"<<endl<<"[aby zakonczyc wprowadzanie liczb wpisz 'break']): ";
        cin >> n;
        cout << "Podaj " << n << " liczb: " << endl;
        nums = read_data(cin, n);
        break;
    }
    case '2':
    {
        string file_name;
        cout << "Podaj nazwe pliku: " << endl;
        cin >> file_name;
        ifstream file(file_name);
        nums = read_data(file, -1);
        break;
    }
    case '3':
        run_tests();
        return 0;
    default:
        cout << endl;
        cout << "Bledny wybor!" << endl;
        return 0;
    }
    auto nums_sorted = sort_by_first_appearance(nums);
    for (vector<int>::iterator it=nums_sorted.begin(); it!=nums_sorted.end(); it++) // petla wypisujaca wektor do pliku
        plik<<' '<<*it;
    cout << "Do posortowania: " << endl;
    display_vec(nums);
    cout << endl;
    cout << "Po posortowaniu: " << endl;
    display_vec(nums_sorted);
    cout << endl;
}
