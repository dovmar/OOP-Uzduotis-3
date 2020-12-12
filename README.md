# OOP-Uzduotis-2

Programa skirta nuskaityti studentų duomenims (vardas, pavardė, namų darbų pažymiai, egzamino pažymys), apskaičiuoti ir išvesti kiekvieno studento galutinį pažymį.

## 2.0 versija

- Pridėtas doxygen aprašas klasėms
- Sukurti keli unit testai naudojant Google Test framework'ą

## Įdiegimo instrukcija

- Atsiųsti [naujausią versiją](https://github.com/dovmar/OOP-Uzduotis-2/releases/).
- Sukompiliuoti programą naudojant CMakeLists.txt failą.
- Paleisti programą.

## Naudojimosi instrukcija

- Jeigu nenorite stipriai keisti programos parametrų, tiesiog paleiskite programą ir sekite nurodymus ekrane.

- Jeigu pasirinkote programai pateikti savo failą, jis turi būti tokio formato (namų darbų kiekį programa aptiks pati):
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
Vardas2     Pavardė2    7    10    8    5    4    6
```

- Jeigu norite detaliai kontroliuoti programos veikimą, faile main.cpp vietoje 
```c++
paleisti(Stud, Stud2);
```
 galite rankiniu būdu pasirinkti su kokiais parametrais programa turėtų veikti, pavyzdžiui:
```c++
sugeneruotiFaila(1000, 10, "generuotas1000.txt");
    nuskaitytiFaila(Stud,"generuotas1000.txt");
    for (Studentas& stud : Stud) {
        naudojantMediana(stud);
        naudojantVidurki(stud);
    }
    Stud2 = padalinti3(Stud);
    isvestiFaila(Stud, "islaike.txt");
    isvestiFaila(Stud2, "neislaike.txt");
```

## Versijų istorija

## [1.5 versija](https://github.com/dovmar/OOP-Uzduotis-1/releases/tag/v1.5)

- Sukurta abstrakti Žmogus klasė
- Supaprastintas kelių funckijų kodas naudojantis klasių galimybėmis
- Ištaisytas anksčiau minėtas bug'as

## [1.2 versija](https://github.com/dovmar/OOP-Uzduotis-1/releases/tag/v1.2)

- Programos versija naudojanti Studento klasę, vietoje struktūrų.

   **DĖMESIO!** Į šį releas'ą pateko bug'as - Studento klasės copy konstructorius neperkopijuoja studento galutinių pažymių, todėl visų studentų pažymiai tampa lygus 0.

    Norint to išvengti reikia pakeisti failo studentas.cpp 87 eilutę į:

```c++
Studentas::Studentas(const Studentas& stud) : vardas_{ stud.vardas_ }, pavarde_{ stud.pavarde_ },
nd_{ stud.nd_ }, egzaminas_{ stud.egzaminas_ } {}

```

## [1.0 versija](https://github.com/dovmar/OOP-Uzduotis-1/releases/tag/v1.0)

- Naujausia programos versija naudojanti struktūras.

## Programos spartos analizė

Sparos matavimui naudotos sistemos duomenys:

```
Processor: Intel(R) Core(TM) i5-8250U CPU @ 1.60GHz, 1801 Mhz, 4 Core(s)
Memory:    6.00GB
Storage:   WDC PC SN520 SDAPMUW-256G-1101 SSD

```

Programos sparta naudojant Studentas struktūrą:

![](spartos_analizė/programos_sparta.png)



Programos sparta naudojant Studentas klasę:

![](spartos_analizė/class_sparta.png)



Programos sparta naudojant O1 flag'ą:

![](spartos_analizė/O1.png)



Programos sparta naudojant O2 flag'ą:

![](spartos_analizė/O2.png)

