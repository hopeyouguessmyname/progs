#include <string>

#include "I_Notebook.h"
#include "Notebook_v2.h"

class NotebookAdapter : public I_Notebook, public I_Notebook_v2
{
	  static Notebook_v2 *notebook;

	public:
    void createNote(std::string title, std::string note);
    std::string getNote(std::string title);
    std::string removeNote(std::string title);
    std::string notesCatalog();
    void createNote(std::string title, std::string note, std::string recipient);
    std::string noteList();
};

