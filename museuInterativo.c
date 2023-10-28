#include <stdio.h>

struct Exposicao {
    int id; 
    char categoria; 
    int quantidade; 
    double valor; 
};

void solicitarExposicoes(struct Exposicao exposicoes[]) {
    for (int i = 0; i < 4; i++) {
        printf("Escolha a exposição desejada:\n");
        printf("1. 100 anos da semana de arte moderna\n");
        printf("2. 150 anos de Santos Dumont\n");
        printf("3. Jogos olímpicos de Paris 2024\n");
        printf("4. Copa do mundo de 2022\n");

        int exposicao;
        printf("Digite o número da exposição desejada (ou 0 para sair): ");
        scanf("%d", &exposicao);

        if (exposicao == 0) {
            break; 
        } else if (exposicao < 1 || exposicao > 4) {
            printf("Opção inválida. Por favor, escolha uma exposição de 1 a 4.\n");
        } else {
            exposicoes[i].id = exposicao;
        }
    }
}

void solicitarIngressos(struct Exposicao exposicoes[]) {
    for (int i = 0; i < 4; i++) {
        int idExposicao = exposicoes[i].id;
        char categoria;
        int quantidade;
        double valor;

        printf("Exposição %d - Escolha a categoria de ingresso:\n", idExposicao);
        printf("a. Inteira\n");
        printf("b. Meia entrada\n");
        printf("c. Gratuito (para idosos)\n");
        scanf(" %c", &categoria);

        printf("Digite a quantidade de ingressos desejada para a Exposição %d: ", idExposicao);
        scanf("%d", &quantidade);

        if (categoria == 'a') {
            valor = quantidade * 20.0;
        } else if (categoria == 'b') {
            valor = quantidade * 10.0;
        } else if (categoria == 'c') {
            valor = 0.0;
        } else {
            printf("Categoria de ingresso inválida.\n");
        }

        exposicoes[i].categoria = categoria;
        exposicoes[i].quantidade = quantidade;
        exposicoes[i].valor = valor;
    }
}


void exibirResumo(struct Exposicao exposicoes[]) {
    for (int i = 0; i < 4; i++) {
        printf("Exposição %d:\n", exposicoes[i].id);
        printf("Categoria: %c\n", exposicoes[i].categoria);
        printf("Quantidade: %d\n", exposicoes[i].quantidade);
        printf("Valor total: R$ %.2f\n", exposicoes[i].valor);
    }
}

int main() {
    printf("Bem-vindo ao Museu Multitemático!\n");

    struct Exposicao exposicoes[4];

    solicitarExposicoes(exposicoes);

    solicitarIngressos(exposicoes);


    exibirResumo(exposicoes);

    return 0;
}