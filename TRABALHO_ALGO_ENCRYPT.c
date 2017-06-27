#include<stdio.h>

int main()
{
    int opcao = 0,
        chave = 2;
    char mensagem[100];
    
    while(opcao != 3) {
        printf("----------ENCRIPTADOR----------\n");
        printf("1 - Encriptar\n");
        printf("2 - Decriptar\n");
        printf("3 - Sair\n");
        printf("-------------------------------\n");
        
        scanf("%d", &opcao);
        getchar();
        
        int i;
        char ch;

        switch(opcao) {
            case 1:
                printf("-----------ENCRIPTAR-----------\n[MENSAGEM]: ");
                fgets(mensagem, sizeof(mensagem), stdin);
                printf("[CHAVE]: ");
                scanf("%d", &chave);
                
                for(i = 0; mensagem[i] != '\0'; ++i){
                    ch = tolower(mensagem[i]);

                    if(ch >= 'a' && ch <= 'z'){
                        ch = ch + chave;
                        
                        if(ch > 'z'){
                            ch = ch - 'z' + 'a' - 1;
                        }
                        
                        mensagem[i] = ch;
                    }
                }
                
                printf("[RETORNO]: %s\n", &mensagem);
                break;
            case 2:
                printf("------------DECRIPTAR------------\n[MENSAGEM]: ");
                fgets(mensagem, sizeof(mensagem), stdin);
                printf("[CHAVE]: ");
                scanf("%d", &chave);
                
                for(i = 0; mensagem[i] != '\0'; ++i){
                    ch = tolower(mensagem[i]);
                    
                    if(ch >= 'a' && ch <= 'z'){
                        ch = ch - chave;
                        
                        if(ch < 'a'){
                            ch = ch + 'z' - 'a' + 1;
                        }
                        
                        mensagem[i] = ch;
                    }
                }
                
                printf("[RETORNO]: %s\n", &mensagem);
                break;
        }
        
    }
    

    return 0;
}
