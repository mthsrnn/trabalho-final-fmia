#include "transicoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(char *entrada, FILE *outfile) {
    char variaveis[] = {'a', 'b', 'c', 'd'};
    int quantasEntradas = 4;
    unsigned char *tabelaVerdade = calloc(1 << quantasEntradas, sizeof(char));

    for (int i = 0; i < (1 << quantasEntradas); i++) {
        tabelaVerdade[i] = entrada[i] - '0';
    }

    for (int i = 0; i < (1 << quantasEntradas); i++) {
        fprintf(outfile, "%c", '0' + tabelaVerdade[i]);
    }

    fprintf(outfile, ",");

    FILE *original_stdout = stdout;
    stdout = outfile;

    imprimeArcos(tabelaVerdade, variaveis, quantasEntradas);

    stdout = original_stdout;

    fputs("\n", outfile);

    free(tabelaVerdade);
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        FILE *infile = fopen(argv[1], "r");
        FILE *outfile = fopen(argv[2], "w");

        if (infile == NULL || outfile == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        char line[256];
        while (fgets(line, sizeof(line), infile)) {
            char *newline = strchr(line, '\n');
            if (newline) {
                *newline = '\0';
            }
            processInput(line, outfile);
        }

        fclose(infile);
        fclose(outfile);
    } else {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
