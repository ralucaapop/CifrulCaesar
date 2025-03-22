#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SHIFT 3  // Pentru ciful lui Caesar folosim cheia 3

void caesar_cipher(char *text, int shift, int decrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { //verificam daca caracterul este litera(alfabetul ales contine doar literele alfabetului englez)
            char base = isupper(text[i]) ? 'A' : 'a';
            if (decrypt) //daca trebuie sa facem decriptare
                text[i] = (text[i] - base - shift + 26) % 26 + base; //scadem valoare cheii
            else
                text[i] = (text[i] - base + shift) % 26 + base; //daca trebuie sa facem criptare, adunam cu valoare cheii
        }
    }
}

void process_file(char *input_file, char *output_file, int decrypt) {
    FILE *fin = fopen(input_file, "r");
    if (!fin) {
        perror("Eroare la deschiderea fișierului de intrare");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout) {
        perror("Eroare la deschiderea fișierului de ieșire");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fin)) {  //citim cate 1024 de caractere din fisier
        caesar_cipher(buffer, SHIFT, decrypt);      //aplicam cifrul lui caesar pentru caracterele citite
        fputs(buffer, fout);                        //scriem in fisierul de output textul cifrat
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Utilizare: %s -e/-d -i input.txt -o output.txt\n", argv[0]);
        return -1;
    }


    int decrypt = (strcmp(argv[1], "-d") == 0) ? 1 : 0;  //Verificam daca trebuie sa facem criptare sau desciptare in functie de argumentul specificat
    const char *input_file = NULL, *output_file = NULL;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            input_file = argv[++i];                         //Extragem fisierul de intrare din argumente
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];                        //Extragem fisierul de iesire din argumente
        }
    }

    if (!input_file || !output_file) {
        fprintf(stderr, "Fișierele de intrare și ieșire sunt necesare!\n");
        return -1;
    }

    process_file(input_file, output_file, decrypt);
    printf("Procesare completa!\n");
    return 0;
}
