#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _end
{
    char rua[50];
    char bairro[50];
    int numero;
    int cep;
} Endereco;

typedef struct _cad
{
    int id;
    char nome[100];
    Endereco endereco;
    char usuario[50];
    char senha[50];
    char tipo;
} Cadastro;

typedef struct _node
{
    Cadastro cadastro;
    struct _node *next;
} Node;

typedef struct _linked_list
{
    Node *begin;
    Node *end;
} Lista;


int ID = 0;
void AdicionarUsuario(Lista *lista, char nome[], char rua[], char bairro[], int *numero, int *cep, char *tipo, char usuario_de_fora[], char senha[])
{
    int ID_ATUAL = 0;
    Node *node = (Node*) malloc(sizeof(Node));
    Cadastro usuario;
    if (node == NULL)
    {
        printf("\nErro");
        exit(1);
    }
    if (lista->begin == NULL)
    {
        printf("\n------------------------------------");
        printf("\nCADASTRO DE SUPERUSUARIO");
        printf("\n------------------------------------");

        printf("\nNome: ");
        setbuf(stdin, NULL);
        gets(usuario.nome);

        printf("\n-= Endereco =-");
        printf("\nRua: ");
        setbuf(stdin, NULL);
        gets(usuario.endereco.rua);

        printf("\nBairro: ");
        setbuf(stdin, NULL);
        gets(usuario.endereco.bairro);

        printf("\nNumero: ");
        scanf("%i", &usuario.endereco.numero);

        printf("\nCEP: ");
        scanf("%i", &usuario.endereco.cep);

        printf("\n-= Conta =-");

        printf("\nTipo: SUPERUSUARIO");

        printf("\nUsuario: ");
        setbuf(stdin, NULL);
        gets(usuario.usuario);

        printf("\nSenha: ");
        setbuf(stdin, NULL);
        gets(usuario.senha);

        ID_ATUAL++;
        ID = ID_ATUAL;
        node->cadastro.id = ID;
        strcpy(node->cadastro.nome, usuario.nome);
        strcpy(node->cadastro.endereco.rua, usuario.endereco.rua);
        strcpy(node->cadastro.endereco.bairro, usuario.endereco.bairro);
        node->cadastro.endereco.numero = usuario.endereco.numero;
        node->cadastro.endereco.cep = usuario.endereco.cep;
        node->cadastro.tipo = 'S';
        strcpy(node->cadastro.usuario, usuario.usuario);
        strcpy(node->cadastro.senha, usuario.senha);
    }
    else
    {
        printf("\nENTROU NO CADASTRO");

        ID_ATUAL++;
        ID += ID_ATUAL;
        node->cadastro.id = ID;
        printf("\nDEBUG - node->cadastro.id: %i", node->cadastro.id);
        printf("\nDEBUG - ID: %i", ID);

        strcpy(node->cadastro.nome, nome);
        printf("\nDEBUG - node->cadastro.nome: %s", node->cadastro.nome);
        printf("\nDEBUG - nome: %s", nome);

        strcpy(node->cadastro.endereco.rua, rua);
        printf("\nDEBUG - node->cadastro.endereco.rua: %s", node->cadastro.endereco.rua);
        printf("\nDEBUG - rua: %s", rua);

        strcpy(node->cadastro.endereco.bairro, bairro);
        printf("\nDEBUG - node->cadastro.endereco.bairro: %s", node->cadastro.endereco.bairro);
        printf("\nDEBUG - bairro: %s", bairro);

        node->cadastro.endereco.numero = *numero;
        printf("\nDEBUG - node->cadastro.endereco.numero: %i", node->cadastro.endereco.numero);
        printf("\nDEBUG - numero: %i", *numero);

        node->cadastro.endereco.cep = *cep;
        printf("\nDEBUG - node->cadastro.endereco.cep: %i", node->cadastro.endereco.cep);
        printf("\nDEBUG - cep:: %i", *cep);

        node->cadastro.tipo = *tipo;
        printf("\nDEBUG - node->cadastro.tipo: %c", node->cadastro.tipo);
        printf("\nDEBUG - tipo: %c", *tipo);

        strcpy(node->cadastro.usuario, usuario_de_fora);
        printf("\nDEBUG - node->cadastro.usuario: %s", node->cadastro.usuario);
        printf("\nDEBUG - usuario: %s", usuario_de_fora);

        strcpy(node->cadastro.senha, senha);
        printf("\nDEBUG - node->cadastro.senha: %s", node->cadastro.senha);
        printf("\nDEBUG - senha: %s", senha);
    }

    node->next = lista->begin;
    if (lista->begin == NULL)
    {
        lista->end = node;
    }
    lista->begin = node;

}

Lista *CriarLista()
{
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("\nErro");
        exit(1);
    }
    lista->begin = NULL;
    lista->end = NULL;

    if (lista->begin == NULL)
    {
        AdicionarUsuario(lista, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return lista;
}

int Login(Lista *lista, char usuario[], char senha[])
{
    Node *PONTEIRO_DE_NODE = (Node*) malloc(sizeof(Node));
    for (PONTEIRO_DE_NODE = lista->begin; PONTEIRO_DE_NODE != NULL; PONTEIRO_DE_NODE = PONTEIRO_DE_NODE->next)
    {
        printf("\nDEBUG - ENTROU NO FOR");
        if (strcmp(PONTEIRO_DE_NODE->cadastro.usuario, usuario) == 0)
        {
           if(strcmp(PONTEIRO_DE_NODE->cadastro.senha, senha) == 0)
           {
                printf("\nDEBUG - ACHOU O USUARIO");
                if (PONTEIRO_DE_NODE->cadastro.tipo == 'S' || PONTEIRO_DE_NODE->cadastro.tipo == 'A')
                    return 1;
                if (PONTEIRO_DE_NODE->cadastro.tipo == 'C')
                    return 2;
           }
        }
    }
    free(PONTEIRO_DE_NODE);
    return 0;

}

Node *PesquisarNome (Lista *lista, char pesqNome[]) {

    Node *PONTEIRO_DE_NODE = (Node*) malloc(sizeof(Node));
    for (PONTEIRO_DE_NODE = lista->begin; PONTEIRO_DE_NODE != NULL; PONTEIRO_DE_NODE = PONTEIRO_DE_NODE->next)
    {
        if (strcmp(PONTEIRO_DE_NODE->cadastro.nome, pesqNome) == 0) {
            return PONTEIRO_DE_NODE;
        }
    }
    free(PONTEIRO_DE_NODE);
    return NULL;
}

Node *AlterarSenha(Lista *lista, char usuario[], char senha[])
{
    Node *PONTEIRO_DE_NODE = (Node*) malloc(sizeof(Node));
    for (PONTEIRO_DE_NODE = lista->begin; PONTEIRO_DE_NODE != NULL; PONTEIRO_DE_NODE = PONTEIRO_DE_NODE->next)
    {
        if (strcmp(PONTEIRO_DE_NODE->cadastro.usuario, usuario) == 0)
        {
            if(strcmp(PONTEIRO_DE_NODE->cadastro.senha, senha) == 0)
                return PONTEIRO_DE_NODE;
        }
    }
    free(PONTEIRO_DE_NODE);
    return NULL;
}
void menu()
{
        printf("\n------------------------------------\n");;
        printf("SISTEMA DE ADMINISTRACAO\n");
        printf("\n------------------------------------\n");
        printf("\n\t1. LOGIN");
        printf("\n\t2. SAIR");
        printf("\n------------------------------------\n");
        printf("Escolha: ");
}

void menu_adm()
{
        printf("\n------------------------------------\n");;
        printf("SISTEMA DE ADMINISTRACAO\n");
        printf("\n------------------------------------\n");
        printf("\n\t1. CADASTRAR NOVO USUARIO");
        printf("\n\t2. REMOVER USUARIO");
        printf("\n\t3. PESQUISAR POR NOME");
        printf("\n\t4. ALTERAR SENHA");
        printf("\n\t5. SAIR");
        printf("\n------------------------------------\n");
        printf("Escolha: ");
}

void menu_cliente()
{
        printf("\n------------------------------------\n");;
        printf("SISTEMA DE ADMINISTRACAO\n");
        printf("\n------------------------------------\n");
        printf("\n\t1. ALTERAR SENHA");
        printf("\n\t2. SAIR");
        printf("\n------------------------------------\n");
        printf("Escolha: ");
}

int VerificarTipoDoUsuario(char tipo)
{
    if(tipo == 'A' || tipo == 'C' )
        return 1;
    if (tipo == 'S')
        return 0;

}

int main()
{
    Lista *lista = CriarLista();
    Cadastro usuario_auxiliar;
    char pesqNome[50];
    int OPCAO_PRINCIPAL;
    int OPCAO_SECUNDARIA;
    int erro;


    do
    {
        menu();
        scanf("%i", &OPCAO_PRINCIPAL);
        if (OPCAO_PRINCIPAL == 1)
        {
            Cadastro USUARIO_ATUAL;
            printf("\nUSUARIO: ");
            setbuf(stdin, NULL);
            gets(usuario_auxiliar.usuario);
            strcpy(USUARIO_ATUAL.usuario, usuario_auxiliar.usuario);

            printf("\nSENHA: ");
            setbuf(stdin, NULL);
            gets(usuario_auxiliar.senha);
            strcpy(USUARIO_ATUAL.senha, usuario_auxiliar.senha);

            int verificacao = Login(lista, usuario_auxiliar.usuario, usuario_auxiliar.senha);
            if (verificacao == 1)
            {
                menu_adm();
                scanf("%i", &OPCAO_SECUNDARIA);
                if (OPCAO_SECUNDARIA == 1)
                {
                    int erro = 0;
                    printf("\nNOME: ");
                    setbuf(stdin, NULL);
                    gets(usuario_auxiliar.nome);

                    printf("\n ---= Endereco =---");
                    printf("\nRua: ");
                    setbuf(stdin, NULL);
                    gets(usuario_auxiliar.endereco.rua);

                    printf("\nBAIRRO: ");
                    setbuf(stdin, NULL);
                    gets(usuario_auxiliar.endereco.bairro);

                    printf("\nNUMERO: ");
                    scanf("%i", &usuario_auxiliar.endereco.numero);

                    printf("\nCEP: ");
                    scanf("%i", &usuario_auxiliar.endereco.cep);

                    printf("\n ---= Conta =---");

                    do
                    {
                        erro = 0;
                        printf("\nTipo: ");
                        setbuf(stdin, NULL);
                        scanf("%c", &usuario_auxiliar.tipo);
                        if (VerificarTipoDoUsuario(usuario_auxiliar.tipo) != 1)
                        {
                            printf("\nTipo invalido.");
                            erro = -1;
                            system("pause");
                        }
                    }while(erro == -1);


                    printf("\nUSUARIO: ");
                    setbuf(stdin, NULL);
                    gets(usuario_auxiliar.usuario);

                    printf("\nSENHA: ");
                    setbuf(stdin, NULL);
                    gets(usuario_auxiliar.senha);

                    AdicionarUsuario(lista, usuario_auxiliar.nome, usuario_auxiliar.endereco.rua, usuario_auxiliar.endereco.bairro, &usuario_auxiliar.endereco.numero, &usuario_auxiliar.endereco.cep, &usuario_auxiliar.tipo, usuario_auxiliar.usuario, usuario_auxiliar.senha);

                }
                if(OPCAO_SECUNDARIA == 2)
                {
                    printf("\n--- A FAZER AINDA ----");
                }
                if(OPCAO_SECUNDARIA == 3)
                {
                    printf("\nPESQUISAR USUARIO PELO NOME: ");
                    setbuf(stdin, NULL);
                    gets(pesqNome);

                    if(PesquisarNome(lista, &pesqNome) != NULL)
                    {
                        Node *ponteiro = PesquisarNome(lista, &pesqNome);

                        printf("\nID: %i", ponteiro->cadastro.id);
                        printf("\nNOME: %s", ponteiro->cadastro.nome);
                        printf("\n ---= Endereco =--- ");
                        printf("\nRUA: %s", ponteiro->cadastro.endereco.rua);
                        printf("\nBAIRRO: %s", ponteiro->cadastro.endereco.bairro);
                        printf("\nNUMERO: %%i", ponteiro->cadastro.endereco.numero);
                        printf("\nCEP: %i", ponteiro->cadastro.endereco.cep);
                        printf("\n ---= Conta =---");
                        printf("\nTIPO: %c\n", ponteiro->cadastro.tipo);
                        printf("\nUSUARIO: **********");
                        printf("\nSENHA: **********\n");
                        system("pause");
                    }
                }
                if (OPCAO_SECUNDARIA == 4)
                {
                    Node *ponteiro = AlterarSenha(lista, USUARIO_ATUAL.usuario, USUARIO_ATUAL.senha);
                    printf("\nAlteracao de senha do %s", ponteiro->cadastro.usuario);
                    printf("\nNova senha: ");
                    setbuf(stdin, NULL);
                    gets(ponteiro->cadastro.senha);
                    printf("DEBUG - NOVA SENHA: %s", ponteiro->cadastro.senha);
                }
            }
            if(verificacao == 2)
            {
                menu_cliente();
                scanf("%i", &OPCAO_SECUNDARIA);
            }
            if(verificacao == 0)
            {
                printf("\nUsuario e/ou senha incorretos.");
            }
        }

        if (OPCAO_PRINCIPAL == 3)
        {

        }
    }while(OPCAO_PRINCIPAL != 2);


    return 0;
}
