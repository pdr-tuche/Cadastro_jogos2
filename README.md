
# cadastro_Fliperama
#### Projeto da disciplina: Programação Estruturada 2019.2 , interface gráfica criada utilizando o framework Qt SDK.
Aplicação desenvolvida para cadastrar jogos eletrônicos. Com o objetivo de gerenciar o estoque de jogos eletrônicos de um fliperama indepedentemente da plataforma em que o jogo é executado.

## Como usar:
### cadastro:
Após inserir os dados necessários, basta clicar no botão "Confirmar" para inserir ao estoque.
A aplicação não permite cadastros em branco, os atributos "nome do jogo" e "código" já existente no estoque, nome do jogo com menos de três caracteres e os atributos "quantidade" e "preço" com valores igual a zero. Caso houver alguma situação como os casos citados acima, será apresentada uma mensagem de alerta para o usuário corrigir os dados invalidados.
## Funções:
Após feito o cadastro, é possível ver as estatísticas: média de preço, preço mais alto e mais baixo (imagem a seguir). As estatísticas são instantaneamente atualizadas a cada novo cadastro.

![estatisticas](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/janela.png)

A aplicação permite a ordenação alfabética dos dados cadastrados clicando no botão em vermelho na imagem a seguir:

![alfabeticamente](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/ordenado_nome.png)

A aplicação permite a ordenação por disponibilidade dos dados cadastrados clicando no botão em vermelho na imagem a seguir, assim, mostrando os dados cadastrados do jogo mais borbotoante até o mais escasso.

![ordenado_por_quantidade](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/ordenado_quantidade.png)

é necessário salvar seus dados antes de fechar a aplicação. Para salvar seus dados basta clicar no botão "salvar tabela" (em vermelho na imagem a seguir), e escolher o local de armazenamento. O seu arquivo deve ser do tipo .csv, outros tipos de arquivos não são suportados pela aplicação. Para que haja uma maior organização de seu estoque é recomendado nomear o arquivo com o nome da plataforma dos jogos que foram cadastrados, assim separando jogos de plataformas diferentes. Exemplo: (nintendo.csv , playstation.csv , xbox.csv). Não obstante, o usuário pode cadastrar jogos de várias plataformas em um unico arquivo se desejar.

![salvar](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/salvar_tabela.png)

Para carregar um arquivo com dados de jogos já inscritos basta clicar no botão "carregar um arquivo". Será aberta uma janela para ser selecionado qual arquivo abrir conforme a imagem abaixo.

![carregar](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/selecao_carregar_arquivo.png)

É possível editar um cadastro por vez, digitando novamente nos campos de atributos do cadastro (em amarelo na imagem a seguir), e após selecionar o Jogo o qual a modificação será feita clicando na tabela, basta clicar no botão "editar item" para que assim seja feita a modificação. (Não é possível fazer a modificação de apenas um atributo. É necessário preencher todos os campos dos atributos para ser feita a modificação.)

![editar](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/selecao_editar_item.png)

Se excluir um cadastro for necessário, selecione o Jogo na tabela e clique no botão "Excluir item". (Não é possível fazer múltiplas exclusões).

![excluir](https://github.com/pdr-tuche/Cadastro_jogos2/blob/master/imagens/selecao_excluir_item.png)

#
##### that's all folks
