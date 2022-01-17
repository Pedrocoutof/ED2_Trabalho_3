# ED2_Trabalho_3
## Grupo

- Gabriel Toledo Netto Gribel.
- Marcus Vinícius Rodrigues da Silva.
- Nícolas Moraes.
- Pedro do Couto Filgueiras.

## Problemas
  Tivemos grande dificuldade para gerar o 'make-file', mas conseguimos gerar um arquivo '.exe' que acreditamos que possa compensá-lo.

## Como executar
  Na pasta onde o executável (./bin/Debug/) está armazenado execute o seguinte comando:

```         
.\main [diretório do arquivo .csv]
```

  Após isso o programa irá verificar se existe o arquivo "tiktok_app_reviews.bin" arquivo binário na mesma pasta do executável.
  Se não possuir um arquivo binário ele irá criar imprimindo na tela o número de registros gravados.<br>
  
  Caso tenha algum problema para gerar o arquivo binário clique [aqui](https://drive.google.com/drive/folders/19aUpOx9O-iQ_iTyopk2irIskJOty3kDn?usp=sharing)  para ser direcionado a uma pasta no Google Drive onde possui o arquivo binário já pré-processado e outros arquivos CSVs reduzidos.<br>

  Após isso, o programa irá apresentar o menu para interagir com o usuário.<br>

<h2>ÁrvoreVP</h2><br>

**1 - Modo de Análise** <br>
      &emsp;&nbsp;Gera um arquivo chamado "saida.txt" na mesma pasta que o arquivo main está armazenado, com todas as seguintes informações:<br>
      &emsp;&emsp;&emsp; 1 - tamanho da árvore<br>
      &emsp;&emsp;&emsp; 2 - número de comparações na inserção e na busca<br>
      &emsp;&emsp;&emsp; 3 - tempo gasto na inserção e na busca<br>
      &emsp;&emsp;&emsp; 4 - média de tempo gasto e de comparações<br>
      
**2 - Modo de Teste** <br>
      Para facilitar a busca, adicionamos a opção de imprimir toda árvore no terminal, para ver todos os reviews_id's guardados na árvore.
      Logo após, você poderá digitar o review_id que deseja procurar na árvore, se encontrar, o programa perguntará se deseja imprimir todo o conteúdo presente na posição do review_id pesquisado, essa impressão acessará a função 'acessaRegistro()' e exibirá toda informação presente naquela posição do arquivo binário. Caso sua chave não esteja na árvore retornará uma mensagem avisando que a chave não foi encontrada.<br>
      
<hr>
 
 <h2>ÁrvoreB</h2>
 
**1 - Modo de Análise** <br>
      &emsp;&nbsp;Gera um arquivo chamado "saida.txt" na mesma pasta que o arquivo main está armazenado, com todas as seguintes informações:<br>
      &emsp;&emsp;&emsp; 1 - ordem da árvore<br>
      &emsp;&emsp;&emsp; 2 - número de comparações na inserção e na busca<br>
      &emsp;&emsp;&emsp; 3 - tempo gasto na inserção e na busca<br>
      &emsp;&emsp;&emsp; 4 - média de tempo gasto e de comparações<br>
      
**2 - Modo de Teste**<br>
      Para facilitar a busca, adicionamos a opção de imprimir toda árvore no terminal, para ver todos os reviews_id's guardados na árvore.
      Logo após, você poderá digitar o review_id que deseja procurar na árvore, se encontrar, o programa perguntará se deseja imprimir todo o conteúdo presente na posição do review_id pesquisado, essa impressão acessará a função 'acessaRegistro()' e exibirá toda informação presente naquela posição do arquivo binário. Caso sua chave não esteja na árvore retornará uma mensagem avisando que a chave não foi encontrada.<br>
      
