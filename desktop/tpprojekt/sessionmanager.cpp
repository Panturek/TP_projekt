#include "sessionmanager.h"
#include <qdebug.h>
#include "writememory.h"
#include "qregularexpression.h"

int getIdFromResponse( const std::string inputString ){
    QRegularExpression re("id=(?<id>\\d+);");
    QRegularExpressionMatch match = re.match( QString::fromStdString(inputString) );
    if( match.hasMatch() ){
        return match.captured("id").toInt();
    }
    return -1;
}

SessionManager::SessionManager(QObject *parent, std::string host)
    : QObject(parent)
    , host(host)
    , user_id(-1){
}

SessionManager::~SessionManager(){
    curlpp::Cleanup cleanup;
}
void SessionManager::makeWriter(){
    using namespace std::placeholders;
    curlpp::types::WriteFunctionFunctor functor
            = std::bind(&WriterMemory::WriteMemoryCallback, &writer, _1, _2, _3);
    request.setOpt(new curlpp::options::WriteFunction(functor));
}

void SessionManager::login( const QString plogin, const QString ppassword){
    try{
        makeWriter();
        std::string url = std::string(host) + "/zaloguj.php";
        std::string login = "login="+plogin.toStdString();
        std::string haslo = "haslo="+ppassword.toStdString();
        std::string data = (login+'&'+haslo).c_str();

        request.setOpt(new curlpp::options::Url(url.c_str()));
        //request.setOpt(new curlpp::options::Verbose(true));

        request.setOpt(new curlpp::options::PostFields(data.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(data.size()));

        request.perform();
        user_id = getIdFromResponse(writer.getContent());
        if(user_id > 0){
            emit loggedIn();
        }
    }
    catch(...){
        qDebug() << "conn refused";
    }
}

void SessionManager::registerRequest(){
    getPlans();
}

std::string SessionManager::getLastResponse(){
    auto res = writer.getContent();
    writer.clear();
    return res;
}

void SessionManager::getPlans(const std::string user_id ){
    try{
        auto id = QString::number( getIdFromResponse(user_id) ).toStdString();
        auto url = host+"/getplans.php?q=ch&u="+id;

        request.setOpt(new curlpp::options::Url(url.c_str()));
        request.setOpt(new curlpp::options::HttpGet(("q=ch&u="+id).c_str()));
        request.perform();

    }
    catch(...){

    }
}

void SessionManager::planData(){
    try{
        auto url = host+"/plandata.php";
        std::string postField = "{ \"plan_id\":\"12009232331491\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

void SessionManager::newPlan( ){
    try{
        auto url = host+"/newplan.php";
        std::string postField = "{\"name\":\"nazwa planu\",\"description\":\"krótki opis działania planu \",\"author\":\"1\","
                                "\"plan\":{\"features\":{\"open\":true,\"states\":[\"a\",\"b\",\"c\",\"d\"],\"display\":\"text\",\"startdate\":false,\"enddate\":false},\"tasks\":{\"t0\":{\"next\":\"t1\"},\"t1\":{\"text\":\"task1\",\"next\":\"t2\"},\"t2\":{\"text\":\"task2\",\"next\":\"t0\"}}}}";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

void SessionManager::planReview(const std::string plan_id){
    if(user_id < 1){
        return;
    }

    try{
        auto url = host+"/planreview.php";
        std::string postField = "{ \"plan_id\":\"102009071956271\", \"user_id\":\"1\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

void SessionManager::newExecutive(){
    if(user_id < 1){
        return;
    }

    try{
        auto url = host+"/newexecutive.php";
        std::string postField = "{ \"plan_id\":\"12009232331491\", \"user_id\":\"1\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

