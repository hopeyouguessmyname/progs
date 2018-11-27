#include <string>
#include <iostream>

#include "NotebookAdapter.h"

Notebook_v2 *NotebookAdapter::notebook=NULL;

void NotebookAdapter::createNote(std::string title, std::string note)
{
  if(notebook == NULL)
    notebook = new Notebook_v2();
  notebook->createNote(title, note, ""); 
}
std::string NotebookAdapter::getNote(std::string title)
{ 
  return notebook->getNote(title); 
}
std::string NotebookAdapter::removeNote(std::string title){ return notebook->removeNote(title); }
std::string NotebookAdapter::notesCatalog(){ return notebook->noteList(); }
void NotebookAdapter::createNote(std::string title, std::string note, std::string recipient)
{
  notebook->createNote(title, note, recipient); 
}
std::string NotebookAdapter::noteList(){ return notebook->noteList(); }

