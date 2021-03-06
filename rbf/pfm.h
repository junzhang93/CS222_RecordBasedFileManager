#ifndef _pfm_h_
#define _pfm_h_

#include <climits>
#include <fstream>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

typedef unsigned PageNum;
typedef int RC;
typedef char byte;

#define PAGE_SIZE 4096
#define SUCCESS 0
#define FAIL (-1)
const byte FILE_ID = 0xaa;

class FileHandle;

class PagedFileManager
{
public:
    static PagedFileManager* instance();                                  // Access to the _pf_manager instance

    RC createFile    (const string &fileName);                            // Create a new file
    RC destroyFile   (const string &fileName);                            // Destroy a file
    RC openFile      (const string &fileName, FileHandle &fileHandle);    // Open a file
    RC closeFile     (FileHandle &fileHandle);                            // Close a file

protected:
    PagedFileManager();                                                   // Constructor
    ~PagedFileManager();                                                  // Destructor

private:
    static PagedFileManager *_pf_manager;
};


class FileHandle
{
    friend class PagedFileManager;

public:
    // variables to keep the counter for each operation
    shared_ptr<unsigned> readPageCounter = make_shared<unsigned>(0);
    shared_ptr<unsigned> writePageCounter = make_shared<unsigned>(0);
    shared_ptr<unsigned> appendPageCounter = make_shared<unsigned>(0);
    shared_ptr<unsigned> numOfPages = make_shared<unsigned>(0);
    
    FileHandle();                                                         // Default constructor
    ~FileHandle();                                                        // Destructor

    RC readPage(PageNum pageNum, void *data);                             // Get a specific page
    RC writePage(PageNum pageNum, const void *data);                      // Write a specific page
    RC appendPage(const void *data);                                      // Append a specific page
    unsigned getNumberOfPages();                                          // Get the number of pages in the file
    RC collectCounterValues(unsigned &readPageCount, unsigned &writePageCount, unsigned &appendPageCount);  // Put the current counter values into variables
    RC readHeaderPage(void *data);
    RC writeHeaderPage(const void *data);

private:
    static const int RD_OFFSET = sizeof(FILE_ID);
    static const int WR_OFFSET = RD_OFFSET + sizeof(unsigned);
    static const int APP_OFFSET = WR_OFFSET + sizeof(unsigned);
    static const int NUM_OF_PAGES_OFFSET = APP_OFFSET + sizeof(unsigned);

    shared_ptr<fstream> file = make_shared<fstream>();

    RC openFile(const string &fileName);
    RC closeFile();
};

#endif
