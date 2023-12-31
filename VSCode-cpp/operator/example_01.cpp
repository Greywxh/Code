#include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    int inches;
public:
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    
    void displayDistance() {
        cout << "F: " << feet << ", I: " << inches << endl;
    }
    
    // 重载负运算符 ( - )
    Distance operator- () {
        feet = -feet;
        inches = -inches;
        return Distance(feet, inches);
    }
};

int main(void)
{
    Distance d1(1, 10), d2(-5, 110);
    
    -d1;                     // 取相反数
    d1.displayDistance();    // 距离 D1
    
    -d2;                     // 取相反数
    d2.displayDistance();    // 距离 D2
    system("pause");
    return 0;
}