#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void preencheVetor(int vetor[]){
    for (int i = 0; i < 16; i++) {
        vetor[i] = i;
    }
}

int indiceVetor(int vetor[], int valor){
    for (int i = 0; i < 16; i++){

        if (vetor[i] == valor){
            return i;
        }
    }

    return -1;
}

bool ordenacaoVetor(int vetor[]){
    for (int i = 0; i < 15; i++){
        if (vetor[i] > vetor[i + 1]){
            return false;
        } 
    }
    return true;
}

void moveEsquerda(int vetor[]){
    int salvaAnterior;
    int salvaQuinze;

    salvaQuinze = indiceVetor(vetor, 15);
    if(salvaQuinze != 0 && salvaQuinze != 4 && salvaQuinze != 8 && salvaQuinze != 12){
        salvaAnterior = vetor[salvaQuinze - 1];
    vetor[salvaQuinze] = salvaAnterior;
    vetor[salvaQuinze -1] = 15;
    } else{
        ;
    }

}

void moveDireita(int vetor[]){
    int salvaSucessor;
    int salvaQuinze;

   salvaQuinze = indiceVetor(vetor, 15);
    if(salvaQuinze != 3 && salvaQuinze != 7 && salvaQuinze != 11 && salvaQuinze != 15){
        salvaSucessor = vetor[salvaQuinze + 1];
        vetor[salvaQuinze] = salvaSucessor;
        vetor[salvaQuinze + 1] = 15;
    } else{
        ;
    }

}

void moveCima(int vetor[]){
    int salvaAnterior4;
    int salvaQuinze;

    salvaQuinze = indiceVetor(vetor, 15);
    if (salvaQuinze != 0 && salvaQuinze != 1 && salvaQuinze != 2 && salvaQuinze != 3 ){
        salvaAnterior4 = vetor[salvaQuinze - 4];
        vetor[salvaQuinze] = salvaAnterior4;
        vetor[salvaQuinze - 4] = 15;
    } else{
        ;
    }
}

void moveBaixo(int vetor[]){
    int salvaSucessor4;
    int salvaQuinze;

    salvaQuinze = indiceVetor(vetor, 15);
    if (salvaQuinze != 12 && salvaQuinze != 13 && salvaQuinze != 14 && salvaQuinze != 15){
        salvaSucessor4 = vetor[salvaQuinze + 4];
        vetor[salvaQuinze] = salvaSucessor4;
        vetor[salvaQuinze + 4] = 15;
    } else{
        ;
    }
}

void moveAleatorio(int vetor[]){
    int escolha = rand() % 4;
    switch (escolha)
    {
        case 0:
        moveCima(vetor);
        break;

        case 1:
        moveBaixo(vetor);
        break;

        case 2:
        moveEsquerda(vetor);
        break;

        case 3:
        moveDireita(vetor);
        break;
    }

}

void embaralha(int vetor[]){
    int n;
    int quantidadeEmbaralha = rand() % 10000;
   for (n = 0; n < quantidadeEmbaralha; n++)
    {
        moveAleatorio(vetor);
    }
}

bool movimentacao(int vetor[]){
    char tecla;
    scanf(" %c", &tecla);
    if (tecla == 's' ||tecla == 'b' ||tecla == 'A')
    {
        moveBaixo(vetor);
    } else if (tecla == 'w' ||tecla == 'c' ||tecla == 'B')
    {
       moveCima(vetor);
    }else if (tecla == 'd' ||tecla == 'D')
    {
        moveDireita(vetor); 
    }else if (tecla == 'a' ||tecla == 'e' ||tecla == 'C')
    {
        moveEsquerda(vetor);
    } else if (tecla == 'q' || tecla == 'Q'){
        return false;
    }else{
        ;
    }
    return true;
}

void movimentacaoNumeroPosicao(int vetor[]){
    int posicao;
    printf("digite um numero de 1 até 16 para trocar de posicao se possivel: ");
    scanf("%d", &posicao);
    if (vetor[posicao - 1] == 15)
    {
        moveEsquerda(vetor);
    } else if (vetor[posicao + 1] == 15)
    {
        moveDireita(vetor);
    } else if (vetor[posicao + 4] == 15)
    {
        moveCima(vetor);
    }else if (vetor[posicao - 4] == 15)
    {
        moveBaixo(vetor);
    } else{
        ;
    }
    
}

void cor_letra(int r, int g, int b)
{
  printf("%c[38;2;%d;%d;%dm", 27, r, g, b);
}

void cor_fundo(int r, int g, int b)
{
  printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal()
{
  printf("%c[0m", 27);
}

void cor_tabuleiro()
{
  cor_fundo(140, 70, 20); // marrom
}
void cor_peca()
{
  cor_fundo(200, 200, 170); // branco sujo
  cor_letra(70, 50, 40); // escuro
}
void cor_vazio()
{
  cor_fundo(0, 0, 0); // preto
}

void pula_linha()
{
  printf("\r\n");
}

void limpa_tela()
{
  cor_normal();
  printf("%c[2J", 27); // limpa a tela
  printf("%c[H", 27);  // põe o cursor no início
}

void desenha_borda()
{
  cor_normal();
  printf("%3s", "");
  cor_tabuleiro();
  printf("%32s","");
  cor_normal();
  pula_linha();
}
void imprime_pedaco_linha_v8(int t[], int l, bool com_peca)
{
  char desenho[] = "ABCDEFGHIJKLMNO ";

  cor_normal();
  printf("%3s", "");
  cor_tabuleiro();
  printf("  ");
  for (int i = 0; i < 4; i++) {
    int v = t[l*4 + i];
    v == 15 ? cor_vazio() : cor_peca();
    printf("   %c   ", com_peca ? desenho[v] : ' ');
  }
  cor_tabuleiro();
  printf("  ");
  cor_normal();
  pula_linha();
}

void imprime_linha_v8(int t[], int l)
{
  imprime_pedaco_linha_v8(t, l, false);
  imprime_pedaco_linha_v8(t, l, true);
  imprime_pedaco_linha_v8(t, l, false);
}

void imprime_tabuleiro_v8(int t[])
{
  limpa_tela();
  pula_linha();
  desenha_borda();
  for (int linha = 0; linha < 4; linha++) {
    imprime_linha_v8(t, linha);
  }
  desenha_borda();
}

int main(){

    system("stty raw -echo");

    srand(time(NULL));

    int vetor[16];
    preencheVetor(vetor);
    embaralha(vetor);
    bool botaoSaida = true;

    while(ordenacaoVetor(vetor) == false && botaoSaida){
        imprime_tabuleiro_v8(vetor);
        botaoSaida = movimentacao(vetor);
    }

    system("stty sane");

    if (botaoSaida == false){
        printf("voce finalizou o programa\n Adeus! ):\n");    
    }else{
        imprime_tabuleiro_v8(vetor);

        printf("voce venceu!\nate a proxima.\n");
    }
    
 return 0; 

}