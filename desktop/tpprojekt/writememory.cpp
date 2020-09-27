#include "writememory.h"
#include <qdebug.h>
#include <memory>
#include <cstring>

#define MAX_FILE_LENGTH 20000

WriterMemory::WriterMemory(){
    this->m_pBuffer = NULL;
    this->m_pBuffer = (char*) malloc(MAX_FILE_LENGTH * sizeof(char));
    this->m_Size = 0;
}

WriterMemory::~WriterMemory(){
    if (this->m_pBuffer)
        free(this->m_pBuffer);
}

void* WriterMemory::Realloc(void* ptr, size_t size){
    if(ptr)
        return realloc(ptr, size);
    else
        return malloc(size);
}

size_t WriterMemory::WriteMemoryCallback(char* ptr, size_t size, size_t nmemb){
    size_t realsize = size * nmemb;

    m_pBuffer = (char*) Realloc(m_pBuffer, m_Size + realsize);
    if (m_pBuffer == NULL) {
        realsize = 0;
    }
    memcpy(&(m_pBuffer[m_Size]), ptr, realsize);
    m_Size += realsize;
    return realsize;
}

void WriterMemory::print(){
    qDebug() << "Size: " << m_Size;
    qDebug() << "Content: " << m_pBuffer;
}

std::string WriterMemory::getContent() const{
    if(m_Size && m_pBuffer)
        return std::string(m_pBuffer);
    return "";
}

