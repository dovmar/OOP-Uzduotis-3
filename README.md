# OOP-Uzduotis-1

Programa skirta nuskaityti studentų duomenims (vardas, pavardė, namų darbų pažymiai, egzamino pažymys), apskaičiuoti ir išvesti kiekvieno studento galutinį pažymį.

[0.2 versija](https://github.com/dovmar/OOP-Uzduotis-1/releases/tag/v0.2)

[0.1 versija](https://github.com/dovmar/OOP-Uzduotis-1/releases/tag/v0.1)

### Naujausios versijos naudojimosi instrukcija

Programoje nereikia rankiniu būdu įvesti stulpelių kiekio ir patys stulpelių vardai nėra svarbūs.

Norint nuskaityti studentų duomenis iš failo, naudoti funciją **nuskaitytiFaila()**. Pvz. jeigu mūsų tinkamo formato failo vardas "studentai.txt":
```c++
nuskaitytiFaila(Stud,n,"studentai.txt");
```

Studentų rezultatai įrašomi į failą su **isvestiFaila()**.
```c++
isvestiFaila(Stud,n);
```

Duomenys nebūtinai turi būti ir įvedami iš failo ir rezultatai išvedami į failą. Pvz. duomenis galima įvesti ranka ir tada rezultatus įrašyti į failą arba atvikščiai.
```c++
int n;
vector <duomuo> Stud;
ivedimas(Stud,n);
isvestiFaila(Stud,n);
```
