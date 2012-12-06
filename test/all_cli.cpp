#include <QApplication>
#include <QDebug>


#include "processor/PinYinProcessor.h"
#include "processor/InsertProcessor.h"
#include "processor/ToGifProcessor.h"
#include "processor/ReverseProcessor.h"
#include "processor/ToBigCharProcessor.h"
#include "processor/ToImageProcessor.h"
#include "processor/LevelProcessor.h"
#include "processor/LevelSeedProcessor.h"
#include "processor/ShuffleProcessor.h"
#include "processor/AverageInsertProcessor.h"
#include "processor/KeywordsProcessor.h"
#include "processor/SimilarProcessor.h"
#include "processor/VerticalLayoutProcessor.h"
#include "Result.h"


#include "test_function.h"

template<typename T>
void test(const QStringList& daiChuLi,const QString& wenJianMing){
    T t;
    Result jieGuo=t.process(daiChuLi);

    jieGuo.saveFile(t.name()+"_"+wenJianMing);
}

#define IF_TEST(STR,CS) if(leiXing==QString(#STR)) { test<STR> (neiRong,CS); return 0;}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    Q_ASSERT(argc>=2);

    QString leiXing(argv[argc-2]);

    QStringList neiRong=jiaZaiWenJianZiFuChuan(argv[argc-1]);

    QString wenJianMing=argv[argc-1];

    IF_TEST(ToBigCharProcessor,wenJianMing);
    IF_TEST(PinYinProcessor,wenJianMing);
    IF_TEST(ToImageProcessor,wenJianMing);
    IF_TEST(InsertProcessor,wenJianMing);
    IF_TEST(ToGifProcessor,wenJianMing);
    IF_TEST(ReverseProcessor,wenJianMing);
    IF_TEST(ShuffleProcessor,wenJianMing);
    IF_TEST(AverageInsertProcessor,wenJianMing);
    IF_TEST(SimilarProcessor,wenJianMing);
    IF_TEST(VerticalLayoutProcessor,wenJianMing);
    
    Q_ASSERT(false);
}

