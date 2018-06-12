# Especifica os Diretórios
DIR_SOURCES = ../Sources
DIR_OBJECTS = ../Objects
DIR_HEADERS = ../Headers
DIR_PROJECT = ../Project

# Especifica o compilador, a versão do C++ utilizado e as flags
CC = g++ -std=c++11
CFLAGS = -I$(DIR_HEADERS) -Wall -ftest-coverage -fprofile-arcs 
LIBS = -lm 

# Define o local de cada tipo de arquivo
_HEADERS = Piece.hpp Test_Piece.hpp
HEADERS = $(patsubst %,$(DIR_HEADERS)/%,$(_HEADERS))

_OBJ = main.o Piece.o Test_Piece.o
OBJ = $(patsubst %,$(DIR_OBJECTS)/%,$(_OBJ))

# Compila os arquivos de código fonte em arquivos de objeto
$(DIR_OBJECTS)/%.o: %.cpp $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

$(DIR_OBJECTS)/%.o: main.cpp $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

# Vincula os arquivos objetos em um binário
$(DIR_PROJECT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Chama todas as regras de make
all: $(DIR_PROJECT) project gcov

# Deleta alguns arquivos do projeto (binários, objetos, gcov e gcda)
.PHONY: clean

clean:
	rm -f $(DIR_SOURCES)/*.o *~ core $(INCDIR)/*~ *.gcda *.gcno *.gcov *.o $(DIR_PROJECT) obj/*.
	rm -f $(DIR_OBJECTS)/*.o
	rm -f $(DIR_OBJECTS)/*.gcno
	rm -f $(DIR_OBJECTS)/*.gcov
	rm -f $(DIR_OBJECTS)/*.gcda

# Move os arquivos da pasta objetos para a pasta onde reside o código do projeto,
# gera o gcov de alguns arquivos, e em seguida move de volta para a pasta Objetos
gcov:
	mv $(DIR_OBJECTS)/*.o $(DIR_SOURCES)
	mv $(DIR_OBJECTS)/*.gcno $(DIR_SOURCES)
	mv $(DIR_OBJECTS)/*.gcda $(DIR_SOURCES)

	gcov main.cpp
	gcov Piece.cpp
	gcov Test_Piece.cpp

	mv $(DIR_SOURCES)/*.o $(DIR_OBJECTS)
	mv $(DIR_SOURCES)/*.gcno $(DIR_OBJECTS)
	mv $(DIR_SOURCES)/*.gcov $(DIR_OBJECTS)
	mv $(DIR_SOURCES)/*.gcda $(DIR_OBJECTS)

# Limpa a tela e executa automaticamente o software
project:
	clear
	./$(DIR_PROJECT)