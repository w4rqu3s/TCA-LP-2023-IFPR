<h1 align="center">TCA - Gerência de Campeonato</h1>
<p align="center">Trabalho Conclusivo Anual da disciplina de Linguagem de Programação na IFPR Paranaguá</p>

## 🗣 | Descrição

O software foi desenvolvido como trabalho de conclusão da disciplina de LP do curso de informática da IFPR Paranaguá, e deveria funcionar como um sistema de gerenciamento de Turmas e Times do campeonato de futebol do colégio. 


## 📝 | Requisitos

O sistema deveria ter cumprir as seguintes funcionalidades:

- [x] CRUD de Turmas e Tims
- [x] Relacionar turmas e times (seguindo requisitos mais específicos)
- [x] Utilizar alocação dinâmica para Strings e Vetores
- [x] Salvar os dados em arquivos texto


## 🛠 | Tecnologias

O projeto foi programado em **C** por ser a linguagem lecionada na disciplina. Foram utilizadas apenas biblioetcas padrões da linguagem, sendo elas **<stdio.h>, <stdlib.h>, <string.h>** e **<ctype.h>**. O programa foi desenvolvido no **Visual Studio Code**.

## 🕹 | Utilização

#### (🔽) - Instalação
Baixe um dos arquivos do programa e salve numa pasta do seu computador, de preferência uma pasta separada/reservada.
OBS: Baixe a versão correta de acordo com o seu sistema operacional, caso contrário o programa não funcionará corretamente.

#### (🔌) - Iniciar
Para utilizar o sistema, basta baixar o arquivo execuável e abrí-lo, ou baixar o arquivo em C e compilar para um executável.
O programa abrirá no terminal da ferramenta que você esitver utilizando.

#### (📁) - Arquivos
Na primeira execução, o código criará 2 arquivos para salvamento de dados chamados *times.txt* e *turmas.txt*. Para evitar erros no sistema, por favor, **não edite os arquivos**.

#### (🧤) - Utilizar
O funcionamento do programa é intuitivo, basta selecionar as opções desejadas e seguir as instruções. 

#### (⚠) - Avisos
Por se tratar de um software programado em C, é necessário se atentar a alguns tópicos devido as limitações da linguagem:

1. 🚫 Não feche o programa/terminal em que o programa está executando sem antes selecionar a opção *sair* no *Menu Principal* - Como o programa utiliza alocação dinâmica para criar 
Strings e Vetores, é necessário que você encerre o código corretamente para que as alocações de memória sejam liberadas, caso contrário isso pode prejudicar a execução do programa e a memória.

2. 🚫 Não edite os arquivos de salvamento do sistema - Isso pode prejudicar o funcionamento do programa, uma vez que o mesmo utiliza uma sintaxe específica de texto para marcar as
informações

3. 🚫 Não digite dados de tipo errado nos campos de inserimento (por exemplo, digitar um caractere onde era pedido um inteiro) - Por se tratar de uma linguagem limitada, isso pode
quebrar o programa e encerrá-lo indevidamente

4. 🚫 Não utilize a versão errada do programa (Linux/Windows) - Alguns comandos utilizados dentro do código windows podem não funcionar no Linux e vice-versa, portanto para evitar
bugs utilize a versão correta do programa.



