#ifndef ROUND_H
#define ROUND_H

// THIS FORUMAL IS VERY IMPORTANT FORMULA

// If we iterate threw out turns from 

/*

&& the first player's number is  = x;
for(int i = 0; i < 52; i++)
{
then playerturn = (i + x)%4

*/
class Round
{
    public:
    bool Play();
    Round();

    private:
    bool spades_[13];
    bool hearts_[13];
    bool clubs_[13];
    bool diamonds_[13];
};

#endif
