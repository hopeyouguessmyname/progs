#include <string>

class I_Notebook
{
	virtual void createNote(std::string title, std::string note)=0;
	virtual std::string getNote(std::string title)=0;
	virtual std::string removeNote(std::string title)=0;
	virtual std::string notesCatalog()=0;
};
