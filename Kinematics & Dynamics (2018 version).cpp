#include<iostream>
#include<cmath>
#include<iomanip>
#include<sstream>
#include <limits>
#include <stdexcept>
using namespace std;

void cinfix()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double quadratic1(double a, double b, double c)
{
    double x1,x2,test;
    test = (b*b)- 4 * a * c;
    if (test >=0)
    {
        x1 = ((-b + sqrt(test))/(2*a));
        x2 = ((-b - sqrt(test))/(2*a));
    }
    else
        cout << "ERROR: No real roots." << endl;

    return x1;
}
double quadratic2(double a, double b, double c)
{
    double x1,x2,test;
    test = (b*b)- 4 * a * c;
    if (test >=0)
    {
        x1 = ((-b + sqrt(test))/(2*a));
        x2 = ((-b - sqrt(test))/(2*a));
    }
    else
        cout << "ERROR: No real roots." << endl;

    return x2;
}
// Resolves forces in x and y components.
double force_resolver(int numforces, double force[], bool flag[], double &w, double &ff)
{
    const double pi = 3.14159265;
    double angle, degree;

    if (flag[2] == false)
    {
        cout << "Enter weight: ";
        cin >> w;
        while (cin.fail() || w <= 0)
        {
            cinfix();
            if (w <= 0)
            {
                cout << "Error: Weight cannot be negative or zero." << endl;
            }
            else
            {
                cout << "Error: Invalid Input." << endl;
            }
            cout << "Enter Weight: ";
            cin >> w;
        }
    }

    if (flag[4] == false)
    {
        cout << "Enter friction force: ";
        cin >> ff;
        while (cin.fail())
        {
            cinfix();
            cout << "Error: Invalid Input." << endl;
            cout << "Enter friction force: ";
            cin >> ff;
        }
    }
    int x = 1;
    if (ff != 0)
    {
        x++;
    }

    for (int z = x; z <= numforces; z++)
    {
        cout << "Enter force " << x << " magnitude: ";
        cin >> force[0];
        while (cin.fail())
        {
            cinfix();
            cout << "Error: Invalid Input." << endl;
            cout << "Enter force " << x << " magnitude: ";
            cin >> force[0];
        }
        cout << "Enter force " << x << " angle from the +ve x axis: ";
        cin >> degree;
        while (cin.fail() || degree > 360 || degree < -360)
        {
            cinfix();
            if (degree > 360 || degree < -360)
            {
                cout << "Error: Angle out of range. (Angle must be -360 < q < 360) ";
            }
            else
            {
                cout << "Error: Invalid Input." << endl;
            }
            cout << "Enter force " << x << " angle from the +ve x axis: ";
            cin >> degree;
        }
        angle = degree * pi /180;
        force[1] = force[1] + force[0]*cos(angle);
        force[2] = force[2] + force[0]*sin(angle);
    }
    cout << force[2] << endl << endl << endl;
    force[1] = force[1] - ff;
    return force[1];
}
// finds the variables of motion in 2D.
double eqs_of_motion_1D (bool check[], double v[], double u[], double t[], double s[], double a[], double &q)
{

    for (int x = 1; x<=5; x++)
    {


        if (check[0] == true && check[1] == true && check[3] == true)
        {
            a[1] = (pow(v[1],2)-pow(u[1],2)) / (-2*s[1]);
            a[2] = (pow(v[2],2)-pow(u[2],2)) / (-2*s[2]);
            check[4] = true;
        }

        if (check[0] == true && check[1] == true && check[2] == true)
        {
            a[1] = (v[1]-u[1])/t[0];
            a[2] = (v[2]-u[2])/t[0];
            check[4] = true;
        }

        if (check[2] == true && check[1] == true && check[3] == true)
        {
            a[1] = (2*(s[1]-(u[1]*t[0]))) / pow(t[0],2);
            a[2] = (2*(s[2]-(u[2]*t[0]))) / pow(t[0],2);
            check[4] = true;
        }

        if (check[4] == true && check[1] == true && check[3] == true)
        {
            v[1] = sqrt(pow(u[1],2)+(2*a[1]*s[1]));
            v[2] = sqrt(pow(u[2],2)+(2*a[2]*s[2]));
            check[0] = true;
        }

        if (check[4] == true && check[1] == true && check[2] == true)
        {   v[1] = u[1] + (a[1]*t[0]);
            v[2] = u[2] + (a[2]*t[0]);
            check[0] = true;
        }

        if (check[2] == true && check[1] == true && check[3] == true)
        {
            v[1] = ((2*s[1])/t[0])-u[1];
            v[2] = ((2*s[2])/t[0])-u[2];
            check[0] = true;
        }

        if (check[4] == true && check[0] == true && check[3] == true)
        {
            u[1] = sqrt(pow(v[1],2)-(2*a[1]*s[1]));
            u[2] = sqrt(pow(v[2],2)-(2*a[2]*s[2]));
            check[1] = true;
        }

        if (check[4] == true && check[0] == true && check[2] == true)
        {
            u[1] = v[1] - (a[1]*t[0]);
            u[2] = v[2] - (a[2]*t[0]);
            check[1] = true;
        }

        if (check[2] == true && check[0] == true && check[3] == true)
        {
            u[1] = ((2*s[1])/t[0])-v[1];
            u[2] = ((2*s[2])/t[0])-v[2];
            check[1] = true;
        }

        if (check[2] == true && check[4] == true && check[3] == true)
        {
            u[1] = (s[1]-(0.5*a[1]*pow(t[0],2)))/t[0];
            u[2] = (s[2]-((a[2]*pow(t[0],2))/2))/t[0];
            check[1] = true;
        }

        if (check[4] == true && check[0] == true && check[1] == true)
        {
            if (a[1]!=0){s[1] = (pow(v[1],2) - pow(u[1],2))/(2*a[1]);}
            else{s[1]=u[1]*t[0];}
            if (a[2]!=0){s[2] = (pow(v[2],2)- pow(u[2],2))/(2*a[2]);}
            else{s[2]=u[2]*t[0];}
            check[3] = true;
        }

        if (check[2] == true && check[0] == true && check[1] == true)
        {
            s[1] = 0.5*(v[1]+u[1])*t[0];
            s[2] = 0.5*(v[2]+u[2])*t[0];
            check[3] = true;
        }

        if (check[2] == true && check[4] == true && check[1] == true)
        {
            s[1] = (u[1]*t[0]) + (0.5 * a[1] * pow(t[0],2));
            s[2] = (u[2]*t[0]) + (0.5*a[2]*pow(t[0],2));
            check[3] = true;
        }


        if (check[3] == true && check[0] == true && check[1] == true)
        {
            t[0] = s[1]/(0.5*(v[1]+u[1]));
            check[2] = true;
        }

        if (check[3] == true && check[4] == true && check[1] == true)
        {
            t[0] = quadratic1((0.5*a[1]),u[1],-s[1]);
            check[2] = true;
            t[1] = quadratic2((0.5*a[1]),u[1],-s[1]);
        }

        if (check[4] == true && check[0] == true && check[1] == true)
        {
            if (a[1]!=0){t[0] = (v[1]-u[1])/a[1]; check[2] = true;}
            else{t[0]= 0 ;}
        }

    }
    if (check[4]==true)
    {
        return a[1];
    }
}
// Finds the variables if the motion is a projectile.
double projectile(bool check[], double v[], double u[], double &q)
{
    const double g = 9.80665;
    if (check[0] == true)
    {
        int h = (pow(v[2],2))/(2*g);
        cout << "Max Height: " << h << endl;
    }

    if (check[1] == true)
    {
        int t_hp = u[2]/g;
        int t_flight = 2 * t_hp;
        int d = (pow(u[0],2)*sin(2*q))/g;
        cout << "Time at Max Height: " << t_hp << endl;
        cout << "Time of Flight: " << t_flight << endl;
        cout << "Range of the Flight: " << d << endl;
    }
}
// Main function for kinematics motion.
bool Kinematics(double a[], bool &a_check)
{
    const double pi = 3.14159265;
    double v[3] = {0, 0, 0}, u[3] = {0, 0, 0}, t[2] = {0, 0}, s[3] = {0, 0, 0}, q, q2;
    int nk_var, nu_var;
    bool check[5], checker_q = false;
    check[0]= false;
    check[1]= false;
    check[2]= false;
    check[3]= false;

    if (a_check == false)
    {
        check[4]= false;
    }
    else
    {
        check[4] == true;
    }
    string temp, word_unknown = "", word_known = "";
    char answer;
    cout << setw(45) << "KINEMATICS" << endl;
    cout << "\nNumber of known variables: ";
    cin >> nk_var;
    while (cin.fail() || nk_var > 6)
    {
        cinfix();
        if (nk_var > 6)
        {
            cout << "Error: Number of known variables cannot exceed 6." << endl;
        }
        else
        {
            cout << "Error: Invalid input." << endl;
        }
        cout << "Re-enter number of known variables: ";
        cin >> nk_var;
    }
    char known[nk_var];
    /*cout << "Number of unknown variables: ";
    cin >> nu_var;
    char unknown[nu_var];*/
    cout << "\n1. Acceleration (a)      2. Initial Velocity (u)\n3. Final Velocity (v)    4. Displacement (s)" << endl;
    cout << "5. Time (t)              6. Angle (Q)" << endl;
    cout << "\nEnter the known variable's symbols (shown in brackets);" << endl;
    for (int x = 1; x<=nk_var; x++)
    {
        cout << "Known variable " << x << ": ";
        cin >> temp;
        while(temp != "s" && temp != "u" && temp != "t" && temp != "a" && temp != "v" && temp != "q")
        {
            cinfix();
            cout << endl << "Error: Invalid Input. Please choose a correct symbol.\nKnown Variable " << x << ": " ;
            cin >> temp;
        }
        known[x-1]=temp[0];
        word_known = word_known + temp;
    }
    /*for (int x = 1; x<=nu_var; x++)
    {
        cout << "Unknown variable " << x << ": ";
        cin >> temp;
        unknown[x-1]=temp[0];
        word_unknown = word_unknown + temp;
    }*/
    for (int x = 0; x < word_known.length(); x++)
    {
        if (known[x] == 'q')
        {
            cout << "Enter angle (q) of velocity: ";
            cin >> q;
            while (cin.fail() || q > 360 || q < -360)
            {
                cinfix();
                if (q > 360 || q < -360)
                {
                    cout << "Error: Angle out of range. (Q must be -360 < q < 360) ";
                }
                else
                {
                    cout << "Error: Invalid Input." << endl;
                }
                cout << "Enter angle (q) of velocity: ";
                cin >> q;
            }
            checker_q = true;
            q = q * pi /180;

        }
        if (known[x] == 'v')
        {
            cout << "Enter final velocity (v): ";
            cin >> v[0];
            while (cin.fail())
            {
                cinfix();
                cout << "Error: Invalid input." << endl;
                cout << "Enter final velocity (v): ";
                cin >> v[0];
            }
            check[0] = true;
        }
        if (known[x] == 'u')
        {
            cout << "Enter initial velocity (u): ";
            cin >> u[0];
            while (cin.fail())
            {
                cinfix();
                cout << "Error: Invalid input." << endl;
                cout << "Enter initial velocity (u): ";
                cin >> u[0];
            }
            check[1] = true;
        }
        if (known[x] == 't')
        {
            cout << "Enter time (t): ";
            cin >> t[0];
            while (cin.fail() || t < 0)
            {
                cinfix();
                if (t < 0)
                {
                    cout << "Error: Time cannot be negative.";
                }
                else
                {
                    cout << "Error: Invalid input." << endl;
                }

                cout << "Enter time (t): ";
                cin >> t[0];
            }
            check[2] = true;
        }
        if (known[x] == 's')
        {
            cout << "Enter displacement (s): ";
            cin >> s[0];
            while (cin.fail())
            {
                cinfix();
                cout << "Error: Invalid input." << endl;
                cout << "Enter displacement (s): ";
                cin >> s[0];
            }
            check[3] = true;
        }
        if (known[x] == 'a')
        {
            cout << "Enter net acceleration (a): ";
            cin >> a[0];
            while (cin.fail())
            {
                cinfix();
                cout << "Error: Invalid input." << endl;
                cout << "Enter net acceleration (a): ";
                cin >> a[0];
            }
            cout << "Enter its angle from +ve x axis (0 for 1D motion): ";
            cin >> q2;
            while (cin.fail() || q2 > 360 || q2 < -360)
            {
                cinfix();
                if (q2 > 360 || q2 < -360)
                {
                    cout << "Error: Angle out of range. (Q must be -360 < q < 360) ";
                }
                else
                {
                    cout << "Error: Invalid Input." << endl;
                }
                cout << "Enter angle (q) of acceleration: ";
                cin >> q2;
            }
            q2 = q2 * pi/180;
            check[4] = true;
        }
    }
    if (checker_q == false && check[0] == true)
    {
        v[1] = v[0];
    }
    if (checker_q == false && check[1] == true)
    {
        u[1] = u[0];
    }
    if (checker_q == false && check[3] == true)
    {
        s[1] = s[0];
    }
    if (checker_q == false && check[4] == true)
    {
        a[1] = a[0];
    }
    if (check[0] == true && checker_q == true)
    {
        v[1] = v[0]*cos(q);
        v[2] = v[0]*sin(q);
    }
    if (check[1] == true && checker_q == true)
    {
        u[1] = u[0]*cos(q);
        u[2] = u[0]*sin(q);
    }
    if (check[3] == true && checker_q == true)
    {
        s[1] = s[0]*cos(q);
        s[2]= s[0]*sin(q);
    }
    if (check[4] == true && checker_q == true)
    {
        a[1] = a[0]*cos(q2);
        a[2] = a[0]*sin(q2);
    }

    eqs_of_motion_1D(check, v, u, t, s, a, q);

    cout << "Is it a projectile motion? Y/N" << endl;
    cin >> answer;
    while (cin.fail() || (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'))
    {
        cinfix();
        cout << "Error: Invalid response.\nEnter 'Y' for Yes or 'N' for No: ";
        cin >> answer;
    }
    cout << endl << endl;
    if (check[0]==true)
    {
        cout << "X-Velocity at t = " << t[0] << ": " << v[1] << endl << "Y-Velocity at t = " << t[0] << ": " << v[2] << endl;
    }
    if (check[1]==true)
    {
        cout << "X-Initial Velocity: " << u[1] << endl << "Y-Initial Velocity: " << u[2] << endl;
    }
    if (check[2]==true)
    {
        cout << "Time 1: " << t[0] << endl << "Time 2: " << t[1] << endl;
    }
    if (check[3]==true)
    {
        cout << "X-Displacement at t = " << t[0] << ": " << s[1] << endl << "Y-Displacement at t = " << t[0] << ": " << s[2] << endl;
    }
    if (check[4]==true)
    {
        cout << "X-Acceleration: " << a[1] << endl << "Y-Acceleration: " << a[2] << endl;
    }
    if (answer == 'Y' || answer == 'y')
    {
        projectile(check, v, u, q);
    }

    return check[4];
}
// Main function for dynamics of the particle.
bool dynamics(double a[], bool &a_check)
{
    int knownforces, answer2;
    double w = 0, u = 0 , m = 0, q = 0, N = 0, ff = 0;
    const double pi = 3.14159265;
    double const g = 9.81;
    double force[3] = {0, 0, 0};
    char answer;
    bool flag[5] = {false, false, false, false, false};

    if (a_check == true)
    {
        flag[1] = true;
    }
    string word_known = "", temp;
    cout << "\n1. Force (f)                2. Mass (w)\n3. Inclination Angle (q)    4. Acceleration(a)" << endl;
    cout << "5. Friction Co-efficient (u) " << endl << endl;
    cout << "Enter NUMBER of known variables in the list above: ";
    int nk_var;
    cin >> nk_var;
    while (cin.fail() || nk_var > 6)
    {
        cinfix();
        if (nk_var > 6)
        {
            cout << "Error: Number of known variables cannot exceed 6." << endl;
        }
        else
        {
            cout << "Error: Invalid input." << endl;
        }
        cout << "Re-enter number of known variables: ";
        cin >> nk_var;
    }
    cout << "Enter the symbols of the variables known from the list above. " << endl;
    for (int x = 1; x<=nk_var; x++)
    {
        cout << "Known variable " << x << ": ";
        cin >> temp;
        while(temp != "f" && temp != "a" && temp != "m" && temp != "q" && temp != "u")
        {
            cinfix();
            cout << endl << "Error: Invalid Input. Please choose a correct symbol.\nKnown Variable " << x << ": " ;
            cin >> temp;
        }
        word_known = word_known + temp;
    }

    for (int x = 0; x < word_known.length(); x++)
    {
        if (word_known[x] == 'f')
        {
            flag[0] = true;
        }

        if (word_known[x] == 'a')
        {
            flag[1] = true;
        }

        if (word_known[x] == 'm')
        {
            flag[2] = true;
            cout << "Enter mass: ";
            cin >> m;
            while (cin.fail() || m <= 0)
            {
                cinfix();
                if (m <= 0)
                {
                    cout << "Error: Mass cannot be negative or zero." << endl;
                }
                else
                {
                    cout << "Error: Invalid Input." << endl;
                }
                cout << "Enter Mass: ";
                cin >> m;
            }
        }

        if (word_known[x] == 'q')
        {
            flag[3] = true;
            cout << "Enter inclination angle: ";
            cin >> q;
            while (cin.fail() || q > 360 || q < -360)
            {
                cinfix();
                if (q > 360 || q < -360)
                {
                    cout << "Error: Angle out of range. (Q must be -360 < q < 360) ";
                }
                else
                {
                    cout << "Error: Invalid Input." << endl;
                }
                cout << "Enter angle of inclination: ";
                cin >> q;
            }
            q = q * pi /180;
        }

        if (word_known[x] == 'u')
        {
            flag[4] = true;
            cout << "Enter friction co-efficient: ";
            cin >> u;
            while (cin.fail() || u >= 1)
            {
                cinfix();
                if (u >= 1)
                {
                    cout << "Error: Friction co-efficient cannot be greater or equal to 1." << endl;
                }
                else
                {
                    cout << "Error: Invalid input." << endl;
                }
                cout << "Enter friction co-efficient: ";
                cin >> u;
            }
        }
    }
    int counter_w = 0;
    int count_f = 0;
    int counter = 0;

    if (flag[0] == true)
    {
        cout << "Enter number of known forces acting on the object: ";
        cin >> knownforces;
        while (cin.fail() || knownforces < 0)
        {
            cinfix();
            if (knownforces < 0)
            {
                cout << "Error: Number of forces cannot be negative." << endl;
            }
            else
            {
                cout << "Error: Invalid input." << endl;
            }
            cout << "Enter friction co-efficient: ";
            cin >> knownforces;
        }
        force_resolver(knownforces, force, flag, w, ff);
    }

    for (int x = 1; x<=5; x++)
    {

        if (counter == 0 && x>3 && flag[0] == true)
        {
            //cout << "Enter number of unknown forces: ";
            //cin >> unknownforces;

            cout << "Is the object in equilibrium?\nYes = 1\nNo = 2\nDon't know = 3\n>> ";
            cin >> answer2;
            while (cin.fail() || (answer2 != 1 && answer2 != 2 && answer2 != 3))
            {
                cinfix();
                if (answer2 != 1 && answer2 != 2 && answer != 3)
                {
                    cout << "Error: Input 1, 2 or 3 ONLY." << endl;
                }
                else
                {
                    cout << "Error: Invalid input." << endl;
                }
                cout << "Is the object in equilibrium?\nYes = 1\nNo = 2\nDon't know = 3\n>> ";
                cin >> answer2;
            }
                switch(answer2)
                {
                    cout << endl;
                    case 1:
                        if (force[1] != 0 || force[2] != 0)
                        {
                            cout << "There must be an unknown force;" << endl;
                            cout << "Horizontal-x component of the unknown force: " << -force[1] << endl;
                            cout << "Vertical-y component of the unknown force: " << -force[2] << endl;
                            double q_force;
                            cout << "Magnitude of Force: " << sqrt(pow(force[1],2) + pow(force[2],2))<< endl;
                            cout << "Angle of Force: " << atan(force[2]/force[1]) * (180/pi) << endl;
                            force[1] = 0;
                            force[2] = 0;
                        }
                        break;

                    case 2:
                        cout << endl;
                        break;

                    case 3:
                        if (force[1] != 0 || force[2] != 0)
                        {
                            cout << "The particle is not in equilibrium." << endl;
                        }
                        else{cout << "The particle is in equilibrium." << endl;}
                        break;
                }

            counter++;
        }

        if (flag[2] == true)
        {
            w = m * g;
            if (flag[3] == true)
            {
                double y_w = w * cos(q);
                double x_w = w * sin(q);
                if(counter_w <=0)
                {
                    N = w*cos(q) - force[2];
                    force[1] = force[1] + x_w;
                    force[2] = force[2] - y_w + N;
                    counter_w++;
                }
            }
            else
            {
                if(counter_w <=0)
                {
                    N = w - force[2];
                    force[2] = force[2] - w + N;
                    counter_w++;
                }
            }
            flag[0] = true;
        }
        if (flag[4] == true && flag[2] == true)
        {
            ff = u*N;
            if (count_f <=0){force[1] = force[1] - ff; count_f++;}
        }
        if (flag[0] == true && flag[2] == true)
        {
            a[1] = force[1]/m;
            a[2] = force[2]/m;
            flag[1] = true;
        }
        if (flag[0] == true && flag[1] == true)
        {
            if (a[1]!=0){m = force[1]/a[1];}
            if (a[2]!=0){m = force[2]/a[2];}
        }
        if (flag[1] == true && flag[2] == true)
        {
            force[1] = m * a[1];
            force[2] = m * a[2];
        }
    }
    cout << endl << endl;
    cout << "Resultant Force X = " << force[1] <<endl;
    cout << "Resultant Force Y = " << force[2] <<endl;
    cout << "acceleration X = " << a[1] <<endl;
    cout << "acceleration Y = " << a[2] <<endl;
    cout << "Weight = " << w << endl;
    cout << "Normal Force = " << N << endl;
    cout << "Friction force = " << ff << endl;

    return flag[1];
}

int main()
{
    char answer;
    do
    {
        bool a_check = false;
        double a[3];
        cout << "PHYSICS - KINEMATICS & DYNAMICS" << endl<< endl;
        int reply;
        cout << "Enter;\n1 for Kinematics\n2 for Dynamics\n>> ";
        cin >> reply;
        while (cin.fail() || (reply != 1 && reply != 2))
        {
            cinfix();
            if (reply != 1 && reply != 2)
            {
                cout << "Error: Input 1 OR 2 ONLY." << endl;
            }
            else
            {
                cout << "Error: Invalid input." << endl;
            }
            cout << "Enter;\n1 for Kinematics\n2 for Dynamics\n>> ";
            cin >> reply;
        }
        cout << endl;
        if (reply == 1)
        {
            a_check = Kinematics(a, a_check);
            cout << "Do you want to proceed with Dynamics? Y/N\n>> ";
            cin >> answer;
            while (cin.fail() || (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'))
            {
                cinfix();
                cout << "Error: Invalid response.\nEnter 'Y' for Yes or 'N' for No: ";
                cin >> answer;
            }
            if (answer == 'y' || answer == 'Y')
            {
                dynamics(a, a_check);
            }
        }
        else if (reply == 2)
        {
            a_check = dynamics(a, a_check);
            cout << "Do you want to proceed with Kinematics? Y/N\n>> ";
            cin >> answer;
            while (cin.fail() || (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'))
            {
                cinfix();
                cout << "Error: Invalid response.\nEnter 'Y' for Yes or 'N' for No: ";
                cin >> answer;
            }
            if (answer == 'y' || answer == 'Y')
            {
                Kinematics(a, a_check);
            }
        }
        cout << endl << endl;
        cout << "Do you want to go to main menu? Y/N\n>>";
        cin >> answer;
    }
    while (answer == 'y' || answer == 'Y');
    if (answer == 'N' || answer == 'n')
    {
        cout << endl << "GOODBYE!" << endl;
    }
}

