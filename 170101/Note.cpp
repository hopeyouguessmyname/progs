#include <string>
#include <iostream>

#include "Note.h"


Note::Note(std::string title, std::string note)
{
  this->title = title;
  this->note = note;
}

Note::Note(std::string title, std::string note, std::string recipient) : Note(title, note)
{
	this->recipient = recipient;
}

std::string Note::getRecipient(){ return recipient;	}
std::string Note::getTitle(){ return title;	}
std::string Note::getNote(){ return note;	}

