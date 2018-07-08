# Xadrez
Implementação do jogo de xadrez para a disciplina Métodos de Programação

**Regras do pull request**

* Atualize sua master local
* Faça merge da sua branch com a master
* Corrija os conflitos e deixe funcional
* Faça make clean
* Abra o pull request

**Tarefas:**
	
*	Cada um dos membros do grupo deve criar uma branch Com seu nome e nome da sua tarefa
*	Anotar todas as suas Contribuições em um relatório localizado em Documentation/Relatório Individual/
*	Criar a classe peça e fazer com que as peças do xadrez herdem dela
*	Talvez seja necessário criar uma classe para o movimento realizado
*	Criar uma classe para o tabuleiro
*	Designar alguém para implementar a interface vulgo Paulo Mito
*	ATENÇÃO: O makefile deve sempre estar funcional

**Os arquivos estão organizados da seguinte forma:**

*	docs -> Contém os arquivos de documentação gerados pelo doxygen (Latex e Html) e os relatórios individuais de cada membro do grupo
*	include-> Contém os arquivos de cabeçalho do código como (.hpp)
*	obj-> Contém os objetos e arquivos gcov gerados pelo makefile
*	src-> Contém os métodos das classes dos arquivos de cabeçalho, a main e o makefile
*   tests-> Aqui estão localizados os testes 

-----------

**Ambiente e Execução**

**Requirements:**
	
	Ubuntu version: 18:04
	C++ version: 11
	gcc version: 7.3.0
	make version: 4.1
    sdl2-dev
    sdl2-image-dev
    sdl2-ttf-dev
	*	Caso necessário, instale os pacotes utilizando "sudo apt-get install make" e "sudo apt-get install g++"

**Para compilar e executar:**
	
*	Acesse o diretório "Sources", digite "make all" no terminal e o arquivo "Project" será gerado na estrutura principal do projeto e executado automaticamente gerando relatórios de teste em seguida. 
*	Para executar digite "make project". (Executar direto o ./Project ainda não está funcionando)

**Comandos makefile:**
	
	make		 -	Compila o Projeto
	make project -	Executa o projeto
	make gcov	 -	Gera arquivos gcov para testes
	make clean	 -	Apaga arquivos objeto, binários, gcov e outros
	make all	 -	Compila, executa e gera Arquivos Gcov

-----------

**Links**

**Links do Professor**

	Tutorial:             https://guides.github.com/activities/hello-world/
	Biblioteca ncurses:   http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html
	Biblioteca SDL:       https://www.libsdl.org/
	PlayCB:               http://pt-br.playcb.wikia.com/wiki/Wikia_PlayCB
	QT:                   https://www.qt.io/ 

**Curso C++**

	Este é o melhor curso de C++ que vocês vão encontrar
	https://goo.gl/pbwEiV

**Tutorial do Paulo de SDL**

	http://lazyfoo.net/tutorials/SDL/index.php

**Xadrez**

	https://github.com/nolderosw/xdgp
	https://github.com/LuisCoder/Xadrez
