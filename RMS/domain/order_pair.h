#ifndef ORDER_PAIR_H
#define ORDER_PAIR_H


class OrderPair
{
public:
    OrderPair(int id,int amount);
    int getId();
    int getAmount();

private:
    int _id;
    int _amount;
};

#endif // ORDER_PAIR_H
