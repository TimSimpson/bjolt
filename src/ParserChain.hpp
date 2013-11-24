#include <ParserStatus.hpp>
#include <windows.h>


template<typename MyParser, typename NextParser>
class ParserChain
{
private:
    MyParser parser;
    NextParser next;

public:
    ParserChain()
    :   parser(),
        next()
    {
    }

    ParserStatus Parse(TCHAR & element)
    {
        auto status = ParserStatus::Ok;
        Parse(status, element);
        return status;
    }

    void Parse(ParserStatus & currentStatus, TCHAR & element)
    {
        if (currentStatus < ParserStatus::Error)
        {
            const ParserStatus myStatus = parser.Parse(element);
            if (myStatus > currentStatus)
            {
                currentStatus = myStatus;
            }
        }
        next.Parse(currentStatus, element);
    }

};


class ParserChainEnd
{
public:
    void Parse(ParserStatus & currentStatus, TCHAR & element)
    {
    }
};

