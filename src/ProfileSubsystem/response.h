#ifndef RESPONSE_H
#define RESPONSE_H

class Response
{
    public:
        Response(int question, int personal, int desired);
        Response(const Response& response);
        ~Response();

        int getQuestion() const;
        int getPersonal() const;
        int getDesired() const;

    private:
        int question;
        int personal;
        int desired;
};

#endif // RESPONSE_H
