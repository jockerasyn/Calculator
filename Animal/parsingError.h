#ifndef PARSEERROR_H_
#define PARSEERROR_H_
enum ParseError
{
    NoError,
    FileNotExist,
    DirrNotExist,
    WritingError,
    IncorrectFormat,
    EmptyFarm
};
#endif