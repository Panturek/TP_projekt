#ifndef WRITEMEMORY_H
#define WRITEMEMORY_H
#include <string>

class WriterMemory
{
public:
    WriterMemory();
    ~WriterMemory();
    void* Realloc(void* ptr, size_t size);
    size_t WriteMemoryCallback(char* ptr, size_t size, size_t nmemb);
    void print();
    void clear();
    std::string getContent() const;
private:
    char* m_pBuffer;
    size_t m_Size;
};

#endif // WRITEMEMORY_H
