#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//DEFININDO A ESTRUTURA "CLiente"
typedef struct _cliente{
    char nome[50];
    float saldo;
} Cliente;

//DEFININDO A FUNÇÃO PARA CRIRAR UM "Cliente"
Cliente *criarCliente(char *nome, float saldo){
    Cliente *cliente = (Cliente*) calloc(1, sizeof(Cliente));
    strcpy(cliente -> nome, nome);
    cliente -> saldo = saldo;
    
    return cliente;
}

void lines(){
	printf("\n+----------------------------------------------------------------+\n");
}

//DEFININDO A FUNÇÃO "sacar"
void sacar(Cliente *clienteSaldo, float solicitacao){
    if (clienteSaldo -> saldo >= solicitacao){
        clienteSaldo -> saldo -= solicitacao;
        lines();
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t\tBANCO DO BRASIL");
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t+--------------------------+");
        puts("\t\t|    SAQUE  - AUTORIZADO   |");
        puts("\t\t+--------------------------+");
        lines();
        printf("CLIENTE: %s\n", clienteSaldo->nome);
        printf("VALOR DE SAQUE: %.2f\n", solicitacao);
        puts("STATUS: SAQUE AUTORIZADO.\n");
        printf("VALOR ATUAL NA CONTA: %.2f", clienteSaldo->saldo);
        lines();
    }
    else{
        lines();
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t\tBANCO DO BRASIL");
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t+------------------------------+");
        puts("\t\t|    SAQUE - NÃO AUTORIZADO    |");
        puts("\t\t+------------------------------+");
        lines();
        printf("CLIENTE: %s\n", clienteSaldo->nome);
        printf("VALOR DA TENTATIVA DE SAQUE: %.2f\n", solicitacao);
        printf("STATUS: SAQUE NAO AUTORIZADO.\n");
        printf("VALOR ATUAL NA CONTA: %.2f\n", clienteSaldo->saldo);
        printf("MOTIVO: SALDO INSUFICIENTE ");
        lines();
    }

}

//DEFININDO A FUNÇÃO "depositar"
void depositar(Cliente *clienteSaldo, float valorDepositado){
    clienteSaldo -> saldo += valorDepositado;
    lines();
    puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    puts("\t\t\tBANCO DO BRASIL");
    puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    puts("\t\t\t+--------------+");
    puts("\t\t\t|   DEPÓSITO   |");
    puts("\t\t\t+--------------+");
    lines();
    printf("CLIENTE: %s\n", clienteSaldo->nome);
    printf("VALOR DEPOSITADO: %.2f\n", valorDepositado);
    printf("VALOR ATUAL NA CONTA: %.2f", clienteSaldo->saldo);
    lines();
}

//DEFININDO A FUNÇÃO "transferir"
void transferir(Cliente *remetente, Cliente *destinatario, float valorTransferencia){
    if(remetente -> saldo >= valorTransferencia){
        remetente -> saldo -= valorTransferencia;
        destinatario -> saldo += valorTransferencia;
        lines();
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t\tBANCO DO BRASIL");
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t+--------------------------+");
        puts("\t\t|TRANSFERÊNCIA - AUTORIZADA|");
        puts("\t\t+--------------------------+");
        lines();
        printf("REMETENTE: %s\n", remetente->nome);
        printf("DESTINATARIO: %s\n", destinatario->nome);
        puts("STATUS: TRANSFERENCIA AUTORIZADA.\n");
        printf("VALOR TRANSFERIDO: %.2f\n", valorTransferencia);
        printf("VALOR ATUAL NA CONTA DO REMETENTE: %.2f\n", remetente->saldo);
        printf("VALOR ATUAL NA CONTA DO DESTINATARIO: %.2f\n", destinatario->saldo);
        lines();
    }
    else{
        lines();
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t\tBANCO DO BRASIL");
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        puts("\t\t+------------------------------+");
        puts("\t\t|TRANSFERÊNCIA - NÃO AUTORIZADA|");
        puts("\t\t+------------------------------+");
        lines();
        printf("REMETENTE: %s\n", remetente->nome);
        printf("DESTINATARIO: %s\n", destinatario->nome);
        printf("STATUS: TRANSFERENCIA NAO AUTORIZADA.\n");
        printf("VALOR DA TENTATIVA DE TRANSFERENCIA: %.2f\n", valorTransferencia);
        printf("VALOR ATUAL NA CONTA: %.2f\n", remetente->saldo);
        printf("MOTIVO: SALDO DO REMETENTE INSUFICIENTE PARA CONCLUIR A TRANSFERENCIA");
        lines();
    }
}

//DEFININDO A FUNÇÃO PARA DESALOCAR A MEMÓRIA
void liberarMemoria(Cliente **cliente){
    free(*cliente);
    *cliente = NULL;
}

//DEFININDO A FUNÇÃO PARA EXIBIR INFORMAÇÕES DO CLIENTE
void interfaceCliente(Cliente *cliente){
    lines();
    puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    puts("\t\t\t    BANCO DO BRASIL");
    puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    puts("\t\t\t+----------------------+");
    puts("\t\t\t|INFORMACÕES DO CLIENTE|");
    puts("\t\t\t+----------------------+");
    lines();
    printf("CLIENTE: %s\n", cliente->nome);
    printf("SALDO: R$%.2f\n", cliente ->saldo);
    lines();
}


int main(void){
	setlocale(LC_ALL, "Portuguese");
    
	int cont; int cliente_num;
    int opcao;
    Cliente *clientes[10]; //Criando uma lista de clientes
    int cont_cliente = 0; //criando um contador de clientes
	
	do{
		system("cls");
		puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        puts("\t\t\t    BANCO DO BRASIL");
        puts("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

        lines();
    	printf("1- CRIAR CLIENTE\n2- REALIZAR SAQUE\n3- REALIZAR DEPÓSITO\n4- REALIZAR TRANSFERÊNCIA\n5- CONSULTAR SALDO\n6- SAIR");
        lines();
        puts("+---------------------------------------------------------------------------------------------------+");
    	printf("AVISO: O PROGRAMA TEM UM LIMITE MÁXIMO DE 10 CLIENTES E A MEMÓRIA É LIMPA SEMPRE QUE FINALIZADO.\n");
        puts("+---------------------------------------------------------------------------------------------------+");

    	printf("ESCOLHA UM DOS SERVIÇOS ACIMA: ");
    	fflush(stdin);
    	scanf("%i", &opcao);

    	switch(opcao){
    		case 1: {
    			system("cls");
    			char nome[50];
				float saldo;

                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tCRIANDO CLIENTE");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    			printf("INFORME O NOME DO CLIENTE: ");
    			scanf("%s", &nome);
    			printf("INFORME O SALDO DO CLIENTE: R$");
    			scanf("%f", &saldo);

    			clientes[cont_cliente] = criarCliente(nome, saldo);
    			cont_cliente++;

                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("     CLIENTE CADASTRADO COM SUCESSO");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    			system("pause");

    			break;
			}
			case 2: {
				system("cls");
				float saque;

                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tÁREA DE SAQUE");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

				for(cont = 0; cont <= cont_cliente -1; cont++){
					printf("%i- %s\n", cont+1, clientes[cont]->nome);
				}

				lines();
				printf("INFORME O NÚMERO(ÍNDICE) DO CLIENTE PARA REALIZAR O SAQUE: ");
				fflush(stdin);
				scanf("%i", &cliente_num);
				printf("INFORME O VALOR DE SAQUE: R$");
				fflush(stdin);
				scanf("%f", &saque);

                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tPROCESSANDO SAQUE...");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
                sleep(2);
				system("cls");
                
				sacar(clientes[cliente_num-1], saque);
				system("pause");
				
				break;
			}
			case 3: {
				system("cls");
				float deposito;
				puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tÁREA DE DEPÓSITO");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

				for(cont = 0; cont <= cont_cliente -1; cont++){
					printf("%i- %s\n", cont+1, clientes[cont]->nome);
				}

				lines();
				printf("INFORME O NÚMERO(ÍNDICE) DO CLIENTE PARA REALIZAR O DEPÓSITO: ");
				fflush(stdin);
				scanf("%i", &cliente_num);
				printf("INFORME O VALOR DO DEPÓSITO: R$");
				fflush(stdin);
				scanf("%f", &deposito);
				system("cls");
				depositar(clientes[cliente_num-1], deposito);
				system("pause");

				break;
			}
			case 4: {
				system("cls");
				float transferencia;
				int remetente, destinatario;

                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tÁREA DE TRANSFERÊNCIA");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

				for(cont = 0; cont <= cont_cliente -1; cont++){
					printf("%i- %s\n", cont+1, clientes[cont]->nome);
				}

				lines();
				printf("INFORME O NÚMERO(ÍNDICE) DO REMETENTE: ");
				fflush(stdin);
				scanf("%i", &remetente);
				printf("INFORME O NÚMERO(ÍNDICE) DO DESTINATÁRIO: ");
				fflush(stdin);
				scanf("%i", &destinatario);
				printf("INFORME O VALOR DA TRANSFERÊNCIA: R$");
				fflush(stdin);
				scanf("%f", &transferencia);
				system("cls");
				transferir(clientes[remetente-1], clientes[destinatario-1], transferencia);
				system("pause");

				break;
			}
			case 5: {
				system("cls");
                
                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    	        puts("\tEXIBIÇÃO DE SALDO");
    	        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
				
				for(cont = 0; cont <= cont_cliente -1; cont++){
					printf("%i- %s\n", cont+1, clientes[cont]->nome);
				}

				lines();
				printf("INFORME O NÚMERO(ÍNDICE) DO CLIENTE: ");
				fflush(stdin);
				scanf("%i", &cliente_num);
				system("cls");
				interfaceCliente(clientes[cliente_num-1]);
				system("pause");

				break;
			}
    			
		}
	} while(opcao != 6);
	
	//DESALOCANDO MEMÓRIA
	system("cls");
    lines();
	printf("FINALIZANDO O PROGRAMA E REALIZANDO A LIMPEZA(DESALOCANDO) DE MEMÓRIA...\n");
	printf("POR FAVOR, AGUARDE!\n");
    lines();

	for(cont = 0; cont<=cont_cliente -1; cont++){
		liberarMemoria(&clientes[cont]);
	}

	sleep(3);

	printf("LIMPEZA(DESALOCAÇÃO) REALIZADA COM SUCESSO, PROGRAMA FINALIZADO!\n");
    printf("O BB AGRADECE POR SUA PREFERÊNCIA!");
    lines();
    
    
    //TESTE RÁPIDO
//    Cliente *pablo = criarCliente("Pablo Cardoso", 600);
//    Cliente *pedro = criarCliente("Pedro Campos", 500);
//    Cliente *ruan = criarCliente("Ruan Alves", 400);
//    interfaceCliente(pablo);
//    sacar(pablo, 100);
//    depositar(pablo, 200);
//    transferir(pablo, pedro, 200);
//
//    sacar(ruan, 500);
//    transferir(pedro, ruan, 400);
//    interfaceCliente(ruan);
//    transferir(ruan, pablo, 1000);
//
//    liberarMemoria(&pablo);
//    liberarMemoria(&pedro);
//    liberarMemoria(&ruan);

    return 0;
}
