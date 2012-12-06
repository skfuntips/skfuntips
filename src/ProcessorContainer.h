#ifndef CHU_LI_RONG_QI_H
#define CHU_LI_RONG_QI_H

#include <vector>

class IProcessor;

class ProcessorContainer :private std::vector<IProcessor*>{

    typedef std::vector<IProcessor*> FuLeiXing;



public:

    using FuLeiXing::begin;

    using FuLeiXing::end;

    using FuLeiXing::size;

    using FuLeiXing::iterator;

    using FuLeiXing::const_iterator;

    using FuLeiXing::operator [];

    ProcessorContainer();

};


#endif//CHU_LI_RONG_QI_H
