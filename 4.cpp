#include <iostream>
#include <cmath>
using namespace std;

class drone
{
protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    drone(float latitude, float longitude, float altitude, float speed)
    {
        this->latitude = latitude;
        this->longitude = longitude;
        this->altitude = altitude;
        this->speed = speed;
    }
    virtual void adjustAltitude(float meters) = 0;

    virtual void setSpeed(float speed) = 0;
};
class flyable
{
public:
    virtual void takeoff(float altitude, float speed, float longitude, float latitude) = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class scannable
{
public:
    virtual void scanArea(float radius) = 0;
};

class recondrone : public flyable, public scannable, public drone
{
    float cameraresolution;
    float maxflighttime;

public:
    recondrone(float latitude, float longitude, float altitude, float speed, float cameraresolution, float maxflighttime) : drone(latitude, longitude, altitude, speed)
    {
        this->cameraresolution = cameraresolution;
        this->maxflighttime = maxflighttime;
    }
    void setlatitude(float latitude)
    {
        this->latitude = latitude;
    }
    void setlongitude(float longitude)
    {
        this->longitude = longitude;
    }
    void setSpeed(float speed)
    {
        try
        {
            if (speed < 0)
            {
                throw invalid_argument("Invalid speed");
            }
            else
            {
                this->speed = speed;
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void adjustAltitude(float meters) override
    {
        try
        {
            if (meters < 0)
            {
                throw invalid_argument("Invalid altitude");
            }
            else
            {
                this->altitude += meters;
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

    void takeoff(float altitude, float speed, float longitude, float latitude) override
    {
        cout << "Takingoff" << endl;
        adjustAltitude(altitude);
        setSpeed(speed);
        setlongitude(longitude);
        setlatitude(latitude);
        cout << "altitude:" << altitude << endl;
        cout << "speed:" << speed << endl;
        cout << "longitude:" << longitude << endl;
        cout << "latitude:" << latitude << endl;
    }
    void land() override
    {
        cout << "landing" << endl;
        altitude = 0;
        speed = 0;
        longitude = 0;
        latitude = 0;
        cout << "altitude:" << altitude << endl;
        cout << "speed:" << speed << endl;
        cout << "longitude:" << longitude << endl;
        cout << "latitude:" << latitude << endl;
    }
    void navigateTo(float latitude, float longitude, float altitude) override
    {
        double distance;
        distance = sqrt(pow(longitude - this->longitude, 2) + pow(altitude - this->altitude, 2));
        cout << "distance left:" << distance << endl;
        float time;
        time = distance / speed;
        cout << "time to reach target:" << time << endl;
    }
    void scanArea(float radius) override
    {
        int num;
        srand(time(NULL));
        try
        {
            num = rand() % 10;
            if ((num == 0))
            {
                throw runtime_error("signal lost");
            }
            else
            {
                if (radius == 0)
                {
                    throw invalid_argument("drone crashed");
                }
                else
                {
                    int num = rand() % 10 + 1;
                    cout << "number of objects in our way:" << num << endl;
                    for (int i = 0; i < num; i++)
                    {
                        cout << "Coordinates of object no. " << i+1 << endl;
                        cout << "latitude:" << abs((latitude + (rand() % 20)) - radius) << endl;
                        cout << "longitude:" << abs((longitude + (rand() % 20)) - radius) << endl;
                        cout << "altitude:" << abs((altitude + (rand() % 20)) - radius) << endl;
                        cout<<endl;
                    }
                }
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
};
int main()
{
    recondrone d1(0, 0, 0, 0, 1080, 3600);

    d1.takeoff(300, 200, 100, 100);
    cout << endl;
    cout << "______________________________________________________________" << endl;
    d1.navigateTo(200, 200, 300);
    cout << endl;
    cout << "______________________________________________________________" << endl;
    d1.scanArea(100);
    cout << endl;
    cout << "______________________________________________________________" << endl;
    d1.land();
    cout << endl;
    cout << "______________________________________________________________" << endl;

    return 0;
}
