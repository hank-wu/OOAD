#include "receipt.h"

Receipt::Receipt(std::string tableName): _tableName(tableName)
{

}

void Receipt::setItem(std::string mealName, int subtotal){
    _mealName.push_back(mealName);
    _subtotal.push_back(subtotal);
}

std::string Receipt::content(){
    std::string content = "";
    std::vector<int>::iterator itSubtotal=_subtotal.begin();
    std::vector<std::string>::iterator itMealName = _mealName.begin();
    for(int i=0;i< _subtotal.size();i++){
        content += *itMealName + "  ";
        content += std::to_string(*itSubtotal) + "\n";
        itMealName++;
        itSubtotal++;
    }
    return content;
}
