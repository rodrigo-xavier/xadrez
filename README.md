# Xadrez
Implementação do jogo de xadrez para a disciplina Métodos de Programação

**Os arquivos estão organizados da seguinte forma:**

	Documentation -> Contém os arquivos de documentação gerados pelo doxygen (Latex e Html) e os relatórios individuais de cada membro do grupo
	Headers-> Contém os arquivos de cabeçalho do código como (.hpp)
	Log-> Contém o arquivo de log gerado pelo github utilizando (git log -p > log.txt)
	Objects-> Contém os objetos e arquivos gcov gerados pelo makefile
	Sources-> Contém os métodos das classes dos arquivos de cabeçalho, a main e o makefile

**Para compilar o código:**

	No ubuntu: 
	
	Basta apenas acessar o diretório "Sources" pelo terminal e digitar "make all" e o arquivo "Project" será gerado e executado automaticamente. 
	Para gerar os arquivos gcov, acesse o diretório "Sources" pelo terminal e digite "make gcov" e os arquivos serão gerados na pasta Objects.
	Para executar digite "./Project" ou "make project"

**Links Úteis:**

Tutorial:             https://guides.github.com/activities/hello-world/

Biblioteca ncurses:   http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html

Biblioteca SDL:       https://www.libsdl.org/

PlayCB:               http://pt-br.playcb.wikia.com/wiki/Wikia_PlayCB

QT:                   https://www.qt.io/ 
