#include <string>
#include <vector>

#include "I_Notebook.h"
#include "Note.h"

class Notebook : public I_Notebook
{
	  std::vector<Note*> notesList;

	public:
    void createNote(std::string title, std::string note);
    std::string getNote(std::string title);
    std::string removeNote(std::string title);
    std::string notesCatalog();
};

