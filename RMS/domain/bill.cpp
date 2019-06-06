#include "bill.h"

Bill::Bill(int amount): _amount(amount)
{

}

bool Bill::pay(int money){
    bool isEnough = false;
    if(money >= _amount){
        isEnough = true;
        _balance = money - _amount;
    }
    return isEnough;
}

int Bill::getBalance(){
    return _balance;
}
