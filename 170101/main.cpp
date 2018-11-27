#include <iostream>

#include "NotebookAdapter.h"

int main()
{
		NotebookAdapter *notebookAdapter = new NotebookAdapter();
		notebookAdapter->createNote("Title 1", "First note");
		notebookAdapter->createNote("Title 2", "2 note");
		notebookAdapter->createNote("Title 3", "3 note");
		
		std::cout << notebookAdapter->notesCatalog() << std::endl;
		std::cout << "Notatka 2: " << notebookAdapter->getNote("Title 2") << "\n";
		notebookAdapter->removeNote("Title 3");
		notebookAdapter->createNote("Tytuł nowej notatki", "Notatka z odbiorcą", "Frodo");
		std::cout << notebookAdapter->notesCatalog() << std::endl;

  return 0;
}
