#include<iostream>
#include<iomanip>
#include<sstream>
#include <limits>
#include<string>
#include<vector>
#include <cmath>
#include <exception>
#include <map>
#include <list>
#include <set>
#include "kine.hpp"

void cinfix()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<double> quadratic(double a, double b, double c)
{
    std::vector<double> x;
    double test;
    test = (b*b) - 4 * a * c;
    if (test >= 0)
    {
        x.push_back((-b + sqrt(test)) / (2*a));
        x.push_back((-b - sqrt(test)) / (2*a));
    }
    else{
        std::cout << "ERROR: No real roots." << std::endl;
    }

    return x;
}

void print_vec(std::vector<double> vec){
    std::cout << "(";
    for(unsigned int x = 0; x < vec.size(); x++){
        if(x < vec.size() - 1){
            std::cout << vec.at(x) << ", ";
        }
        else{
            std::cout << vec.at(x);
        }
    }
    std:: cout << ")";
}

void check_nan(std::vector<double> &vec){
    for(unsigned int x = 0; x < vec.size(); x++){
        if(std::isnan(vec[x])){
            vec[x] = 0;
        }
    }
}

//Force Functions

Force::Force(){
    for (int x = 0; x < 3; x++){
        force.push_back(0);
    }
}
void Force::define_force(double x, double y, double z){
    force[0] = x;
    force[1] = y;
    force[2] = z;
}
void Force::define_force(double mass, Acceleration Acc){
    force[0] = mass * Acc.get_x();
    force[1] = mass * Acc.get_y();
    force[2] = mass * Acc.get_z();
}

std::vector<double> Force::get_coordinates(){
    std::vector<double> points = {force.at(0), force.at(1), force.at(2)};
    return points;
}

double Force::get_x(){
    return force[0];
}
double Force::get_y(){
    return force[1];
}
double Force::get_z(){
    return force[2];
}
double Force::get_magnitude(){
    return sqrt(force[0]*force[0] + force[1]*force[1] + force[2]*force[2]);

}
double Force::get_angle_x(){
    return acos(force.at(0) / this->get_magnitude());
}
double Force::get_angle_y(){
    return acos(force.at(1) / this->get_magnitude());
}
double Force::get_angle_z(){
    return acos(force.at(2) / this->get_magnitude());

}
Force::~Force(){
}

//Acceleration Functions

Acceleration::Acceleration(){
    for (int x = 0; x < 3; x++){
        acceleration.push_back(0);
    }
}

void Acceleration::define_acceleration(double x, double y, double z){
    acceleration[0] = x;
    acceleration[1] = y;
    acceleration[2] = z;
}
void Acceleration::define_acceleration(double mass, Force f){
    acceleration[0] = f.get_x() / mass;
    acceleration[1] = f.get_y() / mass;
    acceleration[2] = f.get_z() / mass;
    check_nan(acceleration);
}
void Acceleration::define_acceleration(double t, Velocity_i v1, Velocity_f v2){
    acceleration[0] = (v2.get_x() - v1.get_x()) / t;
    acceleration[1] = (v2.get_y() - v1.get_y()) / t;
    acceleration[2] = (v2.get_z() - v1.get_z()) / t;
    check_nan(acceleration);
}
void Acceleration::define_acceleration(double t, Velocity_i v1, Displacement d){
    acceleration[0] = (d.get_x() - (v1.get_x() * t)) * (2/(t*t));
    acceleration[1] = (d.get_y() - (v1.get_y() * t)) * (2/(t*t));
    acceleration[2] = (d.get_z() - (v1.get_z() * t)) * (2/(t*t));
    check_nan(acceleration);
}
void Acceleration::define_acceleration(Displacement d, Velocity_i v1, Velocity_f v2){
    acceleration[0] = (v2.get_x()*v2.get_x() - v1.get_x()*v1.get_x()) / (2*d.get_x());
    acceleration[1] = (v2.get_y()*v2.get_y() - v1.get_y()*v1.get_y()) / (2*d.get_y());
    acceleration[2] = (v2.get_z()*v2.get_z() - v1.get_z()*v1.get_z()) / (2*d.get_z());
    check_nan(acceleration);
}

std::vector<double> Acceleration::get_coordinates(){
    std::vector<double> points = {acceleration.at(0), acceleration.at(1), acceleration.at(2)};
    return points;
}
double Acceleration::get_x(){
    return acceleration.at(0);
}
double Acceleration::get_y(){
    return acceleration.at(1);
}
double Acceleration::get_z(){
    return acceleration.at(2);
}
double Acceleration::get_magnitude(){
    return sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]);
}
double Acceleration::get_angle_x(){
    return acos(acceleration.at(0) / this->get_magnitude());
}
double Acceleration::get_angle_y(){
    return acos(acceleration.at(1) / this->get_magnitude());
}
double Acceleration::get_angle_z(){
    return acos(acceleration.at(2) / this->get_magnitude());

}
Acceleration::~Acceleration(){
}

//Velocity_i functions

Velocity_i::Velocity_i(){
    for (int x = 0; x < 3; x++){
        Velocity.push_back(0);
    }
}
void Velocity_i::define_velocity(double x, double y, double z){
    Velocity[0] = x;
    Velocity[1] = y;
    Velocity[2] = z;
}

void Velocity_i::define_velocity(double t, Displacement d, Acceleration a){
    Velocity[0] = (d.get_x() - 0.5 * a.get_x() * t * t) / t;
    Velocity[1] = (d.get_y() - 0.5 * a.get_y() * t * t) / t;
    Velocity[2] = (d.get_z() - 0.5 * a.get_z() * t * t) / t;
    check_nan(Velocity);
}

void Velocity_i::define_velocity(Velocity_f v2, Acceleration a, double t){
    Velocity[0] = v2.get_x() - a.get_x() * t;
    Velocity[1] = v2.get_y() - a.get_y() * t;
    Velocity[2] = v2.get_z() - a.get_z() * t;
}

void Velocity_i::define_velocity(Velocity_i v1, Acceleration a, double t){
    Velocity[0] = v1.get_x() + a.get_x() * t;
    Velocity[1] = v1.get_y() + a.get_y() * t;
    Velocity[2] = v1.get_z() + a.get_z() * t;
}

std::vector<double> Velocity_i::get_coordinates(){
    std::vector<double> points = {Velocity.at(0), Velocity.at(1), Velocity.at(2)};
    return points;
}
double Velocity_i::get_x(){
    return Velocity[0];
}
double Velocity_i::get_y(){
    return Velocity[1];
}
double Velocity_i::get_z(){
    return Velocity[2];
}
double Velocity_i::get_magnitude(){
    return sqrt(Velocity[0]*Velocity[0] + Velocity[1]*Velocity[1] + Velocity[2]*Velocity[2]);

}
double Velocity_i::get_angle_x(){
    return acos(Velocity.at(0) / this->get_magnitude());
}
double Velocity_i::get_angle_y(){
    return acos(Velocity.at(1) / this->get_magnitude());
}
double Velocity_i::get_angle_z(){
    return acos(Velocity.at(2) / this->get_magnitude());

}

Velocity_i::~Velocity_i(){
}

//Velocity_f functions

/*void Velocity_f::define_velocity(Velocity_i v1, Displacement d, Acceleration a){
    Velocity[0] = sqrt(v1.get_x()*v2.get_x() + 2 * a.get_x() * d.get_x());
    Velocity[1] = sqrt(v1.get_y()*v2.get_y() + 2 * a.get_y() * d.get_y());
    Velocity[2] = sqrt(v1.get_z()*v2.get_z() + 2 * a.get_z() * d.get_z());

void Velocity_i::define_velocity(double t, Acceleration acc){
    Velocity[0] = acc.get_x() * t;
    Velocity[1] = acc.get_y() * t;
    Velocity[2] = acc.get_z() * t;
}

}*/


//Displacement functions

Displacement::Displacement(){
    for (int x = 0; x < 3; x++){
        displacement.push_back(0);
    }
}

void Displacement::define_displacement(double x, double y, double z){
    displacement[0] = x;
    displacement[1] = y;
    displacement[2] = z;
}

void Displacement::define_displacement(double t, Velocity_i v){
    displacement[0] = v.get_x() * t;
    displacement[1] = v.get_y() * t;
    displacement[2] = v.get_z() * t;
}

void Displacement::define_displacement(double t, Velocity_i v, Acceleration a){
    displacement[0] = v.get_x() * t + 0.5 * a.get_x() * t * t;
    displacement[1] = v.get_y() * t + 0.5 * a.get_y() * t * t;
    displacement[2] = v.get_z() * t + 0.5 * a.get_z() * t * t;
}

std::vector<double> Displacement::get_coordinates(){
    std::vector<double> points = {displacement.at(0), displacement.at(1), displacement.at(2)};
    return points;
}
double Displacement::get_x(){
    return displacement.at(0);
}
double Displacement::get_y(){
    return displacement.at(1);
}
double Displacement::get_z(){
    return displacement.at(2);
}
double Displacement::get_magnitude(){
    return sqrt(displacement.at(0)*displacement.at(0) + displacement.at(1)*displacement.at(1) + displacement.at(2)*displacement.at(2));

}
double Displacement::get_angle_x(){
    return acos(displacement.at(0) / this->get_magnitude());
}
double Displacement::get_angle_y(){
    return acos(displacement.at(1) / this->get_magnitude());
}
double Displacement::get_angle_z(){
    return acos(displacement.at(2) / this->get_magnitude());

}
Displacement::~Displacement(){
}

int main(){
    std::string word;
    std::map<char, std::vector<double>> var;
    std::cout << "                                              KINEMATICS & DYNAMICS" << std::endl;
    std::cout << std::endl;
    std::cout << "\n1. Acceleration (a)      2. Initial Velocity (u)\n3. Final Velocity (v)    4. Displacement (s)" << std::endl;
    std::cout << "5. Time (t)              6. Angle (q)\n7. Force (f)              8. Mass (m)" << std::endl;
    std::cout << "\nEnter the known variables' symbols (shown in brackets);" << std::endl;
    std::cout << ">> ";
    
    std::cin >> word;

    std::set<char> variable_list = {'a','u','v','s','t','q','f', 'm'};
    
    bool found = true;
    for(auto each : word){
        
        if(variable_list.find(each) == variable_list.end()){
            found = false;
        }
    }

    while(found == false)
    {
        cinfix();
        std::cout << std::endl << "Error: Invalid Input. Please choose a correct symbols.\n>> " ;
        std::cin >> word;
        found = true;
        for(auto each : word){

            if(variable_list.find(each) == variable_list.end()){
                found = false;
            }

        }
    }
    std::cout << std::endl;
    std::cout << "Enter the values for the variables.\n" << std::endl;
    double temp;
    char axis[3] = {'x', 'y', 'z'};
    for(auto x : word){

        if (x == 't' || x == 'm'){
            std::cout << x << ": ";
            std::cin >> temp;
            var[x].push_back(temp);
        }

        else{
            for(auto dir : axis){
                std::cout << x << " in " << dir << " direction: ";
                std::cin >> temp;
                var[x].push_back(temp);
            }
        }

        std::cout<<std::endl;
    }

    std::map<char, bool> flags;
    
    std::set<char> word_copy;
    for(auto x : word){
        word_copy.insert(x);
    }

    for(auto iter = variable_list.begin(); iter != variable_list.end(); iter++){

        if(word_copy.find(*iter) != word_copy.end()){
            flags[*iter] = true;
        }
        else
        {
            flags[*iter] = false;
        }

    }


    Acceleration a {};
    Force f {};
    Velocity_f v2 {};
    Velocity_i v1 {};
    Displacement s {};
    double t;
    double m;
    

    //Can be done by lambda expressions

    if (flags['t'] == true){
        t = var['t'].at(0);
    }
    if (flags['m'] == true){
        m = var['m'].at(0);
    } 

    if(flags['a'] == true){
        a.define_acceleration(var['a'].at(0), var['a'].at(1), var['a'].at(2));
    }
    if(flags['f'] == true){
        f.define_force(var['f'].at(0), var['f'].at(1), var['f'].at(2));
    }
    if(flags['v'] == true){
        v2.define_velocity(var['v'].at(0), var['v'].at(1), var['v'].at(2));
    }
    if(flags['u'] == true){
        v1.define_velocity(var['u'].at(0), var['u'].at(1), var['u'].at(2));
    }
    if(flags['s'] == true){
        s.define_displacement(var['s'].at(0), var['s'].at(1), var['s'].at(2));
    }



    for (int z = 0; z < 5; z++){

        

        if (flags['m'] == 1 && flags['a'] == 1){
            f.define_force(m, a);
            flags['f'] = true;
        }
        if (flags['m'] == 1 && flags['f'] == 1){
            a.define_acceleration(m, f);
            flags['a'] = true;
        }
        if (flags['t'] == 1 && flags['v'] == 1 && flags['u']){
            a.define_acceleration(t, v1, v2);
            flags['a'] = true;
        }
        
        if (flags['t'] == 1 && flags['v'] == 1 && flags['s']){
            a.define_acceleration(t, v1, s);
            flags['a'] = true;
        }
        
        if (flags['u'] == 1 && flags['v'] == 1 && flags['s']){
            a.define_acceleration(s, v1, v2);
            flags['a'] = true;
        }
        if (flags['t'] == 1 && flags['v'] == 1 && flags['a']){
            v1.define_velocity(v2, a, t);
            flags['u'] = true;
        }
        if (flags['t'] == 1 && flags['s'] == 1 && flags['a']){
            v1.define_velocity(t, s, a);
            flags['u'] = true;
        }
        
        if (flags['t'] == 1 && flags['u'] == 1 && flags['a']){
            v2.define_velocity(v1, a, t);
            flags['v'] = true;
        }
        
        if (flags['t'] == 1 && flags['u'] == 1 && flags['a']){
            s.define_displacement(t, v1, a);
            flags['s'] = true;
        }
        if (flags['v'] == 1 && flags['u'] == 1 && flags['a']){
            if (a.get_x() != 0){
                t = (v2.get_x() - v1.get_x()) / a.get_x();
            }
            if (a.get_y() != 0){
                t = (v2.get_y() - v1.get_y()) / a.get_y();
            }
            if (a.get_z() != 0){
                t = (v2.get_z() - v1.get_z()) / a.get_z();
            }
            flags['t'] = true;
        }

        std::cout << "t : " << t << std::endl;

        if (flags['s'] == 1 && flags['u'] == 1 && flags['a']){
            
            if(!(a.get_x() < 0 && (v1.get_x() * -1 * s.get_x()) > 0) && a.get_x()){
                std::cout << "1" << std::endl;
    
                t = quadratic(0.5 * a.get_x(), v1.get_x(), -1 * s.get_x() ).at(0);


            }
            if(!(a.get_y() < 0 && (v1.get_y() * -1 * s.get_y()) > 0) && a.get_y()){

                std::cout << "2" << std::endl;

                t = quadratic(0.5 * a.get_y(), v1.get_y(), -1 * s.get_y() ).at(0);

                
            }

            if(!(a.get_z() < 0 && (v1.get_z() * -1 * s.get_z()) > 0) && a.get_z()!= 0){

                std::cout << "3" << std::endl;

                t = quadratic(0.5 * a.get_z(), v1.get_z(), -1 * s.get_z() ).at(0);

                
                
            }
           
            
            flags['t'] = true;
        }
        

    }

    std::cout << "Time: " <<  t << std::endl;
    std::cout << "Mass: " << m << std::endl;
    std::cout << "Force: "; print_vec(f.get_coordinates()); std::cout << "  Magnitude: " << f.get_magnitude() << "  Angle: "; print_vec({f.get_angle_x(), f.get_angle_y(), f.get_angle_z()}); std::cout << std::endl;
    std::cout << "Acceleration: ";print_vec(a.get_coordinates()); std::cout << "  Magnitude: " << a.get_magnitude() << "  Angle: "; print_vec({a.get_angle_x(), a.get_angle_y(), a.get_angle_z()}); std::cout << std::endl;
    std::cout << "Initial Velocity: "; print_vec(v1.get_coordinates()); std::cout << "  Magnitude: " << v1.get_magnitude() << "  Angle: "; print_vec({v1.get_angle_x(), v1.get_angle_y(), v1.get_angle_z()}); std::cout << std::endl;
    std::cout << "Final Velocity: "; print_vec(v2.get_coordinates()); std::cout << "  Magnitude: " << v2.get_magnitude() << "  Angle: "; print_vec({v2.get_angle_x(), v2.get_angle_y(), v2.get_angle_z()}); std::cout << std::endl;
    std::cout << "Displacement: "; print_vec(s.get_coordinates()); std::cout << "  Magnitude: " << s.get_magnitude() << "  Angle: "; print_vec({s.get_angle_x(), s.get_angle_y(), s.get_angle_z()}); std::cout << std::endl;

    
    
    
    return 0;
}
