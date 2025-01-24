# Implementação de jogos de tabuleiro em CPP

# DOCUMENTAÇÃO: https://printfgabriel.github.io/JogosDeTabuleiro-PDS2/html

## Introdução e funcionalidades
  Este é um trabalho da disciplina de Programação e Desenvolvimento de Software II, dada no 2º semestre do cursos de Ciência da Computação e Sistemas de Informação na Universidade Federal de Minas Gerais (UFMG). Trata-se de um software no terminal em C++ que se propõe a gerenciar jogos de tabuleiro, que permite ao seu usuário realizar as seguintes operações:
<ul>
    <li>Cadastrar jogadores;</li>
    <li>Remover jogadores;</li>
    <li>Listar jogadores em ordem alfabética pelo nome ou apelido</li>
    <li>Jogar Damas, LigFour, Reversi e Jogo da Velha;</li>
    <li>Ver estatísticas de vitórias dos jogadores.</li>
  </ul>
 
  
## Requerimentos
Para executar essa aplicação através do arquivo main, é necessário possuir o <strong>C++ junto ao G++</strong> instalados no computador.


## Como executar

### 1. Clone o repositório

```git clone https://github.com/printfgabriel/JogosDeTabuleiro-PDS2.git```

### 2. Instale o Make (distros Linux baseadas em Arch e Debian, respectivamente)

```sudo pacman -Syy make``` 

```sudo apt install make```

### 3. Compilação
Deve ser realizada na seguinte ordem dentro da pasta descompatada JogosDeTabuleiro-PDS2:

```make clean```

```make```

```bin/./main```

### 4. DOXYGEN

Para verificar o Doxygen, basta entrar na pasta <strong>html</strong> e procurar por <strong>index.html</strong>. Ao abrir o arquivo, redireciona-se para a web, onde está toda a documentação do código.

### 5. DOCTEST

No trabalho foi utilizada a biblioteca de teste de software Doctest, em sua versão 2.4.11. O arquivo de cabeçalho da biblioteca encontra-se na pasta third_party.

Os arquivos de teste das classes estão na pasta tests, e podem ser compilados pelo comando:

```make test_NOMEJOGO```

onde NOMEJOGO é checkers, ligfour, tictactoe ou reversi.

Para executar os jogos, basta digitar o comando:

```bin/./testeNOMEJOGO```

onde NOMEJOGO é Checkers, LigFour, TicTacToe ou Reversi.