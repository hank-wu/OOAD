#ifndef RECEIPT_H
#define RECEIPT_H

#include "order_item.h"
#include <map>
#include <string>
#include <vector>

class Receipt
{
public:
    Receipt(std::string tableName);
    void setItem(std::string mealName,int subtotal);
    std::string content();
private:
    std::string _tableName;
    std::vector<std::string> _mealName;
    std::vector<int> _subtotal;

};

#endif // RECEIPT_H
