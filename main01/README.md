# Compilação (Parte 1: pré-compilação)

Continuaremos com um programa bastante simples. Agora, faremos uma pequena alteração para que ele execute uma soma e imprima algumas informações. Parece um passo pequeno demais, mas na verade, estamos a correr em ritmo acelerado pois vamos estudar diversos conceitos de computação neste artigo.

A grande mudança desta etapa é no uso do gcc como ferramenta de compilação. Ainda usaremos ele, mas sem as facilidades que ele trás. Isso para que entendamos melhor como o computador altera nosso código até que possa ser executado.

## Arquitetura e organização de computadores

Não nos aprofundaremos nestes temas, estas são matérias de qualquer curso de Engenharia/Ciência da Computação. Mas iremos tocar em diversos assuntos relacionados. Se quiser se aprofundar em como um computador realmente funciona, pegue um bom livro e/ou bons vídeos sobre o tema. Sempre que um conceito de computação for mencionado, marcarei com uma tag [AOC], indicando que é um conceito de arquitetura e organização de computadores e indicando artigos sobre o assunto e palavras-chaves para pesquisas mais aprofundadas.

## A estrutura do código

Nossa estrutura permanece quase igual, porem agora, temos mais conteúdo de leitura. Nosso arquivo de código tem apenas algumas linhas amais. Chamaremos o arquivo de códico em linguágem C de código-fonte.

### O programa

O código-fonte deste programa tem poucas alterações em relação ao código da etapa anterior.

Entre as diferenças, aparecem:
'''
5   int a, b;
13  int c = 0;
'''

Isto é a declaração de variáveis. Nossas variáveis a, b e c são do tipo inteiro. Em C, precisamos declarar as variáveis antes de podermos acessá-las. Outra característica do C é que precisamos especificar o tipo da variável na declaração. Isso porque o C é uma linguagem declarativa. O Python, por exemplo, não necessita de declaração de variáveis, ainda que, em alguns casos, seja recomendável inicilizar uma variável, o que parece muito com uma declaração, mas não é. Em C, a declaração não é uma recomendação opicional, é obrigatório!

O conceito de variável aqui não é o mesmo da matemática. Uma variável é um pedaço reservado da memória.


#### Memória

Podemos classificar a memória de um computador de várias formas. Um computador, no rigor da teoria, é composto por três elemantos: um processador, a memória e um barramento de entrada e saída. Falaremos destes conceitos apenas de forma superficial [AOC].

No sentido estrito, a memória do computador é a RAM, chamada de memória volátil. Na arquitetura dos computadores pessoais, a RAM contem dados e instruções. Em outros dispositivos, instruções e dados podem ficar separados. [AOC, Arquitetura de programa armazenado, modelo de Von Neumann](https://pt.wikipedia.org/wiki/Arquitetura_de_von_Neumann).
[AOC, Arquitetura Harvard](https://pt.wikipedia.org/wiki/Arquitetura_Harvard)

No sentido amplo, o armazenamento pode ser considerado um tipo de memória. Porém é mais lento e está separado do processador pelo barramento de entrada e saída, enquanto a RAM possui um barramento exclusivo.

Com o surgimento das memórias de estado sólido (SSD) e os barramentos NVME, a diferença de velocidade caiu drásticamente. Mas estando em um meio de comunicação compartilhado com todos os periféricos, o SSD ainda pode ficar esperando que o barramento esteja desocupado para que ele possa enviar ou receber dados. Se a RAM estivesse no barramento de E/S, nosso computador travaria constantemente, já que a execução de qualquer programa depende do acesso à ela.
[EAC, Hierarquia de memória](https://pt.wikipedia.org/wiki/Hierarquia_da_mem%C3%B3ria)

Para nós, memória sempre será no sentido estrito, isto é, a RAM. Enquando os SSDs, HDs, pendrives e CD-ROMs serão chamados de armazenamento.

Um programa é armazenado no disco rígido de um computador. Este disco pode ser local (um hd interno) ou remoto (um site, um disco de rede). Quando executamos um programa, ele precisa ser copiado do armazenamento para a memória. O Sistema Operacional (SO) é responsável por fazer isso, bem como por garantir que haja um espeço dedicado para o programa na memória, isso chamamos de alocação de memória. Ao final da execução, o espaço ocupado precisa ser desalocado. 

#### Alocação de memória

Como dito antes, uma variável é um pedaço da memória. Nesta sessão, vamos traduzir para os termos técnicos corretos:

Ao iniciar o programa, o SO reserva um espaço para o programa na memória. Este espaço é dividido entre os dados e o próprio programa. Quando declaramos uma variável do tipo inteiro, por exemplo, o compilador consulta o tamanho de um inteiro em bytes afim de fazer a reserva. Este tamanho pode variar de sitema para sistema, conforme a arquitetura. Por isso, ao compilar um programa para várias plataformas, o tamanho de uma variável pode variar também.

No GCC, poderíamos indicar que estamos compilando um código para o microcontrolador Atmega 328p do Arduíno, para o microcontrolador PIC 16F, para um microprocessador ARM de celular, ou ainda, para um microprocessador Intel ou AMD. Na verdade, há variações até mesmo entre gerações diferentes da Intel, por exemplo.

Por padrão, no Linux, o GCC consulta os cabeçalhos do SO e determina a versão correta para aquele sistema. Você nem precisa ficar sabendo deste processo.

Pois bem, ao declarar a variável inteira, o que irá acontecer é que o SO irá reservar 2 bytes para aquela variável. Simples assim!

Neste caso, estamos usando a "alocação estática de memória". Isto é, no começo da execução, o SO precisa saber exatamente o tamanho do espaço a ser alocado, por isso informamos o tipo (e por consequência o tamanho) de cada variável antes de usá-las. A alocação estática é o padrão do C.

Portanto, as variáveis no C não podem mudar de tipo no meio do programa, e em consequencia disso, também não podem mudar de tamanho. Um int será sempre um int.

Falaremos dos vários tipos em outro momento.

#### O algoritmo de main.c

O algoritmo é simples. Havendo declarado a e b, computaremos a soma deles, salvando em c e, em seguida, imprimiremos algumas informações.

Há muita coisa acontencendo aqui, no entanto.

Em C, declaramos as variáveis. a e b foram declaradas sem nenhum valor. Já c, foi declarado com valor 0, isto é, inicializamos a variável para garantir que ela esteja zerada. É possível que a e b contenham dados lixo, deixado por outro programa na memória, uma falha de segurança! É um risco baixo, mas em geral, é recomendado inicializar as variávies seja fora da função main (como fizemos com a e b), seja dentro da função main (como fizemos com c).

O SO irá fazer a alocação do espaço adequado para cada variável declarada, isso garante alguma memória para que o programa execute e impede que outros programas acessem dados do nosso programa. Há ataques hackers baseados nisso e os sistemas operacionais modernos tentam impedir que isso ocorra. 

Para nós, programadores (chamados de usuários em alguns casos), a memória é uma grade matriz. O SO reserva um bloco de endereços de memória, endereços contíguos. Mesmo que os dados do programa não estejam um do lado do outro na memória, o SO cria essa ilusão. Cada byte, possui um endereço e cada endereço aponta para um byte. É isso que o programador C enxerga e entende.

Mas para o processador, isso faz pouco sentido. Para ele, não há variáveis e não há tipos. Há apenas a memória. Todo o resto é abstração do sistema operacional ou da linguagem. O que o processador conhece são as palavras (word) de 32 ou 64bits dos microprocessadores de PCs, por exemplo e os ponteiros, isto é, endereços que apontam para esses blocos de memória.

Portanto, nosso código precisa ser compilado para que esse punhado de instruções com nível de abstração alta se transforme nas instruções básicas executadas por um processador.

#### Pré-compilação

O processo de compilação, como dito anteriormente, consiste no uso de um conjunto de ferramentas que trasnformam código-fonte (texto) em código-de-máquina (binário executável). O GCC cuida de todas as etapas para nós, escondendo o processo.

Mas na verdade, compilar é mais do que apenas executar um comando do gcc.

A primeira coisa que o gcc faz é chamar um programa chamado cpp, isto é, C pre-processor. Falamos brevemente do pré-processador quando explicamos a instrução define.

O que o pré-processador faz pode ser chamado de expansão do código-fonte. Um programa em C desconhece a função printf() que imprime na tela. De onde vêm essa informação? Um bom chute é que venha da biblioteca de entrada e saída padrão: stdio.h. Se você pensou nisso, acertou!

O pré-processador pega todo conteúdo dessa biblioteca e acrecenta em um arquivo fonte intermediário.

Você pode ignorar o GCC e chamar o CPP por conta própria para ver o que ele faz.

'''
cpp main.c > main.i
'''

O operador ">" no terminal do Linux redireciona a saída do comando à esquerda. Portanto, a saída do CPP ao invés de ser exibida na tela, será gravada no arquivo main.i.

Se quiser exibir o conteúdo do arquivo, você pode executar o comando:

'''
cat main.i
'''
Ou para poupar tempo, você pode imprimir no arquivo e na tela ao mesmo tempo usando o operador "|" (pipe) e o comando tee

'''
cpp main.c | tee main.i
'''

Observe a saída e veja o tanto de código que o cpp adicionou ao seu código-fonte. Nosso código encontra-se no final do código-fonte expandido. Observe a expansão do define. O que um define faz é substituir no código-fonte aquela etiqueta pelo valor atribuído a ela, como o comando buscar e substituir do Word ou do Visual Studio Code. Veja com é um comportamento diferente do que aconteceu com as variáveis.

## Conclusão

Vimos vários conceitos sobre a memória de um computador. Sabemos que é o Sistema Operacional que gerencia a memória, alocando e desalocando espaço para a execução dos programas. Nós interferimos nesse processo declarando as variáveis com tipos diferentes, cada tipo com seu tamanho e uso, que pode ser diferente para cada sistema.

Vimos também que o processador, desconhece o conceito de variáveis e tipos, para ele, há apenas memória e endereços de memória. Alguns conceitos de arquitetura e organização foram abordados superficialmente e alguns artigos sobre o assunto foram recomendados. Tire um tempo para lễ-los

Por fim, vimos que o primeiro passo da compilação é, na verdade , outro processo chamado de pré-compilação, que expande nosso código-fonte através das diretrizes de pré-compilação como o define e o include.