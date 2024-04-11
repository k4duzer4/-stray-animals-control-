# Controle de Animais de Rua 🐾

Este é um sistema de controle de animais de rua desenvolvido como parte de um projeto para a disciplina de Linguagem de Programação I. O projeto foi desenvolvido em linguagem C e tem como objetivo permitir o cadastro, adoção e consulta de animais em situação de rua. Abaixo está uma visão geral do projeto, incluindo detalhes sobre a implementação em C.

## Linguagem C e Componentes Utilizados 🖥️

O projeto foi desenvolvido em linguagem C, utilizando os seguintes componentes:

- **Estruturas de Dados (struct)**: Foram utilizadas estruturas de dados para representar os animais e o projeto em si. A estrutura `Animal` representa cada animal cadastrado, enquanto a estrutura `Projeto` guarda uma lista de animais e o número total de animais cadastrados.

- **Alocação Dinâmica de Memória (malloc e realloc)**: A alocação dinâmica de memória foi utilizada para permitir a adição de novos animais ao sistema, utilizando a função `realloc` para redimensionar o array de animais.

- **Entrada e Saída de Dados (stdio.h)**: As funções de entrada e saída padrão da linguagem C foram utilizadas para interagir com o usuário através do terminal.

- **Manipulação de Strings (string.h)**: A biblioteca `string.h` foi utilizada para manipular strings, como remover novas linhas (`\n`) e copiar strings.

- **Controle de Fluxo (switch-case)**: A estrutura `switch-case` foi utilizada para implementar um menu de opções interativo para o usuário.

- **Persistência de Dados (arquivos)**: O sistema permite carregar e salvar os dados dos animais em um arquivo de texto, permitindo que as informações persistam entre execuções do programa.

## Funcionalidades Principais 🚀

O sistema possui as seguintes funcionalidades principais:

1. **Cadastrar Animais**: Permite o cadastro de novos animais, incluindo nome, espécie, idade, sexo, cor, endereço, doenças e se o animal já foi adotado.

2. **Mostrar Animais Cadastrados**: Apresenta uma lista dos animais cadastrados no sistema, mostrando suas informações básicas.

3. **Adotar Animais**: Permite a adoção de animais disponíveis para adoção, marcando-os como adotados e registrando o nome do tutor.

4. **Mostrar Animais Adotados**: Exibe uma lista dos animais que já foram adotados, mostrando também as informações dos seus tutores.

## Como Utilizar 📝

1. Compile o código-fonte em um ambiente de desenvolvimento C.

2. Execute o programa resultante para iniciar o sistema.

3. Utilize o menu de opções apresentado no console para interagir com o sistema e realizar as operações desejadas.

4. Os dados dos animais são salvos automaticamente em um arquivo de texto (`animais.txt`) e são carregados na inicialização do sistema.

## Aviso 📌

Este sistema de controle de animais de rua é um projeto educacional e pode ser expandido com mais recursos e funcionalidades, como uma interface gráfica, validação de entrada de dados mais robusta, entre outros.

🐾 Adote, não compre! 🐾
