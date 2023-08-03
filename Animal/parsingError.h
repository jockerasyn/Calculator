#ifndef PARSEERROR_H_
#define PARSEERROR_H_
enum parseError
{
    NoError,
    FileNotExist,
    DirrNotExist,
    WritingError,
    IncorrectFormat,
    EmptyFarm
};
#endif