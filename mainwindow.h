#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //数字按钮录入
    void m_inputnumber(double num)
    {

        //寄存器1等待输入时
        if((m_iStatus & 1) == 0)
            {

                //没有小数点时
                if((m_iStatus >> 1 & 1) == 0)
                    {
                        m_dTemp1*=10;
                        m_dTemp1+=num;
                    }

                //有小数点时
                if((m_iStatus >> 1 & 1) == 1)
                    {
                       for(int i = 0; i < m_iPcount + 1; i++)
                           num/=10;
                       m_dTemp1+=num;
                       m_iPcount++;
                    }
            }

        //寄存器2等待输入时
        if((m_iStatus & 1) == 1)
            {

                //没有小数点时
                if((m_iStatus >> 1 & 1) == 0)
                    {
                        m_dTemp2*=10;
                        m_dTemp2+=num;
                    }

                //有小数点时
                if((m_iStatus >> 1 & 1) == 1)
                    {
                        for(int i = 0; i < m_iPcount + 1; i++)
                            num/=10;
                        m_dTemp2+=num;
                        m_iPcount++;
                    }
            }
    }

    //数字按钮初始化特判
    void m_iszero(QString num)
    {
       if(m_sShow == "0")
           {
                if(num == "0")
                    return;
                else
                   {
                    m_sShow = "";
                    m_iStatus +=4;
                    return;
                   }
           }
    }

    //符号按钮录入
    void m_inputsymbol(char sym)
    {

        //根据状态值确定寄存器1的正负并保存
        if((m_iStatus >> 3 & 1) == 1)
            {
            m_dTemp1 = 0 - m_dTemp1;
            }

        //重置状态 并且将状态第第一位改为1 开始录入寄存器2的数据
        m_cSymbol = sym;
        m_iStatus = 1;
        m_sShow = "0";
        m_iPcount = 0;
        return ;
    }

    //声明标准输出 （不在这里直接写的原因是无法读取出ui）
    void m_output();

    //根据输出调节参数状态(将m_sShow进行分析台重置状态)
    void m_tempnow(QString nowstring)
    {

        //定义小数点有无 并且临时保存小数点有无和小数点后位数
        int Pcount = 0;
        int Pflag = 0;

        //判断是否为负
        if(nowstring[0] == '-')
            {
            m_iStatus = m_iStatus | 8;
            }

        //判断小数点有无 并且数出小数点位数
        int slen = nowstring.length();
        for(int i = 0; i < slen; i++)
            {
                if(Pflag == 1)
                    Pcount++;
                if(nowstring[i] == '.')
                    Pflag = 1;
            }

        //根据小数点有无来更新状态
        if(Pflag == 1)
            m_iStatus = m_iStatus | 2;
        if(Pflag == 0)
            m_iStatus = m_iStatus & 13;

        //更新小数点后位数状态
        m_iPcount = Pcount;
    }
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::MainWindow *ui;
    double m_dTemp1, m_dTemp2;//寄存器1,寄存器2
    int m_iStatus;//第一位存寄存器位置 0为寄存器1 1为寄存器2 第二位存小数点有无 有为1 无为0 第三位存是否为第一次输入（有特殊处理）第四位记录正负
    int m_iPcount;//小数点后位数
    char m_cSymbol;//运算符种类
    QString m_sShow;//展示字符串
};

#endif // MAINWINDOW_H
