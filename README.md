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
<li>Altura: o maior nível encontrado na árvore (altura de uma árvore com n nós pode variar de lg(n) até n-1;</li>
<li>Folha: o nó que não possui filho.</li>
</ul>

<p>A partir dessas características, foram a nos apresentadas três diferentes estruturas em Árvore: <i>Árvore de Pesquisa Binária</i>, <i>Árvore AVL</i> e <i>Árvore Red/Black</i>. Cada uma delas com suas características e peculiaridades, o que possibilita realizar a comparação entre elas e concluir com êxito o objetivo do trabalho.</p>

</hr>
<p><b>* IMPORTANTE * </b> É válido salientar que NENHUMA das estruturas de árvores aqui implementadas foram feitas pelo autor, com excessão da remoção na árvore red/black, que foi tirada do livro <i>Matemática Discreta e Suas Aplicações 6ª ed.</i> do autor Kenneth H. Rossen, todas as outras funções e lógicas foram arquitetadas pelo professor, apenas pequenas modificações foram feitas para o funcionamento ideal do progama. Caso deseje ler as funções originais, é possível acessá-las clicando <a href="https://github.com/mpiress"> aqui</a>.</p>
</hr>

# LÓGICA UTILIZADA

<h2>⚙️ Estruturas: </h2>

<p>Como já citado anteriormente, o objetivo principal do trabalho não era implementar as estrutras e sim realizar testes visando compara-las. Por conta disso, não extenderemos muito sobre as funções principais de cada árvore, uma vez que não foram feitas pelo autor.</p>

<p>Uma das poucas alterações que se mostraram necessárias durante a codificação, foi a necessidade de adotar a mesma estrutura mostrada no livro para a criação das árvores para que a remoção na red/black fosse concluida. No código disponibilizado para uso, durante a criação da árvore, era atribuido <i>NULL</i> ou <i>nullptr</i> (C++) para certificar de que seria criado apenas a raiz. Já no livro, usa-se a palavra <i>nill</i> que diz respeito aos filhos do nó receberem ponteiros nulos. No começo pareceu confuso, mas após ler o passo a passo mostrado no livro, torna-se fácil entender esse ponto. Por isso, a função padrão <code>CreateTree()</code>, para a red/black, foi substituida por uma <code>initializeTreeRB()</code> na qual iguala a nulo todos os possíveis elementos envoltos à raiz.</p>
</br>

<div align="center">
<img src="imgs/initializeTreeRB.svg">ㅤ<br/>ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 1: Função <code>initializeTreeRB()</code> modificada.</i>
</div>

</br>
<p>No programa, não há nenhum tipo de menu, sendo assim, todas as estruturas irão rodar com todos os arquivos automaticamente. Caso o usuário deseje operar com apenas um dos arquivos, no <code>main()</code>, deve comentar adicionando " // " antes das linhas referentes aos arquivos que ele não deseja executar.</p>

<p>Todas as operações acontecem dentro de uma mesma função, a <code>leArquivos( TAM )</code>. Essa é a única função chamada no main do programa e, a cada chamada passa um tamanho TAM diferente, onde cada TAM representa um arquivo. Os arquivos dos quais o programa irá retirar os valores tem uma formatação padrão enquanto ao seus nomes. Para o ideal funcionamento do algoritmo, os arquivos devem ter como nome a seguinte estruura: <code>(TAM)NumbersFile.txt</code> como mostra a figura 2.

<div align="center">
<img src="imgs/arquivosLEITURA.png">ㅤ<br/>ㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 2: Estrutura padrão para os nomes dos arquivos.</i>
</div>

<p>Caso o usuário deseje adicionar um novo arquivo para testes, deve serguir esse formato, além de garantir que todos os valores presentes dentro do arquivo sejam "flutuantes" com até 6 casas decimais.</p>

<p>Na figura 2 é possível perceber que tem um arquivo que foge dos padrões e recebe o nome de <code>entrada.txt</code>. Esse arquivo é onde estão armazenados os valores aos quais, após a inserção, serão pesquisados dentro das estruturas. Com isso, caso o usuário deseje altera-los, basta inserir um novo arquivo de entrada para pesquisa, mas mantendo o nome <code>entrada.txt</code> para que não seja necessário mudar nada nas funções de leitura.</p>

<p>A leitura dos arquivos acontece de forma padrão, a qual já foi citada várias vezes em fórums e outros READMEs. Utilizando a bilbioteca <code>< fstream ></code> e sua função <code>is_open()</code> seguida de um <code>while</code> que roda até que o arquivo chegue ao fim, cada linha lida é capturada com o <code>getline()</code>, armazenada em uma <code>string LINHA</code> que com o auxílio da função <code>stof()</code> é converitda para valor "flutuante" e associada a variável <code>float AUX</code>. Por fim, esse valor agora float, é inserido nas estruturas.</p>

<div align="center">
<img src="imgs/insercaoEXEMPLO
.png">ㅤㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 3: Exemplo de como a inserção é feita/chamada.</i>
</div>

<p>Exatamente este mesmo passo a passo é usado para todas as demais estruturas de dados, com excessão do Vector que, como pedido pelo professor, a pesquisa deveria ser feita a partir do método de pesquisa binária. Por isso, um tempo a mais é necessário para que ele seja ordenado, uma vez que apenas é possível realizar busca binária em estruturas ordenadas. Para tal, foi implementado um <i>QuickSort</i> que mostrou desempenho incível durante a ordenação, mas isso será discutido daqui a pouco.</p>

<p>Na verdade, essa estrutura mostrada na figura 3 é usada para todos os metodos em todas as estruturas de dados, com alteração, é claro da função chamada (insert, serach e remove), sendo assim, qualquer possível manutenção no código ou alteração por parte do usuário seria de extrema tranquilidade, uma vez que, tudo segue o exato mesmo padrão.</p>

<h2>🕗 Tempo: </h2>

<p>Para coletar o tempo gasto para cada interação nas diferentes estruturas, utilizou-se a biblioteca <code>< chrono ></code>, bem como o <code>namespasce chrono</code>. Inicialmente, tentou-se utilziar a biblioteca <code>< time.h ></code>, porém, a mesma mostrou desempenho duvidoso enquanto rodando no Windows 10 em um WSL de Ubuntu. Por conta disso, seus resultados não compatíveis trouxeram a necessiade de uma nova bilbioteca que tivesse haver com tempo de execução. A Chrono, por sua vez, mostrou-se eficiente mesmo no Win10, exibindo resultados compatíveis e bastante precisos. Sua implementação não é tão simples quanto a da outro bilbioteca, porém não é nada muito complexo também!</p>

<div align="center">
<img src="imgs/iniciaTempo.png">ㅤㅤㅤㅤㅤㅤㅤ
<i>Figura 4: Inicialização/declaração necessárias da bib. Chrono..</i>
</div>

<p>Perceba que é atribuido como valor para cada variável a função <code>(t1 - t1)</code>, que nada mais serve para zera-las, evitando lixo de memória e tempos sobrepostos. Provavelmente exista algum método próprio para isso, ou um jeito mais inteligente de se fazer. Este está funcionando, e foi o pensado na hora, por tanto, está ótimo!.</p>