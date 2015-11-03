#ifndef RESPONSE_H
#define RESPONSE_H

/**
 * @brief The Response class
 *
 * Stores information about a response to a question.
 */
class Response
{
    public:
        /**
         * @brief Response Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param student The ID of the student to which the response belongs.
         * @param personal The ID of the answer for the personal question.
         * @param desired The ID of the answer for the desired question.
         */
        Response(int student, int personal, int desired);

        /**
         * @brief Response Creates a new instance.
         * @param copy The Response to copy.
         */
        Response(const Response& copy);

        ~Response();

        /**
         * @brief getStudent
         * @return The ID of the student to which the response belongs.
         */
        int getStudent() const;

        /**
         * @brief getPersonal
         * @return The ID of the answer for the personal question.
         */
        int getPersonal() const;

        /**
         * @brief getDesired
         * @return The ID of the answer for the desired question.
         */
        int getDesired() const;

    private:
        int student;  // The ID of the student
        int personal; // The ID of the answer for the personal question
        int desired;  // The ID of the answer for the desired question
};

#endif // RESPONSE_H
