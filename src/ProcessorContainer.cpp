#include "ProcessorContainer.h"

#include "processor/ToBigCharProcessor.h"
#include "processor/PinYinProcessor.h"
#include "processor/ToImageProcessor.h"
#include "processor/InsertProcessor.h"
#include "processor/ToGifProcessor.h"
#include "processor/ReverseProcessor.h"
#include "processor/ShuffleProcessor.h"
#include "processor/AverageInsertProcessor.h"
#include "processor/KeywordsProcessor.h"
#include "processor/SimilarProcessor.h"
#include "processor/VerticalLayoutProcessor.h"
#include "processor/EncryptProcessor.h"
#include "processor/DeEncryptProcessor.h"
#include "processor/OffsetProcessor.h"

ProcessorContainer::ProcessorContainer(){

   push_back(new ToBigCharProcessor());
   push_back(new PinYinProcessor());
   push_back(new ToImageProcessor());
   push_back(new InsertProcessor());
   push_back(new ToGifProcessor());
   push_back(new ReverseProcessor());
   push_back(new ShuffleProcessor());
   push_back(new AverageInsertProcessor());
   push_back(new SimilarProcessor());
   push_back(new VerticalLayoutProcessor());
   push_back(new EncryptProcessor());
   push_back(new DeEncryptProcessor());
   push_back(new OffsetProcessor());


   push_back(new KeywordsProcessor());


}
