#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;


class Observer {
public:
	virtual void update () = 0;
};


#endif
