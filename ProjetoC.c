


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//variáveis globais
int loguei = 0;
int trans = 0;

typedef struct cadastro_cliente
{
    int idade;
    char nome [25];
    char tel [15];
    char end [50];
    char numCad[15];
}cadastro_cliente;//definição struct
//função struct global
cadastro_cliente cliente;

typedef struct gerenciamento_cliente
{
    char reclamacao [100];
    char contato [100];
    char dicas [50];

}gerenciamento_cliente;//struct para gerenciamento
//função gerenciamento struct global
gerenciamento_cliente p;

struct Produtos{
char nome[30], categoria[20], descricao[70];
int codigo, qtdEst, qtdMinEst;
float valor;
};

struct Carrinho{

char nome[50];
int codProduto, qtdDesejada;
float valTotal;
};


//funções
void cadastro();//função para cadastro;
void limpatela();//função para limpar a tela;
void doacoes ();//função para doações;
void gerenciamento ();//função para gerenciamento;
void sugestao();//função para sugestão;
void reclamacao ();//função reclamação;
void permutasCad ();//função permutas;
void imprimirsugestao ();//imprimir a sugestão;
void imprimereclamacao ();//imprimir a reclamação;
void carrinhodoodio();//função carrinho;
void solicitacoes ();//função gerenciamento;

//programa principal
int main (void)

{
    setlocale (LC_ALL, "Portuguese-Brazilian");
    int cont = 0;
    struct Produtos cadProduto;
    struct Carrinho pedidoSolicitado;

    do
    {
       printf("WeDoCare. Agradeçemos a preferência.");
       printf ("\nInforme uma das opções abaixo: ");
       printf ("\t\n->'0' Para sair.");//ok
       printf ("\t\n->'1' Para cadastro. ");//ok
       printf ("\t\n->'2' Para doações. ");//falta -> criar algo simples de receber dinheiro e dar uma nota fiscal.
       printf ("\t\n->'3' Para solicitações & transações.");//carrinho estará incluso aqui
       printf ("\t\n->'4' Para gerenciamento. ");//ok
       printf ("\t\n->'5' Para limpar o carrinho. ");
       printf ("\n-------------------------------\n");
       printf ("Digite aqui uma das opções: ");
       scanf ("%d", &cont);
       getchar ();
       limpatela();

       switch (cont)
       {
        case 0:
          printf ("\nVocê optou por sair.");
          return 0;
          break;

        case 1: cadastro ();
           break;

        case 2: doacoes();
         break;

         case 3: solicitacoes ();
          break;

        case 4: gerenciamento ();
         break;

        case 5:
        printf ("\nSeu carrinho será zerado! Faça a transição novamente.");
        getch();
        limpatela();
        pedidoSolicitado.codProduto = 0;
        pedidoSolicitado.qtdDesejada = 0;
        strcpy (cadProduto.nome, "NULL");
        pedidoSolicitado.valTotal = 0;
        trans = 0;
        return main();
        getch();
        return 0;
        break;



        default:
        limpatela();
        printf ("\n\tAção não pode ser registrada.");
        getch();
        return main();
         break;
       }
    } while (cont != 0);




}//fim int


//inicio das funções - "limpatela" , para obviamente, limpar a tela kk
void limpatela()
{
    system ("CLS");
}

//cadastro do cliente
void cadastro()
{

    printf ("\n\t------Cadastro------\n");
    fflush(stdin);
    printf ("\nInforme-nos seu nome: ");
    gets (cliente.nome);
    fflush(stdin);
    printf ("\nInfome-nos sua idade: ");
    scanf ("%d", &cliente.idade);
    fflush(stdin);
    printf ("\nInforme-nos seu número de telefone. Ex: (xx)xxxxxxxxx: ");
    gets (cliente.tel);
    fflush (stdin);
    printf ("\nInforme-nos agora seu endereço(max 49 carac.): ");
    fflush (stdin);
    gets (cliente.end);
    fflush (stdin);
    printf ("\nInforme seu cpf. Ex (xxx.xxx.xxx.xx): ");
    gets (cliente.numCad);
    fflush(stdin);
    limpatela();
    printf ("Cadastro efetuado com sucesso!");
    loguei = 1;
    getch();
    limpatela();

    printf ("\n\t-----Dados Cadastrais------");
    printf ("\nSeu nome é: %s", cliente.nome);
    printf ("\nSua idade é: %d", cliente.idade);
    printf ("\nSeu número de telefone é: %s", cliente.tel);
    printf ("\nSeu CPF é: %s", cliente.numCad);
    printf ("\nSeu endereço é: %s", cliente.end);
    printf ("\n\t----------------------------");
    getch ();
    limpatela();


}

//doações
void doacoes()

{
    float resp = 0, novoresp;
    int op, op2;

    if (loguei == 0)
    {
        printf ("\n\n\t->Para acessar esta área é necessário um cadastro. Você será redirecionado para a página de cadastro.<-");
        getch();
        limpatela();
        return cadastro ();
    }
    else if (loguei == 1)
    {

    printf ("\n\t\t-----Doações-----\n");
    printf ("\nDoando para nossa empresa, você ajuda na nossa grande missão que é a inclusão de todos.");
    printf ("\nO valor máximo diário de doações é de 100 reais. ");
    printf ("\nDigite aqui o valor que deseja doar: ");
    scanf ("%f", &resp);
    printf ("\nDeseja doar mais algum valor?");
    printf ("\n[1] - Sim \n[2] - Não");
    scanf ("\n%d", &op);

    if (op == 1)
    {
        while (resp <=100)
        {
        printf ("\nVocê tem armazenado: %.2f", resp);
        printf ("\nDigite aqui o valor que deseja doar['0'] para parar: ");
        scanf ("%f", &novoresp);
        resp = resp + novoresp;
        if (novoresp == 0)
        {
            limpatela();
            printf ("\nVocê tem armazenado %.2f", resp);
            printf ("\nConfirmar transação? \n[1] - Sim \n[2] - Não ");
            scanf ("%d", &op2);

             if (op2 == 1)
            {
                limpatela();
                printf ("Estamos imprimindo sua nota fiscal, %s!", cliente.nome);
                getch();
                printf ("\n\t----------Nota Fiscal----------\n");
                printf ("\n\tOrganização WeDoCare");
                printf ("\n\tNome do doador: %s", cliente.nome);
                printf ("\n\tCPF do doador: %s", cliente.numCad);
                printf ("\n\tTelefone do doador: %s", cliente.tel);
                printf ("\n\tValor doado: %.2f", resp);
                printf ("\n\t--------------------------------\n\n");
                getch();
                limpatela();
                printf("\n\tAgradecemos sua doação! Você será redirecionado ao menu principal. ");
                getch();
                limpatela();
                return 0;

            }//fim if não deseja continuar
            else if (op2 == 2)
            {
                limpatela();
                printf ("\n\tVocê decidiu não encerrar. \n\tVocê será redirecionado para o menu principal e sua doação será resetada");
                getch();
                limpatela();
                resp = 0;
                return 0;
            }//apertou '0' e decidiu não continuar.

        }//fim if encerrando transação
        }//fim while

        if (resp >100)
        {
            limpatela();
            printf ("\n\n\t->Excedeu o número de doações diárias.<-");
            printf ("\n\n\t->O valor máximo diário de doações é de 100 reais.<-");
            printf ("\n\n\t->Sua doação será resetada, faça novamente.");
            getch();
            resp = 0;
            limpatela();
            return 0;

        }
    }//fim if op
    else if (op == 2)
    {
        if (resp >100)
        {
            limpatela();
            printf ("\n\n\t->Excedeu o número de doações diárias.<-");
            printf ("\n\n\t->O valor máximo diário de doações é de 100 reais.<-");
            printf ("\n\n\t->Sua doação será resetada, faça novamente.");
            getch();
            resp = 0;
            limpatela();
            return 0;

        }

        else {
                limpatela();
                printf ("Estamos imprimindo sua nota fiscal, %s!", cliente.nome);
                getch();
                printf ("\n\t----------Nota Fiscal----------\n");
                printf ("\n\tOrganização WeDoCare");
                printf ("\n\tNome do doador: %s", cliente.nome);
                printf ("\n\tCPF do doador: %s", cliente.numCad);
                printf ("\n\tTelefone do doador: %s", cliente.tel);
                printf ("\n\tValor doado: %.2f", resp);
                printf ("\n\t--------------------------------\n\n");
                getch();
                limpatela();
                printf("\n\tAgradecemos sua doação! Você será redirecionado ao menu principal. ");
                getch();
                limpatela();
                return 0;
            }
    }//fim elseif não deseja fazer outra transação

    }//fim loguei

}//fim prog

//menu gerenciamento
void gerenciamento ()
{
    int cont, op;

    if (loguei == 0)
    {
        printf ("\n\n\t->Para acessar esta área é necessário um cadastro. Você será redirecionado para a página de cadastro.<-");
        getch();
        limpatela();
        return cadastro ();
    }

    else if (loguei == 1)
    {
     do {
     cont = 0;
     printf ("\n\t--------Gerênciamento---------");
     printf ("\n->'1' Quem é a WeDoCare?");//iok
     printf ("\n->'2' Publicar alguma sugestão.");//ok
     printf ("\n->'3' Publicar alguma reclamação.");//ok
     printf ("\n->'4' Permutas Cadastradas.");//ok //trocar o swich case
     printf ("\n->'5' Voltar.");//ok //trocar o switch case
     printf ("\n\t-------------------------------\n");
     printf ("Digite aqui uma das opções: ");
     scanf ("%d", &cont);
     getchar ();
     limpatela();

    switch (cont)
    {
        case 1:
        printf ("\n\t\t\t-----Quem somos?-----");
        printf ("\n\t->A 'WeDoCare' é uma micro empresa ainda em desenvolvimento. \nA WeDoCare acolhe pessoas com necessidades especiais, provendo aparelhos e suporte para os mesmos.<-");
        printf ("\n\t\t\t---------------------");
          getch ();
           limpatela();
            break;

        case 2: sugestao ();
         break;

        case 3: reclamacao();
         break;

        case 4: permutasCad ();
         break;

        case 5:
         cont = 1;
          return;
           break;

        default:
        printf("\nNenhuma ação foi reconhecida.");
        getch ();
        limpatela();
        cont = 1;

    }//fim switch

        } while (cont == 1); //fimdowhile

    }//fimelseif
}//fim gerenciamento




//sugestão
void sugestao ()
{

    printf ("\n\t\t-----Sugestão do Cliente------\n");
    printf ("Descreva neste espaço o que pensa, %s.(49carac MAX): ", cliente.nome);
    gets (p.dicas);
    printf ("\nSua permuta foi adicionada com sucesso.");
    getch();
    limpatela();

}//fim sugestão

//imprime a sugestão
void imprimirsugestao ()
{
     printf ("\n\t\t\t-----Sugestão do Cliente------\n");
     printf ("\nSua sugestão foi: %s", p.dicas );
     getch();
     limpatela();

}

//reclamação
void reclamacao()
{
    printf ("\n\t\t\t-----Reclamações------");
    printf ("\nAqui você pode contar algo que esteja lhe atrapalhando ou também alguma reclamação, %s. (99carac MAX) ", cliente.nome);
    gets (p.reclamacao);
    printf ("\nSua permuta foi adicionada com sucesso.");
    getch();
    limpatela();

}

void solicitacoes ()
{
    if (trans == 1)
    {
        limpatela();
        printf ("\nApenas 1 solicitação por pessoa! Caso necessite re-fazer a solicitação, resete seu carrinho.");
        getch ();
        limpatela();
        return main ();

    }

    if (loguei == 0)
    {
        printf ("\n\n\t->Para acessar esta área é necessário um cadastro. Você será redirecionado para a página de cadastro.<-");
        getch();
        limpatela();
        return cadastro ();
    }
    else {
 struct Produtos cadastroGerencia[6];
 struct Carrinho pedidoSolicitado;

int i, codigoDesejado, posicaoVariavel, foundVariavel=0, QtdCompraSolicitada;
char nomeProd [20];
char descProd [50];
printf("\n-------------------- Cadastro de Produtos ---------------------\n");
for (i=0; i< 5; i++)
{
printf("Codigo..: ");
scanf("%d", & cadastroGerencia[i].codigo);
fflush (stdin);
printf("Quantidade em Estoque..: ");
fflush (stdin);
scanf("%d", & cadastroGerencia[i].qtdEst);
fflush (stdin);
printf ("\nNome do produto: ");
gets (cadastroGerencia[i].nome);
printf ("\nDescrição do produto: ");
gets (descProd);
fflush (stdin);
printf("Quantidade em Minima no Estoque..: ");
scanf("%d", & cadastroGerencia[i].qtdMinEst);
fflush (stdin);
printf("Valor do Produto..: ");
scanf("%f", & cadastroGerencia[i].valor);
fflush (stdin);
printf("\n-----------------------------------------------------------------\n");
limpatela();
}
limpatela();
printf ("\nAs informações foram cadastradas com sucesso!");
getch();
limpatela();

printf("\n\n----------------------- Carrinho de Compras -------------------\n");

printf("\n\n-------------------- Lista de Produtos ---------------------\n");
printf("\nCodigo \t Valor \tEstoque   Nome\n");
for (i=0; i<5; i++)
{
printf("%d \t %.2f \t %d \t %s \t \n", cadastroGerencia[i].codigo, cadastroGerencia[i].valor, cadastroGerencia[i].qtdEst, cadastroGerencia[i].nome);
}

printf("\n-------------------------------------------------------------------\n");
printf("Informe o codigo do produto que deseja..: ");
scanf("%d", &codigoDesejado);
if (codigoDesejado > 5)
{
    limpatela();
    printf ("\nAção não reconhecida.");
    getch();
    limpatela();

}

for (i=0; i<5;i++)
{
if (cadastroGerencia[i].codigo == codigoDesejado)
{
posicaoVariavel = i; // recebe a posição do vetor onde o codigo do produto está cadastrado
foundVariavel = 1;
break;
}
}
if (foundVariavel ==1)
{
printf("\nQuantidade desejada..: ");
scanf("%d", &QtdCompraSolicitada);
if ( cadastroGerencia[posicaoVariavel].qtdEst < QtdCompraSolicitada)
{
limpatela();
printf("\n Desculpe - Nao temos a quantidade desejadas.");
getch();
limpatela();
return 0;
}

else
{
pedidoSolicitado.codProduto = codigoDesejado;
pedidoSolicitado.qtdDesejada = QtdCompraSolicitada;
pedidoSolicitado.valTotal = QtdCompraSolicitada * cadastroGerencia[posicaoVariavel].valor;
cadastroGerencia[posicaoVariavel].qtdEst = cadastroGerencia[posicaoVariavel].qtdEst -QtdCompraSolicitada; // Atualizando o meu Estoque

                limpatela();
                printf ("Estamos imprimindo sua nota fiscal, %s!", cliente.nome);
                getch();
                printf ("\n\t----------Nota Fiscal----------\n");
                printf ("\n\tOrganização WeDoCare");
                printf ("\n\tCódigo do produto: %d", pedidoSolicitado.codProduto);
                printf("\n\tQuantidade solicitada..: %d", pedidoSolicitado.qtdDesejada);
                printf ("\n\tNome do solicitante: %s", cliente.nome);
                printf ("\n\tCPF do solicitante: %s", cliente.numCad);
                printf ("\n\tNome do item solicitado: %s", cadastroGerencia[i].nome);
                printf("\n\tValor total a pagar: %.2f", pedidoSolicitado.valTotal);
                printf ("\n\t--------------------------------\n\n");
                getch();
                limpatela();
                printf("\n\tAgradecemos sua solicitação! Você será redirecionado ao menu principal. ");
                getch();
                limpatela();
                trans = 1;
                return 0;

}



}


}//fimelse

}//fimsolicitacoes

void imprimereclamacao ()
{
     printf ("\n\t\t-----Reclamações do Cliente------");
     printf ("\nSua reclamação foi foi: %s", p.reclamacao );
     printf ("\nCaso sua reclamação seja de prímórdio acompanhamento, favor entrar em contato");
     printf ("\nWeDoCare se localiza em: bairro: xxxxxx, numero: xxxxx, rua: xxxxxxx. Telefone para contado: (xx)xxxxx-xxxxx ou (xx)xxxx-xxxx");
     printf ("\nSua reclamação será avaliada e até em 24horas retornaremos o contato.");
     getch();
     limpatela();

}

//menu permutas
void permutasCad ()
{
    int cont = 0, op;

do {

    printf ("\n\t\t-----Permutas Cadastradas------");
    printf ("\n->'0' Voltar.");//ok
    printf ("\n->'1' Permuta de Sujestão.");//ok
    printf ("\n->'2' Permuta de Reclamação.\n");//ok
    printf ("Digite aqui uma das opções: ");
    scanf ("%d", &op);
    limpatela();

    switch (op)
    {
        case 0:
         cont = 1;
          return;
           break;
            limpatela ();

        case 1: imprimirsugestao ();
         return permutasCad ();
          break;

        case 2: imprimereclamacao ();
         return permutasCad ();
          break;

        default:
         limpatela();
         printf("Ação não reconhecida.");
         getch();
         limpatela();
         return permutasCad ();
         break;
         limpatela();



    }

    }while (cont == 1);

}







