#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

	// Estrutura para representar um atendimento.
struct Atendimento {
    char nome[100];
    char cpf[15];
    int tipoAtendimento;
};
	// Função para cadastrar novos atendimentos.
void cadastrarAtendimento(struct Atendimento atendimentos[], int *numAtendimentos) {
    system("cls");
    printf("\n\n  Digite o nome do cliente: ");
    scanf(" %[^\n]", atendimentos[*numAtendimentos].nome);
    printf("  Digite o CPF do cliente (Somente Números): ");
    scanf("%s", atendimentos[*numAtendimentos].cpf);

    int opcaoTipoAtendimento;

    do {
        printf("\n\n  * Escolha o tipo de atendimento:\n\n");
        printf("  1 - Abertura de Conta\n");
        printf("  2 - Caixa\n");
        printf("  3 - Gerente Pessoa Física\n");
        printf("  4 - Gerente Pessoa Jurídica\n");
        printf("  Opção: ");
        scanf("%d", &opcaoTipoAtendimento);

        if (opcaoTipoAtendimento < 1 || opcaoTipoAtendimento > 4) {
            printf("\n  - Opção inválida. Tente novamente. -\n");
        }
    } while (opcaoTipoAtendimento < 1 || opcaoTipoAtendimento > 4);

    atendimentos[*numAtendimentos].tipoAtendimento = opcaoTipoAtendimento;

    (*numAtendimentos)++;
    printf("\n  * Atendimento registrado com sucesso!\n");
    printf("\n  < Retornando para o menu inicial... >\n\n\n\n\n");
    system("pause");
    system("cls");
}
	// Função para listar todos os atendimentos que estão registrados.
void listarAtendimentos(struct Atendimento atendimentos[], int numAtendimentos) {
    system("cls");
    if (numAtendimentos == 0) {
        printf("\n  - Ainda não há nenhum atendimento registrado. -\n");
    } else {
        printf("\n\n  * Lista de Atendimentos Registrados:\n");

        int i;
        for (i = 0; i < numAtendimentos; i++) {
            printf("\n  Nome: %s\n", atendimentos[i].nome);
            // Formatando e exibindo o CPF.
            printf("  CPF: %.3s.%.3s.%.3s-%.2s\n", atendimentos[i].cpf, atendimentos[i].cpf + 3, atendimentos[i].cpf + 6, atendimentos[i].cpf + 9);
            printf("  Tipo Atendimento - %d - ", atendimentos[i].tipoAtendimento);

            switch (atendimentos[i].tipoAtendimento) {
                case 1:
                    printf("Abertura de Conta\n");
                    break;
                case 2:
                    printf("Caixa\n");
                    break;
                case 3:
                    printf("Gerente Pessoa Física\n");
                    break;
                case 4:
                    printf("Gerente Pessoa Jurídica\n");
                    break;
            }
            printf("  ===============================================\n");
        }
        printf("\n  - Todos os Atendimentos Registrados Foram Listados. -\n");
    }
    printf("\n  < Retornando para o menu inicial... >\n\n\n\n\n");
    system("pause");
    system("cls");
}
	// Função para listar os atendimentos resgistrados pelo seu setor.
void listarAtendimentosPorTipo(struct Atendimento atendimentos[], int numAtendimentos, int tipoDesejado) {
	system("cls");
    if (numAtendimentos == 0) {
        printf("\n  - Ainda não há nenhum atendimento registrado. -\n");
    } else {
        int i;
        int encontrouAtendimento = 0; 	// Variável para verificar se algum atendimento foi encontrado.

        for (i = 0; i < numAtendimentos; i++) {
            if (atendimentos[i].tipoAtendimento == tipoDesejado) {
                if (!encontrouAtendimento) {
                    printf("\n  * Lista de Atendimentos Registrados para o Setor %d:\n", tipoDesejado);
                }
                printf("\n  Nome: %s\n", atendimentos[i].nome);
                printf("  CPF: %.3s.%.3s.%.3s-%.2s\n", atendimentos[i].cpf, atendimentos[i].cpf + 3, atendimentos[i].cpf + 6, atendimentos[i].cpf + 9);
                printf("  Tipo Atendimento - %d - ", atendimentos[i].tipoAtendimento);

                switch (atendimentos[i].tipoAtendimento) {
                    case 1:
                        printf("Abertura de Conta\n");
                        break;
                    case 2:
                        printf("Caixa\n");
                        break;
                    case 3:
                        printf("Gerente Pessoa Física\n");
                        break;
                    case 4:
                        printf("Gerente Pessoa Jurídica\n");
                        break;
                    default:
                        printf("Tipo de atendimento desconhecido\n");
                }
                printf("  ===============================================\n");
                encontrouAtendimento = 1;
            }
        }

        if (!encontrouAtendimento) {
            printf("\n  - Ainda não há nenhum atendimento registrado nesse setor. -\n");
        }
    }
    printf("\n  < Retornando para o menu inicial... >\n\n\n\n\n");
    system("pause");
    system("cls");
}
	// Função para exibir as opções de setor para ser listado.
void listarAtendimentosPorSetor(struct Atendimento atendimentos[], int numAtendimentos) {
	system("cls");
    int setorEscolhido;

    do {
        printf("\n\n  * Escolha o setor para listar atendimentos:\n\n");
        printf("  1 - Abertura de Conta\n");
        printf("  2 - Caixa\n");
        printf("  3 - Gerente Pessoa Física\n");
        printf("  4 - Gerente Pessoa Jurídica\n");
        printf("  Opção: ");
        scanf("%d", &setorEscolhido);

        if (setorEscolhido < 1 || setorEscolhido > 4) {
            printf("\n  - Opção inválida. Tente novamente. -\n");
        }
    } while (setorEscolhido < 1 || setorEscolhido > 4);

    listarAtendimentosPorTipo(atendimentos, numAtendimentos, setorEscolhido);
}
	// Menu principal.
int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Atendimento atendimentos[100];
    int numAtendimentos = 0;
    int opcao;

    while (1) {
        printf("\n  ===== Bem-vindo(a) ao sistema de atendimento ===== \n");
        printf("\n\n  * Escolha a opção desejada:\n");
        printf("\n  1 - Solicitar Atendimento\n");
        printf("  2 - Listar Atendimentos Registrados\n");
        printf("  3 - Listar Atendimento por Setor\n");
        printf("  4 - Sair\n");
        printf("  Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAtendimento(atendimentos, &numAtendimentos);
                break;
            case 2:
                listarAtendimentos(atendimentos, numAtendimentos);
                break;
            case 3:
                listarAtendimentosPorSetor(atendimentos, numAtendimentos);
                break;
            case 4: {
                char confirmacao;
                system("cls");
                printf("\n  * Você realmente quer sair do sistema? (s/n): ");
                scanf(" %c", &confirmacao);

                while (confirmacao != 's' && confirmacao != 'S' && confirmacao != 'n' && confirmacao != 'N') {
                    printf("\n  - Opção inválida. Tente novamente. (s/n): ");
                    scanf(" %c", &confirmacao);
                }

                if (confirmacao == 's' || confirmacao == 'S') {
                    printf("\n\n  == Entendido! Agradecemos por utilizar o nosso sistema. Até mais! :) ==\n");
                    printf("\n  - Encerrando o sistema... -\n");
                    return 0;
                } else {
                    printf("\n  < Entendido! Retornando para o menu inicial... >\n\n\n\n\n");
                    system("pause");
                    system("cls");
                }
            } break;
            default:
                printf("\n  - Opção inválida. Tente novamente. - \n\n");
        }
    }

    return 0;
}

