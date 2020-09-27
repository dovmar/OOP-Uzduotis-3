# OOP-Uzduotis-1 v0.2

### Naudojimosi instrukcija

Programa gali nuskaityti studentų duomenis iš failų kuriuose:
- Stulpeliai atskirti tarpais
- 1 ir 2 stulpeliai yra studento vardas ir pavardė
- n sekančių stulpelių skirta namų darbų pažymiams
- Paskutinis stulpelis skirtas egzamino pažymiui

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
