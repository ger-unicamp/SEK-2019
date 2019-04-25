## Exemplos de códigos em C++ para a plataforma Ev3dev
Este diretório irá conter alguns exemplos de códigos básicos. Assim, podemos ter um tutorial próprio de como mexer na linguagem e dar conta de cada tarefa.

## Como começar meu programa em C++ para rodar no EV3?
Bom, primeiro precisamos definir as bibliotecas que usaremos. Com certeza a primeira será do próprio ev3dev ```ev3dev.h```. Como estamos trabalhando com C++ também precisamos de bibliotecas próprias e ainda tomar cuidado com *namespaces*. Para a biblioteca padrão, ocultaremos o namespace com o comando:

```using namespace std;```

mas para a biblioteca do ev3dev estaremos usando o namespace *ev3*:

```namespace ev3 = ev3dev;```

Então como fica o começo do meu programa considerando tudo isso? Fica assim:

```
/*inclue a biblioteca do ev3dev*/
#include "ev3dev.h"
/*inclui todo o template padrão do C++, i.e. todas as bibliotecas padrão da linguagem*/
#include <bits/stdc++.h> 

using namespace std;
namespace ev3 = ev3dev;
```

## Como usar os sensores e motores no meu programa?
Não vai ficar tão diferente assim do python. Os sensores conseguem detectar automaticamente em qual porta estão. Já os motores, precisamos indicar as portas. A maior diferença, além da sintaxe, será o uso do namespace falado acima apenas na declaração dos devices.
Exemplo da declaração dos sensores e motores em C++ considerando as linhas de código acima:
```
int main(){
    /*declaração dos motores*/
    ev3::large_motor          lMotor("outA"); /*O motor esquerdo está na porta A*/
    ev3::large_motor          rMotor("outB"); /*Já o direito, na porta B*/
    ev3::medium_motor         mMotor("outC"); /*O menor motor está na porta C*/
    
    /*Declaração dos sensores*/
    ev3::touch_sensor         ts;
    ev3::gyro_sensor          gs;
    ev3::ultrasonic_sensor    ultra;
    ev3::color_sensor         col;
    
    return 0;
}
```

Mas é só isso? Estamos quase lá! Cada device da biblioteca do ev3 exige que tratemos de excessões. Essas excessões são as verificações de conexão de cada device no próprio ev3. Em C++ esta verificação pode ser feita através de uma simples função que checa se estamos mandado um verdadeiro, se está conectado, ou falso caso não esteja. A função de verificação lança uma excessão da biblioteca padrão do C++ chamada runtime error. Segue implementação abaixo:

```
[...]


void precondition(bool condition, const string& msg){
    if(!condition) throw runtime_error(msg);
}

int main(){
    [...]
    
    /*verifica os motores*/
    precondition(lMotor.connected(), "Motor esquerdo não conectado");
    precondition(rMotor.connected(), "Motor direito não conectado");
    precondition(mMotor.connected(), "Motor medio não conectado");
    
    /*verifica sensores*/
    precondition(ultra.connected(),  "sensor ultrassonico não conectado");
    precondition(gs.connected(),     "sensor gyro não conectado");
    precondition(ts.connected(),     "sensor de toque não conectado");
    precondition(col.connected(),    "sensor de cor não conectado");
    
    [...]
    
    return 0;
}
```

## Como eu compilo meu código para mandar para o ev3?
Primeiro, precisamos entender a diferença de arquitetura. Para compilar um programa em C++ no seu computador para rodar no *seu próprio computador* usamos o seguinte comando no terminal:

```
g++ nome_do_executavel nome_do_codigo.cpp -std=c++11 -Wall -O2
```

Entretanto, se você executar o seguinte comando ```file nome_do_executavel``` você verá que tem uma arquitetura associada ao executável, no caso 64 bits (AMD ou Intel). Para o ev3, precisamos adaptar para a arquiterua ARM de 32 bits. Para fazer isto, é necessário instalar no seu computador (Linux) o pacote ```cpp-arm-linux-gnueabi``` e ```gcc-arm-linux-gnueabi```. Feito isso, executamos o seguinte comando no terminal:

```
arm-linux-gnueabi-g++ -o nome_do_executavel ev3dev.cpp nome_do_codigo.cpp -std=c++11 -static -Wall
```

Note que é importante conter a implementação da biblioteca ev3dev.h representada por ev3dev.cpp, o código feito e as flags que acompanham o comando para evitar erros de dependências e versões. Agora, transferimos o ```nome_do_executável``` para o robô e executamos com o seguinte comando: ```./nome_do_executavel```

## Makefile, nosso companheiro facilitador 
Com o arquivo Makefile, podemos automatizar o processo de compilação apenas executando ```make``` na linha de comando. Para isto precisamos criar um arquivo Makefile que faça sentido para os nossos códigos. Suponha que eu tenha um programa chamado drive-test.cpp e quero compilá-lo e rodá-lo no ev3. Podemos substituir o comando acima por:

```
arm-linux-gnueabi-g++ -o drive-test ev3dev.cpp drive-test.cpp -std=c++11 -static -Wall
```

Em teoria, está certo! É só mandar o ```drive-test``` para o ev3 e executá-lo. Mas e se tivermos outros arquivos contendo funções e classes que estamos usando no drive-test.cpp? E se esse e outros arquivos estiverem outras dependências, ou seja, outros arquivos que contém funções e classes que esses usam? Digitar tudo isso no terminal vai ser muito trabalhoso, principalmente quando esquecemos um único ';' no meio desses códigos. Aí que entra o Makefile. 

Com o Makefile podemos criar dependências de compilação de códigos e automatizar tarefas. Imagina que seja necessário compilar três programas para compilar o drive-test. Podemos construir essa árvore de dependências e executá-la com um único comando. Imagina agora se mudássemos uma linha no arquivo drive-test e não temos o Makefile. Precisaríamos compilar tudo de novo, na mão, por causa de uma única linha. Usando o exemplo aqui citado, a representação do Makefile está abaixo:

```
all: main
main:
    arm-linux-gnueabi-g++ -o drive-test drive-test.cpp ev3dev.o -std=c++11 -static -Wall
ev3dev.o : ev3dev.cpp
    arm-linux-gnueabi-g++ -c ev3dev.cpp -static -Wall
```

Agora, ao executarmos ```make``` teremos uma cadeia de compulação começando pela última linha até chegarmos em ```all```. Assim, geramos o arquivo ev3dev.o apenas uma vez e, quando for necessário atualizar uma única linha ou até mesmo todo o arquivo drive-test.cpp, o Makefile irá executar somente a última linha de compilação, pois nada abaixo dela foi modificado.
