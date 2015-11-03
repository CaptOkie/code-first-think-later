#ifndef RESPONSE_H
#define RESPONSE_H

class Response
{
    public:
        Response(int student, int personal, int desired);
        Response(const Response&);
        ~Response();

        int getStudent() const;
        int getPersonal() const;
        int getDesired() const;

    private:
        int student;
        int personal;
        int desired;
};

#endif // RESPONSE_H
