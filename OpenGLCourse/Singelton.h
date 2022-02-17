#pragma once
class Singelton
{
private:
    /* Here will be the instance stored. */
    static Singelton* instance;

    /* Private constructor to prevent instancing. */
    Singelton();

public:
    /* Static access method. */
    static Singelton* getInstance();
};

