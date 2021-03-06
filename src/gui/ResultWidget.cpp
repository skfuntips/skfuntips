
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

     setResult(Result());
}

void ResultWidget::on_pushButton_saveToClipboard_clicked(){

     Result_.saveClipboard();
}

void ResultWidget::on_pushButton_saveToFile_clicked(){
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


void ResultWidget::setResult(const Result& resultSet){
     Result_=resultSet;

     bool jianQieBan=false;
     bool qingKong=false;


     switch(Result_.type()){
     case STRING:{
         ui_->stackedWidget->setCurrentIndex(0);
         ui_->plainTextEdit_ziFuChuanResult->document()->clear();

         tianChong(ui_->plainTextEdit_ziFuChuanResult->
                   document(),resultSet.string());

         ui_->label_charCount->show();
         ui_->label_charCount->setText(tr("char count:")
                     +QString::number(ui_->plainTextEdit_ziFuChuanResult->document()->characterCount()));
         jianQieBan=true;
         qingKong=true;
         break;
     }
     case IMAGE:{
         ui_->label_charCount->hide();
         ui_->stackedWidget->setCurrentIndex(1);
         ui_->label_tuPianResult->setMovie(NULL);
         ui_->label_tuPianResult->setPixmap(QPixmap::fromImage(Result_));
         jianQieBan=true;
         qingKong=false;
         break;
     }
     case GIF_ANIMATION:{
         ui_->label_charCount->hide();
         ui_->stackedWidget->setCurrentIndex(1);

         dongHua_.reset(new Gif(resultSet));

         QMovie *dianYing=dongHua_->dongHua();

         ui_->label_tuPianResult->setMovie(dianYing);

         dianYing->start();
         jianQieBan=false;
         qingKong=false;
         break;
     }
     }

     ui_->pushButton_saveToClipboard->setEnabled(jianQieBan);
     ui_->pushButton_clear->setEnabled(qingKong);

}


QString ResultWidget::contents(){

    return heBingDuoHang(::kongJianWenBen(ui_->plainTextEdit_ziFuChuanResult->document()));
}
