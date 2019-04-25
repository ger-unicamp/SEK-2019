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
