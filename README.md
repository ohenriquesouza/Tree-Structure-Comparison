# Tree Structure Comparison 🌲

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/ohenriquesouza">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
</a> 
</div>

</hr>

# OBJETIVOS
<div align="justify">

<p>Foi proposto pelo professor Michel Pires na disciplina de Algorítmo e Estrutura de Dados II, um trabalho no qual o objetivo era comparar todas as estruturas de <i>Árvores</i> apresentadas até a data de hoje, além disso, também deveriam entrar na comparação outros tipos de estruturas como: <i>Map</i>, <i>Unordered Map</i> e <i>Vector</i>.</p>

<p>Sendo assim, após a conclusão do projeto, temos aqui um algorítmo capaz de:</br>
<b>- [✔️] Ler números decimais de um arquivo externo;</br></b>
<b>- [✔️] Utilizar o <i>QuickSort</i> para ordenar o vector durante a inserção;</br></b>
<b>- [✔️] Comparar os tempos gastos a cada etapa do programa;</br></b>
<b>- [✔️] Funções como inserir, pesquisar, remover e ordenar (quando necessário) funcionando em todas as estruturas; </br></b></p>

<p>Após a apresentação do tema, bem como a demonstração da lógica, serão apresentados todos os resultados obtidos a partir dos testes feitos.</p>

# INTRODUÇÃO

<p><b>O que é uma árvore em programação?</b> Árvore é uma estrutura de dados que organiza seus elementos de forma hierárquica, onde existe um elemento que fica no topo da árvore, chamado de raiz e existem os elementos subordinados a ele, que são chamados de nós filhos. Cada nós filho pode conter zero, um ou mais de um nós filhos. Os nós filhos que não contém outros nós filhos são chamados de nós folha.</p>

<b>Características de uma Árvore</b>
<ul>
<li>Raiz: Toda arvore possui o nó raiz que é o nó inicial da árvore;</li>
<li>Grau: o número de filhos que um nó possui;</li>
<li>Nível (ou profundidade): a distância de um nó até a raiz;</li>
<li>Altura: o maior nível encontrado na árvore (altura de uma árvore com n nós pode variar de lg(n) até n-1);</li>
<li>Folha: o nó que não possui filho.</li>
</ul>

<p>A partir dessas características, foram a nos apresentadas três diferentes estruturas em Árvore: <i>Árvore de Pesquisa Binária</i>, <i>Árvore AVL</i> e <i>Árvore Red/Black</i>. Cada uma delas com suas características e peculiaridades, o que possibilita realizar a comparação entre elas e concluir com êxito o objetivo do trabalho.</p>

</hr>
<p><b>* IMPORTANTE * </b> É válido salientar que NENHUMA das estruturas de árvores aqui implementadas foram feitas pelo autor, com excessão da remoção na árvore red/black, que foi tirada do livro <i>Algortimos - Teoria e Prática, 3ª ed. nas páginas 274 e 275.</i> do autor Kenneth H. Rossen, todas as outras funções e lógicas foram arquitetadas pelo professor, apenas pequenas modificações foram feitas para o funcionamento ideal do progama. Caso deseje ler as funções originais, é possível acessá-las clicando <a href="https://github.com/mpiress"> aqui</a>.</p>
</hr>

# LÓGICA UTILIZADA

<h2>⚙️ Estruturas: </h2>

<p>Como já citado anteriormente, o objetivo principal do trabalho não era implementar as estrutras e sim realizar testes visando compara-las. Por conta disso, não extenderemos muito sobre as funções principais de cada árvore, uma vez que não foram feitas pelo autor.</p>

<p>Uma das poucas alterações que se mostraram necessárias durante a codificação, foi a necessidade de adotar a mesma estrutura mostrada no livro para a criação das árvores para que a remoção na red/black fosse concluida. No código disponibilizado para uso, durante a criação da árvore, era atribuido <i>NULL</i> ou <i>nullptr</i> (C++) para certificar de que seria criado apenas a raiz. Já no livro, usa-se a palavra <i>nill</i> que diz respeito aos filhos do nó receberem ponteiros nulos. No começo pareceu confuso, mas após ler o passo a passo mostrado no livro, torna-se fácil entender esse ponto. Por isso, a função padrão <code>CreateTree()</code>, para a red/black, foi substituida por uma <code>initializeTreeRB()</code> na qual iguala a nulo todos os possíveis elementos envoltos à raiz.</p>
</br>

<div align="center">
<img src="imgs/initializeTreeRB.png">ㅤ<br/>ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 1: Função <code>initializeTreeRB()</code> modificada.</i>
</div>

</br>
<p>No programa, não há nenhum tipo de menu, sendo assim, todas as estruturas irão rodar com todos os arquivos automaticamente. Caso o usuário deseje operar com apenas um dos arquivos, no <code>main()</code>, deve comentar adicionando " // " antes das linhas referentes aos arquivos que ele não deseja executar.</p>

<p>Todas as operações acontecem dentro de uma mesma função, a <code>leArquivos( TAM )</code>. Essa é a única função chamada no main do programa e, a cada chamada passa um tamanho TAM diferente, onde cada TAM representa um arquivo. Os arquivos dos quais o programa irá retirar os valores tem uma formatação padrão enquanto ao seus nomes. Para o ideal funcionamento do algoritmo, os arquivos devem ter como nome a seguinte estrutura: <code>(TAM)NumbersFile.txt</code> como mostra a figura 4.<br/>

<div align="center">
<img src="imgs/arquivosLEITURA.png">ㅤ<br/>ㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 2: Estrutura padrão para os nomes dos arquivos.</i>
</div>

<br/>
<p>Caso o usuário deseje adicionar um novo arquivo para testes, deve serguir esse formato, além de garantir que todos os valores presentes dentro do arquivo sejam "flutuantes" com até 6 casas decimais.</p>

<p>Na figura 2 é possível perceber que tem um arquivo que foge dos padrões e recebe o nome de <code>entrada.txt</code>. Esse arquivo é onde estão armazenados os valores aos quais, após a inserção, serão pesquisados dentro das estruturas. Com isso, caso o usuário deseje altera-los, basta inserir um novo arquivo de entrada para pesquisa, mas mantendo o nome <code>entrada.txt</code> para que não seja necessário mudar nada nas funções de leitura.</p>

<p>A leitura dos arquivos acontece de forma padrão, a qual já foi citada várias vezes em fórums e outros READMEs. Utilizando a bilbioteca <code>< fstream ></code> e sua função <code>is_open()</code> seguida de um <code>while</code> que roda até que o arquivo chegue ao fim, cada linha lida é capturada com o <code>getline()</code>, armazenada em uma <code>string LINHA</code> que com o auxílio da função <code>stof()</code> é converitda para valor "flutuante" e associada a variável <code>float AUX</code>. Por fim, esse valor agora float, é inserido nas estruturas.</p>

<div align="center">
<img src="imgs/exemploinsert.png"> <br/>ㅤㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 3: Exemplo de como a inserção é feita/chamada.</i>
</div>

<br/>
<p>Exatamente este mesmo passo a passo é usado para todas as demais estruturas de dados, com excessão do Vector que, como pedido pelo professor, a pesquisa deveria ser feita a partir do método de pesquisa binária. Por isso, um tempo a mais é necessário para que ele seja ordenado, uma vez que apenas é possível realizar busca binária em estruturas ordenadas. Para tal, foi implementado um <i>QuickSort</i> que mostrou desempenho muito bom durante a ordenação, mas isso será discutido daqui a pouco.</p>

<p>Na verdade, essa estrutura mostrada na figura 3 é usada para todos os metodos em todas as estruturas de dados, com alteração, é claro da função chamada (insert, serach e remove), sendo assim, qualquer possível manutenção no código ou alteração por parte do usuário seria de extrema tranquilidade, uma vez que, tudo segue exatamente o mesmo padrão.</p>

<p>É importante citar que: para os métodos de pesquisa e remoção na estrutra Vector, utilizou-se de funções muito interessantes, próprias da linguagem C++. As funções em questão foram: <code>binary_search()</code> e a <code>lower_bound()</code> (ambos referenciadas no final do arquivo). A função <code>binary_search()</code>, como indica o nome, realiza uma busca binária no vector (que já deve estar ordenado) e retorna <i>true</i> ou <i>false</i>, caso encontre o número desejado ou não, respectivamente. A <code>lower_bound()</code> por sua vez, realiza uma busca linear. Essa função foi utilizada na parte de remoçao do valor de dentro da estrutura. Devido a eficiência da pesquisa binária, proporcionada pela função, o vector apresenta um tempo de pesquisa bem satisfatório, tempo esse que sofre uma certa defasagem na parte da remoção, uma vez que utiiza também a <code>lower_bound()</code>, que realiza busca linear, o que explica a diferença de tempo.</p>

<h2>🕗 Tempo: </h2>

<p>Para coletar o tempo gasto para cada interação nas diferentes estruturas, utilizou-se a biblioteca <code>< chrono ></code>, bem como o <code>namespasce chrono</code>. Inicialmente, tentou-se utilziar a biblioteca <code>< time.h ></code>, porém, a mesma mostrou desempenho duvidoso enquanto rodando no Windows 10 em um WSL de Ubuntu. Por conta disso, seus resultados não compatíveis trouxeram a necessiade de uma nova bilbioteca que tivesse haver com tempo de execução. A Chrono, por sua vez, mostrou-se eficiente mesmo no Win10, exibindo resultados compatíveis e bastante precisos. Sua implementação não é tão simples quanto a da outro bilbioteca, porém não é nada muito complexo também!</p>

<div align="center">
<img src="imgs/iniciaTempo.svg">ㅤㅤㅤㅤㅤㅤㅤ
<center><i>Figura 4: Inicialização/declaração necessárias da bib. Chrono.</i></center>
</div>

<br/>
<p>Perceba que é atribuido como valor para cada variável a função <code>(t1 - t1)</code>, que nada mais serve para zera-las, evitando lixo de memória e tempos sobrepostos. Provavelmente exista algum método próprio para isso, ou um jeito mais inteligente de se fazer. Este está funcionando, e foi o pensado na hora, por tanto, está ótimo!.</p>

# RESULTADOS E ANÁLISE

<p>Antes de qualquer análise, é importante lembrar que os testes apresentarão resultados diferentes para diferentes máquinas que rodarem o programa. Como diz a intuição, máquinas mais potentes, apresentarão resultados melhores. O computador no qual foi rodado todos os testes que verão abaixo possui as seguintes configurações: Processador Intel i7 - 4790K, 16GB de memória RAM e GPU GTX 1050Ti 4GB VRAM.</p>

<p>Após terminar todo o projeto, realizou-se diversos testes (mais especificadamente 3 testes para cada tamanho de arquivo), e tirou-se a média de tempo que cada estrutura gastou para realizar determinada ação. É importante lembrar que para a função <code>Search</code>, utilizou-se como padrão o arquivo "entrada.txt", o qual carregava consigo 10.000 valores flutuantes que seriam pesquisados em cada estrutura. Desses dez mil arquivos, alguns deles (60%) propositalmente foram inseridos sabendo que os mesmos <b>NÃO</b> existem em nenhuma das entradas, enquanto os outros 40%, são valores que existem nos arquivos, por tanto, estarão dentro das estruturas, se tudo tiver ocorrido be. Os resultados obtidos estão na grandeza dos segundos, e podem ser visualizados abaixo.</p>

| Entrada: 500           |  Insert                            |  Search      | Remove     | Total      |
| -----------------------| -----------------------------------|--------------|------------|------------|
|  <i>"APB"</i>           | 0,0004435  s                      |0,0067838 s   |0,0069817 s |0,014209 s |
|  <i>"AVL"</i>           | 0,0004673  s                      |0,0069382  s  |0,0068141 s |0,0142196 s |
|  <i>"ARB"</i>           | 0,0004237  s                      |0,0069413 s   |0,0065474 s |0,0139124 s |
|  <i>"MAP"</i>           | 0,0005779  s                      |0,0085797 s   |0,0088016 s |0,0179592 s |
|  <i>"U_MAP"</i>         | 0,0005482  s                      |0,0081461 s   |0,0085326 s |0,0172269 s |
|  <i>"VECTOR"</i>        | 0,0004403  s                      |0,0087349 s   |0,0086568 s |0,017832 s |
</hr>

| Entrada: 5000          |  Insert                            |  Search      | Remove     | Total      |
| -----------------------| -----------------------------------|--------------|------------|------------|
|  <i>"APB"</i>          | 0,0063266  s                       |0,0081169 s   |0,0070201 s |0,0214636 s |
|  <i>"AVL"</i>          | 0,00678464  s                       |0,00792  s   |0,0067796 s |0,02148424 s |
|  <i>"ARB"</i>          | 0,005797  s                       |0,0084535 s   |0,0070869 s  |0,0213374 s |
|  <i>"MAP"</i>          | 0,0078614  s                       |0,0106417 s   |0,0102997 s |0,0288028 s |
|  <i>"U_MAP"</i>        | 0,0070108  s                       |0,009399 s   |0,0100015 s  |0,0264113 s |
|  <i>"VECTOR"</i>       | 0,0052704  s                       |0,0108431 s   |0,0102378 s |0,0263513 s |
</hr>

| Entrada: 50000         |  Insert                            |  Search      | Remove     | Total      |
| -----------------------| -----------------------------------|--------------|------------|------------|
|  <i>"APB"</i>          | 0,0749651  s                       |0,0071846 s   |0,006959 s  |0,0891087 s |
|  <i>"AVL"</i>          | 0,0773283   s                       |0,0074415  s |0,0069605 s |0,0917303 s |
|  <i>"ARB"</i>          | 0,0594196  s                       |0,0074063 s   |0,0070156 s |0,0738415 s |
|  <i>"MAP"</i>          | 0,0836889  s                       |0,0101239 s   |0,0133071 s |0,1071199 s |
|  <i>"U_MAP"</i>        | 0,0751497  s                       |0,0080505 s   |0,0105195 s |0,0937197 s |
|  <i>"VECTOR"</i>       | 0,0515952  s                       |0,0105806 s   |0,0162057 s |0,0783815 s |
</hr>

| Entrada: 500000        |  Insert                            |  Search      | Remove     | Total      |
| -----------------------| -----------------------------------|--------------|------------|------------|
|  <i>"APB"</i>          | 0,864255  s                        |0,0071688 s   |0,0069133 s |0,8783371 s |
|  <i>"AVL"</i>          | 0,838687  s                        |0,0073495  s  |0,0069745 s |0,853011 s |
|  <i>"ARB"</i>          | 0,643372  s                        |0,0075557 s   |0,0068262 s |0,6577539 s |
|  <i>"MAP"</i>          | 0,88168  s                         |0,0106540 s   |0,0159773 s |0,9083113 s |
|  <i>"U_MAP"</i>        | 0,722394   s                       |0,0079768 s   |0,0109511 s |0,7413219 s |
|  <i>"VECTOR"</i>       | 0,5242  s                          |0,0113803 s   |0,0964162 s |0,6319965 s |
</hr>

	
| Legenda                |  Significado                                                                                      |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  "APB"                 |Árvore de Busca Binária                                                                            |
|  "AVL"                 | Árvore AVL (Adelson Velsky e Landis)                                                              |               
|  "ARB"                 | Árvore Red/Black                                                                                  |
|  "MAP"                 | Mapa (C++)                                                                                        |
|  "U_MAP"               | Mapa Desordenado (C++)                                                                            |
|  "VECTOR"              | Vector (C++)                                                                                      |

<p>Ao analisar os resultados, fica claro a discrepância quanto a eficiência da árvore Red/Black com as demais árvores. Quanto mais o tamanho dos arquivos aumentam para cada função (insert, search, remove), mais as árvores Binária de Busca e AVL se mostram menos eficientes. Os gráficos a seguir plotam exatamente essa relação [Tempo <b>x</b> Tamanho].</p>

<p float="left">
<img src="imgs/500g.png" width="49%"/>
<img src="imgs/5000g.png" width="49%"/>
<center><i>Figuras 5 e 6: Gráfico relacionando o tempo de execução <b>(em segundos)</b> com o tamanho do arquivo, para cada estrutura.</i></center>
</p>

<br/>

<p float="left">
<img src="imgs/50000g.png" width="49%"/>
<img src="imgs/500000g.png" width="49%"/>
<center><i>Figuras 7 e 8: Gráfico relacionando o tempo de execução <b>(em segundos)</b> com o tamanho do arquivo, para cada estrutura.</i></cener>
</p>

<br/>

<p>É importante lembrar que, o eixo <i>Y</i> está na grandeza de segundos, por tanto, para converter em minutos, deve se dividir o valor por 60. Analisando os gráficos, chega a ser engraçada a tamanha ineficiência das duas árvores APB e AVL, uma vez que os valores computados pelas outras estruturas são tão inferiores, que chegam a ser insignificantes ao se observar.</p>

<h2>📈 Conclusões: </h2>

<p>Como citado no começo do texto, uma coisa que chama a atenção ao analisar os dados, é a excelente eficiência da ordenação <i>QuickSort</i>, que permitiu com que o vector, mesmo sendo "defasado" por precisar ser ordenado, conseguisse concluir a carga de testes com um tempo parcialmente satisfatório. Entretanto, vale dizer que esse tempo relativamente baixo não se dá pela estrutura em sí do Vector e sim pela eficiência do algorítmo Sort. Antes de implementar o QuickSort, utilizou-se apenas para fins comparativos, a ordenação BubbleSort. Com ela, a inserção/ordenação de 5.000 entradas levava em torno de 30 - 33 minutos, valor este que se reduziu a uma fração de segundos com o quick. Para a entrada de 500.000 então... o bubble sort apresentou comportamento deplorável, simplesmente não conseguindo concluir a inserção ordenada, nunca (O algoritmo ficou rodando por mais de 5 horas). Com isso, pode-se concluir sobre o vector que: Para valores de entrada grandes, é essencial o uso de um bom algorítmo de ordenação e ainda assim, apresentará resultados inferiores quando comparadas ás árvores. Caso não seja possível implementar um bom algorítmo de busca, exclua essa estrutura da sua lista de opções, será horrível.</p>

<p>Sobre os dois tipos de Mapas disponibilizados pelo C++, é possível dizer que em não, eles não apresentam ganhos em relação a tempo de execução quando comparados ás estruturas árvores. Apesar de ambos apresentarem desempenho relativamente satisfatório, em todos os testes eles ficaram atrás das árvores testadas. Devido a simplicidade de implementar essas estruturas e o tempo de execução coerente, conclui-se que: apesar de não serem tão rápidos computacionalmente quanto ás árvores, são sim boas opções para operar com certos volumes de entradas.</p>

<p>A rainha das estruturas nesses testes que foram realizados, com certeza foi a Árvore Red/Black. Apresentando desempenho muito superior ao esperado (uma vez que possui umas das implementações mais complicadas das estruturas analisadas, principalmente para remover valores), ela chegou como forte candidata ao título de melhor estrutura de dados para as funções analisadas, porém, sua difícil implementação com certeza a faz perder pontos neste ranking, uma vez que, as outras árvores aqui testadas (que não possuem uma implementação tão trabalhosa) também apresetaram um bom desempenho. Apesar disso, é possível perceber que tanto a APB, quanto a AVL perdem desempenho quando o volume de entrada aumenta consideravelmente.</p>

<p>Em síntese, conclui-se que cada estrutura tem vantagens e desvantagens, como já era de se esperar. Analisando todos os valores obtidos pelas estruturas e as horas gastas se dedicando a cada uma delas, o resultado foi o seguinte.</p>

<ul>
<li>🥇<b>Árvore Red/Black</b>;</li>
<li>🥈<b>Árvore AVL</b>;</li>
<li>🥉<b>Árvore APB</b>;</li>
<li>🎖️<b>Mapas (C++)</b>;</li>
<li>😒<b>Vector</b>;</li>
</ul>

<p>Por fim, todas as estruturas foram capazes de finalizar e objetivar o trabalho. Apesar disso, não foram todas que apresentaram bom desempenho ao final. A escolha de determinada estrutura de dados não depende apenas do quanto ela se mostra eficiente. Cada tipo de problema pode exigir e se mostrar mais simples a partir de certa estrutura. Conclui-se então que, para os testes feitos, a Árvore Red/Black, apesar de possuir difícil implementação, teve melhor o melhor desempenho de todas as estruturas, obtendo tempos excelentes. Como consideração final, vale dizer que, mesmo perdendo nas comparações de tempo, o Unordered_Map (C++) se mostrou ser relativamente prático e bom. Precisando de praticamente uma única linha para gerar sua implementação, talvez (dependendo do problema), a diferença de tempo não seja um obstáculo que deva te impedir de usá-lo.</p>

# COMPILAÇÃO E EXECUÇÃO

A algorítmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make r`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build, além de em seguida executar o programa da pasta build após a realização da compilação             |

# BIBLIOTECAS 
Para o funcionamento desejado, é necessário incluir as seguintes bibliotecas no programa:<br/>

<ul>
	<li><code>#include 'iostream'  </code></li>
	<li><code>#include 'map'</code></li>
	<li><code>#include 'unordered_map'</code></li>
	<li><code>#include 'bits/stdc++.h'</code></li>
	<li><code>#include 'string'</code></li>
	<li><code>#include 'ctime'</code></li>
	<li><code>#include 'ratio'</code></li>
	<li><code>#include 'fstream'</code></li>
	<li><code>#include 'vector'</code></li>
	<li><code>#include 'algorithm'</code></li>
    <li><code>#include 'chrono'</code></li>
    <li><code>#include 'stdlib.h'</code></li>
    <li><code>#include 'stdbool.h'</code></li>
</ul>

<hr/>

# REFERÊNCIAS

<ul>
	<li>https://sites.google.com/site/proffdesiqueiraed/aulas/aula-10---arvores</li>
	<li>https://blog.pantuza.com/artigos/o-algoritmo-de-ordenacao-quicksort</li>
	<li>https://github.com/mpiress</li>
	<li>https://www.geeksforgeeks.org/quick-sort/</li>
	<li>https://cplusplus.com/reference/algorithm/binary_search/</li>
	<li><b>ROSEN, Kenneth</b>. Matemática Discreta e Suas Aplicações 6ª Ed. São Paulo: McGraw-Hill Interamericana do Brasil Ltda. 2009.</li>
	<li><b>CORMEN, Thomas</b>. Algoritmos - Teoria e Prática 3º Ed. São Paulo: ELSEVIER ISBN13, 2012.</li>
</ul>

</div>

# AUTOR
Criado por Henrique Souza Fagundes;

Aluno do 4° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
