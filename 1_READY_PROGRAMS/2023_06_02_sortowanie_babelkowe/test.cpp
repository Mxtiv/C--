// INF.04-02-23.06-SG part III - the TEST fragment of main() (sheet: folder "testy", file "test").
// It is the part of main.cpp between "===== test" and "end of test" - copy it into main().

    int tablica[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
    {
        tablica[i] = rand() % 1001;                // liczby całkowite dodatnie 0..1000
    }

    sortujBabelkowo(tablica, ROZMIAR);

    cout << "Tablica posortowana rosnaco:" << endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;

    bool posortowana = true;
    for (int i = 0; i < ROZMIAR - 1; i++)
    {
        if (tablica[i] > tablica[i + 1])
        {
            posortowana = false;
        }
    }
    cout << "Test sortowania: " << (posortowana ? "OK - tablica jest posortowana" : "BLAD") << endl;
