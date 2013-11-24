#include <ParserStatus.hpp>
#include <sstream>
#include <windows.h>


template<typename Console, typename Parser>
class LineParser
{
private:
    Console console;
    ParserStatus currentLineStatus;
    std::stringstream lineBuffer;
    Parser parser;

public:

    LineParser()
    :   console(),
        currentLineStatus(ParserStatus::Ok),
        lineBuffer(),
        parser()
    {

    }

    void ParseLine(TCHAR * more, size_t length)
    {
        for (size_t i = 0; i < length; ++i)
        {
            if ('\n' == more[i])
            {
                printLine();
            }
            else
            {
                const auto result = parser.Parse(more[i]);
                if (result > currentLineStatus)
                {
                    currentLineStatus = result;
                }
                lineBuffer << more[i];
            }
        }
    }

private:
    typename ParserStatus parse(TCHAR & element)
    {
        return parser.Parse(element);
    }

    void printLine()
    {
        //cout << "POKAY>" << lineBuffer.str() << "<POKAY\n";
        if (currentLineStatus == ParserStatus::Error)
        {
            console.WriteError(lineBuffer.str());
        }
        else if (currentLineStatus == ParserStatus::Warning)
        {
            console.WriteWarning(lineBuffer.str());
        }
        else
        {
            console.WriteNormal(lineBuffer.str());
        }
        lineBuffer.str("");
        lineBuffer.clear();
        currentLineStatus = ParserStatus::Ok;
    }
};
