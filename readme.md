# 21 Master

Bem-vindo ao repositório do **21 Master**! Este projeto foi desenvolvido utilizando a linguagem de programação C e explora conceitos de estruturação de código, manipulação de ponteiros, e interação com o console.

## Sumário

- [Descrição](#descrição)
- [Como Jogar](#como-jogar)
- [Recursos Implementados](#recursos-implementados)
- [Requisitos do Sistema](#requisitos-do-sistema)
- [Como Compilar](#como-compilar)
- [Contribuição](#contribuição)
- [Licença](#licença)
- [Detalhes da Licença](#detalhes-da-licença)

## Descrição

**21 Master** é um jogo de blackjack com três níveis de dificuldade, possui tambẃm o modo jogador contra jogador para jogar com seu amigo, seus gráficos são em vetor trazidos do 'Freepik' e 'OpenGameArt'. Este jogo foi desenvolvido como parte de um projeto pessoal.

## Como Jogar

1. Ao iniciar o jogo, você pode decidir renomear os dois jogadores tanto você quanto a máquina. Mas também pode clicar no modo 'P vs CPU' para jogar contra a máquina ou no 'P vs P' para jogar contra outro jogador.
2. As regras do jogo são: Cada jogador pode possuir até 6 cartas. Perde quem ultrapassar 21 pontos. Em caso de empate, vence quem tiver o menor número de pontos. Para ganhar automaticamente, basta atingir 21 pontos ou ter 6 cartas na mão.
3. Para interagir, você pode utilizar os seguintes comandos:
   - **[Botões]**: Todo o jogo é gerido por botões na tela.
   - **[Alt + Enter]**: Para ativar a tela cheia.

## Recursos Implementados

- Os gráficos foram feitos com a biblioteca SDL.
- A música foi pela biblioteca SDL\_MIXER.
- Os textos foram desenhados pelo SDL\_TTF.

## Requisitos do Sistema

- Compilador C (como GCC ou MSVC)
- Sistema operacional: [Linux/Windows/macOS]
- SDL2
- SDL\_mixer
- SDL\_ttf

## Como Compilar

1. Certifique-se de ter um compilador C instalado em seu sistema.

2. Instale as bibliotecas do SDL.
   ```bash (Debian/Ubuntu e derivados)
      sudo apt update
      sudo apt install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev
      ```
3. Clone este repositório:
   ```bash
   git clone https://github.com/Otaviano-Manoel/black_jack_sdl.git
   ```
4. Navegue até o diretório do projeto:
   ```bash
   cd home/../black_jack/
   ```

5. Compile o código-fonte:
   ```bash
      mkdir -p build && cd build
      cmake ..
      make
   ```

6. Extraia os Assets:
   ```bash
      cd home/../black_jack/
      unzip assets.zip -d /home/../black_jack_sdl/build/Debug
   ```

7. Execute o jogo:
   ```bash
   /home/../black_jack_sdl/build/Debug/outDebug
   ```

## Contribuição

Contribuições são bem-vindas! Se você encontrar problemas ou tiver sugestões de melhoria.

## Créditos

### Gráficos
#### Freepik(freepik.com)
- @stockgiu
- @bearicons
- @rawpixel.com
- @iyikon
- @freepik
- @juicy_fish
#### Other Sources
- Andrew Tidey (andrewtidey.blogspot.co.uk)

### Música
#### Free Music Archive(freemusicarchive.org)
- Zane Little

### Agradecimentos especiais
- Um agradecimento especial ao meu irmão, George Paulino, por sempre estar ao meu lado e tornando cada passo dessa jornada mais leve e especial.

## Licença

O código-fonte deste projeto está licenciado sob a [Creative Commons Zero (CC0)
](https://creativecommons.org/publicdomain/zero/1.0/deed.pt-br), o que significa que você pode usar, modificar e distribuir o código livremente para qualquer finalidade, sem restrições de direitos autorais.

Os gráficos, por outro lado, estão sujeitos à licença [Creative Commons Attribution 4.0 (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/deed.pt-br). Isso significa que você pode usar, modificar e distribuir os gráficos, mas deve fornecer a atribuição adequada aos autores conforme especificado nos créditos.

## Detalhes da Licença

Código-fonte: [CC0 1.0 Universal (CC0 1.0)
](https://creativecommons.org/publicdomain/zero/1.0/deed.pt-br).

Gráficos: [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/deed.pt-br).


