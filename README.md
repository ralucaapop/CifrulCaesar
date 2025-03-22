# Cifru de substitutie: Cifrul lui Caesar

In această aplicație, cheia folosită este SHIFT = 3, ceea ce înseamnă că fiecare literă va fi deplasată cu 3 poziții în alfabet.
Alfabetul contine literele alfabetului englez(litere mari si mici)

## Instrucțiuni de compilare și utilizare

Pentru compilare:
  gcc -o caesar_cipher main.c

Pentru rulare:
  - pentru criptare:
    ./caesar_cipher -e -i input.txt -o output.txt
  - pentru decriptare:
    ./caesar_cipher -d -i input.txt -o output.txt

## Detalii despre implementare

Pentru criptare, funcția caesar_cipher adaugă valoarea cheii (3) la fiecare caracter din textul original, iar pentru decriptare, funcția scade valoarea cheii (3).
Algoritmul respectă literele mari și mici, asigurându-se că acestea rămân corect plasate în cadrul alfabetului.
  
Funcția caesar_cipher: Aplică cifra lui Caesar pe fiecare caracter din textul dat. Dacă este criptare, adaugă valoarea cheii, iar pentru decriptare, o scade.

Funcția process_file: Citește fișierul de intrare, aplică cifra lui Caesar pe fiecare linie de text și scrie rezultatul într-un fișier de ieșire.

Funcția main: Gestionează argumentele liniei de comandă, determină dacă se efectuează criptarea sau decriptarea și apelează funcțiile corespunzătoare.

### Observatii:
Textul poate conține doar litere din alfabetul englez.
Funcțiile de criptare și decriptare sunt case-sensitive, adică literele mari și mici sunt tratate separat.
Dacă fișierele de intrare sau ieșire nu sunt specificate corect sau nu pot fi deschise, aplicația va afisa un mesaj de eroare și va opri execuția.

### Exemple rulare din linia de comanda
![image](https://github.com/user-attachments/assets/2fe55151-a9b2-4b8d-b109-bf9036c2f6fd)
