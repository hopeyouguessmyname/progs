// factory method
#include <iostream>

enum FileType{ JPG_FILE, TXT_FILE, EXE_FILE };

class File
{
    std::string fileName;

  public:
    virtual ~File() = 0;
    virtual void setFileName(std::string p_fileName) { fileName = p_fileName; }
    virtual void printFileName() { std::cout << fileName << std::endl; }
};

File::~File(){}

class JPGFile : public File{  };
class TXTFile : public File{  };
class EXEFile : public File{  };


class FileCreator
{
  public:
    virtual ~FileCreator() = 0;
    virtual File *factoryMethod(FileType fileType, std::string fileName);
};

FileCreator::~FileCreator(){  }

File *FileCreator::factoryMethod(FileType fileType, std::string fileName)
{
  File *file;
  switch(fileType)
  {
    case JPG_FILE:
      file = new JPGFile();
      break;
    case TXT_FILE:
      file = new TXTFile();
      break;
    case EXE_FILE:
      file = new EXEFile();
      break;
  }
  file->setFileName(fileName);
  return file;
}

class JPGFileCreator : public FileCreator{  };
class TXTFileCreator : public FileCreator{  };
class EXEFileCreator : public FileCreator{  };

int main()
{
  FileCreator *jpgFactory = new JPGFileCreator();
  FileCreator *txtFactory = new TXTFileCreator();
  FileCreator *exeFactory = new EXEFileCreator();

  File* files[] = { jpgFactory->factoryMethod(JPG_FILE, "foto.jpg"),
      txtFactory->factoryMethod(TXT_FILE, "story.txt"),
      exeFactory->factoryMethod(EXE_FILE, "solitare.exe") };

  for(unsigned int i = 0; i < sizeof(files)/sizeof(File*); i++)
  {
    files[i]->printFileName();
  }

  return 0;
}

