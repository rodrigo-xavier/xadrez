####################################### Diretórios #########################################
# Aqui estão listados os diretórios do projeto

# Nomes dos executáveis
PROJECT_EXE = ../Project
TEST_EXE = ../Test

# Nomes dos diretórios
DIR_HEADERS = ../include
DIR_SOURCES = ../src
DIR_OBJECTS = ../obj
DIR_TESTS = ../tests
DIR_GCOV = ../docs/gcov



########################################## FLAGS ###########################################
# Especifica o compilador, a versão do C++ e as flags utilizadas para compilar o código

CC = g++ -std=c++11
CFLAGS = -I$(DIR_HEADERS) -ftest-coverage -fprofile-arcs
LIBS = -lm -lSDL2 -lSDL2_image

# Flags que vou precisar para o SDL (o usuário terá que instalar esses 4 pacotes)
# Descomentar quando interface tiver pronta
#LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer



########################## Listas com nomes dos arquivos de código ##########################
# Define o local dos arquivos de código e arquivos de cabeçalho de código

_HEADERS = Piece.hpp Board.hpp Pawn.hpp Knight.hpp Bishop.hpp Rook.hpp Queen.hpp King.hpp States.hpp Texture.hpp Button.hpp Graphics.hpp GameState.hpp GUIBoard.hpp
HEADERS = $(patsubst %,$(DIR_HEADERS)/%,$(_HEADERS))

_OBJECTS = main.o Piece.o Board.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o States.o Texture.o Button.o Graphics.o GameState.o GUIBoard.o
OBJECTS = $(patsubst %,$(DIR_OBJECTS)/%,$(_OBJECTS))

_TESTS = Test_Main.cpp
TESTS = $(patsubst %,$(DIR_TESTS)/%,$(_TESTS))



############################################ Make ############################################
# Aqui são definidas as regras para compilar o código gerando arquivos objetos e binários

# Gera arquivos objeto para todos os .cpp que estão localizados no mesmo diretório do makefile e em seguida compila
$(DIR_OBJECTS)/%.o: %.cpp $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Chama todos os arquivos objeto, gerando binários e criando o executável
$(PROJECT_EXE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Chama todos os arquivos objeto, gerando binários e criando o executável de teste, colocar aqui todos os módulos usados no teste
$(TEST_EXE): $(TESTS) Board.cpp Piece.cpp Pawn.cpp Knight.cpp Bishop.cpp Rook.cpp Queen.cpp King.cpp States.cpp
	$(CC) -o $@ --coverage $^ $(CFLAGS)

# MiniTutorial
# all: library.cpp main.cpp
# $@ - Chama o nome da regra 			- all
# $< - Chama o primeiro pré-requisito 	- libray.cpp
# $^ - Chama todos os pré-requisitos 	- library.cpp main.cpp



################################## Outras Regras de Make ####################################
# Aqui estão listadas algumas regras úteis de make para facilitar o trabalho

# make project
# Limpa a tela e executa automaticamente o software
project:
	clear
	./$(PROJECT_EXE)

# make test
# Chama a regra que compila o teste, depois move o arquivo residual .gcno de src para obj
test: $(TEST_EXE)
	mv $(DIR_SOURCES)/*.gcno $(DIR_OBJECTS)

# make gcov
# executa o teste, move o .gcno de obj para src, gera o gcov e em seguida move todos os arquivos .gcno e .gcda de src para obj
gcov:
	./$(TEST_EXE)

	mv $(DIR_OBJECTS)/*.gcno $(DIR_SOURCES)

	gcov -n *.gcda > $(DIR_GCOV)/relatorio-gcov.txt
	cat $(DIR_GCOV)/relatorio-gcov.txt

	mv $(DIR_SOURCES)/*.gcno $(DIR_OBJECTS)
	mv $(DIR_SOURCES)/*.gcda $(DIR_OBJECTS)

# make all
# Chama todas as regras de make
all: $(PROJECT_EXE) test gcov project



########################################## Clean ###########################################
# Deleta alguns arquivos do projeto (binários, objetos, gcov e gcda)

.PHONY: clean gcov

# make clean

clean:
	rm -f $(DIR_OBJECTS)/*.o *~ core $(INCDIR)/*~ *.gcda *.gcno *.gcov *.o ../obj/*.gcno ../obj/*.gcda $(PROJECT_EXE) $(DIR_OBJECTS)/*. $(TEST_EXE)
