#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define TAMANHOLISTA 100
#define QUANTIDADELOOPBUSCA 1000

//RESPOSTAS
//10. Qual a complexidade do algoritmo de busca?
// Resposta: O(n) - Sendo que n � o tamanho do vetor e a busca � linear.

//11. Qual foi o valor m�dio encontrado pelo seu programa?
// Resposta: n/2, pois o valor encontrado est� aproximadamente no meio do vetor.

// 12. Os 2 valores acima s�o da mesma ordem de grandeza?
// Resposta: Sim, pois s�o proporcionais ao vetor.

//13. Se h� um valor maior entre a complexidade assint�tica e a m�dia encontrada, qual a explica��o?
//Resposta: Como o valor sempre existe na lista, vou fazer em m�dia n/2 compara��es.

void gerarNumeroAleatorioSemRepeticao(int *lista) {
    for (int i = 0; i < TAMANHOLISTA; i++) {
        int numeroAleatorioGerado;
        int numeroRepetido;

        do {
            numeroAleatorioGerado = rand() % TAMANHOLISTA;
            numeroRepetido = 0;

            for (int j = 0; j < i; j++) {
                if (numeroAleatorioGerado == *(lista + j)) {
                    numeroRepetido = 1;
                    break;
                }
            }
        } while (numeroRepetido == 1);

        *(lista + i) = numeroAleatorioGerado;
    }
}

int buscaLinearNumero(int *lista, int numeroEscolhido) {
    for (int i = 0; i < TAMANHOLISTA; i++) {
        if (numeroEscolhido == *(lista + i)) {
            return i;
        }
    }
    return -1;
}

float calcularMedia(int *lista, int numeroEscolhido) {
    float media = 0;
    int resultadoBusca;

    for (int i = 0; i < QUANTIDADELOOPBUSCA; i++) {
        gerarNumeroAleatorioSemRepeticao(lista);
        resultadoBusca = buscaLinearNumero(lista, numeroEscolhido);

        if (resultadoBusca != -1) {
            media += resultadoBusca + 1;
        }
    }

    media /= QUANTIDADELOOPBUSCA;
    return media;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *lista = (int*)malloc(sizeof(int) * TAMANHOLISTA);

    if (lista == NULL) {
        printf("Erro: Mem�ria Insuficiente!\n");
        return 1;
    }

    int numeroEscolhido;
    printf("Digite um n�mero de 0 a 99 para buscar na lista: ");
    scanf("%d", &numeroEscolhido);


    if (numeroEscolhido < 0 || numeroEscolhido >= TAMANHOLISTA) {
        printf("Aten��o! N�mero fora do intervalo! O n�mero deve estar entre 0 e 99.\n");
        free(lista);
        return 1;
    }

    float mediaLoops = calcularMedia(lista, numeroEscolhido);
    printf("\nA m�dia de loops para encontrar o n�mero %d �: %.2f\n", numeroEscolhido, mediaLoops);

    free(lista);
    return 0;
}
