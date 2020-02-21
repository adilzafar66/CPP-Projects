class Acceleration;
class Force;
class Displacement;
class Velocity_i;
class Velocity_f;

class Force
{
private:
    std::vector<double> force;
public:

    Force();

    void define_force(double x, double y, double z);
    void define_force(double mass, Acceleration Acc);
    
    std::vector<double> get_coordinates();
    double get_x();
    double get_y();
    double get_z();
    double get_magnitude();
    double get_angle_x();
    double get_angle_y();
    double get_angle_z();
    
    ~Force();
};

class Acceleration
{
private:
    std::vector<double> acceleration;
public:
    Acceleration();

    void define_acceleration(double x, double y, double z);
    void define_acceleration(double mass, Force f);
    void define_acceleration(double t, Velocity_i v1, Velocity_f v2);
    void define_acceleration(double t, Velocity_i v1, Displacement d);
    void define_acceleration(Displacement d, Velocity_i v1, Velocity_f v2);

    std::vector<double> get_coordinates();
    double get_x();
    double get_y();
    double get_z();
    double get_magnitude();
    double get_angle_x();
    double get_angle_y();
    double get_angle_z();

    ~Acceleration();
};

class Velocity_i
{
private:
    std::vector<double> Velocity;
public:
    Velocity_i();

    void define_velocity(double x, double y, double z);
    void define_velocity(double t, Displacement d, Acceleration a);
    void define_velocity(Velocity_f v2, Acceleration a, double t);
    void define_velocity(Velocity_i v1, Acceleration a, double t);

    std::vector<double> get_coordinates();
    double get_x();
    double get_y();
    double get_z();
    double get_magnitude();
    double get_angle_x();
    double get_angle_y();
    double get_angle_z();

    ~Velocity_i();
};

class Velocity_f : public Velocity_i
{

public:
    //void define_velocity(Velocity_i v1, Displacement d, Acceleration a);
    //void define_velocity(double t, Acceleration acc);

};

class Displacement
{
private:
    std::vector<double> displacement;
public:
    
    Displacement();

    void define_displacement(double x, double y, double z);
    void define_displacement(double t, Velocity_i v);
    void define_displacement(double t, Velocity_i v, Acceleration a);

    std::vector<double> get_coordinates();
    double get_x();
    double get_y();
    double get_z();
    double get_magnitude();
    double get_angle_x();
    double get_angle_y();
    double get_angle_z();

    ~Displacement();


};