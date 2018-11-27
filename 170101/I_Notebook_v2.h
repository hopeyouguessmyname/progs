#include <string>

class I_Notebook_v2
{
	virtual void createNote(std::string title, std::string note, std::string recipient)=0;
	virtual std::string getNote(std::string title)=0;
	virtual std::string removeNote(std::string title)=0;
	virtual std::string noteList()=0;
};
