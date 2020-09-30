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
        writer.clear();
        if(user_id > 0){
            emit loggedIn();
        }
    }
    catch(...){
        qDebug() << "conn refused";
    }
    writer.clear();
}

void SessionManager::registerRequest(){
    getPlans( "ch" );
}

std::string SessionManager::getLastResponse(){
    auto res = writer.getContent();
    writer.clear();
    return res;
}

int SessionManager::getUserId() const{
    return user_id;
}

QString SessionManager::getPlans(const QString searched ){
    try{
        if( searched == "")
            return "";
        auto id = QString::number( user_id ).toStdString();
        auto url = host+"/getplans.php?q="+searched.toStdString()+"&u="+id;

        request.setOpt(new curlpp::options::Url(url.c_str()));
        request.setOpt(new curlpp::options::HttpGet(("q=ch&u="+id).c_str()));
        request.perform();
        return getLastResponse().c_str();
    }
    catch(...){

    }
    return "";
}

QString SessionManager::planData( const QString planId){
    try{
        auto url = host+"/plandata.php";
        std::string postField = "{ \"plan_id\":\""+planId.toStdString()+"\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
        return getLastResponse().c_str();
    }
    catch(...){

    }
    return "";
}

void SessionManager::newPlan(const QString plan ){
    try{
        auto url = host+"/newplan.php";
        std::string postField = plan.toStdString();
/* {\"name\":\"nazwa planu\",
 * \"description\":\"krótki opis działania planu \",
 * \"author\":\"1\",
 * \"plan\":{
 * \"features\":{
 * \"open\":true,
 * \"states\":[\"a\",\"b\",\"c\",\"d\"],
 * \"display\":\"text\",
 * \"startdate\":false,
 * \"enddate\":false},
 * \"tasks\":{
 * \"t0\":{\"next\":\"t1\"},
 * \"t1\":{\"text\":\"task1\",\"next\":\"t2\"},
 * \"t2\":{\"text\":\"task2\",\"next\":\"t0\"}
 * }}}";
*/
        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

QString SessionManager::myPlans(){
    if(user_id < 1){
        return "" ;
    }

    try{
        auto url = host+"/myplans.php";
        auto userId = QString::number(user_id).toStdString();
        std::string postField = userId;

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();

        return QString::fromStdString(getLastResponse());
    }
    catch(...){

    }
}

QString SessionManager::planReview(const std::string plan_id){
    if(user_id < 1){
        return "";
    }

    try{
        auto url = host+"/planreview.php";
        auto userId = QString::number(user_id).toStdString();
        std::string postField = "{ \"plan_id\":\""+plan_id+"\", \"user_id\":\""+userId+"\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
        return getLastResponse().c_str();
    }
    catch(...){

    }
    return "";
}

void SessionManager::newExecutive(const QString plan_id){
    if(user_id < 1){
        return;
    }

    try{
        auto url = host+"/newexecutive.php";
        auto planId = plan_id.toStdString();
        auto userId = QString::number(user_id).toStdString();
        std::string postField = "{ \"plan_id\":\""+planId+"\", \"user_id\":\""+userId+"\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

void SessionManager::setState(const QString planId,
                              const int userId,
                              const QString taskId,
                              const QString state){
    if(user_id < 1){
        return;
    }

    try{
        auto url = host+"/setstate.php";
        std::string postField = "{ \"plan_id\":\"102009071956271\", \"user_id\":\"1\", "
                                " \"task_id\": \"t2\", \"state\": \"Done\" }";

        request.setOpt(new curlpp::options::PostFields(postField.c_str()));
        request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
        request.setOpt(new curlpp::options::Url(url.c_str()));

        request.perform();
    }
    catch(...){

    }
}

QString SessionManager::planState(const QString planId, const int userId){
    if(user_id < 1){
            return "";
        }

        try{
            auto url = host+"/setstate.php";
            std::string postField = "{ \"plan_id\":\"102009071956271\", \"user_id\":\"1\", "
                                    " \"task_id\": \"t2\", \"state\": \"Done\" }";

            request.setOpt(new curlpp::options::PostFields(postField.c_str()));
            request.setOpt(new curlpp::options::PostFieldSize(postField.size()));
            request.setOpt(new curlpp::options::Url(url.c_str()));

            request.perform();
            return getLastResponse().c_str();
        }
        catch(...){

        }
}
