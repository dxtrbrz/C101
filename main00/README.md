# C 101
## Uma breve introdução

Este primeiro trecho de código é uma estrutura básica de um programa em C. Isto é o mínimo necessário para que o seu programa seja compilado.

## Include

O termo #include inclui o cabeçalho de uma biblioteca essencial, a biblioteca padrão de entrada e saída: stdio

As declarações iniciadas por cerquilha ("#") são um tipo de declaração especial. Não são parte da linguagem C propriamente dita, não são compiladas com o código. Chamam-se diretrizes de pré-compilação. Isto significa que essas declarações passam instruções para um programa chamado pré-compilador. Elas sequer são passadas para o compilador nas fases seguintes.

As diretrizes de pré-compilação são os temas que abordaremos nas etapas seguintes desse projeto, bem como outros mais.

## A função main()

Essa função é propriamente o nosso programa. Nem tudo em um programa precisa acontecer em uma função main, mas essa é a forma mais comum de iniciar um programa.

No nosso exemplo, a declaração da função começa com int main(){}. O termo int determina o tipo de retorno da função, isto é, se a função terminar corretamente, ela retornará algo ao programa principal. Neste caso, a função main retorna um dado do tipo inteiro. E o programa principal é o terminal do Linux.

Dentro dos parêntesis, ficariam o que chamamos de argumentos da função. Trataremos disso mais a diante, em outras fases. Por enquanto, main() não recebe nenhum argumento e, portanto, os parentesis encontram-se vazios.
uto
Em seguida, temos as chaves {}. É entre as chaves que se encontra o código que determina o que uma função faz.

### A metáfora de uma indústria
Pense em uma indústria, por um momento. Uma função é como uma indústria que recebe insumos determinados (argumentos), executa diversas ações para processar estes insumos e, por fim, tem como resultado um determinado produto (retorno).

Eventualmente, uma indústria pode consumir produtos de outra indústria. Uma indústria de automóveis pode não fabricar vidros, bancos e até mesmo motores. Ela apenas conta que outra indústria fabrique estes itens e que eles estejam disponíveis no momento em que eles forem necessários.

Em um programa, podemos ter funções que chamam funções para processar os dados.

Nosso programa, no entanto, é extremamente simples. Ele simplesmente retorna um inteiro, tal qual a função main exige.

## Compilação

O processo de compilação é composto por várias fases, como veremos em seguida. Por hora, considere que compilar é transformar o código de alto nível em um código de baixo nível.

### Alto nível

Isto fala sobre o nível de abstração. Um línguágem de alto nível é uma linguágem que é legível. É bem verdade que para um leigo, a linguágem C não é muito legível, principalmente se não conhecer o idioma inglês. Mas usamos palavras do dicionário e uma sintaxe (isto é, há uma regra em como as palavras se relacionam).

### Baixo nível

Um baixo nível de abstração significa que estamos muito perto de como um computador "pensa". Talvez isto nunca tenha passado na sua mente, mas um computador não entende o nosso idioma. Um computador é como uma cálculadora. Há muitos níveis de abstração envolvidos entre vocês falar o nome de sua assitente virtual, dar um comando em Português e uma ação ser executada.

Mas no menor nível de abstração, um computador só entende números. Nossos computadores modernos, só entendem números em uma representação específica chamada base numérica binária.


## Como compilar

Não se preocupe ainda, trataremos dos detalhes em outro momento.

Por hora, devemos apenas compilar para sabermos se nosso programa funciona.

No Linux, temos um programa chamado gcc. Este é um conjunto de ferramentas (programas especiais) que farão todo o trabalho pesado. Podemos ter o gcc no Windows também.

Se digitarmos ``` gcc main.c ```, no terminal o gcc criará um arquivo binário executável. Por padrão, o nome desse arquivo é a.out.

Para executá-lo, digite o seguinte comando no terminal:

```
./a.out
```

## Lidando com o retorno de um programa no Linux

Bem, o resultado pode parecer frustrante, pois o programa não faz absolutamente nada!
Na verdade, isto é algo que você precisa saber. Um computador só é tão esperto quanto o código que o programa. Ele nunca faz nada além do que foi pedido. Neste caso, não pedimos nada e não recebemos nada.

Imprimir na tela um resultado é uma ação, portanto, é executada por uma função (que já veremos). Se não chamamos a função de imprimir, não teremos nada a ser visualizado. E foi o que aconteceu!

Quer dizer que isso é uma notícia boa! Se houvesse um erro de sintaxe, o programa não compilaria. Não dar erro, é um sucesso em C!

Mas e o retorno? Aparentemente retornar é uma ação, correto? Do ponto de vista de uma instrução executada pelo processador, sim! 

O que ocorreu com o nosso retorno? Bem, um comando (um programa) executado no terminal do Linux precisa retornar um código. Este código é usado para determinar se o programa executou corretamente ou se houve algum erro, apesar de não termos feito esse tratamento.

Aqui vai uma dica de Linux: o retorno do último comando fica armazenado em uma variável especial. É a variável $?. O nome não ajuda, mas este é um atalho muito útil!

Apos executar o programa, execute o comando
```
echo $?
```

Pronto! Você já fez o seu primeiro programa e já sabe como acessar o retorno de uma função principal.

Tente alterar o valor do retorno, recompilar e reexibir o retorno. E não se acostume, apenas este primeiro contato é suoerficial assim. Logo, logo estaremos tratando em maior profundidade os assuntos.