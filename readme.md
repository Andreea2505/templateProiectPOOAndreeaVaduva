# Sistem de management pentru cabinet veterinar – Proiect OOP

## Descriere generală
Aplicația reprezintă un sistem de management pentru un cabinet veterinar. Aceasta permite administrarea persoanelor (clienți și medici), gestionarea animalelor, administrarea stocului de medicamente, efectuarea consultațiilor și generarea de statistici despre sistem. Interacțiunea cu utilizatorul se realizează prin intermediul unui meniu în consolă.

---

# Prezentarea claselor

## 1. Ierarhia Persoanelor

### Clasa Persoana
Clasa de bază pentru toate tipurile de persoane din sistem.

Atribute:
- nume
- telefon

Metode:
- constructor și destructor virtual
- funcția de afișare a datelor
- funcția de obținere a numelui

Clasa servește drept bază pentru clasele Client și MedicVeterinar.

---

### Clasa Client (moștenire virtuală din Persoana)
Reprezintă proprietarii animalelor.

Atribute:
- id client
- adresă
- vector de animale
- număr total de clienți (atribut static)

Funcționalități:
- adăugarea unui animal
- afișarea informațiilor despre client
- contorizarea clienților existenți

---

### Clasa MedicVeterinar (moștenire virtuală din Persoana)
Reprezintă medicii veterinari din sistem.

Atribute:
- salariu
- specializare

Funcționalități:
- afișarea datelor medicului
- obținerea salariului și a specializării

---

### Clasa MedicClient – moștenire multiplă (diamant)
Această clasă moștenește atât Client, cât și MedicVeterinar. Reprezintă o persoană care este simultan client al clinicii și medic veterinar.

---

## 2. Ierarhia Animalelor

### Clasa Animal (clasă abstractă)
Clasa de bază pentru toate animalele.

Atribute:
- id
- nume
- vârstă
- proprietar
- număr total de animale (static)

Metode:
- funcție virtuală de afișare
- funcție virtuală pură pentru calculul costului consultației

Fiind clasă abstractă, nu poate fi instanțiată direct.

---

### Clasa Mamifer (moștenește Animal)
Adaugă atributul:
- are blană

Costul consultației depinde de existența blănii.

---

### Clase derivate din Mamifer

Carnivor
- adaugă tipul de carne consumat
- costul consultației crește cu 20%

Erbivor
- adaugă tipul de plante consumate
- costul consultației scade cu 10%

---

### Alte clase derivate din Animal

Pasare
- adaugă anvergura aripilor
- costul consultației depinde de aceasta

Reptila
- adaugă informația despre venin
- costul diferă în funcție de periculozitate

---

## 3. Medicamente și consultații

### Clasa Medicament
Gestionează informațiile despre medicamentele din stoc:
- nume
- cantitate

Include constructor de copiere și operator de atribuire.

---

### Clasa Stoc
Gestionează colecția de medicamente:
- adăugare medicamente
- căutare medicament
- actualizare stoc
- afișare stoc

---

### Clasa Consultatie
Leagă:
- un animal
- un medic veterinar
- un medicament din stoc

Rolul acestei clase este simularea unei consultații și actualizarea stocului.

---

## 4. Clasa Meniu (Singleton)
Clasa Meniu controlează întreaga aplicație și implementează design pattern-ul Singleton. Există o singură instanță a meniului care gestionează:
- vectorul de animale
- vectorul de persoane
- stocul de medicamente

---

# Structuri de moștenire utilizate

## Moștenire pe mai multe nivele

Animal → Mamifer → Carnivor / Erbivor

Această structură permite reutilizarea logicii comune și specializarea progresivă a claselor.

---

## Moștenirea în diamant

Persoana este clasa de bază pentru:
- Client
- MedicVeterinar

Clasa MedicClient moștenește ambele clase, ceea ce creează forma de diamant.

        Persoana
        /      \
    Client   MedicVeterinar
        \      /
        MedicClient

### Problema diamantului
Fără moștenire virtuală, obiectul MedicClient ar conține două copii ale clasei Persoana:
- una moștenită prin Client
- una moștenită prin MedicVeterinar

Acest lucru ar genera:
- duplicarea atributelor nume și telefon
- ambiguități la apelul metodelor din Persoana
- consum inutil de memorie

### Soluția implementată

class Client : virtual public Persoana  
class MedicVeterinar : virtual public Persoana  

Prin această abordare:
- există o singură instanță Persoana în obiectul final
- ambiguitățile sunt eliminate
- memoria este utilizată eficient

Utilizarea moștenirii diamant demonstrează aplicarea corectă a moștenirii multiple și rezolvarea unei probleme clasice din programarea orientată pe obiect.

---

# Excepții și validări

Aplicația utilizează o clasă personalizată de excepții: UserInputError.

Validări implementate:
- verificarea introducerii numerelor
- validarea formatului telefonului
- validarea ID-urilor pozitive
- verificarea unicității ID-urilor
- validarea vârstei animalelor
- verificarea vectorilor goi
- verificarea indexului valid

Toate erorile sunt tratate folosind blocuri try-catch în meniu.

---

# Meniul aplicației

1. Adăugare persoană  
2. Adăugare animal  
3. Afișare stoc  
4. Adăugare medicament  
5. Efectuare consultație  
6. Afișare date complete  
7. Ștergere animal  
8. Statistici  
9. Actualizare stoc medicament  
0. Ieșire  

---

# Fluxul aplicației

1. Programul pornește și creează instanța Singleton a meniului.
2. Utilizatorul interacționează prin meniu.
3. Datele sunt validate și salvate în colecții.
4. Consultațiile utilizează animalele, medicii și stocul.
5. Se pot genera statistici.
6. La închidere se eliberează memoria.

---


