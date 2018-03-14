_O ano em que eu era monitora, ou seja... Em que criei essa bela descrição._

### Trabalho de Alg III - 2015-1 ###

**Data de entrega:** 29/05

**Numero de integrantes(equipe):** MAX 3 alunos


**Descricao:**

Carlos Eduardo adora jogar. E' uma das coisas que mais faz ele feliz nessa vida. Carlos Eduardo quer tornar isso mais prazeroso e menos trabalhoso. Ele encontrou uma bela solucao.

Carimbo, seu irmao, o ensinou a mexer com Arvores de Busca Balanceadas e ele as achou muito uteis e interessantes. Ele gostou particularmente de duas: AVL e 2-3-4. 

Ele quer salvar apenas 3 informacoes dos registros dos jogos: codigo (criado por ele), nome (parte principal) e descricao (sintetizada). Mas, enquanto pensava como salvar essas informacoes, ele considerou que poderia precisar/querer procurar os jogos tanto por nome quanto por codigo. Entao resolveu armazenar nas duas arvores com chaves diferentes:

- AVL -> Codigo
- 2-3-4 -> Nome

Eles devem ser responsaveis por mostrar em qual linha do registro o jogo esta' armazenado. 

A maioria dos jogos que Carlos Eduardo tem sao da Steam e, atualmente, ele usa um linux maroto. No dia 05/05/2015, a lista de jogos da SteamOS+Linux esta' em 2100, mas como ele e' um menino que pensa no futuro, vai colocar um numero maior e codigos mais espacados. 

> De 10001 ate' 16000 -> jogos que tem.  
> De 16001 ate' 22000 -> jogos que ja' jogou e quer comprar.  
> De 22001 ate' 28000 -> jogos que escutou falar e gostou.  
> De 28001 ate' 34000 -> jogos que nunca escutou falar.  
> De 34001 ate' 40000 -> jogos que ja' jogou e nao gostou.  
> De 40001 ate' 46000 -> jogos que as maes dos criadores deveria ter vergonha.  

Carlos Eduardo acha que e' um numero razoavel, pelos menos por enquanto. Algum dia, talvez, se arrependa.

Ele nao quer colocar os nomes inteiros dos jogos, entao ira' manter apenas um indicador do nome (no lugar de Portal 2 -> Portal, em vez de Team Fortress 2 -> Fortress ...), os diferenciando na descricao. Por isso, para referencia, se houver nomes repedidos os salve a Direita.

-------------------------------------------------------------

**Especificacoes de Carlos Eduardo:**

Carlos Eduardo e' exigente e esta' anotando instrucoes especificas do que quer fazer. Vamos ver abaixo o que ele quer fazer:

O programa tera' o nome de steamGames e sera' feito em linguagem C. 

O programa deve permitir duas acoes: inserir e buscar. Na busca ele pode ainda escolher se quer buscar por nome ou pelo codigo. Veja como ele quer abaixo: 

**Execucao:**
	
```sh
./steamGames arqDados arqBuscas
```

ex.:
```sh
./steamGames registros.lol buscarJogos.txt > minhaListaJogos.txt
```

Na execucao da busca sera' puxado os dados de registro.lol, deve ser impresso as duas arvores inteiras (conforme especificacao abaixo) e tera' as seguintes caracteristicas:

> c 10001    -> c == codigo == AVL  
> n Portal   -> n == nome == 2-3-4  
> f -> f == fim da busca  

-----------------------------------------------------------------

- Suponha que o conteudo do arquivo registros.lol e':

> 10001 Portal Esse e' referente ao jogo Portal 2. Muuuito tops! Um dos melhores jogos da zuera! Descricao do site: "The 'Perpetual Testing Initiative' has been expanded to allow you to design co-op puzzles for you and your friends!"  
> 10002 Torchlight Esse e' referente ao jogo Torchlight II. Bom RPG. Varias opcoes. OBS.: meu bicho de estimacao e' um panda chamado ZueraAssassina.  
> 22001 Goat Jogo Goat Simulator. Parece muito louco! A cabra sobe em uma escada pelo pescoco.   
> 28001 Savage Jogo Savage Lands. A qualidade parece boa. User reviews: Very positive.   
> 16001 Portal Esse e' referente so ao jogo Portal. Nao tem algumas coisas do Portal 2, mas mesmo assim...  
> 0  


- E que o conteudo do arquivo buscarJogos.txt e':

> c 22001  
> n savage  
> n portal  
> f  

- A execucao do programa com a chamada 

```sh
./steamGames registros.lol buscarJogos.txt
```

- Deve ser como mostrado abaixo.

> Codigo:  
> (10002 (10001) (22001 (16001) (28001)))  
> 
> Nome:  
> (Portal (Goat) (Portal;Savage;Torchlight))  
> 
> 22001 Goat Jogo Goat Simulator. Parece muito louco! A cabra sobe em uma escada pelo pescoco.   
> Savage 28001 Jogo Savage Lands. A qualidade parece boa. User reviews: Very positive.  
> Portal 10001 Esse e' referente ao jogo Portal 2. Muuuito tops! Um dos melhores jogos da zuera! Descricao do site: "The "Perpetual Testing Initiative" has been expanded to allow you to design co-op puzzles for you and your friends!"  
> Portal 16001 Esse e' referente so ao jogo Portal. Nao tem algumas coisas do Portal 2, mas mesmo assim...  


------------------------------------------------------------
------------------------------------------------------------

**Detalhes de Entrega:**

Deve ser enviado um arquivo compactado tar.gz com, no minimo, os seguintes arquivos:
- main.c
- steamGames.c
- steamGames.h
- Makefile
- LEIAME  (com o cabecalho especificado)

O compactado deve possuir o nome como login.tar.gz. Em caso de trabalho em grupo, deve possuir o login de todos - login1-login2-login3.tar.gz .
Apos descompactar deve gerar uma pasta com o nome do compactado (login ou login1-login2-login3) com todos os arquivos necessarios, sem subdiretorios.

O trabalho deve ser entregue ate' 23h59m do dia 29 de maio de 2015, contendo como titulo do e-mail "CI057 - Trabalho.2015-1" para o  professor de sua turma: 
andrey@inf.ufpr.br
carmem@inf.ufpr.br


** Qualquer duvida, nao hesitem em procurar a monitoria no horario disponivel ou mandar e-mail (cdp13@inf.ufpr.br).


------------------------------------------------------------

**Observacoes:**                                         *IMPORTANTE*
- Deve compilar e rodar nas maquinas do Dinf
- O arquivo Makefile deve possuir opcao clean (apaga todos os arquivos objeto -> .o)
- Utilizar o arquivo steamGames.h, podendo acrescentar funcoes que quiser e julgar necessarias, mas sem alterar o que ja' esta definido.
- Arquivo LEIAME - utilizando cabecalho fornecido no arquivo
	- O que colocar: detalhes do trabalho que achar interessante, dificuldades que teve na implementacao e bugs conhecidos. 



| DICA NOVA!							|  
|:--------------------------------------------------------------|
|* Repare bem na estrutura da 2-3-4.				|  								
|  Será que ela é positiva, será que ela é negativa...		|
|  Será que ela é otimista, será que é pessimista...		|	
|								|							
|	Veja bem qual será mais fácil...			|			
|	Veja bem qual será possível...				|			
|								|							
|	Às vezes prevenir os erros ANTES facilita a vida.	|	
|								|							




------------------------------

**Informacoes aleatorias:**
- Por que registro.lol? Porque na steam so' tem dota.
- Carlos Eduardo possui nomes muito interessantes em sua familia. 
