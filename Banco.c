// === La Banque Clément====
// =========================
#include <stdio.h>

int findConta(int *conta, int cc[1000], int n);
void openConta(int conta, float *saldo, int cc[1000], int *n);
void fazerDeposito(float saldo[1000], int i);
void fazerSaque(float saldo[1000], int i);
void fazerPIX(float saldo[1000], int cc[1000], int n);
float tomaValor(void);
void menu(int *p);

int main(void) {
    int cc[1000], n = 0, i, op, conta;
    float saldo[1000];

    for (i = 0; i < 1000; i++) {
        cc[i] = 0;
        saldo[i] = 0;
    }

    do {
        menu(&op);
        if (op == 1) {
            i = findConta(&conta, cc, n);
            if (i != n) printf("esta conta-corrente ja existe\n");
            else openConta(conta, saldo, cc, &n);
        }
        if (op == 2) {
            i = findConta(&conta, cc, n);
            if (i == n) printf("numero de conta-corrente invalido\n");
            else printf("saldo: %.2f\n", saldo[i]);
        }
        if (op == 3) {
            i = findConta(&conta, cc, n);
            if (i == n) printf("numero de conta-corrente invalido\n");
            else fazerDeposito(saldo, i);
        }
        if (op == 4) {
            i = findConta(&conta, cc, n);
            if (i == n) printf("numero de conta-corrente invalido\n");
            else fazerSaque(saldo, i);
        }
        if (op == 5) {
            fazerPIX(saldo, cc, n);
        }
    } while (op != 6);

    return 0;
}

void menu(int *p) {
    printf("1) Abrir conta\n");
    printf("2) Verificar saldo\n");
    printf("3) Fazer Deposito\n");
    printf("4) Fazer Saque\n");
    printf("5) Fazer PIX\n");
    printf("6) Sair do sistema\n");
    scanf("%d", p);
}

int findConta(int *conta, int cc[1000], int n) {
    int j;
    printf("numero da conta: ");
    scanf("%d", conta);
    for (j = 0; j < n && *conta != cc[j]; j++);
    return j;
}

void openConta(int conta, float *saldo, int cc[1000], int *n) {
    float valor;
    printf("valor do deposito inicial: ");
    valor = tomaValor();
    cc[*n] = conta;
    saldo[*n] = valor;
    (*n)++;
    printf("operacao realizada com sucesso\n");
}

void fazerDeposito(float saldo[1000], int i) {
    float valor;
    printf("valor do deposito: ");
    valor = tomaValor();
    saldo[i] += valor;
    printf("operacao realizada com sucesso\n");
}

void fazerSaque(float saldo[1000], int i) {
    float valor;
    printf("valor do saque: ");
    valor = tomaValor();
    if (valor > saldo[i]) {
        printf("saldo insuficiente\n");
    } else {
        saldo[i] -= valor;
        printf("operacao realizada com sucesso\n");
    }
}

void fazerPIX(float saldo[1000], int cc[1000], int n) {
    int contaOrigem, contaDestino, iOrigem, iDestino;
    float valor;

    printf("numero da conta de origem: ");
    scanf("%d", &contaOrigem);
    iOrigem = findConta(&contaOrigem, cc, n);
    if (iOrigem == n) {
        printf("conta de origem invalida\n");
        return;
    }

    printf("numero da conta de destino: ");
    scanf("%d", &contaDestino);
    iDestino = findConta(&contaDestino, cc, n);
    if (iDestino == n) {
        printf("conta de destino invalida\n");
        return;
    }

    printf("valor do PIX: ");
    valor = tomaValor();
    if (valor > saldo[iOrigem]) {
        printf("saldo insuficiente\n");
    } else {
        saldo[iOrigem] -= valor;
        saldo[iDestino] += valor;
        printf("PIX realizado com sucesso\n");
    }
}

float tomaValor(void) {
    float valor;
    scanf("%f", &valor);
    while (valor <= 0) {
        printf("o valor deve ser positivo.\n");
        printf("valor: ");
        scanf("%f", &valor);
    }
    return valor;
}