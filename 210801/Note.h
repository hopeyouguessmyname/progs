#include <string>

class Note
{
    std::string title;
    std::string note;
    std::string recipient;

  public:
    Note(std::string title, std::string note);
    Note(std::string title, std::string note, std::string recipient);
	
    std::string getRecipient();
    std::string getTitle();
    std::string getNote();
};

