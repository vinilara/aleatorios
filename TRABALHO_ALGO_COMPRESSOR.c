#include <stdio.h>
#include <string.h>

char vogaisEncontrada[100];

int main()
{
    char fraseOriginal[100] = {0},
         fraseCompactada[100] = {0},
         fraseDescompactada[100] = {0};
    
    int fraseOriginalLen,
        fraseFinalLen;
    
    printf("Digite uma frase simples para compressão:");
    
    fgets(fraseOriginal, 100, stdin);
    
    fraseOriginalLen = strlen(fraseOriginal) - 1;
    
    printf("---------- RESULTADO DA COMPRESSÃO ----------");
    
    // COMPACTA //
    
    int c,
    cV = 0;
    
    for (c = 0; c < fraseOriginalLen; c++) {
        if (strchr("aeiou", fraseOriginal[c]) != NULL) {
            vogaisEncontrada[c] = fraseOriginal[c];
            cV++;
        } else {
            vogaisEncontrada[c] = ' ';
            fraseCompactada[c - cV] = fraseOriginal[c];
        }
    }
    
    printf("\nSua mensagem comprimida é: %s", fraseCompactada);
    
    printf("\nSua mensagem comprimida tem length: %d", strlen(fraseCompactada));
    
    
    // DESCOMPACTA //
    
    int c1,
        pC = 0;
    
    for (c1 = 0; c1 < fraseOriginalLen; c1++) {
        if (vogaisEncontrada[c1] == ' ') {
            fraseDescompactada[c1] = fraseCompactada[pC];
            pC++;
        }
        else {
            fraseDescompactada[c1] = vogaisEncontrada[c1];
        }
    }
    
    printf("\n\nSua mensagem descomprimida é: %s", fraseDescompactada);
    
    printf("\nSua mensagem descomprimida tem length: %d\n", strlen(fraseDescompactada));
    
    fraseFinalLen = strlen(fraseCompactada);
    printf("\nA compressão poupou: %d\n", (fraseOriginalLen - fraseFinalLen));
    
    printf("-------------------------------------------\n");
    
    return 0;
}
