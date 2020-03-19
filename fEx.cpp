#include<string>
#include<ctime>
#include<opencv/cv.h> //download the directory
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<fstream>
using namespace std;
class LoginManager
{
public:

LoginManager()
{
accessGranted=0;
}
void Login()
{
cout<<"Enter your username.\nUsername:";
cin>>userNameAttempt;
//userName = getFile("users.dat");
if(userNameAttempt==userName)
{
cout<<"Password:";
cin>>passwordAttempt;
//password= getFile("pswds.dat");
if(passwordAttempt==password)
{
cout<<"Correct password. Here we will write the code for webcam";
using namespace cv;

string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}


    VideoCapture capture(0);

    int frame_rate = 10;

    for(int i = 0; i<4 ; i++)
    {
        time_t timer_start, timer_stop;
        Mat frame;
        stringstream recordstr;
        recordstr << "records/" << i << ".avi";
        string recordfile = recordstr.str();

        VideoWriter video(recordfile, CV_FOURCC('M', 'J', 'P', 'G'), frame_rate, Size(frame_width,frame_height), true);
        if ( !video.isOpened() )
    {
        cout << "Cannot open the video file. \n";
        return -1;
    }

    double numFrames = video.get(CV_CAP_PROP_FPS);



        time (&timer_start);
        for(double j = 0; j < numFrames; j++){
            capture >> frame;
            if(frame.empty()){
                cout << "Failed to capture an image" << endl;
                return -1;
            }
            video.write(frame);
        }
        time (&timer_stop);
        double timeDiff = difftime (timer_stop, timer_start);
        cout<<"video "<<i<<".avi stopped capturing at "<< currentDateTime() <<" & took "<<timeDiff<<" seconds"<<endl;
        sleep(60);
    }
    for(int k=0;k<numFrames;k++)
    {
          if (frame.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }
    else
    {
          Mat src=imread(frame);
Mat planes[3];
split(src,planes);
Mat blur_image;
GaussianBlur(frame,blur_image,Size(3,3),0);
String window_name = "Web_cam_window";
String window_name_blur_image = "Blur with 3*3 Gaussian Kernal";
namedWindow(window_name);
namedWindow(window_name_blur_image);
waitKey(0);
destroyAllWindows();
    }

    }


cin.get();
}
else
{
cout<<"Try something else.";
Login();
}
}
else
{
cout<<"Try again";
Login();
}
}

string getFile(const char* p_fileName)
{
string line;
fstream file;
file.open(p_fileName,ios::in);
if(file.is_open())
{
getline(file,line);
}
file.close();
return line;
}
private:
string password="Aparajita";
string userName="cu";
bool accessGranted;
string userNameAttempt;
string passwordAttempt;
};
int main()
{
LoginManager app;
app.Login();
cin.get();
}
