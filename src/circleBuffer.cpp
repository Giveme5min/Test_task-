#include <iostream>
#include <initializer_list>



template <typename T>
class Buffer
{
    size_t size; //Size of current array
    size_t size_cur;
    //  T items; //items currently in array
    T* arr;
public:
    //copy and moving semantic omitted
    ~Buffer() { delete[] arr; }
    //use initializer list available from C++11
    Buffer(std::initializer_list<T> init)
        : size(init.size()),
        //  items(init.size()),
        arr(new T[init.size()])
    {
        std::copy(init.begin(), init.end(), arr);
        size_cur = size;
    }

    T* begin() { return arr; }
    T* end() { return arr + size_cur; }

    size_t max_size() { return size; }
    size_t Size() { return size_cur; }
    void pop_front();
    void clear();
    void push_back(T val);
    void push_front(T val);







};

template<typename T>
void Buffer<T>::push_back(T val)
{
    if (size_cur < size) {
        ++size_cur;
        arr[size_cur - 1] = val;
    }
    else {
        for (int i = 0; i < size_cur; i++)
            arr[i] = arr[i + 1];

        arr[size_cur - 1] = val;
    }


}

template<typename T>
void Buffer<T>::push_front(T val)
{
    if (size_cur == 0) {
        ++size_cur;
        arr[0] = val;
    }

    else if (size_cur != 0 && size_cur < size)
    {
        ++size_cur;
        for (int i = size_cur - 2; i >= 0; i--)
            arr[i + 1] = arr[i];

        arr[0] = val;
    }

    else {
        for (int i = size_cur - 2; i >= 0; i--)
            arr[i + 1] = arr[i];

        arr[0] = val;
    }
}



template<typename T>
void Buffer<T>::pop_front()
{


    if (size_cur > 0) {
        for (int i = 0; i < size_cur; i++)
        {
            arr[i] = arr[i + 1];
            //std::cout<<arr[i]<<std::endl;
        }
        --size_cur;
    }
}

template<typename T>
void Buffer<T>::clear()
{
    for (int i = 0; i < size_cur; i++)
        arr[i] = 0;

    size_cur = 0;

}

template<typename T>
void print(Buffer<T>& buf)
{
    for (auto& value : buf)
        std::cout << value;
    std::cout << std::endl;
}







int main()
{
    Buffer<int> buffer({ 1,2,3,4 });
    std::cout << "Buffer<int> buffer=";
    print(buffer);


    buffer.push_back(4);
    std::cout << "push_back:";
    print(buffer);


    buffer.push_front(0);
    std::cout << "push_front:";
    print(buffer);


    buffer.push_back(5);
    std::cout << "push_back:";
    print(buffer);

    buffer.pop_front();
    std::cout << "pop_front:";
    print(buffer);

    for (auto& value : buffer)
        std::cout << value;
    std::cout << std::endl;

    std::cout << "Size()=" << buffer.Size() << std::endl;
    std::cout << "max_size()=" << buffer.max_size() << std::endl;

    buffer.clear();
    std::cout << "clear:";
    print(buffer);

    system("pause");




}
