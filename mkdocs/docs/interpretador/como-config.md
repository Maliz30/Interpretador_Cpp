## Como configurar o Interpretador

Este roteiro apresenta os procedimentos para instalação e configuração das ferramentas Flex, Bison e Git, para usuários macos, windows e linux.

### 1. Introdução

O objetivo deste roteiro é preparar o ambiente de desenvolvimento com as seguintes ferramentas:

- **Flex:** para análise léxica.
- **Bison:** para análise sintática.
- **Gcc:** compilar código fonte.

---

## 1. Instalação e configuração do ambiente

### 1.1 MacOS

**1.1.1 Ativação do Flex e Bison:**

É necessário que o homebrew já esteja instalado, caso não esteja, siga o [passo a passo](https://brew.sh/pt/).

1. Instalar o flex e o bison:

```bash
brew install flex bison
```

2. Para garantir que o Brew irá utilizar os path corretamente faça:

```bash
export PATH="$(brew --prefix flex)/bin:$PATH"
export PATH="$(brew --prefix bison)/bin:$PATH"
```

3. Para carregar as mudanças: 

```bash
source ~/.zshrc
```

4. Para verificar se deu certo: 

```bash
flex --version
bison --version
```

**1.1.2 Rodando o projeto:**

1. Dentro da pasta _/parser_:

- rode o bison: ```bash
                bison -d parser.y
                ```

<br>

2. Dentro da pasta _/lexer_:

- rode o léxico: ```bash
                flex lexer.l
                ```

<br>

3. Dentro da pasta _/src_:

Faça:
- gere o executável: ```bash
                    gcc -o executavel parser/parser.tab.c lexer/lex.yy.c -lfl
                    ```
- rode (inserindo dados manualmente): ```bash
                                    ./executavel
                                    ```
- rode (inserindo um arquivo de teste): ```bash
                                        ./executavel < codigos_teste/nomeArquivoDeTeste.cpp
                                        ```

Ou:

- para rodar com makefile:

```bash
make        # compila tudo
make run    # roda o programa compilado
make clean  # apaga os arquivos gerados
make run-hello       # roda com o teste hello.cpp
make run-conditional # roda com o teste conditional.cpp
# e assim vai...
```

---

### 1.2 Windows (usando WSL)

**1.2.1 Ativação do WSL:**  
Execute no PowerShell (como administrador):

```powershell
wsl --install
```

Depois de reiniciar, abra o Ubuntu do WSL.

**1.2.2 Instalação do Flex, Bison e Git no WSL (Ubuntu):**

```bash
sudo apt update
sudo apt install flex bison build-essential git -y
```

**1.2.3 Verificação:**

```bash
flex --version
bison --version
```

**1.2.4 Rodando o projeto no WSL:**

1. Dentro da pasta _/parser_:  ```bash
                                bison -d parser.y
                                ```

2. Dentro da pasta _/lexer_:  ```bash
                            flex lexer.l
                            ```

3. Dentro da pasta _/src_:  ```bash
                            gcc -o executavel parser/parser.tab.c lexer/lex.yy.c -lfl
                            ```

4. Rode direto no terminal:  ```bash
                            ./executavel
                            ```

5. Ou rode inserindo arquivo de teste:
```bash
./executavel < codigos_teste/nomeArquivoDeTeste.cpp
```

6. Ou simplesmente use o Makefile:
```bash
make           # compila tudo
make run       # roda o programa compilado
make clean     # apaga os arquivos gerados
make run-hello       # roda com o teste hello.cpp
make run-conditional # roda com o teste conditional.cpp
# e assim vai...
```

---

### 1.3 Linux (Ubuntu)

**1.3.1 Instalação do Flex, Bison e Git:**  

```bash
sudo apt update
sudo apt install flex bison build-essential git -y
```

**1.3.2 Verificação:**  
```bash
flex --version
bison --version
```

**1.3.3 Rodando o projeto no Linux:**  

1. Dentro da pasta _/parser_:  ```bash
                                bison -d parser.y
                                ```

2. Dentro da pasta _/lexer_:  ```bash
                            flex lexer.l
                            ```

3. Dentro da pasta _/src_:  ```bash
                            gcc -o executavel parser/parser.tab.c lexer/lex.yy.c -lfl
                            ```

4. Rode direto no terminal:  ```bash
                            ./executavel
                            ```

5. Ou rode inserindo arquivo de teste:
```bash
./executavel < codigos_teste/nomeArquivoDeTeste.cpp
```

6. Ou simplesmente use o Makefile:
```bash
make           # compila tudo
make run       # roda o programa compilado
make clean     # apaga os arquivos gerados
make run-hello       # roda com o teste hello.cpp
make run-conditional # roda com o teste conditional.cpp
# e assim vai...
```


## Histórico de Versões

| Versão |    Data    | Descrição                       | Autor(es)                                 | Revisor(es)                                         |
|--------|:----------:|---------------------------------|-------------------------------------------|-----------------------------------------------------|
| 1.0    | 26/06/2025 | Criação da página               | [Milena Baruc](https://github.com/MilenaBaruc) | [Maria Alice](https://github.com/Maliz30)      |
