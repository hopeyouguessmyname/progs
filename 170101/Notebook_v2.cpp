#include <string>
#include <vector>
#include <iostream>

#include "Notebook_v2.h"

 
void Notebook_v2::createNote(std::string title, std::string note, std::string recipient)
{
	notesList.push_back(new Note(title, note, recipient));
}

std::string Notebook_v2::getNote(std::string title)
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

std::string Notebook_v2::removeNote(std::string title)
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

std::string Notebook_v2::noteList()
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

