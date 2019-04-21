#include "seat_order.h"

SeatOrder::SeatOrder(Seat *seat,Order *order)
    :_seat(seat), _order(order)
{

}

int SeatOrder::getSeatId(){
    return _seat->getSeatId();
}
