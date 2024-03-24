#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_STR 50

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef enum
{
    info,
    mamb,
    mec,
    tads,
    tga,
    csoc,
} enum_turma;

typedef enum
{
    goleiro, 
    alaD, 
    alaE, 
    fixo,
    pivo
} enum_posicoes;

typedef struct
{
    char *nome;
    enum_turma curso;
    int ano;
} TTurma;

typedef struct 
{
    char *nome;
    TData data_nascimento;
    enum_posicoes *posicoes; 
    char *turma;
    char *matricula;
    int num_camisa;
    int num_posicoes;
} TJogador;

typedef struct 
{
    char *nome;
    char *tecnico;
    TJogador *jogadores;
    int numJogadores;
    char **turma;
    int numTurmas;
} TTime;

TTurma *_vetorTurmas;
int numTurmas;
TTime *_vetorTimes;
int numTimes;

int salvamentoAutomatico;

void incializaPrograma();                // inicializa o programa

int exibeMenu();                         // exibe o menu inicial
int disparaMenu(int opcao);              // dispara as opções do menu inicial
int confirmaSaida();                     // confirma se o usuário deseja encerrar o programa
int menuDois(char *str);                 // exibe as opções do menu time e turma

int menuSalvar();                        // exibe as opções do salvamento automático
void disparaMenuSalvar(int opcao);       // dispara a opção selecionada
void salvaAutomatico(int secao);         // efetua o salvamento automático

void disparaTurma(int opcao);                                   // dispara as opções do menu turma
void incluiTurma();                                             // inclui uma turma no vetor de turmas
TTurma criaTurma();                                             // cria uma turma
enum_turma criaCurso(int selecao, int turma);                   // cria um curso para uma turma
int criaAno(int selecao, int turma);                            // cria um ano para uma turma
void criaNome(int selecao, char *nome, int turma, int comp);    // cria um nome para uma turma
int verificaNomeTurma(char *str, int comp);                     // verifica se o nome da turma ja existe

int menuListagemTurma();                // exibe as opções de listagem  
void disparaListagem(int opcao);            // dispara as opções do menu listagem
void listaTurma(TTurma turma);              // exibe uma turma
void listaTurmas();                         // exibe todas as turmas
void listaUmaTurma();                       // exibe uma turma selecionada
int perguntaTurma();                        // faz o usuário selecionar uma turma
void printaEnum(int e);                     // exibe a turma que a que o código enum se refere

int menuExclusao(int secao);                 // exibe o menu exclusao
void disparaExclusaoTurma(int opcao);        // dispara a exclusao de turma
void excluiUma(int selecao);                 // excluir uma turma especifica
int excluiTodas();                           // excluir todas as turmas
int verificaExistenciaTurma(char *str);      // verifica se uma turma existe em um time
int verificaExistenciaTurmas();              // verifica se alguma das turmas existe em um time
int confirmaExclusaoTurma(int opcao);        // confirma a exclusao
void excluiTurma(int turma);                 // exclui uma turma

void disparaAlteracaoTurma();                    // dispara a opcao alterar turma
int menuAlteracaoTurma();                        // exibe menu de alteração de turma
void alteraTurma(int opcao, int turma);          // realiza a alteração de um atributo de uma turma
void atualizaNomeTurma(int turma);               // altera o nome de uma turma
void alteraCurso(int turma);                     // altera o curso de uma turma
void alteraAno(int turma);                       // altera o ano de uma turma
char confirmaAlteracao();                        // confirma a alteração de um atributo de uma turma
int alteraNomeTurma(char *original, char *nome); // altera o nome da turma em um time caso ela esteja atribuída à ele
char procedeAlteracaoNomeTurma(char *str);       // verifica se o usuário deseja proceder a alteração do nome
void alteraTurmaJogador(int time, char *nome);   // altera o nome de uma turma em um jogador


void disparaTime(int opcao);                                // dispara opções do menu time
void incluiTime();                                          // inclui um time no vetor de times
TTime criaTime();                                           // cria um time
void criaNomeTime(char *strAux, int secao, int comp);       // cria o nome de um time
void criaTecnico(char *strAux, int secao);                  // cria o técnico de um time

void adicionaJogador(TTime *time);                            // adiciona um jogador a um time
void adicionaTurma(TTime *time, int selecao);                 // adiciona uma turma a um time
int verificaTurmaTime(TTime time);                            // verifica se a turma deve ser adicionado ao time

TJogador criaJogador(TTime time);                                       // cria um jogador
void criaNomeJogador(char *strAux, int secao, TTime time, int comp);    // cria um nome para um jogador
void criaMatricula(char *strAux);                                       // cria uma matrícula para o jogador
int verificaJogador(char *nome, TTime time, int comp);                  // verifica se o nome do jogador já existe
TData criaData(int secao);                                              // cria uma data de nascimento para um jogador
int criaCamisa(int secao, TTime time, int comp);                        // cria um número de camisa para um jogador
int verificaCamisa(int camisa, TTime time, int comp);                   // verifica se a camisa já pertence a outro jogador
void criaTurmaJogador(char *str, TTime time);                           // cria uma turma para um jogador
int verificaTurma(char *str, TTime time);                               // verifica se a turma a ser incluída em um jogador é válida
void exibeTurmasDisponiveis(TTime time);                                // exibe turmas disponiveis a serem selecionadas
int verificaNomeTime(char *str, int comp);                              // verifica se o nome do time já existe
void adicionaPosicao(TJogador *jogador);                                // adiciona a(s) posição(ões) ao jogador
enum_posicoes criaPosicao(TJogador *jogador, int comp);                 // cria a posição a ser adicionada
int verificaPosicao(char *str);                                         // verifica se a posição escolhida é válida
int verificaPosicaoTime(int posicao, TJogador *jogador, int comp);      // verifica se a posição já existe dentro do jogador
char confirmaPosicao();                                                 // pergunta se o usuário deseja adicionar outra posição

int menuListagemTime();                          // fornece as opções de listagem de time
void disparaListagemTime(int opcao);             // dispara as opções de listagem para time
void listaTimes();                               // lista todos os times
void listaTudoTimes();                           // lista tudo de todos os times
int perguntaTime();                              // faz o usuário selecionar um time
void listaTime(TTime time);                      // lista um time
void listaJogadores(TTime time);                 // lista Todos os Jogadores de um time
void listaJogador(TJogador jogador, int i);      // lista um jogador
void listaPosicoes(TJogador jogador, int num);   // lista as posicoes do jogador
void printaPosicao(int e);                       // converte o enum de posicao em texto

void disparaExclusaoTime(int opcao);                            // dispara a opcao de  exclusao de time
void excluiUm(int selecao);                                     // exclui um time selecionado
int excluiTodos();                                              // exclui todos os times
void excluiTime(int selecao);                                   // exclui um time
char confirmaExclusaoTime(int secao);                           // confirma se o usuário quer continuar com a exclusão
void mainAlteracaoTime();                                       // inicializa a alteração de time
int menuAlteracaoTime();                                        // exibe o menu de alteracao de time
void disparaAlteracaoTime(int opcao, int selecao);              // dispara a alteracao de time
void alteraNomeTime(int selecao);                               // altera o nome de um time
void alteraTecnico(int selecao);                                // altera o técnico de um time
int menuJogador();                                              // exibe o menu de atualização de jogador
void disparaJogador(int opcao, TTime *etime, int stime);        // dispara a opção selecioanda


int menuAlteraJogador();                                                          // exibe o menu de alteração de jogador
void disparaAlteracaoJogador(int opcao, int time, int selecao);                   // dispara a opção escolhida no menuAlteraJogador
void alteraNomeJogador(int time, int selecao);                                    // altera o nome de um jogador  
void alteraMatricula(int time, int selecao);                                      // altera a matricula de um jogador
void alteraCamisa(int time, int selecao);                                         // altera o num da camisa de um jogador          
void alteraData(int time, int selecao);                                           // altera a dt de nasc de um jogador
void atualizaTurmaJogador(int time, int selecao);                                 // altera a turma de um jogador

void excluiUmJogador(int time);                            // exclui um jogador selecionado
int alteraTurmaTime(int selecao, int time);                // verifica se é necessário excluir a turma do jogador excluído
void excluiTurmaTime(int time, int selecao);               // exclui uma turma de um time
void excluiJogador(int time, int selecao);                 // exclui um jogador
char confirmaExclusaoJogador();                            // verifica se o usuário deseja confirmar a exclusão
int perguntaJogador(int time);                             // faz o usuário selecionar um jogador

int menuPosicao();                                                              // exibe o menu de alteração de posição
void disparaPosicao(int opcao, int time, int selecao);                          // dispara a opção escolhida  
void alteraPosicao(int time, int selecao);                                      // altera a posição selecionada
void excluiUmaPosicao(int time, int selecao);                                   // exclui uma posição escolhida pelo usuário
void excluiPosicao(int time, int selecao, int posicao);                         // exclui uma posição
void exibePosicoes(TJogador jogador);                                           // exibe as posições disponíveis para seleção
int perguntaPosicao(TJogador jogador);                                          // faz o usuário selecionar uma posição
int verificaExistenciaPosicao(TJogador jogador, enum_posicoes posicao);         //verifica se a posição existe dentor do jogador
char confirmaExclusaoPosicao();                                                 // confirma se o usuário quer excluir a posição

void exibeTimes();                          // exibe os nomes dos times
int verificaCaracteres(char *str);          // verifica se há caracteres especiais
void exibeTurmas();                         // exibe os nomes das turmas
void exibeJogadores(int selecao);           // exibe os nomes dos jogadores
int validaData(int dia, int mes, int ano);  // valida uma data
int validaAno(int ano);                     // valida um ano  
int converteEnum(char *str);                // converte uma string em um valor enum (turma)
void mensagensErro(int erro);               // exibe as mensagens de erro
void mensagensSucesso(int sucesso);         // exibe as mensagens de sucesso

// libera as alocações dinâmicas
void liberaTurmas();
void liberaTurma(int turma);
void liberaTimes();
void liberaTime(int time);
void liberaJogadores(int time);
void liberaTurmasTime(int time);
void liberaJogador(int time, int jogador);

void salvaTurmas();         // salva as turmas em um arquivo
void salvaTimes();          // salva os times em um arquivo
void recuperaTurmas();      // recupera os dados salvos de turmas no arquivo
void recuperaTimes();       // recupera os dados salvos de times no arquivo

void finalizaPrograma();    // finaliza o programa

// funções inciais

int main(void)
{
    int opcao;

    incializaPrograma();

    do
    {
        opcao = disparaMenu(exibeMenu());
    } while(opcao != 0);

    finalizaPrograma();

    return 0;
}
void incializaPrograma()
{
    int opcao;

    system("cls");

    _vetorTurmas = (TTurma *) malloc(1 * sizeof(TTurma));
    if(!_vetorTurmas)
    {
        mensagensErro(0);
        exit(1);
    }
    numTurmas = 0;
    _vetorTimes = (TTime *) malloc(1 * sizeof(TTime));
    if(!_vetorTimes)
    {
        mensagensErro(1);
        exit(1);
    }
    numTimes = 0;

    salvamentoAutomatico = 0;

    recuperaTurmas();
    recuperaTimes();

    mensagensSucesso(2);
}

int exibeMenu()
{
    int opcao;

    printf("\n***MENU INICIAL***\n");
    printf("\n(1) - Turma");
    printf("\n(2) - Time");
    printf("\n(3) - Salvamento Automatico");
    printf("\n(4) - Sair");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
int disparaMenu(int opcao)
{  
    int op;

    if(opcao == 1)
    {
        while(op != 5)
        {
            op = menuDois("turma");
            disparaTurma(op);   
        } 
    }
    else if (opcao == 2)
    {
        if(numTurmas > 0)
        {
            while(op != 5)
            {
                op = menuDois("times");
                disparaTime(op);
            } 
        }
        else
        {
            mensagensErro(9);
        }
    }
    else if(opcao == 3)
    {
        while(op != 2)
        {
            op = menuSalvar();
            disparaMenuSalvar(op);
        } 
    } 
    else if(opcao == 4)
    {
        if(confirmaSaida() == 1)
        {
            return 0;
        }
    }
    else
    {
        mensagensErro(3);
    }

    return 1;
}
int confirmaSaida()
{
    char op;

    while(1)
    {
        printf("\nDeseja encerrar o programa? (s/n): ");
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);

        if(op == 's')
        {
            return 1;
        }
        else if(op == 'n')
        {
            return 0;
        }
        else
        {
            mensagensErro(20);
        }
    }

}
int menuDois(char *str)
{
    int opcao;

    printf("\n***MENU %s***\n", str == "turma" ? "TURMA" : "TIME");
    printf("\n(1) - Incluir");
    printf("\n(2) - Listar");
    printf("\n(3) - Alterar");
    printf("\n(4) - Excluir");
    printf("\n(5) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}

int menuSalvar()
{
    int opcao;

    printf("\n***SALVAMENTO AUTOMATICO***\n");
    printf("\nWARNING: O salvamento automatico contem um custo de processamento alto!!!");
    printf("\nESTADO ATUAL: %s\n", salvamentoAutomatico == 1 ? "ATIVADO" : "DESATIVADO");
    printf("\n(1) - %s", salvamentoAutomatico == 1 ? "Desativar" : "Ativar");
    printf("\n(2) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaMenuSalvar(int opcao)
{
    if(opcao == 1 && salvamentoAutomatico == 1)
    {
        salvamentoAutomatico = 0;
        printf("\nSALVAMENTO AUTOMÁTICO DESATIVADO!\n");
        system("PAUSE");
        system("cls");
    }
    else if(opcao == 1 && salvamentoAutomatico == 0)
    {
        salvamentoAutomatico = 1;
        printf("\nSALVAMENTO AUTOMÁTICO ATIVADO!\n");
        system("PAUSE");
        system("cls");
    }
    else if(opcao != 2)
    {
        mensagensErro(3);
    }
}
void salvaAutomatico(int secao)
{
    if(salvamentoAutomatico)
    {
        if(secao == 1)
        {
            salvaTurmas();
            mensagensSucesso(13);
        }
        else
        {
            salvaTimes();
            mensagensSucesso(13);
        }
    }
}

// funções turma

void disparaTurma(int opcao)
{
    int op;

    if(opcao == 1)
    {
        incluiTurma();
    }
    else if(opcao == 2)
    {
        if(numTurmas > 1)
        {
            while(op != 3)
            {
                op = menuListagemTurma();
                disparaListagem(op);
            }
        }
        else if(numTurmas > 0)
        {
            disparaListagem(2);
        }
        else
        {
            mensagensErro(9);
        }
    }
    else if(opcao == 3)
    {
        disparaAlteracaoTurma();
    }
    else if(opcao == 4)
    {
        if(numTurmas > 1)
        {   
            op = menuExclusao(1);
            disparaExclusaoTurma(op);
        }
        else if(numTurmas > 0)
        {
            excluiUm(0);
        }
        else
        {
            mensagensErro(9);
        }
    }
    else if(opcao != 5)
    {
        mensagensErro(3);
    }
}
void incluiTurma()
{
    _vetorTurmas[numTurmas] = criaTurma();
    numTurmas++;
    _vetorTurmas = (TTurma *) realloc(_vetorTurmas, (numTurmas + 1) * sizeof(TTurma)); 
    if(!_vetorTurmas)
    {
        mensagensErro(7);
        exit(1);
    }
    listaTurma(_vetorTurmas[numTurmas - 1]);
    mensagensSucesso(3);
    salvaAutomatico(1);
}
TTurma criaTurma()
{
    TTurma turma;
    char strAux[TAM_STR];

    printf("\n**CRIACAO DE TURMA** - (digite os dados da turma a ser incluida)\n\n");
    system("PAUSE");
    system("cls");

    criaNome(1, strAux, 0, -1);
    turma.nome = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(turma.nome, strAux);

    turma.curso = criaCurso(1, 0);

    turma.ano = criaAno(1, 0);

    return turma;
}
enum_turma criaCurso(int selecao, int turma)
{
    int validacao;
    char strAux[TAM_STR/2];

    while(1)
    {
        printf("\nCURSOS DISPONIVEIS: info - mamb - mec - tads - tga - csoc");
        if(selecao == 1)
        {
            printf("\nDigite o curso da turma: ");
        }
        else
        {  
            printf("\nDigite o novo curso da turma (%s): ", _vetorTurmas[turma].nome);
        }
        fflush(stdin);
        gets(strAux);
        system("cls");
        validacao = converteEnum(strAux);
        if(validacao >= 0)
        {
            return validacao;
        }
    }
}
int criaAno(int selecao, int turma)
{
    int ano;

    while(1)
    {   
        if(selecao == 1)
        {
            printf("\nDigite o ano da turma: ");
        }
        else
        {  
            printf("\nDigite o novo ano da turma (%s): ", _vetorTurmas[turma].nome);
        }
        scanf("%i", &ano);
        system("cls");
        if(validaAno(ano) == 1)
        {
            return ano;
        }
    }
}
void criaNome(int selecao, char *nome, int turma, int comp)
{
    while(1)
    { 
        if(selecao == 1)
        {
            printf("\nDigite o nome/apelido da turma: ");
        }
        else
        {  
            printf("\nDigite o novo nome/apelido da turma (%s): ", _vetorTurmas[turma].nome);
        }
        fflush(stdin);
        gets(nome);
        system("cls");
        if(verificaNomeTurma(nome, comp) == 1)
        {
            if(verificaCaracteres(nome) == 0)
            {
                break;
            }
        }
        else
        {
            mensagensErro(14);
        }
    }
}
int verificaNomeTurma(char *str, int comp)
{
    int i;
    for(i = 0; i < numTurmas; i++)
    {
        if(strcmp(str, _vetorTurmas[i].nome) == 0 && i != comp)
        {
            return 0;
            //nome da turma já existe
        }
    }

    return 1;
    //nome da turma não existe
}

int menuListagemTurma()
{
    int opcao;

    printf("\n***MENU LISTAGEM***\n");
    printf("\n(1) - Listar Uma Turma Especifica");
    printf("\n(2) - Listar Todas as Turmas");
    printf("\n(3) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaListagem(int opcao)
{
    if(opcao == 1)
    {
        listaUmaTurma();
    }
    else if(opcao == 2)
    {
        listaTurmas();
    }
    else if(opcao != 3)
    {
        mensagensErro(3);
    }
}
void listaTurmas()
{
    int i;
    for(i = 0; i < numTurmas; i++)
    {
        listaTurma(_vetorTurmas[i]);
        system("PAUSE");
        system("cls");
    }
}
void listaUmaTurma()
{
    int selecao = perguntaTurma();
    listaTurma(_vetorTurmas[selecao]);
    system("PAUSE");
    system("cls");
}
int perguntaTurma()
{
    char selecao[TAM_STR];
    int i;

    while(1)
    {
        exibeTurmas();
        printf("\nSelecione a turma: ");
        fflush(stdin);
        gets(selecao);
        system("cls");
        if(verificaNomeTurma(selecao, -1) == 0)
        {
            break;
        }
        mensagensErro(8);
    }


    for(i = 0; i < numTurmas; i++)
    {
        if(strcmp(selecao, _vetorTurmas[i].nome) == 0)
        {
            break;
        }
    }

    return i;
}
void listaTurma(TTurma turma)
{
    printf("\n***TURMA: %s***\n", turma.nome);
    printf("\nCurso da turma: ");
    printaEnum(turma.curso);
    printf("\nAno da turma: %i\n", turma.ano);
}
void printaEnum(int e)
{
    switch (e)
    {
        case 0:
        printf("info");
        break;

        case 1:
        printf("mamb");
        break;

        case 2:
        printf("mec");
        break;

        case 3:
        printf("tads");
        break;

        case 4:
        printf("tga");
        break;

        case 5:
        printf("csoc");
        break;
    }
}

int menuExclusao(int secao)
{
    int opcao;

    printf("\n***MENU EXCLUSAO***\n");
    printf("\n(1) - Excluir Um%s", secao == 1 ? "a Turma" : " Time");
    printf("\n(2) - Excluir Tod%s", secao == 1 ? "as as Turmas" : "os os Times");
    printf("\n(3) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaExclusaoTurma(int opcao)
{
    if(opcao == 1)
    {
        excluiUma(perguntaTurma());
    }
    else if(opcao == 2)
    {
        if(verificaExistenciaTurmas() == 0)
        {
            listaTurmas();
            confirmaExclusaoTurma(2) == 's' ? excluiTodas() : mensagensSucesso(6);
        }
        else
        {
            mensagensErro(24);
        }
    }
    else if(opcao != 3)
    {
        mensagensErro(3);
    }
}
void excluiUma(int selecao)
{
    if(verificaExistenciaTurma(_vetorTurmas[selecao].nome) == 1)
    {
        listaTurma(_vetorTurmas[selecao]);
        while(1)
        {
            if(confirmaExclusaoTurma(1) == 's')
            {
                excluiTurma(selecao);
                salvaAutomatico(1); 
                break;
            }
            else
            {
                mensagensSucesso(6);
                break;
            }
        } 
    }
    else
    {
        mensagensErro(19);
    }
}
int excluiTodas()
{
    int i, aux = numTurmas;

    for(i = 0; i < aux; i++)
    {
        excluiTurma(i);
    }
    salvaAutomatico(1);

    return 0;
}
int verificaExistenciaTurmas()   
{
    int i;

    for(i = 0; i < numTurmas; i++)  
    {
        if(verificaExistenciaTurma(_vetorTurmas[i].nome) == 0)
        {
            return 0;
        }
    }

    return 1;
}
int verificaExistenciaTurma(char *str)   
{
    int i, j;

    for(i = 0; i < numTimes; i++)  
    {
        for(j = 0; j < _vetorTimes[i].numTurmas; j++)
        {
            if(strcmp(str, _vetorTimes[i].turma[j]) == 0)
            {

                return 0;
            }
        }
    }

    return 1;
}

int confirmaExclusaoTurma(int opcao)
{
    char op = ' ';

    while(1)
    {
        printf("\nDeseja excluir %s ? (s/n): ", opcao == 1 ? "essa turma" : "todas as turmas");
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);
        if(op == 's' || op == 'n')
        {
            return op;
        }
        mensagensErro(20);
    }

}
void excluiTurma(int turma)
{
    for(turma; turma < numTurmas - 1; turma++)
    {
        _vetorTurmas[turma] = _vetorTurmas[turma + 1];
    }
    liberaTurma(turma);
    numTurmas--;
    mensagensSucesso(5);
}

void disparaAlteracaoTurma()
{
    int turma, op;

    if(numTurmas == 0)
    {
        mensagensErro(9);
    }
    else if(numTurmas == 1)
    {
        while(op != 4)
        {
            printf("\nTURMA A SER ALTERADA:\n");
            listaTurma(_vetorTurmas[0]);
            op = menuAlteracaoTurma();
            alteraTurma(op, 0);
        }
    }
    else
    {   
        turma = perguntaTurma();
        while(op != 4)
        {
            listaTurma(_vetorTurmas[turma]);
            op = menuAlteracaoTurma();
            alteraTurma(op, turma);
        }
    }
}
int menuAlteracaoTurma()
{
    int opcao;

    printf("\n***MENU ALTERACAO***\n");
    printf("\n(1) - Alterar Nome");
    printf("\n(2) - Alterar Curso");
    printf("\n(3) - Alterar Ano");
    printf("\n(4) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void alteraTurma(int opcao, int turma)
{
    if(opcao == 1)
    {
        atualizaNomeTurma(turma);
    }
    else if(opcao == 2)
    {
        alteraCurso(turma);
    }   
    else if(opcao == 3)
    {
        alteraAno(turma);
    }
    else if(opcao != 4)
    {
        mensagensErro(3);
    }
}
void atualizaNomeTurma(int turma)
{
    char strAux[TAM_STR];

    criaNome(2, strAux, turma, turma);
    if(confirmaAlteracao() == 's')
    {
        if(alteraNomeTurma(_vetorTurmas[turma].nome, strAux) == 1)
        {
            _vetorTurmas[turma].nome = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(_vetorTurmas[turma].nome, strAux);
            salvaAutomatico(1);
            listaTurma( _vetorTurmas[turma]);
            mensagensSucesso(7);
        }
    }
    else
    {
        mensagensSucesso(6);
    }
    
}
void alteraCurso(int turma)
{
    int numAux;

    numAux = criaCurso(2, turma);
    if(confirmaAlteracao() == 's')
    {
        _vetorTurmas[turma].curso = numAux;
        salvaAutomatico(1);
        listaTurma( _vetorTurmas[turma]);
        mensagensSucesso(7);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void alteraAno(int turma)
{
    int numAux;

    numAux = criaAno(2, turma);
    if(confirmaAlteracao() == 's')
    {
        _vetorTurmas[turma].ano = numAux;
        salvaAutomatico(1);
        listaTurma( _vetorTurmas[turma]);
        mensagensSucesso(7);
    }
    else
    {
        mensagensSucesso(6);
    }
}
char confirmaAlteracao()
{
    char op;
    while(1)
    {
        printf("\nDeseja confirmar alteracao ? (s/n): ");
        fflush(stdin);
        scanf("%c", &op);
        if(op == 's' || op == 'n')
        {
            return op;
        }
        mensagensErro(20);
    }
}
int alteraNomeTurma(char *original, char *nome)
{
    int i, j;
    char op = procedeAlteracaoNomeTurma(original);

    if(op == 's')
    {
        for(i = 0; i < numTimes; i++)
        {
            for(j = 0; j < _vetorTimes[i].numTurmas; j++)
            {
                if(strcmp(original, _vetorTimes[i].turma[j]) == 0)
                {
                    _vetorTimes[i].turma[j] = (char *) realloc(NULL, (strlen(nome) + 1) * sizeof(char));
                    strcpy(_vetorTimes[i].turma[j], nome);
                    alteraTurmaJogador(i, nome);
                }
            }
        }

        return 1;
    }
    else if (op == 'x')
    {
        return 1;
    }
    else
    {
        mensagensSucesso(6);
        return 0;
    }
}
char procedeAlteracaoNomeTurma(char *str)
{
    int i, j;
    char op = 'x';


    if(verificaExistenciaTurma(str) == 0)
    {
        while(1)
        {
            printf("\nAVISO: o nome desta turma ja esta cadastrado no time %s, ", str);
            printf("deseja proceder com a alteracao ? (s/n): ");
            fflush(stdin);
            scanf("%c", &op);
            op = tolower(op);

            if(op == 's' || op == 'n')
            {
                if(op == 'n')
                {
                    return op;
                }
                break;
            }
            mensagensErro(20);
        }
    }

    return op;
}
void alteraTurmaJogador(int time, char *nome)
{
    int i;
    for(i = 0; i < _vetorTimes[time].numJogadores; i++)
    {
        _vetorTimes[time].jogadores[i].turma = (char *) realloc(NULL, (strlen(nome) + 1) * sizeof(char));
        strcpy(_vetorTimes[time].jogadores[i].turma, nome);
    }
}

// funções time

void disparaTime(int opcao)
{
    int op;

    if(opcao == 1)
    {
        incluiTime();
    }
    else if(opcao == 2)
    {
        if(numTimes >= 1)
        {
            while(op != 7)
            {
                op = menuListagemTime();
                disparaListagemTime(op);
            }
        }
        else
        {
            mensagensErro(16);
        }
    }
    else if(opcao == 3)
    {
        mainAlteracaoTime();
    }
    else if(opcao == 4)
    {
        if(numTimes > 1)
        {

            op = menuExclusao(2);
            disparaExclusaoTime(op);
        }
        else if(numTimes == 1)
        {
            excluiUm(0);
        }
        else
        {
            mensagensErro(16);
        }
    }
    else if(opcao != 5)
    {
        mensagensErro(3);
    }
}

void incluiTime()
{
    _vetorTimes[numTimes] = criaTime();
    numTimes++;
    _vetorTimes = realloc(_vetorTimes, (numTimes + 1) * sizeof(TTime));
    if(!_vetorTimes)
    {
        mensagensErro(21);
    }
    listaTime(_vetorTimes[numTimes - 1]);
    listaJogadores(_vetorTimes[numTimes - 1]);
    mensagensSucesso(4);
    salvaAutomatico(2);
}
TTime criaTime()
{
    TTime time;
    char strAux[TAM_STR * 2];

    printf("\n**CRIACAO DE TIME** - (digite os dados do time a ser incluido)\n\n");
    system("PAUSE");
    system("cls");

    criaNomeTime(strAux, 1, -1);
    time.nome = (char *) malloc( ( (strlen(strAux)) + 1) * sizeof(char));
    strcpy(time.nome, strAux);

    criaTecnico(strAux, 1);
    time.tecnico = (char *) malloc( ( (strlen(strAux)) + 1) * sizeof(char));
    strcpy(time.tecnico, strAux);
    system("cls");

    time.numTurmas = 0;
    time.numJogadores = 0;
    adicionaJogador(&time);

    return time;
}
void criaNomeTime(char *strAux, int secao, int comp)
{
    while(1)
    {
        printf("\nDigite o%snome do time: ", secao == 1 ? " " : " novo ");
        fflush(stdin);
        gets(strAux);
        system("cls");
        if(verificaNomeTime(strAux, comp) == 1)
        {
            if(verificaCaracteres(strAux) == 0)
            {
                break;
            }
        }
        else
        {
            mensagensErro(18);   
        }
    }
}
void criaTecnico(char *strAux, int secao)
{
    while(1)
    {
        printf("\nDigite o%stecnico do time: ", secao == 1 ? " " : " novo ");
        fflush(stdin);
        gets(strAux);
        if(verificaCaracteres(strAux) == 0)
        {
            break;
        }
    }
}

void adicionaJogador(TTime *time)
{
    char op = 's';
    if(time->numJogadores == 0)
    {
        time->jogadores = (TJogador *) malloc(1 * sizeof(TJogador));
        if(!time->jogadores)
        {
            mensagensErro(15);
        }
    }

    while(op != 'n')
    {
        if(op == 's')
        {
            time->jogadores[time->numJogadores] = criaJogador(*time);
            time->numJogadores++;
            time->jogadores = (TJogador *) realloc(time->jogadores, (time->numJogadores + 1) * sizeof(TJogador));
            if(!time->jogadores)
            {
                mensagensErro(22);
            }
            adicionaTurma(time, time->numJogadores - 1);
        }
        if(time->numJogadores < 10)
        {
            printf("\nDeseja adicionar outro jogador? (s/n): ");
            fflush(stdin);
            scanf("%c", &op);
            op = tolower(op);
            system("cls");
        }
        else
        {
            printf("\nQUANTIDADE LIMITE DE JOGADORES AITNGIDA! (10)\n");
            system("PAUSE");
            system("cls");
            op = 'n';
        }
    }
}
void adicionaTurma(TTime *time, int selecao)
{   
    if(time->numTurmas == 0)
    {
        time->turma = (char **) malloc(1 * sizeof(char *));
        if(!time->turma)
        {
            mensagensErro(15);
        }
    }
    if(verificaTurmaTime(*time) == 1)
    {
        time->turma[time->numTurmas] = (char *) malloc( (strlen(time->jogadores[selecao].turma) + 1 ) * sizeof(char));
        strcpy(time->turma[time->numTurmas], time->jogadores[selecao].turma);
        time->numTurmas++;
        time->turma = (char **) realloc(time->turma, (time->numTurmas + 1) * sizeof(char *));
        if(!time->turma)
        {
            mensagensErro(23); 
        }
    }
}
int verificaTurmaTime(TTime time)
{
    int i;

    for(i = 0; i < time.numTurmas; i++)
    {
        if(strcmp(time.jogadores[time.numJogadores - 1].turma, time.turma[i]) == 0)
        {
            return 0;
        }
    }

    return 1;
}
TJogador criaJogador(TTime time)
{
    TJogador jogador;
    char strAux[TAM_STR * 2];
    int turma;

    printf("\n**CRIACAO DE JOGADOR** - (digite os dados do jogador a ser incluida)\n\n");
    system("PAUSE");
    system("cls");

    criaNomeJogador(strAux, 1, time, -1);
    jogador.nome = (char *) malloc( ( (strlen(strAux)) + 1) * sizeof(char));
    strcpy(jogador.nome, strAux);

    jogador.data_nascimento = criaData(1); //verificar

    criaTurmaJogador(strAux, time);
    jogador.turma = (char *) malloc( ( (strlen(strAux)) + 1) * sizeof(char));
    strcpy(jogador.turma, strAux);

    jogador.posicoes = (enum_posicoes *) malloc(1 * sizeof(enum_posicoes));
    if(!jogador.posicoes)
    {
        mensagensErro(26);
    }
    jogador.num_posicoes = 0;
    adicionaPosicao(&jogador);

    criaMatricula(strAux);
    jogador.matricula = (char *) malloc( ( (strlen(strAux)) + 1) * sizeof(char));
    strcpy(jogador.matricula, strAux);
    system("cls");

    jogador.num_camisa = criaCamisa(1, time, -1);

    return jogador;
}
void criaMatricula(char *strAux)
{   
    while(1)
    {
        printf("\nDigite a matricula do jogador: ");
        fflush(stdin);
        gets(strAux);
        if(verificaCaracteres(strAux) == 0)
        {
            break;
        }
    }
}
void criaNomeJogador(char *strAux, int secao, TTime time, int comp)
{
    while(1)
    {
        printf("\nDigite o%snome do jogador: ", secao == 1 ? " " : " novo ");
        fflush(stdin);
        gets(strAux);
        system("cls");
        if(verificaJogador(strAux, time, comp) == 1)
        {
            if(verificaCaracteres(strAux) == 0)
            {
                break;
            }
        } 
        else
        { 
            mensagensErro(34);
        }
    }
}
int verificaJogador(char *nome, TTime time, int comp)
{
    int i;

    for(i = 0; i < time.numJogadores; i++)
    {
        if(strcmp(nome, time.jogadores[i].nome) == 0 && i != comp)
        {
            return 0;   // nome já existe
        }
    }

    return 1;   // nome não existe
}
TData criaData(int secao)
{
    TData data;

    while(1)
    {
        printf("\nDigite a%sdata de nascimento do jogador (D/M/A): ", secao == 1 ? " " : " nova ");
        scanf("%i %i %i", &data.dia, &data.mes, &data.ano);
        system("cls");
        if(validaData(data.dia, data.mes, data.ano) == 1)
        {
            return data;
        }
        mensagensErro(10);
    }
}
int criaCamisa(int secao, TTime time, int comp)
{
    int num_camisa;

    while(1)
    {
        printf("\nDigite a%scamisa do jogador: ", secao == 1 ? " " : " nova ");
        scanf("%i", &num_camisa);
        system("cls");
        if(num_camisa >= 0)
        {
            if(verificaCamisa(num_camisa, time, comp))
            {
                return num_camisa;
            }
            else
            {
                mensagensErro(36);
            }
        }
        else
        {
            mensagensErro(13);
        }
        
    }
}
int verificaCamisa(int camisa, TTime time, int comp)
{
    int i;

    for(i = 0; i < time.numJogadores; i++)
    {
        if(camisa == time.jogadores[i].num_camisa && i != comp)
        {
            return 0;   // camisa já existe no time
        }
    }

    return 1;   // camisa não existe no time
}

void criaTurmaJogador(char *str, TTime time)
{
    while(1)
    {   
        time.numTurmas < 2 ? exibeTurmas() : exibeTurmasDisponiveis(time);

        printf("\nDigite a turma do jogador (nome da turma): ");
        fflush(stdin);
        gets(str);
        system("cls");

        if(verificaTurma(str, time) == 1)
        {
            break;
        }
    }
}
int verificaTurma(char *str, TTime time)
{
    int i;

    if(verificaNomeTurma(str, -1) == 0)
    {
        if(time.numTurmas < 2)
        {
            return 1;
            //pode ser adicionado
        }
        else
        {
            for(i = 0; i < time.numTurmas; i++)
            {
                if(strcmp(str, time.turma[i]) == 0)
                {
                    return 1;
                    //já existe
                }
            }
            mensagensErro(12);
            return 0;
            //não existe nas turmas do time, ultrapassa o limite
        }   
    }
    mensagensErro(11);
    return 0;
    //não existe no vetor de turmas
}
void exibeTurmasDisponiveis(TTime time)
{
    int i;
    printf("\nTurmas disponiveis: ");
    for(i = 0; i < time.numTurmas; i++)
    {
        printf("%s %c ", time.turma[i], i != (time.numTurmas - 1) ? '-' : ' ');
    }
}
int verificaNomeTime(char *str, int comp)
{
    int i;
    for(i = 0; i < numTimes; i++)
    {
        if(strcmp(str, _vetorTimes[i].nome) == 0 & i != comp)
        {
            return 0;
            //nome do time já existe
        }
    }

    return 1;
    //nome do time não existe
}

void adicionaPosicao(TJogador *jogador)
{
    char op = 's';

    while(op != 'n')
    {
        if(op == 's')
        {
            jogador->num_posicoes++;
            jogador->posicoes[jogador->num_posicoes - 1] = criaPosicao(jogador, -1);
            jogador->posicoes = (enum_posicoes *) realloc(jogador->posicoes, (jogador->num_posicoes + 1) * sizeof(enum_posicoes));
            if(!jogador->num_posicoes)
            {
                mensagensErro(22);
            }
        }
        if(jogador->num_posicoes < 5)
        {
           op = confirmaPosicao();
        }
        else
        {
            printf("\nQUANTIDADE LIMITE DE POSICOES ATINGIDA! (5)\n");
            system("PAUSE");
            system("cls");
            break;
        }
    }
}
char confirmaPosicao()
{
    char op;

    while(1)
    {
        printf("\nDeseja adicionar outra posicao? (s/n): ");
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);
        if(op != 's' && op != 'n')
        {
            mensagensErro(20);
            continue;
        }
        system("cls");

        return op;
    }
}
enum_posicoes criaPosicao(TJogador *jogador, int comp)
{
    enum_posicoes posicao;
    char str[TAM_STR/2];

    while(1)
    {   
        printf("\nPosicoes disponiveis: goleiro, ala D, ala E, fixo e pivo");

        printf("\nDigite a posicao do jogador: ");
        fflush(stdin);
        gets(str);
        posicao = verificaPosicao(str);
        if(posicao != -1)
        {
            if(verificaPosicaoTime(posicao, jogador, comp) == 1)
            {
                return posicao;
            }
            else
            {
                mensagensErro(35);
            }
        }
    }
}
int verificaPosicao(char *str)
{
    int e;

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    if (strcmp(str, "goleiro") == 0)
    {
        e = 0;
    }
    else if (strcmp(str, "ala d") == 0 || strcmp(str, "alad") == 0)
    {
        e = 1;
    }
    else if (strcmp(str, "ala e") == 0 || strcmp(str, "alae") == 0)
    {
        e = 2;
    }
    else if (strcmp(str, "fixo") == 0)
    {
        e = 3;
    }
    else if (strcmp(str, "pivô") == 0 || strcmp(str, "pivo") == 0)
    {
        e = 4;
    }
    else
    {
        e = -1;
        mensagensErro(25);
    }

    return e;

}
int verificaPosicaoTime(int posicao, TJogador *jogador, int comp)
{
    int i;
    
    for(i = 0; i < jogador->num_posicoes - 1; i++)
    {
        if(posicao == jogador->posicoes[i] && i != comp)
        {
            return 0;   // posição já existe no jogador
        }
    }

    return 1;   // posição não existe no jogador
}

int menuListagemTime()
{
    int opcao;

    printf("\n***MENU LISTAGEM***\n");
    printf("\n(1) - Listar Um Time");
    printf("\n(2) - Listar Todos os Times");
    printf("\n(3) - Listar Um Jogador");
    printf("\n(4) - Listar Todos os Jogadores");
    printf("\n(5) - Listar Tudo de Um Time");
    printf("\n(6) - Listar Tudo de Todos os Times");
    printf("\n(7) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaListagemTime(int opcao)
{
    int jogador, time, i;

    if(opcao == 1)
    {
        if(numTimes > 1)
        {
            listaTime(_vetorTimes[perguntaTime()]);
            system("PAUSE");
            system("cls");
        }
        else
        {
            listaTime(_vetorTimes[0]);
            system("PAUSE");
            system("cls");
        }
    }
    else if(opcao == 2)
    {
        listaTimes();
    }
    else if(opcao == 3)
    {
        if(numTimes > 1)
        {
            time = perguntaTime();
        }
        else
        {   
            time = 0;
        }

        if(_vetorTimes[time].numJogadores > 1)
        {
            jogador = perguntaJogador(time);
        }
        else
        {
            jogador = 0;
        }
        listaJogador(_vetorTimes[time].jogadores[jogador], jogador + 1);
        system("PAUSE");
        system("cls");
    }
    else if(opcao == 4)
    {
        if(numTimes > 1)
        {
            time = perguntaTime();
        }
        else
        {   
            time = 0;
        }

        for(i = 0; i < _vetorTimes[time].numJogadores; i++)
        {
            listaJogador(_vetorTimes[time].jogadores[i], (i + 1));
            system("PAUSE");
            system("cls");
        }
    }
    else if(opcao == 5)
    {
        if(numTimes > 1)
        {
            time = perguntaTime();
        }
        else
        {
            time = 0;
        }
        
        listaTime(_vetorTimes[time]);
        listaJogadores(_vetorTimes[time]);
        system("PAUSE");
        system("cls");
    }
    else if(opcao == 6)
    {
        listaTudoTimes();
    }
    else if(opcao != 7)
    {
        mensagensErro(3);
    }
}
void listaTimes()
{
    int i;
    for(i = 0; i < numTimes; i++)
    {
        listaTime(_vetorTimes[i]);
        system("PAUSE");
        system("cls");
    }
}
void listaTudoTimes()
{   
    int i;

    for(i = 0; i < numTimes; i++)
    {
        listaTime(_vetorTimes[i]);
        listaJogadores(_vetorTimes[i]);
        system("PAUSE");
        system("cls");
    }
}
int perguntaTime()
{
    char selecao[TAM_STR];
    int i;

    while(1)
    {
        exibeTimes();
        printf("\nSelecione o time: ");
        fflush(stdin);
        gets(selecao);
        system("cls");
        if(verificaNomeTime(selecao, -1) == 0)
        {
            break;
        }
        mensagensErro(17);
    }
    // analisar maneira de otimizar as duas partes em uma só
    for(i = 0; i < numTimes; i++)
    {
        if(strcmp(selecao, _vetorTimes[i].nome) == 0)
        {
            break;
        }
    }

    return i;
}
void listaTime(TTime time)
{
    int i;

    printf("\n***TIME: %s***", time.nome);
    printf("\nTecnico do time: %s\n", time.tecnico);
    for(i = 0; i < time.numTurmas; i++)
    {
        printf("\nNome da turma[%i]: %s", (i + 1), time.turma[i]);
    }
    printf("\n");
}
void listaJogadores(TTime time)
{
    int i;

    for(i = 0; i < time.numJogadores; i++)
    {
        listaJogador(time.jogadores[i], (i + 1));
    }
}
void listaJogador(TJogador jogador, int num)
{
    printf("\nNome do jogador[%i]: %s", num, jogador.nome);
    printf("\nData de nasc do jogador[%i]: %i/%i/%i", num, jogador.data_nascimento.dia, jogador.data_nascimento.mes, jogador.data_nascimento.ano);
    listaPosicoes(jogador, num);
    printf("\nMatricula do jogador[%i]: %s", num, jogador.matricula);
    printf("\nTurma do jogador[%i]: %s", num, jogador.turma);
    printf("\nCamisa do jogador[%i]: %i\n", num, jogador.num_camisa);
}
void listaPosicoes(TJogador jogador, int num)
{
    int i;

    for(i = 0; i < jogador.num_posicoes; i++)
    {
        printf("\nPosicao [%i] do jogador[%i]: ", (i + 1), num);
        printaPosicao(jogador.posicoes[i]);
    }
}
void printaPosicao(int e)
{
    switch (e)
    {
        case 0:
        printf("goleiro");
        break;

        case 1:
        printf("ala D");
        break;

        case 2:
        printf("ala E");
        break;

        case 3:
        printf("fixo");
        break;

        case 4:
        printf("pivo");
        break;
    }
}

void disparaExclusaoTime(int opcao)
{
    if(opcao == 1)
    {
        excluiUm(perguntaTime());
    }
    else if(opcao == 2)
    {
        listaTimes();
        confirmaExclusaoTime(2) == 's' ? excluiTodos() : mensagensSucesso(6);
    }
    else if(opcao != 3)
    {
        mensagensErro(3);
    }
}
void excluiUm(int selecao)
{
    listaTime(_vetorTimes[selecao]);
    if(confirmaExclusaoTime(1) == 's')
    {
        excluiTime(selecao);
        salvaAutomatico(2);
    }
    else
    {
        mensagensSucesso(6);
    }
}
int excluiTodos()
{
    int i, aux = numTimes;

    for(i = 0; i < aux; i++)
    {
        excluiTime(i);
    }
    salvaAutomatico(2);

    return 0;
}
void excluiTime(int selecao)
{
    for(selecao; selecao < numTimes - 1; selecao++)
    {
        _vetorTimes[selecao] = _vetorTimes[selecao + 1];
    }
    liberaTime(selecao);
    numTimes--;
    mensagensSucesso(10);
}
char confirmaExclusaoTime(int secao)
{
    char op = ' ';

    while(1)
    {
        printf("\nDeseja excluir %s ? (s/n): ", secao == 1 ? "esse time" : "todos os times");
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);
        system("cls");
        if(op == 's' || op == 'n')
        {
            return op;
        }
        mensagensErro(20);
    }
}


void mainAlteracaoTime()
{
    int selecao, op = 0;

    if(numTimes == 0)
    {
        mensagensErro(16);
        op = 4;
    }
    else if(numTimes == 1)
    {
        selecao = 0; 
    }
    else
    {   
        selecao = perguntaTime();
    }

    while(op != 4)
    {
        printf("\nTIME A SER ALTERADO:\n");
        listaTime(_vetorTimes[selecao]);
        op = menuAlteracaoTime();
        disparaAlteracaoTime(op, selecao);
    }
}
int menuAlteracaoTime()
{
    int opcao;

    printf("\n***MENU ALTERACAO***\n");
    printf("\n(1) - Alterar Nome");
    printf("\n(2) - Alterar Tecnico");
    printf("\n(3) - Alterar Jogadores");
    printf("\n(4) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaAlteracaoTime(int opcao, int selecao)
{
    char strAux[TAM_STR * 2];
    int op;

    if(opcao == 1)
    {
        alteraNomeTime(selecao);
    }
    else if(opcao == 2)
    {
        alteraTecnico(selecao);
    }
    else if(opcao == 3)
    {
        while(op != 4)
        {
            op = menuJogador();
            disparaJogador(op, &_vetorTimes[selecao], selecao);
        }
    }
    else if(opcao != 4)
    {
        mensagensErro(3);
    }
}
void alteraNomeTime(int selecao)
{
    char strAux[TAM_STR * 2];

    criaNomeTime(strAux, 2, selecao);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[selecao].nome =  realloc(NULL, (strlen(strAux) + 1) * sizeof(char));
        strcpy(_vetorTimes[selecao].nome, strAux);
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaTime(_vetorTimes[selecao]);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void alteraTecnico(int selecao)
{
    char strAux[TAM_STR * 2];

    criaTecnico(strAux, 2);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[selecao].tecnico = realloc(NULL, (strlen(strAux) + 1) * sizeof(char));
        strcpy(_vetorTimes[selecao].tecnico, strAux);
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaTime(_vetorTimes[selecao]);
    }
    else
    {
        mensagensSucesso(6);
    }
}
int menuJogador()
{
    int opcao;

    printf("\n***MENU JOGADOR***\n");
    printf("\n(1) - Incluir Novo Jogador");
    printf("\n(2) - Alterar Jogador");
    printf("\n(3) - Excluir jogador");
    printf("\n(4) - Voltar");

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaJogador(int opcao, TTime *etime, int stime)
{
    int op, selecao;

    if(opcao == 1)
    {
        adicionaJogador(etime);
        if(confirmaAlteracao() == 's')
        {
            mensagensSucesso(7);
            salvaAutomatico(2);
        }
        else
        {
            mensagensSucesso(6);
            excluiJogador(stime, etime->numJogadores - 1);
        }
    }
    else if(opcao == 2)
    {
        if(etime->numJogadores > 1)
        {
            selecao = perguntaJogador(stime);    
        }
        else
        {
            selecao = 0;
        }

        while(op != 7)
        {
            printf("\nJOGADOR A SER ALTERADO:\n");
            listaJogador(_vetorTimes[stime].jogadores[selecao], selecao + 1);
            op = menuAlteraJogador();
            disparaAlteracaoJogador(op, stime, selecao);
        }
    }
    else if(opcao == 3)
    {
        if(etime->numJogadores >= 2)
        {
            excluiUmJogador(stime);
        }
        else
        {
            mensagensErro(28);
        }
    }
    else if(opcao != 4)
    {
        mensagensErro(3);
    }
}

int menuAlteraJogador()
{
    int opcao;

    printf("\n***MENU JOGADOR***\n");
    printf("\n(1) - Alterar Nome ");
    printf("\n(2) - Alterar Matricula");
    printf("\n(3) - Alterar Numero da Camisa");
    printf("\n(4) - Alterar Posicao"); // numPosicoes
    printf("\n(5) - Alterar Data de nascimento");
    printf("\n(6) - Alterar Turma");
    printf("\n(7) - Voltar");


    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaAlteracaoJogador(int opcao, int time, int selecao)
{
    int op = 0;

    if(opcao == 1)
    {
        alteraNomeJogador(time, selecao);
    }
    else if(opcao == 2)
    {
        alteraMatricula(time, selecao);
    }
    else if(opcao == 3)
    {
        alteraCamisa(time, selecao);
    }
    else if (opcao == 4)
    {
        while(op != 4)
        {
            op = menuPosicao();
            disparaPosicao(op, time, selecao);
        }
    }   
    else if(opcao == 5)
    {
        alteraData(time, selecao);
    }   
    else if(opcao == 6)
    {
        
    }
    else if(opcao != 7)
    {
        mensagensErro(3);
    }
}
void alteraNomeJogador(int time, int selecao)
{
    char strAux[TAM_STR * 2];

    criaNomeJogador(strAux, 2, _vetorTimes[time], selecao);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].nome = realloc(NULL, (strlen(strAux) + 1) * sizeof(char));
        strcpy(_vetorTimes[time].jogadores[selecao].nome, strAux);
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaJogador(_vetorTimes[time].jogadores[selecao], selecao + 1);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void alteraMatricula(int time, int selecao)
{
    char strAux[TAM_STR * 2];

    criaMatricula(strAux);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].matricula = realloc(NULL, ( (strlen(strAux)) + 1) * sizeof(char));
        strcpy(_vetorTimes[time].jogadores[selecao].matricula, strAux);
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaJogador(_vetorTimes[time].jogadores[selecao], selecao + 1);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void alteraCamisa(int time, int selecao)
{
    int numAux;

    numAux = criaCamisa(2, _vetorTimes[time], selecao);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].num_camisa = numAux;
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaJogador(_vetorTimes[time].jogadores[selecao], selecao + 1);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void alteraData(int time, int selecao)
{
    TData dataAux;

    dataAux = criaData(2);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].data_nascimento = dataAux;
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaJogador(_vetorTimes[time].jogadores[selecao], selecao + 1);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void atualizaTurmaJogador(int time, int selecao)
{
    char strAux[TAM_STR];

    criaTurmaJogador(strAux, _vetorTimes[time]);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].turma = realloc(NULL, ( (strlen(strAux)) + 1) * sizeof(char));
        strcpy(_vetorTimes[time].jogadores[selecao].turma, strAux);
        adicionaTurma(&_vetorTimes[time], selecao);
        mensagensSucesso(7);
        salvaAutomatico(2);
        listaJogador(_vetorTimes[time].jogadores[selecao], selecao + 1);
    }
    else
    {
        mensagensSucesso(6);
    }
}

int menuPosicao()
{
    int opcao;

    printf("\n***MENU POSICAO***\n");
    printf("\n(1) - Adiciona Posicao ");
    printf("\n(2) - Alterar Posicao");
    printf("\n(3) - Excluir Posicao");
    printf("\n(4) - Voltar"); 

    printf("\n\nSelecione a opcao: ");
    scanf("%i", &opcao);
    system("cls");

    return opcao;
}
void disparaPosicao(int opcao, int time, int selecao)
{
    int op;

    if(opcao == 1)
    {
        if(_vetorTimes[time].jogadores[selecao].num_posicoes < 5)
        {
            adicionaPosicao(&_vetorTimes[time].jogadores[selecao]);
            if(confirmaAlteracao() == 's')
            {
                mensagensSucesso(7);
                salvaAutomatico(2);
            }
            else
            {
                excluiPosicao(time, selecao, _vetorTimes[time].jogadores[selecao].num_posicoes - 1);
                mensagensSucesso(6);
            }
        }
        else
        {
            mensagensErro(30);
        }
    }
    else if(opcao == 2)
    {
        alteraPosicao(time, selecao);
    }
    else if(opcao == 3)
    {
        if(_vetorTimes[time].jogadores[selecao].num_posicoes > 1)
        {
            excluiUmaPosicao(time, selecao);
        }
        else
        {
            mensagensErro(33);
        }
    }
    else if(opcao != 4)
    {
        mensagensErro(3);
    }
}

void alteraPosicao(int time, int selecao)
{
    enum_posicoes posicaoAux;
    int posicao;

    posicao = perguntaPosicao(_vetorTimes[time].jogadores[selecao]);

    posicaoAux = criaPosicao(&_vetorTimes[time].jogadores[selecao], posicao);
    if(confirmaAlteracao() == 's')
    {
        _vetorTimes[time].jogadores[selecao].posicoes[posicao] = posicaoAux;
        mensagensSucesso(7);
        salvaAutomatico(2);
    }
    else
    {
        mensagensSucesso(6);
    }
}

void excluiUmaPosicao(int time, int selecao)
{
    int posicao = perguntaPosicao(_vetorTimes[time].jogadores[selecao]);

    printaPosicao(posicao);
    if(confirmaExclusaoPosicao() == 's')
    {
        excluiPosicao(time, selecao, posicao);
        salvaAutomatico(2);
    }
    else
    {
        mensagensSucesso(6);
    }
}
void excluiPosicao(int time, int selecao, int posicao)
{
    for(posicao; posicao < _vetorTimes[time].jogadores[selecao].num_posicoes - 1; posicao++)
    {
        _vetorTimes[time].jogadores[posicao].posicoes[posicao] = _vetorTimes[time].jogadores[posicao].posicoes[posicao + 1];
    }
    _vetorTimes[time].jogadores[selecao].num_posicoes--;
    mensagensSucesso(12);
}
void exibePosicoes(TJogador jogador)
{
    int i;

    printf("\nPosicoes disponiveis: | ");
    for(i = 0; i < jogador.num_posicoes; i++)
    {
        printaPosicao(jogador.posicoes[i]);
        printf(" %c ", i != (jogador.num_posicoes - 1) ? '-' : '|');
    }   
}
int perguntaPosicao(TJogador jogador)
{
    char str[TAM_STR];
    int verificacao;

    exibePosicoes(jogador);

    while(1)
    {
        printf("\nSelecione a posicao: ");
        fflush(stdin);
        gets(str);
        verificacao = verificaPosicao(str);

        if( verificaExistenciaPosicao(jogador, verificacao ) == 1)
        {
            return verificacao;
        }
        mensagensErro(32);
    }
}
int verificaExistenciaPosicao(TJogador jogador, enum_posicoes posicao)
{
    int i;

    for(i = 0; i < jogador.num_posicoes; i++)
    {
        if(posicao == jogador.posicoes[i])
        {
            return 1;
            //posição existe dentro do jogador
        }
    }

    return 0;   //posição não existe dentro do jogador
}
char confirmaExclusaoPosicao()
{
    char op = ' ';

    while(1)
    {
        printf("\nDeseja excluir essa posicao ? (s/n): ");
        fflush(stdin);
        scanf("%c", &op);
        system("cls");
        op = tolower(op);
        if(op == 's' || op == 'n')
        {
            return op;
        }
        mensagensErro(20);
    }
}


void excluiUmJogador(int time)
{
    int selecao = perguntaJogador(time);

    if(confirmaExclusaoJogador(1) == 's')
    {
        alteraTurmaTime(selecao, time);
        excluiJogador(time, selecao);
        mensagensSucesso(5);
    }
    else
    {
        mensagensSucesso(6);
    }
}
int alteraTurmaTime(int selecao, int time)
{
    int i, j;

    for(i = 0; i < _vetorTimes[time].numJogadores; i++)
    {

        if(strcmp(_vetorTimes[time].jogadores[selecao].nome, _vetorTimes[time].jogadores[i].nome) != 0)
        {
           if(strcmp(_vetorTimes[time].jogadores[selecao].turma, _vetorTimes[time].jogadores[i].turma) == 0)
            {
                return 0;
            }
        }
    }

    for(i = 0; i < _vetorTimes[time].numTurmas; i++)
    {
        if(strcmp(_vetorTimes[time].jogadores[selecao].turma, _vetorTimes[time].turma[i]) == 0)
        {
            excluiTurmaTime(time, i);
            return 1;
        }
    }
}
void excluiTurmaTime(int time, int selecao)
{
    for(selecao; selecao < _vetorTimes[time].numTurmas - 1; selecao++)
    {
        _vetorTimes[time].turma[selecao] = _vetorTimes[time].turma[selecao + 1];
    }
    free(_vetorTimes[time].turma[selecao]);
    _vetorTimes[time].numTurmas--;
}
void excluiJogador(int time, int selecao)
{
    for(selecao; selecao < _vetorTimes[time].numJogadores - 1; selecao++)
    {
       _vetorTimes[time].jogadores[selecao] = _vetorTimes[time].jogadores[selecao + 1];
    }
    liberaJogador(time, selecao);
    _vetorTimes[time].numJogadores--;
}
char confirmaExclusaoJogador()
{
    char op = ' ';

    while(1)
    {
        printf("\nDeseja excluir esse jogador? (s/n): ");
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);
        if(op == 's' || op == 'n')
        {
            return op;
        }
        mensagensErro(20);
    }
}
int perguntaJogador(int time)
{
    char selecao[TAM_STR];
    int i;

    while(1)
    {
        exibeJogadores(time);
        printf("\nSelecione o jogador: ");
        fflush(stdin);
        gets(selecao);
        system("cls");
        for(i = 0; i < _vetorTimes[time].numJogadores; i++)
        {
            if(strcmp(selecao, _vetorTimes[time].jogadores[i].nome) == 0)
            {
                return i;
            }
        }
        mensagensErro(34);
    }
}


// funções gerais

int verificaCaracteres(char *str)
{
    int i, erro = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ';')
        {
            printf("\nO CONTEÚDO NÃO PODE CONTER (;)\n");
            system("PAUSE");
            system("cls");
            erro = 1;
        }
        else if(str[i] == '#')
        {
            printf("\nO CONTEÚDO NÃO PODE CONTER (#)\n");
            system("PAUSE");
            system("cls");
            erro = 1;
        }
        else if(str[i] == '$')
        {
            printf("\nO CONTEÚDO NÃO PODE CONTER ($)\n");
            system("PAUSE");
            system("cls");
            erro = 1;
        }
        else if(str[i] == '@')
        {
            printf("\nO CONTEÚDO NÃO PODE CONTER (@)\n");
            system("PAUSE");
            system("cls");
            erro = 1;
        }
    }

    return erro;
}
void exibeTimes()
{
    int i;

    printf("\nTimes existentes: ");
    for(i = 0; i < numTimes; i++)
    {
        printf("%s %c ", _vetorTimes[i].nome, i != (numTimes - 1) ? '-' : ' ');
    }   
}
void exibeTurmas()
{
    int i;

    printf("\nTurmas existentes: ");
    for(i = 0; i < numTurmas; i++)
    {
        printf("%s %c ", _vetorTurmas[i].nome, i != (numTurmas - 1) ? '-' : ' ');
    }
}
void exibeJogadores(int time)
{
    int i;

    printf("\nJogadores do time %s: ", _vetorTimes[time].nome);
    for(i = 0; i < _vetorTimes[time].numJogadores; i++)
    {
        printf("%s %c ", _vetorTimes[time].jogadores[i].nome, i != (_vetorTimes[time].numJogadores - 1) ? '-' : ' ');
    }
}
int validaData(int dia, int mes, int ano)
{
    if(dia < 1 || dia > 31)
    {
        return 0;
    }
    else if(mes < 1 || mes > 12)
    {
        mensagensErro(-4);
        return 0;
    }
    else if(ano < 0)
    {
        return 0;
    }
    else if(mes == 2)
    {
        if(dia > 29)
        {
            return 0;
        }
        else if( ( (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) && dia > 28)
        {
            return 0;
        }
    }
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30))
    {
        return 0;
    }

    return 1;
}
int validaAno(int ano)
{
    if(ano < 2008)
    {
        mensagensErro(4);
        return 0;
    }
    else if(ano > 2023)
    {
        mensagensErro(5);
        return 0;
    }

    return 1;
}
int converteEnum(char *str)
{
    int e;

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    if (strcmp(str, "info") == 0)
    {
        e = 0;
    }
    else if (strcmp(str, "mamb") == 0)
    {
        e = 1;
    }
    else if (strcmp(str, "mec") == 0)
    {
        e = 2;
    }
    else if (strcmp(str, "tads") == 0)
    {
        e = 3;
    }
    else if (strcmp(str, "tga") == 0)
    {
        e = 4;
    }
    else if (strcmp(str, "csoc") == 0)
    {
        e = 5;
    }
    else
    {
        e = -1;
        mensagensErro(6);
    }

    return e;
}
void mensagensErro(int erro)
{
    switch (erro)
    {
        case 0:
        printf("\n***ERRO 00: VETOR DE TURMAS NAO PODE SER CRIADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 1:
        printf("\n***ERRO 01: VETOR DE TIMES NAO PODE SER CRIADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 2:
        printf("\n***ERRO 02: ARQUIVO NAO PODE SER ABERTO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 3:
        printf("\n***ERRO 03: OPCAO DE MENU INVALIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 4:
        printf("\n***ERRO 04: ANO INVALIDO (menor que 2008)***\n");
        system("PAUSE");
        system("cls");
        break;

        case 5:
        printf("\n***ERRO 05: ANO INVALIDO (maior que 2023)***\n");
        system("PAUSE");
        system("cls");
        break;

        case 6:
        printf("\n***ERRO 06: CURSO INVALIDO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 7:
        printf("\n***ERRO 07: ERRO AO REALOCAR VETOR DE TURMAS***\n");
        system("PAUSE");
        system("cls");
        break;

        case 8:
        printf("\n***ERRO 08: TURMA SELECIONADA INEXISTENTE***\n");
        system("PAUSE");
        system("cls");
        break;

        case 9:
        printf("\n***ERRO 09: NAO EXISTEM TURMAS***\n");
        system("PAUSE");
        system("cls");
        break;

        case 10:
        printf("\n***ERRO 10: DATA INVALIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 11:
        printf("\n***ERRO 11: TURMA INVALIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 12:
        printf("\n***ERRO 12: NAO PODEM HAVER JOGADORES DE MAIS DE 2 TURMAS DIFERENTES POR TIME***\n");
        system("PAUSE");
        system("cls");
        break;

        case 13:
        printf("\n***ERRO 13: NUMERO DE CAMISA INVALIDO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 14:
        printf("\n***ERRO 14: ESSE NOME JA PERTENCE A OUTRA TURMA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 15:
        printf("\n***ERRO 15: ERRO AO CRIAR VETOR DE JOGADORES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 16:
        printf("\n***ERRO 16: NAO EXISTEM TIMES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 17:
        printf("\n***ERRO 17: TIME SELECIONADO INEXISTENTE***\n");
        system("PAUSE");
        system("cls");
        break;

        case 18:
        printf("\n***ERRO 18: NOME JA PERTENCENTE A OUTRO TIME***\n");
        system("PAUSE");
        system("cls");
        break;

        case 19:
        printf("\n***ERRO 19: TURMA A SER EXCLUÍDA PERTENCENTE A UM TIME***\n");
        system("PAUSE");
        system("cls");
        break;

        case 20:
        printf("\n***ERRO 20: OPCAO INVALIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 21:
        printf("\n***ERRO 21: ERRO AO REALOCAR VETOR DE TIMES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 22:
        printf("\n***ERRO 22: ERRO AO REALOCAR VETOR DE JOGADORES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 23:
        printf("\n***ERRO 23: DEVE HAVER APENAS UM JOGADOR***\n");
        system("PAUSE");
        system("cls");
        break;

        case 24:
        printf("\n***ERRO 19: UMA DAS TURMAS A SER EXCLUÍDA PERTENCENTE A UM TIME***\n");
        system("PAUSE");
        system("cls");
        break;

        case 25:
        printf("\n***ERRO 25: POSICAO INVALIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 26:
        printf("\n***ERRO 26: ERRO AO CRIAR VETOR DE POSICOES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 27:
        printf("\n***ERRO 27: ERRO AO REALOCAR VETOR DE POSICOES***\n");
        system("PAUSE");
        system("cls");
        break;

        case 28:
        printf("\n***ERRO 28: DEVE HAVER PELO MENOS UM JOGADOR***\n");
        system("PAUSE");
        system("cls");
        break;

        case 29:
        printf("\n***ERRO 29: JOGADOR INEXISTENTE***\n");
        system("PAUSE");
        system("cls");
        break;

        case 30:
        printf("\n***ERRO 30: DEVE HAVER AO MENOS UMA POSIÇÃO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 31:
        printf("\n***ERRO 31: POSICAO INEXISTENTE***\n");
        system("PAUSE");
        system("cls");
        break;

        case 32:
        printf("\n***ERRO 32: POSICAO INEXISTENTE NO JOGADOR***\n");
        system("PAUSE");
        system("cls");
        break;

        case 33:
        printf("\n***ERRO 33: NUMER MAX DE POSICOES ATINGIDO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 34:
        printf("\n***ERRO 34: NOME DO JOGADOR JA EXISTE NESTE TIME***\n");
        system("PAUSE");
        system("cls");
        break;

        case 35:
        printf("\n***ERRO 35: POSICAO JA EXISTE NO JOGADOR***\n");
        system("PAUSE");
        system("cls");
        break;

        case 36:
        printf("\n***ERRO 36: NUMERO DA CAMISA JA PERTENCE A OUTRO JOGADOR***\n");
        system("PAUSE");
        system("cls");
        break;

        default:
        printf("\n***ERRO -1: NÃO FOI POSSÍVEL ENCONTRAR O ERRO***\n");
        system("PAUSE");
        system("cls");
        break;
    }
}
void mensagensSucesso(int sucesso)
{
    switch (sucesso)
    {
        case 0:
        printf("\n***SUCESSO 00: ARQUIVO RECUPERADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 1:
        printf("\n***SUCESSO 01: ARQUIVOS RECUPERADOS***\n");
        system("PAUSE");
        system("cls");
        break;

        case 2:
        printf("\n***SUCESSO 02: PROGRAMA INICIALIZADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 3:
        printf("\n***SUCESSO 03: TURMA ADICIONADA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 4:
        printf("\n***SUCESSO 04: TIME ADICIONADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 5:
        printf("\n***SUCESSO 05: TURMA EXCLUIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 6:
        printf("\n***SUCESSO 06: OPERACAO ABORTADA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 7:
        printf("\n***SUCESSO 07: ATRIBUTO ALTERADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 8:
        printf("\n***SUCESSO 08: TURMAS LIBERADAS***\n");
        system("PAUSE");
        system("cls");
        break;

        case 9:
        printf("\n***SUCESSO 09: TIMES LIBERADOS***\n");
        system("PAUSE");
        system("cls");
        break;

        case 10:
        printf("\n***SUCESSO 10: TIME EXCLUIDO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 11:
        printf("\n***SUCESSO 11: JOGADOR EXCLUIDO***\n");
        system("PAUSE");
        system("cls");
        break;

        case 12:
        printf("\n***SUCESSO 12: POSICAO EXCLUIDA***\n");
        system("PAUSE");
        system("cls");
        break;

        case 13:
        printf("\n***SUCESSO 13: ARQUIVO ATUALIZADO***\n");
        system("PAUSE");
        system("cls");
        break;

        case -1:
        printf("\n***SUCESSO -1: PROGRAMA FINALIZADO***\n");
        system("PAUSE");
        system("cls");
        break;
    }
}

// funções de liberacao de memoria

void liberaTurmas()
{
    int i;
    for(i = 0; i < numTurmas; i++)
    {
        liberaTurma(i);
    }
    free(_vetorTurmas);
    mensagensSucesso(8);
}
void liberaTurma(int turma)
{
    free(_vetorTurmas[turma].nome);
}

void liberaTimes()
{
    int i;
    for(i = 0; i < numTimes; i++)
    {
        liberaTime(i);
    }
    free(_vetorTimes);
    mensagensSucesso(9);
}
void liberaTime(int time)
{
    free(_vetorTimes[time].nome);
    free(_vetorTimes[time].tecnico);
    liberaJogadores(time);
    liberaTurmasTime(time);
}
void liberaJogadores(int time)
{
    int i;
    for(i = 0; i < _vetorTimes[time].numJogadores; i++)
    {
        liberaJogador(time, i);
    }
    free(_vetorTimes[time].jogadores);
}
void liberaTurmasTime(int time)
{
    int i;
    for(i = 0; i < _vetorTimes[time].numTurmas; i++)
    {
        free(_vetorTimes[time].turma[i]);
    }
    free(_vetorTimes[time].turma);
}
void liberaJogador(int time, int jogador)
{
    free(_vetorTimes[time].jogadores[jogador].nome);
    free(_vetorTimes[time].jogadores[jogador].posicoes);
    free(_vetorTimes[time].jogadores[jogador].turma);
    free(_vetorTimes[time].jogadores[jogador].matricula);
}

void finalizaPrograma()
{

    salvaTurmas();
    salvaTimes();
    mensagensSucesso(13);

    if(numTurmas > 0)
    {
        liberaTurmas();
    }
    if(numTimes > 0)
    {
        liberaTimes();
    }

    mensagensSucesso(-1);
}

// funções de arquivo

void salvaTurmas()
{
    FILE *pArq;
    int i;

    pArq = fopen("turmas.txt", "w+");

    for(i = 0; i < numTurmas; i++)
    {
        fprintf(pArq, "%s;", _vetorTurmas[i].nome);
        fprintf(pArq, "%i;", _vetorTurmas[i].curso);
        fprintf(pArq, "%i;\n", _vetorTurmas[i].ano); 
    }

    fclose(pArq);
}
void salvaTimes()
{
    FILE *pArq;
    int i, j, k;

    pArq = fopen("times.txt", "w+");
    for(i = 0; i < numTimes; i++)
    {

        fprintf(pArq, "%s;", _vetorTimes[i].nome);
        fprintf(pArq, "%s;", _vetorTimes[i].tecnico);
        for(j = 0; j < _vetorTimes[i].numJogadores; j++)
        {
            fprintf(pArq, "#%s;", _vetorTimes[i].jogadores[j].nome);
            fprintf(pArq, "%i;%i;%i;", _vetorTimes[i].jogadores[j].data_nascimento.dia, _vetorTimes[i].jogadores[j].data_nascimento.mes, _vetorTimes[i].jogadores[j].data_nascimento.ano);
            fprintf(pArq, "%s;", _vetorTimes[i].jogadores[j].matricula);
            fprintf(pArq, "%s;", _vetorTimes[i].jogadores[j].turma);
            fprintf(pArq, "%i;", _vetorTimes[i].jogadores[j].num_camisa);
            for(k = 0; k < _vetorTimes[i].jogadores[j].num_posicoes; k++)
            {
                fprintf(pArq, "$%i;", _vetorTimes[i].jogadores[j].posicoes[k]);
            }
        }
        for(j = 0; j < _vetorTimes[i].numTurmas; j++)
        {
            fprintf(pArq, "@%s;", _vetorTimes[i].turma[j]);
        }
        fprintf(pArq, "\n");
    }

    fclose(pArq);
}
void recuperaTurmas()
{
    FILE *pArq;
    int i = 0, countPV= 0;
    char c, strAux[TAM_STR];

    pArq = fopen("turmas.txt", "r");

    if(pArq != NULL)
    {
        while( (c = getc(pArq) ) != EOF)
        {
            if(c != '\n')
            {
                if(c != ';')
                {
                    strAux[i] = c;
                    i++;
                }
                else
                {
                    countPV++;
                    strAux[i] = '\0';

                    switch (countPV)
                    {
                        case 1:
                        _vetorTurmas[numTurmas].nome = (char *) malloc(strlen(strAux + 1) * sizeof(char));
                        strcpy(_vetorTurmas[numTurmas].nome, strAux);
                        break;

                        case 2:
                        _vetorTurmas[numTurmas].curso = atoi(strAux);
                        break;

                        case 3:
                        _vetorTurmas[numTurmas].ano = atoi(strAux);
                        break;
                    }

                    i = 0;
                }
            }
            else
            {
                countPV = 0;
                i = 0;

                numTurmas++;
                _vetorTurmas = (TTurma *) realloc(_vetorTurmas, (numTurmas + 1) * sizeof(TTurma)); 
                if(!_vetorTurmas)
                {
                    mensagensErro(7);
                    exit(1);
                }
            }
        }
    }

    fclose(pArq);
    mensagensSucesso(0);
}
void recuperaTimes()
{
    FILE *pArq;
    int i = 0, countPV = 0, countArr = 0, countHash = 0, countS = 0;
    char c, strAux[TAM_STR];

    pArq = fopen("times.txt", "r");

    if(pArq != NULL)
    {
        while( (c = getc(pArq) ) != EOF)
        {
            if(c != '\n')
            {
                if(c != ';')
                {
                    if(c != '#')
                    {
                        if(c != '$')
                        {
                            if(c != '@')
                            {
                                strAux[i] = c;
                                i++;
                            }
                            else
                            {
                                if(countArr == 0)
                                {
                                    _vetorTimes[numTimes].numTurmas = 0;
                                    _vetorTimes[numTimes].turma = (char **) malloc(1 * sizeof(char *));
                                }

                                _vetorTimes[numTimes].numTurmas++;
                                _vetorTimes[numTimes].turma = (char **) realloc(_vetorTimes[numTimes].turma, (_vetorTimes[numTimes].numTurmas + 1) * sizeof(char *));
                                countPV = 0;
                                countArr++;
                            }
                        }
                        else
                        {
                            countPV = 0;

                            if(countS == 0)
                            {
                                _vetorTimes[numTimes].jogadores[ _vetorTimes[numTimes].numJogadores - 1].num_posicoes = 0;
                                _vetorTimes[numTimes].jogadores[ _vetorTimes[numTimes].numJogadores - 1].posicoes = (enum_posicoes *) malloc(1 * sizeof(enum_posicoes));
                            }

                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].num_posicoes++;
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].posicoes = (enum_posicoes *) realloc(_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].posicoes, (_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].num_posicoes + 1) * sizeof(enum_posicoes));

                            countS++;
                        }
                    }
                    else
                    {
                        countPV = 0;
                        countS = 0;

                        if(countHash == 0)
                        {
                            _vetorTimes[numTimes].numJogadores = 0;
                            _vetorTimes[numTimes].jogadores = (TJogador *) malloc(1 * sizeof(TJogador));
                        }

                        _vetorTimes[numTimes].numJogadores++;
                        _vetorTimes[numTimes].jogadores = (TJogador *) realloc(_vetorTimes[numTimes].jogadores, (_vetorTimes[numTimes].numJogadores + 1) * sizeof(TJogador));  
                        countHash++;
                    }
                }
                else
                {
                    countPV++;
                    strAux[i] = '\0';


                    if(countArr > 0) // entrou em turmas
                    {
                        _vetorTimes[numTimes].turma[_vetorTimes[numTimes].numTurmas - 1] = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
                        strcpy(_vetorTimes[numTimes].turma[_vetorTimes[numTimes].numTurmas - 1], strAux);
                    }
                    else if(countS > 0) // entrou em posições
                    {
                        _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].posicoes[_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].num_posicoes - 1] = atoi(strAux);
                    }
                    else if(countHash > 0) // entrou em jogadores
                    {
                        switch (countPV)
                        {
                            case 1:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].nome = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
                            strcpy(_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].nome, strAux);
                            break;

                            case 2:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].data_nascimento.dia = atoi(strAux);
                            break;

                            case 3:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].data_nascimento.mes = atoi(strAux);
                            break;

                            case 4:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].data_nascimento.ano = atoi(strAux);
                            break;

                            case 5:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].matricula = (char *) malloc((strlen(strAux) + 1)* sizeof(char));
                            strcpy(_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].matricula, strAux);
                            break;

                            case 6:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].turma = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
                            strcpy(_vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].turma, strAux);
                            break;

                            case 7:
                            _vetorTimes[numTimes].jogadores[_vetorTimes[numTimes].numJogadores - 1].num_camisa = atoi(strAux);
                            break;
                        }
                    }
                    else 
                    {
                        switch (countPV)
                        {
                            case 1:
                            _vetorTimes[numTimes].nome = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
                            strcpy(_vetorTimes[numTimes].nome, strAux);
                            break;

                            case 2:
                            _vetorTimes[numTimes].tecnico = (char *) malloc((strlen(strAux) + 1) * sizeof(char));
                            strcpy(_vetorTimes[numTimes].tecnico, strAux);
                            break;
                        }
                    }

                    i = 0;
                }
            }
            else
            {
                countPV = 0;
                countArr = 0;
                countS = 0;
                countHash = 0;
                i = 0;

                numTimes++;
                _vetorTimes = (TTime *) realloc(_vetorTimes, (numTimes + 1) * sizeof(TTime)); 
            }
        }
    }

    fclose(pArq);
    mensagensSucesso(0);
}

