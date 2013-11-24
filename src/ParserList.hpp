#ifndef FILE_PARSERLIST_HPP
#define FILE_PARSERLIST_HPP

#include <vector>


template<typename... Parsers>
class ParserList
{
    private std::vector<Parser> list;

    public ParserList()
    :   list{(Parsers())...}
    {
    }

    public ParserStatus Parse(TCHAR & element)
    {
        ParserStatus status = Parser::Ok;

        for (const auto & parser : list)
        {
            const auto & s = parser::Parse(element);
            if (s > status)
            {
                status = s;
            }
        }
        return status;
    }
};

#endif
