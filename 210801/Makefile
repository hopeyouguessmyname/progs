all: main

main: main.o Note.o Notebook_v2.o Notebook.o NotebookAdapter.o
	g++ main.o Note.o Notebook_v2.o Notebook.o NotebookAdapter.o -o main

main.o: main.cpp
	g++ -c main.cpp

Note.o: Note.cpp
	g++ -std=c++11 -c Note.cpp

Notebook_v2.o: Note.cpp
	g++ -c Notebook_v2.cpp

Notebook.o: Notebook.cpp
	g++ -c Notebook.cpp

NotebookAdapter.o: NotebookAdapter.cpp
	g++ -c NotebookAdapter.cpp

