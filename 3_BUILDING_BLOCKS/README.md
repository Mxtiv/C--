# 3_BUILDING_BLOCKS - paste-ready pieces

[⬅ main index](../README.md)

Small, self-contained pieces of code to paste into your program - every function already has the
**INF.04 comment box** (nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor).

**How to paste a block**
1. Find it below (or Ctrl+F the ID, e.g. `ARR-14`) and open the link - it jumps to the line.
2. Copy from the comment box to the end of the code (everything up to the next `//@` line).
3. The `//@` line above the block says which `#include` it needs (`-` = nothing extra). Don't copy the `//@` line itself.
4. Replace `<numer zdającego>` with your number.
5. A block that says *needs NUM-04* (etc.) calls another block - copy that one too.
6. Inside a class: drop the `(tab, n)` parameters and use the fields (see CLS-03 and ready program 01).

**Even faster - VS Code snippets:** open the whole `C--` folder in VS Code, then in any `.cpp` file type a block's name (`sortujBabelkowo`, `czyPierwsza`, `wczytajLiczbe`...) or its ID without the dash (`arr14`) and press **Tab** - the whole block with its comment box is inserted.

Every file ends with a `DEMO main()` that runs all its blocks - it's only a test, don't copy it.

## Catalog (119 blocks)

### Input / output - [01_input_output.cpp](01_input_output.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [IO-01](01_input_output.cpp#L12) | `wczytajLiczbe` | read an int from a range min..max, ask again until it fits (do-while) | &lt;iostream&gt; &lt;string&gt; |
| [IO-02](01_input_output.cpp#L34) | `wczytajLiczbeRzeczywista` | read a real number (double) from a range min..max, ask again until it fits | &lt;iostream&gt; &lt;string&gt; |
| [IO-03](01_input_output.cpp#L56) | `wczytajTekst` | read a whole line of text (with spaces) - after an earlier cin &gt;&gt; call cin.ignore(); first | &lt;iostream&gt; &lt;string&gt; |
| [IO-04](01_input_output.cpp#L72) | `zapytajTakNie` | yes/no question (t/n) -&gt; bool; use as: do { ... } while (zapytajTakNie("Jeszcze raz? (t/n): ")); | &lt;iostream&gt; &lt;string&gt; |
| [IO-05](01_input_output.cpp#L96) | `menu` | menu loop: do-while + switch, ends on 0 (put your function calls in the cases) | &lt;iostream&gt; |
| [IO-07](01_input_output.cpp#L133) | `wypiszLinie` | print a separator line, e.g. ---------- | &lt;iostream&gt; |

### Random numbers - [02_random.cpp](02_random.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [RND-01](02_random.cpp#L13) | `losujLiczbe` | random int from min..max inclusive (rand) - needs srand(time(0)) once in main | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-02](02_random.cpp#L27) | `wypelnijLosowo` | fill an array with random ints min..max (e.g. dice 1..6) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-03](02_random.cpp#L46) | `losujBezPowtorzen` | fill an array with random ints WITHOUT repeats (lotto: 6 of 1..49) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-04](02_random.cpp#L78) | `tasujTablice` | shuffle an array randomly (Fisher-Yates, manual swap) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-05](02_random.cpp#L98) | `losujRzeczywista` | random real number from min..max | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-06](02_random.cpp#L112) | `losujZnak` | random character from a given set of characters | &lt;cstdlib&gt; &lt;string&gt; |
| [RND-07](02_random.cpp#L126) | `generujHaslo` | password generator: length + options (uppercase, digits, special chars) | &lt;cstdlib&gt; &lt;string&gt; |

### Arrays - [03_arrays.cpp](03_arrays.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [ARR-01](03_arrays.cpp#L15) | `wyswietlTablice` | display every element as "index: value" (exam format) | &lt;iostream&gt; |
| [ARR-02](03_arrays.cpp#L32) | `wyswietlWLinii` | display the array in one line, separated by spaces | &lt;iostream&gt; |
| [ARR-03](03_arrays.cpp#L50) | `suma` | sum of all elements |  |
| [ARR-04](03_arrays.cpp#L69) | `srednia` | average (double - no integer division) |  |
| [ARR-05](03_arrays.cpp#L92) | `minimum` | smallest element (minimum) |  |
| [ARR-06](03_arrays.cpp#L114) | `maksimum` | largest element (maximum) |  |
| [ARR-07](03_arrays.cpp#L136) | `znajdzEkstrema` | min AND max in one pass, "returned" through &amp; parameters ("wartosci ekstremalne") |  |
| [ARR-08](03_arrays.cpp#L164) | `indeksMinimum` | INDEX of the smallest element |  |
| [ARR-09](03_arrays.cpp#L186) | `indeksMaksimum` | INDEX of the largest element |  |
| [ARR-10](03_arrays.cpp#L208) | `iloczyn` | product of all elements (long long - big results) |  |
| [ARR-11](03_arrays.cpp#L227) | `wyswietlPodzielne` | display values divisible by k AND return how many there are (exam wording) | &lt;iostream&gt; |
| [ARR-12](03_arrays.cpp#L252) | `zliczParzyste` | count elements meeting a condition (here: even) - change the if for other conditions |  |
| [ARR-13](03_arrays.cpp#L274) | `wyszukajPierwszy` | linear search: index of the FIRST occurrence or -1 |  |
| [ARR-14](03_arrays.cpp#L296) | `wyszukajWszystkie` | ALL occurrences: writes indexes into indeksy[], returns how many (0 -&gt; print -1) (exam: "zwraca indeksy lub -1") |  |
| [ARR-15](03_arrays.cpp#L324) | `zliczWystapienia` | how many times a value occurs |  |
| [ARR-16](03_arrays.cpp#L347) | `wyszukajZWartownikiem` | SENTINEL search (wartownik): array needs ONE free slot after the data (size n + 1) |  |
| [ARR-17](03_arrays.cpp#L373) | `wyszukajBinarnie` | BINARY search - the array MUST be sorted ascending |  |
| [ARR-18](03_arrays.cpp#L406) | `odwrocTablice` | reverse the array in place (manual swap) |  |
| [ARR-19](03_arrays.cpp#L425) | `zliczKazdaWartosc` | histogram: how many times each value min..max occurs (e.g. dice faces 1..6), prints it | &lt;iostream&gt; |
| [ARR-20](03_arrays.cpp#L453) | `czyPosortowana` | is the array sorted ascending? |  |
| [ARR-21](03_arrays.cpp#L474) | `usunElement` | remove the element at an index (shift left, size decreases) |  |
| [ARR-22](03_arrays.cpp#L497) | `utworzTabliceLosowa` | dynamic array: create with new[] and fill randomly (size given at runtime) - remember delete[] | &lt;cstdlib&gt; &lt;ctime&gt; |
| [ARR-23](03_arrays.cpp#L518) | `wypelnijIWyswietl2D` | 2D array: fill randomly, display as a grid, row sums (fixed number of columns) | &lt;iostream&gt; &lt;cstdlib&gt; |

### Sorting - [04_sorting.cpp](04_sorting.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [SORT-01](04_sorting.cpp#L14) | `sortujBabelkowo` | bubble sort ASCENDING (stops early when nothing was swapped) |  |
| [SORT-02](04_sorting.cpp#L46) | `sortujBabelkowoMalejaco` | bubble sort DESCENDING |  |
| [SORT-03](04_sorting.cpp#L77) | `sortujPrzezWybieranie` | selection sort ASCENDING (find the minimum, put it at position i) |  |
| [SORT-04](04_sorting.cpp#L105) | `sortujPrzezWybieranieMalejaco` | selection sort DESCENDING (find the maximum) |  |
| [SORT-05](04_sorting.cpp#L133) | `sortujPrzezWstawianie` | insertion sort ASCENDING (shift bigger elements right, insert the key) |  |
| [SORT-06](04_sorting.cpp#L158) | `sortujSzybko` | quicksort (fast, recursive) - call: sortujSzybko(tab, 0, n - 1) |  |
| [SORT-07](04_sorting.cpp#L200) | `sortujPrzezZliczanie` | counting sort - for small value ranges (e.g. grades 1..6, dice) |  |

### Number algorithms - [05_numbers.cpp](05_numbers.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [NUM-01](05_numbers.cpp#L15) | `czyPierwsza` | is n a prime number? (checks divisors up to sqrt(n)) |  |
| [NUM-02](05_numbers.cpp#L39) | `sitoEratostenesa` | sieve of Eratosthenes: print all primes &lt;= n (n &lt;= 10000), return how many | &lt;iostream&gt; |
| [NUM-03](05_numbers.cpp#L73) | `wypiszPierwszeWPrzedziale` | print primes in a range a..b (needs NUM-01) | &lt;iostream&gt; |
| [NUM-04](05_numbers.cpp#L97) | `nwd` | NWD (GCD) - Euclid, modulo version (fast) |  |
| [NUM-05](05_numbers.cpp#L118) | `nwdOdejmowanie` | NWD (GCD) - Euclid, SUBTRACTION version (exam classic) |  |
| [NUM-06](05_numbers.cpp#L152) | `nwdRekurencyjnie` | NWD (GCD) - recursive version |  |
| [NUM-07](05_numbers.cpp#L170) | `nww` | NWW (LCM) = a / NWD(a, b) * b (needs NUM-04) |  |
| [NUM-08](05_numbers.cpp#L184) | `silnia` | factorial n! with a loop (long long fits up to 20!) |  |
| [NUM-09](05_numbers.cpp#L202) | `silniaRekurencyjnie` | factorial n! recursive |  |
| [NUM-10](05_numbers.cpp#L219) | `fibonacci` | n-th Fibonacci number with a loop (F0 = 0, F1 = 1) |  |
| [NUM-11](05_numbers.cpp#L240) | `fibonacciRekurencyjnie` | n-th Fibonacci number recursive (slow for n &gt; 35) |  |
| [NUM-12](05_numbers.cpp#L257) | `wypiszCiagFibonacciego` | print the first n Fibonacci numbers | &lt;iostream&gt; |
| [NUM-13](05_numbers.cpp#L279) | `sumaCyfr` | sum of the digits of a number |  |
| [NUM-14](05_numbers.cpp#L302) | `liczbaCyfr` | how many digits a number has |  |
| [NUM-15](05_numbers.cpp#L329) | `odwrocLiczbe` | reverse the digits: 1230 -&gt; 321 |  |
| [NUM-16](05_numbers.cpp#L348) | `czyPalindromLiczbowy` | is the number a palindrome (12321)? |  |
| [NUM-17](05_numbers.cpp#L368) | `sumaDzielnikow` | sum of proper divisors (without the number itself) |  |
| [NUM-18](05_numbers.cpp#L389) | `czyDoskonala` | is it a perfect number (6 = 1+2+3, 28, 496)? |  |
| [NUM-19](05_numbers.cpp#L414) | `wypiszDzielniki` | print all divisors of n | &lt;iostream&gt; |
| [NUM-20](05_numbers.cpp#L437) | `rozkladNaCzynniki` | prime factorization: 360 = 2 * 2 * 2 * 3 * 3 * 5 | &lt;iostream&gt; |
| [NUM-21](05_numbers.cpp#L473) | `potega` | power a^b, fast (squaring), integers |  |
| [NUM-22](05_numbers.cpp#L497) | `czyArmstronga` | Armstrong / narcissistic number (153 = 1^3 + 5^3 + 3^3) |  |
| [NUM-23](05_numbers.cpp#L532) | `czyPrzestepny` | leap year? |  |
| [NUM-24](05_numbers.cpp#L549) | `naSystem` | decimal -&gt; any base 2..16 (binary, octal, hex) as text (each new digit goes in front) | &lt;string&gt; |
| [NUM-25](05_numbers.cpp#L575) | `zSystemu` | any base 2..16 -&gt; decimal (Horner's scheme) | &lt;string&gt; &lt;cctype&gt; |
| [NUM-26](05_numbers.cpp#L605) | `zaokraglij` | round to k decimal places (e.g. 3.14159 -&gt; 3.14) | &lt;cmath&gt; |

### Strings - [06_strings.cpp](06_strings.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [STR-01](06_strings.cpp#L13) | `naWielkie` | text to UPPER case | &lt;string&gt; &lt;cctype&gt; |
| [STR-02](06_strings.cpp#L30) | `naMale` | text to lower case | &lt;string&gt; &lt;cctype&gt; |
| [STR-03](06_strings.cpp#L47) | `zliczSamogloski` | count vowels (a e i o u y, any case) | &lt;string&gt; &lt;cctype&gt; |
| [STR-04](06_strings.cpp#L69) | `zliczSpolgloski` | count consonants (letters that are not vowels) | &lt;string&gt; &lt;cctype&gt; |
| [STR-05](06_strings.cpp#L94) | `zliczCyfry` | count digits in a text | &lt;string&gt; &lt;cctype&gt; |
| [STR-06](06_strings.cpp#L115) | `zliczZnak` | count occurrences of one character | &lt;string&gt; |
| [STR-07](06_strings.cpp#L137) | `zliczSlowa` | count words separated by spaces (counts where a word starts) | &lt;string&gt; |
| [STR-08](06_strings.cpp#L159) | `podzielNaSlowa` | split a text into words -&gt; string slowa[] array, returns how many | &lt;string&gt; |
| [STR-09](06_strings.cpp#L196) | `podzielWgSeparatora` | split by a separator, e.g. "Jan;17;4.5" by ';' -&gt; string czesci[] array, returns how many | &lt;string&gt; |
| [STR-10](06_strings.cpp#L228) | `odwrocNapis` | reverse a text | &lt;string&gt; |
| [STR-11](06_strings.cpp#L246) | `czyPalindrom` | palindrome check, ignoring spaces and letter case ("Kobyla ma maly bok") | &lt;string&gt; &lt;cctype&gt; |
| [STR-12](06_strings.cpp#L276) | `usunSpacje` | remove all spaces | &lt;string&gt; |
| [STR-13](06_strings.cpp#L297) | `zamienWszystkie` | replace ALL occurrences of a fragment with another (walks the text, compares with substr) | &lt;string&gt; |
| [STR-14](06_strings.cpp#L327) | `szyfrujCezarem` | Caesar cipher with any key (keeps case, other chars unchanged); decrypt = key 26 - k | &lt;string&gt; |
| [STR-15](06_strings.cpp#L358) | `deszyfrujCezarem` | Caesar decrypt (needs STR-14) | &lt;string&gt; |
| [STR-16](06_strings.cpp#L372) | `czyLiczbaCalkowita` | is the text a whole number ("123", "-45")? - check BEFORE stoi | &lt;string&gt; &lt;cctype&gt; |
| [STR-17](06_strings.cpp#L401) | `kazdeSlowoWielka` | capitalize every word: "jan kowalski" -&gt; "Jan Kowalski" | &lt;string&gt; &lt;cctype&gt; |
| [STR-18](06_strings.cpp#L425) | `inicjaly` | initials: "Jan Maria Rokita" -&gt; "JMR" | &lt;string&gt; &lt;cctype&gt; |
| [STR-19](06_strings.cpp#L446) | `zamienSlowa` | swap the two words of a 2-word text: "Jan Kowalski" -&gt; "Kowalski Jan" | &lt;string&gt; |
| [STR-20](06_strings.cpp#L474) | `czestoscLiter` | frequency of each letter a..z (prints only the letters that occur) | &lt;iostream&gt; &lt;string&gt; &lt;cctype&gt; |
| [STR-21](06_strings.cpp#L502) | `czyAnagram` | anagram check (same letters, other order: "listen" / "silent") - letter-count arrays | &lt;string&gt; &lt;cctype&gt; |
| [STR-22](06_strings.cpp#L542) | `zliczWielkieIMale` | count upper and lower case letters (results through &amp; parameters) | &lt;string&gt; &lt;cctype&gt; |

### PESEL - [07_pesel.cpp](07_pesel.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [PESEL-01](07_pesel.cpp#L16) | `czyPoprawnyFormatPesel` | is it exactly 11 digits? | &lt;string&gt; &lt;cctype&gt; |
| [PESEL-02](07_pesel.cpp#L40) | `cyfraKontrolnaPesel` | compute the control digit from the first 10 digits | &lt;string&gt; |
| [PESEL-03](07_pesel.cpp#L59) | `czyPoprawnyPesel` | full validation: format + checksum (self-contained) | &lt;string&gt; &lt;cctype&gt; |
| [PESEL-04](07_pesel.cpp#L95) | `plecZPesel` | sex from PESEL: 'K' (woman) or 'M' (man) | &lt;string&gt; |
| [PESEL-05](07_pesel.cpp#L113) | `dataUrodzeniaZPesel` | birth date from PESEL (day, month, year through &amp; parameters, all centuries) | &lt;string&gt; |

### Classes - [08_classes.cpp](08_classes.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [CLS-01](08_classes.cpp#L21) | `Osoba` | basic class: private fields, default + parameter constructor, getters, setters with validation, display | &lt;iostream&gt; &lt;string&gt; |
| [CLS-02](08_classes.cpp#L94) | `Notatka` | static counter of created objects + automatic id (id = 1, 2, 3 ...) | &lt;iostream&gt; &lt;string&gt; |
| [CLS-03](08_classes.cpp#L146) | `Tablica` | class with a DYNAMIC array: size in constructor, random fill 1..6, destructor; add methods from 03_arrays.cpp | &lt;iostream&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [CLS-04](08_classes.cpp#L223) | `TablicaStala` | class with a STATIC array of fixed size (const ROZMIAR) - fill, display, find max | &lt;iostream&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [CLS-05](08_classes.cpp#L284) | `Pojazd`, `Samochod` | inheritance: base class with protected fields, derived class calls the BASE constructor, virtual method | &lt;iostream&gt; &lt;string&gt; |
| [CLS-06](08_classes.cpp#L337) | `Figura`, `Kolo`, `Prostokat` | abstract base class (pure virtual = 0) + 2 derived classes + polymorphism through an array of Figura* | &lt;iostream&gt; &lt;string&gt; |
| [CLS-07](08_classes.cpp#L416) | `Punkt` | operators for your class: + (member), == (member), &lt;&lt; (friend, for cout) | &lt;iostream&gt; |
| [CLS-08](08_classes.cpp#L464) | `Uczen`, `wyswietlUczniow`, `najlepszyUczen` | struct + array of structs: display all, find the best by a field | &lt;iostream&gt; &lt;string&gt; |

### Files - [09_files.cpp](09_files.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [FILE-01](09_files.cpp#L14) | `zapiszDoPliku` | write an array to a text file (overwrites), numbers separated by spaces | &lt;fstream&gt; &lt;string&gt; |
| [FILE-02](09_files.cpp#L40) | `dopiszDoPliku` | append one line at the END of a file (ios::app) | &lt;fstream&gt; &lt;string&gt; |
| [FILE-03](09_files.cpp#L61) | `wczytajLiczbyZPliku` | read ALL numbers from a file into an int array, returns how many (loop: while (plik &gt;&gt; x)) | &lt;iostream&gt; &lt;fstream&gt; &lt;string&gt; |
| [FILE-04](09_files.cpp#L89) | `wczytajLinieZPliku` | read a file line by line into a string array, returns how many lines | &lt;fstream&gt; &lt;string&gt; |
| [FILE-05](09_files.cpp#L112) | `Rekord`, `wczytajRekordy` | read records "name;age;grade" (one per line) into an array of structs - getline(plik, pole, ';') | &lt;fstream&gt; &lt;string&gt; |
| [FILE-06](09_files.cpp#L156) | `czyPlikIstnieje` | does a file exist (can it be opened)? | &lt;fstream&gt; &lt;string&gt; |

### Exceptions - [10_exceptions.cpp](10_exceptions.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [EXC-03](10_exceptions.cpp#L13) | `podziel` | function that THROWS runtime_error on bad input (division by zero) + try/catch | &lt;iostream&gt; &lt;stdexcept&gt; |
| [EXC-05](10_exceptions.cpp#L39) | `sprawdzWiek` | throw an int or a string, catch each type in its own catch, catch (...) last | &lt;iostream&gt; &lt;string&gt; |

### vector - [11_vector.cpp](11_vector.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [VEC-01](11_vector.cpp#L14) | `wypelnijWektor` | fill a vector with n random ints min..max with push_back (vector passed by reference!) | &lt;vector&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [VEC-02](11_vector.cpp#L34) | `wyswietlWektor` | display a vector in one line (index loop up to v.size()) | &lt;iostream&gt; &lt;vector&gt; |
| [VEC-03](11_vector.cpp#L51) | `statystykiWektora` | min, max, sum, average of a vector with one own loop (prints them) | &lt;iostream&gt; &lt;vector&gt; |

### Templates - [12_templates.cpp](12_templates.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [TPL-01](12_templates.cpp#L14) | `wiekszy` | function template: larger of two values of ANY type |  |
| [TPL-02](12_templates.cpp#L33) | `wyswietlDowolna` | function template: display an array of ANY type | &lt;iostream&gt; |
| [TPL-03](12_templates.cpp#L52) | `Para` | class template with TWO type parameters: constructor, getters, display | &lt;iostream&gt; |
| [TPL-04](12_templates.cpp#L92) | `oblicz` | function template + a full SPECIALIZATION for &lt;int, float&gt;; other types = instantiation | &lt;iostream&gt; |
