#include <iostream>

class IntArray
{
    public:
        IntArray(size_t _size) : data(new int[_size]), size(_size) 
        {
            for(size_t i = 0; i < _size;i++){
                data[i]=0;
            }
        };
        ~IntArray() {delete [] data; };
        void set(size_t i , int val) {data[i]=val;}
        int get(size_t i) const {return data[i];}
        size_t getSize() const {return size;}
    private:
        int *data;
        size_t size;

};

/*std::ostream& operator<<(std::ostream &os, const IntArray &obj)
{
    for(size_t = 0 ; i < obj.getSize();i++)
    {
        os << obj.get(i);
        if( i !=obj.getSize()-1)
        {
            os <<", ";
        }
    }
    return os;
}
*/

int main()
{
    IntArray arry(3);
    arry.set(0,100);
    arry.set(0,200);
    arry.set(0,300);
    
};