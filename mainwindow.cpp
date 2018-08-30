#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QString>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dTemp1 = 0;
    m_dTemp2 = 0;
    m_iStatus = 0;
    m_iPcount = 0;
    m_sShow = "0";
    m_cSymbol = ' ';
    ui->lineEdit->setText("0");
}

//标准输出
void MainWindow::m_output()
{

    //去小数点后后缀0，若去光 则去掉小数点
    int slen = m_sShow.length();
    for (int i = 0; i < slen; i++)
        {
        if((m_iStatus >> 1 & 1) == 0)
            break;
        if(m_sShow[slen - 1 - i] != '0' && m_sShow[slen - 1 - i] != '.')
            break;
        if(m_sShow[slen - 1 - i] == '0')
            {
            m_sShow.chop(1);
            m_iPcount--;
            continue;
            }
        //去掉小数点 并且更新小数点有无的状态
        if(m_sShow[slen - 1 - i] == '.')
            {
            m_sShow.chop(1);
            m_iStatus = m_iStatus & 13;
            break;
            }
        }

        ui->lineEdit->setText(m_sShow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//C按钮 完全重置
void MainWindow::on_pushButton_3_clicked()
{
    m_dTemp1 = 0;
    m_dTemp2 = 0;
    m_iStatus = 0;
    m_iPcount = 0;
    m_sShow = "0";
    m_cSymbol = ' ';
    ui->lineEdit->setText(m_sShow);
}

//0按钮
void MainWindow::on_pushButton_21_clicked()
{
    m_iszero("0");
    if((m_iStatus >> 2 & 1) == 0)
        return;
    m_inputnumber(0);
    m_sShow.append("0");
    if((m_iStatus >> 3 & 1) == 0)
        ui->lineEdit->setText(m_sShow);
    else
        ui->lineEdit->setText("-" + m_sShow);
}

//1按钮
void MainWindow::on_pushButton_17_clicked()
{
   m_inputnumber(1);
   m_iszero("1");
   m_sShow.append("1");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//2按钮
void MainWindow::on_pushButton_16_clicked()
{
   m_inputnumber(2);
   m_iszero("2");
   m_sShow.append("2");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//3按钮
void MainWindow::on_pushButton_18_clicked()
{
   m_inputnumber(3);
   m_iszero("3");
   m_sShow.append("3");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//4按钮
void MainWindow::on_pushButton_10_clicked()
{
   m_inputnumber(4);
   m_iszero("4");
   m_sShow.append("4");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//5按钮
void MainWindow::on_pushButton_12_clicked()
{
   m_inputnumber(5);
   m_iszero("5");
   m_sShow.append("5");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//6按钮
void MainWindow::on_pushButton_13_clicked()
{
   m_inputnumber(6);
   m_iszero("6");
   m_sShow.append("6");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//7按钮
void MainWindow::on_pushButton_9_clicked()
{
   m_inputnumber(7);
   m_iszero("7");
   m_sShow.append("7");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//8按钮
void MainWindow::on_pushButton_8_clicked()
{
   m_inputnumber(8);
   m_iszero("8");
   m_sShow.append("8");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//9按钮
void MainWindow::on_pushButton_7_clicked()
{
   m_inputnumber(9);
   m_iszero("9");
   m_sShow.append("9");
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//.按钮
void MainWindow::on_pushButton_22_clicked()
{
    if((m_iStatus >> 1 & 1) == 1)
        return;
    m_iStatus = m_iStatus | 2;
    m_sShow.append(".");
    if((m_iStatus >> 3 & 1) == 0)
        ui->lineEdit->setText(m_sShow);
    else
        ui->lineEdit->setText("-" + m_sShow);
}

//CE按钮
void MainWindow::on_pushButton_2_clicked()
{

   //清除当前寄存器数据
   if((m_iStatus & 1) == 0)
       m_dTemp1 = 0;
   if((m_iStatus & 1) == 1)
       m_dTemp2 = 0;

   //重置当前显示面板
   m_sShow = "0";
   m_output();

   //重置正负、是否第一次输入和小数点状态
   m_iStatus = m_iStatus & 1;
   m_iPcount = 0;
}

//删除按钮
void MainWindow::on_pushButton_clicked()
{
    int slen;
    slen = m_sShow.length();

    //当长度只有1时
    if(slen == 1)
     {
        MainWindow::on_pushButton_2_clicked();
        return;
     }

    //最后一位为小数点时
    if(m_sShow[slen - 1] == '.')
        {
        m_iStatus = m_iStatus & 13;
        m_sShow.chop(1);
        ui->lineEdit->setText(m_sShow);
        return;
        }

    //没有小数点时删除最后的数字
    if((m_iStatus >> 1 & 1) == 0)
        {

        //寄存器1
        if((m_iStatus & 1) == 0)
            {
            m_dTemp1 = (m_dTemp1 - (int)m_dTemp1 % 10) / 10;
            }

        //寄存器2
        if((m_iStatus & 1) == 1)
            {
            m_dTemp2 = (m_dTemp2 - (int)m_dTemp2 % 10) / 10;
            }
        }

    //删除小数点后的数字时
    if((m_iStatus >> 1 & 1) == 1)
        {

        //寄存器1
        if((m_iStatus & 1) == 0)
            {
            for(int i = 0; i < m_iPcount + 1; i++)
                {
                m_dTemp1*=10;
                }
            m_dTemp1 = (m_dTemp1 - (int)m_dTemp1 % 10) / 10;
            for(int i = 0; i < m_iPcount + 1; i++)
                {
                m_dTemp1/=10;
                }
            m_iPcount--;
            }

        //寄存器2
        if((m_iStatus & 1) == 1)
            {
            for(int i = 0; i < m_iPcount + 1; i++)
                {
                m_dTemp2*=10;
                }
            m_dTemp1 = (m_dTemp1 - (int)m_dTemp1 % 10) / 10;
            for(int i = 0; i < m_iPcount + 1; i++)
                {
                m_dTemp2/=10;
                }
            m_iPcount--;
            }
        }

    //去除最后一个字符并展示
    m_sShow.chop(1);
    ui->lineEdit->setText(m_sShow);
}

//+按钮
void MainWindow::on_pushButton_23_clicked()
{
    if(m_cSymbol != ' ')
        return;
    m_inputsymbol('+');
    ui->lineEdit->setText("+");
}

//-按钮
void MainWindow::on_pushButton_20_clicked()
{
    if(m_cSymbol != ' ')
        return;
    m_inputsymbol('-');
    ui->lineEdit->setText("-");
}

//*按钮
void MainWindow::on_pushButton_14_clicked()
{
    if(m_cSymbol != ' ')
        return;
    m_inputsymbol('*');
    ui->lineEdit->setText("*");
}

//除按钮
void MainWindow::on_pushButton_6_clicked()
{
    if(m_cSymbol != ' ')
        return;
    m_inputsymbol('/');
    ui->lineEdit->setText("/");
}

//%按钮
void MainWindow::on_pushButton_15_clicked()
{
    if(m_cSymbol != ' ')
        return;
    m_inputsymbol('%');
    ui->lineEdit->setText("%");
}

//正负号转换按钮
void MainWindow::on_pushButton_4_clicked()
{
   if((m_iStatus >> 3 & 1) ==  0)
       m_iStatus +=8;
   else
       m_iStatus -=8;
   if((m_iStatus >> 3 & 1) == 0)
       ui->lineEdit->setText(m_sShow);
   else
       ui->lineEdit->setText("-" + m_sShow);
}

//开根号按钮
void MainWindow::on_pushButton_5_clicked()
{
    if((m_iStatus >> 3 & 1) ==  1)
        {
            ui->lineEdit->setText("负数不能开方");
            return;
        }
    if((m_iStatus & 1) == 0)
        {
        m_dTemp1 = sqrt(m_dTemp1);
        m_sShow = QString::asprintf("%lf",m_dTemp1);
        }
    if((m_iStatus & 1) == 1)
        {
        m_dTemp2 = sqrt(m_dTemp2);
        m_sShow = QString::asprintf("%lf",m_dTemp2);
        }
    m_tempnow(m_sShow);
    m_output();
}

//=按钮
void MainWindow::on_pushButton_25_clicked()
{
    if(m_cSymbol == ' ')
        return;

    if((m_iStatus >> 3 & 1) == 1)
        {
            m_dTemp2 = 0 - m_dTemp2;
        }

    if(m_cSymbol == '+')
        m_dTemp1 = m_dTemp1 + m_dTemp2;

    if(m_cSymbol == '-')
        m_dTemp1 = m_dTemp1 - m_dTemp2;

    if(m_cSymbol == '*')
        m_dTemp1 = m_dTemp1 * m_dTemp2;

    if(m_cSymbol == '/')
        {
        if(m_dTemp2 == 0)
            {
            ui->lineEdit->setText("除数不能为0 请重新输入除数");
            m_dTemp2 = 0;
            m_iStatus = 1;
            m_sShow = "0";
            m_iPcount = 0;
            return;
            }
        m_dTemp1 = m_dTemp1 / m_dTemp2;
        }

    if(m_cSymbol == '%')
        {
        if((m_dTemp1 == (int)m_dTemp1) && (m_dTemp2 ==(int)m_dTemp2))
            m_dTemp1 = (int)m_dTemp1 % (int)m_dTemp2;
        else
            {
            ui->lineEdit->setText("小数不可以取余");
            m_dTemp1 = 0;
            m_dTemp2 = 0;
            m_iStatus = 0;
            m_iPcount = 0;
            m_sShow = "0";
            m_cSymbol = ' ';
            return ;
            }
        }

    m_sShow = QString::asprintf("%lf",m_dTemp1);
    m_tempnow(m_sShow);
    m_output();
    m_iStatus = m_iStatus & 14;
    m_dTemp2 = 0;
    m_cSymbol = ' ';
}
