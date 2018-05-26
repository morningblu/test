#include <iostream>
#include <cstring>


class String {
public:
    /* 构造函数，也兼默认构造函数*/
    inline explicit String(char *str = nullptr)
    {
        if(!str) {
            m_data = nullptr;
            return;
        }

        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }

    /* 拷贝构造函数*/
    inline String(const String &other)
    {
        if (other.m_data == nullptr) {
            m_data = nullptr;
        }

        m_data = new char(strlen(other.m_data) + 1);
        strcpy(m_data, other.m_data);
    }

    /* 移动构造函数 */
    inline String(String &&other) noexcept
    {
        std::cout<<"call move constructor"<<std::endl;
        m_data = other.m_data;
        other.m_data = nullptr;
    }

    /* 赋值运算符重载 */
    inline String &operator=(const String &other)
    {
        if (this == &other) {
            return *this;
        }

        delete []m_data;
        if (!other.m_data) {
            m_data = nullptr;
        }
        else {
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        }

        return *this;
    }

    /* 移动赋值运算 */
    inline String &operator=(String &&other) noexcept
    {
        m_data = other.m_data;
        other.m_data = nullptr;
        return *this;
    }

    /* 等号重载 */
    inline bool operator==(const String &other)
    {
        if (strlen(other.m_data) != strlen(m_data))
            return false;

        return strcmp(m_data, other.m_data) ? false : true;
    }

    /* 加号重载 */
    inline String &operator+(String &other)
    {
        String newStr;
        if (!other.m_data)
            return *this;

        if (!m_data)
            return other;

        newStr = *this;
        strcat(newStr.m_data, other.m_data);

        return newStr;
    }

    /* []重载 */
    inline char &operator[](const unsigned int e) const
    {
        if (e < 0 || e >= strlen(m_data))
            throw("out of bound");

        return m_data[e];
    }

    /* []重载 */
    inline char &operator[](const unsigned int e)
    {
        if (e < 0 || e >= strlen(m_data))
            throw("out of bound");

        return m_data[e];
    }

private:
    char *m_data;
};

int main()
{
    String s1("gu");
    String s2("hao");
    String s3(s1+s2);
    String s4=std::move(s1+s2);
}
