//
//  main.c
//  testes
//
//  Created by Vinícius Eduardo on 20/06/17.
//  Copyright © 2017 Vinícius Eduardo. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct funcionarios { // cria um struct com as opcoes {codigo,nome,funcao,departamento,salario}
    int codigo;
    char nome[30]; // o nome do funcionario pode ter até 31 caracteres (0-30)
    int funcao;
    int departamento;
    float salario;
};

struct funcionarios funcionarios[50]; // cria 50 posicoes com esses atributos para a variavel global "funcionarios"

char departamentos[][20] = {"vendas", "producao", "estoque", "cpd"}; // nomes dos departamentos
char funcoes[][20] = {"testador", "analista", "desenvolvedor", "gerente", "fiscal"}; // nomes das funcoes

void estruturaPrograma(int *opcao, int *codigoFuncionarios); // declara a funcao para nao dar problema no codigo

void exibeMenu(int *opcao) {
    int opcaoInterna; // cria uma variavel temporaria apenas pra guardar a opcao do usuario
    
    printf("-------------------------- RH --------------------------\n");
    printf("0 - Cadastrar funcionario\n");
    printf("1 - Relatorio: Total de funcionarios\n");
    printf("2 - Relatorio: Total de funcionarios por departamento\n");
    printf("3 - Relatorio: Maior salario\n");
    printf("4 - Relatorio: Lista de todos funcionarios\n");
    printf("--------------------------------------------------------\n");
    printf("Escolha a opcao:");
    
    scanf("%d", &opcaoInterna); // obtem a opcao e guarda na variavel temporaria "opcaoInterna"

    *opcao = opcaoInterna; // altera a variavel "opcao" que esta na funcao "main" usando "*" que indica o conteudo da variavel
    
    printf("--------------------------------------------------------\n");
}

void enquanto(int *opcao, int *codigoFuncionarios) {
    
    int opcaoTmp,
    codigoFuncionariosTmp;
    
    opcaoTmp = *opcao;
    codigoFuncionariosTmp = *codigoFuncionarios;
    
    int codigo;
    char nome[30]; // o nome do funcionario pode ter até 31 caracteres (0-30)
    int funcao;
    int departamento;
    float salario;
    
    int i,
        totalFuncionarios = 0,
        maiorSalario = 0;

    while(opcaoTmp <= 4) {
        switch(opcaoTmp) {
            case 0: // cadastra funcionario
                printf("Nome do funcionario:");
                
                getchar(); // resolve conflito com scanf
                fgets(nome, sizeof(nome), stdin); // obtem nome do funcionario
                nome[strcspn(nome, "\n")] = 0; // remove a quebra de linha que a funcao "fgets" da na ultima casa do vetor

                printf("Numero da funcao do funcionario (0-3):");
                scanf("%d", &funcao);
                
                printf("Numero do departamento do funcionario (0-2):");
                scanf("%d", &departamento);
                
                printf("Valor do salario do funcionario $:");
                scanf("%f", &salario);
                
                codigo = codigoFuncionariosTmp++;
                
                funcionarios[codigo].codigo = codigo;
                strcpy(funcionarios[codigo].nome, nome);
                funcionarios[codigo].funcao = funcao;
                funcionarios[codigo].departamento = departamento;
                funcionarios[codigo].salario = salario;
                
                opcaoTmp = 5;
                
                break;
            case 1: // total de usuarios geral
                
                for(i = 0; i < 50; i++) {
                    if(strlen(funcionarios[i].nome) > 0) {
                        totalFuncionarios++;
                    }
                }
                
                printf("Temos um total de %d funcionarios.\n" , totalFuncionarios);
                
                opcaoTmp = 5;
                break;
            case 2: // total de funcinarios por departamento
                
                printf("Qual departamento voce procura contabilizar? (1-4):");
                scanf("%d", &departamento);
                
                for(i = 0; i < 50; i++) {
                    if(funcionarios[i].departamento == departamento) {
                        totalFuncionarios++;
                    }
                }
                
                printf("Temos um total de %d funcionarios no departamento de %s.\n" , totalFuncionarios, &departamentos[departamento]);
                
                opcaoTmp = 5;
                break;
            case 3: // mostra maior salario
                for(i = 0; i < 50; i++) {
                    if(funcionarios[i].salario > maiorSalario) {
                        maiorSalario = i;;
                    }
                }
                
                if(maiorSalario <= 0) {
                    printf("Nao existe maior salario.\n");
                } else {
                    printf("O maior salario e de [%d:%s] que tem remuneracao de $%.3f\n", maiorSalario, funcionarios[maiorSalario].nome, funcionarios[maiorSalario].salario);
                }
                   
                opcaoTmp = 5;
                break;
            case 4: // lista todos funcionarios cadastrados
                for(i = 0; i < 50; i++) {
                    if(strlen(funcionarios[i].nome) > 0) {
                        printf("Codigo: [%d]\nNome: [%s]\nFuncao: [%s]\nDepartamento: [%s]\nSalario: [$%.3f]\n", i, funcionarios[i].nome, &funcoes[funcionarios[i].funcao], &departamentos[funcionarios[i].departamento], funcionarios[i].salario);
                        printf("--------------------------------------------------------\n");
                    }
                }
                
                opcaoTmp = 5;
                break;
        }
    }
  
    exibeMenu(&opcaoTmp);
    
    estruturaPrograma(&opcaoTmp, &codigoFuncionariosTmp);
 }

void estruturaPrograma(int *opcao, int *codigoFuncionarios) {
    int opcaoTmp,
        codigoFuncionariosTmp;
    
    opcaoTmp = *opcao;
    codigoFuncionariosTmp = *codigoFuncionarios;
    
    enquanto(&opcaoTmp, &codigoFuncionariosTmp);
}


int main(int argc, const char * argv[]) {

    int opcao = 0,
        codigoFuncionarios = 0; // variavel opcao (guarda a opcao digitada pelo usuario)
    
    exibeMenu(&opcao);

    estruturaPrograma(&opcao, &codigoFuncionarios);

    return 0;
}
