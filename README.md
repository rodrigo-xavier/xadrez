# Xadrez
Implementação do jogo de xadrez para a disciplina Métodos de Programação

**Tarefas:**
	Cada um dos membros do grupo deve criar uma branch.
	Anotar todas as suas Contribuições em um relatório localizado em Documentation/Relatório Individual/.

**Os arquivos estão organizados da seguinte forma:**

	Documentation -> Contém os arquivos de documentação gerados pelo doxygen (Latex e Html) e os relatórios individuais de cada membro do grupo
	Headers-> Contém os arquivos de cabeçalho do código como (.hpp)
	Log-> Contém o arquivo de log gerado pelo github utilizando (git log -p > log.txt)
	Objects-> Contém os objetos e arquivos gcov gerados pelo makefile
	Sources-> Contém os métodos das classes dos arquivos de cabeçalho, a main e o makefile

**Requirements:**
	Ubuntu version: 18:04
	C++ version: 11
	gcc version: 7.3.0
	make version: 4.1

	Caso necessário, instale os pacotes utilizando "sudo apt-get install make" e "sudo apt-get install g++"

**Para compilar e executar:**
	
	Acesse o diretório "Sources", digite "make all" no terminal e o arquivo "Project" será gerado na estrutura principal do projeto e executado automaticamente gerando relatórios de teste em seguida. 
	Para executar digite "./Project" ou "make project"

**Comandos makefile:**
	make		 -	Compila o Projeto
	make project -	Executa o projeto
	make gcov	 -	Gera arquivos gcov para testes
	make clean	 -	Apaga arquivos objeto, binários, gcov e outros
	make all	 -	Compila, executa e gera Arquivos Gcov

**Links Úteis:**

	Tutorial:             https://guides.github.com/activities/hello-world/
	Biblioteca ncurses:   http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html
	Biblioteca SDL:       https://www.libsdl.org/
	PlayCB:               http://pt-br.playcb.wikia.com/wiki/Wikia_PlayCB
	QT:                   https://www.qt.io/ 
