
#include "ResultWidget.h"
#include "ui_ResultWidget.h"

#include <QFileDialog>
#include <QMovie>
#include <QBuffer>

#include "ResultHighlighter.h"
#include "hangChuLi.h"
#include "Gif.h"


ResultWidget::~ResultWidget(){}




ResultWidget::ResultWidget(QWidget* parent):
    QGroupBox(parent){
    ui_.reset(new Ui::ResultWidget());
     ui_->setupUi(this);

     ResultHighlighter *gaoLiangQi=new ResultHighlighter(ui_->plainTextEdit_ziFuChuanResult->document());

     gaoLiangQi->setDocument(ui_->plainTextEdit_ziFuChuanResult->document());

     sheZhiResult(Result());
}

void ResultWidget::on_pushButton_baoCunDaoJianQieBan_clicked(){

     Result_.saveClipboard();
}

void ResultWidget::on_pushButton_baoCunWenJian_clicked(){
     QString wenJianLeiXing;
     if (Result_.type()==STRING) {
      wenJianLeiXing="*.txt";
     }else if(Result_.type()==IMAGE){
       wenJianLeiXing="*.bmp *.jpg *.png";
     }else{
         Q_ASSERT(Result_.type()==GIF_ANIMATION);
         wenJianLeiXing="*.gif";
     }


     QString wenJianMing=QFileDialog::getSaveFileName(this,
	       tr("save to file"),QString(),wenJianLeiXing);

     Result_.saveFile(wenJianMing);

}


void ResultWidget::sheZhiResult(const Result& ResultSheZhi){
     Result_=ResultSheZhi;

     bool jianQieBan=false;
     bool qingKong=false;


     switch(Result_.type()){
     case STRING:{
         ui_->stackedWidget->setCurrentIndex(0);
         ui_->plainTextEdit_ziFuChuanResult->document()->clear();
         tianChong(ui_->plainTextEdit_ziFuChuanResult->document(),ResultSheZhi.string());
         jianQieBan=true;
         qingKong=true;
         break;
     }
     case IMAGE:{
         ui_->stackedWidget->setCurrentIndex(1);
         ui_->label_tuPianResult->setMovie(NULL);
         ui_->label_tuPianResult->setPixmap(QPixmap::fromImage(Result_));
         jianQieBan=true;
         qingKong=false;
         break;
     }
     case GIF_ANIMATION:{
         ui_->stackedWidget->setCurrentIndex(1);

         dongHua_.reset(new Gif(ResultSheZhi));

         QMovie *dianYing=dongHua_->dongHua();

         ui_->label_tuPianResult->setMovie(dianYing);

         dianYing->start();
         jianQieBan=false;
         qingKong=false;
         break;
     }
     }

     ui_->pushButton_baoCunDaoJianQieBan->setEnabled(jianQieBan);
     ui_->pushButton_qingKong->setEnabled(qingKong);

}


QString ResultWidget::kongJianWenBen(){

    return heBingDuoHang(::kongJianWenBen(ui_->plainTextEdit_ziFuChuanResult->document()));
}
