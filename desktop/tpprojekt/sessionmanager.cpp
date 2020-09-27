#include "sessionmanager.h"
#include <qdebug.h>
#include "writememory.h"

void getPlans(){
    curlpp::Cleanup cleaner;
    curlpp::Easy request;
    WriterMemory mWriterChunk;
    auto url = "http://localhost/rest/getplans.php?q=ch&u=1";
    auto data = "q=ch&u=1";

    using namespace std::placeholders;
    curlpp::types::WriteFunctionFunctor functor
            = std::bind(&WriterMemory::WriteMemoryCallback, &mWriterChunk, _1, _2, _3);
    request.setOpt(new curlpp::options::WriteFunction(functor));

    request.setOpt(new curlpp::options::Url(url));
    request.setOpt(new curlpp::options::HttpGet(data));
    request.setOpt(new curlpp::options::Verbose(true));
    request.perform();

    mWriterChunk.print();
}

SessionManager::SessionManager(QObject *parent, std::string host)
    : QObject(parent)
    , host(host){
}

SessionManager::~SessionManager(){
    curlpp::Cleanup cleanup;
}

void SessionManager::login( const QString plogin, const QString ppassword){

    std::string url = std::string(host) + "/zaloguj.php";
    std::string login = "login="+plogin.toStdString();
    std::string haslo = "haslo="+ppassword.toStdString();
    std::string data = (login+'&'+haslo).c_str();

    request.setOpt(new curlpp::options::Url(url.c_str()));
    request.setOpt(new curlpp::options::Verbose(true));

    WriterMemory mWriterChunk;
    using namespace std::placeholders;
    curlpp::types::WriteFunctionFunctor functor =
            std::bind(&WriterMemory::WriteMemoryCallback, &mWriterChunk, _1, _2, _3);
    request.setOpt(new curlpp::options::WriteFunction(functor));

    request.setOpt(new curlpp::options::PostFields(data.c_str()));
    request.setOpt(new curlpp::options::PostFieldSize(data.size()));

    request.perform();
    qDebug() << mWriterChunk.getContent().c_str();
}

void SessionManager::registerRequest(){
    getPlans();
    qDebug() << "register" ;
}

void SessionManager::establishSession(){

}
