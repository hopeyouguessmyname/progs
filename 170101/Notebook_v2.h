#include <string>
#include <vector>

#include "I_Notebook_v2.h"
#include "Note.h"

class Notebook_v2 : public I_Notebook_v2
{
	  std::vector<Note*> notesList;

	public: 
    void createNote(std::string title, std::string note, std::string recipient);
	  std::string getNote(std::string title);
    std::string removeNote(std::string title);
    std::string noteList();
};

