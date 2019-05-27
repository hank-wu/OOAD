#include "cargo_dao.h"

CargoDao::CargoDao(QSqlQuery * query, QSqlDatabase * mydb): _query(query),_mydb(mydb)
{

}

std::map<int,Cargo *> * CargoDao::getCargoList(){
    _mydb->open();
    std::map<int,Cargo *> * cargoList = new std::map<int,Cargo *>();

    _query->exec("select * from menu");
    while(_query->next())
    {
        int rowNum = _query->at();
        //int columnNum = _query->record().count();
        int fieldId = _query->record().indexOf("id");
        int fieldName = _query->record().indexOf("name");
        int fieldCargo = _query->record().indexOf("cargo");

        int id = _query->value(fieldId).toInt();
        QString qstrFieldName = _query->value(fieldName).toString();
        qstrFieldName += "貨物";
        std::string name = string((const char *)qstrFieldName.toLocal8Bit());
        int cargoAmount = _query->value(fieldCargo).toInt();

        //std::cout<<"id = "<<id<<"  name = "<<tableName<<std::endl;

        Cargo * cargo = new Cargo(id,name,cargoAmount);
        (*cargoList)[id] = cargo;
    }
    _mydb->close();
    return cargoList;
}

void CargoDao::refresh(int id, int amount){
    _mydb->open();
    QString queryStr = "UPDATE menu SET cargo = '";
    queryStr += QString::number(amount) + "' WHERE id = ";
    queryStr += QString::number(id);
    _query->exec(queryStr);
    _mydb->close();
}

void CargoDao::closeDB(){
    _mydb->close();
}
