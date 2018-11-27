#include <string>
#include <vector>
#include <iostream>

#include "Notebook.h"

void Notebook::createNote(std::string title, std::string note)
{
  notesList.push_back(new Note(title, note));
}


std::string Notebook::getNote(std::string title)
{
  for (std::vector<Note*>::iterator it = notesList.begin(); it != notesList.end(); it++)
	{
    if (!(*it)->getTitle().compare(title))
		{
			return (*it)->getNote();
		}
	}

	return "";
}


std::string Notebook::removeNote(std::string title)
{
  for (std::vector<Note*>::iterator it = notesList.begin(); it != notesList.end(); it++)
  {
    if (!(*it)->getTitle().compare(title))
    {
			std::string note = (*it)->getNote();
			notesList.erase(it);
			return note;      
    }
  }

	return "";
}


std::string Notebook::notesCatalog()
{
	std::string catalog;
		
	for (std::vector<Note*>::iterator it = notesList.begin(); it != notesList.end(); it++)
	{
		catalog.append("- ");
    catalog.append((*it)->getTitle());
    catalog.append("\n");
	}
		
	return catalog;
}

