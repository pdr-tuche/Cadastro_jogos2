# Cadastro_jogos2
atualizacao

# cadastro_de_jogos

  

#### Projeto da disciplina: Programação Estruturada 2019.2, utilizando o framework Qt Creator.

Aplicação desenvolvida para cadastrar jogos eletrônicos. Com o objetivo de gerenciar o estoque de jogos eletrônicos de um fliperama indepedentemente da plataforma em que o jogo é executado.

## Como usar:
### cadastro:
Após inserir os dados necessários para concluir o cadastro, basta clicar em confirmar para inseri-la ao estoque.
A aplicação não permite cadastros dos atributos em branco, nome do jogo já existente no estoque, código já existente no estoque, nome do jogo com menos de três caracteres e os atributos "quantidade" e "preço" com valores igual a zero. Caso houver alguma situação como os casos citados acima, será apresentada uma mensagem para o usuário corrigir os dados invalidados.
### Funções:
Após feito o cadastro, é possível ver as estatísticas: média de preço, preço mais alto e mais baixo (imagem a seguir). As estatísticas são instantaneamente atualizadas a cada novo cadastro.

![cadastro](https://github.com/pdr-tuche/cadastro_de_jogos/blob/master/cadastro_estatisticas.png)

A aplicação permite a ordenação alfabética dos jogos cadastrados clicando no botão em vermelho na imagem a seguir:

![alfabeticamente](https://github.com/pdr-tuche/cadastro_de_jogos/blob/master/ordenado_nome_botao.png)

A aplicação permite a ordenação por disponibilidade dos jogos cadastrados clicando no botão em vermelho na imagem a seguir, assim, mostrando os dados cadastrados do jogo mais borbotoante até o mais escasso.


![quantidade](https://github.com/pdr-tuche/cadastro_de_jogos/blob/master/ordenado_quantidade_botao.png)

é necessário salvar seus dados antes de fechar a aplicação.
Para salvar seus dados basta clicar no botão "salvar" (em vermelho na imagem a seguir), e escolher o local de armazenamento. O seu arquivo deve ser do tipo .csv, outros tipos de arquivos não são suportados pela aplicação.
Para que haja uma maior organização de seu estoque é recomendado nomear o arquivo com o nome da plataforma dos jogos que foram cadastrados, assim separando jogos de plataformas diferentes. 
Exemplo: (nintendo.csv , playstation.csv , xbox.csv).
Não obstante, o usuário pode cadastrar jogos de várias plataformas em um unico arquivo se desejar.

Para carregar um arquivo com dados de jogos já inscritos basta clicar no botão "carregar arquivo" (em amarelo na imagem a seguir), e escolher qual arquivo abrir.

![salvar_carregar](https://github.com/pdr-tuche/cadastro_de_jogos/blob/master/salvar_carregar.png)

#
#### "that's all folks !"
