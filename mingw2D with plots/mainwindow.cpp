#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include "QString"
#include "vector"
#include "queue"
#include "math.h"
#include "QImage"
#include "SerialPort.h"
#include "fstream"
#include "QElapsedTimer"

using namespace cv;
using namespace std;

int dc_x=0, dc_y =0;
int errx2=0, erry2=0;
int sendx=0, sendy=0;
QElapsedTimer tim2;
qint64 nanoSec;
int sss=0;
int nn=0;
bool bx=false;
bool by=false;
bool emp = false;

double tot_x = 0;
double tot_y = 0;
double del_x = 0;
double del_y = 0;
double last_x = 0;
double last_y = 0;
double control_x = 0;
double control_y = 0;
double kpx=8.5,kix=5.0,kdx=0.23;
double kpy=8.5,kiy=5.0,kdy=0.23;
double max_control = 20000;
double min_control = 15;

Mat rois[4];

bool capped= false;
char output[11];
char incoming[11];
bool establish  = false;
bool snap = false;
int fc=0;
string fn="pic";
fstream myfile;
fstream myfile2;

int cnt =0;
QString p = "\\\\.\\COM8";
char *port = p.toLocal8Bit().data();
SerialPort arduino(port);
SerialPort *a = &arduino;

int cplot1=0,cplot2=0,cplot3=0,cplot4=0;
bool init = false;
bool re = false;
vector <vector<Point>> contours;
vector <Vec4i> hierarchy;
vector <vector<Point>> con;
vector <Point> hull;
vector <Vec4i> defects;
vector <int> inthull;
queue <Point> list;

QVector<double> tt(100), xx(100),yy(100);
QVector<double> corr_x1(100),corr_x2(100),corr_y1(100),corr_y2(100);
const int dig_limit = 50;

bool capture = false;
bool boxes =false;
cv::Mat backproj;
int l = 30;
bool project=false;
int r;
cv::Mat frame,roi,frame2;
Mat hsv[5];
cv::Mat hist,hist2;
int hbins = 30, sbins = 32;
int histSize[] = {hbins, sbins};
float hranges[] = { 0, 180 };
float sranges[] = { 0, 256 };
const float* ranges[] = { hranges, sranges };
int channels[] = {0, 1};
int errx = 0,erry=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tim2.clockType();
    tim2.start();
    VideoCapture cap;
    myfile.open("Logs.csv",ios::out);
    myfile2.open("Control logs.csv",ios::out);
    ui->setupUi(this);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    ui->label->setScaledContents(true);
    ui->label->devicePixelRatio();
    for (int i=0; i<100; i++)
    {
      tt[i]  = i;
      corr_x1[i] = 0;
      corr_y1[i] = 0;
      corr_x2[i] = 0;
      corr_y2[i] = 0;
    }

    ui->plot_x->addGraph();
    ui->plot_x->addGraph();
    ui->plot_x->graph(0)->setData(tt, corr_x1);
    ui->plot_x->graph(1)->setData(tt, corr_x2);
    ui->plot_x->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_x->graph(1)->setPen(QPen(Qt::red));
    ui->plot_x->xAxis->setLabel("time");
    ui->plot_x->yAxis->setLabel("X Response");
    ui->plot_x->xAxis->setRange(0,100);
    ui->plot_x->yAxis->setRange(-100, 100);
    ui->plot_x->replot();

    ui->plot_y->addGraph();
    ui->plot_y->addGraph();
    ui->plot_y->graph(0)->setData(tt, corr_y1);
    ui->plot_y->graph(1)->setData(tt, corr_y2);
    ui->plot_y->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_y->graph(1)->setPen(QPen(Qt::red));
    ui->plot_y->xAxis->setLabel("time");
    ui->plot_y->yAxis->setLabel("Y Response");
    ui->plot_y->xAxis->setRange(0,100);
    ui->plot_y->yAxis->setRange(-100, 100);
    ui->plot_y->replot();
}

MainWindow::~MainWindow()
{
    string ss = to_string(404);
    char * charArray2 = new char[ss.size()+2];
    charArray2[0] = 'a';
    for(uint i=0;i<ss.size();i++)
    {
        charArray2[i+1] = ss[i];
    }
    charArray2[ss.size()+1] = 'd';
    a->writeSerialPort(charArray2    ,11);
    a->writeSerialPort(charArray2    ,11);
    a->writeSerialPort(charArray2    ,11);
    delete []charArray2;
    myfile.close();
    myfile2.close();
    delete ui;
}

Mat dig_cor_x(Mat in,int x)
{
    Mat cp = Mat::zeros(Size(1,in.rows),CV_8UC3);
    Mat output1;
    in.copyTo(output1);
    if(x<0)
    {
        for(int i=0;i<in.cols-abs(x);i++)
        {
            in.col(i).copyTo(output1.col(i+abs(x)));
        }
        for(int i=0;i<abs(x);i++)
        {
            cp.copyTo(output1.col(i));
        }
    }else if(x>0)
    {
        for(int i=abs(x);i<in.cols;i++)
        {
            in.col(i).copyTo(output1.col(i-abs(x)));
        }
        for(int i=in.cols-x;i<in.cols;i++)
        {
            cp.copyTo(output1.col(i));
        }
    }else
    {

    }
    return output1;
}

Mat dig_cor_y(Mat output1, int y)
{
    Mat rp = Mat::zeros(Size(output1.cols,1),CV_8UC3);
    Mat output2;
    output1.copyTo(output2);
    if(y<0)
    {
        for(int i=0;i<output1.rows-abs(y);i++)
        {
            output1.row(i).copyTo(output2.row(i+abs(y)));
        }
        for(int i=0;i<abs(y);i++)
        {
            rp.copyTo(output2.row(i));
        }
    }else if(y>0)
    {
        for(int i=abs(y);i<output1.rows;i++)
        {
            output1.row(i).copyTo(output2.row(i-abs(y)));
        }
        for(int i=output1.rows-y;i<output1.rows;i++)
        {
            rp.copyTo(output2.row(i));
        }
    }else
    {

    }
    return output2;
}

int getMaxAreaContourId(vector <vector<Point>> contours)
{
    double maxArea = 0;
    int maxAreaContourId = -1;
    for (int j = 0; j < (int)contours.size(); j++) {
        double newArea = cv::contourArea(contours.at(j));
        if (newArea > maxArea) {
            maxArea = newArea;
            maxAreaContourId = j;
        }
    }
    return maxAreaContourId;
}

void MainWindow::on_B1_clicked()
{
    cap.open(0);
    if (cap.isOpened() == false)
    {
        qDebug() << "Camera can't open";
        return;
    }
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
    //connect(timer2, SIGNAL(timeout()), this, SLOT(plot_response()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(send()));
    timer1->start(33);
    Sleep(15);
    timer2->start(33);
}

void MainWindow::send()
{
    if((a->isConnected())&&project)
    {
        sendx=errx;
        sendy=erry;

        if(sendx==0)
        {
            sendx=404;
        }
        if(sendy==0)
        {
            sendy=404;
        }
        //if(emp)
        //{
          //  errx=700;
           // erry=700;
        //}
        string sx = to_string(sendx);
        string sy = to_string(sendy);
        char * charArray = new char[11];
        /*char * charArray = new char[s.size()+1];
        for(uint i=0;i<s.size()+1;i++)
        {
            charArray[i] = s[i];
        }
        charArray[s.size()]='a';*/

        charArray[0] = 'a';
        if(abs(sendx)<10)
        {
            if(sendx>0)
            {
                charArray[1] = '0';
                charArray[2] = '0';
                charArray[3] = '0';
                charArray[4] = sx[0];
            }else
            {
                charArray[1] = sx[0];
                charArray[2] = '0';
                charArray[3] = '0';
                charArray[4] = sx[1];
            }
        }else if(abs(sendx)<100)
        {
            if(sendx>0)
            {
                charArray[1] = '0';
                charArray[2] = '0';
                charArray[3] = sx[0];
                charArray[4] = sx[1];
            }else
            {
                charArray[1] = sx[0];
                charArray[2] = '0';
                charArray[3] = sx[1];
                charArray[4] = sx[2];
            }
        }else
        {
            if(sendx>0)
            {
                charArray[1] = '0';
                charArray[2] = sx[0];
                charArray[3] = sx[1];
                charArray[4] = sx[2];
            }else
            {
                charArray[1] = sx[0];
                charArray[2] = sx[1];
                charArray[3] = sx[2];
                charArray[4] = sx[3];
            }
        }
        charArray[5] = 'c';

        if(abs(sendy)<10)
        {
            if(sendy>0)
            {
                charArray[6] = '0';
                charArray[7] = '0';
                charArray[8] = '0';
                charArray[9] = sy[0];
            }else
            {
                charArray[6] = sy[0];
                charArray[7] = '0';
                charArray[8] = '0';
                charArray[9] = sy[1];
            }
        }else if(abs(sendy)<100)
        {
            if(sendy>0)
            {
                charArray[6] = '0';
                charArray[7] = '0';
                charArray[8] = sy[0];
                charArray[9] = sy[1];
            }else
            {
                charArray[6] = sy[0];
                charArray[7] = '0';
                charArray[8] = sy[1];
                charArray[9] = sy[2];
            }
        }else
        {
            if(sendy>0)
            {
                charArray[6] = '0';
                charArray[7] = sy[0];
                charArray[8] = sy[1];
                charArray[9] = sy[2];
            }else
            {
                charArray[6] = sy[0];
                charArray[7] = sy[1];
                charArray[8] = sy[2];
                charArray[9] = sy[3];
            }
        }
        charArray[10] = 'd';

        a->writeSerialPort(charArray,11);
        /*Sleep(9);
        tim2.restart();
        a->readSerialPort(incoming,15);
        //cout<<atoi(incoming)<<endl;
        sss++;
        if(atoi(incoming)==erry)
        {
            nn++;
            cout<<"1   "<<(float)nn/sss<<endl;
            myfile<<"1"<<endl;
        }else
        {
            cout<<"0"<<endl;
            myfile<<"0"<<endl;
        }*/
        //sss = tim2.nsecsElapsed()/1000;
        //myfile<<sss<<endl;
        ui->label_2->setText(QString::fromStdString(sy));
        delete [] charArray;
        //ui->label_2->setText("Connected");
    }
    else
    {
        ui->label_2->setText("Disconnected");
    }
    plot_response(errx2,erry2);
}

void MainWindow::plot_response(int x, int y)
{
    if(project)
    {
        tot_x += errx;
        del_x = errx - last_x;

        tot_y += erry;
        del_y = erry - last_y;


        control_x = kpx*errx + kix*tot_x*0.033 + kdx*del_x/0.033;
        if(abs(control_x)>=max_control)
        {
            if(control_x>0)
                control_x = max_control;
            else
                control_x = -max_control;
        }else if(abs(control_x)<min_control)
        {
            if(control_x>0)
                control_x = min_control;
            else
                control_x = -min_control;
        }
        //myfile2<<control_x<<","<<dc_x<<",";
        corr_x1[cplot3]=control_x/100;
        corr_x2[cplot3]=dc_x;
        cplot3++;

        last_x = errx;

        //--------------------------

        control_y = kpy*erry + kiy*tot_y*0.033 + kdy*del_y/0.033;

        if(abs(control_y)>=max_control)
        {
            if(control_y>0)
                control_y = max_control;
            else
                control_y = -max_control;

        }else if(abs(control_y)<min_control)
        {
            if(control_y>0)
                control_y = min_control;
            else
                control_y = -min_control;
        }
        //myfile2<<control_y<<","<<dc_y<<endl;
        corr_y1[cplot4]=control_y/100;
        corr_y2[cplot4]=dc_y;
        cplot4++;
        last_y = erry;

        //----------------------------------
        if(cplot3>=100)
        {
            cplot3=0;
            for(int i=0;i<100;i++)
            {
                corr_x1[i]=0;
                corr_x2[i]=0;
            }
        }

        if(cplot4>=100)
        {
            cplot4=0;
            for(int i=0;i<100;i++)
            {
                corr_y1[i]=0;
                corr_y2[i]=0;
            }
        }

        ui->plot_x->graph(0)->setData(tt, corr_x1);
        ui->plot_x->graph(1)->setData(tt, corr_x2);
        ui->plot_x->replot();

        ui->plot_y->graph(0)->setData(tt, corr_y1);
        ui->plot_y->graph(1)->setData(tt, corr_y2);
        ui->plot_y->replot();
    }

    if((ui->Butt_X->isChecked())||(ui->Butt_Y->isChecked()))
    {
        if(!init)
        {
            ui->label_4->setText("Initialize first!");
        }else
        {
            ui->label_4->setText("Recording");
            if(ui->Butt_X->isChecked())
            {
                xx[cplot1]=x;
                cplot1++;
                ui->err_plot_x->graph(0)->setData(tt, xx);
                ui->err_plot_x->replot();
                if(cplot1>=100)
                {
                    cplot1=0;
                    for(int i=0;i<100;i++)
                    {
                        xx[i]=0;
                    }
                }
                myfile<<x;
                myfile2<<control_x<<","<<dc_x;
                if(!ui->Butt_Y->isChecked())
                {
                    myfile2<<",0,0"<<endl;
                    myfile<<','<<'0'<<endl;
                }
            }

            if(ui->Butt_Y->isChecked())
            {
                yy[cplot2]=-y;
                cplot2++;
                ui->err_plot_y->graph(0)->setData(tt, yy);
                ui->err_plot_y->replot();
                if(cplot2>=100)
                {
                    cplot2=0;
                    for(int i=0;i<100;i++)
                    {
                        yy[i]=0;
                    }
                }
                if(!ui->Butt_X->isChecked())
                {
                    myfile2<<"0,0";
                    myfile<<'0';
                }
                myfile2<<","<<control_y<<","<<dc_y<<endl;
                myfile<<','<<y<<endl;
            }
        }
    }
}

void MainWindow::processFrameAndUpdateGUI()
{
    //auto start = high_resolution_clock::now();
    //tim2.restart();
    cap.read(frame);
    if (frame.empty() == true)
    {
        return;
    }

    //flip(frame,frame,0);
    //flip(frame,frame,1);
    //rotate(frame,frame,cv::ROTATE_90_CLOCKWISE);
    frame2 = frame;

    Rect rect101(frame.cols*0.8/2,frame.rows*0.8/2,frame.cols*0.2,frame.rows*0.2);
    if(capture)
    {
        capture = false;

        frame = imread("pic0.png",IMREAD_COLOR);
        roi = frame(rect101);
        cvtColor(roi,hsv[0],COLOR_BGR2HSV);
        calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );

        //Mat h = hist;
        //cv::resize(hist,h,Size(500,500));
        //namedWindow("hist",WINDOW_AUTOSIZE);
        //imshow("hist",h);

        frame = imread("pic1.png",IMREAD_COLOR);
        roi = frame(rect101);
        cvtColor(roi,hsv[0],COLOR_BGR2HSV);
        calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );

        frame = imread("pic2.png",IMREAD_COLOR);
        roi = frame(rect101);
        cvtColor(roi,hsv[0],COLOR_BGR2HSV);
        calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );

        normalize( hist, hist2, 0, 255, NORM_MINMAX, -1, Mat() );


        /*capture = false;
        //GaussianBlur(frame,frame,Size(5,5),BORDER_DEFAULT);
        roi = frame(rect101);
        //imshow("base",roi);
        roi.copyTo(rois[0]);
        roi.copyTo(rois[1]);
        roi.copyTo(rois[2]);
        roi.copyTo(rois[3]);
        for(int i=0;i<roi.cols;i++)
        {
            for(int j=0;j<roi.rows;j++)
            {
                rois[0].at<Vec3b>(j,i)[0] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[0]*0.7);
                rois[0].at<Vec3b>(j,i)[1] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[1]*0.7);
                rois[0].at<Vec3b>(j,i)[2] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[2]*0.7);
                rois[1].at<Vec3b>(j,i)[0] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[0]*0.5);
                rois[1].at<Vec3b>(j,i)[1] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[1]*0.5);
                rois[1].at<Vec3b>(j,i)[2] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[2]*0.5);
                rois[2].at<Vec3b>(j,i)[0] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[0]*1.3);
                rois[2].at<Vec3b>(j,i)[1] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[1]*1.3);
                rois[2].at<Vec3b>(j,i)[2] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[2]*1.3);
                rois[3].at<Vec3b>(j,i)[0] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[0]*1.5);
                rois[3].at<Vec3b>(j,i)[1] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[1]*1.5);
                rois[3].at<Vec3b>(j,i)[2] = saturate_cast<uchar>(roi.at<Vec3b>(j,i)[2]*1.5);
            }
        }
        //imshow("res1",rois[0]);
        //imshow("res2",rois[1]);
        //imshow("res3",rois[2]);
        //imshow("res4",rois[3]);
        cvtColor(roi,hsv[0],COLOR_BGR2HSV);
        cvtColor(rois[0],hsv[1],COLOR_BGR2HSV);
        cvtColor(rois[1],hsv[2],COLOR_BGR2HSV);
        cvtColor(rois[2],hsv[3],COLOR_BGR2HSV);
        cvtColor(rois[3],hsv[4],COLOR_BGR2HSV);
        if(re)
        {
            re=false;
            calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, false);
        }else
        {
            //calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            //calcHist( &hsv[1], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            //calcHist( &hsv[2], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            //calcHist( &hsv[3], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            //calcHist( &hsv[4], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            //calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
            calcHist( &hsv[0], 1, channels, Mat(), hist, 2, histSize, ranges, true, true );
        }
        normalize( hist, hist2, 0, 255, NORM_MINMAX, -1, Mat() );*/
        //Mat h = hist;
        //cv::resize(h,h,Size(500,500));
        //namedWindow("hist",WINDOW_AUTOSIZE);
        //imshow("hist",h);
        //imwrite("Hist.png",h);
    }
    if(project)
    {
        cvtColor(frame,hsv[0],COLOR_BGR2HSV);
        calcBackProject( &hsv[0], 1, channels, hist2, frame, ranges, 1, true );
        //morphologyEx(frame,frame,MORPH_ERODE,getStructuringElement(MORPH_RECT,Size(3,3)),Point(-1,-1),2,BORDER_DEFAULT);
        //morphologyEx(frame,frame,MORPH_CLOSE,getStructuringElement(MORPH_RECT,Size(3,3)),Point(-1,-1),2,BORDER_DEFAULT);
        Mat disc = getStructuringElement(MORPH_ELLIPSE,Size(15,15));
        filter2D(frame,frame,-1,disc);
        Mat thresh;
        threshold(frame,thresh,170,255,THRESH_BINARY);
        Mat c[3]= {thresh,thresh,thresh};
        merge(c,3,thresh);
        bitwise_and(frame2,thresh,frame);
        con.clear();
        contours.clear();
        Mat gray;
        cvtColor(frame,gray,COLOR_BGR2GRAY);
        findContours(gray,contours,hierarchy,RETR_LIST,CHAIN_APPROX_SIMPLE);
        if((!contours.empty())&&(contourArea(contours.at(getMaxAreaContourId(contours)))>6000))
        {
            con.push_back(contours.at(getMaxAreaContourId(contours)));
            approxPolyDP(con.at(0),con.at(0),3,true);
            frame = frame2;
            Mat blank(frame.rows,frame.cols,CV_8UC3,Scalar(0,0,0));
            drawContours(blank,con,0,Scalar(255,255,255),FILLED,LINE_8,hierarchy,0,Point(0));
            cvtColor(blank,blank,COLOR_BGR2GRAY);
            threshold(blank,blank,128,255,THRESH_BINARY);
            int sumx=0,sumy=0,n=0;
            for(int i=0;i<blank.rows;i++)
            {
                for(int j=0;j<blank.cols;j++)
                {
                    if(blank.at<bool>(i,j)==true)
                    {
                        sumx=sumx+j;
                        sumy=sumy+i;
                        n++;
                    }
                }
            }
            if(n==0)
            {
                n=1;
            }
            sumx = sumx/n;
            sumy = sumy/n;
            errx = sumx - frame.cols/2;
            erry= sumy - frame.rows/2;
            errx2=errx;
            erry2=erry;
            circle(frame,Point(sumx,sumy),7,Scalar(255,0,0),FILLED,LINE_8);
            convexHull(con.at(0),hull   ,false,false);
            convexHull(con.at(0),inthull,false,false);
            con.push_back(hull);
            drawContours(frame,con,0,Scalar(255,0,0),2,LINE_8,hierarchy,0,Point(0));
            bx=false;
            by=false;

            if((ui->Corr_X->isChecked())&&(!ui->Corr_Y->isChecked()))
            {
                if(abs(errx)>dig_limit)
                {
                    if(errx<=0)
                    {
                        errx2=errx+dig_limit;
                        dc_x = dig_limit;
                    }else
                    {
                        errx2=errx-dig_limit;
                        dc_x = -dig_limit;
                    }
                    frame = dig_cor_x(frame,dig_limit);
                }else
                {
                    errx2=0;
                    dc_x=-errx;
                    frame = dig_cor_x(frame,errx);
                }
                bx=true;
            }

            if((ui->Corr_Y->isChecked())&&(!ui->Corr_X->isChecked()))
            {
                if(abs(erry)>dig_limit)
                {
                    if(erry<=0)
                    {
                        erry2=erry+dig_limit;
                        dc_y=dig_limit;
                    }else
                    {
                        erry2=erry-dig_limit;
                        dc_y=-dig_limit;
                    }
                    frame = dig_cor_y(frame,dig_limit);
                }else
                {
                    erry2=0;
                    dc_y=-erry;
                    frame = dig_cor_y(frame,erry);
                }
                by=true;
            }

            if((ui->Corr_X->isChecked())&&(ui->Corr_Y->isChecked()))
            {
                if(sqrt(errx*errx+erry*erry)>dig_limit)
                {
                    erry2= erry-erry*dig_limit/sqrt(errx*errx+erry*erry);
                    dc_y = -erry*dig_limit/sqrt(errx*errx+erry*erry);

                    errx2= errx-errx*dig_limit/sqrt(errx*errx+erry*erry);
                    dc_x= -errx*dig_limit/sqrt(errx*errx+erry*erry);

                    frame = dig_cor_y(frame,-dc_y);
                    frame = dig_cor_x(frame,-dc_x);
                }else
                {
                    errx2= 0;
                    erry2= 0;
                    dc_x = -errx;
                    dc_y = -erry;
                    frame = dig_cor_y(frame,erry);
                    frame = dig_cor_x(frame,errx);
                }
                bx=true;
                by=true;
            }
            statusBar()->showMessage("Working");
        }else
        {
            frame = frame2;
            statusBar()->showMessage("empty");
        }
    }

    cvtColor(frame,frame,COLOR_BGR2RGB);

    if(snap)
    {
        snap=false;
        fn="pic";
        fn.append(to_string(fc));
        fn.append(".png");
        fc++;
        cvtColor(frame, frame, COLOR_BGR2RGB);
        imwrite(fn,frame);
    }

    if(boxes)
    {
        rectangle(frame, rect101, Scalar(0,0,255),2,8,0);
    }



    QImage qOriginalImage((const uchar*)frame.data, frame.cols,frame.rows,frame.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qOriginalImage));
}

void MainWindow::on_pause_clicked()
{
    if(project)
        project = false;
    else
        if(capped)
        {
            project = true;
        }
}

void MainWindow::on_effect_clicked()
{
    capture = true;
    capped =true;
}

void MainWindow::on_pushButton_clicked()
{
    if(boxes)
    {
        boxes=false;
    }else
    {
        boxes=true;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    establish = true;
    QString p = "\\\\.\\COM";
    p.append(ui->lineEdit->text());
    port = p.toLocal8Bit().data();
    SerialPort arduino(port);
    a = &arduino;
    if(a->isConnected())
    {
        ui->label_2->setText("Connected");
    }else
    {
        establish = false;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    re=true;
}

void MainWindow::on_pushButton_4_clicked()
{
    snap=true;
}

void MainWindow::on_pushButton_6_clicked()
{
    init = true;
    for (int i=0; i<100; i++)
    {
      xx[i] = 0;
      yy[i] = 0;
    }
    ui->err_plot_x->addGraph();
    ui->err_plot_x->graph(0)->setData(tt, xx);
    ui->err_plot_x->xAxis->setLabel("time");
    ui->err_plot_x->yAxis->setLabel("X Error");
    ui->err_plot_x->xAxis->setRange(0,100);
    ui->err_plot_x->yAxis->setRange(-330, 330);
    ui->err_plot_x->replot();

    ui->err_plot_y->addGraph();
    ui->err_plot_y->graph(0)->setData(tt, xx);
    ui->err_plot_y->xAxis->setLabel("time");
    ui->err_plot_y->yAxis->setLabel("Y Error");
    ui->err_plot_y->xAxis->setRange(0,100);
    ui->err_plot_y->yAxis->setRange(-250, 250);
    ui->err_plot_y->replot();
}

void MainWindow::on_pushButton_5_clicked()
{

}
