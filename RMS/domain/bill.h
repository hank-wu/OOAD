#ifndef BILL_H
#define BILL_H


class Bill
{
public:
    Bill(int amount);
    bool pay(int money);
    int getBalance();

private:
    int _amount;
    int _balance;
};

#endif // BILL_H
